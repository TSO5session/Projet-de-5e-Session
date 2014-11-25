// **************************Main.c
// Auteur:      Vincent Chouinard
// Date:        26 octobre 2014
// Version :    1.0
//
// Compilateur: IAR 8.10
//
// Description: Fichier principal
//
// *****************************************************************************
// **** LES INCLUDES ****************//
#include "_DeclarationGenerale.h"    // Raccourcis Linguistiques utiles
#include "ConversionKeilToIAR.h"     // Compatbilité avec Keil
#include "BlocFESTOmain.h"           //
#include "FESTO.h"
// **** LES DEFINES *****************//

// **** LES CLASSES *****************//
class CLFesto FESTO;
// **** LES FONCTIONS DU MAIN *******//

// **** PROGRAMME PRINCIPAL *********//
void main(void)
{
EA    = 0   ;  // Disable interrupt.
WDKEY = 0x55;  // Disable WatchDog.
EA    = 1   ;  // Enable Interrupt

while(1)
  {
   FESTO.SendToBolide("TEST");
  }
}
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
