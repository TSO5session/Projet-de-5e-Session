// ***************** FICHIER:CLHorloge1307.H
//
//  Contient les definitions de classe pour utiliser un horloge 1307
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
   #include "CLI2CPort.h"




// ***************** FICHIER:CLHorloge1307.H
//
// Description: La classe contient des fonctions pour communiquer avec 
//               une horloge 1307 grace au fonction d I/O
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
//   void vReadTime(void)                Fonction pour lire l horloge 1307
//   void vWriteTime(void)               Fonction pour ecrire l horloge 1307
//
//CONSTRUCTEUR: 
//     Constructeur par defaut      CLHorloge1307(void)
//     Constructeur initialisateur  CLHorloge1307(unsigned short int usiAdresse)
//
//
//DESTRUCTEUR:
//
//        ~CLHorloge1307(void)
//
//  AUTEUR : Gabriel Fortin-Belanger
//  DATE CREATION :    2014-02-07		 VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
//******************************************************************************
class CLHorloge1307 : public CLI2CPort
{

  public:
  CLHorloge1307(void);
  CLHorloge1307(USI usiAdresse);
  ~CLHorloge1307(void);
  

   void vWriteTime(void);
   void vReadTime(void);
   STHorlogeHMS stHorlogeHMS;
   USI usiAdresseHorloge;
   
  private:
    
  protected:
};

#endif

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@