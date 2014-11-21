// **************************Timer0.h
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
#ifndef TIMER0
  #define TIMER0

class Timer0 //: public CLAutreClasse
{
public:
   Timer0(void);             // ***Constructeur par defaut
   Timer0(UC ucCustomMili);  // ***Constructeur initialisateur (Initialise entre 1 et 25 ms)
  ~Timer0(void);             // ***Destructeur

   char DelayMs(void);
   void ClockGenerator(void);

protected:

private:
   void InitTimer0(void);             // Initialise le timer a 1 ms
   void CustomSpeed(UC ucCustomMili); // Timer custom (1-25ms) du constructeur initialisateur
};
#endif


//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX