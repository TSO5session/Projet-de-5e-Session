// **************************CLSortieLatch.cpp
// Auteur:       Vincent Chouinard
// Date:         20 juillet 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.1
//
// Description:
// *****************************************************************************
// Le channel du convertisseur ADC va de 0xFA08 a 0xFA0F
// Le channel du convertisseur DAC va de...
// *****************************************************************************
#include "_DeclarationGenerale.h"  // Raccourcis de programmation & variables
#include "CLSortieLatch.h"              // Fichier de definitions du clavier
#include "CLInOutBase.h"


//******************************************************************************
//                            LE CONSTRUCTEUR PAR DEFAUT
// *****************************************************************************
DAC_ADC :: DAC_ADC(void)
{

}

//******************************************************************************
//                            LE CONSTRUCTEUR PAR DEFAUT
// *****************************************************************************
DAC_ADC :: DAC_ADC(UC ucParametre)
{

}

// *****************************************************************************
//                            LE DESTRUCTEUR
// *****************************************************************************
DAC_ADC :: ~DAC_ADC(void)
{

}

void DAC_ADC :: DAC(UC ucChannel, UC ucData)
{
unsigned int uiAdresseDA;
uiAdresseDA = 0xFA28 + ucChannel;

vOut (0xFA20, ucData);            // Écriture de la donnée sur le latch (activation via chip select)
vOut (uiAdresseDA, ucData);       // Transfert de la donnée du latch au convertisseur (via chip select)
}







UC DAC_ADC :: ADC(UC ucChannel)
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
//   ucEssai = ucInput(0xFA10);         //Lecture du buffer du convertisseur AD
   return (ucEssai);
}



//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
