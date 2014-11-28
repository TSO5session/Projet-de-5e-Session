// ************************** FICHIER: CLLIMITEVITESSE.CPP *********************
//
// Fonctions pour la limitation de la vitesse du bolide
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
// DATE CREATION : 2014/04/24 VERSION: 1.0
// DATE MODIFICATION: ****-**-**
//
// *****************************************************************************

#include "CLLimiteVitesse.H"


// Constructeur par defaut ////////////////////////////////////////////////////

CLLimiteVitesse :: CLLimiteVitesse(void)
 {
 }

// Destructeur ////////////////////////////////////////////////////////////////

CLLimiteVitesse :: ~CLLimiteVitesse(void)
 {
 }

///////////////////////////////////////////////////////////////////////////////
// USI CLLimiteVitesse :: uiLimiteVitesse(void)
///////////////////////////////////////////////////////////////////////////////
//
// Description: 
//
// Parametres d'entrees: null
//
// Parametres de sortie: La limite de vitesse (unsigned short)
//
// Appel de la fonction: uiLimiteVitesse();
//
// Cree le 2014/04/24 par Louis-Normand Ang Houle
//
// Modifications:
// -
//
///////////////////////////////////////////////////////////////////////////////

UC CLLimiteVitesse :: ucLimiteVitesse(void)
 {
   USI uiTemp1;
   UC ucTemp2;  
   uiTemp1 = uiLireValeur(LIMVITESSE);
   ucTemp2 = ((uiTemp1 >> 4)/2);
     
   return(ucTemp2);
 }

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@