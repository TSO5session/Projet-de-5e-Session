#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\Conversions.cpp"
// **************************Conversions.cpp
// Auteur:       Vincent Chouinard
// Date:         20 juillet 2014
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

#line 12 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\Conversions.cpp"
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\Conversions.h"
// **************************Conversions.h
// Auteur:       Vincent Chouinard
// Date:         20 juillet 2014
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

#line 12 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\Conversions.h"




class Conversion //: public CLAutreClasse
{
public:
   Conversion(void);            // ***Constructeur par defaut
   Conversion(UC ucParametre);  // ***Constructeur initialisateur
  ~Conversion(void);            // ***Destructeur

   UC         HEXtoASCII    (UC HEXtoConvert);   //         Convert.HEXtoASCII(0x44);
   UC         ASCIItoHEX    (UC ASCIItoConvert); //ASCII  = Convert.ASCIItoHEX('B');
   const char FloatToString (float fInputFloat); //String = Convert.FloatToString(131.74);  
   
protected:

private:
   void StringAdder(char cNumber);
   static char *StringFinal;      // Pour pointeur sur tableau de char.
   
};

//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
#line 13 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\Conversions.cpp"
///// Initialise les variables statiques.
char *Conversion :: StringFinal = 0;

//******************************************************************************
//                            LE CONSTRUCTEUR PAR DEFAUT
// *****************************************************************************
Conversion :: Conversion(void)
{

}

//******************************************************************************
//                            LE CONSTRUCTEUR PAR DEFAUT
// *****************************************************************************
Conversion :: Conversion(UC ucParametre)
{

}

// *****************************************************************************
//                            LE DESTRUCTEUR
// *****************************************************************************
Conversion :: ~Conversion(void)
{

}

void Conversion :: StringAdder(char cNumber)
{
  
}

const char Conversion :: FloatToString (float fInputFloat)
{
int i                 = 0; // Pour les boucles de comptage
float fTemporaire     = 0; // Pour le calcul de decimales
USI usiLesEntiers     = 0; // Pour la conversion d'un float en entier
USI usiLesEntiersTemp = 0; // Pour la conversion d'un float en entier
USI usiDecimalesTemp  = 0; // Pour convertir les decimales d'un float en entier
USI usiLesDecimales   = 0; // Pour convertir les decimales d'un float en entier

usiLesEntiers   = (USI)fInputFloat; // Conversion des floats en USI sans virgule
usiLesDecimales = (USI)fInputFloat; // Enleve les decimales du float
fTemporaire     = (fInputFloat - (float)usiLesDecimales) * 100;//Decimales 0-999
usiLesDecimales = (USI)fTemporaire; //Conversion (.0 a .999) vers (0 a 999)

for(i = 0; i < 3; i++) //Pour trois fois (Centaine, dizaine, unite)
  {
   if(i == 0) // Pour les centaines
     {
      usiLesEntiersTemp = usiLesEntiers /  100;
      usiLesEntiers     = usiLesEntiers - (100 * usiLesEntiersTemp);
     }
   if(i == 1) // Pour les dizaines
     {
      usiLesEntiersTemp = usiLesEntiers /  10;
      usiLesEntiers     = usiLesEntiers - (10 * usiLesEntiersTemp);
     }
   if(i == 2) // Pour les unitees
     {
      usiLesEntiersTemp=usiLesEntiers;
     }

   switch(usiLesEntiersTemp) // Affiche un caractere correspondant a l'unite
     {                       // float lue
      case 0:
         StringAdder('0');
      break;

      case 1:
         StringAdder('1');
      break;

      case 2:
         StringAdder('2');
      break;

      case 3:
         StringAdder('3');
      break;

      case 4:
         StringAdder('4');
      break;

      case 5:
         StringAdder('5');
      break;

      case 6:
         StringAdder('6');
      break;

      case 7:
         StringAdder('7');
      break;

      case 8:
         StringAdder('8');
      break;

      case 9:
         StringAdder('9');
      break;
     }
   }

StringAdder('.'); // Affiche la satane virgule

for(i = 0; i < 2; i++) //Pour deux fois (Dixieme, centieme)
  {
   if(i == 0)          // Pour les dixiemes
     {
      usiDecimalesTemp = usiLesDecimales /  10;
     }
   if(i == 1)          // Pour les centiemes
     {
      usiDecimalesTemp = usiLesDecimales - (10 * usiDecimalesTemp) ;
     }

   switch(usiDecimalesTemp) // Affiche un caractere correspondant a l'unite
     {                      // float lue
      case 0:
         StringAdder('0');
      break;

      case 1:
         StringAdder('1');
      break;

      case 2:
         StringAdder('2');
      break;

      case 3:
         StringAdder('3');
      break;

      case 4:
         StringAdder('4');
      break;

      case 5:
         StringAdder('5');
      break;

      case 6:
         StringAdder('6');
      break;

      case 7:
         StringAdder('7');
      break;

      case 8:
         StringAdder('8');
      break;

      case 9:
         StringAdder('9');
      break;
     }
  }
return(*StringFinal);
}





UC Conversion :: ASCIItoHEX(UC ASCIItoConvert)
{
UC ConvertedToHEX = 0;

switch(ConvertedToHEX)
    {
     case '0':
      ConvertedToHEX = 0x30;
     break;

     case '1':
      ConvertedToHEX = 0x31;
     break;

     case '2':
      ConvertedToHEX = 0x32;
     break;

     case '3':
      ConvertedToHEX = 0x33;
     break;

     case '4':
      ConvertedToHEX = 0x34;
     break;

     case '5':
      ConvertedToHEX = 0x35;
     break;

     case '6':
      ConvertedToHEX = 0x36;
     break;

     case '7':
      ConvertedToHEX = 0x37;
     break;

     case '8':
      ConvertedToHEX = 0x38;
     break;

     case '9':
      ConvertedToHEX = 0x39;
     break;

     case 'A':
      ConvertedToHEX = 0x41;
     break;

     case 'B':
      ConvertedToHEX = 0x42;
     break;
     
     case 'C':
      ConvertedToHEX = 0x43;
     break;

     case 'D':
      ConvertedToHEX = 0x44;
     break;

     case 'E':
      ConvertedToHEX = 0x45;
     break;

     case 'F':
      ConvertedToHEX = 0x46;
     break;

     case 'G':
      ConvertedToHEX = 0x47;
     break;

     case 'H':
      ConvertedToHEX = 0x48;
     break;

     case 'I':
      ConvertedToHEX = 0x49;
     break;

     case 'J':
      ConvertedToHEX = 0x4A;
     break;

     case 'K':
      ConvertedToHEX = 0x4B;
     break;

     case 'L':
      ConvertedToHEX = 0x4C;
     break;

     case 'M':
      ConvertedToHEX = 0x4D;
     break;

     case 'N':
      ConvertedToHEX = 0x4E;
     break;

     case 'O':
      ConvertedToHEX = 0x4F;
     break;

     case 'P':
      ConvertedToHEX = 0x50;
     break;

     case 'Q':
      ConvertedToHEX = 0x51;
     break;

     case 'R':
      ConvertedToHEX = 0x52;
     break;

     case 'S':
      ConvertedToHEX = 0x53;
     break;

     case 'T':
      ConvertedToHEX = 0x54;
     break;

     case 'U':
      ConvertedToHEX = 0x55;
     break;

     case 'V':
      ConvertedToHEX = 0x56;
     break;

     case 'W':
      ConvertedToHEX = 0x57;
     break;

     case 'X':
      ConvertedToHEX = 0x58;
     break;

     case 'Y':
      ConvertedToHEX = 0x59;
     break;

     case 'Z':
      ConvertedToHEX = 0x5A;
     break;     
   }

return(ConvertedToHEX);
}

