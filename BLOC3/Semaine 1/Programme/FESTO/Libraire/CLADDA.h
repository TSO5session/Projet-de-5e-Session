// ********************** FICHIER: CLCommunic.h ******************************
// Descrtiption : La classe contient des fonctions pour controler le i2c du upsd 
//                
//
// Fonctions    : 
//                
//                
//                
//
//  AUTEUR :Gabriel Fortin-Belanger
//  DATE CREATION :    27/03/2014		 VERSION: 1.0
//
// ****************************************************************************


#ifndef ADDAH
   #define  ADDAH
   #include "_DeclarationGenerale.h"
   #include "CLInOutBase.h"


class CLADDA : public CLInOutBase
{
   
   public:
     CLADDA(void);
     ~CLADDA(void);
     UC ucConvADBuf(unsigned short int usiChanel);
     void  vConvDALatch(unsigned short int usiChanel , UC ucData);
     UC ucDataIN( UC ucBit);
       
     
     
     
     
   protected:
     
     
     
     
   private:
     
       
   


};

#endif