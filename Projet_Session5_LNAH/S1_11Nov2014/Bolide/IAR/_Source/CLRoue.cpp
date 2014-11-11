// ************************** FICHIER: CLROUE.CPP ***********************
//
// Fonctions pour controler une roue du bolide
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

#include "CLRoue.h"


//// Constructeur par defaut ////////////////////////////////////////////////////

CLRoue :: CLRoue(void)
 {
   ucAdresseRoue = 0;
 }

//// Constructeur initialisateur ////////////////////////////////////////////////
CLRoue :: CLRoue(UC ucAdresse)
 {
   ucAdresseRoue = ucAdresse;
 }

//// Destructeur ////////////////////////////////////////////////////////////////
 
CLRoue :: ~CLRoue(void)
 {
 }

///////////////////////////////////////////////////////////////////////////////
// void CLRoue :: vMarcheAvant(UC ucVitesse)
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

void CLRoue :: vMarcheAvant(UC ucVitesse)
 {
   USI uiVitesseRoue  = ucVitesse;
   
   uiVitesseRoue = uiVitesseRoue << 8;
   uiVitesseRoue = ARRETVARIABLE + uiVitesseRoue;
   vConfigurerDAC6574(ucAdresseRoue, uiVitesseRoue);
 }

///////////////////////////////////////////////////////////////////////////////
// void CLRoue :: vMarcheArriere(UC ucVitesse)
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

void CLRoue :: vMarcheArriere(UC ucVitesse)
 {
   USI uiVitesseRoue  = ucVitesse;
   
   uiVitesseRoue = uiVitesseRoue << 8;
   uiVitesseRoue = ARRETVARIABLE - uiVitesseRoue;
   vConfigurerDAC6574(ucAdresseRoue, uiVitesseRoue);
 }

///////////////////////////////////////////////////////////////////////////////
// void CLRoue :: vArret(void)
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

void CLRoue :: vArret(void)
 { 
   vConfigurerDAC6574(ucAdresseRoue, ARRETVARIABLE);
 }

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@