#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\CLSPI.cpp"
//**********************  Fichier: CLSPI.cpp
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

#line 18 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\CLSPI.cpp"
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
#line 19 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\CLSPI.cpp"
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\MCP2515.h"
#line 49 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\MCP2515.h"






























#line 94 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\MCP2515.h"















#line 117 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\MCP2515.h"

/* Registres permettant de contrôler le module d'envoi « TX0 » */
#line 135 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\MCP2515.h"

/* Registres permettant de contrôler le module de réception « RX0 » */
#line 20 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\CLSPI.cpp"
//******************************************************************************
//                            LE CONSTRUCTEUR PAR DEFAUT
// *****************************************************************************
CLSPI :: CLSPI(void)
{
P1_bit . P15_INT3     = 0;  // Commence a bas  
P1_bit . P14_INT2     = 0;  // Commence a bas  
P1_bit . P16_INT4     = 0;  // Commence a bas
P1_bit . P17_INT5       = 1; // Commence a bas
}

//******************************************************************************
//                            LE CONSTRUCTEUR INITIALISATEUR
// *****************************************************************************
CLSPI :: CLSPI(UC Directions)
{
P1_bit . P15_INT3     = 0;        // Commence a bas  
P1_bit . P14_INT2     = 0;        // Commence a bas  
P1_bit . P16_INT4     = 0;        // Commence a bas
P1_bit . P17_INT5       = 1;       // Commence a bas

Direction(Directions); // Initialise les directions
}

// *****************************************************************************
//                            LE DESTRUCTEUR
// *****************************************************************************
CLSPI :: ~CLSPI(void)
{

}

//*****************************************************************************
// Nom de la fct       : vSPIEcire
// Description         : Fonction qui permet de lire et d'ecrire un octet
//                     : sous les 4 different mode SPI
//
// INCLUDE             : #include "_DeclarationGenerale.h", #include "CLSPI.h"
//
// Prototype           : UC ucSPIEcire(UC ucValeur, UC ucMode);
//
//
// Parametre d'entree  : ucValeur pour la valeur a envoyer ucMode pour le mode
//
// Parametre de sortie : ucDonneeLue pour la donnee lue
//
// Procedure appelees  : aucune
//
// Exemple d'appel     : val = clComSPI.ucSPIEcire(0xAA);
//
// Fait par            : Vincent Chouinard
// Date                : 23 septembre 2014
// Revision            : A
// Modification
//*****************************************************************************
UC CLSPI :: Write(UC ucValeur, UC ucMode)
{
UC i;                               // Pour boucle
UC ucDonneeLue = 0;                 // Pour la donnee a transmettre
//CS             = LOW;

if(ucMode == 0)                     // Si mode 0?
  {
   P1_bit . P16_INT4  = 0;                     // Met la clock a 0

   for(i = 0; i < 8; i++)           // Fait 8 fois
     {
      if((ucValeur & 0x80) == 0x80) //fait un masque si egale a 1
        {
         P1_bit . P15_INT3 = 1;                  // Envoie 1
        }
       else                         // Sinon
        {
         P1_bit . P15_INT3 =0;                   // Envoie 0.
        }

       ucValeur    = ucValeur    << 1  ; // Decale la valeur a envoyer
       ucDonneeLue = ucDonneeLue << 1  ; // Decale la valeur lue
       P1_bit . P16_INT4        = 1              ; // Clock a 1
       ucDonneeLue = ucDonneeLue + P1_bit . P14_INT2; // Aditionne l'etat de MISO avec
                                         // le reste de la donnee lue
       P1_bit . P16_INT4        = 0               ; // Clock a 0.
     }
   }

if(ucMode == 1)          // Si mode 1?
  {
   P1_bit . P16_INT4  = 1;
   for(i = 0; i < 8; i++)
     {
      ucDonneeLue = ucDonneeLue << 1;
      P1_bit . P16_INT4        = 1;

      if((ucValeur & 0x80) == 0x80)
        {
         P1_bit . P15_INT3 = 1;
        }
      else
        {
         P1_bit . P15_INT3 =0;
        }
      ucDonneeLue = ucDonneeLue + P1_bit . P14_INT2;
      P1_bit . P16_INT4        = 0;                // Met la clock a 0
     }
     P1_bit . P16_INT4         = 1;
   }

if(ucMode == 2)          // Si mode 2?
  {
   for(i = 0; i < 8; i++)
     {
      ucDonneeLue = ucDonneeLue << 1;
      if((ucValeur & 0x80) == 0x80)
        {
         P1_bit . P15_INT3 = 1;
        }
      else
        {
         P1_bit . P15_INT3 =0;
        }
       ucDonneeLue = ucDonneeLue + P1_bit . P14_INT2;
       P1_bit . P16_INT4        = 0;
       P1_bit . P16_INT4        = 1;
     }
   }

if(ucMode == 3)          // Si mode 3?
  {
   for(i = 0; i < 8; i++)
     {
      ucDonneeLue = ucDonneeLue << 1;
      P1_bit . P16_INT4        = 0;
      if((ucValeur & 0x80) == 0x80)
        {
         P1_bit . P15_INT3 = 1;
        }
      else
        {
         P1_bit . P15_INT3 = 0;
        }
      ucDonneeLue = ucDonneeLue + P1_bit . P14_INT2;
      P1_bit . P16_INT4        = 1;
     }
   }
//CS = HIGH;
return(ucDonneeLue);
}

UI CLSPI :: Write16(UI uiValeur, UC ucMode)
{
UC i;                      // Pour boucle
UI uiDonneeLue= 0;         // Pour la donnee a transmettre
P1_bit . P17_INT5 = 0;
if(ucMode == 0)            // Si mode 0?
  {
   P1_bit . P16_INT4 = 0;             // Met la clock a 0
   for(i = 0; i < 16; i++) // Fait 8 fois
     {
      if((uiValeur & 0x8000) == 0x8000)//fait un masque si egale a 1
        {
         P1_bit . P15_INT3 = 1;          // Envoie 1
        }
      else                  // Sinon
        {
         P1_bit . P15_INT3 =0;           // Envoie 0.
        }

      uiValeur    = uiValeur    << 1  ;  // Decale la valeur a envoyer
      uiDonneeLue = uiDonneeLue << 1  ;  // Decale la valeur lue
      P1_bit . P16_INT4        = 1              ; // Clock a 1
      uiDonneeLue = uiDonneeLue + P1_bit . P14_INT2; // Aditionne l'etat de MISO avec
                                        // le reste de la donnee lue
      P1_bit . P16_INT4        = 0               ; // Clock a 0.
     }
   }

   if(ucMode == 1)          // Si mode 1?
    {
     P1_bit . P16_INT4 = 1;
     for(i = 0; i < 16; i++)
       {
        uiDonneeLue = uiDonneeLue << 1;
        P1_bit . P16_INT4        = 1;
        if((uiValeur & 0x8000) == 0x8000)
         {
          P1_bit . P15_INT3 = 1;
         }
        else
         {
          P1_bit . P15_INT3 =0;
         }
        uiDonneeLue = uiDonneeLue + P1_bit . P14_INT2;
        P1_bit . P16_INT4        = 0;   // Met la clock a 0
       }
     P1_bit . P16_INT4 = 1;
    }
  if(ucMode == 2)          // Si mode 2?
    {
     for(i = 0; i < 16; i++)
       {
        uiDonneeLue = uiDonneeLue << 1;
        if((uiValeur & 0x8000) == 0x8000)
          {
           P1_bit . P15_INT3 = 1;
          }
        else
         {
          P1_bit . P15_INT3 =0;
         }
       uiDonneeLue = uiDonneeLue + P1_bit . P14_INT2;
       P1_bit . P16_INT4        = 0;
       P1_bit . P16_INT4        = 1;
      }
   }

   if(ucMode == 3)          // Si mode 3?
     {
      for(i = 0; i < 16; i++)
        {
         uiDonneeLue = uiDonneeLue << 1;
         P1_bit . P16_INT4        = 0;
         if((uiValeur & 0x8000) == 0x8000)
           {
            P1_bit . P15_INT3 = 1;
           }
         else
           {
            P1_bit . P15_INT3 =0;
           }
         uiDonneeLue = uiDonneeLue + P1_bit . P14_INT2;
         P1_bit . P16_INT4        = 1;
        }

      }
P1_bit . P17_INT5 = 1;
return(uiDonneeLue);
}

//*****************************************************************************
// Nom de la fct:       : Direction
// Description:         : Fonction qui permet de modifier la direction des ports
//                      : du MCP23S08
//
// INCLUDE:             : #include "_DeclarationGenerale.h", #include "CLSPI.h"
//
// Prototype:           : Direction(UC ucDirection)
//
//
// Parametre d'entree:  : ucDirection pour la direction des I/O.
//
// Parametre de sortie: : aucun
//
// Procedure appelees:  : aucune
//
// Exemple d'appel:     : val = clComSPI.ucSPIEcire(0xAA);
//
// Fait par             : Vincent Chouinard
// Date:                : 23 septembre 2014
// Revision             :
// Modification         :
//*****************************************************************************
void CLSPI :: Direction (UC ucDirection)
{
P1_bit . P17_INT5 = 0             ; // Chip select bas
Write(0x40, 0)       ; // Envoie l'adresse du boitier
Write(0x00, 0)       ; // Envoie le registre a modifier
Write(ucDirection, 0); // Envoie la direction
P1_bit . P17_INT5 = 1            ; // Chip Select haut
}

UC CLSPI :: WriteMPC (UC Data)
{
UC maVar = 0           ;  
P1_bit . P17_INT5 = 0               ; // Selectionne le MPC via chip select
Write(0x40, 0)         ; // Envoie l'adresse du boitier
Write(0x09, 0)         ; // Envoie l'adresse du reistre des IO
maVar = Write(Data, 0) ; // Envoie la donnee
P1_bit . P17_INT5 = 1              ; // End chip select
return(maVar)          ; // Envoie la donnee hexa a ecrire sur les IO
}

UC CLSPI :: ReadMPC (void)
{
P1_bit . P17_INT5       = 0            ; // Selectionne le MPC via chip select  
Write(0x41, 0)            ; // Envoie l'adresse du boitier
Write(0x09, 0)            ; // Envoie l'adresse du reistre des IO
UC maVar = Write(0, 0) ; // Lit le contenu du MPC
P1_bit . P17_INT5       = 1           ; // End chip select
return(maVar); // Lit la donnee hexa a correspondant aux IO
}

UC CLSPI :: WritePOT (UC Data)
{
P1_bit . P17_INT5       = 0           ; // Selectionne le MPC via chip select  
Write(0x00, 0)           ; // Pour activer le mode ecriture
UC maVar = Write(Data, 0); // Ecrit une valeur sur le POT
P1_bit . P17_INT5       = 1          ; // Selectionne le MPC via chip select
return(maVar)            ; // Ecrit la valeur sur le POT numerique
}

UC CLSPI :: WriteDAC (UC ucPin, int iData)
{
UC ucHaut;
UC ucBas;
P1_bit . P16_INT4 = 0; // DAC CHip Select ON

switch (ucPin)
  { 
  case 1:     // Write on DAC A
     ucHaut    = (iData << 8) & 0x000F; 
     ucHaut    = ucHaut |       0x80  ;    
     ucBas     = iData  &       0x00FF;    
     Write(ucHaut, 0);
     Write(ucBas,  0);
  break;
  
  case 2:     // Write on DAC B
     ucHaut    = (iData << 8) & 0x000F; 
     ucHaut    = ucHaut |       0x90  ;    
     ucBas     = iData  &       0x00FF;   
     Write(ucHaut, 0);
     Write(ucBas,  0); 
  break;

  case 3:     // Write on DAC C
     ucHaut    = (iData << 8) & 0x000F; 
     ucHaut    = ucHaut |       0xA0  ;    
     ucBas     = iData  &       0x00FF;   
     Write(ucHaut, 0);
     Write(ucBas,  0); 
  break;

  case 4:     // Write on DAC D
     ucHaut    = (iData << 8) & 0x000F; 
     ucHaut    = ucHaut |       0xB0  ;    
     ucBas     = iData  &       0x00FF;    
     Write(ucHaut, 0);
     Write(ucBas,  0);      
  break;  
 }

P1_bit . P16_INT4 = 1;// DAC CHip Select OFF
return(0);
}

UC CLSPI :: WriteMPC(UC NombreDonneesEnvoyer, UC Donnee1, UC Donnee2, UC Donnee3)
{
UC i;

UC Donnees[3] = {0x00};
   Donnees[0] = Donnee1;
   Donnees[1] = Donnee2;
   Donnees[2] = Donnee3;

P1_bit . P17_INT5 = 0;   // Un chip select

for(i = 0; i < NombreDonneesEnvoyer; i++)
  {
   Write(Donnees[i], 0);      // = Donnees[k];
   Delai(1);   // Delai au moins tant que le module du SPI est occupé 
  }

P1_bit . P17_INT5 = 1;   // Un chip select
return(0x01);
}

void CLSPI :: Delai(unsigned long Temps)
{
unsigned long k;
for(k = 0; k < Temps; k++);  
}
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX

