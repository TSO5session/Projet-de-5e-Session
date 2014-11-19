// ***************** FICHIER:CLI2CBase.cpp
//
//  Description:Ce fichier contient la definition des differentes fonction 
//              I2C de base qui communique avec le materiel
//
//  Application realisee avec IAR
//
//  AUTEUR : Gabriel Fortin-Belanger
//  DATE CREATION :    2014-02-07		 VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
//******************************************************************************

#include "_DeclarationGenerale.h"
#include "CLADDA.h"



CLADDA :: CLADDA(void)
{



}


CLADDA :: ~CLADDA(void)
{



}


UC CLADDA :: ucConvADBuf(unsigned short int usiChanel)
{

  ucIn((0xFA08 + usiChanel));
  P3_3 = 0;
  P3_3 = 1;
  while(P3_2 == 0);
  return(ucIn(0xFA10));
         
  
  

}

void CLADDA :: vConvDALatch(unsigned short int usiChanel , UC ucData)
{


 vOut(0xFA20 , ucData); //Sortie 8bit
 vOut((0xFA28 + usiChanel)  , ucData); //Sortie 8bit

         
  
  

}
UC CLADDA :: ucDataIN(UC ucBit)
{
  switch(ucBit)
  {
  case 0:
     return(  (ucIn(0xFA00)) & 0x01 );
    break;
      case 1:
     return(  ((ucIn(0xFA00)) & 0x02) >> 1 );
    break;
    case 2:
     return(  ((ucIn(0xFA00)) & 0x04) >> 2 );
    break;
     case 3:
     return(  ((ucIn(0xFA00)) & 0x08) >> 3 );
    break;
     case 4:
     return(  ((ucIn(0xFA00)) & 0x10) >> 4 );
    break;
     case 5:
     return(  ((ucIn(0xFA00)) & 0x20) >> 5 );
    break;
      case 6:
     return(  ((ucIn(0xFA00)) & 0x40) >> 6 );
    break;
     case 7:
     return(  ((ucIn(0xFA00)) & 0x80) >> 7 );
    break;
     case 8:
     return( ucIn(0xFA00));
    break;
  
  }
  
 

}




//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@