#line 1 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\CLMCP2515.cpp"
// ***************** FICHIER:CLI2CPort.cpp
//
//  Description:Contient les fonctions haut niveau pour communiquer avec 
//              l I2C.
//             
//
//  Application realisee avec IAR
//
//  AUTEUR : Gabriel Fortin-Belanger
//  DATE CREATION :    2014-02-07		 VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
//******************************************************************************
#line 1 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\_DeclarationGenerale.h"

// ***************** FICHIER: _DECLARATIONGENERALE.H 
//
//  DEFINITION GENERALE POUR UN PROJET
//
//  Application realisee avec Keil 3.6
//
//  AUTEUR : DANIEL BRETON
//  DATE CREATION :    2099-03-30		 VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
// *****************************************************************************
// CHOIX DU TYPE DE COMPILATEUR
//

//
//
// *****************************************************************************
                                                                           


#line 1 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\TypeCible.h"
// ***************** FICHIER:TYPECIBLE.H 
//
//  Permet de slectionner quel microcontroller sera utiliser
//
//  Application realisee avec IAR
//
//  AUTEUR : Gabriel Fortin-Belanger
//  DATE CREATION :    2014-02-07		 VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
// *****************************************************************************



//******************************************************************************
//Choix de la cible
//
// #define DALLAS89C450
//  #define UPSD3254A
//******************************************************************************


//******************************************************************************
//      Fichier de definition des registres 
//
//




#line 1 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\iouPSD3254A.h"
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
    unsigned char  : 2;
  } IP_bit;
} @ 0xB8;
__sfr __no_init volatile union
{
  unsigned char IEA; /* Interrupt Enable (2nd) */
  struct /* Interrupt Enable (2nd) */
  {
    unsigned char EUSB : 1;
    unsigned char EI2C : 1;
    unsigned char  : 2;
    unsigned char ES2 : 1;
    unsigned char  : 2;
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
    unsigned char  : 2;
    unsigned char PS2 : 1;
    unsigned char  : 2;
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
    unsigned char  : 3;
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
    unsigned char  : 4;
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
    unsigned char  : 6;
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
    unsigned char  : 7;
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
    unsigned char  : 2;
  } ACON_bit;
} @ 0x97;
/*
 * Interrupt Vectors
 */
#line 672 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\iouPSD3254A.h"

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

#line 33 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\TypeCible.h"
    



//*****************************************************************************
//SECTION DES APPLICATIONS
//
//
//
//
//
//#define TEST_SECTION
#line 52 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\TypeCible.h"
//
//
//
//
//
//******************************************************************************


#line 23 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\_DeclarationGenerale.h"
#line 1 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\ConversionKeilToIAR.h"
// ***************** FICHIER:CONVERSTIONKEILTOIAR.H
//
//  Permet d'utiliser les programmes fait avec keil dans 
//  IAR.
//
//  Application realisee avec IAR
//
//  AUTEUR : Gabriel Fortin-Belanger
//  DATE CREATION :    2014-02-07		 VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
//******************************************************************************






//******************************************************************************
//
//
//
//
//******************************************************************************




//******************************************************************************

#line 74 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\ConversionKeilToIAR.h"

//******************************************************************************


#line 87 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\ConversionKeilToIAR.h"

#line 96 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\ConversionKeilToIAR.h"

#line 105 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\ConversionKeilToIAR.h"









// Interruption priorite




// Interruption niveau activite.













#line 139 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\ConversionKeilToIAR.h"

#line 146 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\ConversionKeilToIAR.h"
   
#line 154 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\ConversionKeilToIAR.h"

 //ADC





//PWM
#line 170 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\ConversionKeilToIAR.h"






//******************************************************************************

#line 24 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\_DeclarationGenerale.h"






// *****************************************************************************
//
//                            DEFINITION DE MOT CLE
//
// *****************************************************************************



























//******************************************************************************

// *****************************************************************************
//
//                            DEFINITION DE TYPE
//
// *****************************************************************************
 




  
typedef  unsigned char UC ;
typedef  unsigned int  UI ;
typedef  unsigned short int USI ;
typedef  unsigned short     US ; 
typedef  unsigned short int UINT16 ;
typedef  unsigned int UINT;




// *****************************************************************************
//
//                            DEFINITION DE Structure
//
// *****************************************************************************


struct STHorlogeHMS
 {
   
   UC ucHeure;
   UC ucMinute;
   UC ucSeconde;
 
 };

struct STHorlogeJMA
 {

  UC ucJour;
  UC ucMois;
  UC ucAnnee;
 
 };

union UNHorlogeHMS
 {
   struct STHorlogeHMS stHeure;
   UC ucTab[3];
 
 };

 
  struct STNibble8bit   //Structure qui separe un octet en 2 nibble
   {
     UC ucBit0a3 :4;
     UC ucBit4a7 :4; 

   };
 struct STNibble16bit  //Structure qui separe un mot de 16bit en 4 nibble
   {


     UI ucBit0a3 :4;
     UI ucBit4a7 :4;
     UI ucBit8a11 :4;
    UI ucBit12a15 :4; 

   };
 struct STOctet16bit  //Structure qui separe un mot de 16bit en 2 octet
   {
     UC ucBas ; 
     UC ucHaut ;
        
   };
  union UNMot8bitNibble            // union entre la structure qui separe 
   {                               //un octet en 2 nibble avec un octet
     struct STNibble8bit stNibble;
     UC ucOctet;     

   };
  union UNMot16bit                    //Union entre Structure qui separe un                              
   {                                  //mot de 16bit en 2 octet , une structure 
     struct STOctet16bit stOctet16bit;//qui separe un mot de 16 bit en 4 nibble
     struct STNibble16bit stNibble16bit;//Et un mot de 16 bit
     UINT16 uiWord;
   };



 struct STBitOctet //Champ de bit qui separe un octet en 8 bit 
  {
    UC ucBit0 : 1;
    UC ucBit1 : 1;
    UC ucBit2 : 1;
    UC ucBit3 : 1;
    UC ucBit4 : 1;
    UC ucBit5 : 1;
    UC ucBit6 : 1;
    UC ucBit7 : 1;
   
  
  };
union UNOctetBit //Union entre champ de bit qui separe octet en 8 et un octet
 {
 
   struct STBitOctet stBitOctet;
   UC ucOctet;
 
 
 };

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@




#line 15 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\CLMCP2515.cpp"
#line 1 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\CLMCP2515.h"
// ***************** FICHIER:CLEcran.H
//
//  Contient les definitions de classe pour utiliser l'ecran LCD
//  
//
//  Application realisee avec IAR
//
//  AUTEUR : Gabriel Fortin-Belanger
//  DATE CREATION :    2014-02-07		 VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
//******************************************************************************
#line 1 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\_DeclarationGenerale.h"

// ***************** FICHIER: _DECLARATIONGENERALE.H 
//
//  DEFINITION GENERALE POUR UN PROJET
//
//  Application realisee avec Keil 3.6
//
//  AUTEUR : DANIEL BRETON
//  DATE CREATION :    2099-03-30		 VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
// *****************************************************************************
// CHOIX DU TYPE DE COMPILATEUR
//

//
//
// *****************************************************************************
                                                                           






#line 83 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\_DeclarationGenerale.h"


// *****************************************************************************
//
//                            DEFINITION DE Structure
//
// *****************************************************************************
#line 177 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\_DeclarationGenerale.h"
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@




#line 16 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\CLMCP2515.h"
#line 1 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\CLSPI.h"
// ***************** FICHIER:CLEcran.H
//
//  Contient les definitions de classe pour utiliser l'ecran LCD
//  
//
//  Application realisee avec IAR
//
//  AUTEUR : Gabriel Fortin-Belanger
//  DATE CREATION :    2014-02-07		 VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
//******************************************************************************
#line 1 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\_DeclarationGenerale.h"

// ***************** FICHIER: _DECLARATIONGENERALE.H 
//
//  DEFINITION GENERALE POUR UN PROJET
//
//  Application realisee avec Keil 3.6
//
//  AUTEUR : DANIEL BRETON
//  DATE CREATION :    2099-03-30		 VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
// *****************************************************************************
// CHOIX DU TYPE DE COMPILATEUR
//

//
//
// *****************************************************************************
                                                                           






#line 83 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\_DeclarationGenerale.h"


// *****************************************************************************
//
//                            DEFINITION DE Structure
//
// *****************************************************************************
#line 177 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\_DeclarationGenerale.h"
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@




#line 16 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\CLSPI.h"



class CLSPI
{

   public:
     CLSPI(void);
     ~CLSPI(void);
    UC ucSPITransfert( UC ucMode, UC ucByte);
  
  
 
   protected:
  
  
  
  
   private:
  
  

  
  
  

};
   
#line 17 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\CLMCP2515.h"
#line 1 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\CLEcran.h"
// ***************** FICHIER:CLEcran.H
//
//  Contient les definitions de classe pour utiliser l'ecran LCD
//  
//
//  Application realisee avec IAR
//
//  AUTEUR : Gabriel Fortin-Belanger
//  DATE CREATION :    2014-02-07		 VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
//******************************************************************************


#line 1 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\_DeclarationGenerale.h"

// ***************** FICHIER: _DECLARATIONGENERALE.H 
//
//  DEFINITION GENERALE POUR UN PROJET
//
//  Application realisee avec Keil 3.6
//
//  AUTEUR : DANIEL BRETON
//  DATE CREATION :    2099-03-30		 VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
// *****************************************************************************
// CHOIX DU TYPE DE COMPILATEUR
//

//
//
// *****************************************************************************
                                                                           






#line 83 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\_DeclarationGenerale.h"


// *****************************************************************************
//
//                            DEFINITION DE Structure
//
// *****************************************************************************
#line 177 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\_DeclarationGenerale.h"
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@




#line 18 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\CLEcran.h"
#line 1 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\CLInOutBase.h"
// ***************** FICHIER:CLInOutBase.H
//
// Permet d'utiliser la classe pour faire des In Out
//  
//
//  Application realisee avec IAR
//
//  AUTEUR : Gabriel Fortin-Belanger
//  DATE CREATION :    2014-02-07		 VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
//******************************************************************************

#line 1 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\_DeclarationGenerale.h"

// ***************** FICHIER: _DECLARATIONGENERALE.H 
//
//  DEFINITION GENERALE POUR UN PROJET
//
//  Application realisee avec Keil 3.6
//
//  AUTEUR : DANIEL BRETON
//  DATE CREATION :    2099-03-30		 VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
// *****************************************************************************
// CHOIX DU TYPE DE COMPILATEUR
//

//
//
// *****************************************************************************
                                                                           






#line 83 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\_DeclarationGenerale.h"


// *****************************************************************************
//
//                            DEFINITION DE Structure
//
// *****************************************************************************
#line 177 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\_DeclarationGenerale.h"
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@




#line 15 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\CLInOutBase.h"


   


// ***************** FICHIER:CLInOutBase.H
//
// Description: La classe contient des fonctions In et Out qui peuvent 
//              travailler a 8 ou 16 bits. Pour les In et Out a 16bits il faut
//              fournir un parametre qui donne le type de transfert.
//
//              SAMELSB: 2 acces 8 bits a la meme adresse, LSB en premier.   
//              SAMEMSB: 2 acces 8 bits a la meme adresse, MSB en premier.  
//              SUITELSB: 2 acces 8 bits adresses successives, LSB en  premier 
//              SUITEMSB:2 acces 8 bits adresses successives, MSB en premier              
//
//
//
// 
// COMPOSITION: Aucune
//
//
// HERITAGE: Aucune.
//
//FONCTION:
//
// Fonction public ecriture 8 bits d un port.  vOut().     
// Fonction public ecriture 16 bits d un port.  vOut(). 
// Fonction public Lecture  8 bits d un port.  ucIn().
// Fonction public Lecture  16 bits d un port.  usiIn().
//
// Fonction prive  ecriture 8 bit. vOutportb().
// Fonction prive  Lecture 8 bit.  ucInportb().
//
//CONSTRUCTEUR:
//
//
//
//
//
//DESTRUCTEUR:
//
//
//
//
//
//  AUTEUR : Gabriel Fortin-Belanger
//  DATE CREATION :    2014-02-07		 VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
//******************************************************************************

class CLInOutBase
{
public:
  
   void vOut(unsigned short int usiAdresse, 
             unsigned char ucDonnee);//Sortie 8bit
   void vOut(unsigned short int usiAdresse, unsigned short int usiDonnee,
              unsigned char ucTypeTransfert);//Sortie 16bit
     
   unsigned char ucIn(unsigned short int usiAdresse); // Entree 8 bits
   unsigned short int usiIn(unsigned short int usiAdresse, 
                            unsigned char unTypeTransfert);// Entree 16 bit
     
private:
   UNMot16bit  unMot16bit; 
   UC __xdata *ucpAdresse;
  //Fonctions pour réaliser les acces dans un environnements 8051
   unsigned char ucInportb(unsigned short int usiAdresse); 
   void vOutportb(unsigned short int usiAdresse, unsigned char ucDonnee);
};  





//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#line 19 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\CLEcran.h"


// ***************** FICHIER:CLEcran.H
//
// Description: La classe contient des fonctions In et Out qui peuvent 
//              travailler a 8 ou 16 bits. Pour les In et Out a 16bits il faut
//              fournir un parametre qui donne le type de transfert.
//
// COMPOSITION: Aucune
//
//
// HERITAGE: CLInOutBase.
//
//FONCTION:
//
//  Fonct permet d'afficher un caractere                   vLcdAffCar ( ).
//  Fonct permet d'effacer l'ecran                         vLcdClr ( ).
//  Fonct permet d'initialiser l'ecran                     vLcdInit ( ).
//  Fonct permet de positionner le curseur                 vLcdPoscurC0L1 ( ).
//  Fonct permet d'attendre ecran pret                     vLcdBusy( ).
//  Fonct delais                                           vDelais( ).
//  Fonct permet afficher chaine de caractere              vLcdAffChaine().
//  Fonct permet afficher un ecran de 4 chaine             vLcdAffEcran().
//  Fonct permet afficher nombre hexadecimal               vLcdAffCarHex().
//  Fonct permet Generer un caractere cree par utilisateur vLcdCarGen().
//
//
//CONSTRUCTEUR: 
//       Constructeur par defaut          CLEcran(void)
//       Constructeur initialisateur      CLEcran(unsigned short int usiAdresse)
//
//
//DESTRUCTEUR:
//
//       destructeur efface l ecran      ~CLEcran(void)
//
//  AUTEUR : Gabriel Fortin-Belanger
//  DATE CREATION :    2014-02-07		 VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
//******************************************************************************


class CLEcran : public CLInOutBase
{
  public:
    void vLcdAffCar(UC ucCarac);  
    void vLcdClr(void);
    void vLcdPoscurC0L1(UC col,UC ligne);
    void vLcdInit(void);
    void vLcdAffChaine(char *ucpMessage);
    void vLcdAffEcran(char *ucpEcran);
    void vLcdAffCarHex(UC ucCarac);
    void vLcdCarGen(UC *ucTabCarac);
    
    CLEcran(void);
    CLEcran(unsigned short int usiAdresse);
    
    ~CLEcran(void);
  
    
  private:
   void vLcdBusy(void);
   void vDelaisEcran(UINT16 usiTemps);
   
   UINT16 usiAdresseEcran;
    
  protected:
  


};


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#line 18 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\CLMCP2515.h"

   class CLMCP2515 : public CLSPI
   {
   public:
     CLMCP2515();
     ~CLMCP2515();
   void Delai(unsigned long Temps);
   unsigned char EcrireDonnesMCP2515(unsigned char NombreDonneesEnvoyer, unsigned char Donnee1, unsigned char Donnee2, unsigned char Donnee3);
   void InitialisationMCP2515(void);
   void EcrireRegistreMCP2515(unsigned char Address, unsigned char Data);
   void ChoisirIdentifiantTX0(int Identifiant);
   void EnvoyerTrameMCP2515(const unsigned char * Message);
   void AcquitterInterruptionsMCP2515(void);
   unsigned char Longueur(const  unsigned char * Contenu);
  UC LireRegistreMCP2515(unsigned char Address);
unsigned char CLMCP2515 :: LireDonnesMCP2515(unsigned char NombreDonneesEnvoyer, unsigned char Donnee1, unsigned char Donnee2, unsigned char Donnee3);
  UC* LireTrameMCP2515(void) ;  
   UC ucBuf[8];
   private:
     
     
     
     
     
   protected:
     
   
   };









#line 16 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\CLMCP2515.cpp"


#line 66 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\CLMCP2515.cpp"






































#line 119 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\CLMCP2515.cpp"























#line 150 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\CLMCP2515.cpp"


/* Registres permettant de contrôler le module d'envoi « TX0 » */

#line 170 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\CLMCP2515.cpp"


/* Registres permettant de contrôler le module de réception « RX0 » */

#line 190 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\CLMCP2515.cpp"







CLMCP2515 :: CLMCP2515(void)
{

 
}


CLMCP2515 :: ~CLMCP2515(void)
{


}


void CLMCP2515 :: InitialisationMCP2515(void)
{
	/* Envoi de la commande de « RESET », qui consiste en l'envoi de l'octet « 0xC0 », par le bus SPI. */
	EcrireDonnesMCP2515(1, 0xC0, 0x00, 0x00);
	
	Delai(1000);	/* Délai permettant de s'assurer que le cicruit « MCP2515 » soit bien réinitialisé. */



/* Passage du circuit MCP2515 en « Configuration mode », nécéssaire pour pouvoir effectuer les opérations de configurations qui suivent */

	EcrireRegistreMCP2515(0x0F, 0x87);	/* Registre 0x0F.
									  - REQOP2 = 1,
									  - REQOP1 = 0,
									  - REQOP0 = 0 : le circuit est passé en « Configuration mode »,
									  - ABAT = 0 : ne pas annuler toutes les transmissons en attentes, si nécéssaire,
									  - OSM : renvois des messages, si nécessaire,
									  - CLKEN = 1 : la broche « CLKOUT » est activée,
									  - CLKPRE1 = 1,
									  - CLKPRE0 = 1 : réglage du prédiviseur de l'horloge de la broche « CLKOUT » à 8,
									  - F_CLKOUT = System Clock / 8 */

	EcrireRegistreMCP2515(0x0C, 0x3C); /* Registre 0x0C */
	EcrireRegistreMCP2515(0x0D, 0x00); /* Registre 0x0D.
									L'envoi d'un message - RTS - ne se fait pas sur le passage à « 0 » d'une broche,
									mais après l'envoi de la commande « RTS », par l'intermédiaire du bus SPI */


/* Initialisations des registres des compteurs d'erreurs */

	EcrireRegistreMCP2515(0x1C, 0x00); /* Registre 0x1C.
								 Mise à zéro du compteur d'erreurs en émission.*/
	EcrireRegistreMCP2515(0x1D, 0x00); /* Registre 0x1D.
								 Mise à zéro du compteur d'erreurs en réception.*/


	
/* Configurations du « Bit Timing » */
							
	EcrireRegistreMCP2515(0x2A, 0xC0 ); /* Registre 0x2A.
									 - SJW = 0 : 1 x TQ,
									 - BRP = 3. */
	EcrireRegistreMCP2515(0x29, 0x88); /* Registre 0x29.
									 - BTLMODE = 1,
									 - SAM = 0,
									 - PHSEG1 = 2,
									 - PRSEG = 0. */
	EcrireRegistreMCP2515(0x28, 0x03 ); /* Registre 0x28.
									 - SOF = 0 : Broche « CLKOUT » activée pour la fonction de répétition de l'horloge,
									 - WAKFIL = 0 : Wake-up filter désactivé,
									 - PHSEG : 2. */



/* Configurations des interruptions du circuit MCP2515 */

	EcrireRegistreMCP2515(0x2B, 0x01); /* Registre 0x2B.
									 Autorisation des interruptions suite à la réception d'une donnée par le module « RXB0 ». */

	EcrireRegistreMCP2515(0x2C, 0x00); /* Registre 0x2C.
								     Acquittement des éventuelles interruptions qui seraient en attente .*/
	
	EcrireRegistreMCP2515(0x2D, 0x00); /* Registre 0x2D */

	EcrireRegistreMCP2515(0x60, 0x20); /* Registre 0x60 */
	
	

/* Configuration initiale du module « TXB0 » */

	EcrireRegistreMCP2515(0x30, 0x03); /* Registre 0x30.
								      TXP = 0b11 : les messages ont la plus haute priorité. */

	EcrireRegistreMCP2515(0x35, 0x01); /* Registre 0x35.
								     Nombre d'octets occupés par les données à envoyer : 1 octet.*/


									 
/* Configurations de l'identifiant en réception par le filtre 0 du circuit MCP2515 */
		
	EcrireRegistreMCP2515(0x00, 0x00);	/* Registre 0x00.
									   Identifiant initial de réception H. */

	EcrireRegistreMCP2515(0x01, 0xC0);	/* Registre 0x01.
									   Identifiant initial de réception L + configurations initiales du mode de fonctionnement des identifiants en réceptions. */



/* Configurations du masque de réception initial utilisé par le filtre 0 du circuit MCP2515 */

	EcrireRegistreMCP2515(0x20, 0x00);	/* Registre 0x20.
									   Masque de réception initial H. */
									   
	EcrireRegistreMCP2515(0x21, 0xE0);	/* Registre 0x21.
									   Masque de réception initial L. + configurations initiales du mode de fonctionnement des masque de réceptions. */




/* Configurations de l'identifiant en émission par le module « TXB0 » du circuit MCP2515 */

	EcrireRegistreMCP2515(0x31, 0x00);	/* Registre 0x31.
									   Identifiant initial d'émission H. */

	EcrireRegistreMCP2515(0x32, 0x00);	/* Registre 0x32.
									   Identifiant initial d'émission L + configurations initiales du mode de fonctionnement des identifiants en émissions. */

	
/* Passage du circuit MCP2515 en « Normal Operation mode » */
	EcrireRegistreMCP2515(0x0F, 0x07); /* Registre 0x0F
	//EcrireRegistreMCP2515(MCP2515_CANCTRL, 0x07); * Registre 0x0F.
								      - REQOP2 = 1,
								      - REQOP1 = 0,
								      - REQOP0 = 0 : le circuit est passé en « Normal Operation mode ». 
								      - Les réglages précédemment évoqués restent inchangés. */

}




void CLMCP2515 :: EcrireRegistreMCP2515(unsigned char Address, unsigned char Data)
{
	EcrireDonnesMCP2515(3, 0x02, Address, Data);	/* Envoi de 3 octets :
													- La commande d'écriture ;
													- L'adresse du registre dans lequel écrire ;
													- L'octet à écrire dans le registre. */
}


UC CLMCP2515 :: LireRegistreMCP2515(unsigned char Address)
{
 // EcrireDonnesMCP2515(3, MCP2515_READ, Address, 0xFF);
  return(LireDonnesMCP2515(3, 0x03, Address, 0xFF));	/* Envoi de 3 octets :
 													//- La commande d'écriture ;
													- L'adresse du registre dans lequel écrire													- L'octet à écrire dans le registre. */
}



/* Configuration de l'identifiant d'envoi utilisé par le module « TXB0 ».


Paramètres d'entrée :

int identifiant - Identifiant, sur 11 bits, que doit utiliser le module « TXB0 ».

Valeur de retour :

Aucune.
*/
void CLMCP2515 :: ChoisirIdentifiantTX0(int Identifiant)
{
	unsigned char Contenu_MCP2515_TXB0SIDH = 0;
	unsigned char Contenu_MCP2515_TXB0SIDL = 0;

	Contenu_MCP2515_TXB0SIDH = (unsigned char)(0x00FF & (Identifiant >> 3));	/* On récupère les 8 bits de poids fort de l'identifiant à configurer,
qui doivent être placés tels quels dans le registre « MCP2515_TXB0SIDH ». */

	Contenu_MCP2515_TXB0SIDL = (unsigned char)(0x00E0 & (Identifiant << 5));	/* On récupère les 3 bits de poids faible de l'identifiant à configurer,
qui doivent être placés dans le registre « MCP2515_TXB0SIDL »,
aux bits « MCP2515_TXB0SIDL<5> », « MCP2515_TXB0SIDL<6> » et « MCP2515_TXB0SIDL<7> ». */

	EcrireRegistreMCP2515(0x31, Contenu_MCP2515_TXB0SIDH);	/* Identifiant Emission H */
	EcrireRegistreMCP2515(0x32, Contenu_MCP2515_TXB0SIDL);	/* Identifiant Emission L + Configurations du mode de fonctionnement des identifiants */
}





/* Envoi d'un message d'un maximum de 8 caractères, par le module « TXB0 ».


Paramètres d'entrée :

unsigned char * message - Pointeur sur le début d'une chaîne d'un maximum de 8 caractères,
à tranmettre par le module « TXB0 ».

Valeur de retour :

Aucune.
*/
void CLMCP2515 :: EnvoyerTrameMCP2515(const  unsigned char * Message)
{
	unsigned char TailleDuMessage = 0;
	unsigned char k;
	unsigned char PointeurRegistre = 0x36;

	/* Détermination du nombre d'octets de données à transmettre, et limitation à 8 octets au maximum. */
	TailleDuMessage = Longueur(Message);

	if(TailleDuMessage > 8)	/* Si le nombre d'octets de données à transmettre dépasse le nombre maximal d'octets possible. */
	{
		TailleDuMessage = 8;	/* Le nombre maximal d'octets possible sera tranmis par le circuit MCP2515. */
	}

	EcrireRegistreMCP2515(0x35, TailleDuMessage);	/* Le MCP2515 est informé du nombre d'octets de données qu'il aura à tranmettre. */

	/* Chargement du message dans le MCP2515 */
	for(k = 0; k < TailleDuMessage; k++)
	{
		EcrireRegistreMCP2515(PointeurRegistre, Message[k]);	/* Les registres de données du module « TXB0 »,
dont les adresses sont consécutives, sont remplis,
en commencant par le registre « MCP2515_TXB0D0 », d'adresse 0x36. */
		PointeurRegistre++;
	}

	/* Envoi de la commande « RTS », qui consiste en l'envoi de l'octet « 0xC0 », par le bus SPI. */
	EcrireDonnesMCP2515(1, 0x81, 0x00, 0x00);

	Delai(10);
}





UC*  CLMCP2515 :: LireTrameMCP2515(void)
{
   UC ucTrame;
  // UC ucID;
  
   
  
   
   // ucID = LireRegistreMCP2515(MCP2515_RXB0DLC);
   //ucBuf[0] = ucTrame;
   
 ucTrame = LireRegistreMCP2515(0x65);
   ucBuf[0] = ucTrame;
   
 
   
  for(UC uci=0;uci < ucTrame; uci++)
   {

      ucBuf[uci + 1] = LireRegistreMCP2515( 0x66 + uci);
       Delai(1000);
   }
 
  
  return (ucBuf);
  
}




/* Acquittement des interruptions du circuit MCP2515.


Paramètres d'entrée :

Aucun.

Valeur de retour :

Aucune.
*/
void CLMCP2515 :: AcquitterInterruptionsMCP2515(void)
{
	EcrireRegistreMCP2515(0x0F, 0x87);	/* Registe 0x0F.
									   Le circuit est passé en « Configuration mode ». */
	EcrireRegistreMCP2515(0x2C, 0x00);	/* Registre 0x2C.
									   Acquittement des interruptions du circuit MCP2515. */
	EcrireRegistreMCP2515(0x0F, 0x07);	/* Registe 0x0F.
									   Le circuit est passé en « Normal Operation mode ». */
}




unsigned char CLMCP2515 :: EcrireDonnesMCP2515(unsigned char NombreDonneesEnvoyer, unsigned char Donnee1, unsigned char Donnee2, unsigned char Donnee3)
{
	unsigned char k;

	unsigned char Donnees[3] = {0x00};

	Donnees[0] = Donnee1;
	Donnees[1] = Donnee2;
	Donnees[2] = Donnee3;

	P1_bit . P17 = 0;	/* ~CS_MCP2515 = 0 */

	for(k = 0; k < NombreDonneesEnvoyer; k++)
	{
			ucSPITransfert( 0x00 , Donnees[k]);
			for(int V =0 ;V<100;V++);	/* Delai au moins tant que le module du SPI est occupé */	
	}

	P1_bit . P17 = 1;	/* ~CS_MCP2515 = 1 */

	return 0x01;
}



unsigned char CLMCP2515 :: LireDonnesMCP2515(unsigned char NombreDonneesEnvoyer, unsigned char Donnee1, unsigned char Donnee2, unsigned char Donnee3)
{
	unsigned char k;
        unsigned char buf;
	unsigned char Donnees[3] = {0x00};

	Donnees[0] = Donnee1;
	Donnees[1] = Donnee2;
	Donnees[2] = Donnee3;

	P1_bit . P17 = 0;	/* ~CS_MCP2515 = 0 */

	for(k = 0; k < NombreDonneesEnvoyer; k++)
	{
		        buf = ucSPITransfert( 0x00 , Donnees[k]);
			for(int V =0 ;V<100;V++);	/* Delai au moins tant que le module du SPI est occupé */	
	}

	P1_bit . P17 = 1;	/* ~CS_MCP2515 = 1 */

	return buf;
}






void CLMCP2515 :: Delai(unsigned long Temps)
{
	unsigned long k;

	for(k = 0; k < Temps; k++);
}

unsigned char CLMCP2515 :: Longueur(const  unsigned char * Contenu)
{
	unsigned char Compteur = 0;

	while(Contenu[Compteur] != '\0')
	{
		Compteur++;
	}

	return Compteur;
}


