// ***************** FICHIER:CLMaison.H
//
//  Contient les definitions de classe pour utiliser le simulateur de maison
//  
//
//  Application realisee avec IAR
//
//  AUTEUR : Gabriel Fortin-Belanger
//  DATE CREATION :    2014-02-07		 VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
//******************************************************************************

#ifndef CLMAISONH
#define CLMAISONH

#include "CLInOutBase.h"
#include "_DeclarationGenerale.h"
#include "CLHorloge.h"
#include "CLEcran.h"
#include "CLHorlogeIO.h"
#include "CLPiece.h"




// ***************** FICHIER:CLMaison.H
//
// Description: La classe contient 4 pieces et un horloge
//              pour le simulateur de maison       
//             
//
// COMPOSITION: class CLPiece clPiece1;
//              class CLPiece clPiece2;
//              class CLPiece clPiece3;
//              class CLPiece clPiece4;
//              class CLHorloge clHorloge;
//
//
// HERITAGE:-
//
//FONCTION:
//
//
//
//CONSTRUCTEUR: 
//       Constructeur par defaut          CLMaison(void)
//       Constructeur initialisateur      CLMaison(USI usiAdresse)
//
//
//DESTRUCTEUR:
//
//            ~CLMaison(void)
//
//  AUTEUR : Gabriel Fortin-Belanger
//  DATE CREATION :    2014-02-07		 VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
//******************************************************************************

class CLMaison
{

public:
  CLMaison(void);
  CLMaison(USI usiAdresse);
  ~CLMaison(void);
  USI usiAdresseMaison;
  class CLPiece clPiece1;
  class CLPiece clPiece2;
  class CLPiece clPiece3;
  class CLPiece clPiece4;
  class CLHorloge clHorloge;
  
protected:
private:
  


};

#endif
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@