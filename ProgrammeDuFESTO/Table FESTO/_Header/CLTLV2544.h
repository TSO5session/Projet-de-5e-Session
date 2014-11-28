// ************************** FICHIER: CLTLV2544.H *****************************
//
// Fonctions pour le convertisseur analogue->digital SPI TLV2554
//
// Application realisee avec IAR C++ 8.10
//
// AUTEUR : LOUIS-NORMAND ANG HOULE
// DATE CREATION : 2014/10/06 VERSION: 1.0
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

#ifndef CLTLV2544H
#define CLTLV2544H

#ifdef DALLAS89C450
   #define SLVSLCT_TLV2554 P1_5
#endif
#ifdef UPSD3254A
   #define SLVSLCT_TLV2554 P1_5
#endif

#define TLV2554_CAN0 0x00
#define TLV2554_CAN1 0x20
#define TLV2554_CAN2 0x40
#define TLV2554_CAN3 0x60

class CLTLV2544 : public CLSerialPortInterface
{
   public:  
   CLTLV2544(void);
   CLTLV2544(UC ucMode);
   ~CLTLV2544(void);

   USI uiLireConversion(UC ucCanal);
      
   protected:

   private:
};

#endif

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@