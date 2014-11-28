// ************************** FICHIER: CLI2CBASE.H *****************************
//
// Fonctions de communication de base en I2C
//
// Application realisee avec IAR C++ 8.10
//
// AUTEUR : LOUIS-NORMAND ANG HOULE
// DATE CREATION : 2014/03/27 VERSION: 1.0
// DATE MODIFICATION: ****-**-**
//
// Description: Fonction d'acces aux I/O (Low level) du protocole I2C
//
// DESCRIPTION DES FONCTIONS
//
// CLI2CBase(void)       : Constructeur par defaut
// CLI2CBase(UC ucDelai) : Constructeur-initialisateur
// ~CLI2CBase(void)      : Destructeur
//
// void vI2CStart(void)  : Fonction d'initialisation I2C
// void vI2CStop(void)   : Fonction de cloturage I2C
//
// void vI2CEcrireBit(UC ucValeur) : Ecriture d'un bit sur le bus I2C
// UC ucI2CEcrireOctet(UC ucOctet) : Ecriture d'un octet sur le bus I2C
//
// UC ucI2CLireOctet(void): Lecture d'un bit sur le bus I2C
// UC ucI2CLireBit(void)  : Lecture d'un octet sur le bus I2C
//
// void vDelaisI2C(void)  : Delai de stabilisation du signal
//
// *****************************************************************************
#include "DeclarationGenerale.h"

#ifndef CLI2CBASEH
   #define CLI2CBASEH


#ifdef DALLAS89C450
  #define SDA           P3_4
  #define SCL           P3_5
#endif

#ifdef UPSD3254A
  #define SCL           P3_7
  #define SDA           P3_6
#endif

#define ACK  0
#define NACK 1

class CLI2CBase
{
public:
   CLI2CBase(void);
   CLI2CBase(UC ucDelai);
  ~CLI2CBase(void);

protected:
   void vI2CStart        (void);
   void vI2CStop         (void);
   UC   ucI2CEcrireOctet (UC ucOctet);
   UC   ucI2CLireOctet   (UC ucAck);

private:
   void vI2CEcrireBit    (UC ucValeur);
   UC   ucI2CLireBit     (void);
   void vDelaiI2C        (void);
   UC   ucDelaiI2C;
};
#endif
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
