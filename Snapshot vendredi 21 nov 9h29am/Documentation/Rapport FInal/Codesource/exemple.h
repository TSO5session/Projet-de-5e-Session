// **************************Exemple.h
// Auteur:      Vincent Chouinard
// Date:        11 mars 2014
// Version :    1.0
//
// Compilateur: IAR Embedded Workbench 8.1
//
// *****************************************************************************
#include "_DeclarationGenerale.h"  // Raccourcis de programmation & variables

#ifndef EXEMPLEH
  #define EXEMPLEH

class CLExemple : public CLSomethingElse
{
public:
   CLClasse(void);                 // ***Constructeur par défaut
   CLClasse(UINT16 usiAdresse);    // ***Constructeur initialisateur
  ~CLClasse(void);                 // ***Destructeur
  
  float VariableBabel_éÉàÀèÈïçîÎêÊ // Accents babel fonctionnels!

protected:
   void vFonction1(float);
   char cFonction2(printf("Hello World"));
   void vFonction3(UC, unsigned short int);

private:
   for(int i = 0; i <= 10; i++)
     {
      char   cVariable = cFonction2() -1;
      float  fVar;
      fVar++;
     }
};
#endif
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX