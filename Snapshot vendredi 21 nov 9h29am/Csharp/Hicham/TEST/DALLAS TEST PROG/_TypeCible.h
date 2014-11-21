


// ************************** FICHIER: _TYPECIBLE.H
//
//  Application realisee avec IAR C++ 8.10
//
//  Fichier pour selectionner la CIBLE et pour inclure
//  le fichier de conversion des définitions des registres SFR.
//
//  AUTEUR : DANIEL BRETON
//  DATE CREATION :    2013-01-23       VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
// ************************************************************************
#ifndef TYPECIBLEH
  #define TYPECIBLEH

#define DALLAS89C450
//  #define UPSD3254A

// ********************************************************************
//  Fichier de definition des registres en fonction de la CIBLE.
//
  #ifdef DALLAS89C450
    #include <ioDS89C450.h>
  #endif


  #ifdef UPSD3254A
    #include <ioUPSD3254A.h>
  #endif
//
// ********************************************************************
#endif

