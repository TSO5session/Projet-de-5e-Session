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

// ********************** FONCTION: SendString()
//
// DESCRIPTION:         Fonction pour envoyer un string sur Xbee
//
// INCLUDE:             "CLXBEE.h"
//
// PROTOTYPE:           void SendString(void)
//
// PROCEDURE D'APPEL:   SendString()
//
// PARAMETRE D'ENTREE:  string
//
// PARAMETRE DE SORTIE: AUCUN
//
// Auteur:              Vincent Chouinard
// Date:                21 novembre 2014 (Version 1.0)
// *****************************************************************************
void CLXbee :: SendString(char const *ucMonString)
{
  Serial.SendString(ucMonString);  
}

// ********************** FONCTION: SendCarac()
//
// DESCRIPTION:         Fonction pour envoyer un cractère ASCII sur Xbee
//
// INCLUDE:             "CLXBEE.h"
//
// PROTOTYPE:           void SendCarac(void)
//
// PROCEDURE D'APPEL:   SendCarac()
//
// PARAMETRE D'ENTREE:  UC
//
// PARAMETRE DE SORTIE: AUCUN
//
// Auteur:              Vincent Chouinard
// Date:                21 novembre 2014 (Version 1.0)
// *****************************************************************************
void CLXbee :: SendCarac(UC ucCar)
{
  Serial.Send(ucCar);
}

// ********************** FONCTION: SendNumber()
//
// DESCRIPTION:         Fonction pour envoyer un integer sur Xbee
//
// INCLUDE:             "CLXBEE.h"
//
// PROTOTYPE:           void SendNumber(void)
//
// PROCEDURE D'APPEL:   SendNumber()
//
// PARAMETRE D'ENTREE:  unsigned int
//
// PARAMETRE DE SORTIE: AUCUN
//
// Auteur:              Vincent Chouinard
// Date:                21 novembre 2014 (Version 1.0)
// *****************************************************************************
void CLXbee :: SendNumber(UI uiChiffreAAfficher)
{
  Serial.SendNumber(uiChiffreAAfficher);  
}

// ********************** FONCTION: GetChar()
//
// DESCRIPTION:         Fonction pour lire le buffer RS232
//
// INCLUDE:             "CLXBEE.h"
//
// PROTOTYPE:           UC GetChar(void)
//
// PROCEDURE D'APPEL:   GetChar()
//
// PARAMETRE D'ENTREE:  AUCUN
//
// PARAMETRE DE SORTIE: UC
//
// Auteur:              Vincent Chouinard
// Date:                21 novembre 2014 (Version 1.0)
// *****************************************************************************
UC CLXbee :: GetChar(void)
{
  return(Serial.GetChar());  
}
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
