// ***************** FICHIER:CLEcran.cpp
//
//  Description: 
//  
//
//  Application realisee avec IAR
//
//  AUTEUR : Gabriel Fortin-Belanger
//  DATE CREATION :    2014-02-07		 VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
//******************************************************************************

#include "CLDelai.h"
#include "_DeclarationGenerale.h"



CLDelai :: CLDelai(void)
{
  
  
  ET0 = 0;
  TH0 = 0xF8;
  TL0 = 0x30;
  TMOD |= 0x01;
  
  

  
  
  
  

}


CLDelai :: ~CLDelai(void)
{


}
/*
void vDelay_ms (unsigned int uiDelay_ms)
 {


   while (uiDelay_ms != 0)
     { 
      TL0          = 0x30;         // Valeur pour un ms
      TH0          = 0xF8;         //
      TR0          = 1;           //Start Timer 1     
      while (TF0 != 1); 
      TF0 = 0;
      uiDelay_ms--;
     } 
 } 

 */


void CLDelai :: vDelaimsTimer0(UC ucTime)
{

UC ucCount = 0;
TCON_bit.TR0 = 1;
for(UC i = 0;i<ucTime;i++)
{
    
  while(TCON_bit.TF0 == 0);
  
  if(TCON_bit.TF0 == 1 )
  {
       
       TH0 = 0xF8;
       TL0 = 0x30;
       TCON_bit.TF0 =0;
       ucCount ++;
   }
  
  }
  TCON_bit.TR0 = 0;
  
}



