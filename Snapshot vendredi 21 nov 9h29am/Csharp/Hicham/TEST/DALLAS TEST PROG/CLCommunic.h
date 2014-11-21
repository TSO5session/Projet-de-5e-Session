//**********************  Fichier: CLCommunic.h
//  Description : Fichier d'entete pour le fichier CLCommunic.cpp
//  
//  Composition: aucune
//  Heritage : aucun
//  Fonctions necessaire pour communiquer avec le port serie:
//
//CLCommunic()                                          Constructeur par defaut
//CLCommunic(UC ucLongBuf, UC ucLongTrame, UI uiBaud)  Construct initialisateur
//~CLCommunic()                                                     Destructeur 
//UC ucInitLongTrame(UC ucLong)                 Pour initialiser longueur trame
//UC static ucLireNbCaractRecu()         Fct pour lire nombre de caractere recu
//UC ucLireEtatTrame()                         Fct pour lire l'etat de la trame
//char *ucpLireTrame()                Fct qui retourne adresse du debut lecture
//vTransCaratere(UC ucCar)                    Fct pour transmettre un caractere
//vTransChiffre(UI uiChiffreAAfficher)          Fct pour transmettre un chiffre 
//vAffChaine(char const *ucpMessage)   Fct pour transmettre chaine de caractere
//void vInitBaudRate(UI uiBaud)        Fct pour intialiser le baudrate et timer
//__interrupt static void vInteruptSerial();     Fct pour recevoir un caractere
//UC ucValideTrame()                                 Fct pour valider une trame

//
//  Programmeur: Philippe Dubois
//  Cours: 247-436
//                                                                           
//  Date: 10 avril 2014
//                                                                           //
//  Compilateur: IAR 8.1                                  
//                                                                           //
//  Modification:                                                            //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////
#ifndef CLCOMMUNICH               // Si CLCOMMUNICH non defini.
   #define CLCOMMUNICH            // Defini CLCOMMUNICH

#include <stdio.h>               // Definition des function I/O (printf, getchar
#include "_DeclarationGenerale.h" // Pour les declaration generale
#include "TypeCible.h"            // Pour les definition des registre.
#include "ConversionKeilToIAR.h"  //

class RS232            
{
public:                     
   RS232(void);                                    // Constructeur par defaut.
   RS232(UC ucLongBuf, UC ucLongTrame, UI uiBaud); // Constructeur initialisateur                                   
  ~RS232(void);                                    // Destructeur
  
  void SendString(char const *ucpMessage);         // Envoyer un string
  void SendCar(char Caractere);
  char GetCar(void);
                                    
protected:
  
private:                      
   void SetConfig(void);
}; 
#endif
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
















