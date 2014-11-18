#include "DeclarationGenerale.h"
#include "CLInclinometre.h"

CLInclinometre :: CLInclinometre(void)
 {
   vInitialiseInclinometre();
 }


void CLInclinometre :: vInitialiseInclinometre (void)
 {
  clPWMuPSD.vInitialisePWM();     // Initialise le PWM
  clADCuPSD.vInitialiseADCuPSD(); // Initialise le convertisseur ADC 
 }
 
void CLInclinometre :: vMultiplexageLed (void) 
 {
  clPWMuPSD.vOutPWM (clADCuPSD.ucConversion (CANAL0), CANALPWM1); 
  clPWMuPSD.vOutPWM (clADCuPSD.ucConversion (CANAL1), CANALPWM2);
 }