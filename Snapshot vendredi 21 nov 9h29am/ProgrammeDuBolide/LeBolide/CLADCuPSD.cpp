#include "CLADCuPSD.h"

#ifdef UPSD3254A
void CLADCuPSD :: vInitialiseADCuPSD (void)
 {
  P1SFS = 0xB0;       // Set le P1 a des entrée analog
  ASCL = 1;           // Conversion a 12MHz
  ACON_bit.ADEN = 1;  // Enable le mode de conversion A/A
 }  


 UC CLADCuPSD :: ucConversion (UC ucCanal)
 {
  UC ucDonnee; 
  switch (ucCanal)      // Selectionne le canal 0
   {
    case CANAL0:
     ACON_bit.ADS1 = 0;
     ACON_bit.ADS0 = 0;
    break;

    case CANAL1:        // S�lectionne le canal 1
     ACON_bit.ADS1 = 0;
     ACON_bit.ADS0 = 1;
    break;    
   }
  
  ACON_bit.ADST = 1;      // Start une conversion
 
 while (ACON_bit.ADSF == 0) {}; // Polling tant que conversion pas terminé fait rien
  if (ACON_bit.ADSF)             // Si conversion terminé
   { 
     ucDonnee = ADAT;   // Met donnee dans la variable
   } 
  return (ucDonnee);   // Retourne la tension lue  
 }
#endif
