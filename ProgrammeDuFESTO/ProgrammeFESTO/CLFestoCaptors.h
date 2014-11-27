// **************************CLFestoCaptors.h
// Auteur:       Vincent Chouinard
// Date:         27 novembre 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.10
//
// Description:
// *****************************************************************************
#include "_DeclarationGenerale.h"  // Raccourcis de programmation & variables
#include "CLIOPCF8574.h"           // Pour lire au travers d'un PCF8574

#ifndef CLFESTOCAPTORSH
  #define CLFESTOCAPTORSH

#define AdresseCapacitive 0x42
#define AdresseOptic      0x42
#define AdresseIductive   0x42
#define AdresseHeight     0x43
#define AdresseVentouse   0x43

class CLFestoCaptors 
{
public:
   CLFestoCaptors(void);             // ***Constructeur par defaut
   CLFestoCaptors(UC ucParametre);   // ***Constructeur initialisateur
  ~CLFestoCaptors(void);             // ***Destructeur

   UC ReadCapacitiveCaptor (void);   // Lit le capteur capacitif
   UC ReadOpticCaptor      (void);   // lit le capteur optique
   UC ReadInductiveCaptor  (void);   // lit le capteur magnétique
   UC ReadHeightCaptor     (void);   // Lit le capteur de hauteur du bloc (capteur A4)
   UC ReadPreVentouseCaptor(void);   // Lit le dernier capteur avant que la ventouse ne prenne le bloc
   
   class CLIOPCF8574 PCF3;//(0x43);    
   class CLIOPCF8574 PCF4;   
   
protected:

private:
         
};
#endif
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX