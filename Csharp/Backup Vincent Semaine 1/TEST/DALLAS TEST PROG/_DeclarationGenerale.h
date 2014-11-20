// ***************** FICHIER: _DeclarationGenerale.h
//
//  DEFINITION GENERALE POUR UN PROJET
//
//  Application realisee avec Keil 4.72.9 && IAR 8.1
//
//  AUTEUR : DANIEL BRETON
//  DATE CREATION :    4 septembre 2013      VERSION: 1.2
//  DATE MODIFICATION: 23 janvier 2014
//                        ---> Ajout de TypeDEF
//                     6 FEVRIER 2014
//                        ---> Ajout de structures & de headers pour IAR 8.1
// ****************************************************************************
//                           LES INCLUDES
// ****************************************************************************
#include "ConversionKeilToIAR.h"     // Conversion KEIL <--> IAR
#include "TypeCible.h"               // Selection du CPU

#ifndef DECLARATIONGENERALEH
  #define DECLARATIONGENERALEH
// ****************************************************************************
//                            DEFINITION DE MOTS CLES
// ****************************************************************************
#define ACTIF   1
#define INACTIF 0

#define ON      1
#define OFF     0

#define VRAI    1
#define FAUX    0

#define HIGH    1
#define LOW     0

#define HAUT    1
#define BAS     0

#define ACK     0
#define NOACK   1

#define TRUE    1             
#define FALSE   0   

#define COMPLET   1
#define INCOMPLET 0

// ****************************************************************************
//                            VARIABLES SHORTCUTS
// ****************************************************************************
#ifndef NULL
  #define NULL 0
#endif

typedef bool               bit;        
typedef float              F;
typedef signed long        L;
typedef signed char        C;
typedef unsigned  long     UL;
typedef unsigned char      UC;
typedef unsigned int       UI;
typedef signed short int   SI;
typedef unsigned short int USI;
typedef signed char        INT8;
typedef unsigned char      UINT8;
typedef unsigned short int UINT16;
typedef signed long        INT32;
typedef unsigned long int  UINT32;
typedef void               VOID;

#define BARGRAPH1 0xFA00  // Adresses des composantes sur la carte binaire.
#define BARGRAPH2 0xFB00
#define DIPSW1    0xFA00
#define DIPSW2    0xFB00
#define SEGMENT1  0xFD00
#define SEGMENT2  0xFC00

// ****************************************************************************
//                            DEFINITION DES STRUCTURES
// ****************************************************************************
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

struct STDoubleOctet
 {
   UC ucOctet1;
   UC ucOctet2;
 };

union UNEntierOctet
 {
   struct STDoubleOctet stDoubleOctet;
   USI uiEntier;
 };

struct STQuadOctet
 {
   UC ucOctet1;
   UC ucOctet2;
   UC ucOctet3;
   UC ucOctet4;
 };

union UNLongOctet
 {
   struct STQuadOctet stQuadOctet;
   UL ulLong;
 };
#endif
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX