//*****************CLADCuPSD.h**************************************************
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

#ifndef CLADCUSPD
   #define  CLADCUSPD

#define CANAL0 0x00
#define CANAL1 0x01

class CLADCuPSD
{
public:
   void vInitialiseADCuPSD (void);
   UC   ucConversion       (UC ucCanal);

protected:

private:

};
#endif
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
