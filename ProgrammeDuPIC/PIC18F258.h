////////////////////////////////////////////////////////////////////////////////
// Les différentes fonctions du PIC
//
// Fonctions : vDelai       Delai
//           : vInitPic     Initialisation du PIC
//           : vInitRS232   Initialisation du port serie
//           : vTx232       Transmission port serie
//           : vRx232       Reception port serie
//           : vTransChaine Tranmit chaine sur port serie
//           : vInitPWM     Initialise PWM pic
// PAR:        Louis-Normand Ang-Houle, Vincent CHouinard, Gabriel Fortin-Bélanger
//             et Hicham Safoine
////////////////////////////////////////////////////////////////////////////////

#ifndef PIC16F1459H
 #define PIC16F1459H

#include "DeclarationPIC.h"

void vDelai       (UC ucDelai);    // Delai
void vInitPic     (void);          // Initialisation du PIC
void vInitRS232   (void);          // Initialisation du port serie
void vTx232       (UC ucSend);     // Transmission port serie
void vTransChaine (UC *ucpChaine); // Tranmit chaine sur port serie
#endif

//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX