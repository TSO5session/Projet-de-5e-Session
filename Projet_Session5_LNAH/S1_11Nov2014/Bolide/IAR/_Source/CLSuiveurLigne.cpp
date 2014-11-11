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


//// Constructeur par defaut ///////////////////////////////////////////////////

CLSuiveurLigne :: CLSuiveurLigne(void):
CLIOPCF8574(0x44)
 {
   
 }

//// Constructeur Initialisateur ///////////////////////////////////////////////

CLSuiveurLigne :: CLSuiveurLigne(UC ucAdresse): 
CLIOPCF8574(ucAdresse)  
 {
   
 } 

//// Destructeur ///////////////////////////////////////////////////////////////

CLSuiveurLigne :: ~CLSuiveurLigne(void)
 {
   
 }

///////////////////////////////////////////////////////////////////////////////
// UC CLSuiveurLigne :: ucSuivreLigne(void)
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
// Cree le  par Louis-Normand Ang Houle
//
// Modifications:
// -
//
///////////////////////////////////////////////////////////////////////////////

UC CLSuiveurLigne :: ucSuivreLigne(void)
 {
   union UNOctetBit unSuiveurLigne;
   UC    ucDirection;
   
   unSuiveurLigne.ucOctet = ucLireIOPCF(); 
  
   if(unSuiveurLigne.ucOctet == 0xFE) ucDirection = DROITE; 
   
   if((unSuiveurLigne.ucOctet == 0xC0) || //Tous les senseurs sont ouverts.
      (unSuiveurLigne.ucOctet == 0xC8) || //Le senseur central est actif.
      (unSuiveurLigne.ucOctet == 0x18) || //Centre + CentreGauche
      (unSuiveurLigne.ucOctet == 0x0C) || //Centre + CentreDroite
      (unSuiveurLigne.ucOctet == 0xDC))   //Centre + CentreDroite + CentreGauche
    {
      ucDirection = DROITDEVANT;
    }   
   
   else
    {
      if(unSuiveurLigne.stChampBit.bBit1 == 1)
       {
         ucDirection = GAUCHE;
       }
      if(unSuiveurLigne.stChampBit.bBit2 == 1)
       {
         ucDirection = GAUCHELENT;
       }
      if(unSuiveurLigne.stChampBit.bBit5 == 1)
       { 
         ucDirection = DROITE;
       }
      if(unSuiveurLigne.stChampBit.bBit4 == 1)
       {
         ucDirection = DROITELENT;
       }
    } 

   return(ucDirection);
 }

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@