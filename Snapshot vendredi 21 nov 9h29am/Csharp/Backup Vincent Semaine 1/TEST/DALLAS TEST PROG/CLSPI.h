//**********************  Fichier: CLSPI.h
//  Description  : Fonctions necessaire pour communiquer en SPI.
//
//  Composition  : aucune
//  Heritage     : aucune
//
//  Programmeur  : Vincent Chouinard
//  Cours        : 247-636
//
//  Date         : 22 Octobre 2014
//
//  Compilateur  : IAR 8.1
//
//  Modification :
//
//////////////////////////////////////////////////////////////////////////////
#ifndef CLSPIH                     // Si CLSPI.h non defini.
  #define CLSPIH                   // Defini CLSPI.h

#include "_DeclarationGenerale.h"  // inclue DeclarationGenerale.h
#include "MCP2515.h"              // define des registres du MCP2515
/////////////////////////////////////
#define MOSI P1_5                  // Master OUT, Slave IN
#define MISO P1_4                  // Master IN, Slave OUT
#define SCLK P1_6                  // La clock
#define CS   P1_7                  // Le chip-select
#define CSIO P1_4                  // Chip select des I/O
#define CSAD P1_5                  // Chip select des AD
#define CSDA P1_6                  // Chip select des DA
#define EOC  P1_7                  // END of conversion flag
/////////////////////////////////////

class CLSPI
{
public:
   CLSPI(void)    ;                          // Constructeur.
   CLSPI(UC ucVal);                          // Constructeur initialisateur.
  ~CLSPI(void)    ;                          // Destructeur.

   UC   WriteMPC     (UC Data);              // Pour envoyer une valeur hexa sur les IO du MPC
   UC   WritePOT     (UC Data);              // Pour écrire sur un POT numerique 
   UC   WriteDAC     (UC ucPin, int iData);  // Pour faire une conversion Digital to Numeric
   UC   WriteMPC     (UC NombreDonneesEnvoyer, UC Donnee1, UC Donnee2, UC Donnee3);   
   UC   ReadMPC      (void);                 // Pour lire la valeur hexa des IO du MPC

protected:

private:
   void Delai     (unsigned long Temps);     // Implémentation d'un delai ajustable
   void Direction (UC Directions) ;          // Pour la direction des port du MCP23S08  
   UC   Write     (UC ucValeur, UC ucMode);  // Pour ecrire une donnee 8  bit en SPI
   UI   Write16   (UI uiValeur, UC ucMode);  // Pour ecrire une donnee 16 bit en SPI    
};
#endif                                       // Fin du Si CLSPI non defini.

//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX

