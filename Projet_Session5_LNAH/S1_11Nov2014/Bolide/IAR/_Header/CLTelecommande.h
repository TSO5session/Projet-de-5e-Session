// ************************** FICHIER: CLTelecommande.h*************************
//
// Auteur:       Louis-Normand Ang-Houle, Hicham Safoine, Vincent Chouinard
// Date:         1 mai 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.1
//
// Description: Fichiers de compilation pour la telecommande
// *****************************************************************************
#include "DeclarationGenerale.h"
#include "CLEcran.h"
#include "CLInclinometre.h"
#include "CLClavier.h"
#include "CLCommunicCom2.h"
#include "CLHorloge1307.h"

#ifndef CLTELECOMMANDEH
#define CLTELECOMMANDEH

   class CLTelecommande
    {
       public:
       
      CLTelecommande (void);  //Constructeur par default
     ~CLTelecommande (void);  //Destructeur
  
      void vControleTelecommande(void);
   
      class CLEcran        clEcranuPSD;
      class CLCommunicCom2 clCommunicuPSD;
      class CLInclinometre clInclinometre;
      class CLClavier      clClavier;
      class CLHorloge1307  clHorloge;

      protected:

      private:
      UC ucChoix;
      UC ucVitesse;
      UC ucVitesseTourne;
      UC ucTouchePese;
      UC ucAncienneTouche;
    };

#endif
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX

