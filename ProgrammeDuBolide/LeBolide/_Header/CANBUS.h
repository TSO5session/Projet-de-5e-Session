// **************************CANBUS.h
// Auteur:       Vincent Chouinard
// Date:         27 octobre 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.1
//
// Description:
// *****************************************************************************
#include "DeclarationGenerale.h"  // Raccourcis de programmation & variables
#include "CLSerialPortInterface.h"// Pour utiliser le bus SPI
#include "MCP2515.h"              // define des registres du MCP2515

#ifndef CANBUSH
  #define CANBUSH

class CanBus
{
public:
   CanBus(void);            // ***Constructeur par defaut
   CanBus(UC ucParametre);  // ***Constructeur initialisateur
  ~CanBus(void);            // ***Destructeur
   
   void SendMCP(const UC *Message); // Envoie un string sur le CAN bus
   UC   ReadMCP(void);              // Lit un string sur le CAN bus

protected:

private:
   class CLSerialPortInterface SPI;
   
   void ModeLoopbackInit               (void)               ; // Mode loopback
   void AcquitterInterruptionsMCP2515  (void)               ; // Gestion des interrupts
   void MCP24515_init                  (void)               ; // Initialisation du MCP
   void ChoisirIdentifiantTX0          (int Identifiant)    ; // Choisie un registre CAN   
   void Delai                          (unsigned long Temps); // Court delai d'initialisation
   void EcrireRegistreMCP2515          (UC Address, UC Data); // Configure le MCP
   UC   LireRegistreMCP2515            (UC Address, UC Data); // Configure le MCP
   UC   Longueur                       (const UC *Contenu)  ; // Gestion d'une longueur
};
#endif
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