UC Conversion :: HEXtoASCII(UC HEXtoConvert)
{
UC ConvertedToAscii = 0;

if((HEXtoConvert >= 0x41) && (HEXtoConvert <= 0x5A)) // Si l'hex est une lettre majuscule
  {
   switch(HEXtoConvert)
    {
     case 0x41:
      ConvertedToAscii = 'A';
     break;

     case 0x42:
      ConvertedToAscii = 'B';
     break;

     case 0x43:
      ConvertedToAscii = 'C';
     break;

     case 0x44:
      ConvertedToAscii = 'D';
     break;

     case 0x45:
      ConvertedToAscii = 'E';
     break;

     case 0x46:
      ConvertedToAscii = 'F';
     break;

     case 0x47:
      ConvertedToAscii = 'G';
     break;

     case 0x48:
      ConvertedToAscii = 'H';
     break;

     case 0x49:
      ConvertedToAscii = 'I';
     break;

     case 0x4A:
      ConvertedToAscii = 'J';
     break;

     case 0x4B:
      ConvertedToAscii = 'K';
     break;

     case 0x4C:
      ConvertedToAscii = 'L';
     break;

     case 0x4D:
      ConvertedToAscii = 'M';
     break;

     case 0x4E:
      ConvertedToAscii = 'N';
     break;

     case 0x4F:
      ConvertedToAscii = 'O';
     break;

     case 0x50:
      ConvertedToAscii = 'P';
     break;

     case 0x51:
      ConvertedToAscii = 'Q';
     break;

     case 0x52:
      ConvertedToAscii = 'R';
     break;

     case 0x53:
      ConvertedToAscii = 'S';
     break;

     case 0x54:
      ConvertedToAscii = 'T';
     break;

     case 0x55:
      ConvertedToAscii = 'U';
     break;

     case 0x56:
      ConvertedToAscii = 'V';
     break;

     case 0x57:
      ConvertedToAscii = 'W';
     break;

     case 0x58:
      ConvertedToAscii = 'X';
     break;

     case 0x59:
      ConvertedToAscii = 'Y';
     break;

     case 0x5A:
      ConvertedToAscii = 'Z';
     break;
  }
}

if((HEXtoConvert >= 0x61) && (HEXtoConvert <= 0x7A)) // Si l'hex est une lettre minuscule
  {
   switch(HEXtoConvert)
    {
     case 0x61:
      ConvertedToAscii = 'a';
     break;

     case 0x62:
      ConvertedToAscii = 'b';
     break;

     case 0x63:
      ConvertedToAscii = 'c';
     break;

     case 0x64:
      ConvertedToAscii = 'd';
     break;

     case 0x65:
      ConvertedToAscii = 'e';
     break;

     case 0x66:
      ConvertedToAscii = 'f';
     break;

     case 0x67:
      ConvertedToAscii = 'g';
     break;

     case 0x68:
      ConvertedToAscii = 'h';
     break;

     case 0x69:
      ConvertedToAscii = 'i';
     break;

     case 0x6A:
      ConvertedToAscii = 'j';
     break;

     case 0x6B:
      ConvertedToAscii = 'k';
     break;

     case 0x6C:
      ConvertedToAscii = 'l';
     break;

     case 0x6D:
      ConvertedToAscii = 'm';
     break;

     case 0x6E:
      ConvertedToAscii = 'n';
     break;

     case 0x6F:
      ConvertedToAscii = 'o';
     break;

     case 0x70:
      ConvertedToAscii = 'p';
     break;

     case 0x71:
      ConvertedToAscii = 'q';
     break;

     case 0x72:
      ConvertedToAscii = 'r';
     break;

     case 0x73:
      ConvertedToAscii = 's';
     break;

     case 0x74:
      ConvertedToAscii = 't';
     break;

     case 0x75:
      ConvertedToAscii = 'u';
     break;

     case 0x76:
      ConvertedToAscii = 'v';
     break;

     case 0x77:
      ConvertedToAscii = 'w';
     break;

     case 0x78:
      ConvertedToAscii = 'x';
     break;

     case 0x79:
      ConvertedToAscii = 'y';
     break;

     case 0x7A:
      ConvertedToAscii = 'z';
     break;
  }
}

if((HEXtoConvert >= 0x30) && (HEXtoConvert <= 0x39)) // Si l'hex est un chiffre
  {
switch(HEXtoConvert)
    {
     case 0x30:
      ConvertedToAscii = '0';
     break;

     case 0x31:
      ConvertedToAscii = '1';
     break;

     case 0x32:
      ConvertedToAscii = '2';
     break;

     case 0x33:
      ConvertedToAscii = '3';
     break;

     case 0x34:
      ConvertedToAscii = '4';
     break;

     case 0x35:
      ConvertedToAscii = '5';
     break;

     case 0x36:
      ConvertedToAscii = '6';
     break;

     case 0x37:
      ConvertedToAscii = '7';
     break;

     case 0x38:
      ConvertedToAscii = '8';
     break;

     case 0x39:
      ConvertedToAscii = '9';
     break;
  }
}
return(ConvertedToAscii);
}
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
