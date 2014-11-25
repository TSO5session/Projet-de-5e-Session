// ***************** FICHIER:CLEcran.H
//
//  Contient les definitions de classe pour utiliser l'ecran LCD
//  
//
//  Application realisee avec IAR
//
//  AUTEUR : Gabriel Fortin-Belanger
//  DATE CREATION :    2014-02-07       VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
//******************************************************************************
#ifndef CLMCP2515H
   #define  CLMCP2515H

#include "_DeclarationGenerale.h"
#include "CLSPI.h"
#include "CLEcran.h"


class CLMCP2515 
{
public:
   CLMCP2515();
  ~CLMCP2515();
  
   void Delai                        (unsigned long Temps);
   void InitialisationMCP2515        (void);
   void AcquitterInterruptionsMCP2515(void);
   void ChoisirIdentifiantTX0        (int Identifiant);
   void EnvoyerTrameMCP2515          (const UC * Message);   
   void EcrireRegistreMCP2515        (UC Address, UC Data);
   
   UC   ucBuf[8];
   UC*  Read               (void); 
   UC   Longueur           (const UC * Contenu);
   UC   LireRegistreMCP2515(UC Address);
   
   UC EcrireDonnesMCP2515(UC NombreDonneesEnvoyer, UC Donnee1, UC Donnee2, UC Donnee3);
   UC CLMCP2515 :: LireDonnesMCP2515(UC NombreDonneesEnvoyer, UC Donnee1, UC Donnee2, UC Donnee3);
  
protected:
  
private:
class CLSPI SPI     ; // Initialise la communication SPI
};

#endif
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX