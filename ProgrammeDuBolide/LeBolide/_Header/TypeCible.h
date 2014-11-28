// ************************** FICHIER: TYPECIBLE.H ****************************
//
// Auteur:       Louis-Normand Ang-Houle, Hicham Safoine, Vincent Chouinard
// Date:         1 mai 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.1
//
// Description: Fichier pour selectionner la CIBLE et inclure
//              le fichier de conversion des definitions des registres SFR.
// *****************************************************************************
#ifndef TYPECIBLEH
  #define TYPECIBLEH

////////////////////////////////////////////////////////////////////////////////
//  Choix de la cible
  #define UPSD3254A
//#define DALLAS89C450
//  #define SPI_DALLAS
//  #define I2C_DALLAS

////////////////////////////////////////////////////////////////////////////////
//  Fichier de definition des registres en fonction de la cible.
  #ifdef DALLAS89C450
    #include <ioDS89C450.h>
  #endif

  #ifdef UPSD3254A
    #include <ioUPSD3254A.h>
  #endif
#endif
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

