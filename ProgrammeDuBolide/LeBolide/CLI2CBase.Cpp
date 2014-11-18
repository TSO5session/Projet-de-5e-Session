// ************************** FICHIER: I2CBASE.CPP ****************************
//
// Fonctions de communication de base en I2C
//
// Application realisee avec IAR C++ 8.10
//
// LIMITATION DU COMPILATEUR:
// Impossible de faire de l'heritage multiple.
//
// Note: on peut utiliser XAR pour creer des librairies.
// On peut mettre les librairies dans le projets et Exclure de la compilation
// les modules qui sont contenus dans la librairie.
//
// Pour Windows 7 on utilise la VMware pour programmer le upsd 3254A avec CAPS.
//
// AUTEUR : LOUIS-NORMAND ANG HOULE
// DATE CREATION : 2014/03/27 VERSION: 1.0
// DATE MODIFICATION: ****-**-**
//
// *****************************************************************************

#include "CLI2CBase.h"

// Constructeur par defaut //////////////////////////////////////////////////// 

CLI2CBase :: CLI2CBase(void)
 {
   ucDelaiI2C = 5;
 }

// Constructeur initialisateur ////////////////////////////////////////////////
CLI2CBase :: CLI2CBase(UC ucDelai)
 {
   ucDelaiI2C = ucDelai;
 }

// Destructeur ////////////////////////////////////////////////////////////////

CLI2CBase :: ~CLI2CBase(void)
 {
 }

///////////////////////////////////////////////////////////////////////////////
// void CLI2CBase :: vI2CStart(void)    
///////////////////////////////////////////////////////////////////////////////
//
// Description: 
//
// Parametres d'entrees: null
//            
// Parametres de sortie: null
//
// Appel de la fonction: 
//
// Cree le  4 avril 2014 par Louis-Normand Ang Houle 
// 
// Modifications:	
// -
//
///////////////////////////////////////////////////////////////////////////////

void CLI2CBase :: vI2CStart(void)     	       
 {
    SDA = HAUT;                              //Met SDA a 1
    SCL = HAUT;                              //Met SCL a 1
    vDelaiI2C();                             //Delai
    SDA = BAS;                               //Met SDA a 0 
    vDelaiI2C();                             //Delai 
    SCL = BAS;                               //Met SCL a 0
    vDelaiI2C();                             //Delai
 }

///////////////////////////////////////////////////////////////////////////////
// void CLI2CBase :: vI2CStop(void)
///////////////////////////////////////////////////////////////////////////////
//
// Description: 
//
// Parametres d'entrees: null
//            
// Parametres de sortie: null
//
// Appel de la fonction: 
//
// Cree le  4 avril 2014 par Louis-Normand Ang Houle 
// 
// Modifications:	
// -
//
///////////////////////////////////////////////////////////////////////////////

void CLI2CBase :: vI2CStop(void)
 {
    SDA = BAS;                               //Met SDA a 0
    SCL = BAS;                               //Met SCL a 0
    vDelaiI2C();                             //Delai
    SCL = HAUT;                              //Met SCL a 1
    vDelaiI2C();                             //Delai
    SDA = HAUT;                              //Met SDA a 1
    vDelaiI2C();                             //Delai   
 }

///////////////////////////////////////////////////////////////////////////////
// UC   CLI2CBase :: ucI2CLireBit(void)
///////////////////////////////////////////////////////////////////////////////
//
// Description: 
//
// Parametres d'entrees: null
//            
// Parametres de sortie: null
//
// Appel de la fonction: 
//
// Cree le  4 avril 2014 par Louis-Normand Ang Houle 
// 
// Modifications:	
// -
//
///////////////////////////////////////////////////////////////////////////////

UC   CLI2CBase :: ucI2CLireBit(void)
 {
    UC ucBit;
    SDA = HAUT;                             
    vDelaiI2C();                             
    SCL = HAUT;                              
    vDelaiI2C();                 
    ucBit = SDA;                        
    vDelaiI2C();                        
    SCL = BAS;                  
    vDelaiI2C();           
    return (ucBit);                     
 }

///////////////////////////////////////////////////////////////////////////////
// void CLI2CBase :: vI2CEcrireBit(UC ucBit)
///////////////////////////////////////////////////////////////////////////////
//
// Description: 
//
// Parametres d'entrees: null
//            
// Parametres de sortie: null
//
// Appel de la fonction: 
//
// Cree le  4 avril 2014 par Louis-Normand Ang Houle 
// 
// Modifications:	
// -
//
///////////////////////////////////////////////////////////////////////////////

void CLI2CBase :: vI2CEcrireBit(UC ucBit)
 {
   SDA = ucBit;                        
   vDelaiI2C();                        
   SCL = HAUT;                  
   vDelaiI2C();                            
   SCL = BAS;                             
   vDelaiI2C();                              
 }

///////////////////////////////////////////////////////////////////////////////
// UC CLI2CBase :: ucI2CLireOctet(UC ucAck)
///////////////////////////////////////////////////////////////////////////////
//
// Description: 
//
// Parametres d'entrees: null
//            
// Parametres de sortie: null
//
// Appel de la fonction: 
//
// Cree le  4 avril 2014 par Louis-Normand Ang Houle 
// 
// Modifications:	
// -
//
///////////////////////////////////////////////////////////////////////////////

UC CLI2CBase :: ucI2CLireOctet(UC ucAck)
 {
    UC ucLecture = 0x00;                   //Variable de reception   
    
    for (UC i=0; i < 8; i++)                   //Repeter 8 fois 
     {
       if(ucI2CLireBit() == 1)                //Si lecture retourne 1
	{
	  ucLecture = ucLecture + 1;     //Additionne 1 a LireOctet
	}   
       if(i != 7) ucLecture = ucLecture << 1; //Decale LireOctet 1 vers gauche                                                     	                  
     }	      
   vI2CEcrireBit(ucAck);
   return (ucLecture); 		               //Retourne l'octet lue  
 }

///////////////////////////////////////////////////////////////////////////////
// UC CLI2CBase :: ucI2CEcrireOctet(UC ucOctet)
///////////////////////////////////////////////////////////////////////////////
//
// Description: 
//
// Parametres d'entrees: null
//            
// Parametres de sortie: null
//
// Appel de la fonction: 
//
// Cree le  4 avril 2014 par Louis-Normand Ang Houle 
// 
// Modifications:	
// -
//
///////////////////////////////////////////////////////////////////////////////

UC CLI2CBase :: ucI2CEcrireOctet(UC ucOctet)
 {
    for (UC i=0; i<8; i++)                 
     {	
      if((ucOctet & 0x80) == 0) vI2CEcrireBit(0);
      else                      vI2CEcrireBit(1);
      ucOctet = ucOctet << 1;         
     }                               
    return (ucI2CLireBit());		     
 }

///////////////////////////////////////////////////////////////////////////////
// void CLI2CBase :: vDelaiI2C(void)
///////////////////////////////////////////////////////////////////////////////
//
// Description: 
//
// Parametres d'entrees: null
//            
// Parametres de sortie: null
//
// Appel de la fonction: 
//
// Cree le  4 avril 2014 par Louis-Normand Ang Houle 
// 
// Modifications:	
// -
//
///////////////////////////////////////////////////////////////////////////////

void CLI2CBase :: vDelaiI2C(void)
 {
    for (UC i= ucDelaiI2C; i>0; i--);
 }

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!