#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\CLI2CHard.cpp"
// ************************** FICHIER: CLI2CHARD.cpp****************************
//
// Fonctions de communication de base en I2C
//
// Application realisee avec IAR C++ 8.10
//
// AUTEUR : VINCENT CHOUINARD
// DATE CREATION : 2014/08/9 VERSION: 1.0
// DATE MODIFICATION: ****-**-**
//
// *****************************************************************************
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\CLI2CHard.h"
// ************************** FICHIER: CLI2CHARD.h *****************************
//
// Fonctions de communication de base en I2C
//
// Application realisee avec IAR C++ 8.10
//
// AUTEUR : VINCENT CHOUINARD
// DATE CREATION : 15/sept/2014 VERSION: 1.0
// DATE MODIFICATION: ****-**-**
//
// *****************************************************************************
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\_DeclarationGenerale.h"
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
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\ConversionKeilToIAR.h"
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

#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\TypeCible.h"
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
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\ioDS89C450.h"
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
#line 483 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\ioDS89C450.h"

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

#line 24 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\TypeCible.h"







//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
#line 14 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\ConversionKeilToIAR.h"




// *****************************************************************************
// DEFINITION DES  MODELES DE MEMOIRE
// *****************************************************************************






// *****************************************************************************


// Interruption activation






// Interruption priorite








// Interruption niveau activite.
































#line 87 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\ConversionKeilToIAR.h"

#line 96 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\ConversionKeilToIAR.h"




// *****************************************************************************

// *****************************************************************************
#line 211 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\ConversionKeilToIAR.h"
// *****************************************************************************

//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX

#line 17 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\_DeclarationGenerale.h"




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

#line 77 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\_DeclarationGenerale.h"

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
#line 13 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\CLI2CHard.h"
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\ConversionKeilToIAR.h"
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



#line 213 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\ConversionKeilToIAR.h"
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX

#line 14 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\CLI2CHard.h"




class CLI2CHARD
{
public:
   CLI2CHARD(void);  // Constructeur par defaut
  ~CLI2CHARD(void);  // Destructeur
  
   UI   static i;                             // array pointer 
   UC   static i2c_xmit_buf[256];             // message transmission buffer
   UC   static i2c_rcv_buf [256];             // message reception buffer          
   UC   static dummybyte, i2c_timeout;        // dummy byte to rcv, timeout cz  
   bool static bus_lost_flag;                 // Bus loss flag
   bool static i2cwait;                       // To wait
   bool static i2c_master;                    // To set master mode
   bool static i2c_xmitr;                     // Transmitter variable
   bool static slave_nack_flag;               // Slave nACK flag
   bool        i2c_init_flag;                 // Flag d'initialisation
   bool        i2c_timeout_flag;              // Ackpolling timeout flag
   
   void vEcritOctet(UC ucAdresse, UC ucData); // Pour Ecrire un octet
   UC   ucLitOctet (UC ucAdresse);            // Pour lire un octet
  
protected:
  
private:
   void vDelay(UINT16 i);                     // Just a little delai for ACKpolling purposes
   void vInitUpsd                  (void);    // uPSD Hardware I2C bus 2 init
   void vI2C_WaitInterrupt         (void);    // Wait for interrupt before continue
   __interrupt static void vIntrI2C(void);    // The interrupt function where all happens. 
};

//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
#line 13 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\CLI2CHard.cpp"
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\_DeclarationGenerale.h"
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
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\ConversionKeilToIAR.h"
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



#line 213 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\ConversionKeilToIAR.h"
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX

#line 17 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\_DeclarationGenerale.h"


#line 139 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\_DeclarationGenerale.h"
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
#line 14 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\CLI2CHard.cpp"
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\ConversionKeilToIAR.h"
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



#line 213 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\ConversionKeilToIAR.h"
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX

#line 15 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\CLI2CHard.cpp"

bool CLI2CHARD :: bus_lost_flag;     //
bool CLI2CHARD :: i2cwait;           // Pour controler le delais
bool CLI2CHARD :: i2c_master;        //
bool CLI2CHARD :: i2c_xmitr;         //
bool CLI2CHARD :: slave_nack_flag;   //

UI   CLI2CHARD :: i;                 // array pointer
UC   CLI2CHARD :: i2c_xmit_buf[256]; // message transmission buffer
UC   CLI2CHARD :: i2c_rcv_buf [256]; // message reception buffer
UC   CLI2CHARD :: dummybyte;
UC   CLI2CHARD :: i2c_timeout;       // dummy byte to rcv, timeout cz

// *****************************************************************************
//                            LE CONSTRUCTEUR initialisateur
// *****************************************************************************
CLI2CHARD :: CLI2CHARD(void)
{
vInitUpsd(); // Initialise les SFR du bus I2C du uPSD3254
}

// *****************************************************************************
//                            LE DESTRUCTEUR
// *****************************************************************************
CLI2CHARD :: ~CLI2CHARD(void)
{

}

// **********************FONCTION: vInitUpsd()**********************************
//
// DESCRIPTION: Initialise les registres du bus I2C hardware du uPSD
//
// INCLUDE: "_DeclarationGenerale.h"
//          "CLI2CHard.h"
//
// PROTOTYPE:           void vInitUpsd(void)
//
// PROCEDURE D'APPEL:   vInitUpsd()
//
// PARAMETRE D'ENTREE:  AUCUN
//
// PARAMETRE DE SORTIE: AUCUN
//
// EXEMPLE: vInitUpsd() ---> Initialise le bus I2C Hardware
//
// Auteur:              Vincent Chouinard
// Date:                16 septembre 2014   (Version 1.0)
// Modification:
// *****************************************************************************
void CLI2CHARD :: vInitUpsd(void)
{
P3SFS           |= 0xC0;  // Enable P3.7 for SCL, P3.6 for SDA
S2CON           |= 0x01;  // Setup I2C-2 for 500KHz (24MHz XTAL)
i2c_init_flag    = 1;     // set init done flag
i2c_timeout_flag = 0;     // clear timeout error flag
i2cwait          = 0;     // Petit delais d'attente
IPA             |= 0x02;  // set high priority for EI2C
IEA             |= 0x02;  // set EI2C I2C Int. Enable bit
}

// **********************FONCTION: vI2C_WaitInterrupt()*************************
//
// DESCRIPTION: Permet d'attendre qu'un interrupt survient
//
// INCLUDE: "_DeclarationGenerale.h"
//          "CLI2CHard.h"
//
// PROTOTYPE:           void vI2C_WaitInterrupt(void)
//
// PROCEDURE D'APPEL:   vI2C_WaitInterrupt()
//
// PARAMETRE D'ENTREE:  AUCUN
//
// PARAMETRE DE SORTIE: AUCUN
//
// EXEMPLE: vI2C_WaitInterrupt() ---> Attend un interrupt
//
// Auteur:              Vincent Chouinard
// Date:                16 septembre 2014   (Version 1.0)
// Modification:
// *****************************************************************************
void CLI2CHARD :: vI2C_WaitInterrupt(void)
{
i2cwait     = 1;            // Flag d'attente
i2c_timeout = 0;            // Flag de depassement d'attente

while (i2cwait == 1)        // Wait for int to clear flag
  {                         //
   if(i2c_timeout >= 2 )    // XmS timeout loop
     {                      //
      i2c_timeout_flag = 1; // set error flag
      i2cwait          = 0; // Reset le flag d'attente
     }                      //
   vDelay(i);               // 1 mS delay (approximatively)
   i2c_timeout++;           // for the timeloop
  }
}

// **********************FONCTION: vIntrI2C()***********************************
//
// DESCRIPTION: Fonction PRAGMA VECTOR d'interruption
//
// INCLUDE: "_DeclarationGenerale.h"
//          "CLI2CHard.h"
//
// PROTOTYPE:            #pragma vector = 0x43 __interrupt void CLI2CHARD :: vIntrI2C(void)
//
// PROCEDURE D'APPEL:   Purement hardware
//
// PARAMETRE D'ENTREE:  AUCUN
//
// PARAMETRE DE SORTIE: AUCUN
//
// EXEMPLE: Survient lors d'une interruption sur le vecteur 0x43
//
// Auteur:              Vincent Chouinard
// Date:                16 septembre 2014   (Version 1.0)
// Modification:
// *****************************************************************************
 #pragma vector = 0x43                       // Lors d'une interruption de type INTERRUPT I2C
__interrupt void CLI2CHARD :: vIntrI2C(void) // I2C Hardware interrupt
{
if((S2STA & BLOST) == 1)    // If I2C bus is out of sync
  {
   S2DAT = dummy;           // send dummy byte
   bus_lost_flag    = 1;    // Activate bus loss flag
  }

if((S2STA & ACKR)  == 1)    // If bus send nACK
  {
   S2DAT = dummy;           // send dummy byte
   slave_nack_flag  = 1;    // Activate bus loss flag
  }
 
if(i2c_master & i2c_xmitr)  // If master must transmit
  {                         // Master transmitter mode
   i2cwait = 0;             // reset wait flag
  }

if(i2c_master & ~i2c_xmitr) // If master must receive
  {                         // Master receiver mode
   i2cwait = 0;             // reset wait flag
  }
}

// **********************FONCTION: vEcritOctet()*************************
//
// DESCRIPTION: Permet d'attendre qu'un interrupt survient
//
// INCLUDE: "_DeclarationGenerale.h"
//          "CLI2CHard.h"
//
// PROTOTYPE:           void vEcritOctet(UC, UC)
//
// PROCEDURE D'APPEL:   vEcritOctet(UC ucAdresse, UC ucData)
//
// PARAMETRE D'ENTREE:  ucAdresse et ucData
//
// PARAMETRE DE SORTIE: AUCUN
//
// EXEMPLE: vEcritOctet(0x43, 0x8A) ---> Ecrit 8A sur un chip dont l'adresse est 0x43
//
// Auteur:              Vincent Chouinard
// Date:                16 septembre 2014   (Version 1.0)
// Modification:
// *****************************************************************************
void CLI2CHARD :: vEcritOctet(UC ucAdresse, UC ucData)
{
EN1 = 1;                    // Enable I2C.
STA = 1;                    // Send start bit
S2DAT = ucAdresse /*& 0xFE*/;   // Envoyer adresse I2C du dispositif
vI2C_WaitInterrupt();       // Wait for interrupt
AA    = 1;                  // Send ACKowledge
STA   = 0;                  // Clear STA (Disable START)

// ********************************************************
// CE QUI EST IMPORTANT C'EST DE METTRE LE STOP AVANT
// LA DERNIERE INTERRUPTION SOIT LA TRANSMISSION DU DERNIER
// OCTET.
// ********************************************************
STO   = 1;                  // Send STOP bit
S2DAT = ucData;             // Envoyer la donnee ucData
vI2C_WaitInterrupt();       // Wait for interrupt.
STA   = 0;                  // Disable START).
STO   = 0;                  // Send STOP bit).
EN1   = 0;                  // Disiable I2C-2
}

// **********************FONCTION: ucLitOctet()*************************
//
// DESCRIPTION: Permet d'attendre qu'un interrupt survient
//
// INCLUDE: "_DeclarationGenerale.h"
//          "CLI2CHard.h"
//
// PROTOTYPE:           UC ucLitOctet(UC)
//
// PROCEDURE D'APPEL:   UC = ucLitOctet(UC ucAdresse)
//
// PARAMETRE D'ENTREE:  ucAdresse
//
// PARAMETRE DE SORTIE: ucData
//
// EXEMPLE: UC = ucLitOctet(0x43) ---> Lit la data sur un chip dont l'adresse est 0x43
//
// Auteur:              Vincent Chouinard
// Date:                16 septembre 2014   (Version 1.0)
// Modification:
// *****************************************************************************
UC CLI2CHARD :: ucLitOctet(UC ucAdresse)
{
UC ucData;                  // Pour enregistrer la donnee lue
EN1 = 1;                    // Enable I2C.
STA = 1;                    // Set STA to send start bit).

                            // Envoyer adresse du dispositif en lecture.
                            // Masquer pour s'assurer d'une adresse de lecture.
S2DAT = (ucAdresse | 0x01); // I2C addresse en lecture (R/W bit)
vI2C_WaitInterrupt();       // Wait for interrupt

AA  = 1;                    // Send ACKowledge
STA = 0;                    // Disable START
STO = 0;                    // Send STOP bit

                            // Important de conserver les 2 lignes suivantes
                            // pour mettre le I2C en entree.
S2DAT = 0xFF;               // Send byte for rcv mode.
vI2C_WaitInterrupt();       // Wait for interrupt

// ********************************************************
// CE QUI EST IMPORTANT C'EST DE METTRE LE STOP AVANT
// LA DERNIERE INTERRUPTION SOIT LA RECEPTION DU DERNIER
// OCTET.
// ********************************************************
STO    = 1;                 // Send STOP bit
ucData = S2DAT;             // Lire dernier octet.
vI2C_WaitInterrupt();       // Wait for interrupt
AA     = 0;                 // Send Not ACKnowledge
STA    = 0;                 // Disable START
EN1    = 0;                 // Disiable I2C-2
return(ucData);
}


// **********************FONCTION: vDelay()*************************
//
// DESCRIPTION: Permet d'attendre qu'un interrupt survient
//
// INCLUDE: "_DeclarationGenerale.h"
//          "CLI2CHard.h"
//
// PROTOTYPE:           void vDelay(UINT16)
//
// PROCEDURE D'APPEL:   vDelay(UINT16)
//
// PARAMETRE D'ENTREE:  vDelay
//
// PARAMETRE DE SORTIE: AUCUN
//
// EXEMPLE: vDelay(555) ---> Cre un delais de 555 unite de temps
//
// Auteur:              Vincent Chouinard
// Date:                16 septembre 2014   (Version 1.0)
// Modification:
// *****************************************************************************
void CLI2CHARD :: vDelay(UINT16 iWasteMyTime)
{
for(iWasteMyTime = 0; iWasteMyTime < 10; iWasteMyTime++)
  {
    /*Perd du temps dans une boucle FOR*/
  }
}
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
