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
#ifndef CLTLV2544H
   #define  CLTLV2544H
   #include "_DeclarationGenerale.h"
   #include "CLSPI.h"
#include "CLEcran.h"

   class CLTLV2544 : public CLSPI
   {
   public:
     CLTLV2544();
     ~CLTLV2544();
     UC ucConvAD(UC ucChanel);
     CLEcran clEcran;
       UC ucVALH;
   UC ucVALL;
     
     
   private:
     
     
     
     
     
   protected:
     
   
   };









#endif