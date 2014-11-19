// **************************Fichier.cpp
// Auteur:       Prenom Nom
// Date:         19 Octobre 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.1
//
// Description:
// *****************************************************************************
#include "DeclarationGenerale.h"  // Raccourcis de programmation & variables
#include "CLXBEE.h"               // Fichier de definitions de communication XBEE
//#include "CLRS232.h"              // En-tete de communication RS232

//******************************************************************************
//                            LE CONSTRUCTEUR PAR DEFAUT
// *****************************************************************************
CLXbee :: CLXbee(void)
{

}

//******************************************************************************
//                            LE CONSTRUCTEUR INITIALISATEUR
// *****************************************************************************
CLXbee :: CLXbee(UC ucParametre)
{

}

// *****************************************************************************
//                            LE DESTRUCTEUR
// *****************************************************************************
CLXbee :: ~CLXbee(void)
{

}

void CLXbee :: SendString(char const *ucMonString)
{
Serial.SendString(ucMonString);  
}

void CLXbee :: SendCarac(UC ucCar)
{
Serial.Send(ucCar);
}

void CLXbee :: SendNumber(UI uiChiffreAAfficher)
{
Serial.SendNumber(uiChiffreAAfficher);  
}

UC CLXbee :: GetChar(void)
{
return(Serial.GetChar());  
}
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
