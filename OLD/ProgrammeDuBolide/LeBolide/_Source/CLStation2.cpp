// ************************** FICHIER: CLSTATION2.CPP *************************
//
// Fonctions pour le controle du station 2 (controleur table Festo)
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

#include "CLStation2.h"


// Constructeur par defaut ////////////////////////////////////////////////////

CLStation2 :: CLStation2(void)
: clXBeeST2(5, 5, 9600),
  clEcranST2(0xF800)
 {
     TrameTxST2[0] = '2';
     TrameTxST2[1] = ' ';
     TrameTxST2[2] = 'L';
     TrameTxST2[3] = '0';
     TrameTxST2[4] = '0';
 }

// Destructeur ////////////////////////////////////////////////////////////////

CLStation2 :: ~CLStation2(void)
 {
 }

///////////////////////////////////////////////////////////////////////////////
// void CLStation1 :: vControleStation2(void)
///////////////////////////////////////////////////////////////////////////////
//
// Description: Fonction de controle de la station 2
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

void CLStation2 :: vControleStation2(void)
 {
  UC *TrameRxST2;
  
  TrameRxST2 = clXBeeST2.ucpLireTrame();
  
  if(TrameRxST2 != NULL)
   {
     clEcranST2.vLCDCursor(0,2);
     clEcranST2.vLCDDisplayCaracChain(TrameRxST2);
     
     if((TrameRxST2[0] == '1') &&          //Trame recue de la station 1
        (TrameRxST2[1] == ' '))
     {
       switch(TrameRxST2[2])
       {

       }
     }
     else clXBeeST2.vResetTampon(); 
     if((TrameRxST2[0] == '3') &&          //Trame recue du vehicule
        (TrameRxST2[1] == ' '))
     {
       switch(TrameRxST2[2])
       {
          case 'L':
            TrameRxST2 = NULL;
            break;
          
          case 'A':
            TrameRxST2 = NULL;  
            clXBeeST2.vTransChaine(TrameTxST2);
            break;
            
       }
     }
     else clXBeeST2.vResetTampon();     
   }   
 }

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@