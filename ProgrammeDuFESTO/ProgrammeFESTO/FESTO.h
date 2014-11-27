// **************************Fichier.h
// Auteur:       Vincent Chouinard
// Date:         27 novembre 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.10
//
// Description:
// *****************************************************************************
// **** LES INCLUDES ****************//
#include "CLEcran.h"                 // Pour utiliser l'�cran
#include "CLCommunicUpsdPort1.h"     // Pour utiliser le port s�rie du uPSD
#include "_DeclarationGenerale.h"    // Raccourcis Linguistiques utiles
#include "ConversionKeilToIAR.h"     // Compatbilit� avec KeilP
#include "CLPompe.h"                 // Utilisation des pompes de la table FESTO
#include "CLFestoCaptors.h"          // Pour lire les capteurs de la table FESTO

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
  
   void ucGestionFESTO     (void); // G�re toute la s�quence FESTO
  
   UC IsTheBolideHere      (void); // V�rifie si le v�hicule est amarr� � la table festo 
   UC IsTheBlocInTheBolid  (void); // Retourne 1 lorsque le bloc est de retour dans le bolide
   UC ReadInstructionFromPC(void); // Lit les instructions du PC
   UC GetBlocColor         (void); // Lit la couleur du bloc
     
   void SendToBolide       (char const *ucpMessage); // Envoie un message au bolide
   void SendToStation1     (char const *ucpMessage); // Envoie un message � la station de contr�le
   
protected:

private:
   class CLCommunic     Xbee    ; // Initialise la communication s�rie uPSD   
   class CLEcran        LCD     ; // Initialise l' ecran LCD
   class CLPompe        Pompe   ; // Initialise le contr�le des pompes
   class CLFestoCaptors Capteur ; // Initialise la leture des capteurs
   
   void  Delai (UINT32 Temps);  // Impl�mentation d'un delai ajustable
   
};
#endif
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX