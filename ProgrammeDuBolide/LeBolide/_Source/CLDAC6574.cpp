// ************************** FICHIER: CLDAC6574.CPP ***********************
//
// Fonctions pour le convertisseur digital -> analogue I2C DAC6574
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
// DATE CREATION : 2014/04/16 VERSION: 1.0
// DATE MODIFICATION: ****-**-**
//
// *****************************************************************************

#include "CLDAC6574.h"


// Constructeur par defaut ////////////////////////////////////////////////////

CLDAC6574 :: CLDAC6574(void)
 {
   ucAdresseDAC6574 = ADRDAC6574;
 }

// Constructeur initialisateur ////////////////////////////////////////////////

CLDAC6574 :: CLDAC6574(UC ucAdresse)
 {
   ucAdresseDAC6574 = ucAdresse;  
 }

// Destructeur ////////////////////////////////////////////////////////////////

CLDAC6574 :: ~CLDAC6574(void)
 {
 }

///////////////////////////////////////////////////////////////////////////////
// void vConfigurerDAC6574(UC ucCanal, UC ucValeur);
///////////////////////////////////////////////////////////////////////////////
//
// Description: Fonction pour configurer le DAC6574  
//
// Parametres d'entrees 
// -UC ucCanal : Numero du canal
// -UC ucValeur: Tension à envoyer
//
// Parametres de sortie: null
//
// Appel de la fonction: vConfigurerDAC6574(UC ucCanal, UC ucValeur);
//
// Cree le  par Louis-Normand Ang Houle
//
// Modifications:
// -
//
///////////////////////////////////////////////////////////////////////////////

void CLDAC6574 :: vConfigurerDAC6574(UC ucCanal, USI uiValeur)
 { 
   union UNOctetBit unCanal;
   union UNEntierOctet unValeur;
   
   UC uctTableau[3]; 
   
   unCanal.ucOctet   = CONFIG6574; 
   
   switch(ucCanal)
    {
//------------------------------------------------------------------------------   
      case 0:
        unCanal.stChampBit.bBit1 = 0;
        unCanal.stChampBit.bBit2 = 0;
      break;
//------------------------------------------------------------------------------         
      case 1:
        unCanal.stChampBit.bBit1 = 1;
        unCanal.stChampBit.bBit2 = 0;
      break;
//------------------------------------------------------------------------------         
      case 2:
        unCanal.stChampBit.bBit1 = 0;
        unCanal.stChampBit.bBit2 = 1;
      break;
//------------------------------------------------------------------------------         
      case 3:
        unCanal.stChampBit.bBit1 = 1;
        unCanal.stChampBit.bBit2 = 1;
      break;
//------------------------------------------------------------------------------   
    }
   
   unValeur.uiEntier = uiValeur;
   
   uctTableau[0] = unCanal.ucOctet;
   uctTableau[1] = unValeur.stDeuxOctet.ucOctet2;
   uctTableau[2] = unValeur.stDeuxOctet.ucOctet1; 
 
   vI2CEcrireDonnee(ucAdresseDAC6574, NULL, PASADR, uctTableau, 3);  
 }

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@