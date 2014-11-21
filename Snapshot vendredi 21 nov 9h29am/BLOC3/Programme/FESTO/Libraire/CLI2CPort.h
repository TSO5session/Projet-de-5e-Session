// ***************** FICHIER:CLI2CPort.H
//
//  Contient les definitions de classe pour utiliser  I2C a haut niveau avec
//  plusieurs composants i2c.
//  
//
//  Application realisee avec IAR
//
//  AUTEUR : Gabriel Fortin-Belanger
//  DATE CREATION :    2014-02-07		 VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
//******************************************************************************
#ifndef CLI2CPORTH
   #define  CLI2CPORTH
   #include "_DeclarationGenerale.h"
   #include "CLInOutBase.h"
   #include "CLI2CBase.h"

   

// ***************** FICHIER:CLI2CPort.H
//
// Description: La classe contient des fonctions pour cntroler des 
//              circuit i2c de tout type.
//             
//
// COMPOSITION: Aucune
//
//
// HERITAGE: CLI2CBase.
//
//FONCTION:Fonction Pour lire une donne sur un chip i2c 
//         ucI2CLireDonnee(UC ucAdrChip, US usiAdrDepart,UC ucTypeAdr)
//         Fonction Pour Ecrire une donne sur un chip i2c 
//       vI2CEcrireDonnee(UC ucAdrChip,US usiAdrDepart,UC ucTypeAdr,UC ucDonnee)
//
//
//
//
//
//CONSTRUCTEUR: 
//   Constructeur par defaut           CLI2CPort(void)
//       
//
//
//DESTRUCTEUR:
//
//       destructeur                   ~CLI2CPort(void)
//
//  AUTEUR : Gabriel Fortin-Belanger
//  DATE CREATION :    2014-02-07		 VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
//******************************************************************************

class CLI2CPort : public CLI2CBase
{
  public:
  CLI2CPort(void);
  ~CLI2CPort(void);
   UC ucI2CLireDonnee(UC ucAdrChip, US usiAdrDepart,UC ucTypeAdr);
   void vI2CEcrireDonnee(UC ucAdrChip,US usiAdrDepart,UC ucTypeAdr,UC ucDonnee);
    
    
  protected:

    
    
  private:


};


//******************************************************************************

#endif
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

