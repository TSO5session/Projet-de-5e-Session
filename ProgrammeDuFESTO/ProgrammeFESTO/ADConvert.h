// **************************ADConvert.h
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
#include "CLInOutBase.h"

#ifndef ADCONVERTH
  #define ADCONVERTH

class AD7829 : public CLInOutBase
{
public:
   AD7829(void);             // ***Constructeur par defaut
   AD7829(UC ucParametre);   // ***Constructeur initialisateur
  ~AD7829(void);             // ***Destructeur
  
  void DAC (UC ucChannel, UC ucData);  // Écrire une tension Analog sur un channel
  UC   ADC (UC ucChannel);             // Lire le convertisseur Analog to digital 
  
protected:

private:

};
#endif
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX