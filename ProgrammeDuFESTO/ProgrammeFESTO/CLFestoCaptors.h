// **************************Fichier.h
// Auteur:       Prenom nom
// Date:         19 octobre 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.1
//
// Description:
// *****************************************************************************
#include "_DeclarationGenerale.h"  // Raccourcis de programmation & variables
#include "CLI2CPort.h"             // Pour utiliser le bus I2C Software
#include "CLSPI.h"                 // Pour utiliser le bus SPI

#ifndef CLFESTOCAPTORSH
  #define CLFESTOCAPTORSH

class CLFestoCaptors 
{
public:
   CLFestoCaptors(void);             // ***Constructeur par defaut
   CLFestoCaptors(UC ucParametre);   // ***Constructeur initialisateur
  ~CLFestoCaptors(void);             // ***Destructeur

   UC readCapacitiveCaptor (void);   // Lit le capteur capacitif
   UC readOpticCaptor      (void);   // lit le capteur optique
   UC readInductiveCaptor  (void);   // lit le capteur magnétique
   
   UC readHeightCaptor     (void);   // Lit le capteur de hauteur du bloc (capteur A4)
   UC readPreVentouseCaptor(void);   // Lit le dernier capteur avant que la ventouse ne prenne le bloc
   
protected:

private:
   class CLSPI      SPI     ; // Initialise la communication SPI
   class CLI2CPort  I2C     ; // Initialise le communication I2C Software
};
#endif
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX