// ************************** FICHIER: CLIOPCF8574.H ***************************
//
// Auteur:       Louis-Normand Ang-Houle, Hicham Safoine, Vincent Chouinard
// Date:         1 mai 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.1
//
// Description:
// *****************************************************************************
#include "DeclarationGenerale.h"
#include "CLI2CPort.H"

#ifndef CLIOPCF8574H
   #define CLIOPCF8574H

#define ADRIOPCF 0x40

class CLIOPCF8574 : public CLI2CPort
{
public:
   CLIOPCF8574(void);
   CLIOPCF8574(UC ucAdresse);
  ~CLIOPCF8574(void);

   UC    ucLireIOPCF  (void);
   void  vEcrireIOPCF (UC ucDonnee);
   union UNOctetBit   unIOPCF;

protected:

private:
   UC ucAdresseIOPCF;
};
#endif
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
