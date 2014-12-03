// ************************** FICHIER: CLI2CHARD.cpp****************************
//
// Fonctions de communication de base en I2C
//
// Application realisee avec IAR C++ 8.10
//
// AUTEUR : VINCENT CHOUINARD
// DATE CREATION : 2014/08/9 VERSION: 1.0
// DATE MODIFICATION: ****-**-**
//
// *****************************************************************************
#include "CLI2CHard.h"               //
#include "_DeclarationGenerale.h"    //
#include "ConversionKeilToIAR.h"     // Conversion KEIL <--> IAR

bool CLI2CHARD :: bus_lost_flag;     //
bool CLI2CHARD :: i2cwait;           // Pour controler le delais
bool CLI2CHARD :: i2c_master;        //
bool CLI2CHARD :: i2c_xmitr;         //
bool CLI2CHARD :: slave_nack_flag;   //

UI   CLI2CHARD :: i;                 // array pointer
UC   CLI2CHARD :: i2c_xmit_buf[256]; // message transmission buffer
UC   CLI2CHARD :: i2c_rcv_buf [256]; // message reception buffer
UC   CLI2CHARD :: dummybyte;
UC   CLI2CHARD :: i2c_timeout;       // dummy byte to rcv, timeout cz

// *****************************************************************************
//                            LE CONSTRUCTEUR initialisateur
// *****************************************************************************
CLI2CHARD :: CLI2CHARD(void)
{
vInitUpsd(); // Initialise les SFR du bus I2C du uPSD3254
}

// *****************************************************************************
//                            LE DESTRUCTEUR
// *****************************************************************************
CLI2CHARD :: ~CLI2CHARD(void)
{

}

// **********************FONCTION: vInitUpsd()**********************************
//
// DESCRIPTION: Initialise les registres du bus I2C hardware du uPSD
//
// INCLUDE: "_DeclarationGenerale.h"
//          "CLI2CHard.h"
//
// PROTOTYPE:           void vInitUpsd(void)
//
// PROCEDURE D'APPEL:   vInitUpsd()
//
// PARAMETRE D'ENTREE:  AUCUN
//
// PARAMETRE DE SORTIE: AUCUN
//
// EXEMPLE: vInitUpsd() ---> Initialise le bus I2C Hardware
//
// Auteur:              Vincent Chouinard
// Date:                16 septembre 2014   (Version 1.0)
// Modification:
// *****************************************************************************
void CLI2CHARD :: vInitUpsd(void)
{
P3SFS           |= 0xC0;  // Enable P3.7 for SCL, P3.6 for SDA
S2CON           |= 0x01;  // Setup I2C-2 for 500KHz (24MHz XTAL)
i2c_init_flag    = 1;     // set init done flag
i2c_timeout_flag = 0;     // clear timeout error flag
i2cwait          = 0;     // Petit delais d'attente
IPA             |= 0x02;  // set high priority for EI2C
IEA             |= 0x02;  // set EI2C I2C Int. Enable bit
}

// **********************FONCTION: vI2C_WaitInterrupt()*************************
//
// DESCRIPTION: Permet d'attendre qu'un interrupt survient
//
// INCLUDE: "_DeclarationGenerale.h"
//          "CLI2CHard.h"
//
// PROTOTYPE:           void vI2C_WaitInterrupt(void)
//
// PROCEDURE D'APPEL:   vI2C_WaitInterrupt()
//
// PARAMETRE D'ENTREE:  AUCUN
//
// PARAMETRE DE SORTIE: AUCUN
//
// EXEMPLE: vI2C_WaitInterrupt() ---> Attend un interrupt
//
// Auteur:              Vincent Chouinard
// Date:                16 septembre 2014   (Version 1.0)
// Modification:
// *****************************************************************************
void CLI2CHARD :: vI2C_WaitInterrupt(void)
{
i2cwait     = 1;            // Flag d'attente
i2c_timeout = 0;            // Flag de depassement d'attente

while (i2cwait == 1)        // Wait for int to clear flag
  {                         //
   if(i2c_timeout >= 2 )    // XmS timeout loop
     {                      //
      i2c_timeout_flag = 1; // set error flag
      i2cwait          = 0; // Reset le flag d'attente
     }                      //
   vDelay(i);               // 1 mS delay (approximatively)
   i2c_timeout++;           // for the timeloop
  }
}

// **********************FONCTION: vIntrI2C()***********************************
//
// DESCRIPTION: Fonction PRAGMA VECTOR d'interruption
//
// INCLUDE: "_DeclarationGenerale.h"
//          "CLI2CHard.h"
//
// PROTOTYPE:            #pragma vector = 0x43 __interrupt void CLI2CHARD :: vIntrI2C(void)
//
// PROCEDURE D'APPEL:   Purement hardware
//
// PARAMETRE D'ENTREE:  AUCUN
//
// PARAMETRE DE SORTIE: AUCUN
//
// EXEMPLE: Survient lors d'une interruption sur le vecteur 0x43
//
// Auteur:              Vincent Chouinard
// Date:                16 septembre 2014   (Version 1.0)
// Modification:
// *****************************************************************************
 #pragma vector = 0x43                       // Lors d'une interruption de type INTERRUPT I2C
__interrupt void CLI2CHARD :: vIntrI2C(void) // I2C Hardware interrupt
{
if((S2STA & BLOST) == 1)    // If I2C bus is out of sync
  {
   S2DAT = dummy;           // send dummy byte
   bus_lost_flag    = 1;    // Activate bus loss flag
  }

if((S2STA & ACKR)  == 1)    // If bus send nACK
  {
   S2DAT = dummy;           // send dummy byte
   slave_nack_flag  = 1;    // Activate bus loss flag
  }
 
if(i2c_master & i2c_xmitr)  // If master must transmit
  {                         // Master transmitter mode
   i2cwait = 0;             // reset wait flag
  }

if(i2c_master & ~i2c_xmitr) // If master must receive
  {                         // Master receiver mode
   i2cwait = 0;             // reset wait flag
  }
}

// **********************FONCTION: vEcritOctet()*************************
//
// DESCRIPTION: Permet d'attendre qu'un interrupt survient
//
// INCLUDE: "_DeclarationGenerale.h"
//          "CLI2CHard.h"
//
// PROTOTYPE:           void vEcritOctet(UC, UC)
//
// PROCEDURE D'APPEL:   vEcritOctet(UC ucAdresse, UC ucData)
//
// PARAMETRE D'ENTREE:  ucAdresse et ucData
//
// PARAMETRE DE SORTIE: AUCUN
//
// EXEMPLE: vEcritOctet(0x43, 0x8A) ---> Ecrit 8A sur un chip dont l'adresse est 0x43
//
// Auteur:              Vincent Chouinard
// Date:                16 septembre 2014   (Version 1.0)
// Modification:
// *****************************************************************************
void CLI2CHARD :: vEcritOctet(UC ucAdresse, UC ucData)
{
EN1 = 1;                    // Enable I2C.
STA = 1;                    // Send start bit
S2DAT = ucAdresse /*& 0xFE*/;   // Envoyer adresse I2C du dispositif
vI2C_WaitInterrupt();       // Wait for interrupt
AA    = 1;                  // Send ACKowledge
STA   = 0;                  // Clear STA (Disable START)

// ********************************************************
// CE QUI EST IMPORTANT C'EST DE METTRE LE STOP AVANT
// LA DERNIERE INTERRUPTION SOIT LA TRANSMISSION DU DERNIER
// OCTET.
// ********************************************************
STO   = 1;                  // Send STOP bit
S2DAT = ucData;             // Envoyer la donnee ucData
vI2C_WaitInterrupt();       // Wait for interrupt.
STA   = 0;                  // Disable START).
STO   = 0;                  // Send STOP bit).
EN1   = 0;                  // Disiable I2C-2
}

// **********************FONCTION: ucLitOctet()*************************
//
// DESCRIPTION: Permet d'attendre qu'un interrupt survient
//
// INCLUDE: "_DeclarationGenerale.h"
//          "CLI2CHard.h"
//
// PROTOTYPE:           UC ucLitOctet(UC)
//
// PROCEDURE D'APPEL:   UC = ucLitOctet(UC ucAdresse)
//
// PARAMETRE D'ENTREE:  ucAdresse
//
// PARAMETRE DE SORTIE: ucData
//
// EXEMPLE: UC = ucLitOctet(0x43) ---> Lit la data sur un chip dont l'adresse est 0x43
//
// Auteur:              Vincent Chouinard
// Date:                16 septembre 2014   (Version 1.0)
// Modification:
// *****************************************************************************
UC CLI2CHARD :: ucLitOctet(UC ucAdresse)
{
UC ucData;                  // Pour enregistrer la donnee lue
EN1 = 1;                    // Enable I2C.
STA = 1;                    // Set STA to send start bit).

                            // Envoyer adresse du dispositif en lecture.
                            // Masquer pour s'assurer d'une adresse de lecture.
S2DAT = (ucAdresse | 0x01); // I2C addresse en lecture (R/W bit)
vI2C_WaitInterrupt();       // Wait for interrupt

AA  = 1;                    // Send ACKowledge
STA = 0;                    // Disable START
STO = 0;                    // Send STOP bit

                            // Important de conserver les 2 lignes suivantes
                            // pour mettre le I2C en entree.
S2DAT = 0xFF;               // Send byte for rcv mode.
vI2C_WaitInterrupt();       // Wait for interrupt

// ********************************************************
// CE QUI EST IMPORTANT C'EST DE METTRE LE STOP AVANT
// LA DERNIERE INTERRUPTION SOIT LA RECEPTION DU DERNIER
// OCTET.
// ********************************************************
STO    = 1;                 // Send STOP bit
ucData = S2DAT;             // Lire dernier octet.
vI2C_WaitInterrupt();       // Wait for interrupt
AA     = 0;                 // Send Not ACKnowledge
STA    = 0;                 // Disable START
EN1    = 0;                 // Disiable I2C-2
return(ucData);
}


// **********************FONCTION: vDelay()*************************
//
// DESCRIPTION: Permet d'attendre qu'un interrupt survient
//
// INCLUDE: "_DeclarationGenerale.h"
//          "CLI2CHard.h"
//
// PROTOTYPE:           void vDelay(UINT16)
//
// PROCEDURE D'APPEL:   vDelay(UINT16)
//
// PARAMETRE D'ENTREE:  vDelay
//
// PARAMETRE DE SORTIE: AUCUN
//
// EXEMPLE: vDelay(555) ---> Cre un delais de 555 unite de temps
//
// Auteur:              Vincent Chouinard
// Date:                16 septembre 2014   (Version 1.0)
// Modification:
// *****************************************************************************
void CLI2CHARD :: vDelay(UINT16 iWasteMyTime)
{
for(iWasteMyTime = 0; iWasteMyTime < 10; iWasteMyTime++)
  {
    /*Perd du temps dans une boucle FOR*/
  }
}
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX