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
#include "_DeclarationGenerale.h"  // Raccourcis de programmation & variables
#include "ADConvert.h"             //
#include "CLInOutBase.h"           //

//******************************************************************************
//                            LE CONSTRUCTEUR PAR DEFAUT
// *****************************************************************************
AD7829 :: AD7829(void)
{

}

//******************************************************************************
//                            LE CONSTRUCTEUR INITIALISATEUR
// *****************************************************************************
AD7829 :: AD7829(UC ucParametre)
{

}

// *****************************************************************************
//                            LE DESTRUCTEUR
// *****************************************************************************
AD7829 :: ~AD7829(void)
{

}

void AD7829 :: DAC(UC ucChannel, UC ucData)
{
unsigned int uiAdresseDA = 0xFA28 + ucChannel;

vOut (0xFA20,      ucData);       // Écriture de la donnée sur le latch (activation via chip select)
vOut (uiAdresseDA, ucData);       // Transfert de la donnée du latch au convertisseur (via chip select)
}

UC AD7829 :: ADC(UC ucChannel)
{
UC ucEssai;
unsigned int uiAdresseAD;

uiAdresseAD = 0xFA08 + ucChannel; //Ajoute l'adresse au canal      
ucEssai     = ucIn(uiAdresseAD);  //Chip select du ADC7829
P3_3        = 0;                  //Demande de conversion
P3_3        = 1;                  //Demande de conversion

while (P3_2 == 0);                //Attente de fin de conversion
  {
   ucEssai = ucIn(uiAdresseAD);   //Lecture du convertisseur
  }
  
//Version de programme pour la carte IO BUG ver2 ou il n'y a pas de buffer sur le bus de donnees
//ucEssai = ucInput(0xFA10);         //Lecture du buffer du convertisseur AD
return(ucEssai);
}

//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX