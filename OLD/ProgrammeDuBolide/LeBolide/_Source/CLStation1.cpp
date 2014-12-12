// ************************** FICHIER: CLSTATION1.CPP *************************
//
// Fonctions pour le controle du station 1 (proxy PC)
//
//
// Application realisee avec IAR C++ 8.10
//
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
// DATE CREATION : 2014/12/01 VERSION: 1.0
// DATE MODIFICATION: ****-**-**
//
// *****************************************************************************

#include "CLStation1.h"

#ifdef STATION_1

// Constructeur par defaut ////////////////////////////////////////////////////

CLStation1 :: CLStation1(void)
: clEcranST1(0xF800), 
  clXbeeST1(5,5,9600)
 {

 }

// Destructeur ////////////////////////////////////////////////////////////////

CLStation1 :: ~CLStation1(void)
 {
 }

///////////////////////////////////////////////////////////////////////////////
// void CLStation1 :: vControleStation1(void)
///////////////////////////////////////////////////////////////////////////////
//
// Description: Fonction de controle de la 1re station
//
// Parametres d'entrees: null
//
// Parametres de sortie: null
//
// Appel de la fonction: void (void);
//
// Cree le 2014/12/01 par Louis-Normand Ang Houle
//
// Modifications:
// -
//
///////////////////////////////////////////////////////////////////////////////

void CLStation1 :: vControleStation1(void)
 {
   UC *TrameRxST1;
   UC  Menu[4][20] = {"H:   M:   S:      ",
                      "                  ",
                      "                  ",
                      "                  "};  
   
   clEcranST1.vLCDDisplayScreen(*Menu); 
   clCANST1.LireMCP2515();      
   switch (clCANST1.Tab [0])
    {
     case 0x06:
     if (clCANST1.Tab [1] == 0x00)
      {
        clHorlogeST1.stTemps.ucHeure   = 
        ((clCANST1.Tab [2] / 10)<<4) + (clCANST1.Tab [2] % 10);             
             
        clHorlogeST1.stTemps.ucMinute  = 
        ((clCANST1.Tab [3] / 10)<<4) + (clCANST1.Tab [3] % 10);
             
        clHorlogeST1.stTemps.ucSeconde =  
        ((clCANST1.Tab [4] / 10)<<4) + (clCANST1.Tab [4] % 10);    
      }         
     break;         
    }       
   
   
   clHorlogeST1.vReadTime ();
   clEcranST1.vLCDCursor (2,1);
   clEcranST1.vLCDDisplayHexCarac(clHorlogeST1.stTemps.ucHeure);  
   clEcranST1.vLCDCursor (7,1);
   clEcranST1.vLCDDisplayHexCarac(clHorlogeST1.stTemps.ucMinute);
   clEcranST1.vLCDCursor (12,1); 
   clEcranST1.vLCDDisplayHexCarac(clHorlogeST1.stTemps.ucSeconde);
   
  TrameRxST1 = clXbeeST1.ucpLireTrame();
  if(TrameRxST1 != NULL)
   {
     clEcranST1.vLCDCursor(0,2);
     clEcranST1.vLCDDisplayCaracChain(TrameRxST1);
     
     if(TrameRxST1[0] == '2' &&          //Trame recue de la station 2
        TrameRxST1[1] == ' ')
      {
       switch(TrameRxST1[2])             //Commande recue?
        {

        }
      }
      else clXBeeST1.vResetTampon();
    }
  }  
 
 
#endif
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@