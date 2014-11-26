#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\CLFestoCaptors.cpp"
// **************************CLFestoCaptors.cpp
// Auteur:       Prenom Nom
// Date:         19 Octobre 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.1
//
// Description:
// *****************************************************************************
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\_DeclarationGenerale.h"
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
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\ConversionKeilToIAR.h"
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

#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\TypeCible.h"
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




#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\iouPSD3254A.h"
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
#line 694 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\iouPSD3254A.h"

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

#line 28 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\TypeCible.h"



//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
#line 14 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\ConversionKeilToIAR.h"




// *****************************************************************************
// DEFINITION DES  MODELES DE MEMOIRE
// *****************************************************************************






// *****************************************************************************
#line 100 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\ConversionKeilToIAR.h"
// *****************************************************************************

// *****************************************************************************

// Interruption activation






// Interruption priorite




// Interruption niveau activite.












 // #define ES0 IE_bit.ES
 // #define ES0 IE_bit.ES




#line 141 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\ConversionKeilToIAR.h"

#line 148 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\ConversionKeilToIAR.h"



#line 159 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\ConversionKeilToIAR.h"

#line 168 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\ConversionKeilToIAR.h"

#line 177 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\ConversionKeilToIAR.h"




// S2STA
#line 190 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\ConversionKeilToIAR.h"

// S2CON
#line 202 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\ConversionKeilToIAR.h"

//S1DAT DEFINE 0xDA /* Data Hold Register */
//S1ADR DEFINE 0xDB /* DDC I2C address */
//S2DAT DEFINE 0xDE /* Data Hold Register */





// *****************************************************************************

//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX

#line 17 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\_DeclarationGenerale.h"




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

#line 77 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\_DeclarationGenerale.h"

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

#line 12 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\CLFestoCaptors.cpp"
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\CLFestoCaptors.h"
// **************************Fichier.h
// Auteur:       Prenom nom
// Date:         19 octobre 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.1
//
// Description:
// *****************************************************************************
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\_DeclarationGenerale.h"
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
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\ConversionKeilToIAR.h"
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



#line 213 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\ConversionKeilToIAR.h"
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX

#line 17 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\_DeclarationGenerale.h"


#line 139 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\_DeclarationGenerale.h"
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX

#line 12 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\CLFestoCaptors.h"
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\CLI2CPort.h"
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
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\_DeclarationGenerale.h"
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
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\ConversionKeilToIAR.h"
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



#line 213 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\ConversionKeilToIAR.h"
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX

#line 17 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\_DeclarationGenerale.h"


#line 139 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\_DeclarationGenerale.h"
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX

#line 25 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\CLI2CPort.h"
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\CLI2CBase.h"
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
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\_DeclarationGenerale.h"
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
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\ConversionKeilToIAR.h"
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



#line 213 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\ConversionKeilToIAR.h"
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX

#line 17 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\_DeclarationGenerale.h"


#line 139 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\_DeclarationGenerale.h"
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX

#line 32 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\CLI2CBase.h"







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
#line 26 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\CLI2CPort.h"










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
#line 13 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\CLFestoCaptors.h"
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\CLSPI.h"
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



#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\_DeclarationGenerale.h"
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
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\ConversionKeilToIAR.h"
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



#line 213 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\ConversionKeilToIAR.h"
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX

#line 17 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\_DeclarationGenerale.h"


#line 139 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\_DeclarationGenerale.h"
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX

#line 21 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\CLSPI.h"
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\MCP2515.h"



#line 52 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\MCP2515.h"






























#line 97 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\MCP2515.h"















#line 120 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\MCP2515.h"

/* Registres permettant de contrôler le module d'envoi « TX0 » */
#line 138 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\MCP2515.h"

/* Registres permettant de contrôler le module de réception « RX0 » */
#line 22 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\CLSPI.h"
/////////////////////////////////////
#line 31 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\CLSPI.h"
/////////////////////////////////////

class CLSPI
{
public:
   CLSPI(void)    ;                            // Constructeur.
   CLSPI(UC ucVal);                            // Constructeur initialisateur.
  ~CLSPI(void)    ;                            // Destructeur.

   UC   WriteMPC     (UC Data);                // Pour envoyer une valeur hexa sur les IO du MPC
   UC   WritePOT     (UC Data);                // Pour écrire sur un POT numerique 
   UC   WriteDAC     (UC ucPin, int iData);    // Pour faire une conversion Digital to Numeric
   UC   WriteMPC     (UC NombreDonneesEnvoyer, UC Donnee1, UC Donnee2, UC Donnee3);   
   UC   ReadMPC      (void);                   // Pour lire la valeur hexa des IO du MPC
   UC   Write        (UC ucValeur, UC ucMode); // Pour ecrire une donnee 8  bit en SPI
protected:

private:
   void Delai     (unsigned long Temps);     // Implémentation d'un delai ajustable
   void Direction (UC Directions) ;          // Pour la direction des port du MCP23S08  
   
   UI   Write16   (UI uiValeur, UC ucMode);  // Pour ecrire une donnee 16 bit en SPI    
};


//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX

#line 14 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\CLFestoCaptors.h"




class CLFestoCaptors 
{
public:
   CLFestoCaptors(void);             // ***Constructeur par defaut
   CLFestoCaptors(UC ucParametre);   // ***Constructeur initialisateur
  ~CLFestoCaptors(void);             // ***Destructeur

   UC readCapacitiveCaptor (void);   // Lit le capteur capacitif
   UC readOpticCaptor      (void);   // lit le capteur optique
   UC readInductiveCaptor  (void);   // lit le capteur magnétique
   
   UC readHeightCaptor     (void);   // Lit le capteur de hauteur du bloc (capteur A4)
   UC readPreVentouseCaptor(void);   // Lit le dernier capteur avant que la ventouse ne prenne le bloc
   
protected:

private:
   class CLSPI      SPI     ; // Initialise la communication SPI
   class CLI2CPort  I2C     ; // Initialise le communication I2C Software
};

//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
#line 13 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\CLFestoCaptors.cpp"


//******************************************************************************
//                            LE CONSTRUCTEUR PAR DEFAUT
// *****************************************************************************
CLFestoCaptors :: CLFestoCaptors(void)
{

}

//******************************************************************************
//                            LE CONSTRUCTEUR INITIALISATEUR
// *****************************************************************************
CLFestoCaptors :: CLFestoCaptors(UC ucParametre)
{

}

// *****************************************************************************
//                            LE DESTRUCTEUR
// *****************************************************************************
CLFestoCaptors :: ~CLFestoCaptors(void)
{

}

// **********************FONCTION: readCapacitiveCaptor()
//
// DESCRIPTION        : Lit le capteur capacitif et retourne la valeur lue
//
// INCLUDE            : "_DeclarationGenerale.h" "CLFestoCaptors.h"
//                      
// PROTOTYPE          : UC readOpticCaptor(void)
//
// PROCEDURE D'APPEL  : data = readOpticCaptor()
//
// PARAMETRE D'ENTREE : AUCUN
//
// PARAMETRE DE SORTIE: UC
//
// Auteur             : Vincent Chouinard
// Date               : 25 novembre 2014   (Version 1.0)
// Modification       :
// *****************************************************************************
UC CLFestoCaptors :: readCapacitiveCaptor (void)
{
return(0);
}

// **********************FONCTION: readOpticCaptor()
//
// DESCRIPTION        : Lit le capteur optique et retourne la valeur lue
//
// INCLUDE            : "_DeclarationGenerale.h" "CLFestoCaptors.h"
//                      
// PROTOTYPE          : UC readOpticCaptor(void)
//
// PROCEDURE D'APPEL  : data = readOpticCaptor()
//
// PARAMETRE D'ENTREE : AUCUN
//
// PARAMETRE DE SORTIE: UC
//
// Auteur             : Vincent Chouinard
// Date               : 25 novembre 2014   (Version 1.0)
// Modification       :
// *****************************************************************************
UC CLFestoCaptors :: readOpticCaptor (void)
{
return(0); 
}

// **********************FONCTION: readMagneticCaptor()
//
// DESCRIPTION        : Lit le capteur magnétique et retourne la valeur lue
//
// INCLUDE            : "_DeclarationGenerale.h" "CLFestoCaptors.h"
//                      
// PROTOTYPE          : UC readInductiveCaptor(void)
//
// PROCEDURE D'APPEL  : data = readInductiveCaptor()
//
// PARAMETRE D'ENTREE : AUCUN
//
// PARAMETRE DE SORTIE: UC
//
// Auteur             : Vincent Chouinard
// Date               : 25 novembre 2014   (Version 1.0)
// Modification       :
// *****************************************************************************
UC CLFestoCaptors :: readInductiveCaptor (void)
{
return(0);   
}

// **********************FONCTION: readHeightCaptor()
//
// DESCRIPTION        : Lit le capteur de hauteur du bloc
//
// INCLUDE            : "_DeclarationGenerale.h" "CLFestoCaptors.h"
//                      
// PROTOTYPE          : UC readHeightCaptor(void)
//
// PROCEDURE D'APPEL  : data = readHeightCaptor()
//
// PARAMETRE D'ENTREE : AUCUN
//
// PARAMETRE DE SORTIE: UC
//
// Auteur             : Vincent Chouinard
// Date               : 25 novembre 2014   (Version 1.0)
// Modification       :
// *****************************************************************************
UC CLFestoCaptors :: readHeightCaptor (void)
{
return(0);
}

// **********************FONCTION: readPreVentouseCaptor()
//
// DESCRIPTION        : Lit le dernier capteur avant que la ventouse ne prenne le bloc
//
// INCLUDE            : "_DeclarationGenerale.h" "CLFestoCaptors.h"
//                      
// PROTOTYPE          : UC readPreVentouseCaptor(void)
//
// PROCEDURE D'APPEL  : data = readPreVentouseCaptor()
//
// PARAMETRE D'ENTREE : AUCUN
//
// PARAMETRE DE SORTIE: UC
//
// Auteur             : Vincent Chouinard
// Date               : 25 novembre 2014   (Version 1.0)
// Modification       :
// *****************************************************************************
UC CLFestoCaptors :: readPreVentouseCaptor(void)
{
return(0);  
}
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
