//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//
// Les différentes fonctions HW du PIC
//
// Fonctions : vDelai       Delai
//           : vInitPic     Initialisation du PIC
//           : vInitRS232   Initialisation du port serie
//           : vTx232       Transmission port serie
//           : vRx232       Reception port serie
//           : vTransChaine Tranmit chaine sur port serie
//           : vInitPWM     Initialise PWM pic
//           : interrupt    Interruptions generales du PIC
// TSO 2012-2015   Jean-Francois Bilodeau    MikroC 6.0.0  6/4/2014
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&//
#include "PIC18F258.h"

volatile UC ucTrame = INCOMPLETE, ucNbCaract = 0, 
            ucIndiceTampon = 0, ucValPortB = 0, ucTxDataI2C, ucRxDataI2C;
UC ucTabRx232[26];//Tab reception

//************************** vInitPic ****************************************//
//Description : Fonction d'initialisation du PIC.
//              Set les interruptions, les ADC, le crystal, le sens des ports
//              par defaut ainsi que les valeurs voulues
//
//Prototype fonction : vInitPic
//
//Param entree       : Aucun
//
//Param sortie       : Aucun
//
//Procedure d'appel  : vInitPic()
//
//TSO 2012-2015   Jean-Francois Bilodeau    MikroC 6.0.0  6/4/2014
//******************************************************************************
void vInitPic (void)
 {
   INTCON = 0xC0;      //ENABLE GLOBAL INTERRUPT, ENABLE PERIPHERAL INTERRUPT
   OSCCON = 0b00000000;//4MHZINTRC
   ADCON0.ADON = 0;    //DEACTIVATE analog PIC18F258
   TRISC = 0b10000000; //RX IN, TX OUT
   TRISB = 0b00001000; //CAN TX/RX set up
 }

//************************** vInitRS232 **************************************//
//Description : Fonction d'initialisation du Port Serie du PIC
//              Set les interruptions du port serie necessaires.
//              Set la vitesse en BD rate, les paritees, mode high speed
//
//Prototype fonction : vInitRS232
//
//Param entree       : Aucun
//
//Param sortie       : Aucun
//
//Procedure d'appel  : vInitRS232()
//
//TSO 2012-2015   Jean-Francois Bilodeau    MikroC 6.0.0  6/4/2014
//******************************************************************************
void vInitRS232 (void)
 {
   PIE1 = 0x20;          //Receive enable
   SPBRG = 0x19;         //9600BDs
   RCSTA = 0x90;         //Set le registre de reception serie
   TXSTA = 0x24;         //Set le registre de transmission serie, BRGH 1 HSPEED
 }

//************************** vTx232 **************************************//
//Description : Fonction d'envoi de donnee via le port serie du PIC
//              Polling tant que le dernier envoi est pas fait, sinon
//              lets go shoot vers la PIN TX du PIC.
//
//Prototype fonction : vTx232
//
//Param entree       : ucSend : donnee a envoyer sur le port serie
//
//Param sortie       : Aucun
//
//Procedure d'appel  : vTx232 ('A')//exemple
//
//TSO 2012-2015   Jean-Francois Bilodeau    MikroC 6.0.0  6/4/2014
//******************************************************************************
void vTx232 (UC ucSend)
 {
    while (PIR1.TXIF == 0);//Tant que dernier envoie pas terminé fait rien
    TXREG = ucSend;        //Valeur entree dans TXREG, envoi serie
 }

//************************** vTransChaine ************************************//
//Description : Fonction d'envoi de chaine de caractere via le port serie
//              Recoit un pointeur en entree et utilise Tx232
//
//Prototype fonction : vTransChaine (UC *ucpChaine)
//
//Param entree       : *ucpChaine ; pointeur sur chaine de caractere
//
//Param sortie       : Aucun
//
//Procedure d'appel  : vTransChaine ("TestRS232")
//
//TSO 2012-2015   Jean-Francois Bilodeau    MikroC 6.0.0  6/4/2014
//******************************************************************************
void vTransChaine (UC *ucpChaine)
 {
   while (*ucpChaine != 0x00)   //Tant qu'on n'atteint pas la fin de la chaine
    {
      vTx232(*ucpChaine);       //Affiche caractere de la chaine
      ucpChaine++;              //Incremente position pour aff tout les carac
    }
 }

//************************** interrupt ************************************//
//Description : Fonction d'interruption generale du PIC
//              Selon la source d'interruption, execute le code necessaire
//
//            : PIR1.RCIF --RECEIVE serial flag
//              Source interruption rx port serie, sauve valeurs dans le tableau
//              de reception serie, indique trame complete lorsque indice defini
//              par utilisateur est plein
//
//Prototype fonction : interrupt (void)
//
//Param entree       : Aucun
//
//Param sortie       : Aucun
//
//Procedure d'appel  : Execute tout seul lorsque interruption survient
//
//TSO 2012-2015   Jean-Francois Bilodeau    MikroC 6.0.0  6/4/2014
//******************************************************************************
void interrupt (void)
 {
   INTCON.GIE = 0;   //Disable all interrupts
   //Regarde quelle est la source d'interruption
   if (PIR1.RCIF)    //Receive serial flag up?
    {
      if (ucIndiceTampon >= INDICETAMPON){ucIndiceTampon = 0;}
      //Si tampon >= indice tampon, remet a 0. Defini par usager selon appli
      ucTabRx232[ucIndiceTampon] = RCREG; //Val recue dans le tab de reception
      ucIndiceTampon++;                   //increm indice reception
      if (ucNbCaract < LONGUEURTRAME - 1) //Si nb caractere < long trame?
       {
         ucNbCaract++;                    //increm nb caract recu
         ucTrame = INCOMPLETE;            //Trame incomplete
       }
      else                                //Si nb caractere = long trame
       {
         ucIndiceTampon = 0;              //INdice tampon a 0
         ucNbCaract = 0;                  //nb caract a 0
         ucTrame = COMPLETE;              //wouhou! trame complete
       }
       
      if(ucNbCaract > 13)
      {
         if(ucTabRx232[13] != '.')
          {
            ucIndiceTampon = 0;
            ucNbCaract = 0;
            ucTrame = INCOMPLETE;
          }
      }
    }
   INTCON.GIE = 1;               //Re-Active interruption generale
   PIR1.RCIF = 0;                //Baisse flag pour permettre seconde interrupt
 }

void vDelai (UC ucDelai)
 {
    for (; ucDelai>0; ucDelai--);
 }