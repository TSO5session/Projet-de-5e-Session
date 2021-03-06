#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo1\\Programme\\CLEcran.cpp"
// **************************CLEcran.cpp
// Auteur:      Vincent Chouinard
// Date:        13 fevrier 2014
// Version :    1.0
//
// vLcdAffCar      ---> Affiche un caracter (a-z,A-Z0-9)
// vLcdClr         ---> Efface l'ecran
// vLcdPoscurC0L1  ---> Positionne le curseur
// vLcdInit        ---> Initialise l'ecran
// vDelaisEcran    ---> Delais a tout faire
// vLcdAffChaine   ---> Affiche un string de "Texte"
// vLcdAffEcran    ---> Pour afficher des menus
// vLcdAffCarHex   ---> Pour afficher un caracter en HEX
// vLcdCarGen      ---> Pour creer des caracteres customs
// vHexToAscii2    ---> Pour transformer l'ASCII en HEX
// vLcdBusy        ---> Busy Polling
//
// Compilateur: IAR 8.2 && Keil 4.79.9
//
// Description: Fichier de definitions pour utiliser un ecran LCD
//
// *****************************************************************************
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo1\\Programme\\CLEcran.h"
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
// void vLCDDisplayCarac(UC ucCaractere);
// void vLCDDisplayCarac(char cCaractere);
//
// void vLCDDisplayCaracChain(const UC *ucpMessage);
// void vLCDDisplayCaracChain(const char *cpMessage);
//
// void vHexToASCII(UC ucHexCar, UC *ucpHi, UC *ucpLo);
// void vLCDDisplayHexCarac(UC ucHexCar);
//
// void vLCDDisplayScreen(const UC *ucpEcran);
// void vLCDBusy(void);
// void vDelaiLCD(USI uiDelai);
//
// *****************************************************************************
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo1\\Programme\\_DeclarationGenerale.h"
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
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo1\\Programme\\ConversionKeilToIAR.h"
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

#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo1\\Programme\\TypeCible.h"
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




#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo1\\Programme\\iouPSD3254A.h"
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
#line 694 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo1\\Programme\\iouPSD3254A.h"

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

#line 28 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo1\\Programme\\TypeCible.h"



//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
#line 14 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo1\\Programme\\ConversionKeilToIAR.h"




// *****************************************************************************
// DEFINITION DES  MODELES DE MEMOIRE
// *****************************************************************************






// *****************************************************************************
#line 100 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo1\\Programme\\ConversionKeilToIAR.h"
// *****************************************************************************

// *****************************************************************************

// Interruption activation






// Interruption priorite




// Interruption niveau activite.












 // #define ES0 IE_bit.ES
 // #define ES0 IE_bit.ES




#line 141 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo1\\Programme\\ConversionKeilToIAR.h"

#line 148 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo1\\Programme\\ConversionKeilToIAR.h"



#line 159 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo1\\Programme\\ConversionKeilToIAR.h"

#line 168 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo1\\Programme\\ConversionKeilToIAR.h"

#line 177 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo1\\Programme\\ConversionKeilToIAR.h"




// S2STA

#line 191 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo1\\Programme\\ConversionKeilToIAR.h"

// S2CON

#line 204 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo1\\Programme\\ConversionKeilToIAR.h"

//S1DAT DEFINE 0xDA /* Data Hold Register */
//S1ADR DEFINE 0xDB /* DDC I2C address */
//S2DAT DEFINE 0xDE /* Data Hold Register */





// *****************************************************************************

//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX

#line 17 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo1\\Programme\\_DeclarationGenerale.h"




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

#line 77 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo1\\Programme\\_DeclarationGenerale.h"

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
#line 28 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo1\\Programme\\CLEcran.h"
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo1\\Programme\\CLInOutBase.h"
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
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo1\\Programme\\_DeclarationGenerale.h"
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
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo1\\Programme\\ConversionKeilToIAR.h"
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



#line 215 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo1\\Programme\\ConversionKeilToIAR.h"
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX

#line 17 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo1\\Programme\\_DeclarationGenerale.h"


#line 139 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo1\\Programme\\_DeclarationGenerale.h"
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
#line 12 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo1\\Programme\\CLInOutBase.h"









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

#line 29 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo1\\Programme\\CLEcran.h"









class CLEcran : public CLInOutBase
{
public:
   CLEcran(void);
   CLEcran(USI uiAdresse);
  ~CLEcran(void);

   void vLCDClr              (void);
   void vLCDInit             (void);
   void vLCDCursor           (UC   ucCol, UC ucLine);
   void vLCDDisplayCarac     (UC   ucCaractere);
   void vLCDDisplayCarac     (char cCaractere);

   void vHexToASCII          (UC   ucHexCar,   UC *ucpHi,      UC *ucpLo);
   void vHexToASCII          (USI  uiHexCar,   UC *ucpHiOctHi, UC *ucpLoOctHi,
                              UC  *ucpHiOctLo, UC *ucpLoOctLo);

   void vLCDDisplayHexCarac  (UC          ucHexCar);
   void vLCDDisplayHexCarac  (USI         uiHexCar);
   void vLCDDisplayCaracChain(const UC   *ucpMessage);
   void vLCDDisplayCaracChain(const char *cpMessage);
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
#line 24 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\Prog\\Labo1\\Programme\\CLEcran.cpp"
// *****************************************************************************
//                            LES CONSTRUCTEURS
// *****************************************************************************
CLEcran :: CLEcran(void)
{
uiAdresseEcran = 0xF800;
vLCDInit();
}

CLEcran :: CLEcran(USI uiAdresse)
{
uiAdresseEcran = uiAdresse;
vLCDInit();
}

// *****************************************************************************
//                            LE DESTRUCTEUR
// *****************************************************************************
CLEcran :: ~CLEcran(void)
{
vLCDClr();
}

// **********************FONCTION: NomDeLaFonction()**************************
//
// DESCRIPTION: Positionne le curseur d'ecriture a l'endroit sp�cifie par
//              la fonction appelante
//
// INCLUDE: <_DeclarationGenerale.h>
//          "CLEcran.h"
//
// PROTOTYPE:           void vLcdPoscurC0L1(UC,UC)
//
// PROCEDURE D'APPEL:   vLcdPoscurC0L1(ucCol,ucLigne)
//
// PARAMETRE D'ENTREE:  ucCol   ---> Positionne la colone
//                      ucLigne ---> Positionne la ligne
//
// PARAMETRE DE SORTIE: AUCUN
//
// EXEMPLE: vLcdPoscurC0L1(0,1) ---> Met le curseur au debut de l'ecran
//
// Auteur:              Vincent Chouinard
// Date:                22 mars 2014   (Version 1.0)
// Modification:
// *****************************************************************************
void CLEcran :: vDelaiLCD(USI uiDelai)
{
USI i;
for(i = 0;i <= uiDelai; i++);
}

void CLEcran :: vLCDBusy(void)
{
while(ucIn(uiAdresseEcran + 1) & 0x80);
}

void CLEcran :: vLCDClr(void)
{
vLCDBusy();
vOut(uiAdresseEcran + 0, 0x01);
}

void CLEcran :: vLCDInit(void)
{
USI i;
for(i = 0; i <= 3; i++)    //Faire 3 fois
  {
   vDelaiLCD(10000);                  //Attendre la stabilisation des parametres
   vOut(uiAdresseEcran + 0,0x38);
  }

vLCDBusy();vOut(uiAdresseEcran + 0,0x38); // Attente du Busy Flag
vLCDBusy();vOut(uiAdresseEcran + 0,0x01); // Attente du Busy Flag
vLCDBusy();vOut(uiAdresseEcran + 0,0x0C); // Attente du Busy Flag
vLCDBusy();vOut(uiAdresseEcran + 0,0x06); // Attente du Busy Flag
}

// **********************FONCTION: NomDeLaFonction()**************************
//
// DESCRIPTION: Positionne le curseur d'ecriture a l'endroit sp�cifie par
//              la fonction appelante
//
// INCLUDE: <_DeclarationGenerale.h>
//          "CLEcran.h"
//
// PROTOTYPE:           void vLcdPoscurC0L1(UC,UC)
//
// PROCEDURE D'APPEL:   vLcdPoscurC0L1(ucCol,ucLigne)
//
// PARAMETRE D'ENTREE:  ucCol   ---> Positionne la colone
//                      ucLigne ---> Positionne la ligne
//
// PARAMETRE DE SORTIE: AUCUN
//
// EXEMPLE: vLcdPoscurC0L1(0,1) ---> Met le curseur au debut de l'ecran
//
// Auteur:              Vincent Chouinard
// Date:                22 mars 2014   (Version 1.0)
// Modification:
// *****************************************************************************
void CLEcran :: vLCDCursor(UC ucCol, UC ucLine)
{
UC ucPosition;
switch(ucLine)
  {
   case 1:                       //Si ligne 1 choisi
      ucPosition = 0x00 + ucCol; //Curseur sur ligne 1 (1,Y)
   break;

   case 2:                       //Si ligne 2 choisi
      ucPosition = 0x40 + ucCol; //Curseur sur ligne 2 (2,Y)
   break;

   case 3:                       //Si ligne 3 choisi
      ucPosition = 0x14 + ucCol; //Curseur sur ligne 3 (3,Y)
   break;

   case 4:                       //Si ligne 4 choisi
      ucPosition = 0x54 + ucCol; //Curseur sur ligne 4 (4,Y)
   break;

   default:                      //Sinon
      ucPosition = 0x00 + ucCol; //Curseur � position initial (0,0)
   break;
  }

ucPosition = ucPosition | 0x80; //Definition du registre du curseur
vLCDBusy();                                   //Attente du Flag Busy
vOut(uiAdresseEcran+0, ucPosition); //Envoi de la commande
}

void CLEcran :: vLCDDisplayCarac(UC ucCaractere)
{
vLCDBusy();
vOut(uiAdresseEcran+2, ucCaractere);
}

void CLEcran :: vLCDDisplayCarac(char cCaractere)
{
vLCDBusy();
vOut(uiAdresseEcran+2, cCaractere);
}

void CLEcran :: vHexToASCII(UC ucHexCar, UC *ucpHi, UC *ucpLo)
{
UC ucTemp;
ucTemp = ucHexCar;
*ucpHi = ucTemp   >> 4;
*ucpLo = ucHexCar & 0x0F;

if(*ucpHi <= 9)             //SI MSB est chiffe
  {
   *ucpHi = *ucpHi + 0x30;  //Convertion hexa a ASCII (Chiffre)
  }
else                        //SINON
  {
   *ucpHi = *ucpHi + 0x37;  //Convertion hexa a ASCII (Lettre)
  }

if(*ucpLo <= 9)             //SI LSB est chiffre
  {
   *ucpLo = *ucpLo + 0x30;  //Convertion hexa a ASCII (Chiffre)
  }
else                        //SINON
  {
   *ucpLo = *ucpLo + 0x37;  //Convertion hexa a ASCII (Lettre)
  }
}

void CLEcran :: vHexToASCII(USI uiHexCar, UC *ucpHiOctHi, UC *ucpLoOctHi,
                                          UC *ucpHiOctLo, UC *ucpLoOctLo)
{
*ucpHiOctHi = (uiHexCar >> 12) & 0x0F;
*ucpLoOctHi = (uiHexCar >> 8 ) & 0x0F;
*ucpHiOctLo = (uiHexCar >> 4 ) & 0x0F;
*ucpLoOctLo =  uiHexCar        & 0x0F;

if(*ucpHiOctHi <= 9)                  //SI MSB est chiffe
  {
   *ucpHiOctHi = *ucpHiOctHi + 0x30;  //Convertion hexa a ASCII (Chiffre)
  }
else                                  //SINON
  {
   *ucpHiOctHi = *ucpHiOctHi + 0x37;  //Convertion hexa a ASCII (Lettre)
  }

if(*ucpLoOctHi <= 9)                  //SI LSB est chiffre
  {
   *ucpLoOctHi = *ucpLoOctHi + 0x30;  //Convertion hexa a ASCII (Chiffre)
  }
else                                  //SINON
  {
   *ucpLoOctHi = *ucpLoOctHi + 0x37;  //Convertion hexa a ASCII (Lettre)
  }

if(*ucpHiOctLo <= 9 )                 //SI MSB est chiffre
  {
   *ucpHiOctLo = *ucpHiOctLo + 0x30;  //Convertion hexa a ASCII (Chiffre)
  }
else                                  //SINON
  {
   *ucpHiOctLo = *ucpHiOctLo + 0x37;  //Convertion hexa a ASCII (Lettre)
  }

if(*ucpLoOctLo <= 9 )                 //SI LSB est chiffre
  {
   *ucpLoOctLo = *ucpLoOctLo + 0x30;  //Convertion hexa a ASCII (Chiffre)
  }
else                                  //SINON
  {
   *ucpLoOctLo = *ucpLoOctLo + 0x37;  //Convertion hexa a ASCII (Lettre)
  }
}

void CLEcran :: vLCDDisplayHexCarac(UC ucHexCar)
 {
  UC ucHi;UC ucLo;

  vHexToASCII(ucHexCar, &ucHi, &ucLo); //Conversion de Hexadecimal a ASCII
  vLCDDisplayCarac(ucHi);              //Affiche MSB
  vLCDDisplayCarac(ucLo);              //Affiche LSB
 }

void CLEcran :: vLCDDisplayHexCarac(USI uiHexCar)
{
UC ucHiOctHi;
UC ucLoOctHi;
UC ucHiOctLo;
UC ucLoOctLo;

vHexToASCII(uiHexCar, &ucHiOctHi, &ucLoOctHi, &ucHiOctLo, &ucLoOctLo);

vLCDDisplayCarac(ucHiOctHi); //Affiche MSB OctHI
vLCDDisplayCarac(ucLoOctHi); //Affiche LSB OctHI
vLCDDisplayCarac(ucHiOctLo); //Affiche MSB OctLO
vLCDDisplayCarac(ucLoOctLo); //Affiche LSB OctLO
}

void CLEcran :: vLCDDisplayCaracChain(const UC *ucpMessage)
{
while(*ucpMessage != 0x00)
  {
   vLCDDisplayCarac(*ucpMessage);
   ucpMessage++;
  }
}

void CLEcran ::vLCDDisplayCaracChain (const char *cpMessage)
{
while(*cpMessage != 0x00)
  {
   vLCDDisplayCarac(*cpMessage);
   cpMessage++;
  }
}

void CLEcran :: vLCDDisplayScreen(const UC *ucpEcran)
{
UC ucLigne;
for(ucLigne = 1; ucLigne <= 4; ucLigne++)
  {
   vLCDCursor(1,ucLigne);
   vLCDDisplayCaracChain(ucpEcran);
   ucpEcran = ucpEcran + 1;
  }
}

void CLEcran :: vLCDDisplayEtatPort(UC ucEtatPort)
{
for(UC i = 0; i < 8; i++)
  {
   if((ucEtatPort & 0x80) == 0x80)
     {
      vLCDDisplayCarac('1');
     }
   else
     {
      vLCDDisplayCarac('0');
     }
   ucEtatPort = ucEtatPort << 1;
  }
}

void CLEcran :: vLCDDisplayFloat(float fInputFloat)
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
         vLCDDisplayCarac('0');
      break;

      case 1:
         vLCDDisplayCarac('1');
      break;

      case 2:
         vLCDDisplayCarac('2');
      break;

      case 3:
         vLCDDisplayCarac('3');
      break;

      case 4:
         vLCDDisplayCarac('4');
      break;

      case 5:
         vLCDDisplayCarac('5');
      break;

      case 6:
         vLCDDisplayCarac('6');
      break;

      case 7:
         vLCDDisplayCarac('7');
      break;

      case 8:
         vLCDDisplayCarac('8');
      break;

      case 9:
         vLCDDisplayCarac('9');
      break;
     }
   }

vLCDDisplayCarac('.'); // Affiche la satane virgule

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
         vLCDDisplayCarac('0');
      break;

      case 1:
         vLCDDisplayCarac('1');
      break;

      case 2:
         vLCDDisplayCarac('2');
      break;

      case 3:
         vLCDDisplayCarac('3');
      break;

      case 4:
         vLCDDisplayCarac('4');
      break;

      case 5:
         vLCDDisplayCarac('5');
      break;

      case 6:
         vLCDDisplayCarac('6');
      break;

      case 7:
         vLCDDisplayCarac('7');
      break;

      case 8:
         vLCDDisplayCarac('8');
      break;

      case 9:
         vLCDDisplayCarac('9');
      break;
     }
  }
}
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
