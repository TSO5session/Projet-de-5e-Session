// ************************** FICHIER: CLSUIVEURLIGNE.CPP **********************
//
// Fonctions de suivie de ligne pour le bolide
//
// Application realisee avec IAR C++ 8.10
//
//
// LIMITATION DU COMPILATEUR:
// Impossible de faire de l'heritage multiple.
//
// Note: on peut utiliser XAR pour creer des librairies.
// On peut mettre les librairies dans le projets et Exclure de la compilation
// les modules qui sont contenus dans la librairie.
//
// Pour Windows 7 on utilise la VMware pour programmer le upsd 3254A avec CAPS.
//
// AUTEUR : LOUIS-NORMAND ANG HOULE
// DATE CREATION : 2014/04/17 VERSION: 1.0
// DATE MODIFICATION: ****-**-**
//
// *****************************************************************************
#include "CLSuiveurLigne.h"


//******************************************************************************
//                            LE CONSTRUCTEUR PAR DEFAUT
// *****************************************************************************
CLSuiveurLigne :: CLSuiveurLigne(void)
{

}
//******************************************************************************
//                            LE CONSTRUCTEUR INITIALISATEUR
// *****************************************************************************
CLSuiveurLigne :: CLSuiveurLigne(UC ucAdresse) 
{
   
} 

// *****************************************************************************
//                            LE DESTRUCTEUR
// *****************************************************************************
CLSuiveurLigne :: ~CLSuiveurLigne(void)
{
   
}
///////////////////////////////////////////////////////////////////////////////
// UC CLSuiveurLigne :: ucLireCapteurs(void)
///////////////////////////////////////////////////////////////////////////////
//
// Description: Renvoi l'état des capteurs 
//
// Parametres d'entrees: null
//
// Parametres de sortie: null
//
// Appel de la fonction: ucLireCapteurs();
//
// Cree le 04/12/2014 par Louis-Normand Ang Houle
//
// Modifications:
// -
//
///////////////////////////////////////////////////////////////////////////////

UC CLSuiveurLigne :: ucLireCapteurs(void)
{
   #ifdef SPI_DALLAS 
   clMCP23S09Suiveur.vSetModeMCP23S09(LECTURE_MCP23S09, 0xFF);
   return(clMCP23S09Suiveur.ucLireMCP23S09());
   #endif
   
   #ifdef I2C_DALLAS
   return(clIOPCF8574Suiveur.ucLireIOPCF());
   #endif 
}

///////////////////////////////////////////////////////////////////////////////
// UC CLSuiveurLigne :: ucSuivreLigne(void)
///////////////////////////////////////////////////////////////////////////////
//
// Description: Renvoi la direction 
//
// Parametres d'entrees: null
//
// Parametres de sortie: DIRECTION
//
// Appel de la fonction: ucSuivreLigne();
//
// Cree en mai 2014 par Louis-Normand Ang Houle
//
// Modifications:
// -
//
///////////////////////////////////////////////////////////////////////////////
UC CLSuiveurLigne :: ucSuivreLigne(void)
 {  
   UC    ucDirection;
   
   #ifdef SPI_DALLAS 
   clMCP23S09Suiveur.vSetModeMCP23S09(LECTURE_MCP23S09, 0xFF);
   
   unSuiveurLigne.ucOctet = clMCP23S09Suiveur.ucLireMCP23S09(); 
  
   if((unSuiveurLigne.stChampBit.bBit5 == 1) & //Tous les senseurs sont ouverts.
      (unSuiveurLigne.stChampBit.bBit7 == 1))   //Le senseur central est actif.
    {
      ucDirection = DROITDEVANT;
    }   
   else
 
   if(unSuiveurLigne.stChampBit.bBit5 == 0)
     {
      ucDirection = DROITE;
     }
   
   if(unSuiveurLigne.stChampBit.bBit7 == 0)
     { 
      ucDirection = GAUCHE;
     }
   return(ucDirection);
   #endif
   
   #ifdef I2C_DALLAS
   unSuiveurLigne.ucOctet = clIOPCF8574Suiveur.ucLireIOPCF();    
       
   if((unSuiveurLigne.stChampBit.bBit5 == 1) & //Tous les senseurs sont ouverts.
      (unSuiveurLigne.stChampBit.bBit7 == 1))   //Le senseur central est actif.
    {
      ucDirection = DROITDEVANT;
    }          
   else        
    {
     if(unSuiveurLigne.stChampBit.bBit5 == 0)
       {
        ucDirection = DROITE;
       }       
     if(unSuiveurLigne.stChampBit.bBit7 == 0)
       { 
        ucDirection = GAUCHE;
       }
    } 
   if((!unSuiveurLigne.stChampBit.bBit7) &&
      (!unSuiveurLigne.stChampBit.bBit6) &&
      (!unSuiveurLigne.stChampBit.bBit5))
      {ucDirection = DROITVITE;}
   
   return(ucDirection);
   #endif   
 }

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@