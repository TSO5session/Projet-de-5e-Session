//**********************  Fichier: CLCommunic.cpp
//  Description : UART1 pour carte Dallas
//                version miniminaliste pour carte Dallas
//  Composition : aucune
//  Heritage    : aucun
//
//  Programmeur : Vincent Chouinard
//  Cours       : 247-436
//                                                                           
//  Date        : 10 avril 2014
//                                                                           
//  Compilateur : IAR 8.1                                  
//                                                                           
//  Modification:                                                            
//                                                                           
///////////////////////////////////////////////////////////////////////////////
#include "CLCommunic.h"             //inclue RS232.h.
#include "ConversionKeilToIAR.h"
#include "stdio.h"

RS232 :: RS232(void)
{
SetConfig();   // Initialise le port serie.
}

RS232 :: RS232(UC ucLongBuf, UC ucLongTrame, UI uiBaud)
{

}

RS232 :: ~RS232(void)
{

}

void RS232 :: SendString(char const *ucpMessage)
{
while(*ucpMessage != 0x00)          // Tant qu'on a pas atteint la fin de 
  {                                 // la chaine.
   SBUF0 = *ucpMessage;             // Envoye le caractere dans SBUF0 pour le transmetre sur TX                     
   while(TI_0 == 0);                // Si le flag TI_0 se met a 1 (termine)
   TI_0  = 0;                       // Remet le flag a 0. 
   ucpMessage++;                    // Passe au caractere suivant.
  }
}

void RS232 :: SendCar(char Caractere)
{
SBUF0 = Caractere;         // Envoye le caractere dans SBUF0 pour le transmetre sur TX                     
while(TI_0 == 0);          // Si le flag TI_0 se met a 1 (termine)
TI_0  = 0;                 // Remet le flag a 0.  
}

char RS232 :: GetCar(void)
{
return(SBUF0);
}

void RS232 :: SetConfig(void)
{
// Setup port serie 0 du Dallas pour 57600 baud a 11.059MHz.
SCON0 = 0x50;            // SCON: mode 1, 8-bit UART, enable rcvr.
TMOD |= 0x20;            // TMOD: timer 1, mode 2, 8-bit reload.
TH1   = 255;             // TH1: reload value for 57600 baud a 11.059MHz.
PCON  = 0x80;            // SMOD_0 = 1 (doubleur de baud).
TR1   = 1;               // TR1: Part le timer 1.
TI_0  = 1;               // TI: set TI to send first char of UART.  
}
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX






