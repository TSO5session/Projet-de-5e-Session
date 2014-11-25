// ************************** FICHIER: CLI2CPORT.H *****************************
//
// Fonctions d'I/O du protocole I2C
//
// Application realisee avec IAR C++ 8.10
//
// AUTEUR : VINCENT CHOUINARD
// DATE CREATION : 2014/03/27 VERSION: 1.0
// DATE MODIFICATION: ****-**-**
//
// Description: Fonctions d'acces au I/0 (High level access) du protocole I2C
//
// DESCRIPTION DES FONCTIONS
//
// UC  ucI2CLireDonnee(UC ucAdrBoitier, UC ucAdrRegistre);
// void vI2CLireDonnee(UC ucAdrBoitier, USI uiAdrRegistre, UC ucTypeAdr,
//                     UC *ucpRecevoirDonnee, UC ucNbrLectures);
//
// void vI2CEcrireDonnee(UC ucAdrBoitier, UC ucAdrRegistre, UC ucDonnee);
// void vI2CEcrireDonnee(UC ucAdrBoitier, USI uiAdrRegistre, UC ucTypeAdr,
//                       UC *ucpDonnee, UC ucNbrEcritures);
//
// *****************************************************************************
#include "_DeclarationGenerale.h"
#include "CLI2CBase.h"

#ifndef CLI2CPORTH
   #define CLI2CPORTH

#define PASADR    0
#define ADR8BIT   1
#define ADR16BIT  2
#define READ      1
#define WRITE     0

class CLI2CPort : public CLI2CBase
{
public:
   CLI2CPort(void);
  ~CLI2CPort(void);

protected:
   UC   ucI2CLireDonnee (UC ucAdrBoitier, UC ucAdrRegistre);
   void vI2CLireDonnee  (UC ucAdrBoitier, USI uiAdrRegistre, UC ucTypeAdr,
                         UC *ucpRecevoirDonnee, UC ucNbrLectures);

   void vI2CEcrireDonnee(UC ucAdrBoitier, UC ucAdrRegistre,  UC ucDonnee);
   void vI2CEcrireDonnee(UC ucAdrBoitier, USI uiAdrRegistre, UC ucTypeAdr,
                         UC *ucpDonnee,   UC ucNbrEcritures);

private:
   UC ucAdrBoitier;
};
#endif
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
