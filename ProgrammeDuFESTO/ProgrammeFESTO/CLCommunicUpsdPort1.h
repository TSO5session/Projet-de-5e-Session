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
//  Programmeur: Vincent Chouinard
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

#include "_DeclarationGenerale.h" // Pour les declaration generale
#include "TypeCible.h"            // Pour les definition des registre.
#include "ConversionKeilToIAR.h"  //

#define LONGUEURTRAME  4          // Longueur trame par defaut.
#define LONGUEURTAMPON 12         // Longueur tampon par defaut.
#define TRAMECOMPLET   1          // Pour l'etat de la trame.
#define TRAMEINCOMPLET 0          // Pour l'etat de la trame.

class CLCommunic                  // Classe CLCommunic
{
public:                           // Menbres publics.
   CLCommunic(void);                                    // Constructeur par defaut.
   CLCommunic(UC ucLongBuf, UC ucLongTrame, UI uiBaud); // Constructeur initialisateur
  ~CLCommunic(void);                                    // Destructeur

UC    ucLireEtatReception(void);
UC    GetChar(void);                        // Lit un caractere
UC    ucInitLongTrame(UC ucLong);           // Intialiser la longueur trame.
UC    static ucLireNbCaractRecu(void);      // Lire le nombre de caractere recu
UC    ucLireEtatTrame(void);                // Lire l'etat de la trame.
char *ucpLireTrame(void);                   // Retourne ladresse du tableau.
void  Send(UC ucCar);                       // Transmettre un caractere.
void  SendNumber(UI uiChiffreAAfficher);    // Transmettre un chiffre sur le port serie
void  SendString(char const *ucpMessage);   // Transmettre une chaine de caractereS

protected:

private:                      // Menbres prives.
void vInitBaudRate(UI uiBaud);// Fonction pour intialiser le baudrate et timer.

__interrupt static void vInteruptSerial(void);// Fonction d'interruption pour
                                              // recevoir un caractere.
UC ucValideTrame(void);                       // Fct pour valide une trame.

static char *cTabCaractereRecu;     // Pour pointeur sur tableau de char.
static char *cpDebutTrame;          // Pointeur sur debut tampon.
static char *cpFinTrame;            // Pointeur sur fin tampon.
static char *cptrEcriture;          // Pointeur pour position ecriture.
static char *cptrLecture;           // Pointeur pour lecture.
static UC    ucEtatTrame;           // Pour connaitre l'etat de la trame
static UC    ucNbCaractRecu;        // Pour connaitre le nbr de caractere recu.
static UC    ucLongueurTrame;       // Pour connaitre la longueur de la trame.
static UC    ucLongueurTampon;      // Pour connaitre la longueur du tampon.
static UC    ucCaractereRecu;
static UC    ucEtatReception;
};
#endif
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
















