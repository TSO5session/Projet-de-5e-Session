// ************************** FICHIER: CLDAC7554.CPP ***********************
//
// Fonctions pour le convertisseur digital->analogue SPI DAC7554
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
// DATE CREATION : 2014/11/11 VERSION: 1.0
// DATE MODIFICATION: ****-**-**
//
// *****************************************************************************

#include "CLDAC7554.h"


// Constructeur par defaut ////////////////////////////////////////////////////
CLDAC7554 :: CLDAC7554(void)
 {
 }

// Constructeur initialisateur ////////////////////////////////////////////////
CLDAC7554 :: CLDAC7554(UC ucAdresse)
 {
   SLVSLCT_DAC7554 = 1;
 }

// Destructeur ////////////////////////////////////////////////////////////////
CLDAC7554 :: ~CLDAC7554(void)
 {
 }

///////////////////////////////////////////////////////////////////////////////
//void vWriteChannel(USI uiValue, UC ucChannel)
///////////////////////////////////////////////////////////////////////////////
//
// Description: Ecriture d'une valeur sur un canal du DAC7554
//
// Parametres d'entrees: 
// -uiValue  :  Valeur ecrite sur un canal (0x0000 à 0x0FFF)
// -ucChannel:  Numero du canal (0 à 3)
//
// Parametres de sortie: null
//
// Appel de la fonction: void vWriteChannel(USI uiValue, UC ucChannel);
//
// Cree le 6 octobre 2014 par Louis-Normand Ang Houle
//
// Modifications:
// -
//
///////////////////////////////////////////////////////////////////////////////

void CLDAC7554 :: vWriteChannel(USI uiValue, UC ucChannel)
{
  SLVSLCT_DAC7554 = 0;     
     UC ucData = (ucChannel << 4) | (uiValue >> 8); 
     ucSPITransferMOD0(ucData);
     ucData |= uiValue;  
     ucSPITransferMOD0(ucData);
  SLVSLCT_DAC7554 = 1;    

}

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@