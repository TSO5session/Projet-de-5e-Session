// ************************** FICHIER: CLDAC6574.H *****************************
// Auteur:       Louis-Normand Ang-Houle, Hicham Safoine, Vincent Chouinard
// Date:         1 mai 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.1
//
// Description:
// *****************************************************************************
//
// DESCRIPTION DES FONCTIONS
//
// void vConfigurerDAC6574(UC ucCanal, UC ucValeur):
//
//
// *****************************************************************************
#include "DeclarationGenerale.h"
#include "CLI2CPort.H"

#ifndef CLDAC6574H
#define CLDAC6574H

#define ADRDAC6574 0x98
#define CONFIG6574 0x10

class CLDAC6574 : public CLI2CPort
{
public:
   CLDAC6574(void);
   CLDAC6574(UC ucAdresse);
  ~CLDAC6574(void);

   UC   ucAdresseDAC6574;
   void vConfigurerDAC6574(UC ucCanal, USI uiValeur);

protected:

private:

};
#endif
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
