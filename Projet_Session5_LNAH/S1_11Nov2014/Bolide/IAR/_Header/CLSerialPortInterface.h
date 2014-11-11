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
// 
//
//
// ****************************************************************************

#include "DeclarationGenerale.h"

#ifndef CLSERIALPORTINTERFACEH
   #define CLSERIALPORTINTERFACEH

#ifdef DALLAS89C450
   #define MISO          P1_4
   #define MOSI          P1_5
   #define SCLK          P1_6
#endif

#ifdef UPSD3254A
   #define MISO          P1_4
   #define MOSI          P1_5
   #define SCLK          P1_6
#endif

class CLSerialPortInterface
 {
   public:
   CLSerialPortInterface(void);
   ~CLSerialPortInterface(void);
   
   UC ucSPITransferMOD0(UC ucSPIbyte);
   UC ucSPITransferMOD1(UC ucSPIbyte);
   UC ucSPITransferMOD2(UC ucSPIbyte);
   UC ucSPITransferMOD3(UC ucSPIbyte);
   
   protected:

   private:
     
     
  };

#endif

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@