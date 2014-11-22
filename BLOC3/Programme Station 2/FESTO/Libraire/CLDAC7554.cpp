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
#include "CLDAC7554.h"
#include "CLEcran.h"



CLDAC7554 :: CLDAC7554(void)
{

 
}


CLDAC7554 :: ~CLDAC7554(void)
{


}


void CLDAC7554 :: vConvDA(UC ucChanel , UC ucValH, UC ucValL)
{
 
  int iCal;
  P1_6 =1;
  /*
  iCal = ( ucValH << 8) | ucValL;
  iCal = iCal >> 4;
  ucValH = UC (iCal >> 8 );
  ucValL = UC (iCal);
  */
  switch(ucChanel)
  {
  case 0:
    P1_6 =0;
    ucSPITransfert(0x00,(0x80 | ucValH));
    ucSPITransfert(0x00,ucValL);
    P1_6 =1;
    break;
    
  case 1:
    break;
  case 2:
 
    break;
  case 3:

    break;
    
    
  
  }
 

   

}







