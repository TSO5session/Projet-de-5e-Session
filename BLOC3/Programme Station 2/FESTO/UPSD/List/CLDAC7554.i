#line 1 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\CLDAC7554.cpp"
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




#line 15 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\CLDAC7554.cpp"
#line 1 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\CLDAC7554.h"
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




#line 16 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\CLDAC7554.h"
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
   
#line 17 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\CLDAC7554.h"
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
#line 18 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\CLDAC7554.h"

   class CLDAC7554 : public CLSPI
   {
   public:
     CLDAC7554();
     ~CLDAC7554();
     void vConvDA(UC ucChanel , UC ucValH, UC ucValL);
     CLEcran clEcran;
     
     
     
   private:
     
     
     
     
     
   protected:
     
   
   };









#line 16 "J:\\Projet_Session5_LNAH\\S2_18Nov2014\\Programme Station 2\\FESTO\\Libraire\\CLDAC7554.cpp"




CLDAC7554 :: CLDAC7554(void)
{

 
}


CLDAC7554 :: ~CLDAC7554(void)
{


}


void CLDAC7554 :: vConvDA(UC ucChanel , UC ucValH, UC ucValL)
{
 
  int iCal;
  P1_bit . P16 =1;
  /*
  iCal = ( ucValH << 8) | ucValL;
  iCal = iCal >> 4;
  ucValH = UC (iCal >> 8 );
  ucValL = UC (iCal);
  */
  switch(ucChanel)
  {
  case 0:
    P1_bit . P16 =0;
    ucSPITransfert(0x00,(0x80 | ucValH));
    ucSPITransfert(0x00,ucValL);
    P1_bit . P16 =1;
    break;
    
  case 1:
    break;
  case 2:
 
    break;
  case 3:

    break;
    
    
  
  }
 

   

}







