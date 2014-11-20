
#include "CLI2CBase.h"

// *****************************************************************************
//                            LES CONSTRUCTEURS
// *****************************************************************************
CLI2CBase :: CLI2CBase(void)
{
ucDelaiI2C = 5;
}

CLI2CBase :: CLI2CBase(UC ucDelai)
{
ucDelaiI2C = ucDelai;
}

// *****************************************************************************
//                            LE DESTRUCTEUR
// *****************************************************************************
CLI2CBase :: ~CLI2CBase(void)
{

}

///////////////////////////////////////////////////////////////////////////////
// void CLI2CBase :: vI2CStart(void)
///////////////////////////////////////////////////////////////////////////////
//
// Description:
//
// Parametres d'entrees: null
//
// Parametres de sortie: null
//
// Appel de la fonction:
//
// Cree le  4 avril 2014 par Louis-Normand Ang Houle
//
// Modifications:
// -
//
///////////////////////////////////////////////////////////////////////////////
void CLI2CBase :: vI2CStart(void)
{
SDA = HAUT;                              //Met SDA a 1
SCL = HAUT;                              //Met SCL a 1
vDelaiI2C();                             //Delai
SDA = BAS;                               //Met SDA a 0
vDelaiI2C();                             //Delai
SCL = BAS;                               //Met SCL a 0
vDelaiI2C();                             //Delai
}

///////////////////////////////////////////////////////////////////////////////
// void CLI2CBase :: vI2CStop(void)
///////////////////////////////////////////////////////////////////////////////
//
// Description:
//
// Parametres d'entrees: null
//
// Parametres de sortie: null
//
// Appel de la fonction:
//
// Cree le  4 avril 2014 par Louis-Normand Ang Houle
//
// Modifications:
// -
//
///////////////////////////////////////////////////////////////////////////////

void CLI2CBase :: vI2CStop(void)
{
SDA = BAS;                               //Met SDA a 0
SCL = BAS;                               //Met SCL a 0
vDelaiI2C();                             //Delai
SCL = HAUT;                              //Met SCL a 1
vDelaiI2C();                             //Delai
SDA = HAUT;                              //Met SDA a 1
vDelaiI2C();                             //Delai
}

///////////////////////////////////////////////////////////////////////////////
// UC   CLI2CBase :: ucI2CLireBit(void)
///////////////////////////////////////////////////////////////////////////////
//
// Description:
//
// Parametres d'entrees: null
//
// Parametres de sortie: null
//
// Appel de la fonction:
//
// Cree le  4 avril 2014 par Louis-Normand Ang Houle
//
// Modifications:
// -
//
///////////////////////////////////////////////////////////////////////////////

UC CLI2CBase :: ucI2CLireBit(void)
{
UC ucBit;
SDA = HAUT;
vDelaiI2C();
SCL = HAUT;
vDelaiI2C();
ucBit = SDA;
vDelaiI2C();
SCL = BAS;
vDelaiI2C();
return (ucBit);
}

///////////////////////////////////////////////////////////////////////////////
// void CLI2CBase :: vI2CEcrireBit(UC ucBit)
///////////////////////////////////////////////////////////////////////////////
//
// Description:
//
// Parametres d'entrees: null
//
// Parametres de sortie: null
//
// Appel de la fonction:
//
// Cree le  4 avril 2014 par Louis-Normand Ang Houle
//
// Modifications:
// -
//
///////////////////////////////////////////////////////////////////////////////

void CLI2CBase :: vI2CEcrireBit(UC ucBit)
{
SDA = ucBit;
vDelaiI2C();
SCL = HAUT;
vDelaiI2C();
SCL = BAS;
vDelaiI2C();
}

///////////////////////////////////////////////////////////////////////////////
// UC CLI2CBase :: ucI2CLireOctet(UC ucAck)
///////////////////////////////////////////////////////////////////////////////
//
// Description:
//
// Parametres d'entrees: null
//
// Parametres de sortie: null
//
// Appel de la fonction:
//
// Cree le  4 avril 2014 par Louis-Normand Ang Houle
//
// Modifications:
// -
//
///////////////////////////////////////////////////////////////////////////////

UC CLI2CBase :: ucI2CLireOctet(UC ucAck)
{
UC ucLecture = 0x00;              //Variable de reception

for(UC i=0; i < 8; i++)           //Repeter 8 fois
  {
   if(ucI2CLireBit() == 1)        //Si lecture retourne 1
     {
      ucLecture = ucLecture + 1;  //Additionne 1 a LireOctet
     }
   ucLecture = ucLecture << 1;    //Decale LireOctet 1 vers gauche
  }
vI2CEcrireBit(ucAck);
return(ucLecture);                //Retourne l'octet lue
 }

///////////////////////////////////////////////////////////////////////////////
// UC CLI2CBase :: ucI2CEcrireOctet(UC ucOctet)
///////////////////////////////////////////////////////////////////////////////
//
// Description:
//
// Parametres d'entrees: null
//
// Parametres de sortie: null
//
// Appel de la fonction:
//
// Cree le  4 avril 2014 par Louis-Normand Ang Houle
//
// Modifications:
// -
//
///////////////////////////////////////////////////////////////////////////////
UC CLI2CBase :: ucI2CEcrireOctet(UC ucOctet)
{
for(UC i=0; i<8; i++)
  {
   if((ucOctet & 0x80) == 0) vI2CEcrireBit(0);
   else                      vI2CEcrireBit(1);
      ucOctet = ucOctet << 1;
  }
return (ucI2CLireBit());
}

///////////////////////////////////////////////////////////////////////////////
// void CLI2CBase :: vDelaiI2C(void)
///////////////////////////////////////////////////////////////////////////////
//
// Description:
//
// Parametres d'entrees: null
//
// Parametres de sortie: null
//
// Appel de la fonction:
//
// Cree le  4 avril 2014 par Louis-Normand Ang Houle
//
// Modifications:
// -
//
///////////////////////////////////////////////////////////////////////////////
void CLI2CBase :: vDelaiI2C(void)
{
for (UC i= ucDelaiI2C; i>0; i--);
}

//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
