// ************************** FICHIER: CLTLV2554.CPP ***********************
//
// Fonctions pour le convertisseur analogue->digital SPI TLV2554
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
//          HICHAM SAFOINE
//          GABRIEL FORTIN-BELANGER
//          VINCENT CHOUINARD
// DATE CREATION : 2014/11/11 VERSION: 1.0
// DATE MODIFICATION: ****-**-**
//
// *****************************************************************************

#include "CLTLV2544.h"


// Constructeur par defaut ////////////////////////////////////////////////////

CLTLV2544 :: CLTLV2544(void)
 {
   SLVSLCT_TLV2554 = 0;
   ucSPITransferMOD0(0xA0);
   ucSPITransferMOD0(0x00);   
   SLVSLCT_TLV2554 = 1; 
   
   SLVSLCT_TLV2554 = 0;
   ucSPITransferMOD0(0xA8);
   ucSPITransferMOD0(0x00);   
   SLVSLCT_TLV2554 = 1; 
 }

// Constructeur initialisateur ////////////////////////////////////////////////

CLTLV2544 :: CLTLV2544(UC ucMode)
 {
   SLVSLCT_TLV2554 = 1;
 }

// Destructeur ////////////////////////////////////////////////////////////////

CLTLV2544 :: ~CLTLV2544(void)
 {
 }

///////////////////////////////////////////////////////////////////////////////
// USI uiLireConversion(UC ucCanal);
///////////////////////////////////////////////////////////////////////////////
//
// Description: Lecture d
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

USI CLTLV2544 :: uiLireConversion(UC ucCanal)
 {
   UNEntierOctet unLecture;
     
   ucCanal = ucCanal << 4;
   
   SLVSLCT_TLV2554 = 0;
   unLecture.stDeuxOctet.ucOctet1 = ucSPITransferMOD0(ucCanal);
   unLecture.stDeuxOctet.ucOctet2 = ucSPITransferMOD0(0x00);
   SLVSLCT_TLV2554 = 1;
   
   return unLecture.uiEntier;
 }

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@