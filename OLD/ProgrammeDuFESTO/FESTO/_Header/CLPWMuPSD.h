//***********************CLPWMuPSD.h********************************************
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
#include "CLEcran.h"

#ifndef CLPWMUPSD
   #define CLPWMUPSD

#define GATE      P1_6
#define BG1       P4_6
#define BG2       P4_7
#define CANALPWM1 1
#define CANALPWM2 2

class CLPWMuPSD
{
public:
   void vInitialisePWM (void);
   void vOutPWM        (UC ucDonnee1, UC ucCanal);

protected:

private:

};
#endif
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
