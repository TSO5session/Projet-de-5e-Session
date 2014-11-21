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


#ifndef CLI2CREGH
   #define  CLI2CREGH
   #include "_DeclarationGenerale.h"
   
   class CLI2CReg
   {

    public:
           CLI2CReg(void);
	  ~CLI2CReg(void);
	  UC ucI2CMaster_Transmit(UC ucSlaveAdr,UC ucData);
          UC upsd_i2c_rcv (unsigned char i2c_address);
	  void vI2CRegInit(void);






    protected:







    private:
    __interrupt void static i2c_isr(void);
   void vWaitForInt(void);
   UC static i2cwait;
  UC static slave_nack_flag;
  UC static i2c_timeout_flag;// error flag bits  







        UC static I2C_State;
        UC static  ucI2C_MX;


   
   
   
   
};
   
   
   
   
   
   
   
   
   
  
   
   
   
#endif


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@