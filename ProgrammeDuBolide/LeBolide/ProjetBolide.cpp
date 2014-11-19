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
#include "ProjetBolide.h"
#include "CLXBEE.h"  
#include "CLRS232.h"

void main(void)
 { 
  class CLTest clTest;    // Declaration d'un objet de test
  // class CLXbee XBee;
   
   
#ifdef DALLAS89C450   
   class CLVehicule clVehicule;
   
   while(1)
    {      
      clVehicule.vControleBolide();
     // XBee.SendString("HODOR");
     // XBee.SendCarac ('A');
     // XBee.SendNumber(514);
     // UC mavar = XBee.GetChar();
    }  
#endif
   
#ifdef UPSD3254A
   class CLTelecommande clTelecommande;
   WDKEY = 0x55;
   
   while(1)
    {
           
    } 
#endif  
   
 }

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
