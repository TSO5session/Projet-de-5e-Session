// **************************Timer0.cpp
// Auteur:       Vincent Chouinard
// Date:         24 septembre 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.1
//
// Description:
// *****************************************************************************
#include "_DeclarationGenerale.h"  // Raccourcis de programmation & variables
#include "Timer0.h"
UC   DutyCycle = 0;
//******************************************************************************
//                            LE CONSTRUCTEUR PAR DEFAUT
// *****************************************************************************
Timer0 :: Timer0(void)
{
InitTimer0();
}

//******************************************************************************
//                            LE CONSTRUCTEUR PAR DEFAUT
// *****************************************************************************
Timer0 :: Timer0(UC ucParametre)
{
CustomSpeed(ucParametre);
}


// *****************************************************************************
//                            LE DESTRUCTEUR
// *****************************************************************************
Timer0 :: ~Timer0(void)
{

}

/*
Note: La fréquence en HZ doit etre passee comme suit:
250hz = 1sec / 250 = 0.004 sec ---> Passez 4 en parametre
*/
void Timer0 :: ClockGenerator(void)
{
if(TCON_bit.TF0 == 1)     // Si flag de depassement du timer0 (default =  1ms)
  {
   TCON_bit.TF0 = 0;      // Reinitialisation du flag de depassement
   TH0          = 0xF8;   // Remet le compteur a 1ms
   TL0          = 0x60;   // Remet le compteur a 1ms
   DutyCycle++;
   if(DutyCycle <= 3){P1_7 = HIGH;}
   if(DutyCycle == 4){P1_7 = LOW, DutyCycle = 0;}
  }
}

char Timer0 :: DelayMs(void)  // retourne 1 a chaque ms
{
char i;
i = 0;                        // Dit qu'il n'y a pas d'interrupt
if(TCON_bit.TF0 == 1)         // Si flag de depassement du timer0 ( a 10ms)
  {
   TCON_bit.TF0 = 0;          // Reinitialisation du flag de depassement
   TH0 = 0xF8;                // Remet le compteur a 1ms
   TL0 = 0x60;                // Remet le compteur a 1ms
   i   = 1;                   // Dit qu'il y a un interrupt
  }
return(i);
}

void Timer0 :: InitTimer0(void)       //Initialise le timer 0 a 1ms
{
EA           = 0;
TMOD         = (TMOD & 0xF0) | 0x01;  // timer0 en mode timer 16bit
TL0          = 0x60;                  // Initialise le timer0 a 1ms
TH0          = 0xF8;                  // Initialise le timer0 a 1ms
TH0          = 0;                     // Clear le flag d'overflow du timer0
IE_bit.ET0   = 0;                     // Desactive les interruptions timer0
TCON_bit.TR0 = 1;                     // Stop le timer0
EA           = 1;                     // Enable Interrupt
}

