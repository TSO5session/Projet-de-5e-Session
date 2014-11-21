// **************************Main.cpp
// Auteur:      Vincent Chouinard
// Date:        26 octobre 2014
// Version :    1.0
//
// Compilateur: IAR 8.10
//
// Description: Fichier principal
//
// *****************************************************************************
// **** LES INCLUDES ****************//
#include "CLI2CPort.h"               // Pour utiliser le bus I2C Software
//#include "CLI2CHard.h"             // Pour utiliser le bus I2C Hardware (uPSD Only)
#include "CLSPI.h"                   // Pour utiliser le bus SPI
#include "CLClavier.h"               // Pour utiliser le clavier
#include "CLEcran.h"                 // Pour utiliser l'écran
#include "Timer0.h"                  // Pour utiliser le timer 0
#include "Optik.h"                   // Pour utiliser l'encodeur Optique
#include "CANBUS.h"                  // Pour utiliser un bus CAN
#include "MCP2515.h"                 // Define des registres du MCP2515
#include "CLSortieLatch.h"           // Pour faire des conversion DAC <===> ADC
#include "CLCommunic.h"              // Pour utiliser le port série du Dallas
//#include "CLCommunicUpsdPort1.h"   // Pour utiliser le port série du uPSD (uPSD Only)
#include "_DeclarationGenerale.h"    // Raccourcis Linguistiques utiles
#include "ConversionKeilToIAR.h"     // Compatbilité avec Keil
#include "NomDuProjet.h"             //
// **** LES DEFINES *****************//
#define PCF8574Adress 0x40           // Adresse I2C du PCD8574
// **** LES CLASSES *****************//
//class CLCommunic Serial  ;         // Initialise la communication série uPSD  
//class CLI2CPort  I2CSoft ;         // Initialise le communication I2C Software
//class CLI2CHARD  I2CHard ;         // Initialise le communication I2C Hardware
//class Encodeur   Optik   ;         // Pour lire l'encodeur Optique
//class CLClavier  Keyboard;         // Initialise le clavier
//class DAC_ADC    Convert ;         // Initialise la conversion DAC <===> ADC
//class Timer0     Timer   ;         // Pour utiliser le timer 0 (Default = 1ms)
class RS232        Serial  ;         // Initialise la communication série Dallas
class CLEcran      LCD     ;         // Initialise l' ecran LCD
class CLSPI        SPI     ;         // Initialise la communication SPI
class CanBus       CAN     ;         // Initialise le bus CAN
// **** LES FONCTIONS DU MAIN *******//

// **** PROGRAMME PRINCIPAL *********//
void main(void)
{
LCD.vLCDCursor(0,1)        ;  
LCD.String    ("125K, PCI2, ID = 000");
LCD.vLCDCursor(0,2)        ;
//LCD.String    ("04 020 FF (send)");
LCD.vLCDCursor(0,3)        ;
LCD.String    ("CAN BUS Demo");

while(1)
  {
//   CAN.SendMCP("0100FF"); // Arrêté
//   CAN.SendMCP("0400FF"); // Bloc métallique
//   CAN.SendMCP("0401FF"); // Bloc noire
//   CAN.SendMCP("0700FF"); // Rendu à la station 1
//   CAN.SendMCP("0702FF"); // Rendu à la station 3    
//   CAN.SendMCP("0102FF"); // Hors circuit
    
   CAN.SendMCP("0101FF"); // En marche   
   CAN.SendMCP("0264FF"); // Vitesse maximale
   CAN.SendMCP("0364FF"); // Battrie pleine
   CAN.SendMCP("0402FF"); // Bloc orange
   CAN.SendMCP("0564FF"); // Le bloc est lourd
   CAN.SendMCP("0701FF"); // Rendu à la station 2   

// Envoyer un HeartBeat par seconde, ralentit l'envoie de trames CAN    
unsigned long k; for(k = 0; k < 65555; k++); Serial.SendString("Allo");
  }
}
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
