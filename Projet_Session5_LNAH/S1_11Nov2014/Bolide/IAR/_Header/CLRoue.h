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
#include "CLDAC6574.h"

#ifndef CLROUEH
   #define CLROUEH

#define R_AVANTD   0
#define R_AVANTG   1
#define R_ARRIEREG 2
#define R_ARRIERED 3

#define ARRETVARIABLE 0x8000

class CLRoue : public CLDAC6574
{
public:
   CLRoue(void);
   CLRoue(UC ucAdresse);
  ~CLRoue(void);

   void vMarcheAvant   (UC ucVitesse);
   void vMarcheArriere (UC ucVitesse);
   void vArret         (void);

protected:

private:
   UC ucAdresseRoue;
};
#endif
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
