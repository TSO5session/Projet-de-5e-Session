#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\CANBUS.cpp"
// **************************CANBUS.cpp
// Auteur:       Vincent Chouinard
// Date:         27 octobre 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.1
//
// Description:
// *****************************************************************************
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\_DeclarationGenerale.h"
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
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\ConversionKeilToIAR.h"
// ************************** FICHIER: ConversionKeilToIAR.h *******************
//
// Auteur:       Vincent Chouinard
// Date:         1 mai 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.1 et Keil 4.0
//
// Description: Conversion des SFR entre Keil 4.0 et IAR 8.1
// *****************************************************************************

#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\TypeCible.h"
// **************************TypeCible.h
// Auteur:      Vincent Chouinard
// Date:        4 fevrier 2014
// Version :    1.0
//
// Compilateur: Keil 4.72.9 & IAR 8.1
// Description: Fichier pour choisir le compilateur
//
// *****************************************************************************



// *****************************************************************************
//           CHOIX DU COMPILATEUR
// *****************************************************************************
  //#define DALLAS89C450             // Uncomment to compile for Dallas DS89C450
  //#define UPSD3254A                // Uncomment to compile for Dallas UPSD3254A

// *****************************************************************************
//           DEFINITION DES REGISTRES DU CPU CHOISI
// *****************************************************************************
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\ioDS89C450.h"
/***************************************************************************
 *                                - ioDS89C450.h -
 *
 * Special header for the Maxim (Dallas Semiconductor) DS89C450 Microcontroller.
 *
 ***************************************************************************/






   #pragma system_include

#pragma language=extended

/*-------------------------------------------------------------------------
 *   All SFRs
 *-------------------------------------------------------------------------*/

__sfr __no_init volatile union
{
  unsigned char EIP1;
  struct
  {
    unsigned char MPX2 : 1;
    unsigned char MPX3 : 1;
    unsigned char MPX4 : 1;
    unsigned char MPX5 : 1;
    unsigned char MPWDI : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
  } EIP1_bit;
} @ 0xF1;
__sfr __no_init volatile unsigned char ACC @ 0xE0;
__sfr __no_init volatile unsigned char TL2 @ 0xCC;
__sfr __no_init volatile union
{
  unsigned char T2MOD;
  struct
  {
    unsigned char DCEN : 1;
    unsigned char T2OE : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
  } T2MOD_bit;
} @ 0xC9;
__sfr __no_init volatile union
{
  unsigned char IP0;
  struct
  {
    unsigned char LPX0 : 1;
    unsigned char LPT0 : 1;
    unsigned char LPX1 : 1;
    unsigned char LPT1 : 1;
    unsigned char LPS0 : 1;
    unsigned char LPT2 : 1;
    unsigned char LPS1 : 1;
    unsigned char  : 1;
  } IP0_bit;
} @ 0xB8;
__sfr __no_init volatile unsigned char SADDR1 @ 0xAA;
__sfr __no_init volatile union
{
  unsigned char ACON;
  struct
  {
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char PAGES0 : 1;
    unsigned char PAGES1 : 1;
    unsigned char PAGEE : 1;
  } ACON_bit;
} @ 0x9D;
__sfr __no_init volatile unsigned char SBUF0 @ 0x99;
__sfr __no_init volatile unsigned char TH0 @ 0x8C;
__sfr __no_init volatile union
{
  unsigned char TCON;
  struct
  {
    unsigned char IT0 : 1;
    unsigned char IE0 : 1;
    unsigned char IT1 : 1;
    unsigned char IE1 : 1;
    unsigned char TR0 : 1;
    unsigned char TF0 : 1;
    unsigned char TR1 : 1;
    unsigned char TF1 : 1;
  } TCON_bit;
} @ 0x88;
__sfr __no_init volatile union
{
  unsigned char PSW;
  struct
  {
    unsigned char P : 1;
    unsigned char F1 : 1;
    unsigned char OV : 1;
    unsigned char RS0 : 1;
    unsigned char RS1 : 1;
    unsigned char F0 : 1;
    unsigned char AC : 1;
    unsigned char CY : 1;
  } PSW_bit;
} @ 0xD0;
__sfr __no_init volatile unsigned char TH2 @ 0xCD;
__sfr __no_init volatile unsigned char SADEN0 @ 0xB9;
__sfr __no_init volatile union
{
  unsigned char IE;
  struct
  {
    unsigned char EX0 : 1;
    unsigned char ET0 : 1;
    unsigned char EX1 : 1;
    unsigned char ET1 : 1;
    unsigned char ES0 : 1;
    unsigned char ET2 : 1;
    unsigned char ES1 : 1;
    unsigned char EA : 1;
  } IE_bit;
} @ 0xA8;
__sfr __no_init volatile union
{
  unsigned char P1;
  struct
  {
    unsigned char P10_T2 : 1;
    unsigned char P11_T2EX : 1;
    unsigned char P12_RXD1 : 1;
    unsigned char P13_TXD1 : 1;
    unsigned char P14_INT2 : 1;
    unsigned char P15_INT3 : 1;
    unsigned char P16_INT4 : 1;
    unsigned char P17_INT5 : 1;
  } P1_bit;
} @ 0x90;
__sfr __no_init volatile unsigned char TH1 @ 0x8D;
__sfr __no_init volatile union
{
  unsigned char TMOD;
  struct
  {
    unsigned char M00 : 1;
    unsigned char M10 : 1;
    unsigned char C_T0 : 1;
    unsigned char GATE0 : 1;
    unsigned char M01 : 1;
    unsigned char M11 : 1;
    unsigned char C_T1 : 1;
    unsigned char GATE1 : 1;
  } TMOD_bit;
} @ 0x89;
__sfr __no_init volatile union
{
  unsigned char SCON1;
  struct
  {
    unsigned char RI_1 : 1;
    unsigned char TI_1 : 1;
    unsigned char RB8_1 : 1;
    unsigned char TB8_1 : 1;
    unsigned char REN_1 : 1;
    unsigned char SM2_1 : 1;
    unsigned char SM1_1 : 1;
    unsigned char SM0_FE_1 : 1;
  } SCON1_bit;
} @ 0xC0;
__sfr __no_init volatile unsigned char SADDR0 @ 0xA9;
__sfr __no_init volatile union
{
  unsigned char EXIF;
  struct
  {
    unsigned char BGS : 1;
    unsigned char RGSL : 1;
    unsigned char RGMD : 1;
    unsigned char CKRY : 1;
    unsigned char IE2 : 1;
    unsigned char IE3 : 1;
    unsigned char IE4 : 1;
    unsigned char IE5 : 1;
  } EXIF_bit;
} @ 0x91;
__sfr __no_init volatile union
{
  unsigned char CKCON;
  struct
  {
    unsigned char MD0 : 1;
    unsigned char MD1 : 1;
    unsigned char MD2 : 1;
    unsigned char T0M : 1;
    unsigned char T1M : 1;
    unsigned char T2M : 1;
    unsigned char WD0 : 1;
    unsigned char WD1 : 1;
  } CKCON_bit;
} @ 0x8E;
__sfr __no_init volatile union
{
  unsigned char P0;
  struct
  {
    unsigned char P00 : 1;
    unsigned char P01 : 1;
    unsigned char P02 : 1;
    unsigned char P03 : 1;
    unsigned char P04 : 1;
    unsigned char P05 : 1;
    unsigned char P06 : 1;
    unsigned char P07 : 1;
  } P0_bit;
} @ 0x80;
__sfr __no_init volatile unsigned char SBUF1 @ 0xC1;
__sfr __no_init volatile union
{
  unsigned char P3;
  struct
  {
    unsigned char P30_RXD0 : 1;
    unsigned char P31_TXD0 : 1;
    unsigned char P32_INT0 : 1;
    unsigned char P33_INT1 : 1;
    unsigned char P34_T0 : 1;
    unsigned char P35_T1 : 1;
    unsigned char P36_WR : 1;
    unsigned char P37_RD : 1;
  } P3_bit;
} @ 0xB0;
__sfr __no_init volatile unsigned char SP @ 0x81;
__sfr __no_init volatile union
{
  unsigned char ROMSIZE;
  struct
  {
    unsigned char RMS0 : 1;
    unsigned char RMS1 : 1;
    unsigned char RMS2 : 1;
    unsigned char PRAME : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
  } ROMSIZE_bit;
} @ 0xC2;
__sfr __no_init volatile union
{
  unsigned char IP1;
  struct
  {
    unsigned char MPX0 : 1;
    unsigned char MPT0 : 1;
    unsigned char MPX1 : 1;
    unsigned char MPT1 : 1;
    unsigned char MPS0 : 1;
    unsigned char MPT2 : 1;
    unsigned char MPS1 : 1;
    unsigned char  : 1;
  } IP1_bit;
} @ 0xB1;
__sfr __no_init volatile union
{
  unsigned char P2;
  struct
  {
    unsigned char P20 : 1;
    unsigned char P21 : 1;
    unsigned char P22 : 1;
    unsigned char P23 : 1;
    unsigned char P24 : 1;
    unsigned char P25 : 1;
    unsigned char P26 : 1;
    unsigned char P27 : 1;
  } P2_bit;
} @ 0xA0;
__sfr __no_init volatile unsigned char DPL @ 0x82;
__sfr __no_init volatile unsigned char DPH @ 0x83;
__sfr __no_init volatile union
{
  unsigned char FCNTL;
  struct
  {
    unsigned char FC0 : 1;
    unsigned char FC1 : 1;
    unsigned char FC2 : 1;
    unsigned char FC3 : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char FERR : 1;
    unsigned char FBUSY : 1;
  } FCNTL_bit;
} @ 0xD5;
__sfr __no_init volatile union
{
  unsigned char PMR;
  struct
  {
    unsigned char DME0 : 1;
    unsigned char DME1 : 1;
    unsigned char ALEON : 1;
    unsigned char _4X__2X : 1;
    unsigned char CTM : 1;
    unsigned char SWB : 1;
    unsigned char CD0 : 1;
    unsigned char CD1 : 1;
  } PMR_bit;
} @ 0xC4;
__sfr __no_init volatile unsigned char DPL1 @ 0x84;
__sfr __no_init volatile union
{
  unsigned char EIP0;
  struct
  {
    unsigned char LPX2 : 1;
    unsigned char LPX3 : 1;
    unsigned char LPX4 : 1;
    unsigned char LPX5 : 1;
    unsigned char LPWDI : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
  } EIP0_bit;
} @ 0xF8;
__sfr __no_init volatile unsigned char FDATA @ 0xD6;
__sfr __no_init volatile union
{
  unsigned char STATUS;
  struct
  {
    unsigned char SPRA0 : 1;
    unsigned char SPTA0 : 1;
    unsigned char SPRA1 : 1;
    unsigned char SPTA1 : 1;
    unsigned char  : 1;
    unsigned char PIS0 : 1;
    unsigned char PIS1 : 1;
    unsigned char PIS2 : 1;
  } STATUS_bit;
} @ 0xC5;
__sfr __no_init volatile union
{
  unsigned char CKMOD;
  struct
  {
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char T0MH : 1;
    unsigned char T1MH : 1;
    unsigned char T2MH : 1;
    unsigned char  : 1;
    unsigned char  : 1;
  } CKMOD_bit;
} @ 0x96;
__sfr __no_init volatile unsigned char DPH1 @ 0x85;
__sfr __no_init volatile union
{
  unsigned char EIE;
  struct
  {
    unsigned char EX2 : 1;
    unsigned char EX3 : 1;
    unsigned char EX4 : 1;
    unsigned char EX5 : 1;
    unsigned char EWDI : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
  } EIE_bit;
} @ 0xE8;
__sfr __no_init volatile unsigned char RCAP2L @ 0xCA;
__sfr __no_init volatile union
{
  unsigned char DPS;
  struct
  {
    unsigned char SEL : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char AID : 1;
    unsigned char TSL : 1;
    unsigned char ID0 : 1;
    unsigned char ID1 : 1;
  } DPS_bit;
} @ 0x86;
__sfr __no_init volatile union
{
  unsigned char WDCON;
  struct
  {
    unsigned char RWT : 1;
    unsigned char EWT : 1;
    unsigned char WTRF : 1;
    unsigned char WDIF : 1;
    unsigned char PFI : 1;
    unsigned char EPFI : 1;
    unsigned char POR : 1;
    unsigned char SMOD_1 : 1;
  } WDCON_bit;
} @ 0xD8;
__sfr __no_init volatile unsigned char RCAP2H @ 0xCB;
__sfr __no_init volatile unsigned char TA @ 0xC7;
__sfr __no_init volatile unsigned char SADEN1 @ 0xBA;
__sfr __no_init volatile union
{
  unsigned char SCON0;
  struct
  {
    unsigned char RI_0 : 1;
    unsigned char TI_0 : 1;
    unsigned char RB8_0 : 1;
    unsigned char TB8_0 : 1;
    unsigned char REN_0 : 1;
    unsigned char SM2_0 : 1;
    unsigned char SM1_0 : 1;
    unsigned char SM0_FE_0 : 1;
  } SCON0_bit;
} @ 0x98;
__sfr __no_init volatile unsigned char TL0 @ 0x8A;
__sfr __no_init volatile union
{
  unsigned char PCON;
  struct
  {
    unsigned char IDLE : 1;
    unsigned char STOP : 1;
    unsigned char GF0 : 1;
    unsigned char GF1 : 1;
    unsigned char OFDE : 1;
    unsigned char OFDF : 1;
    unsigned char SMOD0 : 1;
    unsigned char SMOD_0 : 1;
  } PCON_bit;
} @ 0x87;
__sfr __no_init volatile unsigned char B @ 0xF0;
__sfr __no_init volatile union
{
  unsigned char T2CON;
  struct
  {
    unsigned char CP_RL2 : 1;
    unsigned char C_T2 : 1;
    unsigned char TR2 : 1;
    unsigned char EXEN2 : 1;
    unsigned char TCLK : 1;
    unsigned char RCLK : 1;
    unsigned char EXF2 : 1;
    unsigned char TF2 : 1;
  } T2CON_bit;
} @ 0xC8;
__sfr __no_init volatile unsigned char TL1 @ 0x8B;
/*
 * Interrupt Vectors
 */
#line 483 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\ioDS89C450.h"

#pragma language=default


/***************************************************************************
 *   Assembler definitions
 *
 *   The following SFRs are built in in the a8051.exe and can not be
 *   defined explicitly in this file:
 *     ACC,B,PSW,SP,DPL,DPH
 *   The PSW-bits are built-in in the a8051.exe
 *     OV,AC,F0,RS0,RS1,P
 *
 ***************************************************************************/

#line 24 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\TypeCible.h"







//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
#line 14 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\ConversionKeilToIAR.h"




// *****************************************************************************
// DEFINITION DES  MODELES DE MEMOIRE
// *****************************************************************************






// *****************************************************************************


// Interruption activation






// Interruption priorite








// Interruption niveau activite.
































#line 87 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\ConversionKeilToIAR.h"

#line 96 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\ConversionKeilToIAR.h"




// *****************************************************************************

// *****************************************************************************
#line 211 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\ConversionKeilToIAR.h"
// *****************************************************************************

//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX

#line 17 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\_DeclarationGenerale.h"




// ****************************************************************************
//                            DEFINITION DE MOTS CLES
// ****************************************************************************
























// ****************************************************************************
//                            VARIABLES SHORTCUTS
// ****************************************************************************




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

#line 77 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\_DeclarationGenerale.h"

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

//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
#line 12 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\CANBUS.cpp"
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\CANBUS.h"
// **************************CANBUS.h
// Auteur:       Vincent Chouinard
// Date:         27 octobre 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.1
//
// Description:
// *****************************************************************************
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\_DeclarationGenerale.h"
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
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\ConversionKeilToIAR.h"
// ************************** FICHIER: ConversionKeilToIAR.h *******************
//
// Auteur:       Vincent Chouinard
// Date:         1 mai 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.1 et Keil 4.0
//
// Description: Conversion des SFR entre Keil 4.0 et IAR 8.1
// *****************************************************************************



#line 213 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\ConversionKeilToIAR.h"
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX

#line 17 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\_DeclarationGenerale.h"


#line 139 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\_DeclarationGenerale.h"
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
#line 12 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\CANBUS.h"
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\CLSPI.h"
//**********************  Fichier: CLSPI.h
//  Description  : Fonctions necessaire pour communiquer en SPI.
//
//  Composition  : aucune
//  Heritage     : aucune
//
//  Programmeur  : Vincent Chouinard
//  Cours        : 247-636
//
//  Date         : 22 Octobre 2014
//
//  Compilateur  : IAR 8.1
//
//  Modification :
//
//////////////////////////////////////////////////////////////////////////////



#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\_DeclarationGenerale.h"
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
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\ConversionKeilToIAR.h"
// ************************** FICHIER: ConversionKeilToIAR.h *******************
//
// Auteur:       Vincent Chouinard
// Date:         1 mai 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.1 et Keil 4.0
//
// Description: Conversion des SFR entre Keil 4.0 et IAR 8.1
// *****************************************************************************



#line 213 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\ConversionKeilToIAR.h"
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX

#line 17 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\_DeclarationGenerale.h"


#line 139 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\_DeclarationGenerale.h"
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
#line 21 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\CLSPI.h"
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\MCP2515.h"
#line 49 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\MCP2515.h"






























#line 94 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\MCP2515.h"















#line 117 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\MCP2515.h"

/* Registres permettant de contrôler le module d'envoi « TX0 » */
#line 135 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\MCP2515.h"

/* Registres permettant de contrôler le module de réception « RX0 » */
#line 22 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\CLSPI.h"
/////////////////////////////////////
#line 31 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\CLSPI.h"
/////////////////////////////////////

class CLSPI
{
public:
   CLSPI(void)    ;                          // Constructeur.
   CLSPI(UC ucVal);                          // Constructeur initialisateur.
  ~CLSPI(void)    ;                          // Destructeur.

   UC   WriteMPC     (UC Data);              // Pour envoyer une valeur hexa sur les IO du MPC
   UC   WritePOT     (UC Data);              // Pour écrire sur un POT numerique 
   UC   WriteDAC     (UC ucPin, int iData);  // Pour faire une conversion Digital to Numeric
   UC   WriteMPC     (UC NombreDonneesEnvoyer, UC Donnee1, UC Donnee2, UC Donnee3);   
   UC   ReadMPC      (void);                 // Pour lire la valeur hexa des IO du MPC

protected:

private:
   void Delai     (unsigned long Temps);     // Implémentation d'un delai ajustable
   void Direction (UC Directions) ;          // Pour la direction des port du MCP23S08  
   UC   Write     (UC ucValeur, UC ucMode);  // Pour ecrire une donnee 8  bit en SPI
   UI   Write16   (UI uiValeur, UC ucMode);  // Pour ecrire une donnee 16 bit en SPI    
};


//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX

#line 13 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\CANBUS.h"
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\MCP2515.h"
#line 49 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\MCP2515.h"






























#line 94 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\MCP2515.h"















#line 117 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\MCP2515.h"

/* Registres permettant de contrôler le module d'envoi « TX0 » */
#line 135 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\MCP2515.h"

/* Registres permettant de contrôler le module de réception « RX0 » */
#line 14 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\CANBUS.h"




class CanBus : public CLSPI
{
public:
   CanBus(void);            // ***Constructeur par defaut
   CanBus(UC ucParametre);  // ***Constructeur initialisateur
  ~CanBus(void);            // ***Destructeur
  
   void SendMCP(const UC *Message); // Envoie un string sur le CAN bus
   UC   ReadMCP(void);              // Lit un string su le CAN bus

protected:

private:
   void AcquitterInterruptionsMCP2515  (void)               ; // Gestion des interrupts
   void MCP24515_init                  (void)               ; // Initialisation du MCP
   void ChoisirIdentifiantTX0          (int Identifiant)    ; // Choisie un registre CAN   
   void Delai                          (unsigned long Temps); // Court delai d'initialisation
   void EcrireRegistreMCP2515          (UC Address, UC Data); // Configure le MCP
   UC   LireRegistreMCP2515            (UC Address, UC Data); // Configure le MCP
   UC   Longueur                       (const UC *Contenu)  ; // Gestion d'une longueur
};

//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
#line 13 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\CANBUS.cpp"
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\MCP2515.h"
#line 49 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\MCP2515.h"






























#line 94 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\MCP2515.h"















#line 117 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\MCP2515.h"

/* Registres permettant de contrôler le module d'envoi « TX0 » */
#line 135 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\MCP2515.h"

/* Registres permettant de contrôler le module de réception « RX0 » */
#line 14 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\CANBUS.cpp"

// *****************************************************************************



// *****************************************************************************

//******************************************************************************
//                            LE CONSTRUCTEUR PAR DEFAUT
// *****************************************************************************
CanBus :: CanBus(void)
{
class CLSPI SPI;  // Initialise le SPI
MCP24515_init();  // Initialise le MCP2515
ChoisirIdentifiantTX0(0x0A0); // Envoie 0x0A0
}

//******************************************************************************
//                            LE CONSTRUCTEUR INITIALISATEUR
// *****************************************************************************
CanBus :: CanBus(UC ucParametre) // Initialisation du CAN via MCP2515
{

}

// *****************************************************************************
//                            LE DESTRUCTEUR
// *****************************************************************************
CanBus :: ~CanBus(void)
{
  
}

UC CanBus :: ReadMCP(void) // Cette Fonction n'est pas encore fonctionnelle
{
bool gotMessage;
UC   val = 0;


val = WriteMPC(0x2C);                 // Obtention de la longueur

if(LireRegistreMCP2515(val, 0x01) == 1) // Si une data est availible
  {
   gotMessage = true;                            // Lève le flag d'availibilité
  }

if(gotMessage == true)
  {

  }

return(val);
}

void CanBus :: MCP24515_init(void)
{
// Envoi de la commande de   RESET  , qui consiste en l'envoi de l'octet   0xC0  , par le bus SPI. 
   WriteMPC(3, 0xC0, 0x00, 0x00);
   Delai(1000);   // Délai permettant de s'assurer que le MCP2515 soit bien réinitialisé.
        
// Passage du circuit MCP2515 en   Configuration mode  , nécéssaire 
// pour pouvoir effectuer les opérations de configurations qui suivent 

   EcrireRegistreMCP2515(0x0F, 0x87);   /* Registre 0x0F.
                             - REQOP2   = 1 :
                             - REQOP1   = 0 :
                             - REQOP0   = 0 : le circuit est passé en   Configuration mode  ,
                             - ABAT     = 0 : ne pas annuler toutes les transmissons en attentes, si nécéssaire,
                             - OSM          : renvois des messages, si nécessaire,
                             - CLKEN    = 1 : la broche   CLKOUT   est activée,
                             - CLKPRE1  = 1 : 
                             - CLKPRE0  = 1 : réglage du prédiviseur de l'horloge de la broche   CLKOUT   à 8,
                             - F_CLKOUT = System Clock / 8 */        
             
EcrireRegistreMCP2515(0x0C,  0x3C); /* Registre 0x0C */
EcrireRegistreMCP2515(0x0D, 0x00); /* Registre 0x0D.
                           L'envoi d'un message - RTS - ne se fait pas sur le passage à   0   d'une broche,
                           mais après l'envoi de la commande   RTS  , par l'intermédiaire du bus SPI */
   
/* Initialisations des registres des compteurs d'erreurs */
EcrireRegistreMCP2515(0x1C, 0x00); /* Registre 0x1C.
                          Mise à zéro du compteur d'erreurs en émission.*/
EcrireRegistreMCP2515(0x1D, 0x00); /* Registre 0x1D.
                          Mise à zéro du compteur d'erreurs en réception.*/
  
/* Configurations du   Bit Timing   */                 
EcrireRegistreMCP2515(0x2A, 0xC0); /* Registre 0xC0.
                            - SJW = 0 : 1 x TQ,
                            - BRP = 3. */
EcrireRegistreMCP2515(0x29, 0x9A); /* Registre 0x9A.
                            - BTLMODE = 1,
                            - SAM     = 0,
                            - PHSEG1  = 2,
                            - PRSEG   = 0. */
EcrireRegistreMCP2515(0x28, 0x07); /* Registre 0x07.
                            - SOF     = 0 : Broche   CLKOUT   activée pour la fonction de répétition de l'horloge,
                            - WAKFIL  = 0 : Wake-up filter désactivé,
                            - PHSEG : 2. */

/* Configurations des interruptions du circuit MCP2515 */
EcrireRegistreMCP2515(0x2B,  0x01); /* Registre 0x2B.
                            Autorisation des interruptions suite à la réception d'une donnée par le module   RXB0  . */
EcrireRegistreMCP2515(0x2C,  0x00); /* Registre 0x2C.
                             Acquittement des éventuelles interruptions qui seraient en attente .*/
EcrireRegistreMCP2515(0x2D,     0x00); /* Registre 0x2D */
EcrireRegistreMCP2515(0x60, 0x20); /* Registre 0x60 */
   
/* Configuration initiale du module   TXB0   */
EcrireRegistreMCP2515(0x30, 0x03); /* Registre 0x30.
                              TXP = 0b11 : les messages ont la plus haute priorité. */
EcrireRegistreMCP2515(0x35, 0x01);  /* Registre 0x35.
                             Nombre d'octets occupés par les données à envoyer : 1 octet.*/
                      
/* Configurations de l'identifiant en réception par le filtre 0 du circuit MCP2515 */    
EcrireRegistreMCP2515(0x00, 0x00);   /* Registre 0x00.
                              Identifiant initial de réception H. */
EcrireRegistreMCP2515(0x01, 0x20);   /* Registre 0x01.
                              Identifiant initial de réception L + configurations initiales du mode de fonctionnement des identifiants en réceptions. */

/* Configurations du masque de réception initial utilisé par le filtre 0 du circuit MCP2515 */
EcrireRegistreMCP2515(0x20, 0x00);   /* Registre 0x20.
                              Masque de réception initial H. */                              
EcrireRegistreMCP2515(0x21, 0x20);   /* Registre 0x21.
                              Masque de réception initial L. + configurations initiales du mode de fonctionnement des masque de réceptions. */
   
/* Configurations de l'identifiant en émission par le module   TXB0   du circuit MCP2515 */
EcrireRegistreMCP2515(0x31, 0x00);   /* Registre 0x31.
                              Identifiant initial d'émission H. */
EcrireRegistreMCP2515(0x32, 0x00);   /* Registre 0x32.
                              Identifiant initial d'émission L + configurations initiales du mode de fonctionnement des identifiants en émissions. */
  
/* Passage du circuit MCP2515 en   Normal Operation mode   */
EcrireRegistreMCP2515(0x0F, 0x07); /* Registre 0x0F.
                              - REQOP2 = 1,
                              - REQOP1 = 0,
                              - REQOP0 = 0 : le circuit est passé en   Normal Operation mode  . 
                              - Les réglages précédemment évoqués restent inchangés. */        
}

void CanBus :: EcrireRegistreMCP2515(UC Address, UC Data)
{
WriteMPC(3, 0x02, Address, Data);   /* Envoi de 3 octets :
                                       - La commande d'écriture ;
                                       - L'adresse du registre dans lequel écrire ;
                                       - L'octet à écrire dans le registre. */ 
}

void CanBus :: ChoisirIdentifiantTX0(int Identifiant)
{
UC Contenu_MCP2515_TXB0SIDH = 0;
UC Contenu_MCP2515_TXB0SIDL = 0;

// On récupère les 8 bits de poids fort de l'identifiant à configurer,
// qui doivent être placés tels quels dans le registre   MCP2515_TXB0SIDH  . 
Contenu_MCP2515_TXB0SIDH = (UC)(0x00FF & (Identifiant >> 3));   

// On récupère les 3 bits de poids faible de l'identifiant à configurer,
// qui doivent être placés dans le registre   MCP2515_TXB0SIDL  ,
// aux bits   MCP2515_TXB0SIDL<5>  ,   MCP2515_TXB0SIDL<6>   et   MCP2515_TXB0SIDL<7>  .   
Contenu_MCP2515_TXB0SIDL = (UC)(0x00E0 & (Identifiant << 5));   
   
   //Identifiant Emission H 
EcrireRegistreMCP2515(0x31, Contenu_MCP2515_TXB0SIDH);   
   // Identifiant Emission L + Configurations du mode de fonctionnement des identifiants */  
EcrireRegistreMCP2515(0x32, Contenu_MCP2515_TXB0SIDL);   
}

void CanBus :: AcquitterInterruptionsMCP2515(void)
{
EcrireRegistreMCP2515(0x0F, 0x87);   /* Registe 0x0F.
Le circuit est passé en   Configuration mode  . */
EcrireRegistreMCP2515(0x2C, 0x00);   /* Registre 0x2C.
Acquittement des interruptions du circuit MCP2515. */
EcrireRegistreMCP2515(0x0F, 0x07);   /* Registe 0x0F.
Le circuit est passé en   Normal Operation mode  . */  
}

void CanBus :: SendMCP(const UC *Message)
{
UC TailleDuMessage = 0;
UC k;
UC PointeurRegistre = 0x36;

//Détermination du nombre d'octets de données à transmettre, et limitation à 8 octets au maximum
TailleDuMessage = Longueur(Message);

//Si le nombre d'octets de données à transmettre dépasse le nombre maximal d'octets possible
if(TailleDuMessage > 8)   
  {                     // Le nombre maximal d'octets possible
   TailleDuMessage = 8; // sera tranmis par le circuit MCP2515
  }

//Le MCP2515 est informé du nombre d'octets de données qu'il aura à tranmettre
EcrireRegistreMCP2515(0x35, TailleDuMessage); 

for(k = 0; k < TailleDuMessage; k++) // Chargement du message dans le MCP2515
  {
   EcrireRegistreMCP2515(PointeurRegistre, Message[k]); /* Les registres de données du module   TXB0  ,
   dont les adresses sont consécutives, sont remplis,
   en commencant par le registre   MCP2515_TXB0D0  , d'adresse 0x36. */
   PointeurRegistre++;
  }

/* Envoi de la commande   RTS  , qui consiste en l'envoi de l'octet   0xC0  , par le bus SPI. */
WriteMPC(1, 0x81, 0x00, 0x00);
Delai(10);  
}

UC CanBus :: LireRegistreMCP2515(UC Address, UC Data)
{
WriteMPC(Address);  
return(WriteMPC(Data));
}

UC CanBus :: Longueur(const UC *Contenu)
{
UC Compteur = 0;

while(Contenu[Compteur] != '\0')
  {
   Compteur++;
  }
return(Compteur);  
}

void CanBus :: Delai(unsigned long Temps)
{
unsigned long k;
for(k = 0; k < Temps; k++);  
}
















//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
