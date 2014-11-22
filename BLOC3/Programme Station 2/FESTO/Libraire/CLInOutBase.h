// ***************** FICHIER:CLInOutBase.H
//
// Permet d'utiliser la classe pour faire des In Out
//  
//
//  Application realisee avec IAR
//
//  AUTEUR : Gabriel Fortin-Belanger
//  DATE CREATION :    2014-02-07		 VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
//******************************************************************************

#include "_DeclarationGenerale.h"
#ifndef CLINOUTBASE
   #define  CLINOUTBASE
   


// ***************** FICHIER:CLInOutBase.H
//
// Description: La classe contient des fonctions In et Out qui peuvent 
//              travailler a 8 ou 16 bits. Pour les In et Out a 16bits il faut
//              fournir un parametre qui donne le type de transfert.
//
//              SAMELSB: 2 acces 8 bits a la meme adresse, LSB en premier.   
//              SAMEMSB: 2 acces 8 bits a la meme adresse, MSB en premier.  
//              SUITELSB: 2 acces 8 bits adresses successives, LSB en  premier 
//              SUITEMSB:2 acces 8 bits adresses successives, MSB en premier              
//
//
//
// 
// COMPOSITION: Aucune
//
//
// HERITAGE: Aucune.
//
//FONCTION:
//
// Fonction public ecriture 8 bits d un port.  vOut().     
// Fonction public ecriture 16 bits d un port.  vOut(). 
// Fonction public Lecture  8 bits d un port.  ucIn().
// Fonction public Lecture  16 bits d un port.  usiIn().
//
// Fonction prive  ecriture 8 bit. vOutportb().
// Fonction prive  Lecture 8 bit.  ucInportb().
//
//CONSTRUCTEUR:
//
//
//
//
//
//DESTRUCTEUR:
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

class CLInOutBase
{
public:
  
   void vOut(unsigned short int usiAdresse, 
             unsigned char ucDonnee);//Sortie 8bit
   void vOut(unsigned short int usiAdresse, unsigned short int usiDonnee,
              unsigned char ucTypeTransfert);//Sortie 16bit
     
   unsigned char ucIn(unsigned short int usiAdresse); // Entree 8 bits
   unsigned short int usiIn(unsigned short int usiAdresse, 
                            unsigned char unTypeTransfert);// Entree 16 bit
     
private:
   UNMot16bit  unMot16bit; 
   UC xdata *ucpAdresse;
  //Fonctions pour réaliser les acces dans un environnements 8051
   unsigned char ucInportb(unsigned short int usiAdresse); 
   void vOutportb(unsigned short int usiAdresse, unsigned char ucDonnee);
};  


#endif


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@