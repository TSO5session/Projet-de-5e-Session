// **************************Fichier.h
// Auteur:       Prenom nom
// Date:         19 octobre 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.1
//
// Description:
// *****************************************************************************
// **** LES INCLUDES ****************//
#include "CLI2CPort.h"               // Pour utiliser le bus I2C Software
//#include "CLSPI.h"                 // Pour utiliser le bus SPI
#include "CLClavier.h"               // Pour utiliser le clavier
#include "CLEcran.h"                 // Pour utiliser l'écran
#include "Timer0.h"                  // Pour utiliser le timer 0
#include "CLMCP2515.h"               // Pour utiliser un bus CAN
#include "MCP2515.h"                 // Define des registres du MCP2515
#include "Conversions.h"             // Fichier pour convertir des formats
#include "CLCommunicUpsdPort1.h"     // Pour utiliser le port série du uPSD
#include "_DeclarationGenerale.h"    // Raccourcis Linguistiques utiles
#include "ConversionKeilToIAR.h"     // Compatbilité avec Keil
#include "CLMCP2515.h"               // Utilisation du MCP
// **** LES DEFINES *****************//
#define PCF8574Adress 0x40           // Adresse I2C du PCD8574
// **** LES CLASSES *****************//

#ifndef FESTOH
  #define FESTOH

#define ORANGE 1
#define NOIR   1
#define METAL  1

class CLFesto 
{
public:
   CLFesto(void);             // ***Constructeur par defaut
   CLFesto(UC ucParametre);   // ***Constructeur initialisateur
  ~CLFesto(void);             // ***Destructeur
  
   UC IsTheBolideHere      (void); // Vérifie si le véhicule est amarré à la table festo  
   UC ReadInstructionFromPC(void); // Lit les instructions du PC
   UC GetBlocColor         (void); // Lit la couleur du bloc
   
   void SendToBolide       (char const *ucpMessage); // Envoie un message au bolide
   void SendToStation1     (char const *ucpMessage); // Envoie un message à la station de contrôle
   
protected:

private:
   class CLCommunic Xbee    ; // Initialise la communication série uPSD  
   class CLI2CPort  I2C     ; // Initialise le communication I2C Software
   class CLMCP2515  CAN     ; // Initialise le bus CAN     
   class CLSPI      SPI     ; // Initialise la communication SPI
   class CLEcran    LCD     ; // Initialise l' ecran LCD
   class CLClavier  Keyboard; // Initialise le clavier
   class Conversion Convert ; // Conversion de bases
};
#endif
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX