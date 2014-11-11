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
#ifndef CLSPIH
   #define  CLSPIH
   #include "_DeclarationGenerale.h"



class CLSPI
{

   public:
     CLSPI(void);
     ~CLSPI(void);
    UC ucSPITransfert( UC ucMode, UC ucByte);
  
  
 
   protected:
  
  
  
  
   private:
  
  

  
  
  

};
   
#endif