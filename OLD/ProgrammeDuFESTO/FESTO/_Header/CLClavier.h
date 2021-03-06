// **************************Clavier.h
// Auteur:       Louis-Normand Ang-Houle, Hicham Safoine, Vincent Chouinard
// Date:         1 mai 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.1
//
// Description:  Fichier de definitions pour utiliser le clavier du uPSD
// *****************************************************************************
///////////////////////////////////////////////////////////////////////////////
//                     Infos relatives au montage du clavier sur le uPSD
// Utilise un 74HCC922
// 74HCC922      uPSD
//        A sur D0
//        B sur D1
//        C sur D2
//        D sur D3
//       OE sur CS1     (OutputEnable sur chip select 1)
//       DA sur INT0    (AataAvailible sur interrupt0)
///////////////////////////////////////////////////////////////////////////////

#include "DeclarationGenerale.h"  // Raccourcis de programmation & variables
#include "CLInOutBase.h"          // Fichier de definitions pour faire des I/O

#ifndef CLAVIERH
  #define CLAVIERH
  
  #define CS1 0xF900     // Chip Select 1 du uPSD sur 0xF900 

class CLClavier //: public CLInOutBase
{
public: 
   CLClavier(void);              // ***Constructeur par defaut
  ~CLClavier(void);              // ***Destructeur 
   UC ucBoutonAppuye(void);      // Fonction de logique de selection du bouton pese  

protected:

private:    
   static UC ucDonnee;      // Pour lire une donnes sur une adresse
   static UC *ucPtrAdresse; // pour pointer sur une adresse
   
   __interrupt static void vKeyboardInterrupt(void); 
};   
#endif
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 