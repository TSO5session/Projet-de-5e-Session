/***************************************************************************
 *                                - iouPSD3254A.h -
 *
 * Special header for the STMicroelectronics uPSD3254A Microcontroller.
 *
 ***************************************************************************/

#ifndef IOUPSD3254A_H
#define IOUPSD3254A_H
#define __UPSD3254A__
#ifdef __IAR_SYSTEMS_ICC__
#ifndef _SYSTEM_BUILD
   #pragma system_include
#endif
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
#define extern0 0x03 /* External interrupt 0 */
#define IE0_int 0x03 /* External interrupt 0 */
#define timer0 0x0B /* Timer 0 Interrupt */
#define TF0_int 0x0B /* Timer 0 Interrupt */
#define extern1 0x13 /* External interrupt 1 */
#define IE1_int 0x13 /* External interrupt 1 */
#define timer1 0x1B /* Timer 1 Interrupt */
#define TF1_int 0x1B /* Timer 1 Interrupt */
#define sio_ti 0x23 /* Serial Port Interrupt */
#define sio_ri 0x23 /* Serial Port Interrupt */
#define TI_int 0x23 /* Serial Port Interrupt */
#define RI_int 0x23 /* Serial Port Interrupt */

#pragma language=default
#endif  /* __IAR_SYSTEMS_ICC__  */

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

#ifdef __IAR_SYSTEMS_ASM__


/*-------------------------------------------------------------------------
 *   Interrupt
 *-------------------------------------------------------------------------*/

IEA DEFINE 0xA7 /* Interrupt Enable (2nd) */
IE DEFINE 0xA8 /* Interrupt Enable */
IE_EX0 DEFINE 0xA8.0
IE_ET0 DEFINE 0xA8.1
IE_EX1 DEFINE 0xA8.2
IE_ET1 DEFINE 0xA8.3
IE_ES DEFINE 0xA8.4
IE_ET2 DEFINE 0xA8.5
IE_EA DEFINE 0xA8.7
IPA DEFINE 0xB7 /* Interrupt Priority (2nd) */
IP DEFINE 0xB8 /* Interrupt Priority */
IP_PX0 DEFINE 0xB8.0
IP_PT0 DEFINE 0xB8.1
IP_PX1 DEFINE 0xB8.2
IP_PT1 DEFINE 0xB8.3
IP_PS DEFINE 0xB8.4
IP_PT2 DEFINE 0xB8.5

/*-------------------------------------------------------------------------
 *   I2C Bus
 *-------------------------------------------------------------------------*/

S1SETUP DEFINE 0xD1 /* DDC I2C (S1) Setup */
S2SETUP DEFINE 0xD2 /* I2C (S2) Setup */
S1CON DEFINE 0xD8 /* DDC I2C Control Reg */
S1CON_CR0 DEFINE 0xD8.0
S1CON_CR1 DEFINE 0xD8.1
S1CON_AA DEFINE 0xD8.2
S1CON_ADDR DEFINE 0xD8.3
S1CON_STO DEFINE 0xD8.4
S1CON_STA DEFINE 0xD8.5
S1CON_ENI1 DEFINE 0xD8.6
S1CON_CR2 DEFINE 0xD8.7
S1STA DEFINE 0xD9 /* DDC I2C Status */
S2CON DEFINE 0xDC /* I2C Bus Control Reg */
S2STA DEFINE 0xDD /* I2C Bus Status */
S2ADR DEFINE 0xDF /* I2C address */

/*-------------------------------------------------------------------------
 *   USB
 *-------------------------------------------------------------------------*/

USCL DEFINE 0xE1 /* 8-bit Prescaler for USB logic */
UDT1 DEFINE 0xE6 /* USB Endpt1 Data Xmit */
UDT0 DEFINE 0xE7 /* USB Endpt0 Data Xmit */
UISTA DEFINE 0xE8 /* USB Interrupt Status */
UISTA_RESUMF DEFINE 0xE8.0
UISTA_EOPF DEFINE 0xE8.1
UISTA_RXD1F DEFINE 0xE8.2
UISTA_RXD0F DEFINE 0xE8.3
UISTA_TXD0F DEFINE 0xE8.4
UISTA_RSTF DEFINE 0xE8.5
UISTA_SUSPND DEFINE 0xE8.7
UIEN DEFINE 0xE9 /* USB Interrupt Enable */
UCON0 DEFINE 0xEA /* USB Endpt0 Xmit Control */
UCON1 DEFINE 0xEB /* USB Endpt1 Xmit Control */
UCON2 DEFINE 0xEC /* USB Control Register */
USTA DEFINE 0xED /* USB Endpt0 Status */
UADR DEFINE 0xEE /* USB Address Register */
UDR0 DEFINE 0xEF /* USB Endpt0 Data Recv */

/*-------------------------------------------------------------------------
 *   I/O Port
 *-------------------------------------------------------------------------*/

P0 DEFINE 0x80 /* Port 0 */
P0_P00 DEFINE 0x80.0
P0_P01 DEFINE 0x80.1
P0_P02 DEFINE 0x80.2
P0_P03 DEFINE 0x80.3
P0_P04 DEFINE 0x80.4
P0_P05 DEFINE 0x80.5
P0_P06 DEFINE 0x80.6
P0_P07 DEFINE 0x80.7
P1 DEFINE 0x90 /* Port 1 */
P1_P10 DEFINE 0x90.0
P1_P11 DEFINE 0x90.1
P1_P12 DEFINE 0x90.2
P1_P13 DEFINE 0x90.3
P1_P14 DEFINE 0x90.4
P1_P15 DEFINE 0x90.5
P1_P16 DEFINE 0x90.6
P1_P17 DEFINE 0x90.7
P1SFS DEFINE 0x91 /* Port 1 Select Register */
P3SFS DEFINE 0x93 /* Port 3 Select Register */
P4SFS DEFINE 0x94 /* Port 4 Select Register */
P2 DEFINE 0xA0 /* Port 2 */
P2_P20 DEFINE 0xA0.0
P2_P21 DEFINE 0xA0.1
P2_P22 DEFINE 0xA0.2
P2_P23 DEFINE 0xA0.3
P2_P24 DEFINE 0xA0.4
P2_P25 DEFINE 0xA0.5
P2_P26 DEFINE 0xA0.6
P2_P27 DEFINE 0xA0.7
P3 DEFINE 0xB0 /* Port 3 */
P3_P30 DEFINE 0xB0.0
P3_P31 DEFINE 0xB0.1
P3_P32 DEFINE 0xB0.2
P3_P33 DEFINE 0xB0.3
P3_P34 DEFINE 0xB0.4
P3_P35 DEFINE 0xB0.5
P3_P36 DEFINE 0xB0.6
P3_P37 DEFINE 0xB0.7
P4 DEFINE 0xC0 /* New Port 4 */
P4_P40 DEFINE 0xC0.0
P4_P41 DEFINE 0xC0.1
P4_P42 DEFINE 0xC0.2
P4_P43 DEFINE 0xC0.3
P4_P44 DEFINE 0xC0.4
P4_P45 DEFINE 0xC0.5
P4_P46 DEFINE 0xC0.6
P4_P47 DEFINE 0xC0.7

/*-------------------------------------------------------------------------
 *   PWM
 *-------------------------------------------------------------------------*/

PWMCON DEFINE 0xA1 /* PWM Control Polarity */
PWM1 DEFINE 0xA3 /* PWM1 Output Duty Cycle */
PWM2 DEFINE 0xA4 /* PWM2 Output Duty Cycle */
PWM3 DEFINE 0xA5 /* PWM3 Output Duty Cycle */
PWM4P DEFINE 0xAA /* PWM 4 Period */
PWM4W DEFINE 0xAB /* PWM 4 Pulse Width */

/*-------------------------------------------------------------------------
 *   Serial I/O
 *-------------------------------------------------------------------------*/

SCON DEFINE 0x98 /* Serial Control Register */
SCON_RI DEFINE 0x98.0
SCON_TI DEFINE 0x98.1
SCON_RB8 DEFINE 0x98.2
SCON_TB8 DEFINE 0x98.3
SCON_REN DEFINE 0x98.4
SCON_SM2 DEFINE 0x98.5
SCON_SM1 DEFINE 0x98.6
SCON_SM0 DEFINE 0x98.7
SBUF DEFINE 0x99 /* Serial Buffer */
SCON2 DEFINE 0x9A /* 2nd UART Ctrl Register */
SBUF2 DEFINE 0x9B /* 2nd UART Serial Buffer */

/*-------------------------------------------------------------------------
 *   Watchdog timer
 *-------------------------------------------------------------------------*/

WDRST DEFINE 0xA6 /* Watch Dog Reset */
WDKEY DEFINE 0xAE /* Watch Dog Key Register */

/*-------------------------------------------------------------------------
 *   System Management
 *-------------------------------------------------------------------------*/

PCON DEFINE 0x87 /* Power Ctrl */
PWM0 DEFINE 0xA2 /* Output Duty Cycle */
PSCL0L DEFINE 0xB1 /* Prescaler 0 Low (8-bit) */
PSCL0H DEFINE 0xB2 /* Prescaler 0 High (8-bit) */
PSCL1L DEFINE 0xB3 /* Prescaler 1 Low (8-bit) */
PSCL1H DEFINE 0xB4 /* Prescaler 1 High (8-bit) */
RAMBUF DEFINE 0xD4 /* DDC Ram Buffer */
DDCDAT DEFINE 0xD5 /* DDC Data xmit register */
DDCADR DEFINE 0xD6 /* Addr pointer register */
DDCCON DEFINE 0xD7 /* DDC Control Register */
S1DAT DEFINE 0xDA /* Data Hold Register */
S1ADR DEFINE 0xDB /* DDC I2C address */
S2DAT DEFINE 0xDE /* Data Hold Register */

/*-------------------------------------------------------------------------
 *   Timer
 *-------------------------------------------------------------------------*/

TCON DEFINE 0x88 /* Timer / Cntr Control */
TCON_IT0 DEFINE 0x88.0
TCON_IE0 DEFINE 0x88.1
TCON_IT1 DEFINE 0x88.2
TCON_IE1 DEFINE 0x88.3
TCON_TR0 DEFINE 0x88.4
TCON_TF0 DEFINE 0x88.5
TCON_TR1 DEFINE 0x88.6
TCON_TF1 DEFINE 0x88.7
TMOD DEFINE 0x89 /* Timer / Cntr Mode Control */
TL0 DEFINE 0x8A /* Timer 0 Low */
TL1 DEFINE 0x8B /* Timer 1 Low */
TH0 DEFINE 0x8C /* Timer 0 High */
TH1 DEFINE 0x8D /* Timer 1 High */
T2CON DEFINE 0xC8 /* Timer 2 Control */
T2CON_CP_RL2 DEFINE 0xC8.0
T2CON_C_T2 DEFINE 0xC8.1
T2CON_TR2 DEFINE 0xC8.2
T2CON_EXEN2 DEFINE 0xC8.3
T2CON_TCLK DEFINE 0xC8.4
T2CON_RCLK DEFINE 0xC8.5
T2CON_EXF2 DEFINE 0xC8.6
T2CON_TF2 DEFINE 0xC8.7
T2MOD DEFINE 0xC9 /* Timer 2 Mode */
RCAP2L DEFINE 0xCA /* Timer 2 Reload low */
RCAP2H DEFINE 0xCB /* Timer 2 Reload High */
TL2 DEFINE 0xCC /* Timer 2 Low byte */
TH2 DEFINE 0xCD /* Timer 2 High byte */

/*-------------------------------------------------------------------------
 *   Analog to Digital Converter (ADC)
 *-------------------------------------------------------------------------*/

ASCL DEFINE 0x95 /* 8-bit Prescaler for ADC clock */
ADAT DEFINE 0x96 /* ADC Data Register */
ACON DEFINE 0x97 /* ADC Control Register */

#endif /* __IAR_SYSTEMS_ASM__*/
#endif /* IOUPSD3254A_H */
