// ***************** FICHIER:CLInOutBase.cpp
//
//  Application realisee avec IAR C++ 8.1  
//  
// Description: La classe contient des fonctions In et Out qui peuvent 
//              travailler a 8 ou 16 bits.Pour les In et Out 16 Bits il faut
//              fournir un parametre qui donne le type d'acces
//
//
//
//
//
//
//
//  AUTEUR : Gabriel Fortin-Belanger
//  DATE CREATION :    2014-02-07		 VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
//******************************************************************************  


#include "CLInOutBase.h"
#include "_DeclarationGenerale.h"


//*******************************Constantes************************************
#define SAMELSB   0U  //2 acces 8 bits a la meme adresse, LSB en premier. 
#define SAMEMSB   1U  //2 acces 8 bits a la meme adresse, MSB en premier.
#define SUITELSB  2U  //2 acces 8 bits adresses successives, LSB en  premier
#define SUITEMSB  3U  // 2 acces 8 bits adresses successives, MSB en premier  
//******************************************************************************




//***********************vOut
//
//Description:Cette fonction permet d ecrire en appelant la fonction vOutportb
//            
//           
// Nom:void CLInOutBase :: vOut(unsigned short int usiAdresse, 
//                                      unsigned char ucDonnee) 
//           
// PARAMETRE D'ENTREE:US usiAdresse: Addresse ou on veut ecrire
//                    unsigned char ucDonnee: Donnee a envoyer
// 
//
// PARAMETRE DE SORTIE:              
//
//    
// Methode utilise:
// Fonction: vOutportb();
// 
//
//
// DATE DE CREATION: 10 octobre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************
void CLInOutBase :: vOut(unsigned short int usiAdresse, 
                    unsigned char ucDonnee) 
{
   vOutportb(usiAdresse, ucDonnee); 

}

//***********************vOut
//
//Description:Cette fonction permet d ecrire en appelant la fonction vOutportb
//            et permet l ecriture 16 bit  
//           
// Nom:void CLInOutBase :: vOut(unsigned short int usiAdresse ,
//                              unsigned short int usiDonnee,
//                              unsigned char ucTypeTransfert)
//           
// PARAMETRE D'ENTREE:US usiAdresse: Addresse ou on veut ecrire
//                    unsigned char ucDonnee: Donnee a envoyer
//                    unsigned char ucTypeTransfert: type de transfert 
//              SAMELSB: 2 acces 8 bits a la meme adresse, LSB en premier.   
//              SAMEMSB: 2 acces 8 bits a la meme adresse, MSB en premier.  
//              SUITELSB: 2 acces 8 bits adresses successives, LSB en  premier 
//              SUITEMSB:2 acces 8 bits adresses successives, MSB en premier 
//
//
// PARAMETRE DE SORTIE:              
//
//    
// Methode utilise:
// Fonction: vOutportb();
// 
//
//
// DATE DE CREATION: 10 octobre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************
void CLInOutBase :: vOut(unsigned short int usiAdresse ,
                         unsigned short int usiDonnee,
                         unsigned char ucTypeTransfert)
{
  unMot16bit.uiWord =  usiDonnee;//place la donnee dans la structure 
  
  switch(ucTypeTransfert)//choisit le type transfit 
  {
    case SAMELSB://2 acces 8 bits a la meme adresse, LSB en premier. 
      vOutportb( usiAdresse,unMot16bit.stOctet16bit.ucBas);  
      vOutportb( usiAdresse,unMot16bit.stOctet16bit.ucHaut);
    
    break;
    
    case SAMEMSB://2 acces 8 bits a la meme adresse, MSB en premier.
     vOutportb(usiAdresse,unMot16bit.stOctet16bit.ucHaut);
    vOutportb(usiAdresse, unMot16bit.stOctet16bit.ucBas);
    break;
    
    case SUITELSB://2 acces 8 bits adresses successives, LSB en  premier
      vOutportb(usiAdresse,unMot16bit.stOctet16bit.ucBas);
      vOutportb(((usiAdresse)+1), unMot16bit.stOctet16bit.ucHaut);
    break;
    
    case SUITEMSB://2 acces 8 bits adresses successives, MSB en premier 
        vOutportb(usiAdresse, unMot16bit.stOctet16bit.ucHaut);
        vOutportb(((usiAdresse)+1), unMot16bit.stOctet16bit.ucBas);
    break;
    
    
  }


}

//***********************ucIn
//
//Description:Cette fonction permet de lire en appelant la fonction ucInportb
//            
//           
// Nom:UC CLInOutBase :: ucIn(unsigned short int usiAdresse) 
//           
// PARAMETRE D'ENTREE:US usiAdresse: Addresse ou on veut lire
//                   
// 
//
// PARAMETRE DE SORTIE: unsigned char ucDonnee: Donnee lu            
//
//    
// Methode utilise:
// Fonction: ucInportb();
// 
//
//
// DATE DE CREATION: 10 octobre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************
UC CLInOutBase :: ucIn(unsigned short int usiAdresse)
{
  return ucInportb(usiAdresse);
}


//***********************usiIn
//
//Description:Cette fonction permet de lire en appelant la fonction ucInportb
//            et permet la lecture 16 bit
//           
// Nom:UC CLInOutBase :: ucIn(unsigned short int usiAdresse) 
//           
// PARAMETRE D'ENTREE:US usiAdresse: Addresse ou on veut lire
//                    UC ucTypeTransfert:type de transfert
//              SAMELSB: 2 acces 8 bits a la meme adresse, LSB en premier.   
//              SAMEMSB: 2 acces 8 bits a la meme adresse, MSB en premier.  
//              SUITELSB: 2 acces 8 bits adresses successives, LSB en  premier 
//              SUITEMSB:2 acces 8 bits adresses successives, MSB en premier 
// 
//
// PARAMETRE DE SORTIE: unsigned char ucDonnee: Donnee lu            
//
//    
// Methode utilise:
// Fonction: ucInportb();
// 
//
//
// DATE DE CREATION: 10 octobre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************

UINT16 CLInOutBase :: usiIn( unsigned short int usiAdresse,UC ucTypeTransfert)
{
switch(ucTypeTransfert)//choisit le type transfit 
  {
    case SAMELSB://2 acces 8 bits a la meme adresse, LSB en premier.
     unMot16bit.stOctet16bit.ucBas = ucInportb(usiAdresse);
     unMot16bit.stOctet16bit.ucHaut = ucInportb(usiAdresse);
     
    break;
    
    case SAMEMSB://2 acces 8 bits a la meme adresse, MSB en premier.
     unMot16bit.stOctet16bit.ucHaut = ucInportb(usiAdresse);
     unMot16bit.stOctet16bit.ucBas = ucInportb(usiAdresse);
    break;
    
    case SUITELSB://2 acces 8 bits adresses successives, LSB en  premier
     unMot16bit.stOctet16bit.ucBas = ucInportb(usiAdresse);
   unMot16bit.stOctet16bit.ucHaut = ucInportb(usiAdresse +1);
    break;
    
    case SUITEMSB://2 acces 8 bits adresses successives, MSB en premier
     unMot16bit.stOctet16bit.ucBas = ucInportb(usiAdresse);
     unMot16bit.stOctet16bit.ucHaut = ucInportb(usiAdresse +1);
    break;
    
    
  }
return unMot16bit.uiWord;//retourne la donnee lu 

}



//***********************ucInPortb
//
//Description:Cette fonction permet de lire un dispositif I/O relier au bus
//           
// Nom:UC CLInOutBase :: ucInportb(unsigned short int usiAdresse)
//           
// PARAMETRE D'ENTREE:US usiAdresse: Addresse ou on veut lire
//                  
// 
//
// PARAMETRE DE SORTIE: UC ucDonnee: retourne la donnee lue              
//
//    
// Methode utilise:
//
// DATE DE CREATION: 10 octobre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************
UC CLInOutBase :: ucInportb(unsigned short int usiAdresse)
{
   UC ucDonnee;
   ucpAdresse = (UC xdata *) usiAdresse; //Affecte l'adresse du peripherique 
                                         //au pointeur 
   ucDonnee = *ucpAdresse;               // Lit la donnee presente a l'adresse
   return(ucDonnee);                     //retourne la donnee

}


//***********************vOutportb
//
//Description:Cette fonction permet D'ecrire un dispositif I/O relier au bus
//           
// Nom:void  CLInOutBase :: vOutportb(unsigned short int usiAdresse, 
//                                            unsigned char ucDonnee)
//           
// PARAMETRE D'ENTREE:US usiAdresse: Addresse ou on veut lire
//                    UC ucDonnee: Donnee a ecrire
// 
//
// PARAMETRE DE SORTIE: Aucun              
//
//    
// Methode utilise:
//
// DATE DE CREATION: 10 octobre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************
void  CLInOutBase :: vOutportb(unsigned short int usiAdresse, 
                                       unsigned char ucDonnee)
{
   ucpAdresse = (UC xdata *) usiAdresse;//Affecte l'addresse du peripherique 
                                        //au pointeur 
   *ucpAdresse = ucDonnee;              //Ecrit  la donnee a l'adresse

}

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@