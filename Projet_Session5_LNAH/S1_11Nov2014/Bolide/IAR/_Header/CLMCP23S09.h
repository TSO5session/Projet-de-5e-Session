// ************************** FICHIER: CLMCP23S09.H *****************************
//
// Fonctions pour l'extension d'I/O SPI MCP23S09
//
// Application realisee avec IAR C++ 8.10
//
// AUTEUR : LOUIS-NORMAND ANG HOULE
// DATE CREATION : 2011/11/11 VERSION: 1.0
// DATE MODIFICATION: ****-**-**
//
// *****************************************************************************
// 
// DESCRIPTION DES FONCTIONS
//
// 
//
//
// *****************************************************************************

#include "DeclarationGenerale.h"
#include "CLSerialPortInterface.h"

#ifndef CLMCP23S09H
#define CLMCP23S09H

#define LECTURE_MCP23S09  1
#define ECRITURE_MCP23S09 0

#ifdef DALLAS89C450
   #define SLVSLCT_MCP23S09 P1_4
#endif
#ifdef UPSD3254A
   #define SLVSLCT_MCP23S09 P1_4
#endif

class CLMCP23S09 : public CLSerialPortInterface
{
   public:  
     CLMCP23S09(void);
     ~CLMCP23S09(void);
     
     UC ucLireMCP23S09(void);
     void vEcrireMCP23S09(UC ucDonnee);
     void vSetModeMCP23S09(UC ucMode);
     
   protected:

   private:

};

#endif

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@