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
#include "TypeCible.h"
#include "ProjetBolide.h"
#include "Station1.h"     // Fichier de definitions de la station uPSD
#include "CLXBEE.h"

void main(void)
 { 
  class CLTest clTest;    // Declaration d'un objet de test
     
#ifdef DALLAS89C450   
   class CLVehicule Vehicule;
  // class CLXbee     Xbee;

   while(1)
    {      
      //Vehicule.vControleBolide();
      //Xbee.SendString("Hello ");
      Vehicule.BattryInfo();
    }  
#endif
   
#ifdef UPSD3254A
   class CLStation1 StationUPSD;
   WDKEY = 0x55;
   
   while(1)
    {
      StationUPSD.SendToPC    ("Hodor");
      StationUPSD.SendToPIC   ("Hodor");
      StationUPSD.SendToSOC   ("Hodor");
      StationUPSD.SendToBolide("Hodor");
      StationUPSD.SendToFesto ("Hodor");           
    } 
#endif  
 }
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@