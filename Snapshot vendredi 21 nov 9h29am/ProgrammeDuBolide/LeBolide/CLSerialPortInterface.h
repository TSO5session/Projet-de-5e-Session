// ************************** FICHIER: CLSERIALPORTINTERFACE.H ****************
//
// Fonctions pour peripheriques SPI
//
// Application realisee avec IAR C++ 8.10
//
// AUTEUR : LOUIS-NORMAND ANG HOULE
// DATE CREATION : 2014/09/15 VERSION: 1.0
// DATE MODIFICATION: ****-**-**
//
// ****************************************************************************
// 
// DESCRIPTION DES FONCTIONS
//
// ****************************************************************************
#include "DeclarationGenerale.h"

#ifndef CLSERIALPORTINTERFACEH
   #define CLSERIALPORTINTERFACEH

#ifdef DALLAS89C450
   #define MISO          P1_1
   #define MOSI          P1_2
   #define SCLK          P1_3
#endif

#ifdef UPSD3254A
   #define MISO          P1_4
   #define MOSI          P1_5
   #define SCLK          P1_6
#endif

/////////////////////////////////////
#define CS   P1_7                  // Le chip-select
#define CSIO P1_4                  // Chip select des I/O
#define CSAD P1_5                  // Chip select des AD
#define CSDA P1_6                  // Chip select des DA
#define EOC  P1_7                  // END of conversion flag
/////////////////////////////////////

class CLSerialPortInterface
{
public:
  CLSerialPortInterface(void);
 ~CLSerialPortInterface(void);
   
  UC ucSPITransferMOD0(UC ucSPIbyte);
  UC ucSPITransferMOD1(UC ucSPIbyte);
  UC ucSPITransferMOD2(UC ucSPIbyte);
  UC ucSPITransferMOD3(UC ucSPIbyte);
  
  UC WriteMPC     (UC Data);              // Pour envoyer une valeur hexa sur les IO du MPC
  UC WriteMPC     (UC NombreDonneesEnvoyer, UC Donnee1, UC Donnee2, UC Donnee3);   
  UC ReadMPC      (void);                 // Pour lire la valeur hexa des IO du MPC
   
protected:

private:
   void Delai     (unsigned long Temps);     // Implémentation d'un delai ajustable      
   UC   Write     (UC ucValeur, UC ucMode);  // Pour ecrire une donnee 8  bit en SPI
   UI   Write16   (UI uiValeur, UC ucMode);  // Pour ecrire une donnee 16 bit en SPI 
};

#endif
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@