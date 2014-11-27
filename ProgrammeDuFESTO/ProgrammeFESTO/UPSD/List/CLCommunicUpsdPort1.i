#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\CLCommunicUpsdPort1.cpp"
//**********************  Fichier: CLCommunic.cpp
//  Description : Fonctions necessaire pour communiquer avec le port serie:
//
//
//CLCommunic()                                         Constructeur par defaut
//CLCommunic(UC ucLongBuf, UC ucLongTrame, UI uiBaud)  Construct initialisateur
//~CLCommunic()                                        Destructeur
//
//UC ucInitLongTrame(UC ucLong)               Pour initialiser longueur trame
//UC static ucLireNbCaractRecu()              Fct pour lire nombre de caractere recu
//UC ucLireEtatTrame()                        Fct pour lire l'etat de la trame
//char *ucpLireTrame()                        Fct qui retourne adresse du debut lecture
//vend(UC ucCar)                              Fct pour transmettre un caractere
//SendNumber(UI uiChiffreAAfficher)           Fct pour transmettre un chiffre
//SendString(char const *ucpMessage)          Fct pour transmettre chaine de caractere
//void vInitBaudRate(UI uiBaud)               Fct pour intialiser le baudrate et timer
//__interrupt static void vInteruptSerial();  Fct pour recevoir un caractere
//UC ucValideTrame()                          Fct pour valider une trame
//
//  Composition : aucune
//  Heritage    : aucun
//
//  Programmeur : Vincent Chouinard
//  Cours       : 247-436
//
//  Date        : 10 avril 2014
//                                                                           //
//  Compilateur : IAR 8.1
//                                                                           //
//  Modification:                                                            //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////
#line 1 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\CLCommunicUpsdPort1.h"
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
typedef signed   long      L;
typedef signed   char      C;
typedef unsigned long      UL;
typedef unsigned char      UC;
typedef unsigned int       UI;
typedef signed   short int SI;
typedef unsigned short int USI;
typedef signed   char      INT8;
typedef unsigned char      UINT8;
typedef unsigned short int UINT16;
typedef signed   long      INT32;
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

#line 37 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\CLCommunicUpsdPort1.h"
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

#line 39 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\CLCommunicUpsdPort1.h"






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
















#line 34 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\CLCommunicUpsdPort1.cpp"
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

#line 35 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\CLCommunicUpsdPort1.cpp"

 ///// Initialise les variables statiques.
UC    CLCommunic :: ucEtatTrame       = 0      ; // Trame incomplete.
UC    CLCommunic :: ucNbCaractRecu    = 0              ; // Nombre de caractere recu = 0
UC    CLCommunic :: ucLongueurTrame   = 4  ; // Initialise les longueur du
UC    CLCommunic :: ucLongueurTampon  = 12 ; // buffer et trame.
UC    CLCommunic :: ucCaractereRecu   = 0           ;
UC    CLCommunic :: ucEtatReception   = 0        ;
char *CLCommunic :: cpDebutTrame      = 0           ; // Initialise lse pointeur a NULL.
char *CLCommunic :: cpFinTrame        = 0           ;
char *CLCommunic :: cptrEcriture      = 0           ;
char *CLCommunic :: cptrLecture       = 0           ;
char *CLCommunic :: cTabCaractereRecu = 0           ;


