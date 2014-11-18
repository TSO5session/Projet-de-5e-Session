// ********************* FICHIER: DECLARATIONGENERALE.H ************************
//
// Auteur:       Louis-Normand Ang-Houle, Hicham Safoine, Vincent Chouinard
// Date:         1 mai 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.1
//
// Description: Raccourcis linguistiques utiles
// *****************************************************************************

// *****************************************************************************
// FICHIER PERMETTANT DE FAIRE LA CONVERSION ENTRE LES COMPILATEURS
// ET D'INDIQUER L'APPLICATION A COMPILER
//
#include "TypeCible.h"
#include "ConversionKeilToIAR.h"
#include <stdio.h>
//
// *****************************************************************************

#ifndef DECLARATIONGENERALEH
   #define DECLARATIONGENERALEH

// *****************************************************************************
//                            DEFINITION DE MOT CLE
// *****************************************************************************

#define ACTIF   1              //
#define INACTIF 0              //

#define ON      1              //
#define OFF     0              //

#define HAUT    1              //
#define BAS     0              //

#define HIGH    1              //
#define LOW     0              //

#define VRAI    1              //
#define FAUX    0              //

#define TRUE    1              //
#define FALSE   0              //

// *****************************************************************************
//                            DEFINITION DE TYPE
// *****************************************************************************

/* Alternate definitions */
typedef void                VOID;
#ifndef NULL
  #define NULL 0
#endif

typedef float               F;

typedef signed char         C;
typedef signed char         INT8;

typedef unsigned char       UC;
typedef unsigned char       UINT8;

typedef signed short int    INT16;
typedef signed short int    SI;

typedef unsigned short int  UINT16;
typedef unsigned short int  USI;

typedef signed long         INT32;
typedef signed long         L;

typedef unsigned  long      UINT32;
typedef unsigned  long      UL;

// *****************************************************************************
//                    DEFINITION DE STRUCTURES UTILES
// *****************************************************************************

struct STTemps
 {
   UC ucSeconde;
   UC ucMinute;
   UC ucHeure;
 };

struct STChampBit
 {
   UC bBit0 : 1;
   UC bBit1 : 1;
   UC bBit2 : 1;
   UC bBit3 : 1;
   UC bBit4 : 1;
   UC bBit5 : 1;
   UC bBit6 : 1;
   UC bBit7 : 1;
 };

struct STMot
 {
   UC ucPetitMot : 4;
   UC ucGrandMot : 4;
 };

union UNOctetBit
 {
   struct STMot      stMot;
   struct STChampBit stChampBit;
   UC ucOctet;
 };

struct STDeuxOctet
 {
   UC ucOctet1;
   UC ucOctet2;
 };

union UNEntierOctet
 {
   struct STDeuxOctet stDeuxOctet;
   USI uiEntier;
 };

struct STQuatreOctet
 {
   UC ucOctet1;
   UC ucOctet2;
   UC ucOctet3;
   UC ucOctet4;
 };

union UNLongOctet
 {
   struct STQuatreOctet stQuatreOctet;
   UL ulLong;
 };
#endif
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
