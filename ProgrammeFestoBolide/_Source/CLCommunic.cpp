// ********************** FICHIER: CLCommunic.cpp ******************************
// Descrtiption : La classe contient des fonctions pour controler le port
//                serie du uPSD ou du DALLAS.
//
// Fonctions    : ucInitLongTrame -- Initialise longueur trame
//                vTransCaractere -- Envoie caractere sur port
//                vTransChaine    -- Envoie chaine sur port
//                *ucpLireTrame   -- Pointeur sur la trame
//                ucLireNbCaract  -- Retourne nombre caract recu
//                ucLireEtatTrame -- Retourne etat reception trame
//                vInitBaudRate   -- Initialise Baud
//                ucValideTrame   -- Retourne etat trame valide
//                __interrupt void CLCommunic :: vInterruptSerial (void)
//                --Fonction interruption serie
//                
//                
//
//  AUTEUR : Jean-Francois Bilodeau
//  DATE CREATION :    27/03/2014		 VERSION: 1.0
//
// ****************************************************************************
#include "CLCommunic.h"

UC ucTestCheck;
UC ucTestCheck2;
//******************************************************************************
//******************************MEMBRES STATIQUES*******************************
UC CLCommunic :: ucLongueurBuffer = 0;//tableau buffer
UC CLCommunic :: ucLongueurTrame = 0; //tableau trame
UC CLCommunic :: ucNbCaractRecu = 0;  //indice nb caractere
UC CLCommunic :: ucEtatTrame = INCOMPLETE;     //indice etat trame
UC * CLCommunic :: ucpDebutTampon = 0;   //indice debut tampon
UC * CLCommunic :: ucpFinTampon = 0;     //indice fin tampon
UC * CLCommunic :: ucpEcrireTampon = 0;  //Indice ecriture tampon
UC * CLCommunic :: ucpLireTampon = 0;    //indice lecture tampon
UC * CLCommunic :: ucpTabCaractereRecu = 0;//Tab caract recu
UC * CLCommunic :: ucpLectureTampon = 0;//Tampon lecture
UC * ucpEnvoyerTampon;
// *****************************CLCommunic(void)********************************
//
//Description : Constructeur par defaut. InitBaudRate avec constantes, longueur
//              trame et longueur buffer             
//
// Nom : CLCommunic :: CLCommunic (void)
//
// Parametre d'entree : AUCUN
//
// Parametre sortie : AUCUN
//
//
// Membres utilisés 
//    Fonctions : vinitBaudRate -- Set le baud rate par defaut
//    DOnnees   : Constantes d'initialisation
//
// Auteur : JEAN-FRANCOIS BILODEAU
// Date crée : 27/03/2014
// Date modif :
// ****************************************************************************
CLCommunic :: CLCommunic (void)
 {
   ucLongueurBuffer = LONGUEURBUFFER;//Define dans longbuffer
   ucLongueurTrame = LONGUEURTRAME;//define dans longtrame
   ucpTabCaractereRecu = new UC [LONGUEURBUFFER];//Alloc dynamique selon buffer
   ucpEcrireTampon = &ucpTabCaractereRecu[LONGUEURBUFFER];//Ecrire = tabcaract
   ucpFinTampon = &ucpTabCaractereRecu[LONGUEURBUFFER];//Fin = tabcaract
   ucpDebutTampon = &ucpTabCaractereRecu[0];//Declare membres statiques
   vInitBaudRate (INITBAUDDEFAUT);//Init baud rate avec val par defaut
 }