//*****************************************************************************
// Nom de la fct       : CLCommunic(void)
// Description         : Constructeur qui permet d'initialiser par defaut le port
//                     : serie du micro controleur a  9600 bdr, un tampon de 12
//                     : et une trame a 4 characteres. Initialise les differents
//                     : pointeurs au debut et la la fin du tampon.
//
// INCLUDE             :#include "_TypeCible.h", "CLCommunic.h"
// Prototype           : CLCommunic(void);
//
//
// Parametre d'entree  : Aucune
//
// Parametre de sortie : Aucune
//
// Procedure appelees  : vInitBaudRate(),
//
// Exemple d'appel     : class CLCommunic clCommunic();
//
// Fait par            : Vincent Chouinard
// Date                : 10 avril 2014
// Revision            : A
// Modification        :
//*****************************************************************************
CLCommunic::CLCommunic(void)
{
 cTabCaractereRecu = new char[12]; // Definit tableau de longueur
                                               // LONGUEURTAMPON.
 ucLongueurTrame  = 4;             // Definit longueur de la trame.
 ucLongueurTampon = 12;            // Definit longueur tampon.

 cpDebutTrame = &cTabCaractereRecu[0];                  // Pointeur sur debut tampon.
 cpFinTrame   = &cTabCaractereRecu[(12-1)]; // Pointeur sur fin tampon
 cptrEcriture = &cTabCaractereRecu[0];                  // Pointeur ecriture au debut.
 cptrLecture  = &cTabCaractereRecu[0];                  // Pointeur lecture au debut.

 vInitBaudRate(9600);                                   // Initialise le port serie.
}


//*****************************************************************************
// Nom de la fct        : CLCommunic
// Description          : Constructeur qui permet d'initialiser  le port
//                        serie du micro controleur a  la vitesse voulue, un tampon
//                        de taille dynamique et la longueur de la trame.
//                        Initialise les differents pointeurs au debut et la la fin
//                        du tampon.
//
// INCLUDE              : #include "_TypeCible.h", "CLCommunic.h"
// Prototype            : CLCommunic(UC ucLongBuf, UC ucLongTrame, UI uiBaud);
//
//
// Parametre d'entree   : ucLongBuf pour longueur du trableau
//                        ucLongTrame pour longueur trame
//                        uiBaud pour la vitesse du port serie
//
// Parametre de sortie  : Aucune
//
// Procedure appelees   : vInitBaudRate(), ucInitLongTrame()
//
// Exemple d'appel      : class CLCommunic clCommunic();
//
// Fait par             : Vincent Chouinard
// Date                 : 10 avril 2014
// Revision             : A
// Modification         :
//*****************************************************************************
CLCommunic :: CLCommunic(UC ucLongBuf, UC ucLongTrame, UI uiBaud)
{
 cTabCaractereRecu = new char[ucLongBuf]; // Initialise un tableau de longueur
                                          // voulue.
 ucLongueurTampon = ucLongBuf;            // Longueur tampon = ucLongBuf.
 ucInitLongTrame(ucLongTrame);            // Verifie si longueur trame
                                          // < longueur tampon.
 cpDebutTrame = &cTabCaractereRecu[0];    // Pointeur pour debut tampon.
 cpFinTrame   = &cTabCaractereRecu[(ucLongBuf-1)];// Pointeur pour fin tampon.
 cptrEcriture = &cTabCaractereRecu[0];    // Pointeur ecriture et lecture au
 cptrLecture  = &cTabCaractereRecu[0];    // debut du tampon.
 vInitBaudRate(uiBaud);                   // Initialise la vitesse de
                                          // communication.
}

//*****************************************************************************
// Nom de la fct        :~CLCommunic
// Description          : Desctructeur qui libert la memoire pris par le tampon.
//
// INCLUDE              : #include "_TypeCible.h", "CLCommunic.h"
// Prototype            :~CLCommunic(void);
//
//
// Parametre d'entree   : aucun
//
// Parametre de sortie  : Aucun
//
// Procedure appelees   : aucun
//
// Exemple d'appel      :
//
// Fait par             : Vincent Chouinard
// Date                 : 10 avril 2014
// Revision             : A
// Modification         :
//*****************************************************************************
CLCommunic :: ~CLCommunic(void)
{
if(cTabCaractereRecu)              // Verification pour s'assurer que le
  {                                // pointeur n'a pas deja ete libere
   delete cTabCaractereRecu;       // Libert la memoire prise par le tampon.
   cTabCaractereRecu = 0;       // Pour mettre a 0 le pointeur.
  }
}

//*****************************************************************************
// Nom de la fct:   ucInitLongTrame
// Description:     Verifie si la trame entree est inferieure au tampon
//                  sinon la longueur de la trame = a celle du buffer.
//
// INCLUDE:        #include "_TypeCible.h", "CLCommunic.h"
// Prototype:      UC ucInitLongTrame(UC ucLong);
//
//
// Parametre d'entree: ucLong longueur voulue
//
// Parametre de sortie: ucValide pour valide ou non la taille
//
// Procedure appelees: aucun
//
// Exemple d'appel:  ucInitLongTrame(ucLongTrame);
//
// Fait par: Vincent Chouinard
// Date:            10 avril 2014
// Revision :       A
// Modification :
//*****************************************************************************

UC CLCommunic :: ucInitLongTrame(UC ucLong)
{
UC ucValide;                           // Varaible pour valider ou non.

if(ucLong <= ucLongueurTampon)         // Si longueur trame voulue <= a la longueur
  {                                    // du tampon.
   ucLongueurTrame = ucLong;           // longueur trame = longueur trame voulue.
   ucValide = 1;                    // ucValide = Vrai.
  }

if(ucLong > ucLongueurTampon)          // Si longueur trame voulue > a la longueur
  {                                    // du tampon.
   ucLongueurTrame = ucLongueurTampon; // longueur trame = longueur tampon.
   ucValide = 0;                    // ucValide = Faux.
  }

return(ucValide);                      // Retourne etat de ucValide.
}


//*****************************************************************************
// Nom de la fct:   ucValideTrame
// Description:     Valide la trame recue, additionne tous les caracteres
//                  recues et commpare avec le checksum.
//
// INCLUDE:        #include "_TypeCible.h", "CLCommunic.h"
// Prototype:      UC ucValideTrame(void);
//
//
// Parametre d'entre: aucun
//
// Parametre de sortie: ucValide pour valide ou non la trame.
//
// Procedure appelees: aucun
//
// Exemple d'appel: if(ucValideTrame() == VRAI)
//
// Fait par: Vincent Chouinard
// Date:            10 avril 2014
// Revision :       A
// Modification :
//*****************************************************************************
UC CLCommunic :: ucValideTrame(void)
{
UC ucValide;               // Variable pour etat valide ou non.
UC ucSomme;                // variable pour la somme des caracteres recus.
ucSomme = 0;               // Initialise la somme a 0.
UC ucBoucle;               // Varialbe pour boucle.

char *cPtrVerification;    // pointeur sur la tramme recu
cPtrVerification = cptrLecture; // Intialise l'adresse du debut de la trame.

ucBoucle = (ucLongueurTrame - 1);         // Pour additionner toutes les valeurs
                                          // sauf le dernier
for(;ucBoucle > 0; ucBoucle--)
  {
   ucSomme = *cPtrVerification + ucSomme; // Additionne le caractere avec somme.
   cPtrVerification ++;                   // Valeur suivante.
  }
                                          // Compare la somme avec le checksum recu.
if(ucSomme == *cPtrVerification)          // Si egal?
  {
   ucValide = 1;                       // Trame correcte.
  }
else                                      // Sinon
  {
   ucValide = 0;                       // Trame incorrecte.
  }

return(ucValide);                         // Retourne valide ou non.
}

//*****************************************************************************
// Nom de la fct:   Send                  Fait par: Vincent Chouinard
// Date:            2 octobre 2013
// Revision :       A
// Modification :
// INCLUDE:         #include "_TypeCible.h", "CLCommunic.h"
// Prototype:       void Send(UC ucCar);
//
// Description:     Fonction qui permet de transmettre un caractere par le port
//                  serie, et on attend que le caractere soit completement
//                  envoye par "polling" avec le flag TI_0.
//
// Parametre d'entree: ucCar: caractere qu'on veut envoyer.
//
//
// Parametre de sortie: aucune
//
// Procedure appelees: aucune.
//
// Exemple d'appel: clCommunic.Send('A')
//*****************************************************************************
void CLCommunic :: Send(UC ucCar)
{
SBUF = ucCar;             // Envoye le caractere dans SBUF0 pour le transmetre sur TX
while(SCON_bit . TI ==0);           // Si le flag TI_0 se met a 1 (termine)
SCON_bit . TI  = 0;                 // Remet le flag a 0.
}



//*****************************************************************************
// Nom de la fct:   SendString
// Description:     Transmet une chaine de caracteres sur le port serie.
//
// INCLUDE:        #include "_TypeCible.h", "CLCommunic.h"
// Prototype:      void SendString(char const *ucpMessage)
//
//
// Parametre d'entre: *ucpMessage pour chaine de caractere.
//
// Parametre de sortie: aucun
//
// Procedure appelees: Send()
//
// Exemple d'appel: clCommunic.SendString("TEST");
//
// Fait par: Vincent Chouinrd
// Date:            10 avril 2014
// Revision :       A
// Modification :
//*****************************************************************************
void CLCommunic :: SendString(char const *ucpMessage)
{
while(*ucpMessage != 0x00)          // Tant qu'on a pas atteint la fin de
  {                                 // la chaine.
   Send(*ucpMessage);     // Transmet le caractere.
   ucpMessage++;                    // Passe au caractere suivant.
  }
}

//*****************************************************************************
// Nom de la fct:   ucLireNbCaractRecu                Fait par: VIncent Chouinard
// Date:            2 octobre 2013
// Revision :       A
// Modification :
// INCLUDE:         #include "_TypeCible.h", "CLCommunic.h"
// Prototype:       UC ucLireNbCaractRecu(void);
//
// Description:     Fonction qui retourne le nombre de caractere recu.
//
//
// Parametre d'entree: aucun
//
//
// Parametre de sortie: ucNombreCaractere: nombre de caractere recu.
//
// Procedure appelees: aucune.
//
// Exemple d'appel: if(ucLireNbCaractRecu() < (ucLongueurTrame -1))
//*****************************************************************************
UC CLCommunic :: ucLireNbCaractRecu(void)
{
return(ucNbCaractRecu);          // Retourne le nombre de caractere recu.
}
//*****************************************************************************
// Nom de la fct:   ucLireEtatTrame                  Fait par: VIncent Chouinard
// Date:            2 octobre 2013
// Revision :       A
// Modification :
// INCLUDE:        #include "_TypeCible.h", "CLCommunic.h"
// Prototype:       UC ucLireEtatTrame(void);
//
// Description:     Fonction qui permet de savoir si une trame est complete.
//
//
// Parametre d'entree: aucun
//
//
// Parametre de sortie: ucEtatTrameRecu: a 1 pour complete et 0 si imcomplete.
//
// Procedure appelees: aucune.
//
// Exemple d'appel:if(ucLireEtatTrame()==TRAMECOMPLET)
//*****************************************************************************
UC CLCommunic :: ucLireEtatTrame(void)
{
return(ucEtatTrame);            // Retourne l'etat de la trame.
}
//*****************************************************************************
// Nom de la fct:   *ucpLireTrame                   Fait par: Vincent Chouinard
// Date:            2 octobre 2013
// Revision :       A
// Modification :
// INCLUDE:         #include "_TypeCible.h", "CLCommunic.h"
// Prototype:       UI *ucpLireTrame(void);
//
// Description:     Fonction qui permet de transmettre l'adresse du tableau
//                  contenant la trame de caractere, et reinitialiser l'etat
//                  de la  trame.
//
// Parametre d'entree: aucun
//
//
// Parametre de sortie: uiTab: adresse du tableau.
//
// Procedure appelees: ucValideTrame()
//
// Exemple d'appel:Send('A')
//*****************************************************************************
char *CLCommunic :: ucpLireTrame(void)
{
char *ucptrLectAEnvoyer;           // Pointeur sur la trame recue.
ucEtatTrame = 0;           // Reinitialise l'etat de la trame.

if(ucValideTrame() == 1)        // Verifie si la trame est valide.
  {                                // Si elle l'est
   ucptrLectAEnvoyer = cptrLecture;// transmet l'adresse du debut de la trame.
  }
else                               // Sinon
  {
   ucptrLectAEnvoyer = 0;       // Ne transmet pas l'adresse du debut de
  }                                // la trame.
return(ucptrLectAEnvoyer);         // Retourne l'adresse du tableau ou NULL.
}
//*****************************************************************************
// Nom de la fct:   vInitBaudRate                  Fait par: Vincent Chouinard
// Date:            2 octobre 2013         version base
//                  10 avril 2014          version avec uPSD.
// Revision :       B
// Modification :
// INCLUDE:         #include "_TypeCible.h", "CLCommunic.h"
// Prototype:       void vInitBaudRate(UI uiBaud);
//
// Description:     Fonction qui permet d' initialiser le port série au
//                  baudrate desire, le timer 1(8 bit auto reload) et
//                  les interuptions necessaire pour communiquer avec
//                  le port serie.
//                  Ajout de la compilation conditionnelle pour choix
//                  de la valeur a mettre dans TH1 selon la cible.
//
// Parametre d'entree: UI uiBaud: pour determine la vitesse du baudrate.
//
//
// Parametre de sortie: aucune
//
// Procedure appelees: aucune.
//
// Exemple d'appel: vInitBaudRate(57600);
//*****************************************************************************
void CLCommunic:: vInitBaudRate(UI uiBaud)
{
SCON = 0x50;         // SM0_0=0
                      // SM1_0=1
                      // SM2_0=0 pour longeur 10 bits et asychrone.
                      // REN_0=1 pour recevoir des caracteres.
TMOD = TMOD | 0x20;   // M1=1
                      // M0=0 pour timer 8bit avec autoreload.
PCON = PCON | 0x80;   // Pour doubler le baudrate (SMOD_0=1;).

#line 464 "C:\\Synchro\\Dropbox\\Travaux\\Automne 2014\\ProjetSession5\\ProgrammeDuFESTO\\ProgrammeFESTO\\CLCommunicUpsdPort1.cpp"



switch(uiBaud)         // switch case pour determiner la valeur en
  {                    // hexa qui faut mettre a TH1 pour avoir la
                  // bonne vitesse du timer pour generer
    /*case 57600:      // le baudrate.
    TH1= 0xFE ;
    break;
    case 38400:        // uPSD ne peut aller a ces vitesses
    TH1= 0xFD;
    break;
    case 19200:
    TH1= 0xF9;
    break;*/
    case 9600:
       TH1= 0xF3;
    break;
    case 4800:
       TH1= 0xE6;
    break;
    case 2400:
       TH1= 0xCC;
    break;
    default:
       TH1= 0xF3;         // Si aucune valeur ne correspond vitesse = 9600 .
    break;
  }


TCON_bit . TR1  = 1;      // Active le timer 1.
IE_bit . ET1  = 0;      // Desactive les interruptions du timer 1.
IE_bit . EA   = 1;      // Active les interruptions.
IE_bit . ES   = 1;      // Active les interruptions du port serie.
SCON_bit . TI = 0;      // Met a 0 le drapeau de la transmision serie.
}

//*****************************************************************************
// Nom de la fct:   vInteruptSerial                  Fait par: VIncent CHouinard
// Date:            2 octobre 2013
//
// Revision :       B
// Modification :   10 avril 2014     conversion pour IAR
//
// INCLUDE:         #include "_TypeCible.h", "CLCommunic.h"
// Prototype:       __interrupt  void CLCommunic:: vInteruptSerial(void);
//
// Description:     Fonction qui permet de recevoir des caracteres par le port
//                  serie, si l'interruption vient de la reception on place
//                  les caracteres lus dans un tableau.
//
// Parametre d'entree: aucun.
//
//
// Parametre de sortie: valeur dans cptrLecture pour lire les caractere recus.
//
// Procedure appelees: ucLireNbCaractRecu(),
//
// Exemple d'appel: aucun
//*****************************************************************************
#pragma vector=0x23  // Interrupt 4 pour interruption serie au vecteur 23
 __interrupt  void CLCommunic:: vInteruptSerial(void)
{
IE_bit . EA = 0;                               // Desactive les interruptions.

if(SCON_bit . RI==1)                           // Interruption cause par la reception?
  {
   if(cptrEcriture > cpFinTrame)      // Si on a atteind la fin du buffer
     {
      cptrEcriture = cpDebutTrame;    // Retourne au debut du tampon.
     }

  *cptrEcriture    = SBUF;  // Lit dans SBUF0 le caractere recu et met dans le tableau.
   ucCaractereRecu = SBUF;
   ucEtatReception = 1;
   cptrEcriture++;           // Increment la position du pointeur d'ecriture.

   if(ucLireNbCaractRecu() < (ucLongueurTrame - 1) )
     {                       // Si le nombre de caractere recu est inferieur a
      ucNbCaractRecu++;      // trame - 1 incremente le nombre de caracteres
     }                       // recus.
   else                      // Si la trame est complete?
     {
      ucNbCaractRecu=0;      // Remet a 0 le compte de caractere.
      ucEtatTrame = 1; // Indique qu'une trame est complete.
      cptrLecture = (cptrEcriture - (ucLongueurTrame));
                             // Le pointeur de lecture = la position
                             // d'ecriture - la longuer de la trame.
     }
   SCON_bit . RI = 0;                 // Reinitialiser le flag de reception.
 }                           // Fin du if(RI_0 = 1)
IE_bit . EA = 1;                      // Reactive les interruptions
}                            // Fin de Interruption.

