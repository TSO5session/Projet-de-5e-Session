// ***************** FICHIER:CLI2CBase.cpp
//
//  Description:Ce fichier contient la definition des differentes fonction 
//              I2C de base qui communique avec le materiel
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
#include "CLI2CBase.h"

#define DELAI 100


//***********************CLI2CBase(void)
//
//Description:Constructeur par defaut ne fais rien
//            
//
// Nom:CLI2CBase :: CLI2CBase(void)
//           
// PARAMETRE D'ENTREE: -
//                  
// 
//
// PARAMETRE DE SORTIE: -             
//
//    
// Membre utilise: usiAdresseMaison
//
//
// DATE DE CREATION: 10 octobre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************
CLI2CBase :: CLI2CBase(void)   //Constructeur defaut
{
  
}


//***********************~CLI2CBase(void)
//
//Description:Destructeur par defaut ne fais rien
//           
//
// Nom:CLI2CBase :: ~CLI2CBase(void) 
//           
// PARAMETRE D'ENTREE:  -
//                        
//                  
// 
//
// PARAMETRE DE SORTIE: -             
//
//    
// Membre utilise: vSetLumiere();
//
//
// DATE DE CREATION: 10 octobre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************
CLI2CBase :: ~CLI2CBase(void)   
{
 
}


//***********************Fonction:vI2CStart************************************
//
// Description:     Cette fonction permet de debuter la communication I2C
//
// 
// Nom:void CLI2CBase :: vI2CStart(void)
// 
// PARAMETRE D'ENTREE:Aucun 
//
// PARAMETRE DE SORTIE:Aucun              
//
// EXEMPLE:
//
// PROCEDURES APPELEES: vI2CStart()
//
// DATE DE CREATION: 3 septembre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************
void CLI2CBase :: vI2CStart(void)
{
  SDA = HIGH; //Place la ligne de donnée a 1
  SCL = HIGH; //Place la ligne d'horloge a 1
  vDelais();  //Cree un delai pour que les lignes soient stable
  SDA = LOW;  //Place la ligne de donnée a 0
  vDelais();  //Delai pour la stabilité
  SCL = LOW;  //Ligne d'horloge a 0
  vDelais();  //Delai pour la stabilité   
}


//***********************Fonction:vI2CStop*************************************
//
//Description:Cette fonction permet de faire l<arret d une trame i2c
//
// NOM:
//
// PARAMETRE D'ENTREE:Aucun 
//
// PARAMETRE DE SORTIE:Aucun              
//
// EXEMPLE:void CLI2CBase :: vI2CStop(void)
//
// PROCEDURES APPELEES: vI2CStop()
//
// DATE DE CREATION: 3 septembre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//***************************************************************************** 
void CLI2CBase :: vI2CStop(void)
{
  SDA = LOW; //Place la ligne de donnée a 0
  vDelais(); //Delai pour la stabilité
  SCL = HIGH;//Ligne d'horloge a 1 pour changer la donnée
  vDelais(); //Delai pour la stabilité
  SDA = HIGH;//Place la ligne de donnée a 1
  vDelais();//Delai pour la stabilité
}



//***********************Fonction:ucI2CLireOctet*******************************
//
//Description:Cette fonction permet de lire un octet sur le bus et de
//            retourner le ACK
//
// NOM:UC CLI2CBase :: ucI2CLireOctet(UC ucAckNoAck)
// PARAMETRE D'ENTREE:ucAckNoAck: 0 pour ACK et 1 pour NOACK 
//
// PARAMETRE DE SORTIE:ucVal: valeur de l'octet                
//
// EXEMPLE: ucAckNoAck = 0
//
// PROCEDURES APPELEES: ucI2CLireOctet()
//
// DATE DE CREATION: 3 septembre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************
UC CLI2CBase :: ucI2CLireOctet(UC ucAckNoAck)
{
  UI i;                          //Declare une variable pour la boucle for
  UC ucVal;                      //Declare une variable pour stocké la donnée
  ucVal = 0x00;                  //Met ucVal o 0
  for(i = 0; i<8; i++)           //Fait 8 fois pour garder chaque bit
   {                             //
                                 //
     if(ucI2CLireBit() == 1)     //Si le bit recu est 1
      {                          //
        ucVal = ucVal << 1;      //Decale a gauche de 1
	ucVal = ucVal + 1;       //Additionne 1 a la variable ucVal
      }                          //
                                 // 
     else                        //Sinon
      {                          //
        ucVal = ucVal << 1;      //Decale a gauche de 1 pour placer un 0
      }                          //
                                 //
     SDA = ucAckNoAck;	         //Envoie Le signal ACK
   }                             //
                                 //
                                 //
  return(ucVal);                 //
  
}


//***********************Fonction:ucI2CEcrireOctet*****************************
//
//Description:Cette fonction permet d'Ecrire un octet sur le bus
//
// NOM:UC CLI2CBase :: ucI2CEcrireOctet(UC ucValeur)
// 
// PARAMETRE D'ENTREE:ucValeur:Valeur a ecrire sur le bus 
//
// PARAMETRE DE SORTIE:ucAck: ACK envoyer par le slave 0 pour ACK 1 pour NOACK             
//
// EXEMPLE:ucValeur = 0xA0
//
// PROCEDURES APPELEES:ucI2CEcrireOctet()
//
// DATE DE CREATION: 3 septembre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************
UC CLI2CBase :: ucI2CEcrireOctet(UC ucValeur)
{
  UC ucAck;                                 //Declare une variable pour ACK
  UC i;                                     //Declare variable pour le for
  for(i=0;i<8;i++)                          //Faire 8 fois
   {                                        //
     ucI2CEcrireBit((ucValeur & 0x80)>> 7); //Isole le MSB et l'evoie au LSB
     ucValeur = ucValeur << 1;              //Fait un decallage a gauche de 1  
   }                                        //
		                            //
  ucAck = ucI2CLireBit();                   //Lit le bus pour saisir le ACK
  vDelais();                                //Delai
  return(ucAck);                            //retourne la valeur de ACK


}

//***********************Fonction:ucI2CLireBit*********************************
//
//Description:Cette fonction permet de faire un delai
//
// NOM:UC CLI2CBase :: ucI2CLireBit(void)
//
// 
// PARAMETRE D'ENTREE:Aucun 
//
// PARAMETRE DE SORTIE:ucBit: bit lue sur le port peut etre 1 ou 0              
//
// EXEMPLE:
//
// PROCEDURES APPELEES: ucI2CLireBit()
//
// DATE DE CREATION: 3 septembre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************	
UC CLI2CBase :: ucI2CLireBit(void)
{
  UC ucBit;      //Declare une variable pour stocker le bit lu
		               // 
  SDA = HIGH;    //Met la ligne de donnée a 1 
  vDelais();     //Attend que sa se stabilise
  SCL =  HIGH;   //L'horloge mis a 1
  vDelais();     //Attend que sa se stabilise
  ucBit = SDA;   //Stocke le bit lu
  vDelais();     //Attend que sa se stabilise
  SCL = LOW;     //Horloge mis a 0
  vDelais();     //Attend que sa se stabilise
  return(ucBit); //retourne la valeur du bit lu

}


//***********************Fonction:ucI2CEcrireBit*******************************
//
//Description:Cette fonction permet d'ecrire un bit sur le bus 
//
//
// NOM:U2C CLICBase :: ucI2CEcrireBit(UC ucValeur)
// 
// PARAMETRE D'ENTREE:ucValeur: valeur du bit a envoyer. 0 ou 1.
//
// PARAMETRE DE SORTIE:ucValeur: retourne la valeur du bit             
//
// EXEMPLE: ucValeur = 0;
//
// PROCEDURES APPELEES:ucI2CEcrireBit()
//
// DATE DE CREATION: 3 septembre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//***************************************************************************** 
UC CLI2CBase :: ucI2CEcrireBit(UC ucValeur)
{
   SDA = ucValeur;         //Envoie un bit sur la ligne de donnee
   vDelais();              //
   SCL = HIGH;             //Ligne d'horloge a 1
   vDelais();              //
   SCL = LOW;              //Ligne d'horloge a 0
   vDelais();              //
   return(ucValeur);       //Renvoie la valeur du bit

}


//***********************Fonction:vDelais**************************************
//
//Description:Cette fonction permet de faire un delai
//
// NOM: void CLI2CBase ::  vDelais(void)
//
// 
// PARAMETRE D'ENTREE:Aucun 
//
// PARAMETRE DE SORTIE:Aucun              
//
// EXEMPLE:
//
// PROCEDURES APPELEES: vDelai()
//
// DATE DE CREATION: 3 septembre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************
void CLI2CBase ::  vDelais(void)
{
  UC i;                     //Variable pour la boucle
  for( i=0 ;i < DELAI; i++);//Compte un nombre de fois pour faire un delai 

}

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@