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
#include "_DeclarationGenerale.h"  // Raccourcis de programmation & variables
#include "CLIOPCF8574.h"           // Pour lire au travers d'un PCF8574

#ifndef CLPOMPEH
  #define CLPOMPEH

#define AdresseSOL725 0x40
#define AdresseSOL713 0x40
#define AdresseSOL716 0x40
#define AdresseSOL722 0x40
#define AdresseSOL719 0x41
#define AdresseSOL704 0x41
#define AdresseSOL706 0x41

class CLPompe 
{
public:
   CLPompe(void);             // ***Constructeur par defaut
   CLPompe(UC ucParametre);   // ***Constructeur initialisateur
  ~CLPompe(void);             // ***Destructeur

   void SOL725       (void); // Active la pompe de chargement de marchandise
   
   void SOL713       (void); // Active la pompe d'élévation de la marchandise
   void SOL716       (void); // Rétracte la pompe d'élévation de la marchandise
   
   void SOL722       (void); // Envoie le bloc dans le convoyeur
   void SOL719       (void); // Rétraction de la pompe d'envoie dans le convoyeur
  
   void SOL704       (void); // Baisse la ventouse
   void SOL706       (void); // Monte la ventouse  
   
protected:

private:
   class CLIOPCF8574 PCF1    ; // Initialise l'utilisation d'un PCF8574
   class CLIOPCF8574 PCF2    ; // Initialise l'utilisation d'un PCF8574
};
#endif
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX