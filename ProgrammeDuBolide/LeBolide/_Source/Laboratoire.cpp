// ************************** FICHIER: Laboratoire.CPP ***********************
//
// Fonctions pour laboratoires
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
// DATE CREATION : 2014/08/26 VERSION: 1.0
// DATE MODIFICATION: ****-**-**
//
// *****************************************************************************
#include "Laboratoire.h"
#include "DeclarationGenerale.h"

void main(void)
 { 
   #ifdef UPSD3254A
   WDKEY = 0x55;
   #endif   
   
   class CLTest clTest;    // Declaration d'un objet de test
   clTest.vControleTest(); // Fonctions de test
   
   while(1)
    {      

    }  
 }
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@