// *******CLCommunic(UC ucLongBuf, UC ucLongTrame, UINT16 usiBaud)**************
//
//Description:Constructeur initialisateur,InitBaudRate, longueur
//              trame et longueur buffer avec PARAM ENTREE            
//
// Nom : CLCommunic :: CLCommunic (UC uc... UC uc... UINT16 usi...)
//
// Parametre d'entree : Long buffer, Long Trame, valeur baudRate
//
// Parametre sortie : AUCUN
//
//
// Membres utilisés 
//    Fonctions : vinitBaudRate -- Set le baud rate par defaut
//    DOnnees   : Variables d'entree
//
// Auteur : JEAN-FRANCOIS BILODEAU
// Date crée : 27/03/2014
// Date modif :
// ****************************************************************************
CLCommunic :: CLCommunic (UC ucLongBuf, UC ucLongTrame, UINT16 usiBaud)
 {
   ucpTabCaractereRecu = new UC [ucLongBuf];//Alloc dynamique selon longbuf
   ucpEcrireTampon = &ucpTabCaractereRecu[0];//Ecrire=AdresseCase1 tab caract
   ucpFinTampon = &ucpTabCaractereRecu[ucLongBuf];//Lire=last case tab caract
   ucpDebutTampon = &ucpTabCaractereRecu[0];//Declare membres statiques
   ucLongueurBuffer = ucLongBuf;//Long buffer = param entree buffer
   ucLongueurTrame = ucLongTrame;//Long trame = param entree trame
   vInitBaudRate (usiBaud);//Init baud rate avec valeur param entree
 }


// ********************************~CLCommunic(void)****************************
//
//Description:Constructeur defaut. Desalloue la memoire des tampons          
//
// Nom : CLCommunic :: ~CLCommunic (void)
//
// Parametre d'entree : 
//
// Parametre sortie : AUCUN
//
//
// Membres utilisés 
//    Fonctions : 
//    DOnnees   : 
//
// Auteur : JEAN-FRANCOIS BILODEAU
// Date crée : 27/03/2014
// Date modif :
// ****************************************************************************
CLCommunic :: ~CLCommunic (void)
 {
   delete ucpTabCaractereRecu;
   delete ucpLireTampon;
 }

// **************************vInitBaudRate(usiBaud)*****************************
//
//Description : Initialise Baud avec param recue en entree. Initialise via timer          
//
// Nom : CLCommunic :: vInitBaudRate (usiBaud)
//
// Parametre d'entree : usiBaud : vitesse en BAUDRATE du portserie
//
// Parametre sortie : AUCUN
//
//
// Membres utilisés 
//    Fonctions : 
//    DOnnees   : 
//
// Auteur : JEAN-FRANCOIS BILODEAU
// Date crée : 27/03/2014
// Date modif :
// ****************************************************************************
void CLCommunic :: vInitBaudRate (UINT16 usiBaudRate)
{
#ifdef DALLAS89C450  
 SCON0 = 0x50;          // SM0_0=0 
                        // SM1_0=1
	                // SM2_0=0 pour longeur 10 bits et asychrone.
                        // REN_0=1 pour recevoir des caracteres.
	
 TMOD= TMOD | 0x20;     // M1=1
                        // M0=0 pour timer 8bit avec autoreload.
 PCON= PCON | 0x80;     // Pour doubler le baudrate (SMOD_0=1;).
#endif

#ifdef UPSD3254A  
 SCON = 0x50;           // SM0_0=0 
                        // SM1_0=1
	                // SM2_0=0 pour longeur 10 bits et asychrone.
                        // REN_0=1 pour recevoir des caracteres.
	
 TMOD= TMOD | 0x20;     // M1=1
                        // M0=0 pour timer 8bit avec autoreload.
 PCON= PCON | 0x80;     // Pour doubler le baudrate (SMOD_0=1;).
#endif  
 
#ifdef DALLAS89C450     // Si la cible est le Dallas
 switch(usiBaudRate)    // switch case pour determiner la valeur en 
   {                    // hexa qui faut mettre a TH1 pour avoir la 
	                // bonne vitesse du timer pour generer
    case 57600:         // le baudrate.
     TH1 = 0xFF;
    break;
    case 38400:
     TH1 = 0xFE;
    break;   
    case 19200:
     TH1 = 0xFD;
    break;
    case 9600:
     TH1 = 0xFA;
    break;
    case 4800:
     TH1 = 0xF4;
    break;
    case 2400:
     TH1 = 0xE8;
    break;
    default:
     TH1 = 0xFA;         //9600 vitesse par defaut
    break; 
  }
#endif                  //DALLAS
 
#ifdef UPSD3254A        // Si la cible est le uPSD
 switch(usiBaudRate)    // switch case pour determiner la valeur en 
   {                    // hexa qui faut mettre a TH1 pour avoir la 
	                // bonne vitesse du timer pour generer
    case 9600:
     TH1 = 0xF3;
    break;
    case 4800:
     TH1 = 0xE6;
    break;
    case 2400:
     TH1 = 0xCC;
    break;
    default:
     TH1 = 0xF3;         //9600 val par defaut
    break; 
  }
#endif                  //uPSD
 
 
 TR1 = 1;                 // Active le timer 1.
 ET1 = 0;                 // Desactive les interruptions du timer 1. 
 EA = 1;                  // Active les interruptions.
 #ifdef DALLAS89C450
 ES0 = 1;                 // Active les interruptions du port serie.
 #endif
 #ifdef UPSD3254A
 ES = 1;
 #endif
 
 TI_0 = 0;                // Met a 0 le drapeau de la transmision serie.
 
}


