// ************************** FICHIER: CLADCMAX1236.CPP ***********************
//
// Fonctions pour le convertisseur analogue -> digital I2C MAX1236
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
// DATE CREATION : 2014/04/16 VERSION: 1.0
// DATE MODIFICATION: ****-**-**
//
// *****************************************************************************
#include "CLADCMAX1236.h"

//******************************************************************************
//                            LE CONSTRUCTEUR PAR DEFAUT
// *****************************************************************************
CLADCMAX1236 :: CLADCMAX1236(void)
{
vInitMAX1236();
}

// *****************************************************************************
//                            LE DESTRUCTEUR
// *****************************************************************************
CLADCMAX1236 :: ~CLADCMAX1236(void)
{
  
}

///////////////////////////////////////////////////////////////////////////////
//  void CLADCMAX1236 :: vInitMAX1236(void)
///////////////////////////////////////////////////////////////////////////////
//
// Description: Configuration des registres du  ADC MAX1236
//
// Parametres d'entrees: null
//
// Parametres de sortie: null
//
// Appel de la fonction: vInitMAX1236();
//
// Cree le 2014/04/17 par Louis-Normand Ang Houle
//
// Modifications:
// -
//
///////////////////////////////////////////////////////////////////////////////
void CLADCMAX1236 :: vInitMAX1236(void)
{
UC uctTableau[2] = {SETUPMAX1236, CONFIGMAX1236};
vI2CEcrireDonnee(ADRMAX1236, NULL, PASADR, uctTableau, 2);  
}

///////////////////////////////////////////////////////////////////////////////
// USI  CLADCMAX1236 :: uiLireValeur(UC ucCanal)
///////////////////////////////////////////////////////////////////////////////
//
// Description: Lecture de la valeur du canal selectionne
//
// Parametres d'entrees
// -UC ucCanal: Numero du canal a lire
//
// Parametres de sortie
// -unLecture.uiEntier: Valeur lue dans le canal pointe
//
// Appel de la fonction: uiLireValeur(CANAL);
//
// Cree le 2014/04/17  par Louis-Normand Ang Houle
//
// Modifications:
// -
//
///////////////////////////////////////////////////////////////////////////////
USI  CLADCMAX1236 :: uiLireValeur(UC ucCanal)
{
UC  uctLecture[2] = {0,0};
UC  uctTableau[1] = {CONFIGMAX1236};  
     
union UNEntierOctet unLecture; // Pour lire les donnees (parties haute et basse)
   
switch(ucCanal)
  {
   case 0: // Configure le MAX1236 pour lire le canal 0
       uctTableau[0] = uctTableau[0] | 0x00;
   break;
      
   case 1: // Configure le MAX1236 pour lire le canal 1
       uctTableau[0] = uctTableau[0] | 0x02;
   break;
      
   case 2: // Configure le MAX1236 pour lire le canal 2
       uctTableau[0] = uctTableau[0] | 0x04;
   break;
      
   case 3: // Configure le MAX1236 pour lire le canal 3
       uctTableau[0] = uctTableau[0] | 0x06;
   break;
  } 
   
vI2CEcrireDonnee(ADRMAX1236, NULL, PASADR, uctTableau, 1); // Prepare le MAX1236
vI2CLireDonnee  (ADRMAX1236, NULL, PASADR, uctLecture, 2); // Lit la conversion
      
unLecture.stDeuxOctet.ucOctet2 = uctLecture[0] & 0x0F; // Valeur lue, MSB
unLecture.stDeuxOctet.ucOctet1 = uctLecture[1]; // Valeur lue, LSB 
     
return(unLecture.uiEntier); // Retourne la valeur convertie par le MAX1236
}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@