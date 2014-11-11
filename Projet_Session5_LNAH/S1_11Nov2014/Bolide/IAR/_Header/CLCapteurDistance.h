// ************************** FICHIER: CLCAPTEURDISTANCE.H *********************
// Auteur:       Louis-Normand Ang-Houle, Hicham Safoine, Vincent Chouinard
// Date:         1 mai 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.1
//
// Description:  Fonctions de lecture d'un senseur de proximite GP2D12
// *****************************************************************************
#include "DeclarationGenerale.h"
#include "CLADCMAX1236.H"

#ifndef CLCAPTEURDISTANCEH
   #define CLCAPTEURDISTANCEH

#define SENSEURDROITE 1
#define SENSEURGAUCHE 0

class CLCapteurDistance : public CLADCMAX1236
{
public:
   CLCapteurDistance(void);
   CLCapteurDistance(UC ucAdresse);
  ~CLCapteurDistance(void);

   USI uiLireCapteur(void);

protected:

private:
   UC ucAdrCapteur;

};
#endif
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
