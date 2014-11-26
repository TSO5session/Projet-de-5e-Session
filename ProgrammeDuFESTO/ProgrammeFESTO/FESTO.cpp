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
// MaVar = CAN.Read();
return(NULL);
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
ucCapacitive = Capteur.readCapacitiveCaptor();
ucMagnetic   = Capteur.readInductiveCaptor ();
ucOptique    = Capteur.readOpticCaptor     ();

////////////Prise de décision
if(ucCapacitive == 1) // Si un bloc est présent
  {
   if((ucMagnetic == 1) && (ucOptique = 1))
     {
      ucColor = METAL;  
     }

   if((ucMagnetic == 0) && (ucOptique = 1))
     {
      ucColor = ORANGE;  
     }

   if((ucMagnetic == 0) && (ucOptique = 0))
     {
      ucColor = NOIR;  
     }
  }
else
  {
   ucColor = NOBLOC;
  }

////////////Écriture des résultats
if(ucColor == ORANGE)
  {
   LCD.String("Orange");
   SendToBolide("CounterClockWise");
   CAN.Write(3, 0x04, 0x01, 0xFF);
  }

if(ucColor == NOIR)
  {
   LCD.String("Noir");
   SendToBolide("STOP");
   CAN.Write(3, 0x04, 0x02, 0xFF);
  }

if(ucColor == METAL)
  {
   LCD.String("Metallic");
   SendToBolide("ClockWise");
   CAN.Write(3, 0x04, 0x00, 0xFF);
  }
if(ucColor == NOBLOC)
  {
   LCD.String("Empty");
  }
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
 CAN.Write(3, 0x07, 0x02, 0xFF);
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
UC CLFesto :: ucGestionFESTO (void)
{
UC ucCouleurDuBloc; 
  
if(IsTheBolideHere() == TRUE) // Si le bolide est présent à la station FESTO
  {
   if(Capteur.readInductiveCaptor() == NOBLOC) // S'il n'y a pas de bloc dans la zone de départ
     {
      Pompe.vPompeSOL725();  // Charge un bloc dans l'aire de chargement
      Delai(5000);
     }
   else // S'il y a un bloc dans l'aire de chargement
     {
      ucCouleurDuBloc = GetBlocColor();// Lit la couleur du bloc
      
      while((Capteur.readHeightCaptor()) != 66)     // Tant que la plateforme n'a pas fini de s'élever // Note: 66, c'est pas la bonne valeur
        {
         Pompe.vPompeSOL713();                      // Active la pompe d'élévation du bloc
        }
      
      while((Capteur.readPreVentouseCaptor()) != 1) // Tant que le bloc n'est pas au bout du convoyeur
        {
         Pompe.vPompeSOL722();                      // Envoie le bloc dans le convoyeur
        }
      Pompe.vPompeSOL719();                         // Rétracte la pompe d'envoie dans le convoyeur
     }
  }
return(0);
}

void CLFesto :: Delai(unsigned long Temps)
{
unsigned long k;
for(k = 0; k < Temps; k++);  
}
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX