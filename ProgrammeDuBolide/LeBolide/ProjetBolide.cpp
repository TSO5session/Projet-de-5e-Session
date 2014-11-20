// ************************** FICHIER: ProjetBolide.CPP  ***********************
//
//  Application realisee avec IAR C++ 8.10
//
//  VITESSE DE COMMUNICATION 19200
//
//  LIMITATION DU COMPILATEUR:
//    Impossible de faire de l'heritage multiple.
//
//  Programme principal.
//
//  Note: on peut utiliser XAR pour creer des librairies.
//  On peut mettre les librairies dans le projets et Exclure de la compilation
//  les modules qui sont contenus dans la librairie.
//
//  Pour Windows 7 on utilise la VMware pour programmer le upsd 3254A avec CAPS.
//
//  AUTEURs : LOUIS-NORMAND ANG HOULE VINCENT CHOUINARD
//  DATE CREATION :    2014/02/20       VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
// *****************************************************************************
#include "TypeCible.h"
#include "ProjetBolide.h"
#include "CLXBEE.h"  
#include "CLRS232.h"
#include "Station1.h"     // Fichier de definitions de...

void main(void)
 { 
  class CLTest clTest;    // Declaration d'un objet de test
  // class CLXbee XBee;
   
   
#ifdef DALLAS89C450   
   class CLVehicule clVehicule;
   class CLStation1 StationUPSD;
   
   while(1)
    {      
      clVehicule.vControleBolide();
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

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
