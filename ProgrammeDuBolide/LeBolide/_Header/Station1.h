// **************************Station1.h
// Auteur:       Prenom nom
// Date:         18 novembre 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.1
//
// Description:
// *****************************************************************************
#include "DeclarationGenerale.h"  // Raccourcis de programmation & variables
#include "CLXBEE.h"               // Pour utiliser le Xbee
#include "CLEcran.h"              // Pour utiliser l'�cran
#include "CLHorloge1307.h"        // Pour utiliser un DS1307
#include "CANBUS.h"               // Fichier de definitions du bus CAN

#ifndef STATION1H
  #define STATION1H

class CLStation1 //: public CLAutreClasse
{
public:
  CLStation1(void);             // ***Constructeur par defaut
  CLStation1(UC ucParametre);   // ***Constructeur initialisateur
 ~CLStation1(void);             // ***Destructeur
  
  void WriteClock     (UC AAAA, UC Mo, UC JJ, UC HH, UC MI, UC SS);
  void ReadClock      (void);
  
  void SendToPC       (const UC   *Message);
  void SendToPIC      (const UC   *Message);
  void SendToSOC8200  (const UC   *Message);
  void SendToBolide   (const char *Message);
  void SendToFesto    (const char *Message);
  
  UC   ReadFromPC     (void);
  UC   ReadFromPIC    (void);
  UC   ReadFromSOC    (void);
  char ReadFromBolide (void);
  char ReadFromFesto  (void);

protected:

private:
  class CanBus        CAN;       // Pour utiliser un bus CAN  
  class CLXbee        XBee;      // Pour la communication avec Xbee
  class CLEcran       LCD;       // Pour afficher des trucs et des machins � l'�cran
  class CLHorloge1307 Clock;     // Pour g�rer l'heure
};
#endif
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX