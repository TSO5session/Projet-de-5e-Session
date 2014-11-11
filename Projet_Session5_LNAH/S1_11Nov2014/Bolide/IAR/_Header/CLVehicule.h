// ************************** FICHIER: CLVEHICULE.H*****************************
//
// Auteur:       Louis-Normand Ang-Houle, Hicham Safoine, Vincent Chouinard
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
#include "CLCommunicCom2.h"
#include "CLRoue.h"
#include "CLSuiveurLigne.h"
#include "CLCapteurDistance.h"
#include "CLPile.h"
#include "CLLimiteVitesse.h"
#include "CLHorloge1307.h"

#ifndef CLVEHICULEH
   #define CLVEHICULEH

#define MODEMANUEL  0
#define MODELIGNE   1
#define MODESUIVEUR 2
#define MODEEVITEUR 3
#define MODEINCLINO 4
#define MODETECH    5

#define CONVPOURCENT      1.27
#define VITESSEINIT       0x40
#define VITESSEINITTOURNE 0x30

#define DROITE        0
#define GAUCHE        1
#define DROITDEVANT   2
#define ARRET         4
#define MARCHEARRIERE 5
#define AVANTGAUCHE   6
#define AVANTDROITE   7
#define ARRIEREGAUCHE 8
#define ARRIEREDROITE 9

struct STReceptionTrame
{
UC ucCommande;
UC ucDonnee1;
UC ucDonnee2;
UC ucChecksum1;
UC ucChecksum2;
};

union UNReceptionTrame
{
struct STReceptionTrame stTrameRecue;
UC uctTrameRecue[5];
};

class CLVehicule
{
public:
   CLVehicule(void);
   CLVehicule(UC ucVit, UC ucVitTourne);
  ~CLVehicule(void);

   class CLEcran           clEcranVehicule;
   class CLCommunicCom2    clComBolide;
   class CLRoue            clRoueAvantD;
   class CLRoue            clRoueAvantG;
   class CLRoue            clRoueArriereD;
   class CLRoue            clRoueArriereG;
   class CLSuiveurLigne    clSuiveurLigne;
   class CLCapteurDistance clCapteurDroite;
   class CLCapteurDistance clCapteurGauche;
   class CLLimiteVitesse   clLimiteVitesse;
   class CLPile            clPile;
   class CLHorloge1307     clHorloge;

   void vControleBolide    (void);
   void vAvancer           (UC ucDirection);
   void vSetVitesse        (UC ucVit, UC ucVitTourne);
   void vVerifieVitesse    (void);
   void vInclinometre      (UC ucVertical, UC ucHorizontal);
   void vSuivreLigne       (void);
   void vEviterMoi         (void);
   void vSuivreMoi         (void);

protected:

private:
   UC ucMode;
   UC ucBoucle;
   UC ucTourne;
   UC ucVitRecu;   
   UC ucVitTourneRecu;
   UC ucLimiteVitesse;
   UC ucVitesse;
   UC ucVitesseTourne;

   union UNReceptionTrame unReceptionTrame;
};
#endif
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
