// ************************** FICHIER: CLInOutBase.H  **************************
// Auteur:       Louis-Normand Ang-Houle, Hicham Safoine, Vincent Chouinard
// Date:         1 mai 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.1
//
// Description:
// *****************************************************************************
#include "DeclarationGenerale.h"

#ifndef CLINOUTBASEH
   #define CLINOUTBASEH

#define SAMELSB  1
#define SAMEMSB  2
#define SUITELSB 3
#define SUITEMSB 4

class CLInOutBase
{
public:

protected:
   void vOut(USI uiAdresse, UC ucData);
   void vOut(USI uiAdresse, USI uiDonnee, UC ucTypeTransfert);

   UC   ucIn(USI uiAdresse);
   UC   ucIn(USI uiAdresse, UC ucTypeTransfert);

private:
   UC   ucInPort(USI uiAdresse);
   void vOutPort(USI uiAdresse, UC ucData);
};
#endif
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
