// ************************** FICHIER: CLIOPCF8574.CPP ***********************
//
// Fonctions pour carte d'extension I/O I2C PCF8574
//
// Application realisee avec IAR C++ 8.10
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
// DATE CREATION : 2014/11/14 VERSION: 1.0
// DATE MODIFICATION: ****-**-**
//
// *****************************************************************************
#include "CLIOPCF8574.h"

// Constructeur par defaut ////////////////////////////////////////////////////
CLIOPCF8574 :: CLIOPCF8574(void)
 {
   ucAdresseIOPCF = ADRIOPCF;
 }

// Constructeur initialisateur ////////////////////////////////////////////////
CLIOPCF8574 :: CLIOPCF8574(UC ucAdresse)
 {
   ucAdresseIOPCF = ucAdresse; 
 }

// Destructeur ////////////////////////////////////////////////////////////////
CLIOPCF8574 :: ~CLIOPCF8574(void)
 {
   
 }

///////////////////////////////////////////////////////////////////////////////
// UC CLIOPCF8574 :: ucLireIOPCF(void)
///////////////////////////////////////////////////////////////////////////////
//
// Description: Lecture de l'etat des bits du port
//
// Parametres d'entrees: null
//
// Parametres de sortie 
// - unIOPCF.ucOctet: Etat des bits du port
//
// Appel de la fonction: CLIOPCF8574.ucLireIOPCF();
//
// Cree le 2014/04/16 par Louis-Normand Ang Houle
//
// Modifications:
// -
//
///////////////////////////////////////////////////////////////////////////////
UC CLIOPCF8574 :: ucLireIOPCF(void)
{
return(LirePCF8574());
}

///////////////////////////////////////////////////////////////////////////////
// void CLIOPCF8574 :: vEcrireIOPCF(UC ucDonnee)
///////////////////////////////////////////////////////////////////////////////
//
// Description: Modifie l'etat des bits du port
//
// Parametres d'entrees 
// - ucDonnee: 
//
// Parametres de sortie: null
//
// Appel de la fonction: CLIOPCF8574.vEcrireIOPCF(UCDONNEE);
//
// Cree le 2014/04/16 par Louis-Normand Ang Houle
//
// Modifications:
// -
//
///////////////////////////////////////////////////////////////////////////////
void CLIOPCF8574 :: vEcrireIOPCF(UC ucDonnee)
 {
   UC uctDonnee[1];
   uctDonnee[0] = ucDonnee;
     
   vI2CEcrireDonnee(ucAdresseIOPCF, NULL, PASADR, uctDonnee, 1);   
 }

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@