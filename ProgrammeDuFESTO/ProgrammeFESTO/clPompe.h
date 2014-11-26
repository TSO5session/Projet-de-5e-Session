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
#include "_DeclarationGenerale.h"  // Raccourcis de programmation & variables
#include "CLI2CPort.h"             // Pour utiliser le bus I2C Software
#include "CLSPI.h"                 // Pour utiliser le bus SPI

#ifndef CLPOMPEH
  #define CLPOMPEH

class CLPompe 
{
public:
   CLPompe(void);             // ***Constructeur par defaut
   CLPompe(UC ucParametre);   // ***Constructeur initialisateur
  ~CLPompe(void);             // ***Destructeur

   void vPompeSOL725       (void); // Active la pompe de chargement de marchandise
   
   void vPompeSOL713       (void); // Active la pompe d'élévation de la marchandise
   void vPompeSOL716       (void); // Rétracte la pompe d'élévation de la marchandise
   
   void vPompeSOL722       (void); // Envoie le bloc dans le convoyeur
   void vPompeSOL719       (void); // Rétraction de la pompe d'envoie dans le convoyeur
  
   void vPompeSOL704       (void); // Baisse la ventouse
   void vPompeSOL706       (void); // Monte la ventouse  
   
protected:

private:
   class CLSPI      SPI     ; // Initialise la communication SPI
   class CLI2CPort  I2C     ; // Initialise le communication I2C Software
};
#endif
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX