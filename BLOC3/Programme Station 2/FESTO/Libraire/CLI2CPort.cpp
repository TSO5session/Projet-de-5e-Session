// ***************** FICHIER:CLI2CPort.cpp
//
//  Description:Contient les fonctions haut niveau pour communiquer avec 
//              l I2C.
//             
//
//  Application realisee avec IAR
//
//  AUTEUR : Gabriel Fortin-Belanger
//  DATE CREATION :    2014-02-07		 VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
//******************************************************************************
#include "CLInOutBase.h"
#include "_DeclarationGenerale.h"
#include "CLI2CPort.h"


//*******************************Constantes************************************
#define PASADRESSE 0
#define ADR8BIT    1
#define ADR16BIT   2
//******************************************************************************

//***********************CLI2CPort(void)
//
//Description:Ce constructeur par defaut est appeler lors de la creation 
// d un objet 
//
// Nom:CLPiece :: CLPiece(void)
//           et ne fais rien
// PARAMETRE D'ENTREE: -
//                  
// 
//
// PARAMETRE DE SORTIE: -             
//
//    
// Membre utilise: 
//
//
// DATE DE CREATION: 10 octobre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************
CLI2CPort:: CLI2CPort(void)   //Constructeur defaut
{
  
}

//***********************~CLI2CPort(void) 
//
//Description:Destructeur de CLI2cPort. Ne fais rien
//          
//
// Nom:CLPiece :: ~CLI2CPort(void)
//           
// PARAMETRE D'ENTREE:  -
//                        
//                  
// 
//
// PARAMETRE DE SORTIE: -             
//
//    
// Membre utilise: 
//
//
// DATE DE CREATION: 10 octobre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************
CLI2CPort :: ~CLI2CPort(void)   
{
 
  
}


//***********************Fonction:ucI2CEcrireDonnee
//
//Description:Cette fonction permet d'ecrire une donnee a une adresse 
//            precise dans un slave precis en choisisant le type d'addresse
//
// NOM:void CLI2CPort :: vI2CEcrireDonnee(UC ucAdrChip,US usiAdrDepart,
//                                        UC ucTypeAdr,UC ucDonnee)
//
// 
// PARAMETRE D'ENTREE:ucAdrChip:Adresse du slave
//                    usiAdrDepart:Adresse de la case memoire a ecrire 
//                    ucDonnee:Donnee a ecrire
//                    ucTypeAdr: type d'addrese peut prendre 3 valeur
//                                Pas addresse, 8 bit ,16 bit
// PARAMETRE DE SORTIE:Aucun              
//
// PROCEDURES APPELEES: ucI2CEcrireDonneeType()
//
// DATE DE CREATION: 3 septembre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//***************************************************************************** 
void CLI2CPort :: vI2CEcrireDonnee(UC ucAdrChip,US usiAdrDepart,UC ucTypeAdr,
                                   UC ucDonnee)
{

   unsigned char ucAdrHaute;
   unsigned char ucAdrBas;
	    
   vI2CStart();                         //Start la communication i2c
   UC ucAck =  ucI2CEcrireOctet(ucAdrChip);//Ecrit l'adresse du chip en write
   //while(ucAck == 1)
   // {
   //   vI2CStart();
   //   ucAck = ucI2CEcrireOctet(ucAdrChip);//adresse chip en write,verifier Ack
   // }

   switch(ucTypeAdr)
    {
    
       case PASADRESSE:
          break;
       
       case ADR8BIT:
         ucAdrBas = usiAdrDepart & 0x00FF; //Isole la partie Basse de l adresse
         ucI2CEcrireOctet(ucAdrBas);//Ecrit L'adresse Basse de case memoire 0x10
         break;
       
       case ADR16BIT:
         ucAdrHaute = usiAdrDepart & 0xFF00; //Isole la partie haute de l adresse
         ucI2CEcrireOctet(ucAdrHaute);//Ecrit Adreese haute de case memoire 0x00
         ucAdrBas = usiAdrDepart & 0x00FF; //Isole la partie Basse de l adresse
         ucI2CEcrireOctet(ucAdrBas);//Ecrit L'adresse Basse de case memoire 0x10
         break;
 
    }
   ucI2CEcrireOctet(ucDonnee);//Ecrit la donnee a memoriser 0x34 verifier Ack
   vI2CStop();                //Stop la communication


}


//***********************Fonction:ucI2CLireDonnee
//
//Description:Cette fonction permet de Lire une donnee a une adresse
//            precise dans un slave precis avec un type d'addresse choisit
//
//NOM:unsigned char CLI2CPort :: ucI2CLireDonnee(UC ucAdrChip, US usiAdrDepart,
//                               UC ucTypeAdr)

//
//           
// PARAMETRE D'ENTREE:ucAdrChip:Adresse du chip a contacter
//                    usiAdrDepart:Adresse de la case interne ou il faut lire
//                    ucTypeAdr: type d'addrese peut prendre 3 valeur
//                                Pas addresse, 8 bit ,16 bit
//
// PARAMETRE DE SORTIE:ucDonnee: Valeur de l'octet lue                
//
//
// PROCEDURES APPELEES:ucI2CLireDonneeType()
//
// DATE DE CREATION: 3 septembre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************
unsigned char CLI2CPort :: ucI2CLireDonnee(UC ucAdrChip, US usiAdrDepart,
                                           UC ucTypeAdr)
{
   unsigned char ucAdrHaute;
   unsigned char ucAdrBas;
   unsigned char ucDonnee;
		 
   vI2CStart();                 //Start la communication i2C
   ucI2CEcrireOctet(ucAdrChip); //Ecrit l'adresse du chip en write
   switch(ucTypeAdr)
    {
       case PASADRESSE:
          break;
       
       case ADR8BIT:
         ucAdrBas = usiAdrDepart & 0x00FF; //Isole la partie Basse de l adresse
         ucI2CEcrireOctet(ucAdrBas);//Ecrit L'adresse Basse de case memoire 0x10
         break;
       
       case ADR16BIT:
         ucAdrHaute = usiAdrDepart & 0xFF00; //Isole la partie haute de l adresse
         ucI2CEcrireOctet(ucAdrHaute);//Ecrit Adreese haute de case memoire 0x00
         ucAdrBas = usiAdrDepart & 0x00FF; //Isole la partie Basse de l adresse
         ucI2CEcrireOctet(ucAdrBas);//Ecrit L'adresse Basse de case memoire 0x10
         break;
 
    }
	                             //
   vI2CStart();                 //Start la communication i2C
   ucI2CEcrireOctet(ucAdrChip + 1 ); //Ecrit l'adresse du chip mode read
   ucDonnee = ucI2CLireOctet(0);//Lit la donnee et stocke dans cVar1
   vI2CStop();
   
   return(ucDonnee);       //retourne la donnee lu




}

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@