//*****************************************************************************
// Nom de la fct:   SendNumber
// Description:     Fonction qui permet transmettre  un nombre de 0 a
//                  65000 sur le port serie.
// INCLUDE:       #include "_TypeCible.h", "CLCommunic.h"
// Prototype:     void SendNumber(UI uiChiffreAAfficher);
//
//
// Parametre d'entree: uiChiffreAAfficher pour chiffre a afficher
//
// Parametre de sortie: aucun
//
// Procedure appelees: Send();
//
//
// Exemple d'appel: vLcdAffChiffre(12345)
//
// Fait par: Vincent Chouinard
// Date:            14 novembre 2013
// Revision :       A
// Modification :
//*****************************************************************************
void CLCommunic :: SendNumber(UI uiChiffreAAfficher)
{
UC ucChiffre0; // Declaration des variables
UC ucChiffre1;
UC ucChiffre2;
UC ucChiffre3;
UC ucChiffre4; // isole chaque chiffre du nombre.

ucChiffre0 = ((uiChiffreAAfficher  % 10)    + 0x30);       // Unitee.
ucChiffre1 = (((uiChiffreAAfficher / 10)    % 10) + 0x30); // Dizaine
ucChiffre2 = (((uiChiffreAAfficher / 100)   % 10) + 0x30); // Centaine.
ucChiffre3 = (((uiChiffreAAfficher / 1000)  % 10) + 0x30); // Millier.
ucChiffre4 = ((uiChiffreAAfficher  / 10000) + 0x30);       // Dizaine de mille.

if(ucChiffre4 != 0x30)                 // Si Dizaine de mille  = 0
  {                                    // Ne l'affiche pas
   Send(ucChiffre4);                   // Transmet les Dizaine de mille.
  }

if((ucChiffre4 != 0x30) || (ucChiffre3 != 0x30))// Si les 2 premiers chiffres
  {                                             // sont different de 0.
   Send(ucChiffre3);                            // Transmet les millier.
  }

if((ucChiffre4 != 0x30) || (ucChiffre3 != 0x30)||(ucChiffre2 != 0x30))
  {                                  // Si les 3 1er chiffres sont different
                                     // de 0?
   Send(ucChiffre2);                 // Transmet les centaines.
  }

if((ucChiffre4 != 0x30)||(ucChiffre3 != 0x30)||(ucChiffre2 != 0x30)||(ucChiffre1 != 0x30))
                                  // Si les 4 premier chiffres sont
  {                              // different de 0.
   Send(ucChiffre1);             // Transmet les dizianes.
  }
 Send(ucChiffre0);               // Transmetles unitees.
}

UC CLCommunic :: GetChar(void)
{
ucEtatReception = 0;
return(ucCaractereRecu);
}

UC CLCommunic :: ucLireEtatReception(void)
{
return(ucEtatReception);            // Retourne l'etat de la trame.
}


//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX






