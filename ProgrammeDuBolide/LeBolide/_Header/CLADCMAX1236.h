// ********************** FICHIER: CLADCMAX1236.h
// Auteur:       Louis-Normand Ang-Houle, Hicham Safoine, Vincent Chouinard
// Date:         1 mai 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.1
//
// Description: Fichier de definitions pour lire des valeurs analogiques sur
//              un MAX1236
// *****************************************************************************
#include "DeclarationGenerale.h"
#include "CLI2CPort.H"

#ifndef CLADCMAX1236H
   #define CLADCMAX1236H

#define ADRMAX1236    0x68
#define SETUPMAX1236  0xD2
#define CONFIGMAX1236 0x61

class CLADCMAX1236 : public CLI2CPort
{
public:
   CLADCMAX1236(void);
  ~CLADCMAX1236(void);

   void vInitMAX1236(void);
   USI  uiLireValeur(UC ucCanal);

protected:

private:

};
#endif
//
