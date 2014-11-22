// **************************Station1.cpp
// Auteur:       Prenom Nom
// Date:         18 novembre 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.1
//
// Description:
// *****************************************************************************
#include "DeclarationGenerale.h"  // Raccourcis de programmation & variables
#include "Station1.h"               // Fichier de definitions de...

//******************************************************************************
//                            LE CONSTRUCTEUR PAR DEFAUT
// *****************************************************************************
CLStation1 :: CLStation1(void)
{

}

//******************************************************************************
//                            LE CONSTRUCTEUR INITIALISATEUR
// *****************************************************************************
CLStation1 :: CLStation1(UC ucParametre)
{

}

// *****************************************************************************
//                            LE DESTRUCTEUR
// *****************************************************************************
CLStation1 :: ~CLStation1(void)
{

}

// ********************** FONCTION: WriteClock()
//
// DESCRIPTION:         Fonction pour écrire sur le DS1307 du uPSD
//
// INCLUDE:             "Station1.h"
//
// PROTOTYPE:           void WriteClock(UC, UC, UC, UC, UC, UC)
//
// PROCEDURE D'APPEL:   WriteClock(UC, UC, UC, UC, UC, UC)
//
// PARAMETRE D'ENTREE:  UC, UC, UC, UC, UC, UC
//
// PARAMETRE DE SORTIE: AUCUN
//
// Auteur:              Vincent Chouinard
// Date:                21 novembre 2014 (Version 1.0)
// *****************************************************************************
void CLStation1 :: WriteClock(UC AAAA, UC Mo, UC JJ, UC HH, UC MI, UC SS)
{
UC maVar = CAN.ReadMCP();       // Lit l'heure en provenance du PC 

Clock.stDate.ucJour     = JJ;   // Ajuste les jours
Clock.stDate.ucMois     = Mo;   // Ajuste les mois
Clock.stDate.ucAnnee    = AAAA; // Ajuste les secondes
Clock.vWriteDate();             // Écrit la date

Clock.stTemps.ucHeure   = HH;   // Ajuste les heures
Clock.stTemps.ucMinute  = MI;   // Ajuste les minutes
Clock.stTemps.ucSeconde = SS;   // Ajuste les secondes
Clock.vWriteTime();             // Écrit le temps
}

// ********************** FONCTION: ReadClock()
//
// DESCRIPTION:         Fonction pour lire la clock du PC
//
// INCLUDE:             "Station1.h"
//
// PROTOTYPE:           void WriteClock(void)
//
// PROCEDURE D'APPEL:   WriteClock(void)
//
// PARAMETRE D'ENTREE:  AUCUN
//
// PARAMETRE DE SORTIE: AUCUN
//
// Auteur:              Vincent Chouinard
// Date:                21 novembre 2014 (Version 1.0)
// *****************************************************************************
void CLStation1 :: ReadClock(void)
{
Clock.vReadTime(); 
Clock.vReadDate(); 
CAN.SendMCP("À faire: trouver comment envoyer l'heure");
}

// ********************** FONCTION: SendToPC()
//
// DESCRIPTION:         Fonction pour envoyer une trame CAN au PC
//
// INCLUDE:             "Station1.h"
//
// PROTOTYPE:           void SendToPC(string)
//
// PROCEDURE D'APPEL:   SendToPC(string)
//
// PARAMETRE D'ENTREE:  string
//
// PARAMETRE DE SORTIE: AUCUN
//
// Auteur:              Vincent Chouinard
// Date:                21 novembre 2014 (Version 1.0)
// *****************************************************************************
void CLStation1 :: SendToPC(const UC *Message)
{
  CAN.SendMCP(Message);  // Note: il faut gérer l'ID (EX.: PC = 000; SOC = 001, etc)
}

// ********************** FONCTION: SendToPIC()
//
// DESCRIPTION:         Fonction pour envoyer une trame CAN à la station de pesée
//
// INCLUDE:             "Station1.h"
//
// PROTOTYPE:           void SendToPIC(string)
//
// PROCEDURE D'APPEL:   SendToPIC(string)
//
// PARAMETRE D'ENTREE:  string
//
// PARAMETRE DE SORTIE: AUCUN
//
// Auteur:              Vincent Chouinard
// Date:                21 novembre 2014 (Version 1.0)
// *****************************************************************************
void CLStation1 :: SendToPIC(const UC *Message)
{
  CAN.SendMCP(Message);  // Note: il faut gérer l'ID (EX.: PC = 000; SOC = 001, etc)
}

// ********************** FONCTION: SendToSOC8200()
//
// DESCRIPTION:         Fonction pour envoyer une trame CAN au SOC8200
//
// INCLUDE:             "Station1.h"
//
// PROTOTYPE:           void SendToSOC8200(string)
//
// PROCEDURE D'APPEL:   SendToSOC8200(string)
//
// PARAMETRE D'ENTREE:  string
//
// PARAMETRE DE SORTIE: AUCUN
//
// Auteur:              Vincent Chouinard
// Date:                21 novembre 2014 (Version 1.0)
// *****************************************************************************
void CLStation1 :: SendToSOC8200(const UC *Message)
{
  CAN.SendMCP(Message);  // Note: il faut gérer l'ID (EX.: PC = 000; SOC = 001, etc)
}

// ********************** FONCTION: SendToBolide()
//
// DESCRIPTION:         Fonction pour envoyer une donnée au bolide via Xbee
//
// INCLUDE:             "Station1.h"
//
// PROTOTYPE:           void SendToBolide(string)
//
// PROCEDURE D'APPEL:   SendToBolide(string)
//
// PARAMETRE D'ENTREE:  string
//
// PARAMETRE DE SORTIE: AUCUN
//
// Auteur:              Vincent Chouinard
// Date:                21 novembre 2014 (Version 1.0)
// *****************************************************************************
void CLStation1 :: SendToBolide(const char *Message)
{
  XBee.SendCarac('B');     // Indique que le message est destiné au bolide
  XBee.SendString(Message);
}

// ********************** FONCTION: SendToFesto()
//
// DESCRIPTION:         Fonction pour envoyer une donnée à la table FESTO via Xbee
//
// INCLUDE:             "Station1.h"
//
// PROTOTYPE:           void SendToFesto(string)
//
// PROCEDURE D'APPEL:   SendToFesto(string)
//
// PARAMETRE D'ENTREE:  string
//
// PARAMETRE DE SORTIE: AUCUN
//
// Auteur:              Vincent Chouinard
// Date:                21 novembre 2014 (Version 1.0)
// *****************************************************************************
void CLStation1 :: SendToFesto(const char *Message)
{
  XBee.SendCarac('2');      // Indique que le message est destiné a la table FESTO
  XBee.SendString(Message);
}

// ********************** FONCTION: ReadFromPC()
//
// DESCRIPTION:         Fonction lire la trame reçue du PC
//
// INCLUDE:             "Station1.h"
//
// PROTOTYPE:           UC ReadFromPC(void)
//
// PROCEDURE D'APPEL:   maVar = ReadFromPC(void)
//
// PARAMETRE D'ENTREE:  AUCUN
//
// PARAMETRE DE SORTIE: UC
//
// Auteur:              Vincent Chouinard
// Date:                21 novembre 2014 (Version 1.0)
// *****************************************************************************
UC CLStation1 :: ReadFromPC (void)
{
  return(CAN.ReadMCP());    
}

// ********************** FONCTION: ReadFromPIC()
//
// DESCRIPTION:         Fonction lire la trame reçue du PIC
//
// INCLUDE:             "Station1.h"
//
// PROTOTYPE:           UC ReadFromPIC(void)
//
// PROCEDURE D'APPEL:   maVar = ReadFromPIC(void)
//
// PARAMETRE D'ENTREE:  AUCUN
//
// PARAMETRE DE SORTIE: UC
//
// Auteur:              Vincent Chouinard
// Date:                21 novembre 2014 (Version 1.0)
// *****************************************************************************
UC CLStation1 :: ReadFromPIC (void)
{
  return(CAN.ReadMCP());    
}

// ********************** FONCTION: ReadFromSOC()
//
// DESCRIPTION:         Fonction lire la trame reçue du SOC8200
//
// INCLUDE:             "Station1.h"
//
// PROTOTYPE:           UC ReadFromSOC(void)
//
// PROCEDURE D'APPEL:   maVar = ReadFromSOC(void)
//
// PARAMETRE D'ENTREE:  AUCUN
//
// PARAMETRE DE SORTIE: UC
//
// Auteur:              Vincent Chouinard
// Date:                21 novembre 2014 (Version 1.0)
// *****************************************************************************
UC CLStation1 :: ReadFromSOC   (void)
{
  return(CAN.ReadMCP());    
}

// ********************** FONCTION: ReadFromBolide()
//
// DESCRIPTION:         Fonction pour lire le Xbee du bolide
//
// INCLUDE:             "Station1.h"
//
// PROTOTYPE:           char = ReadFromBolide(void)
//
// PROCEDURE D'APPEL:   char = ReadFromBolide(void)
//
// PARAMETRE D'ENTREE:  AUCUN
//
// PARAMETRE DE SORTIE: char
//
// Auteur:              Vincent Chouinard
// Date:                21 novembre 2014 (Version 1.0)
// *****************************************************************************
char CLStation1 :: ReadFromBolide(void)
{
  if(XBee.GetChar() == '3') // Si c'est le bolide qui envoit
    {
     return(XBee.GetChar());
    }
  else
    {
     return(NULL);
    }    
}

char CLStation1 :: ReadFromFesto (void)
{
  if(XBee.GetChar() == '2') // Si c'est la table festo qui envoit
    {
     return(XBee.GetChar());
    }
  else
    {
     return(NULL);
    }      
}
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX