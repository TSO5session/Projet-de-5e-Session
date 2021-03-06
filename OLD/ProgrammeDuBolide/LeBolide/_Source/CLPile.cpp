// ********************** FICHIER: CLPile.cpp
//  Auteur:      Vincent Chouinard
//  Date:        17 avril 2014
//  Version :    1.0
//
//  CLPile         ---> Constructeur par defaut
//  CLPile(UINT16) ---> Constructeur initialisateur
// ~CLPile         ---> Destructeur
//
//  ucLirePile     ---> Met le MAX1236 en mode "Lecture de la pile" et retourne
//                      une valeur correspondant au niveau de tension de la pile
//
//  Compilateur: IAR 8.1
//
//  Description: Fichier de definitions pour lire le niveau de tension de la
//               pile.
// *****************************************************************************
#include "CLPile.h"
#include "DeclarationGenerale.h"

//******************************************************************************
//                            LE CONSTRUCTEUR PAR DEFAUT
// *****************************************************************************
CLPile :: CLPile(void)
{

}

//******************************************************************************
//                            LE CONSTRUCTEUR INITIALISATEUR
// *****************************************************************************
CLPile :: CLPile(UC ucParametre)
{

}

// *****************************************************************************
//                            LE DESTRUCTEUR
// *****************************************************************************
CLPile :: ~CLPile(void)
{

}

// **********************FONCTION: ucLirePile()
//
// DESCRIPTION: Lit la valeur de la pile sur le MAX1236, converti cette valeur 
//              en decimale la retourne a la fonction appelante.
//
// INCLUDE: "DeclarationGenerale.h"
//          "CLADCMAX1236.h"
//          "CLPile.h"
//
// PROTOTYPE:           UC ucLirePile(void)
//
// PROCEDURE D'APPEL:   UC = ucLirePile();
//
// PARAMETRE D'ENTREE:  AUCUN
//
// PARAMETRE DE SORTIE: UC ---> Niveau de tension de la pile
//
// Auteur:              Vincent Chouinard
// Date:                17 avril 2014   (Version 1.0)
// Modification:        Premiere version
// *****************************************************************************
float CLPile :: fLirePile(void)
{
// 0xFFF = 10.8v
// 0x000 = 0v
// Chaque pas vaut 2.64mV  

#ifdef I2C_DALLAS 
float fTensionPile = uiLireValeur(PILE);// Met le MAX1236 en mode "Lire Pile"
                                        // et lit les 2 octets transmis
fTensionPile *= CONVPILE;               // Retourne une valeur decimale 
return(fTensionPile);                   // correspondant a la tension de la pile
#endif                                  

#ifdef SPI_DALLAS 
float fTensionPile = uiLireConversion(TLV2554_CAN3);// Met le MAX1236 en mode "Lire Pile"
                                            // et lit les 2 octets transmis       
fTensionPile *= CONVPILE;
return(fTensionPile);                       // Retourne une valeur decimale    
                                            // correspondant a la tension de la pile
#endif                                  


}




//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX