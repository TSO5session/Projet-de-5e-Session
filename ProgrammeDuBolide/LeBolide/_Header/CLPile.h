// ********************** FICHIER: CLPile.h
//  Auteur:      Vincent Chouinard
//  Date:        17 avril 2014
//  Version :    1.0
//
//  CLPile         ---> Constructeur par defaut
//  CLPile(UINT16) ---> Constructeur initialisateur
// ~CLPile         ---> Destructeur
//
//  fLirePile      ---> Met le MAX1236 en mode "Lecture de la pile" et retourne
//                      une valeur correspondant au niveau de tension de la pile
//
//  Compilateur: IAR 8.1
//
//  Description: Fichier de definitions pour lire le niveau de tension de la
//               pile.
// *****************************************************************************
#include "DeclarationGenerale.h"
#include "CLADCMAX1236.h"
#include "CLTLV2544.h"

#ifndef CLPILEH
   #define CLPILEH

#define CONVPILE 0.00133
#define PILE     3

class CLPile : public CLADCMAX1236
{
public:
   CLPile(void);             // ***Constructeur par defaut
   CLPile(UC ucParametre);   // ***Constructeur initialisateur
  ~CLPile(void);             // ***Destructeur
  
   float fLirePile(void);       // pour lire la tension de la pile

protected:

private:
#ifdef I2C_DALLAS
 class CLADCMAX1236 clADCPile;
#endif
  
#ifdef SPI_DALLAS
 class CLTLV2544 clADCPile;
#endif
};
#endif
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
