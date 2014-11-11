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
//                
//                
//                
//
//  AUTEUR :Gabriel Fortin-Belanger
//  DATE CREATION :    27/03/2014		 VERSION: 1.0
//
// ****************************************************************************
#include "CLInOutBase.h"
#include "_DeclarationGenerale.h"
#include "CLCommunic.h"



//***********************************Constante**********************************
#define LONGEURTRAME  7
#define LONGEURBUFFER 8
//******************************************************************************


 UC * CLCommunic::ucpDebutTampon = 0;
 UC * CLCommunic::ucpFinTampon = 0;
 UC * CLCommunic::ucpEcritureTampon = 0;
 UC * CLCommunic::ucpLireTampon = 0;
 UC   CLCommunic::ucLongeurTampon = 0;
 UC   CLCommunic::ucLongeurTrame = 0;
 UC   CLCommunic::ucCompteurCarac = 0;
 UC   CLCommunic::ucTrameRecu = 0;



//***********************CLCommunic(void)
//
//Description:Constructeur par defaut initialise la longeur du buffer, de la 
//            trame et positionne les pointeur  de la memoire allouer.
//           
//           
// NOM: CLCommunic::CLCommunic(void)
//           
// PARAMETRE D'ENTREE: Aucun
//                   
// 
//
// PARAMETRE DE SORTIE: Aucun              
//
//    
//
// DATE DE CREATION: 10 octobre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************
CLCommunic::CLCommunic(void)
{
  ucInitLongTrame(LONGEURTRAME);
  
  ucLongeurTampon = LONGEURBUFFER;
  ucpDebutTampon = new(UC[LONGEURBUFFER]);
  ucpFinTampon = ucLongeurTrame + ucpDebutTampon;
  ucpEcritureTampon = ucpDebutTampon;
  ucpLireTampon  = ucpDebutTampon;
 
  vInitBaudRate(19200);

}

//***********************CLCommunic(UC ucLongBuf, UC ucLongTrame,UINT uiBaud)
//
//Description:Constructeur par defaut initialise la longeur du buffer, de la 
//            trame et positionne les pointeur  de la memoire allouer.
//           
//           
// NOM: CLCommunic::CLCommunic(UC ucLongBuf, UC ucLongTrame,UINT uiBaud)
//           
// PARAMETRE D'ENTREE: Aucun
//                   
// 
//
// PARAMETRE DE SORTIE: Aucun              
//
//    
//
// DATE DE CREATION: 10 octobre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************

CLCommunic::CLCommunic(UC ucLongBuf, UC ucLongTrame,UINT uiBaud)
{
  ucLongeurTampon = ucLongBuf;
  ucInitLongTrame(ucLongTrame);
  
  ucpDebutTampon = new(UC[ucLongeurTampon]);
  ucpFinTampon = (ucLongeurTampon + ucpDebutTampon) ;
  ucpEcritureTampon = ucpDebutTampon;
  ucpLireTampon  = ucpDebutTampon;
  vInitBaudRate(uiBaud);

}

//***********************~CLCommunic(void)
//
//Description:Destructeur qui desalloue lA MEMOIRE
//           
//           
// NOM: CLCommunic::~CLCommunic(void)
//           
// PARAMETRE D'ENTREE: Aucun
//                   
// 
//
// PARAMETRE DE SORTIE: Aucun              
//
//    
//
// DATE DE CREATION: 10 octobre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//***************************************************************************** 


CLCommunic::~CLCommunic(void)
{
  delete[] ucpDebutTampon; 

}


//***********************Fonction:ucInitLongTrame**************************
//
// Description:     Cette fonction initialise 
//
// Prototype: UC CLCommunic :: ucInitLongTrame(UC ucLong)
// 
// PARAMETRE D'ENTREE:Aucun
//
// PARAMETRE DE SORTIE:true or False            
//
//
//
// DATE DE CREATION: 26 septembre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//***************************************************************************** 
UC CLCommunic :: ucInitLongTrame(UC ucLong)
{
  if(ucLong < ucLongeurTampon)
  {
    ucLongeurTrame = ucLong;
    return(1);    
  }
  else
  {
   
  return(0);
  }

}


//***********************Fonction:ucLireNbCaractRecu**************************
//
// Description:     Cette fonction retourne le nombre de caractere recu
//
// Prototype: UC ucLireNbCaractRecu(void);
// 
// PARAMETRE D'ENTREE:Aucun
//
// PARAMETRE DE SORTIE: ucNbCarctRecu              
//
//
//
// DATE DE CREATION: 26 septembre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//***************************************************************************** 


UC CLCommunic :: ucLireNbCaractRecu(void)
{

  return(ucCompteurCarac);

}


//***********************Fonction:ucLireEtatTrame******************************
//
// Description: Cette fonction retourne une variable contenant l'etat 
//              de trame qui indique si elle est recu         
//
// Prototype:UC CLCommunic :: ucLireEtatTrame(void);
// 
// PARAMETRE D'ENTREE:Aucun
//
// PARAMETRE DE SORTIE: ucTrameComplete              
//
//
//
// DATE DE CREATION: 26 septembre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************  

UC CLCommunic :: ucLireEtatTrame(void)
{
  return(ucTrameRecu);

}


//***********************Fonction:*ucpLireTrame********************************
//
// Description:     Cette fonction retourne un pointeur sur le debut d'une 
//                  trame recu
//
// Prototype: UC * CLCommunic :: ucpLireTrame(void)
// 
// PARAMETRE D'ENTREE:Aucun
//
// PARAMETRE DE SORTIE: ucTampon              
//
//
//
// DATE DE CREATION: 26 septembre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************
UC * CLCommunic :: ucpLireTrame(void)
{
  
   ucTrameRecu = INCOMPLETE;
  //if(ucValideTrame())
  //{
    return(ucpDebutTampon);
  //}
  //else
  //{
  //  return(NULL);
  
  //}

}


//***********************Fonction:vTransCaractere******************************
//
// Description:     Cette fonction permet D'envoyer un caractere sur le 
//                  port serie
//
// Prototype:void CLCommunic :: vTransCaractere(UC ucCar)
// 
// PARAMETRE D'ENTREE:ucCar 
//
// PARAMETRE DE SORTIE:Aucun              
//
//
// PROCEDURES APPELEES: vTransCaractere(ucCar);
//
// DATE DE CREATION: 26 septembre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************

void CLCommunic :: vTransCaractere(UC ucCar)
{

   SBUF = ucCar;	   //place le caractere dans le buffer
   while(TI_0 == 0);  //Polling du flag de transmission
   TI_0 = 0;		   //Remise Flag a 0;
   
   
}



//***********************Fonction:vTransCaractere******************************
//
// Description:     Cette fonction permet D'envoyer une chaine sur le 
//                  port serie
//
// 
// Prototype:void CLCommunic :: vTransCaractere(UC ucCar)
// 
// PARAMETRE D'ENTREE:char const * ucChaine)
//
// PARAMETRE DE SORTIE:Aucun              
//
//
//
// DATE DE CREATION: 26 septembre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************

void CLCommunic :: vTransString(char const * ucChaine)
{

  while(*ucChaine != 0)
  {
    vTransCaractere(*ucChaine);
    ucChaine ++; 
  
  }

}

/*
***********************Fonction:vInteruptSerial()****************************
//
// Description: Cette fonction permet de traiter une interuption serie
//
// NOM:__interrupt void  CLCommunic :: vInteruptSerial(void) 
// 
// PARAMETRE D'ENTREE:Aucun 
//
// PARAMETRE DE SORTIE:Aucun              
//
// DATE DE CREATION: 26 septembre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
*****************************************************************************

#pragma vector = 0x23
 __interrupt void  CLCommunic :: vInteruptSerial(void)
 {
    EA = 0;        //Desactive les interuptions
   
   if(RI_0)       //Si Reception
    {  
       
      if(ucpEcritureTampon == ucpFinTampon ) //Si Tampon est plein
       {                                     //
         ucpEcritureTampon = ucpDebutTampon; //Repartir a 0
       }
      
      *ucpEcritureTampon = SBUF0; //Stocke le caractere recu dans tampon
      ucpEcritureTampon = ucpEcritureTampon + 1;// increment une position dans tampon
      if(ucCompteurCarac < (ucLongeurTampon-1)) //Si nombre caract recu est 
       {                                   //inferieur a Trame
          ucCompteurCarac = ucCompteurCarac +1;  //incremente le caractere
          ucTrameRecu = INCOMPLETE;
       }
      else                                 //sinon
       {
        ucCompteurCarac = 0;          //Remettre caractere a 0
        ucTrameRecu = COMPLETE;       //Trame complete vaut vrai
        ucpEcritureTampon = ucpDebutTampon;
        ucpLireTampon  = ucpDebutTampon;
        //ucpLireTampon = ucpEcritureTampon - ucLongeurTrame;
       }


     
    }
     RI_0 = 0;                           //reinitialise flag reception
     EA   = 1;                           // re initialise les interuptions
     
 
 
 }

*/
//***********************Fonction:vInitBaudRate********************************
//
// Description:     Cette fonction permet de d'initialiser le Baud rate aux  
//                  vitesse: 2400,488,9600,19200,28800,57600
//
//
// NOM:void CLCommunic :: vInitBaudRate(UINT uiBaud)
// 
// PARAMETRE D'ENTREE:UINT uiBaud
//
// PARAMETRE DE SORTIE:Aucun              
//
//
//
//
// DATE DE CREATION: 26 septembre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************
void CLCommunic :: vInitBaudRate(UINT uiBaud)
{
 
   SCON = 0x50;            // Met le registre SCON0 a 00
   SM1_0 = 1;               //Mode asynchrone, generateur baud rate           
   REN_0 = 1;               //Active la reception
   TMOD= TMOD | 0x20;      //Timer 1 en 8 bit auto-relod
   PCON = PCON| 0x80;      //vitesse doubler pour serie
   TR1   = 1;               // Active timer 1 pour fonctionner le port serie
   TI_0  = 1;               // TI a 1  transmet un premier charactere
   EA = 1;                  //Active les interuptions 
   RI_0 = 0;                  //initialise Reception
   ES0 = 1;                 //Active interuption serie
   ET1 = 0;                 //Desactive timer 1

   switch(uiBaud)             //Condtion pour selectionner choix utilisateur
    { 
      case 2400: TH1 = 0xE8;      // Baud rate 2400
                 TL1 = 0xE8;      //
                 break;           //
      case 4800: TH1 = 0xF4;      // Baud rate 4800
                 TL1 = 0xF4;      //
                 break;           //
      case 9600: TH1 = 0xFA;      // Baud rate 9600
                 TL1 = 0xFA;      //
                 break;           //
      case 19200:TH1 = 0xFD;      // Baud rate 19200
                 TL1 = 0xFD;      //
                 break;           //
      case 28800:TH1 = 0xFE;      // Baud rate 28800
                 TL1 = 0xFE;       //
                 break;           //
      case 57600:TH1 = 0xFF;      // Baud rate 57600
                 TL1 = 0xFF;      //
                 break;           //

     
   }


}



//***********************Fonction:ucValideTrame********************************
//
// Description: Cette fonction permet de verifier qu'une trame valide est recu
//
//
// NOM:void CLCommunic :: vInitBaudRate(UINT uiBaud)
// 
// PARAMETRE D'ENTREE:-
//
// PARAMETRE DE SORTIE:Aucun              
//
//
//
//
// DATE DE CREATION: 26 septembre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************

UC CLCommunic :: ucValideTrame(void)
{
  UC ucConte;
  while(ucpLireTampon < ucpFinTampon )
  {
    ucConte = ucConte + *ucpLireTampon;
    ucpLireTampon ++;
  } 
  
  if( ucConte == *ucpFinTampon)
  {
    return(1);
  
  }
else
  {
    return(0);
  }


}

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@