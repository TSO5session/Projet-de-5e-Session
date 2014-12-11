// ************************** FICHIER: CLSTATION1.H *****************************
//
// Fonctions pour le controle du station 1 (proxy PC)
//
// Application realisee avec IAR C++ 8.10
//
// AUTEUR : LOUIS-NORMAND ANG HOULE
// DATE CREATION : 2014/12/01 VERSION: 1.0
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

#include "CLMCP2515.h"
#include "CLCommunic.h"
#include "CLEcran.h"
#include "CLHorloge1307.h"

#ifndef CLSTATION1H
#define CLSTATION1H

class CLStation1
{
   public: 
   CLStation1(void);
  ~CLStation1(void);
   void vControleStation1(void);
   protected:

   private:
   class CLMCP2515  clCANST1;
   class CLCommunic clXbeeST1;
   class CLEcran    clEcranST1;
   class CLHorloge1307  clHorlogeST1;
};

#endif

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@