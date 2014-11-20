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
#include "DeclarationGenerale.h"  // Raccourcis de programmation & variables
#include "CLRS232.h"              // En-tete de communication RS232

#ifndef CLXBEEH
  #define CLXBEEH

class CLXbee
{
public:
   CLXbee(void);             // ***Constructeur par defaut
   CLXbee(UC ucParametre);   // ***Constructeur initialisateur
  ~CLXbee(void);             // ***Destructeur
   
   void SendString (char const  *ucMonString); // Transmettre un string    par Xbee
   void SendCarac  (UC ucCar);                 // Transmettre un caractère par Xbee
   void SendNumber (UI uiChiffreAAfficher);    // Transmettre un chiffre   par Xbee
   UC   GetChar    (void);                     // Lire un caractère        par Xbee
   
protected:

private:
   class CLRS232 Serial;
};
#endif
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
