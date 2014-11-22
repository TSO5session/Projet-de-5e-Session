// ********************** FICHIER: CLPcf8574.cpp******************************
// Descrtiption : La classe contient des fonctions pour controler le PCF
//              : 8574 sur le suiveur de ligne et sur le bolide
//
// Composition  : CLI2CPort
//
// Heritage     : Aucun
//
// Fonctions    : void vWritePCF8574 (ucAdresse, ucDonnee)//Ecrit Adr, Donnee
//                UC ucReadPCF8574 (UC ucAdresse)  //Read un canal du ADC
//
//  AUTEUR : Gabriel Fortin-Bélanger
//  DATE CREATION :    12/02/2014		 VERSION: 1.0
//
// ****************************************************************************

#include "_DeclarationGenerale.h"
#include "CLIOPcf8574.h"
#include "CLI2CPort.h"


// ******************************CLPcf8574**************************************
//
//Description: Constructeur defaut du PCF8574            
//
// Nom : CLPcf8574 :: CLPcf8574(void)
//
// Parametre d'entree : AUCUN
//
// Parametre sortie : AUCUN
//
//
// Membres utilisés 
//    Fonctions : vI2CEcrireDonnee -- Ecrire Donnee en I2C
//    DOnnees   : Adresse chip, donnee a ecrire
//
// Auteur : Gabriel Fortin-Bélanger
// Date crée : 27/03/2014
// Date modif :
// ****************************************************************************
CLIOPcf8574 :: CLIOPcf8574(void)
 {
   
 }
// *******************CLPcf8574(UC ucAdresse, UC ucDonnee)**********************
//
//Description: Constructeur initialisateur de la classe PCF8574           
//
// Nom : CLPcf8574 :: CLPcf8574(UC ucAdresse, UC ucDonnee)
//
// Parametre d'entree : ucAdresse -- Adresse du CHIP
//                    : ucDonnee  -- Donnee a ecrire
//
// Parametre sortie : AUCUN
//
//
// Membres utilisés 
//    Fonctions : vI2CEcrireDonnee -- Ecrire Donnee en I2C
//    DOnnees   : Adresse chip, donnee a ecrire
//
// Auteur : Gabriel Fortin-Bélanger
// Date crée : 27/03/2014
// Date modif :
// ****************************************************************************
CLIOPcf8574 :: CLIOPcf8574(UC ucAdresse, UC ucDonnee)
 {
   ucAdressePCF8574 = ucAdresse;
   //vI2CEcrireDonnee(ucAdressePCF8574,0 ,ucDonnee);
 
 }

// ***************************~CLPcf85754 (void)*******************************
//
//Description: Destructeur par defaut de la classe PCF8574           
//
// Nom : CLPcf8574 :: ~CLPcf85754 (void)
//
// Parametre d'entree : AUCUN
//                    : AUCUN
//
// Parametre sortie : AUCUN
//
//
// Membres utilisés 
//    Fonctions : 
//    DOnnees   : 
//
// Auteur : Gabriel Fortin-Bélanger
// Date crée : 27/03/2014
// Date modif :
// ****************************************************************************
CLIOPcf8574 :: ~CLIOPcf8574 (void)
 {
 }

// ****************vWritePCF8574(UC ucAdresse, UC ucDonnee)*********************
//
//Description: Ecrire des donnees vers le PCF8574         
//
// Nom : CLPcf8574 :: vWritePCF8574(UC ucAdresse, UC ucDonnee)
//
// Parametre d'entree : ucAdresse -- Adresse du CHIP
//                    : ucDonnee  -- Donnee a ecrire
//
// Parametre sortie : AUCUN
//
//
// Membres utilisés 
//    Fonctions : vI2CEcrireDonnee -- Ecrire Donnee en I2C
//    DOnnees   : Adresse chip, donnee a ecrire
//
// Auteur : Gabriel Fortin-Bélanger
// Date crée : 27/03/2014
// Date modif :
// ****************************************************************************
void CLIOPcf8574 :: vWritePCF8574(UC ucAdresse, UC ucDonnee)
 {
    
    vI2CEcrireDonnee(ucAdresse,0 , 0 ,ucDonnee);
 }

// ****************vWritePCF8574(UC ucAdresse, UC ucDonnee)*********************
//
//Description: Lit des donnees du PCF8574 , ACK seconde lecture ou non        
//
// Nom : UC CLPcf8574 :: ucReadPCF8574 (UC ucAdresse, UC ucAck)
//
// Parametre d'entree : ucAdresse -- Adresse du CHIP
//                    : ucAck     -- Plusieurs lectures?
//
// Parametre sortie : ucRetourValeur -- Valeur Lue du PCF
//
//
// Membres utilisés 
//    Fonctions : ucI2CLireDonnee -- Lire Donnee en I2C
//    DOnnees   : Adresse chip, ACK ou NACK
//
// Auteur : Gabriel Fortin-Bélanger
// Date crée : 27/03/2014
// Date modif :
// ****************************************************************************
UC CLIOPcf8574 :: ucReadPCF8574 (UC ucAdrChip, US usiAdrDepart,UC ucTypeAdr)
 {
 
   return (  ucI2CLireDonnee(ucAdrChip,0 ,0));
 }

