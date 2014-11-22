// ***************** FICHIER:CLPiece.cpp
//
//  Description:Ce fichier contient la definition des differentes fonction 
//              pour controler les pieces
//
//  Application realisee avec IAR
//
//  AUTEUR : Gabriel Fortin-Belanger
//  DATE CREATION :    2014-02-07		 VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
//******************************************************************************

#include "_DeclarationGenerale.h"
#include "CLSPI.h"


CLSPI :: CLSPI(void)
{





}
    



 CLSPI :: ~CLSPI(void)
{




}
   


UC CLSPI :: ucSPITransfert( UC ucMode, UC ucByte)
{

  switch(ucMode)
  {
    unsigned char SPI_count; 
  
    
    
        
  case 0x00:
    for (SPI_count = 8; SPI_count > 0; SPI_count--) // single byte SPI loop
     {
      
    
       if(ucByte & 0x80)
       {
         MOSI = 1;
       }
       else
       {
         MOSI = 0;
       }
       
       ucByte = ucByte << 1; // shift next bit into MSB
       SCK = 0x01; // set SCK high
       
       
     
       ucByte |= MISO; // capture current bit on MISO
       
       
       SCK = 0x00; // set SCK low
     }
    break;
    
  case 0x01:
 
    for (SPI_count = 8; SPI_count > 0; SPI_count--) // single byte SPI loop
     {
        SCK = 0x01;
      if(ucByte & 0x80)
       {
         MOSI = 1;
       }
       else
       {
         MOSI = 0;
       }   // put current outgoing bit on MOSI
        ucByte = ucByte << 1; // shift next bit into MSB
        SCK = 0x00;            // set SCK low
        ucByte |= MISO;        // capture current bit on MISO
     }
  break;
   
  case 0x02:
   for (SPI_count = 8; SPI_count > 0; SPI_count--) // single byte SPI loop
    {
            if(ucByte & 0x80)
       {
         MOSI = 1;
       }
       else
       {
         MOSI = 0;
       } // put current outgoing bit on MOSI
      ucByte = ucByte << 1; // shift next bit into MSB
     SCK = 0x00; // set SCK low
     ucByte |= MISO; // capture current bit on MISO
     SCK = 0x01; // set SCK high
    }
  break;
    
  case 0x03:
    
  for (SPI_count = 8; SPI_count > 0; SPI_count--) // single byte SPI loop
   {
     SCK = 0x00; // set SCK low
            if(ucByte & 0x80)
       {
         MOSI = 1;
       }
       else
       {
         MOSI = 0;
       }// put current outgoing bit on MOSI
     ucByte = ucByte << 1; // shift next bit into MSB
     SCK = 0x01; // set SCK high
     ucByte |= MISO; // capture current bit on MISO
   }
   
  break;
    
  

    
  }

  
  
  
   return(ucByte);
  


}