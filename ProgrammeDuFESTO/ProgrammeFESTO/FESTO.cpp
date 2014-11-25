// **************************FESTO.cpp
// Auteur:       Prenom Nom
// Date:         19 Octobre 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.1
//
// Description:
// *****************************************************************************
#include "_DeclarationGenerale.h"  // Raccourcis de programmation & variables
#include "FESTO.h"               // Fichier de definitions de...

//******************************************************************************
//                            LE CONSTRUCTEUR PAR DEFAUT
// *****************************************************************************
CLFesto :: CLFesto(void)
{

}

//******************************************************************************
//                            LE CONSTRUCTEUR INITIALISATEUR
// *****************************************************************************
CLFesto :: CLFesto(unsigned char ucParametre)
{

}

// *****************************************************************************
//                            LE DESTRUCTEUR
// *****************************************************************************
CLFesto :: ~CLFesto(void)
{

}

UC CLFesto :: ReadInstructionFromPC(void)
{
//UC Commande[8] = CAN.Read();  
}

void CLFesto :: SendToBolide(char const *ucpMessage)
{
Xbee.Send('B');               // Envoie au bolide  
Xbee.SendString(ucpMessage);  // La commande passée en paramètres
}

void CLFesto :: SendToStation1(char const *ucpMessage)
{
Xbee.Send('1');               // Envoie au bolide  
Xbee.SendString(ucpMessage);  // La commande passée en paramètres
}

UC CLFesto :: GetBlocColor(void)
{
UC ucColor = 0;
LCD.vLCDCursor(0,1);

if(ucColor == ORANGE)
  {
   LCD.String("Orange");
   SendToBolide("CounterClockWise");
  }

if(ucColor == NOIR)
  {
   LCD.String("Noir");
   SendToBolide("STOP");
  }

if(ucColor == METAL)
  {
   LCD.String("Metallic");
   SendToBolide("ClockWise");
  }
return(ucColor);
}

UC CLFesto ::IsTheBolideHere(void)
{
  
}
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX