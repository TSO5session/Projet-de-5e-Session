#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\NomDuProjet.cpp"
// **************************Main.c
// Auteur:      Vincent Chouinard
// Date:        26 octobre 2014
// Version :    1.0
//
// Compilateur: IAR 8.10
//
// Description: Fichier principal
//
// *****************************************************************************
// **** LES INCLUDES ****************//
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\CLI2CPort.h"
// ************************** FICHIER: CLI2CPORT.H *****************************
//
// Fonctions d'I/O du protocole I2C
//
// Application realisee avec IAR C++ 8.10
//
// AUTEUR : VINCENT CHOUINARD
// DATE CREATION : 2014/03/27 VERSION: 1.0
// DATE MODIFICATION: ****-**-**
//
// Description: Fonctions d'acces au I/0 (High level access) du protocole I2C
//
// DESCRIPTION DES FONCTIONS
//
// UC  ucI2CLireDonnee(UC ucAdrBoitier, UC ucAdrRegistre);
// void vI2CLireDonnee(UC ucAdrBoitier, USI uiAdrRegistre, UC ucTypeAdr,
//                     UC *ucpRecevoirDonnee, UC ucNbrLectures);
//
// void vI2CEcrireDonnee(UC ucAdrBoitier, UC ucAdrRegistre, UC ucDonnee);
// void vI2CEcrireDonnee(UC ucAdrBoitier, USI uiAdrRegistre, UC ucTypeAdr,
//                       UC *ucpDonnee, UC ucNbrEcritures);
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




#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\iouPSD3254A.h"
/***************************************************************************
 *                                - iouPSD3254A.h -
 *
 * Special header for the STMicroelectronics uPSD3254A Microcontroller.
 *
 ***************************************************************************/






   #pragma system_include

#pragma language=extended

/*-------------------------------------------------------------------------
 *   8051 Core
 *-------------------------------------------------------------------------*/

__sfr __no_init volatile unsigned char ACC @ 0xE0; /* Accumulator */
__sfr __no_init volatile union
{
  unsigned char PSW; /* Program Status Word */
  struct /* Program Status Word */
  {
    unsigned char P : 1;
    unsigned char F1 : 1;
    unsigned char OV : 1;
    unsigned char RS0 : 1;
    unsigned char RS1 : 1;
    unsigned char FO : 1;
    unsigned char AC : 1;
    unsigned char CY : 1;
  } PSW_bit;
} @ 0xD0;
__sfr __no_init volatile unsigned char SP @ 0x81; /* Stack Ptr */
__sfr __no_init volatile unsigned char DPL @ 0x82; /* Data Ptr Low */
__sfr __no_init volatile unsigned char DPH @ 0x83; /* Data Ptr High */
__sfr __no_init volatile unsigned char B @ 0xF0; /* B Register */

/*-------------------------------------------------------------------------
 *   Interrupt
 *-------------------------------------------------------------------------*/

__sfr __no_init volatile union
{
  unsigned char IP; /* Interrupt Priority */
  struct /* Interrupt Priority */
  {
    unsigned char PX0 : 1;
    unsigned char PT0 : 1;
    unsigned char PX1 : 1;
    unsigned char PT1 : 1;
    unsigned char PS : 1;
    unsigned char PT2 : 1;
    unsigned char  : 1;
    unsigned char  : 1;
  } IP_bit;
} @ 0xB8;
__sfr __no_init volatile union
{
  unsigned char IEA; /* Interrupt Enable (2nd) */
  struct /* Interrupt Enable (2nd) */
  {
    unsigned char EUSB : 1;
    unsigned char EI2C : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char ES2 : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char EDDC : 1;
  } IEA_bit;
} @ 0xA7;
__sfr __no_init volatile union
{
  unsigned char IE; /* Interrupt Enable */
  struct /* Interrupt Enable */
  {
    unsigned char EX0 : 1;
    unsigned char ET0 : 1;
    unsigned char EX1 : 1;
    unsigned char ET1 : 1;
    unsigned char ES : 1;
    unsigned char ET2 : 1;
    unsigned char  : 1;
    unsigned char EA : 1;
  } IE_bit;
} @ 0xA8;
__sfr __no_init volatile union
{
  unsigned char IPA; /* Interrupt Priority (2nd) */
  struct /* Interrupt Priority (2nd) */
  {
    unsigned char PUSB : 1;
    unsigned char PI2C : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char PS2 : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char PDDC : 1;
  } IPA_bit;
} @ 0xB7;

/*-------------------------------------------------------------------------
 *   I2C Bus
 *-------------------------------------------------------------------------*/

__sfr __no_init volatile union
{
  unsigned char S2STA; /* I2C Bus Status */
  struct /* I2C Bus Status */
  {
    unsigned char SLV : 1;
    unsigned char ACK_R : 1;
    unsigned char Blost : 1;
    unsigned char Bbusy : 1;
    unsigned char  : 1;
    unsigned char Intr : 1;
    unsigned char Stop : 1;
    unsigned char GC : 1;
  } S2STA_bit;
} @ 0xDD;
__sfr __no_init volatile unsigned char S2ADR @ 0xDF; /* I2C address */
__sfr __no_init volatile unsigned char S1SETUP @ 0xD1; /* DDC I2C (S1) Setup */
__sfr __no_init volatile unsigned char S2SETUP @ 0xD2; /* I2C (S2) Setup */
__sfr __no_init volatile union
{
  unsigned char S2CON; /* I2C Bus Control Reg */
  struct /* I2C Bus Control Reg */
  {
    unsigned char CR0 : 1;
    unsigned char CR1 : 1;
    unsigned char AA : 1;
    unsigned char ADDR : 1;
    unsigned char STO : 1;
    unsigned char STA : 1;
    unsigned char EN1 : 1;
    unsigned char CR2 : 1;
  } S2CON_bit;
} @ 0xDC;
__sfr __no_init volatile union
{
  unsigned char S1CON; /* DDC I2C Control Reg */
  struct /* DDC I2C Control Reg */
  {
    unsigned char CR0 : 1;
    unsigned char CR1 : 1;
    unsigned char AA : 1;
    unsigned char ADDR : 1;
    unsigned char STO : 1;
    unsigned char STA : 1;
    unsigned char ENI1 : 1;
    unsigned char CR2 : 1;
  } S1CON_bit;
} @ 0xD8;
__sfr __no_init volatile union
{
  unsigned char S1STA; /* DDC I2C Status */
  struct /* DDC I2C Status */
  {
    unsigned char SLV : 1;
    unsigned char ACK_R : 1;
    unsigned char Blost : 1;
    unsigned char Bbusy : 1;
    unsigned char  : 1;
    unsigned char Intr : 1;
    unsigned char Stop : 1;
    unsigned char GC : 1;
  } S1STA_bit;
} @ 0xD9;

/*-------------------------------------------------------------------------
 *   USB
 *-------------------------------------------------------------------------*/

__sfr __no_init volatile union
{
  unsigned char UADR; /* USB Address Register */
  struct /* USB Address Register */
  {
    unsigned char UADD0 : 1;
    unsigned char UADD1 : 1;
    unsigned char UADD2 : 1;
    unsigned char UADD3 : 1;
    unsigned char UADD4 : 1;
    unsigned char UADD5 : 1;
    unsigned char UADD6 : 1;
    unsigned char USBEN : 1;
  } UADR_bit;
} @ 0xEE;
__sfr __no_init volatile union
{
  unsigned char UDR0; /* USB Endpt0 Data Recv */
  struct /* USB Endpt0 Data Recv */
  {
    unsigned char UDR00 : 1;
    unsigned char UDR01 : 1;
    unsigned char UDR02 : 1;
    unsigned char UDR03 : 1;
    unsigned char UDR04 : 1;
    unsigned char UDR05 : 1;
    unsigned char UDR06 : 1;
    unsigned char UDR07 : 1;
  } UDR0_bit;
} @ 0xEF;
__sfr __no_init volatile unsigned char USCL @ 0xE1; /* 8-bit Prescaler for USB logic */
__sfr __no_init volatile union
{
  unsigned char UCON0; /* USB Endpt0 Xmit Control */
  struct /* USB Endpt0 Xmit Control */
  {
    unsigned char TP0SIZ0 : 1;
    unsigned char TP0SIZ1 : 1;
    unsigned char TP0SiZ2 : 1;
    unsigned char TP0SIZ3 : 1;
    unsigned char RX0E : 1;
    unsigned char TX0E : 1;
    unsigned char STALL0 : 1;
    unsigned char TSEQ0 : 1;
  } UCON0_bit;
} @ 0xEA;
__sfr __no_init volatile union
{
  unsigned char UDT1; /* USB Endpt1 Data Xmit */
  struct /* USB Endpt1 Data Xmit */
  {
    unsigned char UDT10 : 1;
    unsigned char UDT11 : 1;
    unsigned char UDT12 : 1;
    unsigned char UDT13 : 1;
    unsigned char UDT14 : 1;
    unsigned char UDT15 : 1;
    unsigned char UDT16 : 1;
    unsigned char UDT17 : 1;
  } UDT1_bit;
} @ 0xE6;
__sfr __no_init volatile union
{
  unsigned char UCON1; /* USB Endpt1 Xmit Control */
  struct /* USB Endpt1 Xmit Control */
  {
    unsigned char TP1SIZ0 : 1;
    unsigned char TP1SIZ1 : 1;
    unsigned char TP1SiZ2 : 1;
    unsigned char TP1SIZ3 : 1;
    unsigned char FRESUM : 1;
    unsigned char  : 1;
    unsigned char EP12SEL : 1;
    unsigned char TSEQ1 : 1;
  } UCON1_bit;
} @ 0xEB;
__sfr __no_init volatile union
{
  unsigned char UDT0; /* USB Endpt0 Data Xmit */
  struct /* USB Endpt0 Data Xmit */
  {
    unsigned char UDT00 : 1;
    unsigned char UDT01 : 1;
    unsigned char UDT02 : 1;
    unsigned char UDT03 : 1;
    unsigned char UDT04 : 1;
    unsigned char UDT05 : 1;
    unsigned char UDT06 : 1;
    unsigned char UDT07 : 1;
  } UDT0_bit;
} @ 0xE7;
__sfr __no_init volatile union
{
  unsigned char UCON2; /* USB Control Register */
  struct /* USB Control Register */
  {
    unsigned char STALL1 : 1;
    unsigned char STALL2 : 1;
    unsigned char EP1E : 1;
    unsigned char EP2E : 1;
    unsigned char SOUT : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
  } UCON2_bit;
} @ 0xEC;
__sfr __no_init volatile union
{
  unsigned char UISTA; /* USB Interrupt Status */
  struct /* USB Interrupt Status */
  {
    unsigned char RESUMF : 1;
    unsigned char EOPF : 1;
    unsigned char RXD1F : 1;
    unsigned char RXD0F : 1;
    unsigned char TXD0F : 1;
    unsigned char RSTF : 1;
    unsigned char  : 1;
    unsigned char SUSPND : 1;
  } UISTA_bit;
} @ 0xE8;
__sfr __no_init volatile union
{
  unsigned char USTA; /* USB Endpt0 Status */
  struct /* USB Endpt0 Status */
  {
    unsigned char RP0SIZ0 : 1;
    unsigned char RP0SIZ1 : 1;
    unsigned char RP0SIZ2 : 1;
    unsigned char RP0SIZ3 : 1;
    unsigned char OUT : 1;
    unsigned char IN : 1;
    unsigned char SETUP : 1;
    unsigned char RSEQ : 1;
  } USTA_bit;
} @ 0xED;
__sfr __no_init volatile union
{
  unsigned char UIEN; /* USB Interrupt Enable */
  struct /* USB Interrupt Enable */
  {
    unsigned char RESUMIE : 1;
    unsigned char EOPIE : 1;
    unsigned char TXD1IE : 1;
    unsigned char RXD0IE : 1;
    unsigned char TXD0IE : 1;
    unsigned char RSTFIE : 1;
    unsigned char RSTE : 1;
    unsigned char SUSPNDIE : 1;
  } UIEN_bit;
} @ 0xE9;

