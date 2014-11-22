// ***************** FICHIER:CLHorloge.H
//
//  Contient les definitions de classe pour utiliser l'horloge du simulateur de 
//  maison.
//  
//
//  Application realisee avec IAR
//
//  AUTEUR : Gabriel Fortin-Belanger
//  DATE CREATION :    2014-02-07		 VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
//******************************************************************************
#ifndef CLHORLOGEH
   #define  CLHORLOGEH
   #include "_DeclarationGenerale.h"
   #include "CLInOutBase.h"
   #include "CLHorlogeIO.h"



// ***************** FICHIER:CLHorloge.H
//
// Description: La classe contient des fonctions pour communiquer avec 
//              horloge du simulateur de maison. 
//              
//             
//
// COMPOSITION: Aucune
//
//
// HERITAGE: CLHorlogeIO.
//
//FONCTION:
//
//   void vSetHeureHMS(UC ucHeure, UC ucMinute, UC ucucSeconde) 
//   Fonction pour Ecrire l horloge
//   struct STHorlogeHMS *stpGetHeureHMS(void);               
//   Fonction pour Lire l horloge
//
//CONSTRUCTEUR: 
//       Constructeur par defaut      CLHorloge(void)
//       Constructeur initialisateur  CLHorloge(unsigned short int usiAdresse)
//
//
//DESTRUCTEUR:
//
//        ~CLHorloge(void)
//
//  AUTEUR : Gabriel Fortin-Belanger
//  DATE CREATION :    2014-02-07		 VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
//******************************************************************************
class CLHorloge : public CLHorlogeIO
{
  public: 
    CLHorloge(void);
    CLHorloge(USI usiAdresse);
    void vSetHeureHMS(UC ucHeure, UC ucMinute, UC ucucSeconde);
    struct STHorlogeHMS *stpGetHeureHMS(void);
      
  protected:
    
    
  private:


};
#endif
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@