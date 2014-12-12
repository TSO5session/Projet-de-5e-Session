// ************************** FICHIER: CLSTATION2.H *****************************
//
// Fonctions pour le controle du station 2 (controlleur table Festo)
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
#include "CLCommunic.h"
#include "CLFesto.h"
#include "CLEcran.h"

#ifndef CLSTATION2H
#define CLSTATION2H

class CLStation2
{
   public: 
   CLStation2(void);
  ~CLStation2(void);
   void vControleStation2(void);
   
   protected:
   
     
   private:
   UC TrameTxST2[5];  
   
   class CLCommunic   clXBeeST2;
   class CLEcran      clEcranST2;
   class CLFesto      clTableFesto;
};

#endif

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@