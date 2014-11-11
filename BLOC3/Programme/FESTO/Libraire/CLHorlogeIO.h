// ***************** FICHIER:CLHorlogeIO.H
//
//  Contient les definitions de classe pour utiliser un horloge
//  
//
//  Application realisee avec IAR
//
//  AUTEUR : Gabriel Fortin-Belanger
//  DATE CREATION :    2014-02-07		 VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
//******************************************************************************
#ifndef CLHORLOGEIOH
   #define  CLHORLOGEIOH
   #include "_DeclarationGenerale.h"
   #include "CLInOutBase.h"




// ***************** FICHIER:CLHorlogeIO.H
//
// Description: La classe contient des fonctions pour communiquer avec 
//               une horloge grace au fonction d I/O
//              
//             
//
// COMPOSITION: Aucune
//
//
// HERITAGE: CLInOutBase.
//
//FONCTION:
//
//   void vReadTime(void)                Fonction pour lire l horloge
//   void vWriteTime(void)               Fonction pour ecrire l horloge
//
//CONSTRUCTEUR: 
//       Constructeur par defaut      CLHorlogeIO(void)
//       Constructeur initialisateur  CLHorlogeIO(unsigned short int usiAdresse)
//
//
//DESTRUCTEUR:
//
//        ~CLHorlogeIO(void)
//
//  AUTEUR : Gabriel Fortin-Belanger
//  DATE CREATION :    2014-02-07		 VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
//******************************************************************************
class CLHorlogeIO : public CLInOutBase
{

  public:
  USI usiAdresseHorloge;
  CLHorlogeIO(void);
  CLHorlogeIO(USI usiAdresse);
  ~CLHorlogeIO(void);
  STHorlogeHMS stHorlogeHMS;  
  private:
    
  protected:
   void vReadTime(void);
   void vWriteTime(void);
};

#endif

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@