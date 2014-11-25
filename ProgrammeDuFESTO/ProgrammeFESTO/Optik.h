// **************************Fichier.h
// Auteur:       Vincent Chouinard
// Date:         20 juillet 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.1
//
// Description:
// *****************************************************************************
#include "_DeclarationGenerale.h"  // Raccourcis de programmation & variables
#include "CLSPI.h"                   // Pour utiliser le bus SPI
//#include "CLCommunic.h"             //inclue RS232.h.

#ifndef OPTIKH
  #define OPTIKH

#define PH1 P1_7
#define PH2 P1_6
#define CW  1
#define CCW 0

class Encodeur //: public RS232
{
public:
   Encodeur(void);            // ***Constructeur par defaut
   Encodeur(UC ucParametre);  // ***Constructeur initialisateur
  ~Encodeur(void);            // ***Destructeur
  
   char LogicAnalyser(void);
  
protected:

private:
  static char LastState;           // Pour connaitre l'etat de la trame

};
#endif
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
