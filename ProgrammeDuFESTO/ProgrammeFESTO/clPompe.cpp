// **************************CLPompe.cpp
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
#include "CLPompe.h"               // Fichier de definitions de...

//******************************************************************************
//                            LE CONSTRUCTEUR PAR DEFAUT
// *****************************************************************************
CLPompe :: CLPompe(void)
{

}

//******************************************************************************
//                            LE CONSTRUCTEUR INITIALISATEUR
// *****************************************************************************
CLPompe :: CLPompe(UC ucParametre)
{

}

// *****************************************************************************
//                            LE DESTRUCTEUR
// *****************************************************************************
CLPompe :: ~CLPompe(void)
{

}

// **********************FONCTION: vPompeSOL725()
//
// DESCRIPTION        : Pompe de chargement de marchandise à partir du tube de stockage
//
// INCLUDE            : "_DeclarationGenerale.h" "CLPompe.h"
//                      
// PROTOTYPE          : void vPompeSOL725(void)
//
// PROCEDURE D'APPEL  : vPompeSOL725()
//
// PARAMETRE D'ENTREE : AUCUN
//
// PARAMETRE DE SORTIE: AUCUN
//
// Auteur             : Vincent Chouinard
// Date               : 25 novembre 2014   (Version 1.0)
// Modification       :
// *****************************************************************************
void CLPompe :: SOL725 (void)
{
PCF1.Write(AdresseSOL725);  
}

// **********************FONCTION: vPompeSOL713()
//
// DESCRIPTION        : Pompe d'élévation de la plateforme avec capteurs
//
// INCLUDE            : "_DeclarationGenerale.h" "CLPompe.h"
//                      
// PROTOTYPE          : void vPompeSOL713(void)
//
// PROCEDURE D'APPEL  : vPompeSOL725()
//
// PARAMETRE D'ENTREE : AUCUN
//
// PARAMETRE DE SORTIE: AUCUN
//
// Auteur             : Vincent Chouinard
// Date               : 25 novembre 2014   (Version 1.0)
// Modification       :
// *****************************************************************************
void CLPompe :: SOL713 (void)
{
PCF1.Write(AdresseSOL713);  
}

// **********************FONCTION: vPompeSOL713()
//
// DESCRIPTION        : Rétraction de la pompe d'élévation de la plateforme avec capteurs
//
// INCLUDE            : "_DeclarationGenerale.h" "CLPompe.h"
//                      
// PROTOTYPE          : void vPompeSOL713(void)
//
// PROCEDURE D'APPEL  : vPompeSOL725()
//
// PARAMETRE D'ENTREE : AUCUN
//
// PARAMETRE DE SORTIE: AUCUN
//
// Auteur             : Vincent Chouinard
// Date               : 25 novembre 2014   (Version 1.0)
// Modification       :
// *****************************************************************************
void CLPompe :: SOL716 (void)
{
PCF1.Write(AdresseSOL716);  
}

// **********************FONCTION: vPompeSOL722()
//
// DESCRIPTION        : Envoie le bloc dans le convoyeur
//
// INCLUDE            : "_DeclarationGenerale.h" "CLPompe.h"
//                      
// PROTOTYPE          : void vPompeSOL722(void)
//
// PROCEDURE D'APPEL  : vPompeSOL722()
//
// PARAMETRE D'ENTREE : AUCUN
//
// PARAMETRE DE SORTIE: AUCUN
//
// Auteur             : Vincent Chouinard
// Date               : 25 novembre 2014   (Version 1.0)
// Modification       :
// *****************************************************************************
void CLPompe :: SOL722 (void)
{
PCF1.Write(AdresseSOL722);  
}

// **********************FONCTION: vPompeSOL722()
//
// DESCRIPTION        : Rétracte la pompe SOL722
//
// INCLUDE            : "_DeclarationGenerale.h" "CLPompe.h"
//                      
// PROTOTYPE          : void vPompeSOL722(void)
//
// PROCEDURE D'APPEL  : vPompeSOL722()
//
// PARAMETRE D'ENTREE : AUCUN
//
// PARAMETRE DE SORTIE: AUCUN
//
// Auteur             : Vincent Chouinard
// Date               : 25 novembre 2014   (Version 1.0)
// Modification       :
// *****************************************************************************
void CLPompe :: SOL719 (void)
{
PCF2.Write(AdresseSOL719);  
}

// **********************FONCTION: vPompeSOL704()
//
// DESCRIPTION        : Baisse la ventouse
//
// INCLUDE            : "_DeclarationGenerale.h" "CLPompe.h"
//                      
// PROTOTYPE          : void vPompeSOL704(void)
//
// PROCEDURE D'APPEL  : vPompeSOL704()
//
// PARAMETRE D'ENTREE : AUCUN
//
// PARAMETRE DE SORTIE: AUCUN
//
// Auteur             : Vincent Chouinard
// Date               : 25 novembre 2014   (Version 1.0)
// Modification       :
// *****************************************************************************
void CLPompe :: SOL704 (void)
{
PCF2.Write(AdresseSOL704);  
}

// **********************FONCTION: vPompeSOL706()
//
// DESCRIPTION        : Remonte la ventouse
//
// INCLUDE            : "_DeclarationGenerale.h" "CLPompe.h"
//                      
// PROTOTYPE          : void vPompeSOL706(void)
//
// PROCEDURE D'APPEL  : vPompeSOL706()
//
// PARAMETRE D'ENTREE : AUCUN
//
// PARAMETRE DE SORTIE: AUCUN
//
// Auteur             : Vincent Chouinard
// Date               : 25 novembre 2014   (Version 1.0)
// Modification       :
// *****************************************************************************
void CLPompe :: SOL706 (void)
{
PCF2.Write(AdresseSOL706);  
}
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX