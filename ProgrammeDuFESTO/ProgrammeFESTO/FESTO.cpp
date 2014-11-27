// **************************FESTO.cpp
// Auteur:       Vincent Chouinard
// Date:         27 novembre 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.10
//
// Description:
// *****************************************************************************
#include "_DeclarationGenerale.h"  // Raccourcis de programmation & variables
#include "FESTO.h"                 // Fichier de definitions du gestionnaire de table festo

//******************************************************************************
//                            LE CONSTRUCTEUR PAR DEFAUT
// *****************************************************************************
CLFesto :: CLFesto(void)
{

}

//******************************************************************************
//                            LE CONSTRUCTEUR INITIALISATEUR
// *****************************************************************************
CLFesto :: CLFesto(UC ucParametre)
{

}

// *****************************************************************************
//                            LE DESTRUCTEUR
// *****************************************************************************
CLFesto :: ~CLFesto(void)
{

}

// **********************FONCTION: ReadInstructionFromPC()
//
// DESCRIPTION        : Lit des instructions CAN provenant du PC
//
// INCLUDE            : "_DeclarationGenerale.h" "FESTO.h"
//                      
// PROTOTYPE          : UC ReadInstructionFromPC(void)
//
// PROCEDURE D'APPEL  : data = ReadInstructionFromPC()
//
// PARAMETRE D'ENTREE : AUCUN
//
// PARAMETRE DE SORTIE: La trame CAN du PC
//
// Auteur             : Vincent Chouinard
// Date               : 25 novembre 2014   (Version 1.0)
// Modification       :
// *****************************************************************************
UC CLFesto :: ReadInstructionFromPC(void) 
{
  // Note: la station 1 lit le bus CAN et envoie par Xbee les infos appropriées à la table FESTO
return(NULL); // Il faut donc lire le Xbee!
}

// **********************FONCTION: SendToBolide()
//
// DESCRIPTION        : Envoie une donnée au bolide via Xbee
//
// INCLUDE            : "_DeclarationGenerale.h" "FESTO.h"
//                      
// PROTOTYPE          : void SendToBolide(char const)
//
// PROCEDURE D'APPEL  : SendToBolide("string")
//
// PARAMETRE D'ENTREE : char const
//
// PARAMETRE DE SORTIE: AUCUN
//
// Auteur             : Vincent Chouinard
// Date               : 25 novembre 2014   (Version 1.0)
// Modification       :
// *****************************************************************************
void CLFesto :: SendToBolide(char const *ucpMessage)
{
Xbee.Send('B');               // Envoie au bolide  
Xbee.SendString(ucpMessage);  // La commande passée en paramètres
}

// **********************FONCTION: SendToStation1()
//
// DESCRIPTION        : Envoie une donnée à la station 1 via Xbee
//
// INCLUDE            : "_DeclarationGenerale.h" "FESTO.h"
//                      
// PROTOTYPE          : void SendToStation1(char const)
//
// PROCEDURE D'APPEL  : SendToStation1("string")
//
// PARAMETRE D'ENTREE : char const
//
// PARAMETRE DE SORTIE: AUCUN
//
// Auteur             : Vincent Chouinard
// Date               : 25 novembre 2014   (Version 1.0)
// Modification       :
// *****************************************************************************
void CLFesto :: SendToStation1(char const *ucpMessage)
{
Xbee.Send('1');               // Envoie au bolide  
Xbee.SendString(ucpMessage);  // La commande passée en paramètres
}

// **********************FONCTION: GetBlocColor()
//
// DESCRIPTION        : Lit la couleur du bloc et retourne la
//
// INCLUDE            : "_DeclarationGenerale.h" "FESTO.h"
//                      
// PROTOTYPE          : UC GetBlocColor(void)
//
// PROCEDURE D'APPEL  : data = GetBlocColor()
//
// PARAMETRE D'ENTREE : AUCUN
//
// PARAMETRE DE SORTIE: UC
//
// Auteur             : Vincent Chouinard
// Date               : 25 novembre 2014   (Version 1.0)
// Modification       :
// *****************************************************************************
UC CLFesto :: GetBlocColor(void)
{
UC ucColor      = 0;
UC ucCapacitive = 0;
UC ucMagnetic   = 0;
UC ucOptique    = 0;

LCD.vLCDCursor(0,1);

////////////Lecture des capteurs
ucCapacitive = Capteur.ReadCapacitiveCaptor();
ucMagnetic   = Capteur.ReadInductiveCaptor ();
ucOptique    = Capteur.ReadOpticCaptor     ();

////////////Prise de décision
if(ucCapacitive == 1) // Si un bloc est présent
  {
   if((ucMagnetic == 1) && (ucOptique == 1))
     {
      ucColor = METAL;  
     }

   if((ucMagnetic == 0) && (ucOptique == 1))
     {
      ucColor = ORANGE;  
     }

   if((ucMagnetic == 0) && (ucOptique == 0))
     {
      ucColor = NOIR;  
     }
  }
else
  {
   ucColor = NOBLOC;
  }

////////////Écriture des résultats////////////
if(ucColor == ORANGE){LCD.String("Orange"  );}
if(ucColor == NOIR  ){LCD.String("Noir"    );}
if(ucColor == METAL ){LCD.String("Metallic");}
if(ucColor == NOBLOC){LCD.String("No bloc" );}
return(ucColor);
}

// **********************FONCTION: IsTheBolideHere()
//
// DESCRIPTION        : Vérifie et indique la présence du bolide
//
// INCLUDE            : "_DeclarationGenerale.h" "FESTO.h"
//                      
// PROTOTYPE          : UC IsTheBolideHere(void)
//
// PROCEDURE D'APPEL  : data = IsTheBolideHere()
//
// PARAMETRE D'ENTREE : AUCUN
//
// PARAMETRE DE SORTIE: UC
//
// Auteur             : Vincent Chouinard
// Date               : 25 novembre 2014   (Version 1.0)
// Modification       :
// *****************************************************************************
UC CLFesto :: IsTheBolideHere(void)
{
 LCD.String("Table FESTO");
 return(0);
}

// **********************FONCTION: ucGestionFESTO()
//
// DESCRIPTION        : Gère toute la séquence de la table Festo
//
// INCLUDE            : "_DeclarationGenerale.h" "FESTO.h"
//                      
// PROTOTYPE          : UC readMagneticCaptor(void)
//
// PROCEDURE D'APPEL  : data = readMagneticCaptor()
//
// PARAMETRE D'ENTREE : AUCUN
//
// PARAMETRE DE SORTIE: UC
//
// Auteur             : Vincent Chouinard
// Date               : 25 novembre 2014   (Version 1.0)
// Modification       :
// *****************************************************************************
void CLFesto :: ucGestionFESTO (void)
{
UC ucCouleur;  
LCD.vLCDCursor(0, 2);  

if(IsTheBolideHere() == VRAI) // Si le bolide est à la table festo
  {
   while(Capteur.ReadCapacitiveCaptor() == 0) // Tant qu'il n'y a pas de bloc dans l'aire de chargement
     {
      Pompe.SOL725();                         // Active la pompe de chargement
      LCD.String("SOL725 Active");
     }
   
   ucCouleur = GetBlocColor();                // Lit la couleur du bloc
   Pompe.SOL713();                            // Active la pompe qui fait monter la plateforme
   LCD.String("SOL713 Active");   
   
   while(Capteur.ReadHeightCaptor() == 0)     // Tant que la platefore n'a pas fini de monter
     {
      Pompe.SOL713();                         // Active la pompe qui fait monter la plateforme
     }
   
   Pompe.SOL722();                            // Active la pompe qui envoie sur le convoyeur
   LCD.String("SOL722 Active");
         
   while(Capteur.ReadPreVentouseCaptor() == 0) // Tant que le bloc est encore sur le convoyeur
     {
      Pompe.SOL722();                          // Maintient active la pompe qui envoie sur le convoyeur
     }
   
   Pompe.SOL716();                           // Rétracte la pompe d'envoie dans le convoyeur
   Pompe.SOL719();                           // Abaisse la plateforme élévatrice
  }
else // Si le bolide n'est pas à la table festo
  {
   LCD.String("No bolid"); // Affiche un message sur l'écran LCD  
  }

if(IsTheBlocInTheBolid() == TRUE)        // Si le bloc est retombé dans le bolide
  {
   if(ucCouleur == ORANGE)               // Si le bloc est orange
    {
     SendToBolide("CounterClockWise");   // Donne une instruction au Bolide
     SendToStation1("CounterClockWise"); // Donne l'info au PC via la station 1
    }

   if(ucCouleur == NOIR)                 // Si le bloc est noir
    {
     SendToBolide("STOP");               // Donne une instruction au Bolide
     SendToStation1("STOP");             // Donne l'info au PC via la station 1
    }

   if(ucCouleur == METAL)                // Si le bloc est métallique
    {
     SendToBolide("ClockWise");          // Donne une instruction au Bolide
     SendToStation1("ClockWise");        // Donne l'info au PC via la station 1
    }

   if(ucCouleur == NOBLOC)               // S'il n'y a pas de bloc
    {
     SendToBolide("No bloc");            // Donne une instruction au Bolide
     SendToStation1("No bloc");          // Donne l'info au PC via la station 1
    } 
  }
}

UC CLFesto :: IsTheBlocInTheBolid (void) // Retourne 1 lorsque le bloc est retombé dans le bolide
{
return(1);  
}

void CLFesto :: Delai(UINT32 Temps)
{
unsigned long k;
for(k = 0; k < Temps; k++);  
}
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX