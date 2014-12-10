//******************************************************************************
// Declaration generales pour le 16F88
//******************************************************************************
#ifndef DECLARATIONPICH
 #define DECLARATIONPICH

#define INDICETAMPON  26
#define LONGUEURTRAME 26
#define INCOMPLETE 1
#define COMPLETE 0
 
#define PASADR      0
#define ADR8BIT     1
#define ADR16BIT    2

//SCREEN I2C
#define PCF8574     0x46
#define EN          0x00
#define NEN         0x04
#define CONTROLI2C  0x00
#define WRITEI2C    0x01
#define READI2C     0x03
#define BUSYI2C     0x02
//

#define GAUCHER     0xA5
#define DROITIER    0x5A
#define AVANCER     0x55
#define RECULER     0xAA
#define STOPPER     0x00

#define LGAUCHE      0x16
#define LCGAUCHE     0x14
#define LCENTRE      0x15
#define LCDROITE     0x11
#define LDROITE      0x13

#define CANAL1      0

#define PCFMOTEUR 0x40

#define ADRHOR      0xD0
#define HEURE       0x02
#define MINUTE      0x01
#define SECONDE     0x00
#define JOUR        0x04
#define MOIS        0x05
#define ANNEE       0x06

#define ROULERHEURE 0
#define SETTERALARME 1

#define COMPLETE    0
#define INCOMPLETE  1
#define ACTIF       0
#define INACTIF     1

#define HAUT        1
#define BAS         0

#define ACK         0
#define NACK        1

#define VRAI        0
#define FAUX        1

#define READ 0
#define WRITE 1

typedef unsigned char UC;
typedef unsigned int UI;
typedef char C;
typedef unsigned short int US;

struct STHorloge
 {
    UC ucHeure;
    UC ucMinute;
    UC ucSeconde;
 };

#endif
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX