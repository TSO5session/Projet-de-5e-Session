

// ************************** FICHIER: ProjetSessionCinqMain.CPP  ****
//  Application realisee avec IAR C++ 8.10
//  LABORATOIRE PROJET FIN SESSION
//
//  VITESSE DE COMMUNICATION 19200
//
//  LIMITATION DU COMPILATEUR:
//    Impossible de faire de l'heritage multiple.
//
//  Programme principal.
//
//  Note on peut utiliser XAR pour creer des librairies.
//  On peut mettre les librairies dans le projets et Exclure de la compilation
//  les modules qui sont contenus dans la librairie.
//
//  Pour Windows 7 on utilise la VMware pour programmer le upsd 3254A avec CAPS.
//
//  AUTEUR : Gabriel Fortin-B
//  DATE CREATION :    2012-12-20		 VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
// ************************************************************************
#include "_DeclarationGenerale.h"

#include "_Session3Main.h"
#include <stdio.h>
 

 
void vInit_CPU(void); // initialise le microcontroller
 
   CLSPI clSPI;
   CLEcran clEcran;
   CLADDA clADDA;
    //CLDelai clDelai;
   
   

void main(void)
{
   vInit_CPU();
   while(1)  //faire sans fin
    {

  

    }
}// void main (void)


//************************ TITRE : vInit_CPU    ***************************
//
//  DESCRIPTION :Initialisation du microcontroleur
//
//  NOM: void vInit_CPU (void)
//
//  PARAMETRE D'ENTREE:  AUCUN
//
//  PARAMETRE DE SORTIE: AUCUN
//
//  MEMBRES UTILISES:
//       Fonctions       : AUCUNE
//       Donnees         : AUCUNE
//                      :
//  AUTEUR : DANIEL BRETON
//  DATE CREATION :    2012-12-20		 VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
// ****************************************************************************

void vInit_CPU(void)
{
  #ifdef UPSD3254A
     WDKEY =0x55;  //desactive le watchdog du upsd
  #endif
} // void vInit_CPU (void)


// ****************************************************************************







