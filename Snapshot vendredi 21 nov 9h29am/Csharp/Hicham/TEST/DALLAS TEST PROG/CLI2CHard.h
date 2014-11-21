// ************************** FICHIER: CLI2CHARD.h *****************************
//
// Fonctions de communication de base en I2C
//
// Application realisee avec IAR C++ 8.10
//
// AUTEUR : VINCENT CHOUINARD
// DATE CREATION : 15/sept/2014 VERSION: 1.0
// DATE MODIFICATION: ****-**-**
//
// *****************************************************************************
#include "_DeclarationGenerale.h"
#include "ConversionKeilToIAR.h"

#ifndef CLI2CHARDWAREH
   #define CLI2CHARDWAREH

class CLI2CHARD
{
public:
   CLI2CHARD(void);  // Constructeur par defaut
  ~CLI2CHARD(void);  // Destructeur
  
   UI   static i;                             // array pointer 
   UC   static i2c_xmit_buf[256];             // message transmission buffer
   UC   static i2c_rcv_buf [256];             // message reception buffer          
   UC   static dummybyte, i2c_timeout;        // dummy byte to rcv, timeout cz  
   bool static bus_lost_flag;                 // Bus loss flag
   bool static i2cwait;                       // To wait
   bool static i2c_master;                    // To set master mode
   bool static i2c_xmitr;                     // Transmitter variable
   bool static slave_nack_flag;               // Slave nACK flag
   bool        i2c_init_flag;                 // Flag d'initialisation
   bool        i2c_timeout_flag;              // Ackpolling timeout flag
   
   void vEcritOctet(UC ucAdresse, UC ucData); // Pour Ecrire un octet
   UC   ucLitOctet (UC ucAdresse);            // Pour lire un octet
  
protected:
  
private:
   void vDelay(UINT16 i);                     // Just a little delai for ACKpolling purposes
   void vInitUpsd                  (void);    // uPSD Hardware I2C bus 2 init
   void vI2C_WaitInterrupt         (void);    // Wait for interrupt before continue
   __interrupt static void vIntrI2C(void);    // The interrupt function where all happens. 
};
#endif
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
