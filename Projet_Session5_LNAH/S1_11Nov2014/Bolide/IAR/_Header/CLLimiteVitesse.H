// ************************** FICHIER: CLLIMITEVITESSEH.H **********************
//
// Auteur:       Louis-Normand Ang-Houle, Hicham Safoine, Vincent Chouinard
// Date:         1 mai 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.1
//
// Description:  Fonctions permettant de controler la vitesse du bolide
// *****************************************************************************

#include "DeclarationGenerale.h"
#include "CLADCMAX1236.h"

#ifndef CLLIMITEVITESSEH
#define CLLIMITEVITESSEH
#define LIMVITESSE     2

class CLLimiteVitesse : public CLADCMAX1236
{
public:
   CLLimiteVitesse(void);
  ~CLLimiteVitesse(void);

   UC ucLimiteVitesse(void);

protected:

private:

};
#endif
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
