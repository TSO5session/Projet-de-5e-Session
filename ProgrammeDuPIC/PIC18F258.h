//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||//
// Les différentes fonctions du PIC
//
// Fonctions : vDelai       Delai
//           : vInitPic     Initialisation du PIC
//           : vInitRS232   Initialisation du port serie
//           : vTx232       Transmission port serie
//           : vRx232       Reception port serie
//           : vTransChaine Tranmit chaine sur port serie
//           : vInitPWM     Initialise PWM pic
// TSO 2012-2015   Jean-Francois Bilodeau    MikroC 6.0.0  6/4/2014
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&//

#ifndef PIC16F1459H
 #define PIC16F1459H

#include "DeclarationPIC.h"

void vDelai(UC ucDelai); //Delai
void vInitPic (void);    //Initialisation du PIC
void vInitRS232 (void);  //Initialisation du port serie
void vTx232 (UC ucSend); //Transmission port serie
void vTransChaine (UC *ucpChaine);//Tranmit chaine sur port serie
#endif