// ***************** FICHIER:CLI2CREG.cpp
//
//  Description: Contient les déclaration pour le i2c matériel
//               
//
//  Application realisee avec IAR
//
//  AUTEUR : Gabriel Fortin-Belanger
//  DATE CREATION :    2014-02-07		 VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
//******************************************************************************
#include "CLI2CReg.h"
#include "_DeclarationGenerale.h"
#include "CLI2CPort.h"



        UC CLI2CReg :: I2C_State;
        UC CLI2CReg :: ucI2C_MX;
  


// S2STA 
    
xdata unsigned char i2c_xmit_buf[256]; // message xmit buffer
xdata unsigned char i2c_rcv_buf[256]; // message rcv buffer
unsigned int i;                       // array pointer
unsigned char  dummybyte;
UC  i2c_timeout; // dummy byte to rcv, timeout cntr
UC  i2c_init_flag; 
UC CLI2CReg :: i2cwait; 
UC  i2c_master; 
UC  i2c_xmitr; // callable status flag bits
UC  bus_lost_flag; 
UC CLI2CReg :: slave_nack_flag; 
UC CLI2CReg :: i2c_timeout_flag;// error flag bits    
        
        
CLI2CReg :: CLI2CReg(void)
{



}


CLI2CReg :: ~CLI2CReg(void)
{

	

}

void CLI2CReg :: vI2CRegInit(void)
{
  
  
     P3SFS |= 0xC0; //
     S2CON |= 0x80; // Frequence deu crystal a 100khz;
     i2c_init_flag = 1; // set init done flag
     i2c_timeout_flag = 0; // clear timeout error flag
     //PX1 =0;
     IPA |= 0x02; // set high priority for EI2C
     IEA |= 0x02; // set EI2C I2C Int. Enable bit
     //EX1 = 1;
      EA =1;
     
    

}

UC CLI2CReg :: ucI2CMaster_Transmit(UC ucSlaveAdr,UC ucData)
{

  
  P1_1 = 0;
  while(S2STA_bit.Bbusy != 0);
  i2c_master = 1;
  i2c_xmitr = 1; // set up for master transmitter
  I2C_State = ucI2C_MX;
  S2DAT = ucSlaveAdr;
  S2CON_bit.EN1 = 1;
  S2CON_bit.STO = 0;
  S2CON_bit.STA = 1;
  S2CON_bit.AA = 0;
  vWaitForInt();
   S2CON_bit.STA = 0;
   S2CON_bit.STO = 1; // set STO (stop bit)
   S2DAT = ucData; // send last data byte 
   vWaitForInt(); // Wait for interrupt
   S2DAT = 0xFF;
   S2CON_bit.STO = 0;
   S2CON_bit.EN1 = 0;

  



}

UC CLI2CReg :: upsd_i2c_rcv (unsigned char i2c_address)
{
  while(S2STA_bit.Bbusy != 0);
  i2c_master = 1;
  i2c_xmitr = 0; // set flags for master receiver


  
  S2DAT = (i2c_address | 0x01); // set up i2c address (set R/W bit)
  S2CON_bit.EN1 = 1;
  S2CON_bit.STO =  0;
  S2CON_bit.STA = 1;
  S2CON_bit.AA = 0;
  vWaitForInt();
  S2CON_bit.STA = 0;
  S2DAT = 0xFF; // send byte for rcv mode
   S2CON_bit.AA = 1;
 vWaitForInt();
 // for (i=0; i < (data_len-1); i++)
 // {
 //  dummybyte = S2STA; // Dummy Read S2STA
 //  i2c_rcv_buf[i] = S2DAT; // Get data byte from Slave
 //  vWaitForInt(); // Wait for interrupt
 // }
  S2CON_bit.AA = 0;
   i2c_rcv_buf[i] = S2DAT; // Get last data byte
    vWaitForInt(); // Wait for interrupt
   dummybyte = S2STA; // Dummy Read S2STA
   //i++;
   i2c_rcv_buf[i] = S2DAT; // Get dummy data byte
   return(i2c_rcv_buf[i]);
}

void CLI2CReg :: vWaitForInt(void)
{
  int i;
  i2cwait = 1; //
  i2c_timeout = 0;
  while (i2cwait == 1)
   { // .. wait for int to clear flag
     if(i2c_timeout >= 10)
       { // 10mS timeout loop
         i2c_timeout_flag = 1;// set error flag
         i2cwait = 0; //
       }

     for(i=0;i<200;i++);
     i2c_timeout++;

  }
}


#pragma vector = 0x43
 __interrupt void CLI2CReg :: i2c_isr(void)
{
  P1_1 = 1;
if (S2STA_bit.Blost == 1)
{
S2DAT = 0xFF; // send dummy byte
bus_lost_flag = 1;
}
if (S2STA_bit.ACK_R == 1)
{

S2DAT = 0xFF; // send dummy byte
slave_nack_flag = 1;
}
if (i2c_master & i2c_xmitr)
{ 
i2cwait = 0; // reset wait flag
}
if (i2c_master & ~i2c_xmitr)
{ // mstr receiver mode
i2cwait = 0; // reset wait flag
}
}