// **************************TransCaractere(UC ucCar)***************************
//
//Description :Transmet un caractere sur le port serie via POLLING sur TI         
//
// Nom : CLCommunic :: vTransCaractere(UC ucCar)
//
// Parametre d'entree : ucCar : caractere a envoyer sur port serie
//
// Parametre sortie : AUCUN
//
//
// Membres utilisés 
//    Fonctions : vInitBaudRate pour setter le port serie
//    DOnnees   : ucCar le caractere a envoyer
//
// Auteur : JEAN-FRANCOIS BILODEAU
// Date crée : 27/03/2014
// Date modif :
// ****************************************************************************
void CLCommunic :: vTransCaractere (UC ucCar)
 {
   #ifdef UPSD3254A
    SBUF = ucCar;//ucCar dans le buffer d'envoi
   #endif
   
   #ifdef DALLAS89C450
    SBUF0 = ucCar;//ucCar dans le buffer d'envoi
   #endif
    
   while (TI_0 == 0);          //Polling tant que TI = 0 
   TI_0 = 0;	               //Replace a 0 pour un second envoi
 }


void CLCommunic :: vTransCarBuffer (UC ucL, char *ucDat)
 {
   UC uci;
   for (uci=0; uci<ucL; uci++)
    {
      vTransCaractere(ucDat[uci]); 
    }   
 }

// *********************TransChaine(const UC *ucpChaine)************************
//
//Description :Transmet chaine de caractere sur le port serie via POLLING sur TI         
//
// Nom : CLCommunic :: vTransCaractere (UC *ucpChaine)
//
// Parametre d'entree : ucpChaine :`chaine a envoyer
//
// Parametre sortie : AUCUN
//
//
// Membres utilisés 
//    Fonctions : vInitBaudRate pour setter le port serie
//    DOnnees   : ucChaine chaine a envoyer
//
// Auteur : JEAN-FRANCOIS BILODEAU
// Date crée : 27/03/2014
// Date modif :
// ****************************************************************************
void CLCommunic :: vTransChaine (const UC *ucpChaine)
 {
   const UC *ucpCheckTx;
   ucpCheckTx = ucpChaine;
   
   while (*ucpChaine != 0x00)     //Tant que la chaine est pas finie
    {
      vTransCaractere(*ucpChaine);//Transmet le caractere de la chaine
      ucpChaine++;                //incremente la chaine
    }    
   
   #ifdef CHECKSUM_RS232
   ucCheckTx = ucChecksum(ucpChaine);
   vTransCaractere(ucCheckTx);
   #endif
 }

// *********************ucInitLongTrame (UC ucLong)*****************************
//
//Description : Fonction permet de modifier la longueur de la trame
//
// Nom : UC CLCommunic :: ucInitLongTrame (UC ucLong)
//
// Parametre d'entree : ucLong - Longueur de la trame voulue
//
// Parametre sortie : AUCUN
//
//
// Membres utilisés 
//    Fonctions : vInitBaudRate pour setter le port serie
//    DOnnees   : ucChaine chaine a envoyer
//
// Auteur : JEAN-FRANCOIS BILODEAU
// Date crée : 27/03/2014
// Date modif :
// ****************************************************************************
UC CLCommunic :: ucInitLongTrame (UC ucLong)
{
  UC ucRetour;
  if (ucLong <= ucLongueurBuffer)//Si la trame est plus petite que le buffer
   {
     ucLongueurTrame = ucLong;//Change le buffer de trame
     ucRetour = VRAI;         //Retourne VRAI
   }
  if (ucLong > ucLongueurBuffer) {ucRetour = FAUX;}//Si plus grand que buffer
  //Retourne faux
  return (ucRetour);//retourne la valeur
}

// *********************ucLireNbCaractRecu (void) *****************************
//
//Description : Fonction permet de lire le NB de caract recu dans interrupt
//
// Nom : UC CLCommunic :: ucLireNbCaractRecu (void)
//
// Parametre d'entree : 
//
// Parametre sortie : le nombre de caractere recu dans interrupt
//
//
// Membres utilisés 
//    Fonctions : 
//    DOnnees   : ucNbCaractRecu compteur des caracteres
//
// Auteur : JEAN-FRANCOIS BILODEAU
// Date crée : 27/03/2014
// Date modif :
// ****************************************************************************
UC CLCommunic :: ucLireNbCaractRecu (void)
 {
   return (ucNbCaractRecu);//Retourne le nombre de caractere recu
 }

// *********************ucLireEtatTrame (void)**********************************
//
//Description : Fonction permet de lire etat de la trame (Complet, incomplet)
//
// Nom : UC CLCommunic :: ucLireEtatTrame (void)
//
// Parametre d'entree : 
//
// Parametre sortie : Etat reel de la trame : complete, incomplete
//
//
// Membres utilisés 
//    Fonctions : 
//    DOnnees   : 
//
// Auteur : JEAN-FRANCOIS BILODEAU
// Date crée : 27/03/2014
// Date modif :
// ****************************************************************************
UC CLCommunic :: ucLireEtatTrame (void)
 {
   return (ucEtatTrame);//Retourne l'etat de la trame
 }

// **********************ucpLireTrame(void)**********************************
//
//Description : Fonction fait lecture de la trame recue si trame valide
//
// Nom : UC * CLCommunic :: ucpLireTrame(void)
//
// Parametre d'entree : 
//
// Parametre sortie : Pointeur sur le debut de la trame de caractere
//
//
// Membres utilisés 
//    Fonctions : 
//    DOnnees   : 
//
// Auteur : JEAN-FRANCOIS BILODEAU
// Date crée : 27/03/2014
// Date modif :
// ****************************************************************************
UC * CLCommunic :: ucpLireTrame(void)
 {    
   if (ucLireEtatTrame() == COMPLETE)
    {
      #ifndef CHECKSUM_RS232
      ucpEnvoyerTampon = ucpDebutTampon;
      #endif
      
      //Si valideTrame() retourne trame valide, tampon lecture sur debut tampon
      //Sinon, retourne tampon NULL
      #ifdef CHECKSUM_RS232
      if (ucValideTrame() == VALIDE){ucpEnvoyerTampon = ucpDebutTampon;}
      if (ucValideTrame() == INVALIDE){ucpEnvoyerTampon = NULL;}
      #endif
    }
   else
    {
      ucpEnvoyerTampon = NULL; 
    }
   
   ucEtatTrame=INCOMPLETE;
   return (ucpEnvoyerTampon);     //Retourne tampon de lecture
 }

// *********************ucValideTrame(void)**********************************
//
//Description : Fonction valide la trame recue avec calcul checksum
//
// Nom : UC CLCommunic :: ucValideTrame(void)
//
// Parametre d'entree : 
//
// Parametre sortie : Etat trame valide ou NON
//
//
// Membres utilisés 
//    Fonctions : 
//    DOnnees   : 
//
// Auteur : JEAN-FRANCOIS BILODEAU
// Date crée : 27/03/2014
// Date modif :
// ****************************************************************************
UC CLCommunic :: ucValideTrame(void)
 {
   UC ucTrameValide, uci, ucCheckSum;
   ucpLectureTampon = ucpLireTampon;
   ucCheckSum = 0;
   for (uci=0; uci < ucLongueurTrame-1; uci++)//Add tout sauf checksum
    {
      ucCheckSum += *ucpLectureTampon;//Fait addition
      ucpLectureTampon++;//Incremente indice tampon
    }
   //Si valeur checksum different dernier octet de trame, return invalide.
   //Sinon, le checksum=dernier octet trame, OK, return valide
   if (ucCheckSum != *ucpLectureTampon){ucTrameValide = INVALIDE;}
   if (ucCheckSum == *ucpLectureTampon){ucTrameValide = VALIDE;}   
   return (ucTrameValide);//Retourne TrameValide
 }
// *********************ucChecksum(void)****************************************
//
//Description : Calcul du checksum pour l'envoi
//
// Nom : UC CLCommunic :: ucChecksum(void)
//
// Parametre d'entree : *ucpChaine (Chaine envoyée)
//
// Parametre sortie   : ucChecksum
//
//
// Membres utilisés 
//    Fonctions : 
//    Donnees   : 
//
// Auteur : LOUIS-NORMAND ANG HOULE
// Date crée : 02/12/2014
// Date modif :
// ****************************************************************************
UC CLCommunic :: ucChecksum(const UC  *ucpChaine)
{
  UC ucChecksum;
  while(*ucpChaine != NULL)
   {
     ucChecksum += *ucpChaine;     
     ucpChaine++;  
   }
  return (ucChecksum);
}

// *********************vResetTampon(void)**************************************
//
//Description : Reinitialise le pointeur d'ecriture du tampon a 0
//
// Nom : void CLCommunic :: vResetTampon(void)
//
// Parametre d'entree : NULL
//
// Parametre sortie   : NULL
//
//
// Membres utilisés 
//    Fonctions : 
//    Donnees   : 
//
// Auteur : LOUIS-NORMAND ANG HOULE
// Date crée : 04/12/2014
// Date modif :
// ****************************************************************************

void CLCommunic :: vResetTampon(void)
{
   ucNbCaractRecu = 0;
   ucpEcrireTampon = ucpDebutTampon;
}

// *********************__interruptSerial**********************************
//
//Description : Fonction interruption du port serie
//
// Nom : __interrupt void CLCommunic :: vInterruptSerial(void)
//
// Parametre d'entree : 
//
// Parametre sortie :
//
//
// Membres utilisés 
//    Fonctions : 
//    DOnnees   : 
//
// Auteur : JEAN-FRANCOIS BILODEAU
// Date crée : 27/03/2014
// Date modif :
// ****************************************************************************
#ifdef DALLAS89C450
 #pragma vector = 0x23//Vecteur interruption du port serie DS89C450
#endif

#ifdef UPSD3254A
 #pragma vector = 0x23//Vecteur interruption du port serie uPSD3254A
#endif
__interrupt void CLCommunic :: vInterruptSerial (void)
  {
    EA = 0;	              //desactive les interruptions
    if (RI_0)                 //Si flag reception leve
     {
        P1_7 = !P1_7;
        if (ucpEcrireTampon >= ucpFinTampon)//Si indice tableau est plus grand 
	 {                                    //que l'indice du tampon
            ucpEcrireTampon = ucpDebutTampon; //Replace l'indice a 0
         }
       #ifdef DALLAS89C450
	*ucpEcrireTampon = SBUF0;     //Sinon carac recu va dans tampon
       #endif
       #ifdef UPSD3254A
        *ucpEcrireTampon = SBUF;      //Sinon carac recu va dant tampon
       #endif
	ucpEcrireTampon++;		         //incremente indice tampon	 
        if (ucNbCaractRecu < ucLongueurTrame - 1)//si nbcarat < longueurtrame
         {
            ucNbCaractRecu++;                  //Increm nb caractrecu
            ucEtatTrame = INCOMPLETE;          //trame incomplete
         }                    
        else  //si nb caract recu est plus grand que 6
	 {	
	    ucpLireTampon = (ucpEcrireTampon - ucLongueurTrame);
            //Tampon de lecture = ecriture - longueur trame (buffer circulaire)
	    ucNbCaractRecu = 0;                //remet nb caract a 0
            ucEtatTrame = COMPLETE;            //Trame = complete
	 }
     }
    if (TI_0){};
    RI_0 = 0;  //baisse le flag pour permettre une seconde interrupt
    EA = 1;	  //re-active les interruptions	  
  }  



                             