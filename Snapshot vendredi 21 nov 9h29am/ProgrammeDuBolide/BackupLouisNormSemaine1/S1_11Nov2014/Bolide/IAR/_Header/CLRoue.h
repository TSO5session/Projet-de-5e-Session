// ************************** FICHIER: CLROUE.H *****************************
//
// Fonctions de controle des roues du bolide
//
// Application realisee avec IAR C++ 8.10
//
// AUTEUR : LOUIS-NORMAND ANG HOULE
// DATE CREATION : 2014/04/22 VERSION: 1.0
// DATE MODIFICATION: ****-**-**
//
// *****************************************************************************
//
// DESCRIPTION DES FONCTIONS
//
//
//
//
// *****************************************************************************
#include "DeclarationGenerale.h"
#include "CLDAC7554.h"
#include "CLDAC6574.h"

#ifndef CLROUEH
   #define CLROUEH

#ifdef SPI_DALLAS
  #define ARRETVARIABLE 0x0800

  #define R_AVANTG   0
  #define R_AVANTD   1
  #define R_ARRIEREG 2
  #define R_ARRIERED 3
#endif

#ifdef I2C_DALLAS
  #define ARRETVARIABLE 0x8000
 
  #define R_AVANTG   0
  #define R_ARRIEREG 1
  #define R_AVANTD   2
  #define R_ARRIERED 3
#endif

class CLRoue
{
public:
   CLRoue(void);
   CLRoue(UC ucVal);
  ~CLRoue(void);

   void vMarcheAvant   (USI uiVitesse);
   void vMarcheArriere (USI uiVitesse);
   void vArret         (void);

protected:

private:
   #ifdef SPI_DALLAS
   class CLDAC7554 clDAC7554Roue;
   #endif
   #ifdef I2C_DALLAS
   class CLDAC6574 clDAC6574Roue;
   #endif
   
   UC ucAdresseRoue;
};
#endif
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
