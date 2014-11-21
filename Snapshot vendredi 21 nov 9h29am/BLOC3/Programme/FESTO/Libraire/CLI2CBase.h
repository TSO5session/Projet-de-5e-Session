// ***************** FICHIER:CLI2CBase.H
//
//  Contient les definitions de classe pour utiliser I2C
//  
//
//  Application realisee avec IAR
//
//  AUTEUR : Gabriel Fortin-Belanger
//  DATE CREATION :    2014-02-07		 VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
//******************************************************************************
#ifndef CLI2CBASEH
   #define  CLI2CBASEH
   #include "_DeclarationGenerale.h"
   #include "CLInOutBase.h"



// ***************** FICHIER:CLI2CBase.H
//
// Description: Classe pour controler le hardware avec le protocole i2c
//                    
//             
//
// COMPOSITION: Aucune
//
//
// HERITAGE: -
//
//FONCTION:
//
//    Fonction permettant de Demarrer la communication i2c   vI2CStart(void)
//    Fonction permettant d arreter la communication i2c     vI2CStop(void);
//    
//    
//    Fonction qui va lire un Octet en i2c   ucI2CLireOctet(UC ucAckNoAck)
//    Fonction qui va ecrire un octet en i2c ucI2CEcrireOctet(UC ucValeur)                                       
//      
//    Fonction qui va ecrire un bit en i2c   ucI2CEcrireBit(UC ucValeur)
//    Fonction qui va lire un bit en i2c     ucI2CLireBit(void)
//    Fonction qui va faire un delai         vDelais(void)
//    
//   
//  
//
//CONSTRUCTEUR: 
//       Constructeur par defaut        CLI2CBase  
//       Constructeur initialisateur    ~CLI2CBase  
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

class CLI2CBase
{
  public:
  CLI2CBase(void);
  //CLI2CBase();
  ~CLI2CBase(void);
    
    
  protected:
  void vI2CStart(void);
  void vI2CStop(void);
  UC ucI2CLireOctet(UC ucAckNoAck);
  UC ucI2CEcrireOctet(UC ucValeur);
    
    
  private:
  UC ucI2CEcrireBit(UC ucValeur);
  UC ucI2CLireBit(void);
  void vDelais(void);

};


//******************************************************************************

#endif
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

