// **************************Fichier.cpp
// Auteur:       Vincent Chouinard
// Date:         20 juillet 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.1
//
// Description:
// *****************************************************************************
#include "_DeclarationGenerale.h"  // Raccourcis de programmation & variables
#include "Optik.h"               // Fichier de definitions du clavier

char Encodeur :: LastState = 'Z';      // Trame incomplete.



//******************************************************************************
//                            LE CONSTRUCTEUR PAR DEFAUT
// *****************************************************************************
Encodeur :: Encodeur(void)
{
LastState = P1_7;
}

//******************************************************************************
//                            LE CONSTRUCTEUR PAR DEFAUT
// *****************************************************************************
Encodeur :: Encodeur(UC ucParametre)
{

}

// *****************************************************************************
//                            LE DESTRUCTEUR
// *****************************************************************************
Encodeur :: ~Encodeur(void)
{

}

char Encodeur :: LogicAnalyser(void)
{
char Code = 'Z'; 

UC ChanelA = P1_7;
UC ChanelB = P1_6;

if((LastState == 0) && (ChanelA == HIGH)) // Si il  a une montee sur P1_7
  {
   if(ChanelB == LOW) // Est-ce que P1_6 est a LOW?
     {                // Si oui
      Code = 'A';
     }
   else               // Si non
    {
     Code = 'B';
    }
}
LastState = P1_7;
return(Code);
}

//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
