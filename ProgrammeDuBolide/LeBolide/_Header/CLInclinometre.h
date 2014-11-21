//*********************CLInclinometre.h*****************************************
// Auteur:       Louis-Normand Ang-Houle, Hicham Safoine, Vincent Chouinard
// Date:         1 mai 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.1
//
// Description:  Permet de controler le vehicule avec un inclinometre
// *****************************************************************************
#include "DeclarationGenerale.h"
#include "CLPWMuPSD.h"
#include "CLADCuPSD.h"

#ifndef CLINCLINOMETRE
   #define CLINCLINOMETRE

#define CANAL0 0x00
#define CANAL1 0x01

class CLInclinometre
{
public:
   class CLPWMuPSD clPWMuPSD ;
   class CLADCuPSD clADCuPSD ;
   
   CLInclinometre(void);
   
   void vInitialiseInclinometre (void);
   void vMultiplexageLed        (void);

protected:

private:

 };
#endif
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
