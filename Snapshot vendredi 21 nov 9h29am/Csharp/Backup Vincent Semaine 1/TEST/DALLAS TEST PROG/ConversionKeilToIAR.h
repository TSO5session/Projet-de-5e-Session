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

#include "TypeCible.h"

#ifndef CONVERSIONKEILTOIARH
   #define CONVERSIONKEILTOIARH

// *****************************************************************************
// DEFINITION DES  MODELES DE MEMOIRE
// *****************************************************************************

#define data  __data
#define xdata __xdata
#define code  __code


// *****************************************************************************
#ifdef DALLAS89C450

// Interruption activation
  #define EA            IE_bit.EA
  #define ES0           IE_bit.ES0
  #define ES2           IE_bit.ES1
  #define ET1           IE_bit.ET1
  #define EX0           IE_bit.EX0

// Interruption priorite
  #define LPX0          IP0_bit.LPX0
  #define MPX0          IP1_bit.MPX0

  #define LPS           IP0_bit.LPS0
  #define MPS           IP1_bit.MPS0
  #define LPS2          IP0_bit.LPS1
  #define MPS2          IP1_bit.MPS1

// Interruption niveau activite.
  #define IT0           TCON_bit.IT0
  #define TR1           TCON_bit.TR1

  #define TCLK2         T2CON_bit.TCKL
  #define TRCLK2        T2CON_bit.RCLK
  #define TR2           T2CON_bit.TR2

  #define T2MOD_DCEN    T2MOD_bit.DCEN

  #define SMOD          PCON_bit.SMOD_0
  #define SMOD2         WDCON_bit.SMOD_1

  #define SCON          SCON0
  #define SBUF          SBUF0
  #define RI_0          SCON0_bit.RI_0
  #define TI_0          SCON0_bit.TI_0

  #define SCON2         SCON1
  #define SBUF2         SBUF1
  #define RI_2          SCON1_bit.RI_1
  #define TI_2          SCON1_bit.TI_1

  #define SM0_0         SCON0_bit.SM0_FE_0
  #define SM1_0         SCON0_bit.SM1_0
  #define SM2_0         SCON0_bit.SM2_0
  #define REN_0         SCON0_bit.REN_0

  #define SM0_2         SCON1_bit.SM0_FE_1
  #define SM1_2         SCON1_bit.SM1_1
  #define SM2_2         SCON1_bit.SM2_1
  #define REN_2         SCON1_bit.REN_1

  #define P1_0          P1_bit.P10_T2          // Port 1.0
  #define P1_1          P1_bit.P11_T2EX        // Port 1.1
  #define P1_2          P1_bit.P12_RXD1        // Port 1.2
  #define P1_3          P1_bit.P13_TXD1        // Port 1.3
  #define P1_4          P1_bit.P14_INT2        // Port 1.4
  #define P1_5          P1_bit.P15_INT3        // Port 1.5
  #define P1_6          P1_bit.P16_INT4        // Port 1.6
  #define P1_7          P1_bit.P17_INT5        // Port 1.7

  #define P3_0          P3_bit.P30_RXD0        // Port 3.0
  #define P3_1          P3_bit.P31_TXD0        // Port 3.1
  #define P3_2          P3_bit.P32_INT0        // Port 3.2
  #define P3_3          P3_bit.P33_INT1        // Port 3.3
  #define P3_4          P3_bit.P34_T0          // Port 3.4
  #define P3_5          P3_bit.P35_T1          // Port 3.5
  #define P3_6          P3_bit.P36_WR          // Port 3.6
  #define P3_7          P3_bit.P37_RD          // Port 3.7

  #define SDA           P3_4
  #define SCL           P3_5
#endif // DALLAS89C450
// *****************************************************************************

// *****************************************************************************
#ifdef UPSD3254A
// Interruption activation
  #define EA            IE_bit.EA
  #define ES            IE_bit.ES
  #define ET1           IE_bit.ET1
  #define ES2           IEA_bit.ES2
  #define EX0           IE_bit.EX0

// Interruption priorite
  #define PX0           IP_bit.PX0
  #define PS            IP_bit.PS
  #define PS2           IPA_bit.PS2

// Interruption niveau activite.
  #define IT0           TCON_bit.IT0
  #define TR1           TCON_bit.TR1

  #define TCLK2         T2CON_bit.TCKL
  #define TRCLK2        T2CON_bit.RCLK
  #define TR2           T2CON_bit.TR2

  #define T2MOD_DCEN    T2MOD_bit.DCEN

  #define SBUF0         SBUF
  #define SCON0         SCON

 // #define ES0 IE_bit.ES
 // #define ES0 IE_bit.ES

  #define SMOD          PCON_bit.SMOD
  #define SMOD2         PCON_bit.SMOD1

  #define RI_0          SCON_bit.RI
  #define TI_0          SCON_bit.TI
  #define SM0_0         SCON_bit.SM0
  #define SM1_0         SCON_bit.SM1
  #define SM2_0         SCON_bit.SM2
  #define REN_0         SCON_bit.REN

  #define TI_2          SCON2_bit.TI
  #define RI_2          SCON2_bit.RI
  #define SM0_2         SCON2_bit.SM0
  #define SM1_2         SCON2_bit.SM1
  #define SM2_2         SCON2_bit.SM2
  #define REN_2         SCON2_bit.REN

  #define WATCHDOG_OFF WDKEY = 0x55; // Disable watchdog.

  #define P1_0          P1_bit.P10        // Port 1.0
  #define P1_1          P1_bit.P11        // Port 1.1
  #define P1_2          P1_bit.P12        // Port 1.2
  #define P1_3          P1_bit.P13        // Port 1.3
  #define P1_4          P1_bit.P14        // Port 1.4
  #define P1_5          P1_bit.P15        // Port 1.5
  #define P1_6          P1_bit.P16        // Port 1.6
  #define P1_7          P1_bit.P17        // Port 1.7

  #define P3_0          P3_bit.P30        // Port 3.0
  #define P3_1          P3_bit.P31        // Port 3.1
  #define P3_2          P3_bit.P32        // Port 3.2
  #define P3_3          P3_bit.P33        // Port 3.3
  #define P3_4          P3_bit.P34        // Port 3.4
  #define P3_5          P3_bit.P35        // Port 3.5
  #define P3_6          P3_bit.P36        // Port 3.6
  #define P3_7          P3_bit.P37        // Port 3.7

  #define P4_0          P4_bit.P40        // Port 4.0
  #define P4_1          P4_bit.P41        // Port 4.1
  #define P4_2          P4_bit.P42        // Port 4.2
  #define P4_3          P4_bit.P43        // Port 4.3
  #define P4_4          P4_bit.P44        // Port 4.4
  #define P4_5          P4_bit.P45        // Port 4.5
  #define P4_6          P4_bit.P46        // Port 4.6
  #define P4_7          P4_bit.P47        // Port 4.7

  #define SCL           P3_7
  #define SDA           P3_6

// S2STA
#define SLAVE       S2STA_bit.SLV
#define ACKR        S2STA_bit.ACK_R
#define BLOST       S2STA_bit.Blost
#define BBUSY       S2STA_bit.Bbusy
#define TX_MODE     S2STA_bit.TX_Mode
#define INTRI2C     S2STA_bit.Intr
#define STOPI2C     S2STA_bit.Stop
#define GCALL       S2STA_bit.GC

// S2CON
#define CR0         S2CON_bit.CR0
#define CR1         S2CON_bit.CR1
#define AA          S2CON_bit.AA
#define ADDR        S2CON_bit.ADDR
#define STO         S2CON_bit.STO
#define STA         S2CON_bit.STA
#define EN1         S2CON_bit.EN1
#define CR2         S2CON_bit.CR2
#define EI2C        IEA_bit.EI2C
#define dummy       0xFF

//S1DAT DEFINE 0xDA /* Data Hold Register */
//S1ADR DEFINE 0xDB /* DDC I2C address */
//S2DAT DEFINE 0xDE /* Data Hold Register */




#endif // UPSD3254A
// *****************************************************************************
#endif // CONVERSIONKEILTOIARH
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX

