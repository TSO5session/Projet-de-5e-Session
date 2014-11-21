#include "CLPWMuPSD.h"
#ifdef UPSD3254A
void CLPWMuPSD :: vInitialisePWM (void)
 {
  P4SFS = 0x30;  // Met le port 4 en mode PWM
  PWMCON_bit.PWML = 0; // Inverse la polarit� du PWM 
  PWMCON_bit.PWME = 1; // Enable le PWM  
  PWMCON_bit.CFG1 = 1; // Met la sortie push-pull
  PWMCON_bit.CFG2 = 1; // Met la sortie push-pull
 }

void CLPWMuPSD :: vOutPWM (UC ucDonnee, UC ucCanal)
 {
 
  if (ucCanal == 1)     // Canal PWM1
   {
    PWM1 = ucDonnee;    // Met donn�e horiz. dans PWM
    BG1 = 0;            // Active le transitor horiz.
    BG2 = 1;            // Ferme transitor vertical
    for (UC i = 0; i < 100; i++);  // D�lai pour voir LED    
    GATE = 1;           // Active gate pour donn�e horiz.
    BG1 = 1;            // Ferme transistor horiz.
   }
  
  if (ucCanal == 2)     // Canal PWM2
   {
    PWM2 = ucDonnee;    // Met donn�e vertical dans PWM
    BG1 = 1;            // Ferme transistor vertical
    BG2 = 0;            // Active transistor horiz.
    for (UC i = 0; i < 100; i++);   // D�lai pour LED
    GATE = 0;           // Active gate pour donn�e verticale
    BG2 = 1;            // ferme transistor verticale
   } 
 }
#endif