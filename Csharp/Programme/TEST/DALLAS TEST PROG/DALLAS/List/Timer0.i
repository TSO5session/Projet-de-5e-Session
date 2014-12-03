#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\Timer0.cpp"
// **************************Timer0.cpp
// Auteur:       Vincent Chouinard
// Date:         24 septembre 2014
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
#line 12 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\Timer0.cpp"
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\Timer0.h"
// **************************Timer0.h
// Auteur:       Vincent Chouinard
// Date:         24 septembre 2014
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
#line 12 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\Timer0.h"



class Timer0 //: public CLAutreClasse
{
public:
   Timer0(void);             // ***Constructeur par defaut
   Timer0(UC ucCustomMili);  // ***Constructeur initialisateur (Initialise entre 1 et 25 ms)
  ~Timer0(void);             // ***Destructeur

   char DelayMs(void);
   void ClockGenerator(void);

protected:

private:
   void InitTimer0(void);             // Initialise le timer a 1 ms
   void CustomSpeed(UC ucCustomMili); // Timer custom (1-25ms) du constructeur initialisateur
};



//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
#line 13 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\Csharp\\TEST\\DALLAS TEST PROG\\Timer0.cpp"
UC   DutyCycle = 0;
//******************************************************************************
//                            LE CONSTRUCTEUR PAR DEFAUT
// *****************************************************************************
Timer0 :: Timer0(void)
{
InitTimer0();
}

//******************************************************************************
//                            LE CONSTRUCTEUR PAR DEFAUT
// *****************************************************************************
Timer0 :: Timer0(UC ucParametre)
{
CustomSpeed(ucParametre);
}


// *****************************************************************************
//                            LE DESTRUCTEUR
// *****************************************************************************
Timer0 :: ~Timer0(void)
{

}

/*
Note: La fréquence en HZ doit etre passee comme suit:
250hz = 1sec / 250 = 0.004 sec ---> Passez 4 en parametre
*/
void Timer0 :: ClockGenerator(void)
{
if(TCON_bit.TF0 == 1)     // Si flag de depassement du timer0 (default =  1ms)
  {
   TCON_bit.TF0 = 0;      // Reinitialisation du flag de depassement
   TH0          = 0xF8;   // Remet le compteur a 1ms
   TL0          = 0x60;   // Remet le compteur a 1ms
   DutyCycle++;
   if(DutyCycle <= 3){P1_bit . P17_INT5 = 1;}
   if(DutyCycle == 4){P1_bit . P17_INT5 = 0, DutyCycle = 0;}
  }
}

char Timer0 :: DelayMs(void)  // retourne 1 a chaque ms
{
char i;
i = 0;                        // Dit qu'il n'y a pas d'interrupt
if(TCON_bit.TF0 == 1)         // Si flag de depassement du timer0 ( a 10ms)
  {
   TCON_bit.TF0 = 0;          // Reinitialisation du flag de depassement
   TH0 = 0xF8;                // Remet le compteur a 1ms
   TL0 = 0x60;                // Remet le compteur a 1ms
   i   = 1;                   // Dit qu'il y a un interrupt
  }
return(i);
}

void Timer0 :: InitTimer0(void)       //Initialise le timer 0 a 1ms
{
IE_bit . EA           = 0;
TMOD         = (TMOD & 0xF0) | 0x01;  // timer0 en mode timer 16bit
TL0          = 0x60;                  // Initialise le timer0 a 1ms
TH0          = 0xF8;                  // Initialise le timer0 a 1ms
TH0          = 0;                     // Clear le flag d'overflow du timer0
IE_bit.ET0   = 0;                     // Desactive les interruptions timer0
TCON_bit.TR0 = 1;                     // Stop le timer0
IE_bit . EA           = 1;                     // Enable Interrupt
}

void Timer0 :: CustomSpeed(UC ucCustomMili) // Initialise un timer custom via
{                                           // le constructeur initialisateur
IE_bit . EA           = 0;                           // Desactive les interruptions
TMOD         = (TMOD & 0xF0) | 0x01;        // timer0 en mode timer 16bit

switch(ucCustomMili)//En fonction des milisecondes demandees
  {
   case 1:
      TL0 = 0x02;   // Initialise le timer0 a 1ms
      TH0 = 0xF8;   // Initialise le timer0 a 1ms
   break;

   case 2:
      TL0 = 0x05;   // Initialise le timer0 a 2ms
      TH0 = 0xF0;   // Initialise le timer0 a 2ms
   break;

   case 3:
      TL0 = 0x08;   // Initialise le timer0 a 3ms
      TH0 = 0xE8;   // Initialise le timer0 a 3ms
   break;

   case 4:
      TL0 = 0xBF;   // Initialise le timer0 a 4ms
      TH0 = 0xE0;   // Initialise le timer0 a 4ms
   break;

   case 5:
      TL0 = 0xEF;   // Initialise le timer0 a 5ms
      TH0 = 0xD8;   // Initialise le timer0 a 5ms
   break;

   case 6:
      TL0 = 0x1F;   // Initialise le timer0 a 6ms
      TH0 = 0xD1;   // Initialise le timer0 a 6ms
   break;

   case 7:
      TL0 = 0x4F;   // Initialise le timer0 a 7ms
      TH0 = 0xC9;   // Initialise le timer0 a 7ms
   break;

   case 8:
      TL0 = 0x07;   // Initialise le timer0 a 8ms
      TH0 = 0xC1;   // Initialise le timer0 a 8ms
   break;

   case 9:
      TL0 = 0xAF;   // Initialise le timer0 a 9ms
      TH0 = 0xB9;   // Initialise le timer0 a 9ms
   break;

   case 10:
      TL0 = 0xDF;   // Initialise le timer0 a 10ms
      TH0 = 0xB1;   // Initialise le timer0 a 10ms
   break;

   case 11:
      TL0 = 0x0F;   // Initialise le timer0 a 11ms
      TH0 = 0xAA;   // Initialise le timer0 a 11ms
   break;

   case 12:
      TL0 = 0x3F;   // Initialise le timer0 a 12ms
      TH0 = 0xA2;   // Initialise le timer0 a 12ms
   break;

  case 13:
      TL0 = 0x6F;   // Initialise le timer0 a 13ms
      TH0 = 0x9A;   // Initialise le timer0 a 13ms
   break;

   case 14:
      TL0 = 0x9F;   // Initialise le timer0 a 14ms
      TH0 = 0x92;   // Initialise le timer0 a 14ms
   break;

   case 15:
      TL0 = 0xCF;   // Initialise le timer0 a 15ms
      TH0 = 0x8A;   // Initialise le timer0 a 15ms
   break;

   case 16:
      TL0 = 0xFF;   // Initialise le timer0 a 16ms
      TH0 = 0x82;   // Initialise le timer0 a 16ms
   break;

   case 17:
      TL0 = 0x2F;   // Initialise le timer0 a 17ms
      TH0 = 0x7B;   // Initialise le timer0 a 17ms
   break;

   case 18:
      TL0 = 0x5F;   // Initialise le timer0 a 18ms
      TH0 = 0x73;   // Initialise le timer0 a 18ms
   break;

   case 19:
      TL0 = 0x8F;   // Initialise le timer0 a 19ms
      TH0 = 0x6B;   // Initialise le timer0 a 19ms
   break;

   case 20:
      TL0 = 0xBF;   // Initialise le timer0 a 20ms
      TH0 = 0x63;   // Initialise le timer0 a 20ms
   break;

   case 21:
      TL0 = 0xEF;   // Initialise le timer0 a 21ms
      TH0 = 0x5B;   // Initialise le timer0 a 21ms
   break;

   case 22:
      TL0 = 0x1F;   // Initialise le timer0 a 22ms
      TH0 = 0x54;   // Initialise le timer0 a 22ms
   break;

   case 23:
      TL0 = 0x4F;   // Initialise le timer0 a 23ms
      TH0 = 0x4C;   // Initialise le timer0 a 23ms
   break;

   case 24:
      TL0 = 0x7F;   // Initialise le timer0 a 24ms
      TH0 = 0x44;   // Initialise le timer0 a 24ms
   break;

   case 25:
      TL0 = 0xAF;   // Initialise le timer0 a 25ms
      TH0 = 0x3C;   // Initialise le timer0 a 25ms
   break;

   default:
      TL0 = 0x60;   // Initialise le timer0 a 1ms
      TH0 = 0xF8;   // Initialise le timer0 a 1ms
   break;
}
TH0          = 0;   // Clear le flag d'overflow du timer0
IE_bit.ET0   = 0;   // Desactive les interruptions timer0
TCON_bit.TR0 = 1;   // Stop le timer0
IE_bit . EA           = 1;   // Enable Interrupt
}
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
