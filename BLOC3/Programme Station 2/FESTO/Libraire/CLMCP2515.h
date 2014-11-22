// ***************** FICHIER:CLEcran.H
//
//  Contient les definitions de classe pour utiliser l'ecran LCD
//  
//
//  Application realisee avec IAR
//
//  AUTEUR : Gabriel Fortin-Belanger
//  DATE CREATION :    2014-02-07		 VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
//******************************************************************************
#ifndef CLMCP2515H
   #define  CLMCP2515H
   #include "_DeclarationGenerale.h"
   #include "CLSPI.h"
#include "CLEcran.h"

   class CLMCP2515 : public CLSPI
   {
   public:
     CLMCP2515();
     ~CLMCP2515();
   void Delai(unsigned long Temps);
   unsigned char EcrireDonnesMCP2515(unsigned char NombreDonneesEnvoyer, unsigned char Donnee1, unsigned char Donnee2, unsigned char Donnee3);
   void InitialisationMCP2515(void);
   void EcrireRegistreMCP2515(unsigned char Address, unsigned char Data);
   void ChoisirIdentifiantTX0(int Identifiant);
   void EnvoyerTrameMCP2515(const unsigned char * Message);
   void AcquitterInterruptionsMCP2515(void);
   unsigned char Longueur(const  unsigned char * Contenu);
  UC LireRegistreMCP2515(unsigned char Address);
unsigned char CLMCP2515 :: LireDonnesMCP2515(unsigned char NombreDonneesEnvoyer, unsigned char Donnee1, unsigned char Donnee2, unsigned char Donnee3);
  UC* LireTrameMCP2515(void) ;  
   UC ucBuf[8];
   private:
     
     
     
     
     
   protected:
     
   
   };









#endif