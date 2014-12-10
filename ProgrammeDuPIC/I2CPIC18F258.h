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
//             UC ucReadACK          (void);
//             UC ucI2CLireOctet     (UC ucAck);
//             void vI2CEcrireOctet  (UC ucData, UC ucRW);
//             void vDelaiI2C        (UI uiDelai);
//             void vI2CEcrireEEPROM (UC ucData, UI uiAdr, UC ucAdrChip);
//             UC ucI2CLireEEPROM    (UI uiAdr, UC ucAdrChip);
//             void vI2CEcrireDS1307 (UC ucADR, UC ucH, UC ucM, UC ucS);
//             void vI2CLireDS1307   (UC ucADR)
//****************************************************************************//
// PAR:        Louis-Normand Ang-Houle, Vincent CHouinard, Gabriel Fortin-Bélanger
//             et Hicham Safoine
////////////////////////////////////////////////////////////////////////////////
#ifndef I2CPIC18F258H
   #define I2CPIC18F258H
 
#include "PIC18F258.h"

void vInitI2CMaster    (void);
void vInitI2CSlave     (void);
void vI2CStart         (void);
void vI2CStop          (void);
void vI2CReStart       (void);
void vI2CCheck         (void);
void vSendACK          (UC ucAck);
UC ucReadACK           (void);
UC ucI2CLireOctet      (UC ucAck);
void vI2CEcrireOctet   (UC ucData, UC ucRW);
void vDelaiI2C         (UI uiDelai);
void vI2CEcrireDS1307  (UC ucADR, UC ucH, UC ucM, UC ucS);
void vI2CLireDS1307    (UC ucADR);
void vI2CEcrireEEPROM  (UC ucData, UI uiAdr, UC ucAdrChip);
UC ucI2CLireEEPROM     (UI uiAdr, UC ucAdrChip);
void vI2CEcrirePCF8574 (UC ucAdr, UC ucData);
UC ucI2CLirePCF8574    (UC ucAdr);

#endif
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX