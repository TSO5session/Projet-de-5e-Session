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

void CLStation1 :: WriteClockStation3(UC AAAA, UC Mo, UC JJ, UC HH, UC MI, UC SS)
{
Clock.stDate.ucJour     = JJ;   // Ajuste les jours
Clock.stDate.ucMois     = Mo;   // Ajuste les mois
Clock.stDate.ucAnnee    = AAAA; // Ajuste les secondes
Clock.vWriteDate();             // Écrit la date

Clock.stTemps.ucHeure   = HH;   // Ajuste les heures
Clock.stTemps.ucMinute  = MI;   // Ajuste les minutes
Clock.stTemps.ucSeconde = SS;   // Ajuste les secondes
Clock.vWriteTime();             // Écrit le temps
 
}

void CLStation1 :: ReadClock(void)
{
Clock.vReadTime(); 
Clock.vReadDate();   
}

void CLStation1 :: SendToPC(const UC *Message)
{
  CAN.SendMCP(Message);  // Note: il faut gérer l'ID
}

void CLStation1 :: SendToPIC(const UC *Message)
{
  CAN.SendMCP(Message);  // Note: il faut gérer l'ID
}

void CLStation1 :: SendToSOC(const UC *Message)
{
  CAN.SendMCP(Message);  // Note: il faut gérer l'ID
}

void CLStation1 :: SendToBolide(const char *Message)
{
  XBee.SendCarac('B');     // Indique que le message est destiné au bolide
  XBee.SendString(Message);
}

void CLStation1 :: SendToFesto(const char *Message)
{
  XBee.SendCarac('F');      // Indique que le message est destiné a la table FESTO
  XBee.SendString(Message);
}

UC CLStation1 :: ReadFromPC    (void)
{
  return(CAN.ReadMCP());    
}

UC CLStation1 :: ReadFromPIC   (void)
{
  return(CAN.ReadMCP());    
}

UC CLStation1 :: ReadFromSOC   (void)
{
  return(CAN.ReadMCP());    
}

char CLStation1 :: ReadFromBolide(void)
{
  if(XBee.GetChar() == 'B') // Si c'est le bolide qui envoit
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
  if(XBee.GetChar() == 'F') // Si c'est la table festo qui envoit
    {
     return(XBee.GetChar());
    }
  else
    {
     return(NULL);
    }      
}
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX