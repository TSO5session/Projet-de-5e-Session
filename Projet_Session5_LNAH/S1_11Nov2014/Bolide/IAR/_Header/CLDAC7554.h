// ************************** FICHIER: CLDAC7554.H *****************************
//
// Fonctions pour le convertisseur digital->analogue SPI DAC7554
//
// Application realisee avec IAR C++ 8.10
//
// AUTEUR : LOUIS-NORMAND ANG HOULE
// DATE CREATION : 2014/11/11 VERSION: 1.0
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

#ifndef CLDAC7554H
#define CLDAC7554H

#ifdef DALLAS89C450
   #define SLVSLCT_DAC7554 P1_6
#endif
#ifdef UPSD3254A
   #define SLVSLCT_DAC7554 P1_6
#endif

class CLDAC7554 : public CLSerialPortInterface
{
   public:
   CLDAC7554(void);
   CLDAC7554(UC ucAdresse);
  ~CLDAC7554(void);
  
   void vWriteChannel(USI uiValue, UC ucChannel);
   protected:

   private:

};

#endif

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@