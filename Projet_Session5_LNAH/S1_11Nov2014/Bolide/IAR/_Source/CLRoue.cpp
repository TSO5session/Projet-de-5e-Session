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
   ucAdresseRoue = 0x00;
 }

CLRoue :: CLRoue(UC ucVal)
 {
   ucAdresseRoue = ucVal;
 }

//// Destructeur ////////////////////////////////////////////////////////////////
 
CLRoue :: ~CLRoue(void)
 {
 }

///////////////////////////////////////////////////////////////////////////////
// void CLRoue :: vMarcheAvant(UC ucVitesse)
///////////////////////////////////////////////////////////////////////////////
//
// Description: Marche avant pour la roue
//
// Parametres d'entrees: uiVitesse(0x0000 a 0x07FF)
//
// Parametres de sortie: null
//
// Appel de la fonction: clRoue.vMarcheAvant(0xXXXX);
//
// Cree le 2014/11/13 par Louis-Normand Ang Houle
//
// Modifications:
// -
//
///////////////////////////////////////////////////////////////////////////////

void CLRoue :: vMarcheAvant(USI uiVitesse)
 {
   #ifdef SPI_DALLAS
   uiVitesse = uiVitesse & 0x0FFF;
   uiVitesse = ARRETVARIABLE + uiVitesse;
   clDAC7554Roue.vWriteChannel(uiVitesse, ucAdresseRoue);
   #endif
   
   #ifdef I2C_DALLAS
   uiVitesse = uiVitesse << 8;
   uiVitesse = ARRETVARIABLE + uiVitesse;
   clDAC6574Roue.vConfigurerDAC6574(ucAdresseRoue, uiVitesse);
   #endif
 }

///////////////////////////////////////////////////////////////////////////////
// void CLRoue :: vMarcheArriere(UC ucVitesse)
///////////////////////////////////////////////////////////////////////////////
//
// Description: Marche arriere pour la roue
//
// Parametres d'entrees: uiVitesse(0x0000 a 0x07FF)
//
// Parametres de sortie: null
//
// Appel de la fonction: clRoue.vMarcheArriere(0xXXXX);
//
// Cree le  2014/11/13 par Louis-Normand Ang Houle
//
// Modifications:
// -
//
///////////////////////////////////////////////////////////////////////////////

void CLRoue :: vMarcheArriere(USI uiVitesse)
 {
   #ifdef SPI_DALLAS
   uiVitesse = uiVitesse & 0x0FFF;
   uiVitesse = ARRETVARIABLE - uiVitesse;
   clDAC7554Roue.vWriteChannel(uiVitesse, ucAdresseRoue);
   #endif
   
   #ifdef I2C_DALLAS
   uiVitesse = uiVitesse << 8;
   uiVitesse = ARRETVARIABLE - uiVitesse;
   clDAC6574Roue.vConfigurerDAC6574(ucAdresseRoue, uiVitesse);
   #endif   
 }

///////////////////////////////////////////////////////////////////////////////
// void CLRoue :: vArret(void)
///////////////////////////////////////////////////////////////////////////////
//
// Description: Arrete la roue 
//
// Parametres d'entrees: null
//
// Parametres de sortie: null
//
// Appel de la fonction: clRoue.vArret();
//
// Cree le 2014/11/13 par Louis-Normand Ang Houle
//
// Modifications:
// -
//
///////////////////////////////////////////////////////////////////////////////

void CLRoue :: vArret(void)
 { 
   #ifdef SPI_DALLAS
   clDAC7554Roue.vWriteChannel(ARRETVARIABLE, ucAdresseRoue);
   #endif
   
   #ifdef I2C_DALLAS
   clDAC6574Roue.vConfigurerDAC6574(ucAdresseRoue, ARRETVARIABLE);
   #endif   
 }

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@