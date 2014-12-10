////////////////////////////////////////////////////////////////////////////////
// Les différentes fonctions I2C du MSSP PIC16F1459
//
// Fonctions : void vInitI2CMaster   (void);
//             void vInitI2CSlave    (void);
//             void vI2CStart        (void);
//             void vI2CStop         (void);
//             void vI2CReStart      (void);
//             void vI2CCheck        (void);
//             void vSendACK         (UC ucAck);
//             UC   ucReadACK        (void);
//             UC   ucI2CLireOctet   (UC ucAck);
//             void vI2CEcrireOctet  (UC ucData, UC ucRW);
//             void vDelaiI2C        (UI uiDelai);
//             void vI2CEcrireEEPROM (UC ucData, UI uiAdr, UC ucAdrChip);
//             UC   ucI2CLireEEPROM  (UI uiAdr,  UC ucAdrChip);
//             void vI2CEcrireDS1307 (UC ucADR,  UC ucH, UC ucM, UC ucS);
//             void vI2CLireDS1307   (UC ucADR)
//****************************************************************************//
// PAR:        Louis-Normand Ang-Houle, Vincent CHouinard, Gabriel Fortin-Bélanger
//             et Hicham Safoine
////////////////////////////////////////////////////////////////////////////////
#include "I2CPIC18F258.h"
UC ucTABHMS[3];

//************************void vInitI2CMaster (void)**************************//
//Description : Initialisation function of MSSP
//
//Function    : void vInitI2CMaster (void)
//
//Input param       : Aucun
//
//OUtput param      : Aucun
//
//Call procedure    : vInitI2CMaster()
//
// PAR:        Louis-Normand Ang-Houle, Vincent CHouinard, Gabriel Fortin-Bélanger
//             et Hicham Safoine
////////////////////////////////////////////////////////////////////////////////
void vInitI2CMaster (void)
 {
   TRISC4_bit  = 1;           // SDA IN
   TRISC3_bit  = 0;           // SCL OUT
   SSPSTAT.SMP = 1;           // No slew rate
   SSPSTAT.CKE = 0;           // Disable SMBus inputs
   SSPADD      = 0x09;        // 100 KHz
   SSPCON1     = 0b00101000;  // I2C Master mode
   SSPCON2     = 0b00000000;  // Reset ALL
   //SSPCON3   = 0b00000000;  //Rien de slave
 }

//************************void vInitI2CSlave (void)***************************//
//Description : Fonction d'initialisation du module I2C du PIC16F1459 SLAVE
//
//Prototype fonction : void vInitI2CSlave (void)
//
//Param entree       : Aucun
//
//Param sortie       : Aucun
//
//Procedure d'appel  : vInitI2CSlave()
//
// PAR:        Louis-Normand Ang-Houle, Vincent CHouinard, Gabriel Fortin-Bélanger
//             et Hicham Safoine
////////////////////////////////////////////////////////////////////////////////
void vInitI2CSlave (void)
 {
   TRISB4_bit  = 1;          // SDA IN
   TRISB6_bit  = 1;          // SCL IN
   SSPSTAT.SMP = 1;          // No slew rate
   SSPSTAT.CKE = 0;          // Disable SMBus inputs
   SSPADD      = 0b00110000; // Adresse SLAVE 0x30
   SSPCON1     = 0b00110110; // slave I2C start
   //PIE1.SSP1IE = 1;        // Enable interruptions slave
 }

//**************************void vI2CCheck (void)*****************************//
//Description : Fonction de check du bus I2C. Boucle pour tout type d'erreur
//
//Prototype fonction : void vI2CCheck (void)
//
//Param entree       : Aucun
//
//Param sortie       : Aucun
//
//Procedure d'appel  : vI2CCheck()
//
// PAR:        Louis-Normand Ang-Houle, Vincent CHouinard, Gabriel Fortin-Bélanger
//             et Hicham Safoine
////////////////////////////////////////////////////////////////////////////////
void vI2CCheck (void)
 {
   while (SSPCON2.ACKEN)  ;  // ACKEN not cleared, wait
   while (SSPCON2.RCEN)   ;  // RCEN not cleared, wait
   while (SSPCON2.PEN)    ;  // STOP not cleared, wait
   while (SSPCON2.SEN)    ;  // Start not cleared, wait
   while (SSPCON2.RSEN)   ;  // Rep start not cleared, wait
   while (SSPSTAT.R_NOT_W);  // TX not done wait
 }

//**************************void vI2CStart (void)*****************************//
//Description : Fonction Start I2C. Crée Start Time Up Sequence pour I2C
//
//Prototype fonction : void vI2CStart (void)
//
//Param entree       : Aucun
//
//Param sortie       : Aucun
//
//Procedure d'appel  : vI2CStart();
//
// PAR:        Louis-Normand Ang-Houle, Vincent CHouinard, Gabriel Fortin-Bélanger
//             et Hicham Safoine
////////////////////////////////////////////////////////////////////////////////
void vI2CStart (void)
 {
   vI2CCheck();          //Check bus is clear
   SSPCON2.SEN = 1;      //Start condition
 }

//**************************void vI2CStop (void)******************************//
//Description : Fonction Stop I2C. Crée Stop Timing Sequence pour I2C
//
//Prototype fonction : void vI2CStop (void)
//
//Param entree       : Aucun
//
//Param sortie       : Aucun
//
//Procedure d'appel  : vI2CStop();
//
// PAR:        Louis-Normand Ang-Houle, Vincent CHouinard, Gabriel Fortin-Bélanger
//             et Hicham Safoine
////////////////////////////////////////////////////////////////////////////////
void vI2CStop (void)
 {
   vI2CCheck();          //Check bus is clear
   SSPCON2.PEN = 1;      //Stop condition
 }

//**************************void vI2CReStart (void)***************************//
//Description : Fonction ReStart I2C. Crée ReStart Timing Sequence pour I2C
//
//Prototype fonction : void vI2CReStart (void)
//
//Param entree       : Aucun
//
//Param sortie       : Aucun
//
//Procedure d'appel  : vI2CReStart();
//
// PAR:        Louis-Normand Ang-Houle, Vincent CHouinard, Gabriel Fortin-Bélanger
//             et Hicham Safoine
////////////////////////////////////////////////////////////////////////////////
void vI2CReStart (void)
 {
   vI2CCheck();          //Check bus is clear
   SSPCON2.RSEN = 1;     //Repeated start condition
 }

//**************************UC ucReadAck (void)*******************************//
//Description : Fonction retourne valeur ACK I2C sent par un slave device
//
//Prototype fonction : UC ucReadAck (void)
//
//Param entree       : Aucun
//
//Param sortie       : SSPCON2.ACKSTAT - Valeur ACK sent du slave
//
//Procedure d'appel  : ucX = ucReadACK();
//
// PAR:        Louis-Normand Ang-Houle, Vincent CHouinard, Gabriel Fortin-Bélanger
//             et Hicham Safoine
////////////////////////////////////////////////////////////////////////////////
UC ucReadACK (void)
 {
   return(SSPCON2.ACKSTAT); //Return ACK value sent by slave device
 }

//**************************void vSendACK (UC ucAck)**************************//
//Description : Fonction envoi un ACK ou NACK I2C
//
//Prototype fonction : UC ucReadAck (void)
//
//Param entree       : Aucun
//
//Param sortie       : Aucun
//
//Procedure d'appel  : vSendACK(ACK);
//
// PAR:        Louis-Normand Ang-Houle, Vincent CHouinard, Gabriel Fortin-Bélanger
//             et Hicham Safoine
////////////////////////////////////////////////////////////////////////////////
void vSendACK (UC ucAck)
 {
   vI2CCheck();             //Check I2C bus IDLE
   SSPCON2.ACKDT = ucAck;   //ACK value into ACKDT (ACK data)
   SSPCON2.ACKEN = 1;       //Start ACK/NACK write sequence
 }

//***************void vI2CEcrireOctet (UC ucData, UC ucRW)********************//
//Description : Fonction ecriture octet sur bus I2C
//
//Prototype fonction : void vI2CEcrireOctet (UC ucData, UC ucRW)
//
//Param entree       : ucData - Data to write on I2C bus
//                   : ucRW   - Read or Write operation
//
//Param sortie       : AUCUN
//
//Procedure d'appel  : vI2CEcrireOctet (0x40, WRITE)
//
// PAR:        Louis-Normand Ang-Houle, Vincent CHouinard, Gabriel Fortin-Bélanger
//             et Hicham Safoine
////////////////////////////////////////////////////////////////////////////////
void vI2CEcrireOctet (UC ucData, UC ucRW)
 {
   vI2CCheck();                //Check I2C bus IDLE
   switch (ucRW)               //Switch, READ or WRITE?
    {
      case READ:               //Case read
        SSPBUF = ucData + 1;   //Add 1 to Adress, data into I2C buffer
      break;
      
      case WRITE:              //Case Write
        SSPBUF = ucData + 0;   //Data into I2C buffer
      break;
    }
   while (SSPSTAT.BF  != 0);   //Wait for buffer to be empty
   while (ucReadACK() != 0);   //Wait for slave ACK
 }

//********************UC ucI2CLireOctet (UC ucAck)****************************//
//Description : Fonction read I2C byte
//
//Prototype fonction : UC ucI2CLireOctet (UC ucAck)
//
//Param entree       : ucAck - Ack or Nack value to write
//
//Param sortie       : Data read from I2C buffer
//
//Procedure d'appel  : ucData = ucI2CLireOctet(ACK);
//
//TSO 2012-2015   Jean-Francois Bilodeau    MikroC 6.0.0  18/08/2014
//******************************************************************************
UC ucI2CLireOctet (UC ucAck)
 {
   vI2CCheck();                   //Check I2C bus Idle
   SSPCON2.RCEN = 1;              //Enable receiver
   while    (SSPCON2.RCEN != 0);  //Creates I2C Read sequence
   vSendACK (ucAck);              //Send the ack/Nack value
   return   (SSPBUF);             //return I2C buffer data
 }

//**********void vI2CEcrireEEPROM (UC ucData, UI uiAdr, UC ucAdrChip)*********//
//Description : Fonction write EEPROM memory over I2C
//
//Prototype fonction : vI2CEcrireEEPROM (UC ucData, UI uiAdr, UC ucAdrChip)
//
//Param entree       : ucData    - Data to write to EEPROM
//                   : uiAdr     - Internal EEPROM adress to write data
//                   : ucAdrChip - Physical EEPROM adress on I2C bus
//
//Param sortie       : Aucun
//
//Procedure d'appel  : vI2CEcrireEEPROM (0x34, 0x1234, 0xA0)
//
// PAR:        Louis-Normand Ang-Houle, Vincent CHouinard, Gabriel Fortin-Bélanger
//             et Hicham Safoine
////////////////////////////////////////////////////////////////////////////////
void vI2CEcrireEEPROM (UC ucData, UI uiAdr, UC ucAdrChip)
 {
   UC ucAdrH, ucAdrL;                 // Creates function variables
   ucAdrH = ((uiAdr & 0xFF00) >> 8);  // Isolates adr high nibbles
   ucAdrL = (uiAdr & 0x00FF);         // Isolates adr low nibbles
   
   vI2CStart();                       // Start I2C bus
   vI2CEcrireOctet(ucAdrChip, WRITE); // Writes EEPROM physical adress on I2C
   vI2CEcrireOctet(ucAdrH, WRITE);    // Write ADRH nibble
   vI2CECrireOctet(ucAdrL, WRITE);    // Write ADRL nibble
   vI2CEcrireOctet(ucData, WRITE);    // Write data to EEPROM
   vI2CStop();                        // Stop I2C bus
   //vDelaiI2C(1000);                 // Free time on I2C bus
 }

//****************UC ucI2CLireEEPROM (UI uiAdr, UC ucAdrChip)*****************//
//Description : Fonction read EEPROM memory over I2C
//
//Prototype fonction : ucI2CLireEEPROM (UI uiAdr, UC ucAdrChip)
//
//Param entree       : uiAdr     - Internal EEPROM adress to write data
//                   : ucAdrChip - Physical EEPROM adress on I2C bus
//
//Param sortie       : Data read from EEPROM memory
//
//Procedure d'appel  : ucData = ucI2CLireEEPROM(0x0123, 0xA4)
//
// PAR:        Louis-Normand Ang-Houle, Vincent CHouinard, Gabriel Fortin-Bélanger
//             et Hicham Safoine
////////////////////////////////////////////////////////////////////////////////
UC ucI2CLireEEPROM (UI uiAdr, UC ucAdrChip)
 {
   UC ucAdrH, ucAdrL, ucDataReturn;     //Creates function variables
   ucAdrH = ((uiAdr & 0xFF00) >> 8);    //Isolates adr high nibbles
   ucAdrL = (uiAdr & 0x00FF);           //Isolates adr low nibbles
   
   vI2CStart();                         //Start I2C
   vI2CEcrireOctet(ucAdrChip, WRITE);   //Writes EEPROM physical adress on I2C
   vI2CEcrireOctet(ucAdrH,    WRITE);   //Write ADRH nibble
   vI2CEcrireOctet(ucAdrL,    WRITE);   //Write ADRL nibble
   vI2CReStart();                       //ReStart I2C
   
   vI2CEcrireOctet(ucAdrChip, READ);    //Write EEPROM, Read operation follows
   ucDataReturn = ucI2CLireOctet(NACK); //Reads data from EEPROM
   vI2CStop();                          //Stop I2C
   //vDelaiI2C(1000);                   //I2C bus free time
   return (ucDataReturn);               //Returns EEPROM data
 }

//****************void vI2CEcrirePCF8574 (UC ucAdr, UC ucData)****************//
//Description : Fonction write IO expander over I2C
//
//Prototype fonction : vI2CEcrirePCF8574 (UC ucAdr, UC ucData)
//
//Param entree       : ucAdr  - Physical chip adress
//                   : ucData - Data to write
//
//Param sortie       : None
//
//Procedure d'appel  : vI2CEcrirePCF8574(0x40, 0xFA)
//
// PAR:        Louis-Normand Ang-Houle, Vincent CHouinard, Gabriel Fortin-Bélanger
//             et Hicham Safoine
////////////////////////////////////////////////////////////////////////////////
void vI2CEcrirePCF8574 (UC ucAdr, UC ucData)
 {
   vI2CStart();                    // Start I2C comm
   vI2CEcrireOctet(ucAdr,  WRITE); // Write adress to I2C bus
   vI2CEcrireOctet(ucData, WRITE); // Write data to adress on I2C
   vI2CStop();                     // Stops the com
 }

//********************UC ucI2CLirePCF8574 (UC ucAdr)**************************//
//Description : Fonction read I2C IO expander
//
//Prototype fonction : ucI2CLirePCF8574 (UC ucAdr)
//
//Param entree       : ucAdr - Adr to read
//
//Param sortie       : Data read from IO expander
//
//Procedure d'appel  : ucData = ucI2CLirePCF8574(0xA4)
//
// PAR:        Louis-Normand Ang-Houle, Vincent CHouinard, Gabriel Fortin-Bélanger
//             et Hicham Safoine
////////////////////////////////////////////////////////////////////////////////
UC ucI2CLirePCF8574 (UC ucAdr)
 {
   UC ucDataReturn;                      //Init function variables
   vI2CStart();                          //Start I2C bus
   vI2CEcrireOctet(ucAdr, READ);         //Init read procedure
   ucDataReturn = ucI2CLireOctet(NACK);  //Read value to variable
   vI2CStop();                           //Stop I2C
   return (ucDataReturn);                //Return read value
 }
 
void vI2CEcrireDS1307 (UC ucADR, UC ucH, UC ucM, UC ucS)
 {
   vI2CStart();
      vI2CEcrireOctet(ucADR, WRITE);
      vI2CEcrireOctet(HEURE, WRITE);
      vI2CEcrireOctet(ucH,   WRITE);
   vI2CStop ();

   vI2CStart();
      vI2CEcrireOctet(ucADR,  WRITE);
      vI2CEcrireOctet(MINUTE, WRITE);
      vI2CEcrireOctet(ucM,    WRITE);
   vI2CStop ();

   vI2CStart();
      vI2CEcrireOctet(ucADR,   WRITE);
      vI2CEcrireOctet(SECONDE, WRITE);
      vI2CEcrireOctet(ucS,     WRITE);
   vI2CStop ();
 }
 
void vI2CLireDS1307 (UC ucADR)
 {
   UC ucDataDS1307[3];
   
   vI2CStart();
      vI2CEcrireOctet(ucADR, WRITE); // Envoie l'adresse du DS1307
      vI2CEcrireOctet(HEURE, WRITE); // Envoie le registre des heures
   vI2CReStart();
      vI2CEcrireOctet(ucADR, READ);  // Prépare une lecture des heures
      ucTABHMS[0] = ucI2CLireOctet(NACK); // Lit les heures
   vI2CStop();

   vI2CStart();
      vI2CEcrireOctet(ucADR,  WRITE);  // Envoie l'adresse du DS1307
      vI2CEcrireOctet(MINUTE, WRITE);  // Envoie le registre des secondes
   vI2CReStart();
      vI2CEcrireOctet(ucADR, READ);   // Prépare une lecture des minutes
      ucTABHMS[1] = ucI2CLireOctet(NACK); // Lit les minutes
   vI2CStop();
 
   vI2CStart();
      vI2CEcrireOctet(ucADR,   WRITE);  // Envoie l'adresse du DS1307
      vI2CEcrireOctet(SECONDE, WRITE);  // Envoie le registre des minutes
   vI2CReStart();
      vI2CEcrireOctet(ucADR, READ);     // Prépare une lecture des secondes
      ucTABHMS[2] = ucI2CLireOctet(NACK); // Lit les secondes
   vI2CStop();
 }
 
//**************************void vDelaiI2C (UI uiDelai)***********************//
//Description : Delay Loop
//
//Prototype fonction : void vDelaiI2C (UI uiDelai)
//
//Param entree       : uiDelai - Delay value
//
//Param sortie       : Aucun
//
//Procedure d'appel  : vDelaiI2C(10000);
//
// PAR:        Louis-Normand Ang-Houle, Vincent CHouinard, Gabriel Fortin-Bélanger
//             et Hicham Safoine
////////////////////////////////////////////////////////////////////////////////
void vDelaiI2C (UI uiDelai)
 {
   for (; uiDelai>0; uiDelai--);  //Wait for it
 }
 //LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX