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


#ifndef CONVERSTIONKEILTOIARH
   #define CONVERSTIONKEILTOIARH
#include "TypeCible.h"

//******************************************************************************
//
//
//
//
//******************************************************************************

#define data __data
#define xdata __xdata
#define code __code
//******************************************************************************

#ifdef DALLAS89C450
   #define P1_0           P1_bit.P10_T2    // Port 1.0
   #define P1_1           P1_bit.P11_T2EX  // Port 1.1
   #define P1_2           P1_bit.P12_RXD1  // Port 1.2
   #define P1_3           P1_bit.P13_TXD1  // Port 1.3
   #define P1_4           P1_bit.P14_INT2  // Port 1.4
   #define P1_5           P1_bit.P15_INT3  // Port 1.5
   #define P1_6           P1_bit.P16_INT4  // Port 1.6
   #define P1_7           P1_bit.P17_INT5  // Port 1.7
   #define EA             IE_bit.EA
   #define ET1            IE_bit.ET1
   #define ES0            IE_bit.ES0
   #define TI_0           SCON0_bit.TI_0          
   #define RI_0           SCON0_bit.RI_0  
   #define SM1_0          SCON0_bit.SM1_0  
   #define REN_0          SCON0_bit.REN_0
   #define TR1            TCON_bit.TR1
   #define SMOD_0         PCON_bit.SMOD_0 
   #define M01            TMOD_bit.M01 



   #define P3_0      P3_bit.P30_RXD0            //P3_0
   #define P3_1      P3_bit.P31_TXD0           //P3_1
   #define P3_2      P3_bit. P32_INT0           //P3_2
   #define P3_3      P3_bit. P33_INT1           //P3_3
   #define P3_4      P3_bit.P34_T0          //P3_4
   #define P3_5      P3_bit. P35_T1          //P3_5
   #define P3_6      P3_bit.P36_WR           //P3_6
   #define P3_7      P3_bit.P37_RD           //P3_7


      
  

    


  
   #define SDA            P1_6             //Port 1.6
   #define SCL            P1_7             //Port 1.7

#endif //DALLAS89C450

//******************************************************************************


#ifdef UPSD3254A
     #define P1_0      P1_bit.P10           //P1_0
   #define P1_1      P1_bit.P11           //P1_1
   #define P1_2      P1_bit.P12           //P1_2
   #define P1_3      P1_bit.P13           //P1_3
   #define P1_4      P1_bit.P14           //P1_4
   #define P1_5      P1_bit.P15           //P1_5
   #define P1_6      P1_bit.P16           //P1_6
   #define P1_7      P1_bit.P17           //P1_7

   #define P4_0      P4_bit.P40
   #define P4_1      P4_bit.P41
   #define P4_2      P4_bit.P42
   #define P4_3      P4_bit.P43
   #define P4_4      P4_bit.P44
   #define P4_5      P4_bit.P45
   #define P4_6      P4_bit.P46
   #define P4_7      P4_bit.P47

   #define P3_0      P3_bit.P30           //P3_0
   #define P3_1      P3_bit.P31           //P3_1
   #define P3_2      P3_bit.P32           //P3_2
   #define P3_3      P3_bit.P33           //P3_3
   #define P3_4      P3_bit.P34           //P3_4
   #define P3_5      P3_bit.P35           //P3_5
   #define P3_6      P3_bit.P36           //P3_6
   #define P3_7      P3_bit.P37           //P3_7



   #define SDA           P1_4
   #define SCL           P1_5


   #define ES2       IEA_bit.ES2

// Interruption priorite
   #define PX0       IP_bit.PX0
   #define PS        IP_bit.PS
   #define PS2       IPA_bit.PS2

// Interruption niveau activite.
   #define IT0       TCON_bit.IT0
   #define TR1       TCON_bit.TR1

   #define TCLK2     T2CON_bit.TCKL
   #define TRCLK2    T2CON_bit.RCLK
   #define TR2       T2CON_bit.TR2

   #define T2MOD_DCEN    T2MOD_bit.DCEN


   #define SMOD      PCON_bit.SMOD
   #define SMOD2     PCON_bit.SMOD1

   #define RI_0      SCON_bit.RI
   #define TI_0      SCON_bit.TI
   #define SM0_0     SCON_bit.SM0
   #define SM1_0     SCON_bit.SM1
   #define SM2_0     SCON_bit.SM2
   #define REN_0     SCON_bit.REN

   #define TI_2      SCON2_bit.TI
   #define RI_2      SCON2_bit.RI
   #define SM0_2     SCON2_bit.SM0
   #define SM1_2     SCON2_bit.SM1
   #define SM2_2     SCON2_bit.SM2
   #define REN_2     SCON2_bit.REN
   
   #define EX0       IE_bit.EX0
   #define ET0       IE_bit.ET0
   #define EX1       IE_bit.EX1
   #define ET1       IE_bit.ET1
   #define ES0       IE_bit.ES
   #define ET2       IE_bit.ET2
   #define EA        IE_bit.EA

 //ADC
   #define ADEN      ACON_bit.ADEN
   #define ADS1      ACON_bit.ADS1
   #define ADS0      ACON_bit.ADS0
   #define ADST      ACON_bit.ADST
   #define ADSF      ACON_bit.ADSF
//PWM
   #define PWML      PWMCON_bit.PWML
   #define PWMP      PWMCON_bit.PWMP
   #define PWME      PWMCON_bit.PWME
   #define CFG4      PWMCON_bit.CFG4
   #define CFG3      PWMCON_bit.CFG3
   #define CFG2      PWMCON_bit.CFG2
   #define CFG1      PWMCON_bit.CFG1
   #define CFG0      PWMCON_bit.CFG0

   #define WATCHDOG_OFF WDKEY = 0x55; // Disable watchdog.

#endif //UPSD3254A


//******************************************************************************

#endif //CONVERSIONKEILTOIARH