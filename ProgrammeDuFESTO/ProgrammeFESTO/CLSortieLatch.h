// **************************CLSortieLatch.h
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
#include "CLInOutBase.h"

#ifndef CLSORTIELATCHH
  #define CLSORTIELATCHH

class DAC_ADC : public CLInOutBase
{
public:
   DAC_ADC(void);            // ***Constructeur par defaut
   DAC_ADC(UC ucParametre);  // ***Constructeur initialisateur
  ~DAC_ADC(void);            // ***Destructeur
  
   void DAC(UC ucChannel, UC ucData); // Ecrire sur le convertisseur Digital to analog
   UC   ADC(UC ucChannel);            // Lire le convertisseur Analog to digital

protected:

private:

};
#endif
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX