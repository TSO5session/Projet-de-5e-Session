#include "CLCommunicCom2.h"

UC  CLCommunicCom2 :: ucLongeurTampon;
UC  CLCommunicCom2 :: ucLongeurTrame;
UC  CLCommunicCom2 :: ucNbCarRecu;
UC  CLCommunicCom2 :: ucEtatTrame;

UC  *CLCommunicCom2 :: ucpDebutTampon;
UC  *CLCommunicCom2 :: ucpFinTampon;
UC  *CLCommunicCom2 :: ucpLectureTampon;
UC  *CLCommunicCom2 :: ucpEcritureTampon;

UC  CLCommunicCom2 :: ucCheckSUM;
UC  CLCommunicCom2 :: ucCheckSumLow;
UC  CLCommunicCom2 :: ucCheckSumHIGH;

CLCommunicCom2 :: CLCommunicCom2 (void)
 {
  ucpDebutTampon    = new UC [LONGEURBUFFER];
  ucpFinTampon      = ucpDebutTampon + LONGEURBUFFER - 1;  
  ucLongeurTampon   = LONGEURBUFFER; 
  ucLongeurTrame    = LONGEURTRAME;
  ucpEcritureTampon = ucpDebutTampon;
  vInitBaudRate (9600);
 } 

CLCommunicCom2 :: CLCommunicCom2 (UC ucLongBuf, UC ucLongTrame, UINT16 uiBaud)
 {
  ucpDebutTampon    = new UC [ucLongBuf]; 
  ucpFinTampon      = ucpDebutTampon + ucLongBuf;  
  ucLongeurTampon   = ucLongBuf;
  ucLongeurTrame    = ucLongTrame;
  ucpEcritureTampon = ucpDebutTampon;
  vInitBaudRate (uiBaud);
 }

CLCommunicCom2 :: ~CLCommunicCom2 (void) 
 {  
  delete [] ucpDebutTampon;
 } 

//************************Fonction: vInitBaudRate****************************//
// DESCRIPTION: Initialise le baud rate de la comm. serie
//
// PROTOTYPE:   void CLCommunic ::  vInitBaudRate (UINT16 uiBaud)
//
// PARAMETRE D'ENTREE: UINT16 uiBaud: Vitesse de transmission en baud
//
// PARAMETRE DE SORTIE: Aucun
//
// DATE DE CREATION: 10/10/2013
//
// DATE DE MODIFICATION : -
//***************************************************************************//
void CLCommunicCom2 ::  vInitBaudRate (UINT16 uiBaud)
 {
#ifdef DALLAS89C450  
  EA = 0; 
  TMOD |= 0x20;   //8-bit auto-reload Timer/Counter
  SCON2 = 0x50;   //
  SMOD2 = 1;      // Double Baudrate
  switch (uiBaud)
   {
    case 9600:
    TH1 = 0xFA;
    break;
  //---------------
    case 19200:
    TH1 = 0xFD;
    break;
  //---------------
    case 28800:
    TH1 = 0xFE;
    break;
  //---------------
    case 57600:
    TH1 = 0xFF;
    break;
   }   
  TR1  = 1;  //Start Timer 1
  ET1  = 0;  //Disable timer 1 Interrupt
  ES2  = 1;  //Enable serial 2

  RI_2 = 0;  //Descend flag interupt serie 2
  TI_2 = 0;  //Enable transmission port 2
  EA   = 1;  //Enable toute interruption
#endif

#ifdef UPSD3254A  
   EA           = 0;           //Disable toute interrupt 
   TMOD        |= 0x20;        //8-bit auto-reload Timer/Counter
   SCON2        = 0x50;        //Mode 1, 1 bit start, 8 bit donnee, 1 bit stop
   PCON         = PCON |0x40;  //SMOD double baud rate
   TH1          = 0xF3;        //Baud rate a 9600  
   ET1          = 0;           //Disable timer 1 Interrupt   
   TR1          = 1;           //Start Timer 1  
   ES2          = 1;           //Enable serial 2
   SCON2_bit.TI = 1;           //    
#endif

}  

//**********************Fonction: ucInitLongTrame ***************************//
// DESCRIPTION: Retourne valeur du nb. de caractere recu
//
// PROTOTYPE:  UC CLCommunic :: ucInitLongTrame (UC ucLong)
//
// PARAMETRE D'ENTREE: ucLong = longeur de la trame
//
// PARAMETRE DE SORTIE: retourne VRAI ou FAUX 
//
// DATE DE CREATION: 10/10/2013
//
// DATE DE MODIFICATION : -
//***************************************************************************//
UC CLCommunicCom2 :: ucInitLongTrame (UC ucLong)
 {
  ucLongeurTrame = ucLong;
  if (ucLongeurTrame <= ucLongeurTampon) 
   {
    ucLongeurTrame = ucLongeurTampon * 3;
    return VRAI;
   }
  else return FAUX;
 }

//**********************Fonction: ucLireNbCaractRecu*************************//
// DESCRIPTION: Retourne valeur du nb. de caractere recu
//
// PROTOTYPE:   unsigned char ucLireNbCaractRecu (void);
//
// PARAMETRE D'ENTREE: -
//
// PARAMETRE DE SORTIE: ucNbCarRecu: Valeur nb. de carac. recu
//
// DATE DE CREATION: 10/10/2013
//
// DATE DE MODIFICATION : -
//***************************************************************************//
UC CLCommunicCom2 :: ucLireNbCaractRecu (void)
 {
  return ucNbCarRecu;
 }

//**********************Fonction: ucLireEtatTrame****************************//
// DESCRIPTION: Retourne l'etat de la trame (completee ou pas)
//
// PROTOTYPE:   unsigned char ucLireEtatTrame (void);
//
// PARAMETRE D'ENTREE: -
//
// PARAMETRE DE SORTIE: ucEtatTrame: Etat de la trame (complete ou pas)
//
// DATE DE CREATION: 10/10/2013
//
// DATE DE MODIFICATION : -
//***************************************************************************//
UC CLCommunicCom2 :: ucLireEtatTrame (void)
 {
  return ucEtatTrame;
 }

//**********************Fonction: *ucpLireTrame******************************//
// DESCRIPTION: Remet l'etat de la trame a zero et retourne la trame
//
// PROTOTYPE:   unsigned char *ucpLireTrame(void);
//
// PARAMETRE D'ENTREE: -
//
// PARAMETRE DE SORTIE: ucTabReception: Valeur trame
//
// DATE DE CREATION: 10/10/2013
//
// DATE DE MODIFICATION : -
//***************************************************************************//
UC *CLCommunicCom2 :: ucpLireTrame (void)
 { 
  EA = 0;  
  if (ucValideTrame())
    {    
     EA = 1; 
     
     return (ucpDebutTampon);  
    } 
  else
    {
     EA = 1;  
     return (NULL);
    }
 }

//************************Fonction: ucValideTrame ****************************//
// DESCRIPTION: Permet de transmettre un caractere sur ecran PC
//
// PROTOTYPE:   void ucValideTrame (void);
//
// PARAMETRE D'ENTREE: Aucun
//
// PARAMETRE DE SORTIE: Aucun
//
// DATE DE CREATION: 10/10/2013
//
// DATE DE MODIFICATION : -
//***************************************************************************//
UC CLCommunicCom2 :: ucValideTrame (void)
 {
   UC ucCheck      = 0;
   UC ucTemp       = 0;
   UC ucChecksum   = 0;
   UC ucVraiOuFaux = 0;
   UC ucCompteur   = 0;
   
   if (ucLireEtatTrame ())
    {   
      ucpLectureTampon = ucpDebutTampon;
      
      ucCheck = ucCheck + ucpLectureTampon[ucCompteur];
      while(ucCompteur < (ucLongeurTrame - 3)) 
       {
          ucCompteur ++;
          ucCheck = ucCheck + ucpLectureTampon[ucCompteur];
       }   
      
      ucCompteur++;       
      if(ucpLectureTampon[ucCompteur] > 0x40)
       {
         ucTemp     = ((ucpLectureTampon[ucCompteur] - 0x37) << 4);      
       }
      else
       {
         ucTemp     = ((ucpLectureTampon[ucCompteur] - 0x30) << 4); 
       }
      ucCompteur++; 
      
      if(ucpLectureTampon[ucCompteur] > 0x40)
       {
         ucChecksum = (ucpLectureTampon[ucCompteur] - 0x37);
         ucChecksum = ucChecksum | ucTemp;
       }
      else
       {
         ucChecksum = (ucpLectureTampon[ucCompteur] - 0x30);  
         ucChecksum = ucChecksum | ucTemp;
       }
        
      if (ucCheck == ucChecksum)  ucVraiOuFaux = VRAI;    
      else                        ucVraiOuFaux = FAUX;
    }
   
   else ucVraiOuFaux = FAUX;   
   
   return (ucVraiOuFaux);   
 }

//************************Fonction: vTransCaractere**************************//
// DESCRIPTION: Permet de transmettre un caractere sur ecran PC
//
// PROTOTYPE:   void vTransCaractere (unsigned char ucCar);
//
// PARAMETRE D'ENTREE: unsigned char ucCar: Caractere a transmettre
//
// PARAMETRE DE SORTIE: Aucun
//
// DATE DE CREATION: 10/10/2013
//
// DATE DE MODIFICATION : -
//***************************************************************************//

void CLCommunicCom2 :: vTransCaractere (UC ucCar)
 {
  SBUF2 = ucCar;         //
  while (!TI_2);         // Tant que transmission pas prete, boucle
  TI_2 = 0;              //
 }

//************************Fonction: vTransString*****************************//
// DESCRIPTION: Transmet une string sur le port série
//
// PROTOTYPE: void CLCommunic :: vTransString (UC *ucChaine) 
//
// PARAMETRE D'ENTREE: *ucChaine : pointeur sur la string a transmettre
//
// PARAMETRE DE SORTIE: Aucun
//
// DATE DE CREATION: 10/10/2013
//
// DATE DE MODIFICATION : -
//***************************************************************************//
void CLCommunicCom2 :: vTransString (char *cChaine) 
 {
  UC ucCar = 0;
  while (cChaine[ucCar] != 0x00)        // Tant que pas la fin de la chaine
    {
     vTransCaractere (cChaine [ucCar]); // Transmet le caractere
     ucCar++;                           // Passe au caractere suivant
    }       
 } 

//************************Fonction: vInterruptSerial *************************//
// DESCRIPTION: Interruption sur le port série
//
// PROTOTYPE: __interrupt  void CLCommunic ::   vInterruptSerial (void)  
//
// PARAMETRE D'ENTREE: Aucun
//
// PARAMETRE DE SORTIE: Aucun
//
// DATE DE CREATION: 10/10/2013
//
// DATE DE MODIFICATION : -
//****************************************************************************//

#ifdef UPSD3254A
 #pragma vector = 0x4B  // Place vecteur d'interruption a la bonne adresse
#endif

#ifdef DALLAS89C450
 #pragma vector = 0x3B  // Place vecteur d'interruption a la bonne adresse
#endif

__interrupt void CLCommunicCom2 :: vInterruptSerial (void)
 {  
   EA = 0;                                 // Désactive toute interruption   

   if (RI_2 == 1)                          // Si interruption est par flag série
    {
     if (ucpEcritureTampon == ucpFinTampon)// Si on atteint fin tampon
      {
       ucpEcritureTampon = ucpDebutTampon; // Repositionne curseur debut tampon
      } 
     *ucpEcritureTampon = SBUF2;           //Remise caractère dans tampon
     ucpEcritureTampon++;
     
     if (ucNbCarRecu < ucLongeurTrame)// Si nb. carac. recu < longeur tampon   
      {
       ucNbCarRecu ++;                    // Incremente le compteur de carac.
       ucEtatTrame = 0;                   // Trame non complété
      }
     else 
      { 
       ucNbCarRecu = 0;                   // Reinitialise compteur de caractere
       ucEtatTrame = 1;                   // Trame complete
      }   
     RI_2 = 0;                    // Reinitialise flag d'interruption reception
    }  
   EA = 1;                        // Active interruption
 }


///////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////////////
//
// Description: 
//
// Parametres d'entrees: null
//
// Parametres de sortie: null
//
// Appel de la fonction: void (void);
//
// Cree le  par Vincent Chouinard
//
// Modifications:
// -
//
///////////////////////////////////////////////////////////////////////////////

UC CLCommunicCom2 :: ucCheckSumCalcul(UC uc1, UC uc2, UC uc3)
 { 
   return(uc1 + uc2 + uc3);     
 }

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!



