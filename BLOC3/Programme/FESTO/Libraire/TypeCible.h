// ***************** FICHIER:TYPECIBLE.H 
//
//  Permet de slectionner quel microcontroller sera utiliser
//
//  Application realisee avec IAR
//
//  AUTEUR : Gabriel Fortin-Belanger
//  DATE CREATION :    2014-02-07		 VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
// *****************************************************************************
#ifndef TYPECIBLEH
   #define TYPECIBLEH

//******************************************************************************
//Choix de la cible
//
// #define DALLAS89C450
//  #define UPSD3254A
//******************************************************************************


//******************************************************************************
//      Fichier de definition des registres 
//
//
   #ifdef DALLAS89C450
     #include "ioDS89C450.h"
   #endif

   #ifdef  UPSD3254A
     #include "iouPSD3254A.h"
    
   #endif


//*****************************************************************************
//SECTION DES APPLICATIONS
//
//
//
//
//
//#define TEST_SECTION
#define ECRAN_SECTION
#define INOUT_SECTION
#define MAISON_SECTION
#define I2C_SECTION
#define HORLOGE_1307_SECTION
#define COMM_SECTION
#define I2CREG_SECTION
//
//
//
//
//
//******************************************************************************


#endif