void Timer0 :: CustomSpeed(UC ucCustomMili) // Initialise un timer custom via
{                                           // le constructeur initialisateur
EA           = 0;                           // Desactive les interruptions
TMOD         = (TMOD & 0xF0) | 0x01;        // timer0 en mode timer 16bit

switch(ucCustomMili)//En fonction des milisecondes demandees
  {
   case 1:
      TL0 = 0x02;   // Initialise le timer0 a 1ms
      TH0 = 0xF8;   // Initialise le timer0 a 1ms
   break;

   case 2:
      TL0 = 0x05;   // Initialise le timer0 a 2ms
      TH0 = 0xF0;   // Initialise le timer0 a 2ms
   break;

   case 3:
      TL0 = 0x08;   // Initialise le timer0 a 3ms
      TH0 = 0xE8;   // Initialise le timer0 a 3ms
   break;

   case 4:
      TL0 = 0xBF;   // Initialise le timer0 a 4ms
      TH0 = 0xE0;   // Initialise le timer0 a 4ms
   break;

   case 5:
      TL0 = 0xEF;   // Initialise le timer0 a 5ms
      TH0 = 0xD8;   // Initialise le timer0 a 5ms
   break;

   case 6:
      TL0 = 0x1F;   // Initialise le timer0 a 6ms
      TH0 = 0xD1;   // Initialise le timer0 a 6ms
   break;

   case 7:
      TL0 = 0x4F;   // Initialise le timer0 a 7ms
      TH0 = 0xC9;   // Initialise le timer0 a 7ms
   break;

   case 8:
      TL0 = 0x07;   // Initialise le timer0 a 8ms
      TH0 = 0xC1;   // Initialise le timer0 a 8ms
   break;

   case 9:
      TL0 = 0xAF;   // Initialise le timer0 a 9ms
      TH0 = 0xB9;   // Initialise le timer0 a 9ms
   break;

   case 10:
      TL0 = 0xDF;   // Initialise le timer0 a 10ms
      TH0 = 0xB1;   // Initialise le timer0 a 10ms
   break;

   case 11:
      TL0 = 0x0F;   // Initialise le timer0 a 11ms
      TH0 = 0xAA;   // Initialise le timer0 a 11ms
   break;

   case 12:
      TL0 = 0x3F;   // Initialise le timer0 a 12ms
      TH0 = 0xA2;   // Initialise le timer0 a 12ms
   break;

  case 13:
      TL0 = 0x6F;   // Initialise le timer0 a 13ms
      TH0 = 0x9A;   // Initialise le timer0 a 13ms
   break;

   case 14:
      TL0 = 0x9F;   // Initialise le timer0 a 14ms
      TH0 = 0x92;   // Initialise le timer0 a 14ms
   break;

   case 15:
      TL0 = 0xCF;   // Initialise le timer0 a 15ms
      TH0 = 0x8A;   // Initialise le timer0 a 15ms
   break;

   case 16:
      TL0 = 0xFF;   // Initialise le timer0 a 16ms
      TH0 = 0x82;   // Initialise le timer0 a 16ms
   break;

   case 17:
      TL0 = 0x2F;   // Initialise le timer0 a 17ms
      TH0 = 0x7B;   // Initialise le timer0 a 17ms
   break;

   case 18:
      TL0 = 0x5F;   // Initialise le timer0 a 18ms
      TH0 = 0x73;   // Initialise le timer0 a 18ms
   break;

   case 19:
      TL0 = 0x8F;   // Initialise le timer0 a 19ms
      TH0 = 0x6B;   // Initialise le timer0 a 19ms
   break;

   case 20:
      TL0 = 0xBF;   // Initialise le timer0 a 20ms
      TH0 = 0x63;   // Initialise le timer0 a 20ms
   break;

   case 21:
      TL0 = 0xEF;   // Initialise le timer0 a 21ms
      TH0 = 0x5B;   // Initialise le timer0 a 21ms
   break;

   case 22:
      TL0 = 0x1F;   // Initialise le timer0 a 22ms
      TH0 = 0x54;   // Initialise le timer0 a 22ms
   break;

   case 23:
      TL0 = 0x4F;   // Initialise le timer0 a 23ms
      TH0 = 0x4C;   // Initialise le timer0 a 23ms
   break;

   case 24:
      TL0 = 0x7F;   // Initialise le timer0 a 24ms
      TH0 = 0x44;   // Initialise le timer0 a 24ms
   break;

   case 25:
      TL0 = 0xAF;   // Initialise le timer0 a 25ms
      TH0 = 0x3C;   // Initialise le timer0 a 25ms
   break;

   default:
      TL0 = 0x60;   // Initialise le timer0 a 1ms
      TH0 = 0xF8;   // Initialise le timer0 a 1ms
   break;
}
TH0          = 0;   // Clear le flag d'overflow du timer0
IE_bit.ET0   = 0;   // Desactive les interruptions timer0
TCON_bit.TR0 = 1;   // Stop le timer0
EA           = 1;   // Enable Interrupt
}
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
