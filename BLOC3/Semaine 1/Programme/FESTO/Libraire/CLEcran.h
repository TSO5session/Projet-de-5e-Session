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


#ifndef CLECRANH
   #define  CLECRANH
   #include "_DeclarationGenerale.h"
   #include "CLInOutBase.h"


// ***************** FICHIER:CLEcran.H
//
// Description: La classe contient des fonctions In et Out qui peuvent 
//              travailler a 8 ou 16 bits. Pour les In et Out a 16bits il faut
//              fournir un parametre qui donne le type de transfert.
//
// COMPOSITION: Aucune
//
//
// HERITAGE: CLInOutBase.
//
//FONCTION:
//
//  Fonct permet d'afficher un caractere                   vLcdAffCar ( ).
//  Fonct permet d'effacer l'ecran                         vLcdClr ( ).
//  Fonct permet d'initialiser l'ecran                     vLcdInit ( ).
//  Fonct permet de positionner le curseur                 vLcdPoscurC0L1 ( ).
//  Fonct permet d'attendre ecran pret                     vLcdBusy( ).
//  Fonct delais                                           vDelais( ).
//  Fonct permet afficher chaine de caractere              vLcdAffChaine().
//  Fonct permet afficher un ecran de 4 chaine             vLcdAffEcran().
//  Fonct permet afficher nombre hexadecimal               vLcdAffCarHex().
//  Fonct permet Generer un caractere cree par utilisateur vLcdCarGen().
//
//
//CONSTRUCTEUR: 
//       Constructeur par defaut          CLEcran(void)
//       Constructeur initialisateur      CLEcran(unsigned short int usiAdresse)
//
//
//DESTRUCTEUR:
//
//       destructeur efface l ecran      ~CLEcran(void)
//
//  AUTEUR : Gabriel Fortin-Belanger
//  DATE CREATION :    2014-02-07		 VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
//******************************************************************************


class CLEcran : public CLInOutBase
{
  public:
    void vLcdAffCar(UC ucCarac);  
    void vLcdClr(void);
    void vLcdPoscurC0L1(UC col,UC ligne);
    void vLcdInit(void);
    void vLcdAffChaine(char *ucpMessage);
    void vLcdAffEcran(char *ucpEcran);
    void vLcdAffCarHex(UC ucCarac);
    void vLcdCarGen(UC *ucTabCarac);
    
    CLEcran(void);
    CLEcran(unsigned short int usiAdresse);
    
    ~CLEcran(void);
  
    
  private:
   void vLcdBusy(void);
   void vDelaisEcran(UINT16 usiTemps);
   
   UINT16 usiAdresseEcran;
    
  protected:
  


};

#endif
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@