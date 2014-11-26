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
#include "CLEcran.h"                 // Pour utiliser l'�cran
#include "CLMCP2515.h"               // Pour utiliser un bus CAN
#include "MCP2515.h"                 // Define des registres du MCP2515
#include "CLCommunicUpsdPort1.h"     // Pour utiliser le port s�rie du uPSD
#include "_DeclarationGenerale.h"    // Raccourcis Linguistiques utiles
#include "ConversionKeilToIAR.h"     // Compatbilit� avec Keil
#include "CLMCP2515.h"               // Utilisation du MCP
#include "CLPompe.h"                 // Utilisation des pompes de la table FESTO

#include "CLFestoCaptors.h"          // Pour lire les capteurs de la table FESTO
// **** LES DEFINES *****************//
#define PCF8574Adress 0x40           // Adresse I2C du PCD8574
// **** LES CLASSES *****************//

#ifndef FESTOH
  #define FESTOH

#define ORANGE 1
#define NOIR   2
#define METAL  3
#define NOBLOC 4

class CLFesto 
{
public:
   CLFesto(void);                  // ***Constructeur par defaut
   CLFesto(UC ucParametre);        // ***Constructeur initialisateur
  ~CLFesto(void);                  // ***Destructeur
  
   UC ucGestionFESTO       (void); // G�re toute la s�quence FESTO
  
   UC IsTheBolideHere      (void); // V�rifie si le v�hicule est amarr� � la table festo 
   UC ReadInstructionFromPC(void); // Lit les instructions du PC
   UC GetBlocColor         (void); // Lit la couleur du bloc
     
   void SendToBolide       (char const *ucpMessage); // Envoie un message au bolide
   void SendToStation1     (char const *ucpMessage); // Envoie un message � la station de contr�le
   
protected:

private:
   class CLCommunic     Xbee    ; // Initialise la communication s�rie uPSD  
   class CLI2CPort      I2C     ; // Initialise le communication I2C Software
   class CLMCP2515      CAN     ; // Initialise le bus CAN     
   class CLEcran        LCD     ; // Initialise l' ecran LCD
   class CLPompe        Pompe   ; // Initialise le contr�le des pompes
   class CLFestoCaptors Capteur ; // Initialise la leture des capteurs
   
   void  Delai (unsigned long Temps);  // Impl�mentation d'un delai ajustable
   
};
#endif
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX