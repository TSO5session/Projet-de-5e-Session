// ************************** FICHIER: CLSUIVEURLIGNE.H ************************
//
// Auteur:       Louis-Normand Ang-Houle, Hicham Safoine, Vincent Chouinard
// Date:         1 mai 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.1
//
// Description: Fonctions de suivie de ligne pour le bolide
// *****************************************************************************
#include "DeclarationGenerale.h"
#include "CLIOPCF8574.h"

#ifndef CLSUIVEURLIGNEH
   #define CLSUIVEURLIGNEH

#define DROITE      0
#define GAUCHE      1
#define DROITDEVANT 2
#define ARRET       4
#define DROITELENT  5
#define GAUCHELENT  6

class CLSuiveurLigne : public CLIOPCF8574
{
public:
   CLSuiveurLigne(void);
   CLSuiveurLigne(UC ucAdresse);
  ~CLSuiveurLigne(void);

   UC ucSuivreLigne(void);

protected:

private:
};
#endif
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