/*-------------------------------------------------------------------------
 *   I/O Port
 *-------------------------------------------------------------------------*/

__sfr __no_init volatile union
{
  unsigned char P1; /* Port 1 */
  struct /* Port 1 */
  {
    unsigned char P10 : 1;
    unsigned char P11 : 1;
    unsigned char P12 : 1;
    unsigned char P13 : 1;
    unsigned char P14 : 1;
    unsigned char P15 : 1;
    unsigned char P16 : 1;
    unsigned char P17 : 1;
  } P1_bit;
} @ 0x90;
__sfr __no_init volatile union
{
  unsigned char P4; /* New Port 4 */
  struct /* New Port 4 */
  {
    unsigned char P40 : 1;
    unsigned char P41 : 1;
    unsigned char P42 : 1;
    unsigned char P43 : 1;
    unsigned char P44 : 1;
    unsigned char P45 : 1;
    unsigned char P46 : 1;
    unsigned char P47 : 1;
  } P4_bit;
} @ 0xC0;
__sfr __no_init volatile union
{
  unsigned char P1SFS; /* Port 1 Select Register */
  struct /* Port 1 Select Register */
  {
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char P1S4 : 1;
    unsigned char P1S5 : 1;
    unsigned char P1S6 : 1;
    unsigned char P1S7 : 1;
  } P1SFS_bit;
} @ 0x91;
__sfr __no_init volatile union
{
  unsigned char P0; /* Port 0 */
  struct /* Port 0 */
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
__sfr __no_init volatile union
{
  unsigned char P3; /* Port 3 */
  struct /* Port 3 */
  {
    unsigned char P30 : 1;
    unsigned char P31 : 1;
    unsigned char P32 : 1;
    unsigned char P33 : 1;
    unsigned char P34 : 1;
    unsigned char P35 : 1;
    unsigned char P36 : 1;
    unsigned char P37 : 1;
  } P3_bit;
} @ 0xB0;
__sfr __no_init volatile union
{
  unsigned char P2; /* Port 2 */
  struct /* Port 2 */
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
__sfr __no_init volatile union
{
  unsigned char P3SFS; /* Port 3 Select Register */
  struct /* Port 3 Select Register */
  {
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char P3S6 : 1;
    unsigned char P3S7 : 1;
  } P3SFS_bit;
} @ 0x93;
__sfr __no_init volatile union
{
  unsigned char P4SFS; /* Port 4 Select Register */
  struct /* Port 4 Select Register */
  {
    unsigned char P4S0 : 1;
    unsigned char P4S1 : 1;
    unsigned char P4S2 : 1;
    unsigned char P4S3 : 1;
    unsigned char P4S4 : 1;
    unsigned char P4S5 : 1;
    unsigned char P4S6 : 1;
    unsigned char P4S7 : 1;
  } P4SFS_bit;
} @ 0x94;

/*-------------------------------------------------------------------------
 *   PWM
 *-------------------------------------------------------------------------*/

__sfr __no_init volatile unsigned char PWM4P @ 0xAA; /* PWM 4 Period */
__sfr __no_init volatile unsigned char PWM4W @ 0xAB; /* PWM 4 Pulse Width */
__sfr __no_init volatile union
{
  unsigned char PWMCON; /* PWM Control Polarity */
  struct /* PWM Control Polarity */
  {
    unsigned char CFG0 : 1;
    unsigned char CFG1 : 1;
    unsigned char CFG2 : 1;
    unsigned char CFG3 : 1;
    unsigned char CFG4 : 1;
    unsigned char PWME : 1;
    unsigned char PWMP : 1;
    unsigned char PWML : 1;
  } PWMCON_bit;
} @ 0xA1;
__sfr __no_init volatile unsigned char PWM1 @ 0xA3; /* PWM1 Output Duty Cycle */
__sfr __no_init volatile unsigned char PWM2 @ 0xA4; /* PWM2 Output Duty Cycle */
__sfr __no_init volatile unsigned char PWM3 @ 0xA5; /* PWM3 Output Duty Cycle */

/*-------------------------------------------------------------------------
 *   Serial I/O
 *-------------------------------------------------------------------------*/

__sfr __no_init volatile unsigned char SBUF @ 0x99; /* Serial Buffer */
__sfr __no_init volatile union
{
  unsigned char SCON2; /* 2nd UART Ctrl Register */
  struct /* 2nd UART Ctrl Register */
  {
    unsigned char RI : 1;
    unsigned char TI : 1;
    unsigned char RB8 : 1;
    unsigned char TB8 : 1;
    unsigned char REN : 1;
    unsigned char SM2 : 1;
    unsigned char SM1 : 1;
    unsigned char SM0 : 1;
  } SCON2_bit;
} @ 0x9A;
__sfr __no_init volatile unsigned char SBUF2 @ 0x9B; /* 2nd UART Serial Buffer */
__sfr __no_init volatile union
{
  unsigned char SCON; /* Serial Control Register */
  struct /* Serial Control Register */
  {
    unsigned char RI : 1;
    unsigned char TI : 1;
    unsigned char RB8 : 1;
    unsigned char TB8 : 1;
    unsigned char REN : 1;
    unsigned char SM2 : 1;
    unsigned char SM1 : 1;
    unsigned char SM0 : 1;
  } SCON_bit;
} @ 0x98;

/*-------------------------------------------------------------------------
 *   Watchdog timer
 *-------------------------------------------------------------------------*/

__sfr __no_init volatile unsigned char WDKEY @ 0xAE; /* Watch Dog Key Register */
__sfr __no_init volatile unsigned char WDRST @ 0xA6; /* Watch Dog Reset */

/*-------------------------------------------------------------------------
 *   System Management
 *-------------------------------------------------------------------------*/

__sfr __no_init volatile unsigned char S2DAT @ 0xDE; /* Data Hold Register */
__sfr __no_init volatile unsigned char PSCL0L @ 0xB1; /* Prescaler 0 Low (8-bit) */
__sfr __no_init volatile unsigned char RAMBUF @ 0xD4; /* DDC Ram Buffer */
__sfr __no_init volatile unsigned char PSCL0H @ 0xB2; /* Prescaler 0 High (8-bit) */
__sfr __no_init volatile unsigned char DDCDAT @ 0xD5; /* DDC Data xmit register */
__sfr __no_init volatile unsigned char PSCL1L @ 0xB3; /* Prescaler 1 Low (8-bit) */
__sfr __no_init volatile unsigned char PWM0 @ 0xA2; /* Output Duty Cycle */
__sfr __no_init volatile unsigned char S1DAT @ 0xDA; /* Data Hold Register */
__sfr __no_init volatile unsigned char DDCADR @ 0xD6; /* Addr pointer register */
__sfr __no_init volatile unsigned char PSCL1H @ 0xB4; /* Prescaler 1 High (8-bit) */
__sfr __no_init volatile unsigned char S1ADR @ 0xDB; /* DDC I2C address */
__sfr __no_init volatile union
{
  unsigned char DDCCON; /* DDC Control Register */
  struct /* DDC Control Register */
  {
    unsigned char M0 : 1;
    unsigned char SWHINT : 1;
    unsigned char DDC1EN : 1;
    unsigned char DDCINT : 1;
    unsigned char DDC_AX : 1;
    unsigned char SWENB : 1;
    unsigned char EX_DAT : 1;
    unsigned char  : 1;
  } DDCCON_bit;
} @ 0xD7;
__sfr __no_init volatile union
{
  unsigned char PCON; /* Power Ctrl */
  struct /* Power Ctrl */
  {
    unsigned char IDLE : 1;
    unsigned char PD : 1;
    unsigned char TCLK1 : 1;
    unsigned char RCLK1 : 1;
    unsigned char ADSFINT : 1;
    unsigned char LVREN : 1;
    unsigned char SMOD1 : 1;
    unsigned char SMOD : 1;
  } PCON_bit;
} @ 0x87;

/*-------------------------------------------------------------------------
 *   Timer
 *-------------------------------------------------------------------------*/

__sfr __no_init volatile unsigned char TL2 @ 0xCC; /* Timer 2 Low byte */
__sfr __no_init volatile union
{
  unsigned char T2MOD; /* Timer 2 Mode */
  struct /* Timer 2 Mode */
  {
    unsigned char DCEN : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
  } T2MOD_bit;
} @ 0xC9;
__sfr __no_init volatile unsigned char TH0 @ 0x8C; /* Timer 0 High */
__sfr __no_init volatile union
{
  unsigned char TCON; /* Timer / Cntr Control */
  struct /* Timer / Cntr Control */
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
__sfr __no_init volatile unsigned char TH2 @ 0xCD; /* Timer 2 High byte */
__sfr __no_init volatile unsigned char TH1 @ 0x8D; /* Timer 1 High */
__sfr __no_init volatile union
{
  unsigned char TMOD; /* Timer / Cntr Mode Control */
  struct /* Timer / Cntr Mode Control */
  {
    unsigned char M00 : 1;
    unsigned char M10 : 1;
    unsigned char C_T0 : 1;
    unsigned char Gate0 : 1;
    unsigned char M01 : 1;
    unsigned char M11 : 1;
    unsigned char C_T1 : 1;
    unsigned char Gate1 : 1;
  } TMOD_bit;
} @ 0x89;
__sfr __no_init volatile unsigned char RCAP2L @ 0xCA; /* Timer 2 Reload low */
__sfr __no_init volatile unsigned char RCAP2H @ 0xCB; /* Timer 2 Reload High */
__sfr __no_init volatile unsigned char TL0 @ 0x8A; /* Timer 0 Low */
__sfr __no_init volatile union
{
  unsigned char T2CON; /* Timer 2 Control */
  struct /* Timer 2 Control */
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
__sfr __no_init volatile unsigned char TL1 @ 0x8B; /* Timer 1 Low */

/*-------------------------------------------------------------------------
 *   Analog to Digital Converter (ADC)
 *-------------------------------------------------------------------------*/

__sfr __no_init volatile unsigned char ASCL @ 0x95; /* 8-bit Prescaler for ADC clock */
__sfr __no_init volatile union
{
  unsigned char ADAT; /* ADC Data Register */
  struct /* ADC Data Register */
  {
    unsigned char ADAT0 : 1;
    unsigned char ADAT1 : 1;
    unsigned char ADAT2 : 1;
    unsigned char ADAT3 : 1;
    unsigned char ADAT4 : 1;
    unsigned char ADAT5 : 1;
    unsigned char ADAT6 : 1;
    unsigned char ADAT7 : 1;
  } ADAT_bit;
} @ 0x96;
__sfr __no_init volatile union
{
  unsigned char ACON; /* ADC Control Register */
  struct /* ADC Control Register */
  {
    unsigned char ADSF : 1;
    unsigned char ADST : 1;
    unsigned char ADS0 : 1;
    unsigned char ADS1 : 1;
    unsigned char  : 1;
    unsigned char ADEN : 1;
    unsigned char  : 1;
    unsigned char  : 1;
  } ACON_bit;
} @ 0x97;
/*
 * Interrupt Vectors
 */
#line 694 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\iouPSD3254A.h"

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

#line 28 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\TypeCible.h"



//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
#line 14 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\ConversionKeilToIAR.h"




// *****************************************************************************
// DEFINITION DES  MODELES DE MEMOIRE
// *****************************************************************************






// *****************************************************************************
#line 100 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\ConversionKeilToIAR.h"
// *****************************************************************************

// *****************************************************************************

// Interruption activation






// Interruption priorite




// Interruption niveau activite.












 // #define ES0 IE_bit.ES
 // #define ES0 IE_bit.ES




#line 141 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\ConversionKeilToIAR.h"

#line 148 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\ConversionKeilToIAR.h"



#line 159 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\ConversionKeilToIAR.h"

#line 168 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\ConversionKeilToIAR.h"

#line 177 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\ConversionKeilToIAR.h"




// S2STA
#line 190 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\ConversionKeilToIAR.h"

// S2CON
#line 202 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\ConversionKeilToIAR.h"

//S1DAT DEFINE 0xDA /* Data Hold Register */
//S1ADR DEFINE 0xDB /* DDC I2C address */
//S2DAT DEFINE 0xDE /* Data Hold Register */





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
#line 25 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\CLI2CPort.h"
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\CLI2CBase.h"
// ************************** FICHIER: CLI2CBASE.H *****************************
//
// Fonctions de communication de base en I2C
//
// Application realisee avec IAR C++ 8.10
//
// AUTEUR : VINCENT CHOUINARD
// DATE CREATION : 2014/03/27 VERSION: 1.0
// DATE MODIFICATION: ****-**-**
//
// Description: Fonction d'acces aux I/O (Low level) du protocole I2C
//
// DESCRIPTION DES FONCTIONS
//
// CLI2CBase(void)       : Constructeur par defaut
// CLI2CBase(UC ucDelai) : Constructeur-initialisateur
// ~CLI2CBase(void)      : Destructeur
//
// void vI2CStart(void)  : Fonction d'initialisation I2C
// void vI2CStop(void)   : Fonction de cloturage I2C
//
// void vI2CEcrireBit(UC ucValeur) : Ecriture d'un bit sur le bus I2C
// UC ucI2CEcrireOctet(UC ucOctet) : Ecriture d'un octet sur le bus I2C
//
// UC ucI2CLireOctet(void): Lecture d'un bit sur le bus I2C
// UC ucI2CLireBit(void)  : Lecture d'un octet sur le bus I2C
//
// void vDelaisI2C(void)  : Delai de stabilisation du signal
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



#line 213 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\ConversionKeilToIAR.h"
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX

#line 17 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\_DeclarationGenerale.h"


#line 139 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\_DeclarationGenerale.h"
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
#line 32 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\CLI2CBase.h"







class CLI2CBase
{
public:
   CLI2CBase(void);
   CLI2CBase(UC ucDelai);
  ~CLI2CBase(void);

protected:
   void vI2CStart        (void);
   void vI2CStop         (void);
   UC   ucI2CEcrireOctet (UC ucOctet);
   UC   ucI2CLireOctet   (UC ucAck);

private:
   void vI2CEcrireBit    (UC ucValeur);
   UC   ucI2CLireBit     (void);
   void vDelaiI2C        (void);
   UC   ucDelaiI2C;
};

//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
#line 26 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\CLI2CPort.h"










class CLI2CPort : public CLI2CBase
{
public:
   CLI2CPort(void);
  ~CLI2CPort(void);

protected:
   UC   ucI2CLireDonnee (UC ucAdrBoitier, UC ucAdrRegistre);
   void vI2CLireDonnee  (UC ucAdrBoitier, USI uiAdrRegistre, UC ucTypeAdr,
                         UC *ucpRecevoirDonnee, UC ucNbrLectures);

   void vI2CEcrireDonnee(UC ucAdrBoitier, UC ucAdrRegistre,  UC ucDonnee);
   void vI2CEcrireDonnee(UC ucAdrBoitier, USI uiAdrRegistre, UC ucTypeAdr,
                         UC *ucpDonnee,   UC ucNbrEcritures);

private:
   UC ucAdrBoitier;
};

//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
#line 13 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\NomDuProjet.cpp"
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



#line 213 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\ConversionKeilToIAR.h"
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX

#line 17 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\_DeclarationGenerale.h"


#line 139 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\_DeclarationGenerale.h"
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
#line 14 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\NomDuProjet.cpp"
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\CLSPI.h"
//**********************  Fichier: CLSPI.h
//  Description : Fonctions necessaire pour communiquer en SPI.
//
// CLComSPI(void);                            Constructeur
// CLComSPI(UC ucVal);                        Constructeur initialisateur
// ~CLComSPI(void);                           Destructeur
// UC ucSPIEcire(UC ucValeur, UC ucMode);     Pour ecrire une donnee en SPI
// void vINorOUT(UC ucDirection);             Pour la direction des port du MCP23S08
//
//  Composition: aucune
//  Heritage : aucune
//
//  Programmeur: Vincent Chouinard
//  Cours: 247-636
//
//  Date: 22 Octobre 2014
//
//  Compilateur:  IAR 8.1
//
//  Modification:
//
//
//////////////////////////////////////////////////////////////////////////////



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
#line 28 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\CLSPI.h"
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\MCP2515.h"



#line 52 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\MCP2515.h"






























#line 97 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\MCP2515.h"















#line 120 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\MCP2515.h"

/* Registres permettant de contr�ler le module d'envoi � TX0 � */
#line 138 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\MCP2515.h"

/* Registres permettant de contr�ler le module de r�ception � RX0 � */
#line 29 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\CLSPI.h"
/////////////////////////////////////
#line 38 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\CLSPI.h"
/////////////////////////////////////


class CLSPI
{
public:
   CLSPI(void)    ;                          // Constructeur.
   CLSPI(UC ucVal);                          // Constructeur initialisateur.
  ~CLSPI(void)    ;                          // Destructeur.

   UC   Write     (UC ucValeur, UC ucMode);  // Pour ecrire une donnee 8  bit en SPI
   UI   Write16   (UI uiValeur, UC ucMode);  // Pour ecrire une donnee 16 bit en SPI
   UC   WriteMPC  (UC Data);                 // Pour envoyer une valeur hexa sur les IO du MPC
   UC   WritePOT  (UC Data);                 // Pour �crire sur un POT numerique
   UC   WriteDAC  (UC ucPin, int iData);     // Pour faire une conversion Digital to Numeric
   UC   ReadMPC   (void);                    // Pour lire la valeur hexa des IO du MPC
   UC   WriteMPC2514(UC NombreDonneesEnvoyer, UC Donnee1, UC Donnee2, UC Donnee3); 
   void Direction (UC Directions) ;          // Pour la direction des port du MCP23S08

protected:

private:
   void Delai(unsigned long Temps);
   
};


//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX

#line 15 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\NomDuProjet.cpp"
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\CLClavier.h"
// **************************Clavier.h
// Auteur:       Vincent Chouinard
// Date:         1 mai 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.1
//
// Description:  Fichier de definitions pour utiliser le clavier du uPSD
// *****************************************************************************
///////////////////////////////////////////////////////////////////////////////
//                     Infos relatives au montage du clavier sur le uPSD
// Utilise un 74HCC922
// 74HCC922      uPSD
//        A sur D0
//        B sur D1
//        C sur D2
//        D sur D3
//       OE sur CS1     (OutputEnable sur chip select 1)
//       DA sur INT0    (AataAvailible sur interrupt0)
///////////////////////////////////////////////////////////////////////////////

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
#line 24 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\CLClavier.h"
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\CLInOutBase.h"
// ************************** FICHIER: CLInOutBase.H  **************************
// Auteur:       Vincent Chouinard
// Date:         1 mai 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.1
//
// Description:  Fichier de definitions pour utiliser le clavier du uPSD
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



#line 213 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\ConversionKeilToIAR.h"
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX

#line 17 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\_DeclarationGenerale.h"


#line 139 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\_DeclarationGenerale.h"
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
#line 12 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\CLInOutBase.h"









class CLInOutBase
{
public:

protected:
   void vOut(USI uiAdresse, UC ucData);
   void vOut(USI uiAdresse, USI uiDonnee, UC ucTypeTransfert);

   UC   ucIn(USI uiAdresse);
   UC   ucIn(USI uiAdresse, UC ucTypeTransfert);

private:
   UC   ucInPort(USI uiAdresse);
   void vOutPort(USI uiAdresse, UC ucData);
};

//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX

#line 25 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\CLClavier.h"






class CLClavier : public CLInOutBase
{
public:
   CLClavier(void);                    // Constructeur par defaut.
  ~CLClavier(void);                    // Desctructeur.
 
   UC ucLireClavier(void) ;
   UC ucBoutonAppuye(void);            // Fonction de logique de selection du bouton pese

protected:
   UC        ucToucheClavier;
   static UC ucEtatClavier  ;

private:
   __interrupt static void vKeyboardInterrupt(void);
};

//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
#line 16 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\NomDuProjet.cpp"
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\CLEcran.h"
// ************************** FICHIER: CLEcran.H  ******************************

// DESCRIPTION DES FONCTIONS
//
// CLEcran(void);
// CLEcran(USI uiAdresse);
// ~CLEcran(void);
//
// void vLCDClr(void);
// void vLCDInit(void);
// void vLCDCursor(UC ucCol, UC ucLine);
//
// void Lettre(UC ucCaractere);
// void Lettre(char cCaractere);
//
// void String(const UC *ucpMessage);
// void String(const char *cpMessage);
//
// void vHexToASCII(UC ucHexCar, UC *ucpHi, UC *ucpLo);
// void vLCDDisplayHexCarac(UC ucHexCar);
//
// void vLCDDisplayScreen(const UC *ucpEcran);
// void vLCDBusy(void);
// void vDelaiLCD(USI uiDelai);
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



#line 213 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\ConversionKeilToIAR.h"
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX

#line 17 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\_DeclarationGenerale.h"


#line 139 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\_DeclarationGenerale.h"
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
#line 28 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\CLEcran.h"
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\CLInOutBase.h"
// ************************** FICHIER: CLInOutBase.H  **************************
// Auteur:       Vincent Chouinard
// Date:         1 mai 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.1
//
// Description:  Fichier de definitions pour utiliser le clavier du uPSD
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



#line 213 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\ConversionKeilToIAR.h"
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX

#line 17 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\_DeclarationGenerale.h"


#line 139 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\_DeclarationGenerale.h"
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
#line 12 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\CLInOutBase.h"

#line 37 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\CLInOutBase.h"
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX

#line 29 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\CLEcran.h"









class CLEcran : public CLInOutBase
{
public:
   CLEcran(void);
   CLEcran(USI uiAdresse);
  ~CLEcran(void);

   void vLCDClr              (void);
   void vLCDInit             (void);
   void vLCDCursor           (UC   ucCol, UC ucLine);
   void Lettre               (UC   ucCaractere);
   void Lettre               (char cCaractere);
   void String               (const UC   *ucpMessage);
   void String               (const char *cpMessage);   

   void vHexToASCII          (UC   ucHexCar,   UC *ucpHi,      UC *ucpLo);
   void vHexToASCII          (USI  uiHexCar,   UC *ucpHiOctHi, UC *ucpLoOctHi,
                              UC  *ucpHiOctLo, UC *ucpLoOctLo);

   void vLCDDisplayHexCarac  (UC          ucHexCar);
   void vLCDDisplayHexCarac  (USI         uiHexCar);
   void vLCDDisplayScreen    (const UC   *ucpEcran);
   void vLCDDisplayEtatPort  (UC          ucEtatPort);
   void vLCDDisplayFloat     (float       fInputFloat);

protected:    
                              
private:
   USI  uiAdresseEcran;
   void vLCDBusy (void);
   void vDelaiLCD(USI uiDelai);
};

//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
#line 17 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\NomDuProjet.cpp"
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\Timer0.h"
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
#line 12 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\Timer0.h"



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
#line 18 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\NomDuProjet.cpp"
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\Optik.h"
// **************************Fichier.h
// Auteur:       Vincent Chouinard
// Date:         20 juillet 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.1
//
// Description:
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



#line 213 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\ConversionKeilToIAR.h"
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX

#line 17 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\_DeclarationGenerale.h"


#line 139 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\_DeclarationGenerale.h"
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
#line 12 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\Optik.h"

//#include "CLCommunic.h"             //inclue RS232.h.









class Encodeur //: public RS232
{
public:
   Encodeur(void);            // ***Constructeur par defaut
   Encodeur(UC ucParametre);  // ***Constructeur initialisateur
  ~Encodeur(void);            // ***Destructeur
  
   char LogicAnalyser(void);
  
protected:

private:
  static char LastState;           // Pour connaitre l'etat de la trame

};

//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
#line 19 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\NomDuProjet.cpp"
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\CANBUS.h"
// **************************CANBUS.h
// Auteur:       Vincent Chouinard
// Date:         20 juillet 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.1
//
// Description:
// *****************************************************************************
/*
11 MOSI
12 MISO
13 SCK
10 CS 
*/

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
#line 19 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\CANBUS.h"
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\MCP2515.h"



#line 52 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\MCP2515.h"






























#line 97 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\MCP2515.h"















#line 120 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\MCP2515.h"

/* Registres permettant de contr�ler le module d'envoi � TX0 � */
#line 138 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\MCP2515.h"

/* Registres permettant de contr�ler le module de r�ception � RX0 � */
#line 21 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\CANBUS.h"

















class CanBus : public CLSPI
{
public:
   CanBus(void);            // ***Constructeur par defaut
   CanBus(UC ucParametre);  // ***Constructeur initialisateur
  ~CanBus(void);            // ***Destructeur
  
   void SendMCP2515(const UC *Message);
   void ChoisirIdentifiantTX0(int Identifiant); //

protected:

private:
   void MCP24515_init(void);
   void Delai(unsigned long Temps);
   UC   Longueur(const UC *Contenu);
   void EcrireRegistreMCP2515(UC Address, unsigned char Data);
   void AcquitterInterruptionsMCP2515(void);
};





//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
#line 20 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\NomDuProjet.cpp"
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\MCP2515.h"



#line 52 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\MCP2515.h"






























#line 97 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\MCP2515.h"















#line 120 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\MCP2515.h"

/* Registres permettant de contr�ler le module d'envoi � TX0 � */
#line 138 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\MCP2515.h"

/* Registres permettant de contr�ler le module de r�ception � RX0 � */
#line 21 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\NomDuProjet.cpp"
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\CLSortieLatch.h"
// **************************CLSortieLatch.h
// Auteur:       Vincent Chouinard
// Date:         20 juillet 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.1
//
// Description:
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



#line 213 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\ConversionKeilToIAR.h"
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX

#line 17 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\_DeclarationGenerale.h"


#line 139 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\_DeclarationGenerale.h"
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
#line 12 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\CLSortieLatch.h"
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\CLInOutBase.h"
// ************************** FICHIER: CLInOutBase.H  **************************
// Auteur:       Vincent Chouinard
// Date:         1 mai 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.1
//
// Description:  Fichier de definitions pour utiliser le clavier du uPSD
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



#line 213 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\ConversionKeilToIAR.h"
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX

#line 17 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\_DeclarationGenerale.h"


#line 139 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\_DeclarationGenerale.h"
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
#line 12 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\CLInOutBase.h"

#line 37 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\CLInOutBase.h"
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX

#line 13 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\CLSortieLatch.h"




class DAC_ADC : public CLInOutBase
{
public:
   DAC_ADC(void);            // ***Constructeur par defaut
   DAC_ADC(UC ucParametre);  // ***Constructeur initialisateur
  ~DAC_ADC(void);            // ***Destructeur
  
   void DAC(UC ucChannel, UC ucData); // Ecrire sur le convertisseur Digital to analog
   UC   ADC(UC ucChannel);            // Lire le convertisseur Analog to digital

protected:

private:

};

//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
#line 22 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\NomDuProjet.cpp"
//#include "CLCommunic.h"            // Pour utiliser le port s�rie du Dallas
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\CLCommunicUpsdPort1.h"
//**********************  Fichier: CLCommunic.h
//  Description : Fichier d'entete pour le fichier CLCommunic.cpp
//  
//  Composition: aucune
//  Heritage : aucun
//  Fonctions necessaire pour communiquer avec le port serie:
//
//CLCommunic()                                          Constructeur par defaut
//CLCommunic(UC ucLongBuf, UC ucLongTrame, UI uiBaud)  Construct initialisateur
//~CLCommunic()                                                     Destructeur 
//UC ucInitLongTrame(UC ucLong)                 Pour initialiser longueur trame
//UC static ucLireNbCaractRecu()         Fct pour lire nombre de caractere recu
//UC ucLireEtatTrame()                         Fct pour lire l'etat de la trame
//char *ucpLireTrame()                Fct qui retourne adresse du debut lecture
//vTransCaratere(UC ucCar)                    Fct pour transmettre un caractere
//vTransChiffre(UI uiChiffreAAfficher)          Fct pour transmettre un chiffre 
//vAffChaine(char const *ucpMessage)   Fct pour transmettre chaine de caractere
//void vInitBaudRate(UI uiBaud)        Fct pour intialiser le baudrate et timer
//__interrupt static void vInteruptSerial();     Fct pour recevoir un caractere
//UC ucValideTrame()                                 Fct pour valider une trame

//
//  Programmeur: Vincent Chouinard
//  Cours: 247-436
//                                                                           
//  Date: 10 avril 2014
//                                                                           //
//  Compilateur: IAR 8.1                                  
//                                                                           //
//  Modification:                                                            //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////



#line 1 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\stdio.h"
/* stdio.h standard header */
/* Copyright 2003-2010 IAR Systems AB.  */




  #pragma system_include


#line 1 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\ycheck.h"
/* ycheck.h internal checking header file. */
/* Copyright 2005-2010 IAR Systems AB. */

/* Note that there is no include guard for this header. This is intentional. */


  #pragma system_include


/* __INTRINSIC
 *
 * Note: Redefined each time ycheck.h is included, i.e. for each
 * system header, to ensure that intrinsic support could be turned off
 * individually for each file.
 */










/* __TAABI_PORTABILITY_INTERNAL_LEVEL
 *
 * Note: Redefined each time ycheck.h is included, i.e. for each
 * system header, to ensure that ABI support could be turned off/on
 * individually for each file.
 *
 * Possible values for this preprocessor symbol:
 *
 * 0 - ABI portability mode is disabled.
 *
 * 1 - ABI portability mode (version 1) is enabled.
 *
 * All other values are reserved for future use.
 */






#line 67 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\ycheck.h"









#line 11 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\stdio.h"
#line 1 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\yvals.h"
/* yvals.h internal configuration header file. */
/* Copyright 2001-2010 IAR Systems AB. */





  #pragma system_include


#line 1 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\ycheck.h"
/* ycheck.h internal checking header file. */
/* Copyright 2005-2010 IAR Systems AB. */

/* Note that there is no include guard for this header. This is intentional. */


  #pragma system_include


/* __INTRINSIC
 *
 * Note: Redefined each time ycheck.h is included, i.e. for each
 * system header, to ensure that intrinsic support could be turned off
 * individually for each file.
 */










/* __TAABI_PORTABILITY_INTERNAL_LEVEL
 *
 * Note: Redefined each time ycheck.h is included, i.e. for each
 * system header, to ensure that ABI support could be turned off/on
 * individually for each file.
 *
 * Possible values for this preprocessor symbol:
 *
 * 0 - ABI portability mode is disabled.
 *
 * 1 - ABI portability mode (version 1) is enabled.
 *
 * All other values are reserved for future use.
 */






#line 67 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\ycheck.h"

#line 12 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\yvals.h"

                /* Convenience macros */









                /* Versions */










/*
 * Support for some C99 or other symbols
 *
 * This setting makes available some macros, functions, etc that are
 * beneficial.
 *
 * Default is to include them.
 *
 * Disabling this in C++ mode will not compile (some C++ functions uses C99
 * functionality).
 */


  /* Default turned on when compiling C++, EC++, or C99. */
#line 56 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\yvals.h"






                /* Configuration */
#line 1 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\DLib_Defaults.h"
/***************************************************
 *
 * DLib_Defaults.h is the library configuration manager.
 *
 * Copyright 2003-2010 IAR Systems AB.  
 *
 * This configuration header file performs the following tasks:
 *
 * 1. Includes the configuration header file, defined by _DLIB_CONFIG_FILE,
 *    that sets up a particular runtime environment.
 *
 * 2. Includes the product configuration header file, DLib_Product.h, that
 *    specifies default values for the product and makes sure that the
 *    configuration is valid.
 *
 * 3. Sets up default values for all remaining configuration symbols.
 *
 * This configuration header file, the one defined by _DLIB_CONFIG_FILE, and
 * DLib_Product.h configures how the runtime environment should behave. This
 * includes all system headers and the library itself, i.e. all system headers
 * includes this configuration header file, and the library has been built
 * using this configuration header file.
 *
 ***************************************************
 *
 * DO NOT MODIFY THIS FILE!
 *
 ***************************************************/





  #pragma system_include


/* Include the main configuration header file. */
#line 1 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\LIB\\DLIB\\dl8051Normal.h"
/* Customer-specific DLib configuration. */
/* Copyright (C) 2003 IAR Systems.  All rights reserved. */





  #pragma system_include


/* No changes to the defaults. */

#line 40 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\DLib_Defaults.h"
  /* _DLIB_CONFIG_FILE_STRING is the quoted variant of above */
#line 47 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\DLib_Defaults.h"

/* Include the product specific header file. */
#line 1 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\DLib_Product.h"
/* ICC8051 DLib configuration.                                */
/* Copyright (C) 2003-2011 IAR Systems.  All rights reserved. */










#line 19 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\DLib_Product.h"

#line 27 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\DLib_Product.h"

/* 8051 is to be considered as a small target */




#line 51 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\DLib_Defaults.h"



/*
 * The remainder of the file sets up defaults for a number of
 * configuration symbols, each corresponds to a feature in the
 * libary.
 *
 * The value of the symbols should either be 1, if the feature should
 * be supported, or 0 if it shouldn't. (Except where otherwise
 * noted.)
 */


/*
 * Small or Large target
 *
 * This define determines whether the target is large or small. It must be 
 * setup in the DLib_Product header or in the compiler itself.
 *
 * For a small target some functionality in the library will not deliver 
 * the best available results. For instance sin, tan, and powXp will not use
 * the extra precision packet for large arguments.
 * 
 * The VLA settings are by default determined from this as well. 
 *
 */







/*
 * File handling
 *
 * Determines whether FILE descriptors and related functions exists or not.
 * When this feature is selected, i.e. set to 1, then FILE descriptors and
 * related functions (e.g. fprintf, fopen) exist. All files, even stdin,
 * stdout, and stderr will then be handled with a file system mechanism that
 * buffers files before accessing the lowlevel I/O interface (__open, __read,
 * __write, etc).
 *
 * If not selected, i.e. set to 0, then FILE descriptors and related functions
 * (e.g. fprintf, fopen) does not exist. All functions that normally uses
 * stderr will use stdout instead. Functions that uses stdout and stdin (like
 * printf and scanf) will access the lowlevel I/O interface directly (__open,
 * __read, __write, etc), i.e. there will not be any buffering.
 *
 * The default is not to have support for FILE descriptors.
 */





/*
 * Use static buffers for stdout
 *
 * This setting controls whether the stream stdout uses a static 80 bytes
 * buffer or uses a one byte buffer allocated in the file descriptor. This
 * setting is only applicable if the FILE descriptors are enabled above.
 *
 * Default is to use a static 80 byte buffer.
 */





/*
 * Support of locale interface
 *
 * "Locale" is the system in C that support language- and
 * contry-specific settings for a number of areas, including currency
 * symbols, date and time, and multibyte encodings.
 *
 * This setting determines whether the locale interface exist or not.
 * When this feature is selected, i.e. set to 1, the locale interface exist
 * (setlocale, etc). A number of preselected locales can be activated during
 * runtime. The preselected locales and encodings is choosen by defining any
 * number of _LOCALE_USE_xxx and _ENCODING_USE_xxx symbols. The application
 * will start with the "C" locale choosen. (Single byte encoding is always
 * supported in this mode.)
 *
 *
 * If not selected, i.e. set to 0, the locale interface (setlocale, etc) does
 * not exist. One preselected locale and one preselected encoding is then used
 * directly. That locale can not be changed during runtime. The preselected
 * locale and encoding is choosen by defining at most one of _LOCALE_USE_xxx
 * and at most one of _ENCODING_USE_xxx. The default is to use the "C" locale
 * and the single byte encoding, respectively.
 *
 * The default is not to have support for the locale interface with the "C"
 * locale and the single byte encoding.
 *
 * Supported locales
 * -----------------
 * _LOCALE_USE_C                  C standard locale (the default)
 * _LOCALE_USE_POSIX ISO-8859-1   Posix locale
 * _LOCALE_USE_CS_CZ ISO-8859-2   Czech language locale for Czech Republic
 * _LOCALE_USE_DA_DK ISO-8859-1   Danish language locale for Denmark
 * _LOCALE_USE_DA_EU ISO-8859-15  Danish language locale for Europe
 * _LOCALE_USE_DE_AT ISO-8859-1   German language locale for Austria
 * _LOCALE_USE_DE_BE ISO-8859-1   German language locale for Belgium
 * _LOCALE_USE_DE_CH ISO-8859-1   German language locale for Switzerland
 * _LOCALE_USE_DE_DE ISO-8859-1   German language locale for Germany
 * _LOCALE_USE_DE_EU ISO-8859-15  German language locale for Europe
 * _LOCALE_USE_DE_LU ISO-8859-1   German language locale for Luxemburg
 * _LOCALE_USE_EL_EU ISO-8859-7x  Greek language locale for Europe
 *                                (Euro symbol added)
 * _LOCALE_USE_EL_GR ISO-8859-7   Greek language locale for Greece
 * _LOCALE_USE_EN_AU ISO-8859-1   English language locale for Australia
 * _LOCALE_USE_EN_CA ISO-8859-1   English language locale for Canada
 * _LOCALE_USE_EN_DK ISO_8859-1   English language locale for Denmark
 * _LOCALE_USE_EN_EU ISO-8859-15  English language locale for Europe
 * _LOCALE_USE_EN_GB ISO-8859-1   English language locale for United Kingdom
 * _LOCALE_USE_EN_IE ISO-8859-1   English language locale for Ireland
 * _LOCALE_USE_EN_NZ ISO-8859-1   English language locale for New Zealand
 * _LOCALE_USE_EN_US ISO-8859-1   English language locale for USA
 * _LOCALE_USE_ES_AR ISO-8859-1   Spanish language locale for Argentina
 * _LOCALE_USE_ES_BO ISO-8859-1   Spanish language locale for Bolivia
 * _LOCALE_USE_ES_CL ISO-8859-1   Spanish language locale for Chile
 * _LOCALE_USE_ES_CO ISO-8859-1   Spanish language locale for Colombia
 * _LOCALE_USE_ES_DO ISO-8859-1   Spanish language locale for Dominican Republic
 * _LOCALE_USE_ES_EC ISO-8859-1   Spanish language locale for Equador
 * _LOCALE_USE_ES_ES ISO-8859-1   Spanish language locale for Spain
 * _LOCALE_USE_ES_EU ISO-8859-15  Spanish language locale for Europe
 * _LOCALE_USE_ES_GT ISO-8859-1   Spanish language locale for Guatemala
 * _LOCALE_USE_ES_HN ISO-8859-1   Spanish language locale for Honduras
 * _LOCALE_USE_ES_MX ISO-8859-1   Spanish language locale for Mexico
 * _LOCALE_USE_ES_PA ISO-8859-1   Spanish language locale for Panama
 * _LOCALE_USE_ES_PE ISO-8859-1   Spanish language locale for Peru
 * _LOCALE_USE_ES_PY ISO-8859-1   Spanish language locale for Paraguay
 * _LOCALE_USE_ES_SV ISO-8859-1   Spanish language locale for Salvador
 * _LOCALE_USE_ES_US ISO-8859-1   Spanish language locale for USA
 * _LOCALE_USE_ES_UY ISO-8859-1   Spanish language locale for Uruguay
 * _LOCALE_USE_ES_VE ISO-8859-1   Spanish language locale for Venezuela
 * _LOCALE_USE_ET_EE ISO-8859-1   Estonian language for Estonia
 * _LOCALE_USE_EU_ES ISO-8859-1   Basque language locale for Spain
 * _LOCALE_USE_FI_EU ISO-8859-15  Finnish language locale for Europe
 * _LOCALE_USE_FI_FI ISO-8859-1   Finnish language locale for Finland
 * _LOCALE_USE_FO_FO ISO-8859-1   Faroese language locale for Faroe Islands
 * _LOCALE_USE_FR_BE ISO-8859-1   French language locale for Belgium
 * _LOCALE_USE_FR_CA ISO-8859-1   French language locale for Canada
 * _LOCALE_USE_FR_CH ISO-8859-1   French language locale for Switzerland
 * _LOCALE_USE_FR_EU ISO-8859-15  French language locale for Europe
 * _LOCALE_USE_FR_FR ISO-8859-1   French language locale for France
 * _LOCALE_USE_FR_LU ISO-8859-1   French language locale for Luxemburg
 * _LOCALE_USE_GA_EU ISO-8859-15  Irish language locale for Europe
 * _LOCALE_USE_GA_IE ISO-8859-1   Irish language locale for Ireland
 * _LOCALE_USE_GL_ES ISO-8859-1   Galician language locale for Spain
 * _LOCALE_USE_HR_HR ISO-8859-2   Croatian language locale for Croatia
 * _LOCALE_USE_HU_HU ISO-8859-2   Hungarian language locale for Hungary
 * _LOCALE_USE_ID_ID ISO-8859-1   Indonesian language locale for Indonesia
 * _LOCALE_USE_IS_EU ISO-8859-15  Icelandic language locale for Europe
 * _LOCALE_USE_IS_IS ISO-8859-1   Icelandic language locale for Iceland
 * _LOCALE_USE_IT_EU ISO-8859-15  Italian language locale for Europe
 * _LOCALE_USE_IT_IT ISO-8859-1   Italian language locale for Italy
 * _LOCALE_USE_IW_IL ISO-8859-8   Hebrew language locale for Israel
 * _LOCALE_USE_KL_GL ISO-8859-1   Greenlandic language locale for Greenland
 * _LOCALE_USE_LT_LT   BALTIC     Lithuanian languagelocale for Lithuania
 * _LOCALE_USE_LV_LV   BALTIC     Latvian languagelocale for Latvia
 * _LOCALE_USE_NL_BE ISO-8859-1   Dutch language locale for Belgium
 * _LOCALE_USE_NL_EU ISO-8859-15  Dutch language locale for Europe
 * _LOCALE_USE_NL_NL ISO-8859-9   Dutch language locale for Netherlands
 * _LOCALE_USE_NO_EU ISO-8859-15  Norwegian language locale for Europe
 * _LOCALE_USE_NO_NO ISO-8859-1   Norwegian language locale for Norway
 * _LOCALE_USE_PL_PL ISO-8859-2   Polish language locale for Poland
 * _LOCALE_USE_PT_BR ISO-8859-1   Portugese language locale for Brazil
 * _LOCALE_USE_PT_EU ISO-8859-15  Portugese language locale for Europe
 * _LOCALE_USE_PT_PT ISO-8859-1   Portugese language locale for Portugal
 * _LOCALE_USE_RO_RO ISO-8859-2   Romanian language locale for Romania
 * _LOCALE_USE_RU_RU ISO-8859-5   Russian language locale for Russia
 * _LOCALE_USE_SL_SI ISO-8859-2   Slovenian language locale for Slovenia
 * _LOCALE_USE_SV_EU ISO-8859-15  Swedish language locale for Europe
 * _LOCALE_USE_SV_FI ISO-8859-1   Swedish language locale for Finland
 * _LOCALE_USE_SV_SE ISO-8859-1   Swedish language locale for Sweden
 * _LOCALE_USE_TR_TR ISO-8859-9   Turkish language locale for Turkey
 *
 *  Supported encodings
 *  -------------------
 * n/a                            Single byte (used if no other is defined).
 * _ENCODING_USE_UTF8             UTF8 encoding.
 */





/* We need to have the "C" locale if we have full locale support. */





/*
 * Support of multibytes in printf- and scanf-like functions
 *
 * This is the default value for _DLIB_PRINTF_MULTIBYTE and
 * _DLIB_SCANF_MULTIBYTE. See them for a description.
 *
 * Default is to not have support for multibytes in printf- and scanf-like
 * functions.
 */






/*
 * Throw handling in the EC++ library
 *
 * This setting determines what happens when the EC++ part of the library
 * fails (where a normal C++ library 'throws').
 *
 * The following alternatives exists (setting of the symbol):
 * 0                - The application does nothing, i.e. continues with the
 *                    next statement.
 * 1                - The application terminates by calling the 'abort'
 *                    function directly.
 * <anything else>  - An object of class "exception" is created.  This
 *                    object contains a string describing the problem.
 *                    This string is later emitted on "stderr" before
 *                    the application terminates by calling the 'abort'
 *                    function directly.
 *
 * Default is to do nothing.
 */






/*
 * Handling of floating-point environment
 *
 * If selected, i.e. set to 1, then the floating-point environment, defined in
 * the header file fenv.h, is updated when a floating-point operation produces
 * an exception (overflow, etc). Note that not all products support this.
 *
 * If not selected, i.e. set to 0, then the floating-point environment is not
 * updated.
 *
 * Default is to not update the floating-point environment.
 */






/*
 * Hexadecimal floating-point numbers in strtod
 *
 * If selected, i.e. set to 1, strtod supports C99 hexadecimal floating-point
 * numbers. This also enables hexadecimal floating-points in internal functions
 * used for converting strings and wide strings to float, double, and long
 * double.
 *
 * If not selected, i.e. set to 0, C99 hexadecimal floating-point numbers
 * aren't supported.
 *
 * Default is not to support hexadecimal floating-point numbers.
 */






/*
 * Printf configuration symbols.
 *
 * All the configuration symbols described further on controls the behaviour
 * of printf, sprintf, and the other printf variants.
 *
 * The library proves four formatters for printf: 'tiny', 'small',
 * 'large', and 'default'.  The setup in this file controls all except
 * 'tiny'.  Note that both small' and 'large' explicitly removes
 * some features.
 */

/*
 * Handle multibytes in printf
 *
 * This setting controls whether multibytes and wchar_ts are supported in
 * printf. Set to 1 to support them, otherwise set to 0.
 *
 * See _DLIB_FORMATTED_MULTIBYTE for the default setting.
 */





/*
 * Long long formatting in printf
 *
 * This setting controls long long support (%lld) in printf. Set to 1 to
 * support it, otherwise set to 0.

 * Note, if long long should not be supported and 'intmax_t' is larger than
 * an ordinary 'long', then %jd and %jn will not be supported.
 *
 * Default is to support long long formatting.
 */

#line 369 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\DLib_Defaults.h"






/*
 * Floating-point formatting in printf
 *
 * This setting controls whether printf supports floating-point formatting.
 * Set to 1 to support them, otherwise set to 0.
 *
 * Default is to support floating-point formatting.
 */





/*
 * Hexadecimal floating-point formatting in printf
 *
 * This setting controls whether the %a format, i.e. the output of
 * floating-point numbers in the C99 hexadecimal format. Set to 1 to support
 * it, otherwise set to 0.
 *
 * Default is to support %a in printf.
 */





/*
 * Output count formatting in printf
 *
 * This setting controls whether the output count specifier (%n) is supported
 * or not in printf. Set to 1 to support it, otherwise set to 0.
 *
 * Default is to support %n in printf.
 */





/*
 * Support of qualifiers in printf
 *
 * This setting controls whether qualifiers that enlarges the input value
 * [hlLjtz] is supported in printf or not. Set to 1 to support them, otherwise
 * set to 0. See also _DLIB_PRINTF_INT_TYPE_IS_INT and
 * _DLIB_PRINTF_INT_TYPE_IS_LONG.
 *
 * Default is to support [hlLjtz] qualifiers in printf.
 */





/*
 * Support of flags in printf
 *
 * This setting controls whether flags (-+ #0) is supported in printf or not.
 * Set to 1 to support them, otherwise set to 0.
 *
 * Default is to support flags in printf.
 */





/*
 * Support widths and precisions in printf
 *
 * This setting controls whether widths and precisions are supported in printf.
 * Set to 1 to support them, otherwise set to 0.
 *
 * Default is to support widths and precisions in printf.
 */





/*
 * Support of unsigned integer formatting in printf
 *
 * This setting controls whether unsigned integer formatting is supported in
 * printf. Set to 1 to support it, otherwise set to 0.
 *
 * Default is to support unsigned integer formatting in printf.
 */





/*
 * Support of signed integer formatting in printf
 *
 * This setting controls whether signed integer formatting is supported in
 * printf. Set to 1 to support it, otherwise set to 0.
 *
 * Default is to support signed integer formatting in printf.
 */





/*
 * Support of formatting anything larger than int in printf
 *
 * This setting controls if 'int' should be used internally in printf, rather
 * than the largest existing integer type. If 'int' is used, any integer or
 * pointer type formatting use 'int' as internal type even though the
 * formatted type is larger. Set to 1 to use 'int' as internal type, otherwise
 * set to 0.
 *
 * See also next configuration.
 *
 * Default is to internally use largest existing internally type.
 */





/*
 * Support of formatting anything larger than long in printf
 *
 * This setting controls if 'long' should be used internally in printf, rather
 * than the largest existing integer type. If 'long' is used, any integer or
 * pointer type formatting use 'long' as internal type even though the
 * formatted type is larger. Set to 1 to use 'long' as internal type,
 * otherwise set to 0.
 *
 * See also previous configuration.
 *
 * Default is to internally use largest existing internally type.
 */









/*
 * Emit a char a time in printf
 *
 * This setting controls internal output handling. If selected, i.e. set to 1,
 * then printf emits one character at a time, which requires less code but
 * can be slightly slower for some types of output.
 *
 * If not selected, i.e. set to 0, then printf buffers some outputs.
 *
 * Note that it is recommended to either use full file support (see
 * _DLIB_FILE_DESCRIPTOR) or -- for debug output -- use the linker
 * option "-e__write_buffered=__write" to enable buffered I/O rather
 * than deselecting this feature.
 */






/*
 * Scanf configuration symbols.
 *
 * All the configuration symbols described here controls the
 * behaviour of scanf, sscanf, and the other scanf variants.
 *
 * The library proves three formatters for scanf: 'small', 'large',
 * and 'default'.  The setup in this file controls all, however both
 * 'small' and 'large' explicitly removes some features.
 */

/*
 * Handle multibytes in scanf
 *
 * This setting controls whether multibytes and wchar_t:s are supported in
 * scanf. Set to 1 to support them, otherwise set to 0.
 *
 * See _DLIB_FORMATTED_MULTIBYTE for the default.
 */





/*
 * Long long formatting in scanf
 *
 * This setting controls whether scanf supports long long support (%lld). It
 * also controls, if 'intmax_t' is larger than an ordinary 'long', i.e. how
 * the %jd and %jn specifiers behaves. Set to 1 to support them, otherwise set
 * to 0.
 *
 * Default is to support long long formatting in scanf.
 */

#line 584 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\DLib_Defaults.h"





/*
 * Support widths in scanf
 *
 * This controls whether scanf supports widths. Set to 1 to support them,
 * otherwise set to 0.
 *
 * Default is to support widths in scanf.
 */





/*
 * Support qualifiers [hjltzL] in scanf
 *
 * This setting controls whether scanf supports qualifiers [hjltzL] or not. Set
 * to 1 to support them, otherwise set to 0.
 *
 * Default is to support qualifiers in scanf.
 */





/*
 * Support floating-point formatting in scanf
 *
 * This setting controls whether scanf supports floating-point formatting. Set
 * to 1 to support them, otherwise set to 0.
 *
 * Default is to support floating-point formatting in scanf.
 */





/*
 * Support output count formatting (%n)
 *
 * This setting controls whether scanf supports output count formatting (%n).
 * Set to 1 to support it, otherwise set to 0.
 *
 * Default is to support output count formatting in scanf.
 */





/*
 * Support scansets ([]) in scanf
 *
 * This setting controls whether scanf supports scansets ([]) or not. Set to 1
 * to support them, otherwise set to 0.
 *
 * Default is to support scansets in scanf.
 */





/*
 * Support signed integer formatting in scanf
 *
 * This setting controls whether scanf supports signed integer formatting or
 * not. Set to 1 to support them, otherwise set to 0.
 *
 * Default is to support signed integer formatting in scanf.
 */





/*
 * Support unsigned integer formatting in scanf
 *
 * This setting controls whether scanf supports unsigned integer formatting or
 * not. Set to 1 to support them, otherwise set to 0.
 *
 * Default is to support unsigned integer formatting in scanf.
 */





/*
 * Support assignment suppressing [*] in scanf
 *
 * This setting controls whether scanf supports assignment suppressing [*] or
 * not. Set to 1 to support them, otherwise set to 0.
 *
 * Default is to support assignment suppressing in scanf.
 */





/*
 * Handle multibytes in asctime and strftime.
 *
 * This setting controls whether multibytes and wchar_ts are
 * supported.Set to 1 to support them, otherwise set to 0.
 *
 * See _DLIB_FORMATTED_MULTIBYTE for the default setting.
 */





/*
 * True if "qsort" should be implemented using bubble sort.
 *
 * Bubble sort is less efficient than quick sort but requires less RAM
 * and ROM resources.
 */





/*
 * Set Buffert size used in qsort
 */





/*
 * The default "rand" function uses an array of 32 long:s of memory to
 * store the current state.
 *
 * The simple "rand" function uses only a single long. However, the
 * quality of the generated psuedo-random numbers are not as good as
 * the default implementation.
 */





/*
 * Wide character and multi byte character support in library.
 */





/*
 * Set attributes on the function used by the C-SPY debug interface to set a
 * breakpoint in.
 */





/*
 * Support threading in the library
 *
 * 0    No thread support
 * 1    Thread support with a, b, and d.
 * 2    Thread support with a, b, and e.
 * 3    Thread support with all thread-local storage in a dynamically allocated
 *        memory area and a, and b.
 *      a. Lock on heap accesses
 *      b. Optional lock on file accesses (see _DLIB_FILE_OP_LOCKS below)
 *      d. Use an external thread-local storage interface for all the
 *         libraries static and global variables.
 *      e. Static and global variables aren't safe for access from several
 *         threads.
 *
 * Note that if locks are used the following symbols must be defined:
 *   _DLIB_THREAD_LOCK_ONCE_TYPE
 *   _DLIB_THREAD_LOCK_ONCE_MACRO(control_variable, init_function)
 *   _DLIB_THREAD_LOCK_ONCE_TYPE_INIT
 * They will be used to initialize the needed locks only once. TYPE is the
 * type for the static control variable, MACRO is the expression that will be
 * evaluated at each usage of a lock, and INIT is the initializer for the
 * control variable.
 *
 * Note that if thread model 3 is used the symbol _DLIB_TLS_POINTER must be
 * defined. It is a thread local pointer to a dynamic memory area that
 * contains all used TLS variables for the library. Optionally these two
 * symbols must be defined as well (default is to use the default const data
 * and data memories):
 *   _DLIB_TLS_INITIALIZER_MEMORY which memory to place the initializers for the
 *                                TLS memory area
 *   _DLIB_TLS_MEMORY             which memory to use for the TLS memory area
 *
 *
 * See DLib_Threads.h for a description of what interfaces needs to be
 * defined for thread support.
 *
 */





/*
 * Used by products where one runtime library can be used by applications
 * with different data models, in order to reduce the total number of
 * libraries required. Typically, this is used when the pointer types does
 * not change over the data models used, but the placement of data variables
 * or/and constant variables do.
 *
 * If defined, this symbol is typically defined to the memory attribute that
 * is used by the runtime library. The actual define must use a
 * _Pragma("type_attribute = xxx") construct. In the header files, it is used
 * on all statically linked data objects seen by the application.
 */




#line 821 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\DLib_Defaults.h"


/*
 * Turn on support for the Target-specific ABI. The ABI is based on the
 * ARM AEABI. A target, except ARM, may deviate from it.
 */

#line 835 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\DLib_Defaults.h"

#line 866 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\DLib_Defaults.h"


/*
 * Turn on usage of a pragma to tell the linker the number of elements used
 * in a setjmp jmp_buf.
 */





/*
 * If true, the product supplies a "DLib_Product_string.h" file that
 * is included from "string.h".
 */





/*
 * Determine whether the math fma routines are fast or not.
 */




/*
 * Rtti support.
 */

#line 908 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\DLib_Defaults.h"

/*
 * Use the "pointers to short" or "pointers to long" implementation of 
 * the basic floating point routines (like Dnorm, Dtest, Dscale, and Dunscale).
 */




/*
 * Use 64-bit long long as intermediary type in Dtest, and fabs.
 * Default is to do this if long long is 64-bits.
 */




/*
 * Include dlmalloc as an alternative heap manager in product.
 *
 * Typically, an application will use a "malloc" heap manager that is
 * relatively small but not that efficient. An application can
 * optionally use the "dlmalloc" package, which provides a more
 * effective "malloc" heap manager, if it is included in the product
 * and supported by the settings.
 *
 * See the product documentation on how to use it, and whether or not
 * it is included in the product.
 */

  /* size_t/ptrdiff_t must be a 4 bytes unsigned integer. */
#line 945 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\DLib_Defaults.h"





/*
 * Allow the 64-bit time_t interface?
 *
 * Default is yes if long long is 64 bits.
 */

  #pragma language = save 
  #pragma language = extended





  #pragma language = restore






/*
 * Is time_t 64 or 32 bits?
 *
 * Default is 32 bits.
 */








#line 64 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\yvals.h"











                /* Floating-point */

/*
 * Whenever a floating-point type is equal to another, we try to fold those
 * two types into one. This means that if float == double then we fold float to
 * use double internally. Example sinf(float) will use _Sin(double, uint).
 *
 * _X_FNAME is a redirector for internal support routines. The X can be
 *          D (double), F (float), or L (long double). It redirects by using
 *          another prefix. Example calls to Dtest will be __iar_Dtest,
 *          __iar_FDtest, or __iarLDtest.
 * _X_FUN   is a redirector for functions visible to the customer. As above, the
 *          X can be D, F, or L. It redirects by using another suffix. Example
 *          calls to sin will be sin, sinf, or sinl.
 * _X_PTRCAST is a redirector for a cast operation involving a pointer.
 * _X_CAST  is a redirector for a cast involving the float type.
 *
 * _FLOAT_IS_DOUBLE signals that all internal float routines aren't needed.
 * _LONG_DOUBLE_IS_DOUBLE signals that all internal long double routines
 *                        aren't needed.
 */
#line 131 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\yvals.h"




                /* NAMING PROPERTIES */


/* Has support for fixed point types */




/* Has support for secure functions (printf_s, scanf_s, etc) */
/* Will not compile if enabled */
#line 153 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\yvals.h"

/* Has support for complex C types */




/* If is Embedded C++ language */






/* If is true C++ language */






/* True C++ language setup */
#line 219 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\yvals.h"











                /* NAMESPACE CONTROL */
#line 257 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\yvals.h"










  /* C has extern "C" linkage */
#line 290 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\yvals.h"


  
  typedef bool _Bool;
  



#line 304 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\yvals.h"

#line 1 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\xencoding_limits.h"
/* xencoding_limits.h internal header file */
/* Copyright 2003-2010 IAR Systems AB.  */





  #pragma system_include


#line 1 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\ycheck.h"
/* ycheck.h internal checking header file. */
/* Copyright 2005-2010 IAR Systems AB. */

/* Note that there is no include guard for this header. This is intentional. */


  #pragma system_include


/* __INTRINSIC
 *
 * Note: Redefined each time ycheck.h is included, i.e. for each
 * system header, to ensure that intrinsic support could be turned off
 * individually for each file.
 */










/* __TAABI_PORTABILITY_INTERNAL_LEVEL
 *
 * Note: Redefined each time ycheck.h is included, i.e. for each
 * system header, to ensure that ABI support could be turned off/on
 * individually for each file.
 *
 * Possible values for this preprocessor symbol:
 *
 * 0 - ABI portability mode is disabled.
 *
 * 1 - ABI portability mode (version 1) is enabled.
 *
 * All other values are reserved for future use.
 */






#line 67 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\ycheck.h"

#line 12 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\xencoding_limits.h"
#line 1 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\yvals.h"
/* yvals.h internal configuration header file. */
/* Copyright 2001-2010 IAR Systems AB. */

#line 614 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\yvals.h"

/*
 * Copyright (c) 1992-2009 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
V5.04:0576 */
#line 13 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\xencoding_limits.h"

                                /* Multibyte encoding length. */


#line 24 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\xencoding_limits.h"


#line 40 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\xencoding_limits.h"

                                /* Utility macro */












#line 306 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\yvals.h"



                /* FLOATING-POINT PROPERTIES */

                /* float properties */
#line 324 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\yvals.h"

                /* double properties */
#line 343 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\yvals.h"

                /* long double properties */
                /* (must be same as double) */





#line 366 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\yvals.h"


                /* INTEGER PROPERTIES */

                                /* MB_LEN_MAX */







  #pragma language=save
  #pragma language=extended
  typedef long long _Longlong;
  typedef unsigned long long _ULonglong;
  #pragma language=restore
#line 389 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\yvals.h"



  typedef wchar_t _Wchart;
  typedef wchar_t _Wintt;





#line 408 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\yvals.h"

#line 416 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\yvals.h"

                /* POINTER PROPERTIES */


typedef signed int  _Ptrdifft;
typedef unsigned int     _Sizet;

/* IAR doesn't support restrict  */


                /* stdarg PROPERTIES */





  typedef struct
  {
    char  *_Ap;
  } __Va_list;




extern "C" {
__intrinsic __nounwind void __iar_Atexit(void (*)(void));
}

#line 454 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\yvals.h"
  typedef struct
  {       /* state of a multibyte translation */
    unsigned long _Wchar;      /* Used as an intermediary value (up to 32-bits) */
    unsigned long _State;      /* Used as a state value (only some bits used) */
  } _Mbstatet;







typedef struct
{       /* file position */



  long _Off;    /* can be system dependent */

  _Mbstatet _Wstate;
} _Fpost;







                /* THREAD AND LOCALE CONTROL */

#line 1 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\DLib_Threads.h"
/***************************************************
 *
 * DLib_Threads.h is the library threads manager.
 *
 * Copyright 2004-2010 IAR Systems AB.  
 *
 * This configuration header file sets up how the thread support in the library
 * should work.
 *
 ***************************************************
 *
 * DO NOT MODIFY THIS FILE!
 *
 ***************************************************/





  #pragma system_include


/*
 * DLib can support a multithreaded environment. The preprocessor symbol 
 * _DLIB_THREAD_SUPPORT governs the support. It can be 0 (no support), 
 * 1 (currently not supported), 2 (locks only), and 3 (simulated TLS and locks).
 */

/*
 * This header sets the following symbols that governs the rest of the
 * library:
 * ------------------------------------------
 * _DLIB_MULTI_THREAD     0 No thread support
 *                        1 Multithread support
 * _DLIB_GLOBAL_VARIABLES 0 Use external TLS interface for the libraries global
 *                          and static variables
 *                        1 Use a lock for accesses to the locale and no 
 *                          security for accesses to other global and static
 *                          variables in the library
 * _DLIB_FILE_OP_LOCKS    0 No file-atomic locks
 *                        1 File-atomic locks

 * _DLIB_COMPILER_TLS     0 No Thread-Local-Storage support in the compiler
 *                        1 Thread-Local-Storage support in the compiler
 * _DLIB_TLS_QUAL         The TLS qualifier, define only if _COMPILER_TLS == 1
 *
 * _DLIB_THREAD_MACRO_SETUP_DONE Whether to use the standard definitions of
 *                               TLS macros defined in xtls.h or the definitions
 *                               are provided here.
 *                        0 Use default macros
 *                        1 Macros defined for xtls.h
 *
 * _DLIB_THREAD_LOCK_ONCE_TYPE
 *                        type for control variable in once-initialization of 
 *                        locks
 * _DLIB_THREAD_LOCK_ONCE_MACRO(control_variable, init_function)
 *                        expression that will be evaluated at each lock access
 *                        to determine if an initialization must be done
 * _DLIB_THREAD_LOCK_ONCE_TYPE_INIT
 *                        initial value for the control variable
 *
 ****************************************************************************
 * Description
 * -----------
 *
 * If locks are to be used (_DLIB_MULTI_THREAD != 0), the following lock 
 * interface must be overridden (the default in the library is for the 
 * interface implementation to do nothing): 
 *
 *   typedef void *__iar_Rmtx;                   // Lock info object
 *
 *   void __iar_system_Mtxinit(__iar_Rmtx *);    // Initialize a system lock
 *   void __iar_system_Mtxdst(__iar_Rmtx *);     // Destroy a system lock
 *   void __iar_system_Mtxlock(__iar_Rmtx *);    // Lock a system lock
 *   void __iar_system_Mtxunlock(__iar_Rmtx *);  // Unlock a system lock
 * The interface handles locks for the heap, the locale, the file system
 * structure, the initialization of statics in functions, etc. 
 *
 * The following lock interface is optional to be overridden (the default in 
 * the library is for the interface implementation to do nothing):
 *   void __iar_file_Mtxinit(__iar_Rmtx *);    // Initialize a file lock
 *   void __iar_file_Mtxdst(__iar_Rmtx *);     // Destroy a file lock
 *   void __iar_file_Mtxlock(__iar_Rmtx *);    // Lock a file lock
 *   void __iar_file_Mtxunlock(__iar_Rmtx *);  // Unlock a file lock
 * The interface handles locks for each file stream.
 * 
 * These three once-initialization symbols must also be defined, if the 
 * default initialization later on in this file doesn't work (done in 
 * DLib_product.h):
 *
 *   _DLIB_THREAD_LOCK_ONCE_TYPE
 *   _DLIB_THREAD_LOCK_ONCE_MACRO(control_variable, init_function)
 *   _DLIB_THREAD_LOCK_ONCE_TYPE_INIT
 *
 * If an external TLS interface is used, the following must
 * be defined:
 *   typedef int __iar_Tlskey_t;
 *   typedef void (*__iar_Tlsdtor_t)(void *);
 *   int __iar_Tlsalloc(__iar_Tlskey_t *, __iar_Tlsdtor_t); 
 *                                                    // Allocate a TLS element
 *   int __iar_Tlsfree(__iar_Tlskey_t);               // Free a TLS element
 *   int __iar_Tlsset(__iar_Tlskey_t, void *);        // Set a TLS element
 *   void *__iar_Tlsget(__iar_Tlskey_t);              // Get a TLS element
 *
 */

/* We don't have a compiler that supports tls declarations */





  /* No support for threading. */





#line 256 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\DLib_Threads.h"

#line 285 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\DLib_Threads.h"



#line 307 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\DLib_Threads.h"












#line 485 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\yvals.h"

#line 495 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\yvals.h"

                /* THREAD-LOCAL STORAGE */
#line 503 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\yvals.h"


                /* MULTITHREAD PROPERTIES */
#line 518 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\yvals.h"

                /* LOCK MACROS */
#line 526 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\yvals.h"


  
                // CLASS _Lockit
  class __iar_Lockit
  {     // lock while object in existence -- MUST NEST
  public:
#line 555 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\yvals.h"
/*    explicit __iar_Lockit()
 *    {   // do nothing
 *    }
 */

    explicit __iar_Lockit(int)
    {   // do nothing
    }

    ~__iar_Lockit()
    {   // do nothing
    }

    __iar_Lockit(const __iar_Lockit&);            // not defined
    __iar_Lockit& operator=(const __iar_Lockit&); // not defined
  };

  class __iar_Mutex
  {     // lock under program control
  public:
#line 586 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\yvals.h"
    void _Lock()
    {   // do nothing
    }

    void _Unlock()
    {   // do nothing
    }

  };



                /* MISCELLANEOUS MACROS AND FUNCTIONS*/





#line 612 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\yvals.h"



/*
 * Copyright (c) 1992-2009 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
V5.04:0576 */
#line 12 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\stdio.h"
#line 1 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\ysizet.h"
/* ysizet.h internal header file. */
/* Copyright 2003-2010 IAR Systems AB.  */





  #pragma system_include


#line 1 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\ycheck.h"
/* ycheck.h internal checking header file. */
/* Copyright 2005-2010 IAR Systems AB. */

/* Note that there is no include guard for this header. This is intentional. */


  #pragma system_include


/* __INTRINSIC
 *
 * Note: Redefined each time ycheck.h is included, i.e. for each
 * system header, to ensure that intrinsic support could be turned off
 * individually for each file.
 */










/* __TAABI_PORTABILITY_INTERNAL_LEVEL
 *
 * Note: Redefined each time ycheck.h is included, i.e. for each
 * system header, to ensure that ABI support could be turned off/on
 * individually for each file.
 *
 * Possible values for this preprocessor symbol:
 *
 * 0 - ABI portability mode is disabled.
 *
 * 1 - ABI portability mode (version 1) is enabled.
 *
 * All other values are reserved for future use.
 */






#line 67 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\ycheck.h"

#line 12 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\ysizet.h"



                /* type definitions */




typedef _Sizet size_t;




 typedef unsigned char __data_size_t; typedef unsigned char __idata_size_t; typedef unsigned char __bdata_size_t; typedef unsigned char __pdata_size_t; typedef unsigned int __xdata_size_t; typedef unsigned int __ixdata_size_t; typedef unsigned int __xdata_rom_size_t; typedef unsigned int __generic_size_t; typedef unsigned int __code_size_t;











#line 13 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\stdio.h"
#line 1 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\ystdio.h"
/* ystdio.h internal header */
/* Copyright 2009-2010 IAR Systems AB. */




  #pragma system_include







#line 51 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\ystdio.h"

/* File system functions that have debug variants. They are agnostic on 
   whether the library is full or normal. */
extern "C" {
__intrinsic __nounwind int remove(const char *);
__intrinsic __nounwind int rename(const char *, const char *);
}










/*
 * Copyright (c) 1992-2009 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
V5.042:0576 */
#line 14 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\stdio.h"



/* Module consistency. */
#pragma rtmodel="__dlib_file_descriptor",_STRINGIFY(_DLIB_FILE_DESCRIPTOR)

                /* macros */








#line 65 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\stdio.h"

#line 76 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\stdio.h"

#line 87 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\stdio.h"










                /* type definitions */
typedef _Fpost fpos_t;

                /* printf and scanf pragma support */
#pragma language=save
#pragma language=extended

#line 111 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\stdio.h"

#line 163 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\stdio.h"

extern "C" {
/* Corresponds to fgets(char *, int, stdin); */
__intrinsic __nounwind char * __gets(char *, int);
__intrinsic __nounwind char * gets(char *);
__intrinsic __nounwind void perror(const char *);
_Pragma("__printf_args") __intrinsic __nounwind int printf(const char *, ...);
__intrinsic __nounwind int puts(const char *);
_Pragma("__scanf_args")  __intrinsic __nounwind int scanf(const char *, ...);
_Pragma("__printf_args") __intrinsic __nounwind int sprintf(char *, const char *, 
                                    ...);
_Pragma("__scanf_args")  __intrinsic __nounwind int sscanf(const char *, 
                                   const char *, ...);
__intrinsic __nounwind char * tmpnam(char *);
/* Corresponds to "ungetc(c, stdout)" */
__intrinsic __nounwind int __ungetchar(int);
_Pragma("__printf_args") __intrinsic __nounwind int vprintf(const char *, __Va_list);

  _Pragma("__scanf_args")  __intrinsic __nounwind int vscanf(const char *, __Va_list);
  _Pragma("__scanf_args")  __intrinsic __nounwind int vsscanf(const char *, 
                                      const char *, __Va_list);

_Pragma("__printf_args") __intrinsic __nounwind int vsprintf(char *, const char *,
                                     __Va_list);
/* Corresponds to fwrite(p, x, y, stdout); */
__intrinsic __nounwind size_t __write_array(const void *, size_t, size_t);

  _Pragma("__printf_args") __intrinsic __nounwind int snprintf(char *, size_t, 
                                       const char *, ...);
  _Pragma("__printf_args") __intrinsic __nounwind int vsnprintf(char *, size_t,
                                        const char *, __Va_list);


__intrinsic __nounwind int getchar(void);
__intrinsic __nounwind int putchar(int);

}

#pragma language=restore

#line 218 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\stdio.h"






#line 274 "C:\\Program Files (x86)\\IAR Systems\\Embedded Workbench 6.0\\8051\\inc\\dlib\\c\\stdio.h"

/*
 * Copyright (c) 1992-2002 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
V5.04:0576 */
#line 37 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\CLCommunicUpsdPort1.h"
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
#line 38 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\CLCommunicUpsdPort1.h"
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

#line 40 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\CLCommunicUpsdPort1.h"






class CLCommunic                  // Classe CLCommunic
{
public:                           // Menbres publics. 
   CLCommunic(void);                                    // Constructeur par defaut.
   CLCommunic(UC ucLongBuf, UC ucLongTrame, UI uiBaud); // Constructeur initialisateur                                   
  ~CLCommunic(void);                                    // Destructeur

UC    ucLireEtatReception(void);
UC    GetChar(void);                        // Lit un caractere
UC    ucInitLongTrame(UC ucLong);           // Intialiser la longueur trame.
UC    static ucLireNbCaractRecu(void);      // Lire le nombre de caractere recu
UC    ucLireEtatTrame(void);                // Lire l'etat de la trame.
char *ucpLireTrame(void);                   // Retourne ladresse du tableau.
void  Send(UC ucCar);                       // Transmettre un caractere.
void  SendNumber(UI uiChiffreAAfficher);    // Transmettre un chiffre sur le port serie                                           
void  SendString(char const *ucpMessage);   // Transmettre une chaine de caractereS
                                       
protected:
  
private:                      // Menbres prives.
void vInitBaudRate(UI uiBaud);// Fonction pour intialiser le baudrate et timer.

__interrupt static void vInteruptSerial(void);// Fonction d'interruption pour 
                                              // recevoir un caractere.
UC ucValideTrame(void);                       // Fct pour valide une trame.

static char *cTabCaractereRecu;     // Pour pointeur sur tableau de char.
static char *cpDebutTrame;          // Pointeur sur debut tampon.
static char *cpFinTrame;            // Pointeur sur fin tampon.
static char *cptrEcriture;          // Pointeur pour position ecriture.
static char *cptrLecture;           // Pointeur pour lecture.
static UC    ucEtatTrame;           // Pour connaitre l'etat de la trame
static UC    ucNbCaractRecu;        // Pour connaitre le nbr de caractere recu.
static UC    ucLongueurTrame;       // Pour connaitre la longueur de la trame.
static UC    ucLongueurTampon;      // Pour connaitre la longueur du tampon.
static UC    ucCaractereRecu; 
static UC    ucEtatReception;
}; 

//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
















#line 24 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\NomDuProjet.cpp"
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
#line 25 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\NomDuProjet.cpp"
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

#line 26 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\NomDuProjet.cpp"
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\NomDuProjet.h"
// **************************Fichier.h
// Auteur:       Vincent Chouinard
// Date:         20 juillet 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.1
//
// Description:
// *****************************************************************************
//#include "_DeclarationGenerale.h" // Raccourcis Linguistiques utiles
//#include "ConversionKeilToIAR.h"  //
//#include "CLClavier.h"            // Pour utiliser le clavier
//#include "CLEcran.h"              // Pour utiliser l'�cran
//#include "stdio.h"                // Pour faire des printf

//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
#line 27 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo6\\Programme\\NomDuProjet.cpp"
// **** LES DEFINES *****************//

// **** LES CLASSES *****************//
//class RS232      Serial  ;         // Initialise la communication s�rie Dallas 
//class CLCommunic Serial  ;           // Initialise la communication s�rie uPSD  
//class CLI2CPort  I2CSoft ;           // Initialise le communication I2C Software
//class CLI2CHARD  I2CHard ;           // Initialise le communication I2C Hardware
class CLEcran    LCD     ;           // Initialise l' ecran LCD
//class Encodeur   Optik   ;           // Pour lire l'encodeur Optique
//class CLClavier  Keyboard;           // Initialise le clavier
//class DAC_ADC    Convert ;           // Initialise la conversion DAC <===> ADC
//class Timer0     Timer   ;           // Pour utiliser le timer 0 (Default = 1ms)
//class CLSPI      SPI     ;           // Initialise la communication SPI
class CanBus     CAN     ;           // Initialise le bus CAN
// **** LES FONCTIONS DU MAIN *******//

// **** PROGRAMME PRINCIPAL *********//
void main(void)
{
IE_bit . EA    = 0   ;  // Disable interrupt.
WDKEY = 0x55;  // Disable WatchDog.
IE_bit . EA    = 1   ;  // Enable Interrupt


LCD.vLCDCursor(0,1)      ;  
LCD.String("Class.CAN")  ;
LCD.vLCDCursor(0,2)      ;
LCD.String("Class.SPI")  ;
LCD.vLCDCursor(0,3)      ;
LCD.String("Class.LCD")  ;
LCD.vLCDCursor(0,3)      ;
LCD.String("Class.I2C")  ;

while(1)
  {
   CAN.SendMCP2515("Coucou");
  }
}
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
