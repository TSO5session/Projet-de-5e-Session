// ***************** FICHIER:CLI2CPort.cpp
//
//  Description:Contient les fonctions haut niveau pour communiquer avec 
//              l I2C.
//             
//
//  Application realisee avec IAR
//
//  AUTEUR : Gabriel Fortin-Belanger
//  DATE CREATION :    2014-02-07		 VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
//******************************************************************************
#include "_DeclarationGenerale.h"
#include "CLTLV2544.h"
#include "CLEcran.h"



CLTLV2544 :: CLTLV2544(void)
{

   P1_5 =0;
   ucSPITransfert( 0x00, 0xA8);
   ucSPITransfert( 0x00, 0x04);
   P1_5 =1;
}


CLTLV2544 :: ~CLTLV2544(void)
{


}


UC CLTLV2544 :: ucConvAD(UC ucChanel)
{
  int ucValue;
  P1_5 =1;
  
  
  switch(ucChanel)
  {
  case 0:
   
     
    P1_5 =0;
     
   /*
    clEcran.vLcdPoscurC0L1(0,1);
    clEcran.vLcdAffCarHex(ucSPITransfert( 0x00, 0x00));
     clEcran.vLcdPoscurC0L1(0,4);
    clEcran.vLcdAffCarHex(ucSPITransfert( 0x00, 0x00));
  */
  
   //ucValue = ucSPITransfert( 0x00, 0x00) << 8;
   //ucValue = ucValue | ucSPITransfert( 0x00, 0x00);
    ucVALH = ucSPITransfert( 0x00, 0x00) ;
    ucVALL =  ucSPITransfert( 0x00, 0x00);
    P1_5 =1;
    break;
    
    
    
  case 1:

    break;
  case 2:
 
    break;
  case 3:

    break;
    
    
  
  }
  return(ucValue);

}







