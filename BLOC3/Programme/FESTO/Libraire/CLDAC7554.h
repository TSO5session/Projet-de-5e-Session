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
#ifndef CLDAC75544H
   #define  CLDAC7554H
   #include "_DeclarationGenerale.h"
   #include "CLSPI.h"
#include "CLEcran.h"

   class CLDAC7554 : public CLSPI
   {
   public:
     CLDAC7554();
     ~CLDAC7554();
     void vConvDA(UC ucChanel , UC ucValH, UC ucValL);
     CLEcran clEcran;
     
     
     
   private:
     
     
     
     
     
   protected:
     
   
   };









#endif