// ************************** FICHIER: CLCAPTEURDISTANCE.CPP *******************
//
// Fonctions de lecture d'un senseur de proximite GP2D12 avec un ADC I2C MAX1236
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
// DATE CREATION : 2014/04/22 VERSION: 1.0
// DATE MODIFICATION: ****-**-**
//
// *****************************************************************************

#include "CLCapteurDistance.h"


/// Constructeur par defaut ////////////////////////////////////////////////////

CLCapteurDistance :: CLCapteurDistance(void)
 {
   ucAdrCapteur = SENSEURDROITE; 
 }
/// Constructeur Initialisateur ////////////////////////////////////////////////

CLCapteurDistance :: CLCapteurDistance(UC ucAdresse)
 {
   ucAdrCapteur = ucAdresse;
 }
/// Destructeur ////////////////////////////////////////////////////////////////

CLCapteurDistance :: ~CLCapteurDistance(void)
{
}

///////////////////////////////////////////////////////////////////////////////
// USI CLCapteurDistance :: uiLireCapteur(void)
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

USI CLCapteurDistance :: uiLireCapteur(void)
{
  return(uiLireValeur(ucAdrCapteur));
}

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@