// **************************BlocFESTOmain.cp
// Auteur:       Vincent Chouinard
// Date:         27 novembre 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.10
//
// *****************************************************************************
// **** LES INCLUDES ****************//
#include "_DeclarationGenerale.h"    // Raccourcis Linguistiques utiles
#include "ConversionKeilToIAR.h"     // Compatbilité avec Keil
#include "BlocFESTOmain.h"           // header du main while(1){}
#include "FESTO.h"                   // Gestionnaire de table festo
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
   FESTO.ucGestionFESTO();
  }
}
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
