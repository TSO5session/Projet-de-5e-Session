// ************************** FICHIER: CLVEHICULE.H*****************************
//
// Auteur:       LNAH, GFB, HS, VC
// Date:         1 mai 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.1
//
// Description: Meta-fonction de controle du vehicule
// *****************************************************************************
#include "DeclarationGenerale.h"
#include "CLEcran.h"
#include "CLRoue.h"
#include "CLSuiveurLigne.h"

#ifndef CLVEHICULEH
   #define CLVEHICULEH

#define MODEMANUEL  0
#define MODESUIVEUR 1

#ifdef SPI_DALLAS
#define VITESSEINIT       0x0800
#define VITESSEINITTOURNE 0x0300
#endif

#ifdef I2C_DALLAS
#define VITESSEINIT       0x40
#define VITESSEINITTOURNE 0x30
#endif

#define DROITE        0
#define GAUCHE        1
#define DROITDEVANT   2
#define ARRET         4
#define MARCHEARRIERE 5


class CLVehicule
{
public:
   CLVehicule(void);
   CLVehicule(USI uiVit, USI uiVitTourne);
  ~CLVehicule(void);

   class CLEcran           clEcranVehicule;
   class CLRoue            clRoueAvantD;
   class CLRoue            clRoueAvantG;
   class CLRoue            clRoueArriereD;
   class CLRoue            clRoueArriereG;
   class CLSuiveurLigne    clSuiveurLigne;

   void vControleBolide    (void);
   void vAvancer           (UC ucDirection);
   void vSuivreLigne       (void);

protected:

private:
   UC ucMode;
   
   #ifdef SPI_DALLAS   
   USI uiVitesse;
   USI uiVitesseTourne;
   #endif
   
   #ifdef I2C_DALLAS
   UC ucVitesse;
   UC ucVitesseTourne;
   #endif
   
};
#endif
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
