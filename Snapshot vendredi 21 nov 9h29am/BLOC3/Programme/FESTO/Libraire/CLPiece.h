// ***************** FICHIER:CLEcran.H
//
//  Contient les definitions de classe pour utiliser l'ecran LCD
//  
//
//  Application realisee avec IAR
//
//  AUTEUR : Gabriel Fortin-Belanger
//  DATE CREATION :    2014-02-07		 VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
//******************************************************************************
#ifndef CLPIECEH
   #define  CLPIECEH
   #include "_DeclarationGenerale.h"
   #include "CLInOutBase.h"







struct STPiece
{
  UC ucTemperaturePrecis : 1; //Precision de la temperature
  UC ucTemperature : 5;    // Temperature de la piece par rapport a 15 degree 
  UC ucEtatChauffage:1;   // etat ON ou OFF du chauffage
  UC ucEtatLumiere: 1;    // etat ON ou OFF de la lumiere
};

union UNPiece           //Union entre la structure piece et un Octet
{
 struct STPiece stPiece;
 UC ucPiece;
};



// ***************** FICHIER:CLPiece.H
//
// Description: La classe contient des fonctions pour cntroler les
//              piece du simulateur de maison       
//             
//
// COMPOSITION: Aucune
//
//
// HERITAGE: CLInOutBase.
//
//FONCTION:
//
//    Fonction permettant de lire la temperature      fEtatTemperature(void)
//    Fonction qui retourne l etat du chauffage       ucEtatChauffage(void)
//    Fonction qui retourne l etat de la lumiere      ucEtatLumiere(void)
//    Fonction qui permet d allumer les lumieres 
//    tout en conservant le chauffage de la piece      vSetLumiere(UC ucLumiere,
//                                           USI usiAdresseConsigne, UC ucPiece)
//      
//    Fonction qui va lire la temperature de consigne d une piece 
//    fGetTemperatureConsigne(USI usiAdresseConsigne, UC ucPiece)
//
//    
//   Fonction prive qui va lire au niveau materiel vLirePiece(USI usiAdresse)
//   Fonction prive qui va ecrireau niveau materielvEcrirePiece(USI usiAdresse)
//
//CONSTRUCTEUR: 
//       Constructeur par defaut          CLPiece(void)
//       Constructeur initialisateur      CLPiece(USI usiAdresse)
//
//
//DESTRUCTEUR:
//
//       destructeur reinitialise une piece      ~CLPiece(void)
//
//  AUTEUR : Gabriel Fortin-Belanger
//  DATE CREATION :    2014-02-07		 VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
//******************************************************************************

class CLPiece : public CLInOutBase
{
  public:
    USI usiAdresseMaison;
    UNPiece unPiece;
    CLPiece(void);
    CLPiece(USI usiAdresse);
    ~CLPiece(void);
    float fEtatTemperature(void);
    UC ucEtatChauffage(void);
    UC ucEtatLumiere(void);
    void vSetLumiere(UC ucLumiere,USI usiAdresseConsigne, UC ucPiece);
    float fGetTemperatureConsigne(USI usiAdresseConsigne, UC ucPiece);
    UC ucTemperatureHexa;
    
  private:
    void vLirePiece(USI usiAdresse);
    void vEcrirePiece(USI usiAdresse);
};


//******************************************************************************

#endif
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

