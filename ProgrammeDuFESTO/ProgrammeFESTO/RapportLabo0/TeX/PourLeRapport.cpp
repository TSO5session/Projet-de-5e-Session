\begin{lstlisting}[label={list:first},caption=Code source en directe]
// **************************CLClavier.cpp
// Auteur:      Vincent Chouinard
// Date:        17 avril 2014
// Version :    1.0
//
// Compilateur: IAR 8.1
//
// Description: Fichier permettant d'utiliser le clavier de l'uPSD
//
///////////////////////////////////////////////////////////////////////////////
//                     Infos relatives au montage du clavier sur le uPSD
// Utilise un 74HCC922
// 74HCC922     uPSD
//        A sur D0
//        B sur D1
//        C sur D2
//        D sur D3
//       OE sur CS1     (OutputEnable sur chip select 1)
//       DA sur INT0    (DataAvailible sur interrupt0)
///////////////////////////////////////////////////////////////////////////////
#include "CLClavier.h"            // Fichier de definitions du clavier

UC  CLClavier  :: ucEtatClavier = INACTIF;

//******************************************************************************
//                            LE CONSTRUCTEUR PAR DEFAUT
// *****************************************************************************
CLClavier :: CLClavier(void)
{
EX0 = 1;
IT0 = 1;
}

// *****************************************************************************
//                            LE DESTRUCTEUR
// *****************************************************************************
CLClavier :: ~CLClavier(void)
{

}

// ********************** FONCTION: ucBoutonAppuye()
//
// DESCRIPTION:         Fonction pour transmettre un caractere
//
// INCLUDE:             "Clavier.h"
//
// PROTOTYPE:           UC ucBoutonAppuye(void)
//
// PROCEDURE D'APPEL:   UC = ucBoutonAppuye()
//
// PARAMETRE D'ENTREE:  AUCUN
//
// PARAMETRE DE SORTIE: UC ---> Contient le bouton appuye
//
// Auteur:              Vincent Chouinard
// Date:                17 avril 2014 (Version 1.0)
// *****************************************************************************
UC CLClavier :: ucBoutonAppuye(void)
{
UC ucEtat;
if(ucEtatClavier == ACTIF)
  {
   ucEtat = ACTIF;
  }
else
  {
   ucEtat = INACTIF;
  }
return(ucEtat);
}

UC CLClavier:: ucLireClavier(void)
{
UC  uctTouche[]={         // Tableau des correspondances des
    '1','2','3','A',      // touches du clavier et de leurs
    '4','5','6','B',      // positions.
    '7','8','9','C',      //
    '*','0','#','D'};     //

ucToucheClavier = ucIn(0xF900);
ucEtatClavier   = INACTIF;
return(uctTouche[ucToucheClavier]);
}

// ********************** FONCTION: vkeyboardInterrupt()
//
// DESCRIPTION:         Fonction d'interruption pour lire le clavier
//
// INCLUDE:             "Clavier.h"
//
// PROTOTYPE:           __interrupt void vkeyboardInterrupt(void)
//
// PROCEDURE D'APPEL:   #pragma vector = 0x03 (Seul un interrupt0 peut appeler
//                                             cette fonction)
//
// PARAMETRE D'ENTREE:  AUCUN
//
// PARAMETRE DE SORTIE: AUCUN
//
// Auteur:              Vincent Chouinard
// Date:                17 avril 2014 (Version 1.0)
// *****************************************************************************
#pragma vector = 0x03 // Lors d'une interruption de type INTERRUPT 0
__interrupt void CLClavier :: vKeyboardInterrupt(void)
{
EA = 0;
ucEtatClavier = ACTIF;
EA = 1;
}
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
//**********************  Fichier: CLCommunic.cpp
//  Description : Fonctions necessaire pour communiquer avec le port serie:
//
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
//  Composition: aucune
//  Heritage : aucun
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
#include "CLCommunic.h"             //inclue CLCommunic.h.
#include "ConversionKeilToIAR.h"

 ///// Initialise les variables statiques.
UC    CLCommunic :: ucEtatTrame       = INCOMPLET;      // Trame incomplete.
UC    CLCommunic :: ucNbCaractRecu    = 0;              // Nombre de caractere recu = 0
UC    CLCommunic :: ucLongueurTrame   = LONGUEURTRAME;  // Initialise les longueur du
UC    CLCommunic :: ucLongueurTampon  = LONGUEURTAMPON; // buffer et trame.
UC    CLCommunic :: ucCaractereRecu   = NULL;
UC    CLCommunic :: ucEtatReception   = INACTIF;
char *CLCommunic :: cpDebutTrame      = NULL;           // Initialise lse pointeur a NULL.
char *CLCommunic :: cpFinTrame        = NULL;
char *CLCommunic :: cptrEcriture      = NULL;
char *CLCommunic :: cptrLecture       = NULL;
char *CLCommunic :: cTabCaractereRecu = NULL;


//*****************************************************************************
// Nom de la fct:   CLCommunic(void)
// Description:     Constructeur qui permet d'initialiser par defaut le port
//                  serie du micro controleur a  9600 bdr, un tampon de 12
//                  et une trame a 4 characteres. Initialise les differents
//                  pointeurs au debut et la la fin du tampon.
//
// INCLUDE:         #include "_TypeCible.h", "CLCommunic.h"
// Prototype:       CLCommunic(void);
//
//
// Parametre d'entree: Aucune
//
// Parametre de sortie: Aucune
//
// Procedure appelees: vInitBaudRate(),
//
// Exemple d'appel: class CLCommunic clCommunic();
//
// Fait par: Philippe Dubois
// Date:            10 avril 2014
// Revision :       A
// Modification :
//*****************************************************************************
CLCommunic::CLCommunic(void)
{
 cTabCaractereRecu = new char[LONGUEURTAMPON]; // Definit tableau de longueur
                                               // LONGUEURTAMPON.
 ucLongueurTrame  = LONGUEURTRAME;             // Definit longueur de la trame.
 ucLongueurTampon = LONGUEURTAMPON;            // Definit longueur tampon.

 cpDebutTrame = &cTabCaractereRecu[0];                  // Pointeur sur debut tampon.
 cpFinTrame   = &cTabCaractereRecu[(LONGUEURTAMPON-1)]; // Pointeur sur fin tampon
 cptrEcriture = &cTabCaractereRecu[0];                  // Pointeur ecriture au debut.
 cptrLecture  = &cTabCaractereRecu[0];                  // Pointeur lecture au debut.

 vInitBaudRate(9600);                                   // Initialise le port serie.
}


//*****************************************************************************
// Nom de la fct:   CLCommunic
// Description:     Constructeur qui permet d'initialiser  le port
//                  serie du micro controleur a  la vitesse voulue, un tampon
//                  de taille dynamique et la longueur de la trame.
//                  Initialise les differents pointeurs au debut et la la fin
//                  du tampon.
//
// INCLUDE:         #include "_TypeCible.h", "CLCommunic.h"
// Prototype:     CLCommunic(UC ucLongBuf, UC ucLongTrame, UI uiBaud);
//
//
// Parametre d'entree: ucLongBuf pour longueur du trableau
//                     ucLongTrame pour longueur trame
//                     uiBaud pour la vitesse du port serie
//
// Parametre de sortie: Aucune
//
// Procedure appelees: vInitBaudRate(), ucInitLongTrame()
//
// Exemple d'appel: class CLCommunic clCommunic();
//
// Fait par: Philippe Dubois
// Date:            10 avril 2014
// Revision :       A
// Modification :
//*****************************************************************************
CLCommunic :: CLCommunic(UC ucLongBuf, UC ucLongTrame, UI uiBaud)
{
 cTabCaractereRecu = new char[ucLongBuf]; // Initialise un tableau de longueur
                                          // voulue.
 ucLongueurTampon = ucLongBuf;            // Longueur tampon = ucLongBuf.
 ucInitLongTrame(ucLongTrame);            // Verifie si longueur trame
                                          // < longueur tampon.
 cpDebutTrame = &cTabCaractereRecu[0];    // Pointeur pour debut tampon.
 cpFinTrame   = &cTabCaractereRecu[(ucLongBuf-1)];// Pointeur pour fin tampon.
 cptrEcriture = &cTabCaractereRecu[0];    // Pointeur ecriture et lecture au
 cptrLecture  = &cTabCaractereRecu[0];    // debut du tampon.
 vInitBaudRate(uiBaud);                   // Initialise la vitesse de
                                          // communication.
}

//*****************************************************************************
// Nom de la fct:   ~CLCommunic
// Description:     Desctructeur qui libert la memoire pris par le tampon.
//
// INCLUDE:        #include "_TypeCible.h", "CLCommunic.h"
// Prototype:      ~CLCommunic(void);
//
//
// Parametre d'entree: aucun
//
// Parametre de sortie: Aucun
//
// Procedure appelees: aucun
//
// Exemple d'appel:
//
// Fait par: Philippe Dubois
// Date:            10 avril 2014
// Revision :       A
// Modification :
//*****************************************************************************
CLCommunic :: ~CLCommunic(void)
{
if(cTabCaractereRecu)            // Verification pour s'assurer que le
  {                                // pointeur n'a pas deja ete libere
   delete cTabCaractereRecu;       // Libert la memoire prise par le tampon.
   cTabCaractereRecu = NULL;       // Pour mettre a 0 le pointeur.
  }
}

//*****************************************************************************
// Nom de la fct:   ucInitLongTrame
// Description:     Verifie si la trame entree est inferieure au tampon
//                  sinon la longueur de la trame = a celle du buffer.
//
// INCLUDE:        #include "_TypeCible.h", "CLCommunic.h"
// Prototype:      UC ucInitLongTrame(UC ucLong);
//
//
// Parametre d'entree: ucLong longueur voulue
//
// Parametre de sortie: ucValide pour valide ou non la taille
//
// Procedure appelees: aucun
//
// Exemple d'appel:  ucInitLongTrame(ucLongTrame);
//
// Fait par: Philippe Dubois
// Date:            10 avril 2014
// Revision :       A
// Modification :
//*****************************************************************************

UC CLCommunic :: ucInitLongTrame(UC ucLong)
{
UC ucValide;                           // Varaible pour valider ou non.

if(ucLong <= ucLongueurTampon)         // Si longueur trame voulue <= a la longueur
  {                                    // du tampon.
   ucLongueurTrame = ucLong;           // longueur trame = longueur trame voulue.
   ucValide = VRAI;                    // ucValide = Vrai.
  }

if(ucLong > ucLongueurTampon)          // Si longueur trame voulue > a la longueur
  {                                    // du tampon.
   ucLongueurTrame = ucLongueurTampon; // longueur trame = longueur tampon.
   ucValide = FAUX;                    // ucValide = Faux.
  }

return(ucValide);                      // Retourne etat de ucValide.
}


//*****************************************************************************
// Nom de la fct:   ucValideTrame
// Description:     Valide la trame recue, additionne tous les caracteres
//                  recues et commpare avec le checksum.
//
// INCLUDE:        #include "_TypeCible.h", "CLCommunic.h"
// Prototype:      UC ucValideTrame(void);
//
//
// Parametre d'entre: aucun
//
// Parametre de sortie: ucValide pour valide ou non la trame.
//
// Procedure appelees: aucun
//
// Exemple d'appel: if(ucValideTrame() == VRAI)
//
// Fait par: Philippe Dubois
// Date:            10 avril 2014
// Revision :       A
// Modification :
//*****************************************************************************
UC CLCommunic :: ucValideTrame(void)
{
UC ucValide;               // Variable pour etat valide ou non.
UC ucSomme;                // variable pour la somme des caracteres recus.
ucSomme = 0;               // Initialise la somme a 0.
UC ucBoucle;               // Varialbe pour boucle.

char *cPtrVerification;    // pointeur sur la tramme recu
cPtrVerification = cptrLecture; // Intialise l'adresse du debut de la trame.

ucBoucle = (ucLongueurTrame - 1);         // Pour additionner toutes les valeurs
                                          // sauf le dernier
for(;ucBoucle > 0; ucBoucle--)
  {
   ucSomme = *cPtrVerification + ucSomme; // Additionne le caractere avec somme.
   cPtrVerification ++;                   // Valeur suivante.
  }
                                          // Compare la somme avec le checksum recu.
if(ucSomme == *cPtrVerification)          // Si egal?
  {
   ucValide = VRAI;                       // Trame correcte.
  }
else                                      // Sinon
  {
   ucValide = FAUX;                       // Trame incorrecte.
  }

return(ucValide);                         // Retourne valide ou non.
}

//*****************************************************************************
// Nom de la fct:   vTransCaratere                  Fait par: Philippe Dubois
// Date:            2 octobre 2013
// Revision :       A
// Modification :
// INCLUDE:         #include "_TypeCible.h", "CLCommunic.h"
// Prototype:       void vTransCaratere(UC ucCar);
//
// Description:     Fonction qui permet de transmettre un caractere par le port
//                  serie, et on attend que le caractere soit completement
//                  envoye par "polling" avec le flag TI_0.
//
// Parametre d'entree: ucCar: caractere qu'on veut envoyer.
//
//
// Parametre de sortie: aucune
//
// Procedure appelees: aucune.
//
// Exemple d'appel: clCommunic.vTransCaratere('A')
//*****************************************************************************
void CLCommunic :: vTransCaratere(UC ucCar)
{
SBUF0 = ucCar;             // Envoye le caractere dans SBUF0 pour le transmetre sur TX
while(TI_0 ==0);           // Si le flag TI_0 se met a 1 (termine)
TI_0  = 0;                 // Remet le flag a 0.
}



//*****************************************************************************
// Nom de la fct:   vAffChaine
// Description:     Transmet une chaine de caracteres sur le port serie.
//
// INCLUDE:        #include "_TypeCible.h", "CLCommunic.h"
// Prototype:      void vAffChaine(char const *ucpMessage)
//
//
// Parametre d'entre: *ucpMessage pour chaine de caractere.
//
// Parametre de sortie: aucun
//
// Procedure appelees: vTransCaratere()
//
// Exemple d'appel: clCommunic.vAffChaine("TEST");
//
// Fait par: Philippe Dubois
// Date:            10 avril 2014
// Revision :       A
// Modification :
//*****************************************************************************
void CLCommunic :: vAffChaine(char const *ucpMessage)
{
while(*ucpMessage != 0x00)          // Tant qu'on a pas atteint la fin de
  {                                 // la chaine.
   vTransCaratere(*ucpMessage);     // Transmet le caractere.
   ucpMessage++;                    // Passe au caractere suivant.
  }
}

//*****************************************************************************
// Nom de la fct:   ucLireNbCaractRecu                Fait par: Philippe Dubois
// Date:            2 octobre 2013
// Revision :       A
// Modification :
// INCLUDE:         #include "_TypeCible.h", "CLCommunic.h"
// Prototype:       UC ucLireNbCaractRecu(void);
//
// Description:     Fonction qui retourne le nombre de caractere recu.
//
//
// Parametre d'entree: aucun
//
//
// Parametre de sortie: ucNombreCaractere: nombre de caractere recu.
//
// Procedure appelees: aucune.
//
// Exemple d'appel: if(ucLireNbCaractRecu() < (ucLongueurTrame -1))
//*****************************************************************************
UC CLCommunic :: ucLireNbCaractRecu(void)
{
return(ucNbCaractRecu);          // Retourne le nombre de caractere recu.
}
//*****************************************************************************
// Nom de la fct:   ucLireEtatTrame                  Fait par: Philippe Dubois
// Date:            2 octobre 2013
// Revision :       A
// Modification :
// INCLUDE:        #include "_TypeCible.h", "CLCommunic.h"
// Prototype:       UC ucLireEtatTrame(void);
//
// Description:     Fonction qui permet de savoir si une trame est complete.
//
//
// Parametre d'entree: aucun
//
//
// Parametre de sortie: ucEtatTrameRecu: a 1 pour complete et 0 si imcomplete.
//
// Procedure appelees: aucune.
//
// Exemple d'appel:if(ucLireEtatTrame()==TRAMECOMPLET)
//*****************************************************************************
UC CLCommunic :: ucLireEtatTrame(void)
{
return(ucEtatTrame);            // Retourne l'etat de la trame.
}
//*****************************************************************************
// Nom de la fct:   *ucpLireTrame                   Fait par: Philippe Dubois
// Date:            2 octobre 2013
// Revision :       A
// Modification :
// INCLUDE:         #include "_TypeCible.h", "CLCommunic.h"
// Prototype:       UI *ucpLireTrame(void);
//
// Description:     Fonction qui permet de transmettre l'adresse du tableau
//                  contenant la trame de caractere, et reinitialiser l'etat
//                  de la  trame.
//
// Parametre d'entree: aucun
//
//
// Parametre de sortie: uiTab: adresse du tableau.
//
// Procedure appelees: ucValideTrame()
//
// Exemple d'appel:vTransCaratere('A')
//*****************************************************************************
char *CLCommunic :: ucpLireTrame(void)
{
char *ucptrLectAEnvoyer;           // Pointeur sur la trame recue.
ucEtatTrame = INCOMPLET;           // Reinitialise l'etat de la trame.

if(ucValideTrame() == VRAI)        // Verifie si la trame est valide.
  {                                // Si elle l'est
   ucptrLectAEnvoyer = cptrLecture;// transmet l'adresse du debut de la trame.
  }
else                               // Sinon
  {
   ucptrLectAEnvoyer = NULL;       // Ne transmet pas l'adresse du debut de
  }                                // la trame.
return(ucptrLectAEnvoyer);         // Retourne l'adresse du tableau ou NULL.
}
//*****************************************************************************
// Nom de la fct:   vInitBaudRate                  Fait par: Philippe Dubois
// Date:            2 octobre 2013         version base
//                  10 avril 2014          version avec uPSD.
// Revision :       B
// Modification :
// INCLUDE:         #include "_TypeCible.h", "CLCommunic.h"
// Prototype:       void vInitBaudRate(UI uiBaud);
//
// Description:     Fonction qui permet d' initialiser le port s�rie au
//                  baudrate desire, le timer 1(8 bit auto reload) et
//                  les interuptions necessaire pour communiquer avec
//                  le port serie.
//                  Ajout de la compilation conditionnelle pour choix
//                  de la valeur a mettre dans TH1 selon la cible.
//
// Parametre d'entree: UI uiBaud: pour determine la vitesse du baudrate.
//
//
// Parametre de sortie: aucune
//
// Procedure appelees: aucune.
//
// Exemple d'appel: vInitBaudRate(57600);
//*****************************************************************************
void CLCommunic:: vInitBaudRate(UI uiBaud)
{
SCON0 = 0x50;         // SM0_0=0
                      // SM1_0=1
                      // SM2_0=0 pour longeur 10 bits et asychrone.
                      // REN_0=1 pour recevoir des caracteres.
TMOD = TMOD | 0x20;   // M1=1
                      // M0=0 pour timer 8bit avec autoreload.
PCON = PCON | 0x80;   // Pour doubler le baudrate (SMOD_0=1;).

#ifdef DALLAS89C450   // Si la cible est le Dallas

switch(uiBaud)         // switch case pour determiner la valeur en
  {                    // hexa qui faut mettre a TH1 pour avoir la
                   // bonne vitesse du timer pour generer
   case 57600:         // le baudrate.
      TH1= 0xFF;
   break;
   case 38400:
      TH1= 0xFE;
   break;
   case 19200:
      TH1= 0xFD;
   break;
   case 9600:
      TH1= 0xFA;
   break;
   case 4800:
      TH1= 0xF4;
   break;
   case 2400:
      TH1= 0xE8;
   break;
   default:
      TH1= 0xFA;        // Si aucune valeur ne correspond vitesse = 9600 .
   break;
  }
#endif

#ifdef UPSD3254A        // Si la cible est le uPSD

switch(uiBaud)         // switch case pour determiner la valeur en
  {                    // hexa qui faut mettre a TH1 pour avoir la
                  // bonne vitesse du timer pour generer
    /*case 57600:      // le baudrate.
    TH1= 0xFE ;
    break;
    case 38400:        // uPSD ne peut aller a ces vitesses
    TH1= 0xFD;
    break;
    case 19200:
    TH1= 0xF9;
    break;*/
    case 9600:
       TH1= 0xF3;
    break;
    case 4800:
       TH1= 0xE6;
    break;
    case 2400:
       TH1= 0xCC;
    break;
    default:
       TH1= 0xF3;         // Si aucune valeur ne correspond vitesse = 9600 .
    break;
  }
#endif

TR1  = 1;      // Active le timer 1.
ET1  = 0;      // Desactive les interruptions du timer 1.
EA   = 1;      // Active les interruptions.
ES   = 1;      // Active les interruptions du port serie.
TI_0 = 0;      // Met a 0 le drapeau de la transmision serie.
}

//*****************************************************************************
// Nom de la fct:   vInteruptSerial                  Fait par: Philippe Dubois
// Date:            2 octobre 2013
//
// Revision :       B
// Modification :   10 avril 2014     conversion pour IAR
//
// INCLUDE:         #include "_TypeCible.h", "CLCommunic.h"
// Prototype:       __interrupt  void CLCommunic:: vInteruptSerial(void);
//
// Description:     Fonction qui permet de recevoir des caracteres par le port
//                  serie, si l'interruption vient de la reception on place
//                  les caracteres lus dans un tableau.
//
// Parametre d'entree: aucun.
//
//
// Parametre de sortie: valeur dans cptrLecture pour lire les caractere recus.
//
// Procedure appelees: ucLireNbCaractRecu(),
//
// Exemple d'appel: aucun
//*****************************************************************************
#pragma vector=0x23  // Interrupt 4 pour interruption serie au vecteur 23
 __interrupt  void CLCommunic:: vInteruptSerial(void)
{
EA = 0;                               // Desactive les interruptions.

if(RI_0==1)                           // Interruption cause par la reception?
  {
   if(cptrEcriture > cpFinTrame)      // Si on a atteind la fin du buffer
     {
      cptrEcriture = cpDebutTrame;    // Retourne au debut du tampon.
     }

  *cptrEcriture    = SBUF0;  // Lit dans SBUF0 le caractere recu et met dans le tableau.
   ucCaractereRecu = SBUF0;
   ucEtatReception = ACTIF;
   cptrEcriture++;           // Increment la position du pointeur d'ecriture.

   if(ucLireNbCaractRecu() < (ucLongueurTrame - 1) )
     {                       // Si le nombre de caractere recu est inferieur a
      ucNbCaractRecu++;      // trame - 1 incremente le nombre de caracteres
     }                       // recus.
   else                      // Si la trame est complete?
     {
      ucNbCaractRecu=0;      // Remet a 0 le compte de caractere.
      ucEtatTrame = COMPLET; // Indique qu'une trame est complete.
      cptrLecture = (cptrEcriture - (ucLongueurTrame));
                             // Le pointeur de lecture = la position
                             // d'ecriture - la longuer de la trame.
     }
   RI_0 = 0;                 // Reinitialiser le flag de reception.
 }                           // Fin du if(RI_0 = 1)
EA = 1;                      // Reactive les interruptions
}                            // Fin de Interruption.

//*****************************************************************************
// Nom de la fct:   vTransChiffre
// Description:     Fonction qui permet transmettre  un nombre de 0 a
//                  65000 sur le port serie.
// INCLUDE:       #include "_TypeCible.h", "CLCommunic.h"
// Prototype:     void vTransChiffre(UI uiChiffreAAfficher);
//
//
// Parametre d'entree: uiChiffreAAfficher pour chiffre a afficher
//
// Parametre de sortie: aucun
//
// Procedure appelees: vTransCaratere();
//
//
// Exemple d'appel: vLcdAffChiffre(12345)
//
// Fait par: Philippe Dubois
// Date:            14 novembre 2013
// Revision :       A
// Modification :
//*****************************************************************************
void CLCommunic :: vTransChiffre(UI uiChiffreAAfficher)
{
UC ucChiffre0; // Declaration des variables
UC ucChiffre1;
UC ucChiffre2;
UC ucChiffre3;
UC ucChiffre4; // isole chaque chiffre du nombre.

ucChiffre0 = ((uiChiffreAAfficher  % 10)    + 0x30);       // Unitee.
ucChiffre1 = (((uiChiffreAAfficher / 10)    % 10) + 0x30); // Dizaine
ucChiffre2 = (((uiChiffreAAfficher / 100)   % 10) + 0x30); // Centaine.
ucChiffre3 = (((uiChiffreAAfficher / 1000)  % 10) + 0x30); // Millier.
ucChiffre4 = ((uiChiffreAAfficher  / 10000) + 0x30);       // Dizaine de mille.

if(ucChiffre4 != 0x30)                          // Si Dizaine de mille  = 0
  {                                           // Ne l'affiche pas
   vTransCaratere(ucChiffre4);                  // Transmet les Dizaine de mille.
  }

if((ucChiffre4 != 0x30) || (ucChiffre3 != 0x30))// Si les 2 premiers chiffres
  {                                             // sont different de 0.
   vTransCaratere(ucChiffre3);                  // Transmet les millier.
  }

if((ucChiffre4 != 0x30) || (ucChiffre3 != 0x30)||(ucChiffre2 != 0x30))
  {                                  // Si les 3 1er chiffres sont different
                                       // de 0?
   vTransCaratere(ucChiffre2);         // Transmet les centaines.
  }

if((ucChiffre4 != 0x30)||(ucChiffre3 != 0x30)||(ucChiffre2 != 0x30)||(ucChiffre1 != 0x30))
                                  // Si les 4 premier chiffres sont
  {                                    // different de 0.
   vTransCaratere(ucChiffre1);         // Transmet les dizianes.
  }
 vTransCaratere(ucChiffre0);           // Transmetles unitees.
}

UC CLCommunic :: ucLireTrameSansCheck(void)
{
ucEtatReception = INACTIF;
return(ucCaractereRecu);
}

UC CLCommunic :: ucLireEtatReception(void)
{
return(ucEtatReception);            // Retourne l'etat de la trame.
}


//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX






// **************************CLEcran.cpp
// Auteur:      Vincent Chouinard
// Date:        13 fevrier 2014
// Version :    1.0
//
// vLcdAffCar      ---> Affiche un caracter (a-z,A-Z0-9)
// vLcdClr         ---> Efface l'ecran
// vLcdPoscurC0L1  ---> Positionne le curseur
// vLcdInit        ---> Initialise l'ecran
// vDelaisEcran    ---> Delais a tout faire
// vLcdAffChaine   ---> Affiche un string de "Texte"
// vLcdAffEcran    ---> Pour afficher des menus
// vLcdAffCarHex   ---> Pour afficher un caracter en HEX
// vLcdCarGen      ---> Pour creer des caracteres customs
// vHexToAscii2    ---> Pour transformer l'ASCII en HEX
// vLcdBusy        ---> Busy Polling
//
// Compilateur: IAR 8.2 && Keil 4.79.9
//
// Description: Fichier de definitions pour utiliser un ecran LCD
//
// *****************************************************************************
#include "CLEcran.h"
// *****************************************************************************
//                            LES CONSTRUCTEURS
// *****************************************************************************
CLEcran :: CLEcran(void)
{
uiAdresseEcran = 0xF800;
vLCDInit();
}

CLEcran :: CLEcran(USI uiAdresse)
{
uiAdresseEcran = uiAdresse;
vLCDInit();
}

// *****************************************************************************
//                            LE DESTRUCTEUR
// *****************************************************************************
CLEcran :: ~CLEcran(void)
{
vLCDClr();
}

// **********************FONCTION: NomDeLaFonction()**************************
//
// DESCRIPTION: Positionne le curseur d'ecriture a l'endroit sp�cifie par
//              la fonction appelante
//
// INCLUDE: <_DeclarationGenerale.h>
//          "CLEcran.h"
//
// PROTOTYPE:           void vLcdPoscurC0L1(UC,UC)
//
// PROCEDURE D'APPEL:   vLcdPoscurC0L1(ucCol,ucLigne)
//
// PARAMETRE D'ENTREE:  ucCol   ---> Positionne la colone
//                      ucLigne ---> Positionne la ligne
//
// PARAMETRE DE SORTIE: AUCUN
//
// EXEMPLE: vLcdPoscurC0L1(0,1) ---> Met le curseur au debut de l'ecran
//
// Auteur:              Vincent Chouinard
// Date:                22 mars 2014   (Version 1.0)
// Modification:
// *****************************************************************************
void CLEcran :: vDelaiLCD(USI uiDelai)
{
USI i;
for(i = 0;i <= uiDelai; i++);
}

void CLEcran :: vLCDBusy(void)
{
while(ucIn(uiAdresseEcran + ECRANFLAG) & 0x80);
}

void CLEcran :: vLCDClr(void)
{
vLCDBusy();
vOut(uiAdresseEcran + ECRANCONFIG, 0x01);
}

void CLEcran :: vLCDInit(void)
{
USI i;
for(i = 0; i <= 3; i++)    //Faire 3 fois
  {
   vDelaiLCD(10000);                  //Attendre la stabilisation des parametres
   vOut(uiAdresseEcran + ECRANCONFIG,0x38);
  }

vLCDBusy();vOut(uiAdresseEcran + ECRANCONFIG,0x38); // Attente du Busy Flag
vLCDBusy();vOut(uiAdresseEcran + ECRANCONFIG,0x01); // Attente du Busy Flag
vLCDBusy();vOut(uiAdresseEcran + ECRANCONFIG,0x0C); // Attente du Busy Flag
vLCDBusy();vOut(uiAdresseEcran + ECRANCONFIG,0x06); // Attente du Busy Flag
}

// **********************FONCTION: NomDeLaFonction()**************************
//
// DESCRIPTION: Positionne le curseur d'ecriture a l'endroit sp�cifie par
//              la fonction appelante
//
// INCLUDE: <_DeclarationGenerale.h>
//          "CLEcran.h"
//
// PROTOTYPE:           void vLcdPoscurC0L1(UC,UC)
//
// PROCEDURE D'APPEL:   vLcdPoscurC0L1(ucCol,ucLigne)
//
// PARAMETRE D'ENTREE:  ucCol   ---> Positionne la colone
//                      ucLigne ---> Positionne la ligne
//
// PARAMETRE DE SORTIE: AUCUN
//
// EXEMPLE: vLcdPoscurC0L1(0,1) ---> Met le curseur au debut de l'ecran
//
// Auteur:              Vincent Chouinard
// Date:                22 mars 2014   (Version 1.0)
// Modification:
// *****************************************************************************
void CLEcran :: vLCDCursor(UC ucCol, UC ucLine)
{
UC ucPosition;
switch(ucLine)
  {
   case 1:                       //Si ligne 1 choisi
      ucPosition = 0x00 + ucCol; //Curseur sur ligne 1 (1,Y)
   break;

   case 2:                       //Si ligne 2 choisi
      ucPosition = 0x40 + ucCol; //Curseur sur ligne 2 (2,Y)
   break;

   case 3:                       //Si ligne 3 choisi
      ucPosition = 0x14 + ucCol; //Curseur sur ligne 3 (3,Y)
   break;

   case 4:                       //Si ligne 4 choisi
      ucPosition = 0x54 + ucCol; //Curseur sur ligne 4 (4,Y)
   break;

   default:                      //Sinon
      ucPosition = 0x00 + ucCol; //Curseur � position initial (0,0)
   break;
  }

ucPosition = ucPosition | 0x80; //Definition du registre du curseur
vLCDBusy();                                   //Attente du Flag Busy
vOut(uiAdresseEcran+ECRANCONFIG, ucPosition); //Envoi de la commande
}

void CLEcran :: vLCDDisplayCarac(UC ucCaractere)
{
vLCDBusy();
vOut(uiAdresseEcran+ECRANWR, ucCaractere);
}

void CLEcran :: vLCDDisplayCarac(char cCaractere)
{
vLCDBusy();
vOut(uiAdresseEcran+ECRANWR, cCaractere);
}

void CLEcran :: vHexToASCII(UC ucHexCar, UC *ucpHi, UC *ucpLo)
{
UC ucTemp;
ucTemp = ucHexCar;
*ucpHi = ucTemp   >> 4;
*ucpLo = ucHexCar & 0x0F;

if(*ucpHi <= 9)             //SI MSB est chiffe
  {
   *ucpHi = *ucpHi + 0x30;  //Convertion hexa a ASCII (Chiffre)
  }
else                        //SINON
  {
   *ucpHi = *ucpHi + 0x37;  //Convertion hexa a ASCII (Lettre)
  }

if(*ucpLo <= 9)             //SI LSB est chiffre
  {
   *ucpLo = *ucpLo + 0x30;  //Convertion hexa a ASCII (Chiffre)
  }
else                        //SINON
  {
   *ucpLo = *ucpLo + 0x37;  //Convertion hexa a ASCII (Lettre)
  }
}

void CLEcran :: vHexToASCII(USI uiHexCar, UC *ucpHiOctHi, UC *ucpLoOctHi,
                                          UC *ucpHiOctLo, UC *ucpLoOctLo)
{
*ucpHiOctHi = (uiHexCar >> 12) & 0x0F;
*ucpLoOctHi = (uiHexCar >> 8 ) & 0x0F;
*ucpHiOctLo = (uiHexCar >> 4 ) & 0x0F;
*ucpLoOctLo =  uiHexCar        & 0x0F;

if(*ucpHiOctHi <= 9)                  //SI MSB est chiffe
  {
   *ucpHiOctHi = *ucpHiOctHi + 0x30;  //Convertion hexa a ASCII (Chiffre)
  }
else                                  //SINON
  {
   *ucpHiOctHi = *ucpHiOctHi + 0x37;  //Convertion hexa a ASCII (Lettre)
  }

if(*ucpLoOctHi <= 9)                  //SI LSB est chiffre
  {
   *ucpLoOctHi = *ucpLoOctHi + 0x30;  //Convertion hexa a ASCII (Chiffre)
  }
else                                  //SINON
  {
   *ucpLoOctHi = *ucpLoOctHi + 0x37;  //Convertion hexa a ASCII (Lettre)
  }

if(*ucpHiOctLo <= 9 )                 //SI MSB est chiffre
  {
   *ucpHiOctLo = *ucpHiOctLo + 0x30;  //Convertion hexa a ASCII (Chiffre)
  }
else                                  //SINON
  {
   *ucpHiOctLo = *ucpHiOctLo + 0x37;  //Convertion hexa a ASCII (Lettre)
  }

if(*ucpLoOctLo <= 9 )                 //SI LSB est chiffre
  {
   *ucpLoOctLo = *ucpLoOctLo + 0x30;  //Convertion hexa a ASCII (Chiffre)
  }
else                                  //SINON
  {
   *ucpLoOctLo = *ucpLoOctLo + 0x37;  //Convertion hexa a ASCII (Lettre)
  }
}

void CLEcran :: vLCDDisplayHexCarac(UC ucHexCar)
 {
  UC ucHi;UC ucLo;

  vHexToASCII(ucHexCar, &ucHi, &ucLo); //Conversion de Hexadecimal a ASCII
  vLCDDisplayCarac(ucHi);              //Affiche MSB
  vLCDDisplayCarac(ucLo);              //Affiche LSB
 }

void CLEcran :: vLCDDisplayHexCarac(USI uiHexCar)
{
UC ucHiOctHi;
UC ucLoOctHi;
UC ucHiOctLo;
UC ucLoOctLo;

vHexToASCII(uiHexCar, &ucHiOctHi, &ucLoOctHi, &ucHiOctLo, &ucLoOctLo);

vLCDDisplayCarac(ucHiOctHi); //Affiche MSB OctHI
vLCDDisplayCarac(ucLoOctHi); //Affiche LSB OctHI
vLCDDisplayCarac(ucHiOctLo); //Affiche MSB OctLO
vLCDDisplayCarac(ucLoOctLo); //Affiche LSB OctLO
}

void CLEcran :: vLCDDisplayCaracChain(const UC *ucpMessage)
{
while(*ucpMessage != 0x00)
  {
   vLCDDisplayCarac(*ucpMessage);
   ucpMessage++;
  }
}

void CLEcran ::vLCDDisplayCaracChain (const char *cpMessage)
{
while(*cpMessage != 0x00)
  {
   vLCDDisplayCarac(*cpMessage);
   cpMessage++;
  }
}

void CLEcran :: vLCDDisplayScreen(const UC *ucpEcran)
{
UC ucLigne;
for(ucLigne = 1; ucLigne <= 4; ucLigne++)
  {
   vLCDCursor(1,ucLigne);
   vLCDDisplayCaracChain(ucpEcran);
   ucpEcran = ucpEcran + 1;
  }
}

void CLEcran :: vLCDDisplayEtatPort(UC ucEtatPort)
{
for(UC i = 0; i < 8; i++)
  {
   if((ucEtatPort & 0x80) == 0x80)
     {
      vLCDDisplayCarac('1');
     }
   else
     {
      vLCDDisplayCarac('0');
     }
   ucEtatPort = ucEtatPort << 1;
  }
}

void CLEcran :: vLCDDisplayFloat(float fInputFloat)
{
int i                 = 0; // Pour les boucles de comptage
float fTemporaire     = 0; // Pour le calcul de decimales
USI usiLesEntiers     = 0; // Pour la conversion d'un float en entier
USI usiLesEntiersTemp = 0; // Pour la conversion d'un float en entier
USI usiDecimalesTemp  = 0; // Pour convertir les decimales d'un float en entier
USI usiLesDecimales   = 0; // Pour convertir les decimales d'un float en entier

usiLesEntiers   = (USI)fInputFloat; // Conversion des floats en USI sans virgule
usiLesDecimales = (USI)fInputFloat; // Enleve les decimales du float
fTemporaire     = (fInputFloat - (float)usiLesDecimales) * 100;//Decimales 0-999
usiLesDecimales = (USI)fTemporaire; //Conversion (.0 a .999) vers (0 a 999)

for(i = 0; i < 3; i++) //Pour trois fois (Centaine, dizaine, unite)
  {
   if(i == 0) // Pour les centaines
     {
      usiLesEntiersTemp = usiLesEntiers /  100;
      usiLesEntiers     = usiLesEntiers - (100 * usiLesEntiersTemp);
     }
   if(i == 1) // Pour les dizaines
     {
      usiLesEntiersTemp = usiLesEntiers /  10;
      usiLesEntiers     = usiLesEntiers - (10 * usiLesEntiersTemp);
     }
   if(i == 2) // Pour les unitees
     {
      usiLesEntiersTemp=usiLesEntiers;
     }

   switch(usiLesEntiersTemp) // Affiche un caractere correspondant a l'unite
     {                       // float lue
      case 0:
         vLCDDisplayCarac('0');
      break;

      case 1:
         vLCDDisplayCarac('1');
      break;

      case 2:
         vLCDDisplayCarac('2');
      break;

      case 3:
         vLCDDisplayCarac('3');
      break;

      case 4:
         vLCDDisplayCarac('4');
      break;

      case 5:
         vLCDDisplayCarac('5');
      break;

      case 6:
         vLCDDisplayCarac('6');
      break;

      case 7:
         vLCDDisplayCarac('7');
      break;

      case 8:
         vLCDDisplayCarac('8');
      break;

      case 9:
         vLCDDisplayCarac('9');
      break;
     }
   }

vLCDDisplayCarac('.'); // Affiche la satane virgule

for(i = 0; i < 2; i++) //Pour deux fois (Dixieme, centieme)
  {
   if(i == 0)          // Pour les dixiemes
     {
      usiDecimalesTemp = usiLesDecimales /  10;
     }
   if(i == 1)          // Pour les centiemes
     {
      usiDecimalesTemp = usiLesDecimales - (10 * usiDecimalesTemp) ;
     }

   switch(usiDecimalesTemp) // Affiche un caractere correspondant a l'unite
     {                      // float lue
      case 0:
         vLCDDisplayCarac('0');
      break;

      case 1:
         vLCDDisplayCarac('1');
      break;

      case 2:
         vLCDDisplayCarac('2');
      break;

      case 3:
         vLCDDisplayCarac('3');
      break;

      case 4:
         vLCDDisplayCarac('4');
      break;

      case 5:
         vLCDDisplayCarac('5');
      break;

      case 6:
         vLCDDisplayCarac('6');
      break;

      case 7:
         vLCDDisplayCarac('7');
      break;

      case 8:
         vLCDDisplayCarac('8');
      break;

      case 9:
         vLCDDisplayCarac('9');
      break;
     }
  }
}
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
// ************************** FICHIER: CLInOutBase.CPP  ************************
// *****************************************************************************
#include "CLInOutBase.h"

void CLInOutBase :: vOutPort(USI uiAdresse, UC ucData)
{
UC xdata *ucpPointeur;         //Initialisation pointeur sur memoire externe

ucpPointeur  = (UC xdata *) uiAdresse;// Adressage de la case memoire
*ucpPointeur = ucData;                // Ecriture de bits sur le bus de donnees
}

UC CLInOutBase :: ucInPort(USI uiAdresse)
{
UC xdata *ucpPointeur;         //Initialisation pointeur sur memoire externe
UC ucData   = 0;               //Initialisation d'une variable de reception
ucpPointeur = (UC xdata *)uiAdresse; //Adressage de la case memoire
ucData      = *ucpPointeur;          //Lecture de bits sur le bus de donnees
return ucData;
}

void CLInOutBase :: vOut(USI uiAdresse, UC ucData)
{
vOutPort(uiAdresse, ucData);
}

void CLInOutBase :: vOut(USI uiAdresse, USI uiDonnee, UC ucTypeTransfert)
{
union UNEntierOctet unData;
unData.uiEntier = uiDonnee;

if(ucTypeTransfert == SAMELSB)
  {
   vOutPort(uiAdresse, unData.stDoubleOctet.ucOctet1);
   vOutPort(uiAdresse, unData.stDoubleOctet.ucOctet1);
  }

if(ucTypeTransfert == SAMEMSB)
  {
   vOutPort(uiAdresse, unData.stDoubleOctet.ucOctet2);
   vOutPort(uiAdresse, unData.stDoubleOctet.ucOctet2);
  }

if(ucTypeTransfert == SUITELSB)
  {
   vOutPort(uiAdresse, unData.stDoubleOctet.ucOctet1);
   vOutPort(uiAdresse, unData.stDoubleOctet.ucOctet2);
  }

if(ucTypeTransfert == SUITEMSB)
  {
   vOutPort(uiAdresse, unData.stDoubleOctet.ucOctet2);
   vOutPort(uiAdresse, unData.stDoubleOctet.ucOctet1);
  }
}

UC CLInOutBase :: ucIn(USI uiAdresse)
{
UC ucData = 0;                 //Initialisation d'une variable de reception
ucData    = ucInPort(uiAdresse);
return ucData;
}

UC CLInOutBase :: ucIn(USI uiAdresse, UC ucTypeTransfert)
{
union UNEntierOctet unData;
unData.uiEntier = 0x00;

unData.stDoubleOctet.ucOctet1 = 0x00;
unData.stDoubleOctet.ucOctet2 = 0x00;

if(ucTypeTransfert == SAMELSB)
  {
   unData.stDoubleOctet.ucOctet1 = ucInPort(uiAdresse);
   unData.stDoubleOctet.ucOctet1 = ucInPort(uiAdresse);
  }

if(ucTypeTransfert == SAMEMSB)
  {
   unData.stDoubleOctet.ucOctet2 = ucInPort(uiAdresse);
   unData.stDoubleOctet.ucOctet2 = ucInPort(uiAdresse);
  }

if(ucTypeTransfert == SUITELSB)
   {
    unData.stDoubleOctet.ucOctet1 = ucInPort(uiAdresse);
    unData.stDoubleOctet.ucOctet2 = ucInPort(uiAdresse);
   }

if(ucTypeTransfert == SUITEMSB)
  {
   unData.stDoubleOctet.ucOctet2 = ucInPort(uiAdresse);
   unData.stDoubleOctet.ucOctet1 = ucInPort(uiAdresse);
  }
return unData.uiEntier;
}
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX

// **************************Main.c
// Auteur:      Vincent Chouinard
// Date:        5 aout Janvier 2014
// Version :    1.0
//
// Compilateur: Keil 4.72.9 && IAR 8.10
//
// Description: Fichier principal
//
// *****************************************************************************
// **** LES INCLUDES ****************//
#include "_DeclarationGenerale.h"    // Raccourcis Linguistiques utiles
#include "ConversionKeilToIAR.h"     //
#include "CLClavier.h"               // Pour utiliser le clavier
#include "CLEcran.h"                 // Pour utiliser l'�cran
#include "NomDuProjet.h"             //
#include "CLCommunic.h"              // Pour utiliser le port s�rie
// **** LES FONCTIONS DU MAIN *******//
void vRecuFromKeyBoard(void);
void vRecuFromRS232   (void);
// **** CLASS DECLARATION ***********//
class CLEcran    clEcran(0xF800);
class CLClavier  Clavier;
class CLCommunic clCommunic;
// **** PROGRAMME PRINCIPAL *********//
void main(void)
{
EA    = 0;     // Disable interrupt.
WDKEY = 0x55;  // Disable WatchDog.
EA    = 1;

while(1)
  {
   if(Clavier.ucBoutonAppuye() == ACTIF)
     {
      vRecuFromKeyBoard();
      clEcran.vLCDCursor(0,1);
      clEcran.vLCDDisplayCarac(Clavier.ucLireClavier());
      clCommunic.vTransCaratere(Clavier.ucLireClavier());
     }

   if(clCommunic.ucLireEtatReception() == ACTIF)
     {
      vRecuFromRS232();
      clEcran.vLCDCursor(0,2);
      clEcran.vLCDDisplayCarac(clCommunic.ucLireTrameSansCheck());
     }
  }
}


void vRecuFromKeyBoard(void)
{
clEcran.vLCDCursor(3,1);
clEcran.vLCDDisplayCarac('R');
clEcran.vLCDDisplayCarac('e');
clEcran.vLCDDisplayCarac('c');
clEcran.vLCDDisplayCarac('u');
clEcran.vLCDDisplayCarac(' ');
clEcran.vLCDDisplayCarac('K');
clEcran.vLCDDisplayCarac('e');
clEcran.vLCDDisplayCarac('y');
clEcran.vLCDDisplayCarac('b');
clEcran.vLCDDisplayCarac('o');
clEcran.vLCDDisplayCarac('a');
clEcran.vLCDDisplayCarac('r');
clEcran.vLCDDisplayCarac('d');
}

void vRecuFromRS232(void)
{
clEcran.vLCDCursor(3,2);
clEcran.vLCDDisplayCarac('R');
clEcran.vLCDDisplayCarac('e');
clEcran.vLCDDisplayCarac('c');
clEcran.vLCDDisplayCarac('u');
clEcran.vLCDDisplayCarac(' ');
clEcran.vLCDDisplayCarac('R');
clEcran.vLCDDisplayCarac('S');
clEcran.vLCDDisplayCarac('2');
clEcran.vLCDDisplayCarac('3');
clEcran.vLCDDisplayCarac('2');
}

//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
// **************************Clavier.h
// Auteur:       Vincent Chouinard
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

#include "_DeclarationGenerale.h" // Raccourcis de programmation & variables
#include "CLInOutBase.h"          // Fichier de definitions pour faire des I/O

#ifndef CLAVIERH
  #define CLAVIERH

  #define CS1 0xF900     // Chip Select 1 du uPSD sur 0xF900

class CLClavier : public CLInOutBase
{
public:
   CLClavier(void);                    // Constructeur par defaut.
  ~CLClavier(void);                    // Desctructeur.

   UC ucLireClavier(void);
   UC ucBoutonAppuye(void);            // Fonction de logique de selection du bouton pese

protected:
   UC        ucToucheClavier;
   static UC ucEtatClavier;

private:
   __interrupt static void vKeyboardInterrupt(void);
};
#endif
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
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

#define LONGUEURTRAME  4          // Longueur trame par defaut.
#define LONGUEURTAMPON 12         // Longueur tampon par defaut.
#define TRAMECOMPLET   1          // Pour l'etat de la trame.
#define TRAMEINCOMPLET 0          // Pour l'etat de la trame.

class CLCommunic            // Classe CLCommunic
{
public:                     // Menbres publics.
   CLCommunic(void);                                    // Constructeur par defaut.
   CLCommunic(UC ucLongBuf, UC ucLongTrame, UI uiBaud); // Constructeur initialisateur
  ~CLCommunic(void);                                   // Destructeur

UC    ucLireEtatReception(void);
UC    ucLireTrameSansCheck(void);
UC    ucInitLongTrame(UC ucLong);           // Intialiser la longueur trame.
UC    static ucLireNbCaractRecu(void);      // Lire le nombre de caractere recu
UC    ucLireEtatTrame(void);                // Lire l'etat de la trame.
char *ucpLireTrame(void);                   // Retourne ladresse du tableau.
void  vTransCaratere(UC ucCar);             // Transmettre un caractere.
void  vTransChiffre(UI uiChiffreAAfficher); // Transmettre un chiffre sur le port serie
void  vAffChaine(char const *ucpMessage);   // Transmettre une chaine de caractereS

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
















// ************************** FICHIER: CLEcran.H  ******************************

// DESCRIPTION DES FONCTIONS
//
// CLEcran(void);
// CLEcran(USI uiAdresse);
// ~CLEcran(void);
//
// void vLCDClr(void);
// void vLCDInit(void);
// void vLCDCursor(UC ucCol, UC ucLine);
//
// void vLCDDisplayCarac(UC ucCaractere);
// void vLCDDisplayCarac(char cCaractere);
//
// void vLCDDisplayCaracChain(const UC *ucpMessage);
// void vLCDDisplayCaracChain(const char *cpMessage);
//
// void vHexToASCII(UC ucHexCar, UC *ucpHi, UC *ucpLo);
// void vLCDDisplayHexCarac(UC ucHexCar);
//
// void vLCDDisplayScreen(const UC *ucpEcran);
// void vLCDBusy(void);
// void vDelaiLCD(USI uiDelai);
//
// *****************************************************************************
#include "_DeclarationGenerale.h"
#include "CLInOutBase.h"

#ifndef CLECRANH
   #define CLECRANH

#define ECRANCONFIG 0
#define ECRANFLAG   1
#define ECRANWR     2
#define ECRANRD     3

class CLEcran : public CLInOutBase
{
public:
   CLEcran(void);
   CLEcran(USI uiAdresse);
  ~CLEcran(void);

   void vLCDClr              (void);
   void vLCDInit             (void);
   void vLCDCursor           (UC   ucCol, UC ucLine);
   void vLCDDisplayCarac     (UC   ucCaractere);
   void vLCDDisplayCarac     (char cCaractere);

   void vHexToASCII          (UC   ucHexCar,   UC *ucpHi,      UC *ucpLo);
   void vHexToASCII          (USI  uiHexCar,   UC *ucpHiOctHi, UC *ucpLoOctHi,
                              UC  *ucpHiOctLo, UC *ucpLoOctLo);

   void vLCDDisplayHexCarac  (UC          ucHexCar);
   void vLCDDisplayHexCarac  (USI         uiHexCar);
   void vLCDDisplayCaracChain(const UC   *ucpMessage);
   void vLCDDisplayCaracChain(const char *cpMessage);
   void vLCDDisplayScreen    (const UC   *ucpEcran);
   void vLCDDisplayEtatPort  (UC          ucEtatPort);
   void vLCDDisplayFloat     (float       fInputFloat);

protected:

private:
   USI  uiAdresseEcran;
   void vLCDBusy (void);
   void vDelaiLCD(USI uiDelai);
};
#endif
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
// ************************** FICHIER: CLInOutBase.H  **************************
// Auteur:       Vincent Chouinard
// Date:         1 mai 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.1
//
// Description:  Fichier de definitions pour utiliser le clavier du uPSD
// *****************************************************************************
#include "_DeclarationGenerale.h"

#ifndef CLINOUTBASEH
   #define CLINOUTBASEH

#define SAMELSB  1
#define SAMEMSB  2
#define SUITELSB 3
#define SUITEMSB 4

class CLInOutBase
{
public:

protected:
   void vOut(USI uiAdresse, UC ucData);
   void vOut(USI uiAdresse, USI uiDonnee, UC ucTypeTransfert);

   UC   ucIn(USI uiAdresse);
   UC   ucIn(USI uiAdresse, UC ucTypeTransfert);

private:
   UC   ucInPort(USI uiAdresse);
   void vOutPort(USI uiAdresse, UC ucData);
};
#endif
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX

// ************************** FICHIER: ConversionKeilToIAR.h *******************
//
// Auteur:       Vincent Chouinard
// Date:         1 mai 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.1 et Keil 4.0
//
// Description: Conversion des SFR entre Keil 4.0 et IAR 8.1
// *****************************************************************************

#include "TypeCible.h"

#ifndef CONVERSIONKEILTOIARH
   #define CONVERSIONKEILTOIARH

// *****************************************************************************
// DEFINITION DES  MODELES DE MEMOIRE
// *****************************************************************************

#define data  __data
#define xdata __xdata
#define code  __code


// *****************************************************************************
#ifdef DALLAS89C450

// Interruption activation
  #define EA            IE_bit.EA
  #define ES0           IE_bit.ES0
  #define ES2           IE_bit.ES1
  #define ET1           IE_bit.ET1
  #define EX0           IE_bit.EX0

// Interruption priorite
  #define LPX0          IP0_bit.LPX0
  #define MPX0          IP1_bit.MPX0

  #define LPS           IP0_bit.LPS0
  #define MPS           IP1_bit.MPS0
  #define LPS2          IP0_bit.LPS1
  #define MPS2          IP1_bit.MPS1

// Interruption niveau activite.
  #define IT0           TCON_bit.IT0
  #define TR1           TCON_bit.TR1

  #define TCLK2         T2CON_bit.TCKL
  #define TRCLK2        T2CON_bit.RCLK
  #define TR2           T2CON_bit.TR2

  #define T2MOD_DCEN    T2MOD_bit.DCEN

  #define SMOD          PCON_bit.SMOD_0
  #define SMOD2         WDCON_bit.SMOD_1

  #define SCON          SCON0
  #define SBUF          SBUF0
  #define RI_0          SCON0_bit.RI_0
  #define TI_0          SCON0_bit.TI_0

  #define SCON2         SCON1
  #define SBUF2         SBUF1
  #define RI_2          SCON1_bit.RI_1
  #define TI_2          SCON1_bit.TI_1

  #define SM0_0         SCON0_bit.SM0_FE_0
  #define SM1_0         SCON0_bit.SM1_0
  #define SM2_0         SCON0_bit.SM2_0
  #define REN_0         SCON0_bit.REN_0

  #define SM0_2         SCON1_bit.SM0_FE_1
  #define SM1_2         SCON1_bit.SM1_1
  #define SM2_2         SCON1_bit.SM2_1
  #define REN_2         SCON1_bit.REN_1

  #define P1_0          P1_bit.P10_T2          // Port 1.0
  #define P1_1          P1_bit.P11_T2EX        // Port 1.1
  #define P1_2          P1_bit.P12_RXD1        // Port 1.2
  #define P1_3          P1_bit.P13_TXD1        // Port 1.3
  #define P1_4          P1_bit.P14_INT2        // Port 1.4
  #define P1_5          P1_bit.P15_INT3        // Port 1.5
  #define P1_6          P1_bit.P16_INT4        // Port 1.6
  #define P1_7          P1_bit.P17_INT5        // Port 1.7

  #define P3_0          P3_bit.P30_RXD0        // Port 3.0
  #define P3_1          P3_bit.P31_TXD0        // Port 3.1
  #define P3_2          P3_bit.P32_INT0        // Port 3.2
  #define P3_3          P3_bit.P33_INT1        // Port 3.3
  #define P3_4          P3_bit.P34_T0          // Port 3.4
  #define P3_5          P3_bit.P35_T1          // Port 3.5
  #define P3_6          P3_bit.P36_WR          // Port 3.6
  #define P3_7          P3_bit.P37_RD          // Port 3.7

  #define SDA           P3_4
  #define SCL           P3_5
#endif // DALLAS89C450
// *****************************************************************************

// *****************************************************************************
#ifdef UPSD3254A
// Interruption activation
  #define EA            IE_bit.EA
  #define ES            IE_bit.ES
  #define ET1           IE_bit.ET1
  #define ES2           IEA_bit.ES2
  #define EX0           IE_bit.EX0

// Interruption priorite
  #define PX0           IP_bit.PX0
  #define PS            IP_bit.PS
  #define PS2           IPA_bit.PS2

// Interruption niveau activite.
  #define IT0           TCON_bit.IT0
  #define TR1           TCON_bit.TR1

  #define TCLK2         T2CON_bit.TCKL
  #define TRCLK2        T2CON_bit.RCLK
  #define TR2           T2CON_bit.TR2

  #define T2MOD_DCEN    T2MOD_bit.DCEN

  #define SBUF0         SBUF
  #define SCON0         SCON

 // #define ES0 IE_bit.ES
 // #define ES0 IE_bit.ES

  #define SMOD          PCON_bit.SMOD
  #define SMOD2         PCON_bit.SMOD1

  #define RI_0          SCON_bit.RI
  #define TI_0          SCON_bit.TI
  #define SM0_0         SCON_bit.SM0
  #define SM1_0         SCON_bit.SM1
  #define SM2_0         SCON_bit.SM2
  #define REN_0         SCON_bit.REN

  #define TI_2          SCON2_bit.TI
  #define RI_2          SCON2_bit.RI
  #define SM0_2         SCON2_bit.SM0
  #define SM1_2         SCON2_bit.SM1
  #define SM2_2         SCON2_bit.SM2
  #define REN_2         SCON2_bit.REN

  #define WATCHDOG_OFF WDKEY = 0x55; // Disable watchdog.

  #define P1_0          P1_bit.P10        // Port 1.0
  #define P1_1          P1_bit.P11        // Port 1.1
  #define P1_2          P1_bit.P12        // Port 1.2
  #define P1_3          P1_bit.P13        // Port 1.3
  #define P1_4          P1_bit.P14        // Port 1.4
  #define P1_5          P1_bit.P15        // Port 1.5
  #define P1_6          P1_bit.P16        // Port 1.6
  #define P1_7          P1_bit.P17        // Port 1.7

  #define P3_0          P3_bit.P30        // Port 3.0
  #define P3_1          P3_bit.P31        // Port 3.1
  #define P3_2          P3_bit.P32        // Port 3.2
  #define P3_3          P3_bit.P33        // Port 3.3
  #define P3_4          P3_bit.P34        // Port 3.4
  #define P3_5          P3_bit.P35        // Port 3.5
  #define P3_6          P3_bit.P36        // Port 3.6
  #define P3_7          P3_bit.P37        // Port 3.7

  #define P4_0          P4_bit.P40        // Port 4.0
  #define P4_1          P4_bit.P41        // Port 4.1
  #define P4_2          P4_bit.P42        // Port 4.2
  #define P4_3          P4_bit.P43        // Port 4.3
  #define P4_4          P4_bit.P44        // Port 4.4
  #define P4_5          P4_bit.P45        // Port 4.5
  #define P4_6          P4_bit.P46        // Port 4.6
  #define P4_7          P4_bit.P47        // Port 4.7

  #define SCL           P3_7
  #define SDA           P3_6





#endif // UPSD3254A
// *****************************************************************************
#endif // CONVERSIONKEILTOIARH
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX

/***************************************************************************
 *                                - ioDS89C450.h -
 *
 * Special header for the Maxim (Dallas Semiconductor) DS89C450 Microcontroller.
 *
 ***************************************************************************/

#ifndef IODS89C450_H
#define IODS89C450_H
#define __DS89C450__
#ifdef __IAR_SYSTEMS_ICC__
#ifndef _SYSTEM_BUILD
   #pragma system_include
#endif
#pragma language=extended

/*-------------------------------------------------------------------------
 *   All SFRs
 *-------------------------------------------------------------------------*/

__sfr __no_init volatile union
{
  unsigned char EIP1;
  struct
  {
    unsigned char MPX2 : 1;
    unsigned char MPX3 : 1;
    unsigned char MPX4 : 1;
    unsigned char MPX5 : 1;
    unsigned char MPWDI : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
  } EIP1_bit;
} @ 0xF1;
__sfr __no_init volatile unsigned char ACC @ 0xE0;
__sfr __no_init volatile unsigned char TL2 @ 0xCC;
__sfr __no_init volatile union
{
  unsigned char T2MOD;
  struct
  {
    unsigned char DCEN : 1;
    unsigned char T2OE : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
  } T2MOD_bit;
} @ 0xC9;
__sfr __no_init volatile union
{
  unsigned char IP0;
  struct
  {
    unsigned char LPX0 : 1;
    unsigned char LPT0 : 1;
    unsigned char LPX1 : 1;
    unsigned char LPT1 : 1;
    unsigned char LPS0 : 1;
    unsigned char LPT2 : 1;
    unsigned char LPS1 : 1;
    unsigned char  : 1;
  } IP0_bit;
} @ 0xB8;
__sfr __no_init volatile unsigned char SADDR1 @ 0xAA;
__sfr __no_init volatile union
{
  unsigned char ACON;
  struct
  {
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char PAGES0 : 1;
    unsigned char PAGES1 : 1;
    unsigned char PAGEE : 1;
  } ACON_bit;
} @ 0x9D;
__sfr __no_init volatile unsigned char SBUF0 @ 0x99;
__sfr __no_init volatile unsigned char TH0 @ 0x8C;
__sfr __no_init volatile union
{
  unsigned char TCON;
  struct
  {
    unsigned char IT0 : 1;
    unsigned char IE0 : 1;
    unsigned char IT1 : 1;
    unsigned char IE1 : 1;
    unsigned char TR0 : 1;
    unsigned char TF0 : 1;
    unsigned char TR1 : 1;
    unsigned char TF1 : 1;
  } TCON_bit;
} @ 0x88;
__sfr __no_init volatile union
{
  unsigned char PSW;
  struct
  {
    unsigned char P : 1;
    unsigned char F1 : 1;
    unsigned char OV : 1;
    unsigned char RS0 : 1;
    unsigned char RS1 : 1;
    unsigned char F0 : 1;
    unsigned char AC : 1;
    unsigned char CY : 1;
  } PSW_bit;
} @ 0xD0;
__sfr __no_init volatile unsigned char TH2 @ 0xCD;
__sfr __no_init volatile unsigned char SADEN0 @ 0xB9;
__sfr __no_init volatile union
{
  unsigned char IE;
  struct
  {
    unsigned char EX0 : 1;
    unsigned char ET0 : 1;
    unsigned char EX1 : 1;
    unsigned char ET1 : 1;
    unsigned char ES0 : 1;
    unsigned char ET2 : 1;
    unsigned char ES1 : 1;
    unsigned char EA : 1;
  } IE_bit;
} @ 0xA8;
__sfr __no_init volatile union
{
  unsigned char P1;
  struct
  {
    unsigned char P10_T2 : 1;
    unsigned char P11_T2EX : 1;
    unsigned char P12_RXD1 : 1;
    unsigned char P13_TXD1 : 1;
    unsigned char P14_INT2 : 1;
    unsigned char P15_INT3 : 1;
    unsigned char P16_INT4 : 1;
    unsigned char P17_INT5 : 1;
  } P1_bit;
} @ 0x90;
__sfr __no_init volatile unsigned char TH1 @ 0x8D;
__sfr __no_init volatile union
{
  unsigned char TMOD;
  struct
  {
    unsigned char M00 : 1;
    unsigned char M10 : 1;
    unsigned char C_T0 : 1;
    unsigned char GATE0 : 1;
    unsigned char M01 : 1;
    unsigned char M11 : 1;
    unsigned char C_T1 : 1;
    unsigned char GATE1 : 1;
  } TMOD_bit;
} @ 0x89;
__sfr __no_init volatile union
{
  unsigned char SCON1;
  struct
  {
    unsigned char RI_1 : 1;
    unsigned char TI_1 : 1;
    unsigned char RB8_1 : 1;
    unsigned char TB8_1 : 1;
    unsigned char REN_1 : 1;
    unsigned char SM2_1 : 1;
    unsigned char SM1_1 : 1;
    unsigned char SM0_FE_1 : 1;
  } SCON1_bit;
} @ 0xC0;
__sfr __no_init volatile unsigned char SADDR0 @ 0xA9;
__sfr __no_init volatile union
{
  unsigned char EXIF;
  struct
  {
    unsigned char BGS : 1;
    unsigned char RGSL : 1;
    unsigned char RGMD : 1;
    unsigned char CKRY : 1;
    unsigned char IE2 : 1;
    unsigned char IE3 : 1;
    unsigned char IE4 : 1;
    unsigned char IE5 : 1;
  } EXIF_bit;
} @ 0x91;
__sfr __no_init volatile union
{
  unsigned char CKCON;
  struct
  {
    unsigned char MD0 : 1;
    unsigned char MD1 : 1;
    unsigned char MD2 : 1;
    unsigned char T0M : 1;
    unsigned char T1M : 1;
    unsigned char T2M : 1;
    unsigned char WD0 : 1;
    unsigned char WD1 : 1;
  } CKCON_bit;
} @ 0x8E;
__sfr __no_init volatile union
{
  unsigned char P0;
  struct
  {
    unsigned char P00 : 1;
    unsigned char P01 : 1;
    unsigned char P02 : 1;
    unsigned char P03 : 1;
    unsigned char P04 : 1;
    unsigned char P05 : 1;
    unsigned char P06 : 1;
    unsigned char P07 : 1;
  } P0_bit;
} @ 0x80;
__sfr __no_init volatile unsigned char SBUF1 @ 0xC1;
__sfr __no_init volatile union
{
  unsigned char P3;
  struct
  {
    unsigned char P30_RXD0 : 1;
    unsigned char P31_TXD0 : 1;
    unsigned char P32_INT0 : 1;
    unsigned char P33_INT1 : 1;
    unsigned char P34_T0 : 1;
    unsigned char P35_T1 : 1;
    unsigned char P36_WR : 1;
    unsigned char P37_RD : 1;
  } P3_bit;
} @ 0xB0;
__sfr __no_init volatile unsigned char SP @ 0x81;
__sfr __no_init volatile union
{
  unsigned char ROMSIZE;
  struct
  {
    unsigned char RMS0 : 1;
    unsigned char RMS1 : 1;
    unsigned char RMS2 : 1;
    unsigned char PRAME : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
  } ROMSIZE_bit;
} @ 0xC2;
__sfr __no_init volatile union
{
  unsigned char IP1;
  struct
  {
    unsigned char MPX0 : 1;
    unsigned char MPT0 : 1;
    unsigned char MPX1 : 1;
    unsigned char MPT1 : 1;
    unsigned char MPS0 : 1;
    unsigned char MPT2 : 1;
    unsigned char MPS1 : 1;
    unsigned char  : 1;
  } IP1_bit;
} @ 0xB1;
__sfr __no_init volatile union
{
  unsigned char P2;
  struct
  {
    unsigned char P20 : 1;
    unsigned char P21 : 1;
    unsigned char P22 : 1;
    unsigned char P23 : 1;
    unsigned char P24 : 1;
    unsigned char P25 : 1;
    unsigned char P26 : 1;
    unsigned char P27 : 1;
  } P2_bit;
} @ 0xA0;
__sfr __no_init volatile unsigned char DPL @ 0x82;
__sfr __no_init volatile unsigned char DPH @ 0x83;
__sfr __no_init volatile union
{
  unsigned char FCNTL;
  struct
  {
    unsigned char FC0 : 1;
    unsigned char FC1 : 1;
    unsigned char FC2 : 1;
    unsigned char FC3 : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char FERR : 1;
    unsigned char FBUSY : 1;
  } FCNTL_bit;
} @ 0xD5;
__sfr __no_init volatile union
{
  unsigned char PMR;
  struct
  {
    unsigned char DME0 : 1;
    unsigned char DME1 : 1;
    unsigned char ALEON : 1;
    unsigned char _4X__2X : 1;
    unsigned char CTM : 1;
    unsigned char SWB : 1;
    unsigned char CD0 : 1;
    unsigned char CD1 : 1;
  } PMR_bit;
} @ 0xC4;
__sfr __no_init volatile unsigned char DPL1 @ 0x84;
__sfr __no_init volatile union
{
  unsigned char EIP0;
  struct
  {
    unsigned char LPX2 : 1;
    unsigned char LPX3 : 1;
    unsigned char LPX4 : 1;
    unsigned char LPX5 : 1;
    unsigned char LPWDI : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
  } EIP0_bit;
} @ 0xF8;
__sfr __no_init volatile unsigned char FDATA @ 0xD6;
__sfr __no_init volatile union
{
  unsigned char STATUS;
  struct
  {
    unsigned char SPRA0 : 1;
    unsigned char SPTA0 : 1;
    unsigned char SPRA1 : 1;
    unsigned char SPTA1 : 1;
    unsigned char  : 1;
    unsigned char PIS0 : 1;
    unsigned char PIS1 : 1;
    unsigned char PIS2 : 1;
  } STATUS_bit;
} @ 0xC5;
__sfr __no_init volatile union
{
  unsigned char CKMOD;
  struct
  {
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char T0MH : 1;
    unsigned char T1MH : 1;
    unsigned char T2MH : 1;
    unsigned char  : 1;
    unsigned char  : 1;
  } CKMOD_bit;
} @ 0x96;
__sfr __no_init volatile unsigned char DPH1 @ 0x85;
__sfr __no_init volatile union
{
  unsigned char EIE;
  struct
  {
    unsigned char EX2 : 1;
    unsigned char EX3 : 1;
    unsigned char EX4 : 1;
    unsigned char EX5 : 1;
    unsigned char EWDI : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
  } EIE_bit;
} @ 0xE8;
__sfr __no_init volatile unsigned char RCAP2L @ 0xCA;
__sfr __no_init volatile union
{
  unsigned char DPS;
  struct
  {
    unsigned char SEL : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char AID : 1;
    unsigned char TSL : 1;
    unsigned char ID0 : 1;
    unsigned char ID1 : 1;
  } DPS_bit;
} @ 0x86;
__sfr __no_init volatile union
{
  unsigned char WDCON;
  struct
  {
    unsigned char RWT : 1;
    unsigned char EWT : 1;
    unsigned char WTRF : 1;
    unsigned char WDIF : 1;
    unsigned char PFI : 1;
    unsigned char EPFI : 1;
    unsigned char POR : 1;
    unsigned char SMOD_1 : 1;
  } WDCON_bit;
} @ 0xD8;
__sfr __no_init volatile unsigned char RCAP2H @ 0xCB;
__sfr __no_init volatile unsigned char TA @ 0xC7;
__sfr __no_init volatile unsigned char SADEN1 @ 0xBA;
__sfr __no_init volatile union
{
  unsigned char SCON0;
  struct
  {
    unsigned char RI_0 : 1;
    unsigned char TI_0 : 1;
    unsigned char RB8_0 : 1;
    unsigned char TB8_0 : 1;
    unsigned char REN_0 : 1;
    unsigned char SM2_0 : 1;
    unsigned char SM1_0 : 1;
    unsigned char SM0_FE_0 : 1;
  } SCON0_bit;
} @ 0x98;
__sfr __no_init volatile unsigned char TL0 @ 0x8A;
__sfr __no_init volatile union
{
  unsigned char PCON;
  struct
  {
    unsigned char IDLE : 1;
    unsigned char STOP : 1;
    unsigned char GF0 : 1;
    unsigned char GF1 : 1;
    unsigned char OFDE : 1;
    unsigned char OFDF : 1;
    unsigned char SMOD0 : 1;
    unsigned char SMOD_0 : 1;
  } PCON_bit;
} @ 0x87;
__sfr __no_init volatile unsigned char B @ 0xF0;
__sfr __no_init volatile union
{
  unsigned char T2CON;
  struct
  {
    unsigned char CP_RL2 : 1;
    unsigned char C_T2 : 1;
    unsigned char TR2 : 1;
    unsigned char EXEN2 : 1;
    unsigned char TCLK : 1;
    unsigned char RCLK : 1;
    unsigned char EXF2 : 1;
    unsigned char TF2 : 1;
  } T2CON_bit;
} @ 0xC8;
__sfr __no_init volatile unsigned char TL1 @ 0x8B;
/*
 * Interrupt Vectors
 */
#define IE0_int 0x03 /* External Interrupt 0 */
#define TF0_int 0x0B /* Timer 0 Overflow */
#define IE1_int 0x13 /* External Interrupt 1 */
#define TF1_int 0x1B /* Timer 1 Overflow */
#define RI_0_int 0x23 /* Serial Port 0 */
#define TI_0_int 0x23 /* Serial Port 0 */
#define TF2_int 0x2B /* Timer 2 Overflow */
#define EXF2_int 0x2B /* Timer 2 Overflow */
#define PFI_int 0x33 /* Power Fail */
#define RI_1_int 0x3B /* Serial Port 1 */
#define TI_1_int 0x3B /* Serial Port 1 */
#define IE2_int 0x43 /* External Interrupt 2 */
#define IE3_int 0x4B /* External Interrupt 3 */
#define IE4_int 0x53 /* External Interrupt 4 */
#define IE5_int 0x5B /* External Interrupt 5 */
#define WDIF_int 0x63 /* Watchdog */

#pragma language=default
#endif  /* __IAR_SYSTEMS_ICC__  */

/***************************************************************************
 *   Assembler definitions
 *
 *   The following SFRs are built in in the a8051.exe and can not be
 *   defined explicitly in this file:
 *     ACC,B,PSW,SP,DPL,DPH
 *   The PSW-bits are built-in in the a8051.exe
 *     OV,AC,F0,RS0,RS1,P
 *
 ***************************************************************************/

#ifdef __IAR_SYSTEMS_ASM__


/*-------------------------------------------------------------------------
 *   All SFRs
 *-------------------------------------------------------------------------*/

P0 DEFINE 0x80
P0_P00 DEFINE 0x80.0
P0_P01 DEFINE 0x80.1
P0_P02 DEFINE 0x80.2
P0_P03 DEFINE 0x80.3
P0_P04 DEFINE 0x80.4
P0_P05 DEFINE 0x80.5
P0_P06 DEFINE 0x80.6
P0_P07 DEFINE 0x80.7
DPL1 DEFINE 0x84
DPH1 DEFINE 0x85
DPS DEFINE 0x86
PCON DEFINE 0x87
TCON DEFINE 0x88
TCON_IT0 DEFINE 0x88.0
TCON_IE0 DEFINE 0x88.1
TCON_IT1 DEFINE 0x88.2
TCON_IE1 DEFINE 0x88.3
TCON_TR0 DEFINE 0x88.4
TCON_TF0 DEFINE 0x88.5
TCON_TR1 DEFINE 0x88.6
TCON_TF1 DEFINE 0x88.7
TMOD DEFINE 0x89
TL0 DEFINE 0x8A
TL1 DEFINE 0x8B
TH0 DEFINE 0x8C
TH1 DEFINE 0x8D
CKCON DEFINE 0x8E
P1 DEFINE 0x90
P1_P10_T2 DEFINE 0x90.0
P1_P11_T2EX DEFINE 0x90.1
P1_P12_RXD1 DEFINE 0x90.2
P1_P13_TXD1 DEFINE 0x90.3
P1_P14_INT2 DEFINE 0x90.4
P1_P15_INT3 DEFINE 0x90.5
P1_P16_INT4 DEFINE 0x90.6
P1_P17_INT5 DEFINE 0x90.7
EXIF DEFINE 0x91
CKMOD DEFINE 0x96
SCON0 DEFINE 0x98
SCON0_RI_0 DEFINE 0x98.0
SCON0_TI_0 DEFINE 0x98.1
SCON0_RB8_0 DEFINE 0x98.2
SCON0_TB8_0 DEFINE 0x98.3
SCON0_REN_0 DEFINE 0x98.4
SCON0_SM2_0 DEFINE 0x98.5
SCON0_SM1_0 DEFINE 0x98.6
SCON0_SM0_FE_0 DEFINE 0x98.7
SBUF0 DEFINE 0x99
ACON DEFINE 0x9D
P2 DEFINE 0xA0
P2_P20 DEFINE 0xA0.0
P2_P21 DEFINE 0xA0.1
P2_P22 DEFINE 0xA0.2
P2_P23 DEFINE 0xA0.3
P2_P24 DEFINE 0xA0.4
P2_P25 DEFINE 0xA0.5
P2_P26 DEFINE 0xA0.6
P2_P27 DEFINE 0xA0.7
IE DEFINE 0xA8
IE_EX0 DEFINE 0xA8.0
IE_ET0 DEFINE 0xA8.1
IE_EX1 DEFINE 0xA8.2
IE_ET1 DEFINE 0xA8.3
IE_ES0 DEFINE 0xA8.4
IE_ET2 DEFINE 0xA8.5
IE_ES1 DEFINE 0xA8.6
IE_EA DEFINE 0xA8.7
SADDR0 DEFINE 0xA9
SADDR1 DEFINE 0xAA
P3 DEFINE 0xB0
P3_P30_RXD0 DEFINE 0xB0.0
P3_P31_TXD0 DEFINE 0xB0.1
P3_P32_INT0 DEFINE 0xB0.2
P3_P33_INT1 DEFINE 0xB0.3
P3_P34_T0 DEFINE 0xB0.4
P3_P35_T1 DEFINE 0xB0.5
P3_P36_WR DEFINE 0xB0.6
P3_P37_RD DEFINE 0xB0.7
IP1 DEFINE 0xB1
IP0 DEFINE 0xB8
IP0_LPX0 DEFINE 0xB8.0
IP0_LPT0 DEFINE 0xB8.1
IP0_LPX1 DEFINE 0xB8.2
IP0_LPT1 DEFINE 0xB8.3
IP0_LPS0 DEFINE 0xB8.4
IP0_LPT2 DEFINE 0xB8.5
IP0_LPS1 DEFINE 0xB8.6
SADEN0 DEFINE 0xB9
SADEN1 DEFINE 0xBA
SCON1 DEFINE 0xC0
SCON1_RI_1 DEFINE 0xC0.0
SCON1_TI_1 DEFINE 0xC0.1
SCON1_RB8_1 DEFINE 0xC0.2
SCON1_TB8_1 DEFINE 0xC0.3
SCON1_REN_1 DEFINE 0xC0.4
SCON1_SM2_1 DEFINE 0xC0.5
SCON1_SM1_1 DEFINE 0xC0.6
SCON1_SM0_FE_1 DEFINE 0xC0.7
SBUF1 DEFINE 0xC1
ROMSIZE DEFINE 0xC2
PMR DEFINE 0xC4
STATUS DEFINE 0xC5
TA DEFINE 0xC7
T2CON DEFINE 0xC8
T2CON_CP_RL2 DEFINE 0xC8.0
T2CON_C_T2 DEFINE 0xC8.1
T2CON_TR2 DEFINE 0xC8.2
T2CON_EXEN2 DEFINE 0xC8.3
T2CON_TCLK DEFINE 0xC8.4
T2CON_RCLK DEFINE 0xC8.5
T2CON_EXF2 DEFINE 0xC8.6
T2CON_TF2 DEFINE 0xC8.7
T2MOD DEFINE 0xC9
RCAP2L DEFINE 0xCA
RCAP2H DEFINE 0xCB
TL2 DEFINE 0xCC
TH2 DEFINE 0xCD
FCNTL DEFINE 0xD5
FDATA DEFINE 0xD6
WDCON DEFINE 0xD8
WDCON_RWT DEFINE 0xD8.0
WDCON_EWT DEFINE 0xD8.1
WDCON_WTRF DEFINE 0xD8.2
WDCON_WDIF DEFINE 0xD8.3
WDCON_PFI DEFINE 0xD8.4
WDCON_EPFI DEFINE 0xD8.5
WDCON_POR DEFINE 0xD8.6
WDCON_SMOD_1 DEFINE 0xD8.7
EIE DEFINE 0xE8
EIE_EX2 DEFINE 0xE8.0
EIE_EX3 DEFINE 0xE8.1
EIE_EX4 DEFINE 0xE8.2
EIE_EX5 DEFINE 0xE8.3
EIE_EWDI DEFINE 0xE8.4
EIP1 DEFINE 0xF1
EIP0 DEFINE 0xF8
EIP0_LPX2 DEFINE 0xF8.0
EIP0_LPX3 DEFINE 0xF8.1
EIP0_LPX4 DEFINE 0xF8.2
EIP0_LPX5 DEFINE 0xF8.3
EIP0_LPWDI DEFINE 0xF8.4

#endif /* __IAR_SYSTEMS_ASM__*/
#endif /* IODS89C450_H */
/***************************************************************************
 *                                - iouPSD3254A.h -
 *
 * Special header for the STMicroelectronics uPSD3254A Microcontroller.
 *
 ***************************************************************************/

#ifndef IOUPSD3254A_H
#define IOUPSD3254A_H
#define __UPSD3254A__
#ifdef __IAR_SYSTEMS_ICC__
#ifndef _SYSTEM_BUILD
   #pragma system_include
#endif
#pragma language=extended

/*-------------------------------------------------------------------------
 *   8051 Core
 *-------------------------------------------------------------------------*/

__sfr __no_init volatile unsigned char ACC @ 0xE0; /* Accumulator */
__sfr __no_init volatile union
{
  unsigned char PSW; /* Program Status Word */
  struct /* Program Status Word */
  {
    unsigned char P : 1;
    unsigned char F1 : 1;
    unsigned char OV : 1;
    unsigned char RS0 : 1;
    unsigned char RS1 : 1;
    unsigned char FO : 1;
    unsigned char AC : 1;
    unsigned char CY : 1;
  } PSW_bit;
} @ 0xD0;
__sfr __no_init volatile unsigned char SP @ 0x81; /* Stack Ptr */
__sfr __no_init volatile unsigned char DPL @ 0x82; /* Data Ptr Low */
__sfr __no_init volatile unsigned char DPH @ 0x83; /* Data Ptr High */
__sfr __no_init volatile unsigned char B @ 0xF0; /* B Register */

/*-------------------------------------------------------------------------
 *   Interrupt
 *-------------------------------------------------------------------------*/

__sfr __no_init volatile union
{
  unsigned char IP; /* Interrupt Priority */
  struct /* Interrupt Priority */
  {
    unsigned char PX0 : 1;
    unsigned char PT0 : 1;
    unsigned char PX1 : 1;
    unsigned char PT1 : 1;
    unsigned char PS : 1;
    unsigned char PT2 : 1;
    unsigned char  : 1;
    unsigned char  : 1;
  } IP_bit;
} @ 0xB8;
__sfr __no_init volatile union
{
  unsigned char IEA; /* Interrupt Enable (2nd) */
  struct /* Interrupt Enable (2nd) */
  {
    unsigned char EUSB : 1;
    unsigned char EI2C : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char ES2 : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char EDDC : 1;
  } IEA_bit;
} @ 0xA7;
__sfr __no_init volatile union
{
  unsigned char IE; /* Interrupt Enable */
  struct /* Interrupt Enable */
  {
    unsigned char EX0 : 1;
    unsigned char ET0 : 1;
    unsigned char EX1 : 1;
    unsigned char ET1 : 1;
    unsigned char ES : 1;
    unsigned char ET2 : 1;
    unsigned char  : 1;
    unsigned char EA : 1;
  } IE_bit;
} @ 0xA8;
__sfr __no_init volatile union
{
  unsigned char IPA; /* Interrupt Priority (2nd) */
  struct /* Interrupt Priority (2nd) */
  {
    unsigned char PUSB : 1;
    unsigned char PI2C : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char PS2 : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char PDDC : 1;
  } IPA_bit;
} @ 0xB7;

/*-------------------------------------------------------------------------
 *   I2C Bus
 *-------------------------------------------------------------------------*/

__sfr __no_init volatile union
{
  unsigned char S2STA; /* I2C Bus Status */
  struct /* I2C Bus Status */
  {
    unsigned char SLV : 1;
    unsigned char ACK_R : 1;
    unsigned char Blost : 1;
    unsigned char Bbusy : 1;
    unsigned char  : 1;
    unsigned char Intr : 1;
    unsigned char Stop : 1;
    unsigned char GC : 1;
  } S2STA_bit;
} @ 0xDD;
__sfr __no_init volatile unsigned char S2ADR @ 0xDF; /* I2C address */
__sfr __no_init volatile unsigned char S1SETUP @ 0xD1; /* DDC I2C (S1) Setup */
__sfr __no_init volatile unsigned char S2SETUP @ 0xD2; /* I2C (S2) Setup */
__sfr __no_init volatile union
{
  unsigned char S2CON; /* I2C Bus Control Reg */
  struct /* I2C Bus Control Reg */
  {
    unsigned char CR0 : 1;
    unsigned char CR1 : 1;
    unsigned char AA : 1;
    unsigned char ADDR : 1;
    unsigned char STO : 1;
    unsigned char STA : 1;
    unsigned char EN1 : 1;
    unsigned char CR2 : 1;
  } S2CON_bit;
} @ 0xDC;
__sfr __no_init volatile union
{
  unsigned char S1CON; /* DDC I2C Control Reg */
  struct /* DDC I2C Control Reg */
  {
    unsigned char CR0 : 1;
    unsigned char CR1 : 1;
    unsigned char AA : 1;
    unsigned char ADDR : 1;
    unsigned char STO : 1;
    unsigned char STA : 1;
    unsigned char ENI1 : 1;
    unsigned char CR2 : 1;
  } S1CON_bit;
} @ 0xD8;
__sfr __no_init volatile union
{
  unsigned char S1STA; /* DDC I2C Status */
  struct /* DDC I2C Status */
  {
    unsigned char SLV : 1;
    unsigned char ACK_R : 1;
    unsigned char Blost : 1;
    unsigned char Bbusy : 1;
    unsigned char  : 1;
    unsigned char Intr : 1;
    unsigned char Stop : 1;
    unsigned char GC : 1;
  } S1STA_bit;
} @ 0xD9;

/*-------------------------------------------------------------------------
 *   USB
 *-------------------------------------------------------------------------*/

__sfr __no_init volatile union
{
  unsigned char UADR; /* USB Address Register */
  struct /* USB Address Register */
  {
    unsigned char UADD0 : 1;
    unsigned char UADD1 : 1;
    unsigned char UADD2 : 1;
    unsigned char UADD3 : 1;
    unsigned char UADD4 : 1;
    unsigned char UADD5 : 1;
    unsigned char UADD6 : 1;
    unsigned char USBEN : 1;
  } UADR_bit;
} @ 0xEE;
__sfr __no_init volatile union
{
  unsigned char UDR0; /* USB Endpt0 Data Recv */
  struct /* USB Endpt0 Data Recv */
  {
    unsigned char UDR00 : 1;
    unsigned char UDR01 : 1;
    unsigned char UDR02 : 1;
    unsigned char UDR03 : 1;
    unsigned char UDR04 : 1;
    unsigned char UDR05 : 1;
    unsigned char UDR06 : 1;
    unsigned char UDR07 : 1;
  } UDR0_bit;
} @ 0xEF;
__sfr __no_init volatile unsigned char USCL @ 0xE1; /* 8-bit Prescaler for USB logic */
__sfr __no_init volatile union
{
  unsigned char UCON0; /* USB Endpt0 Xmit Control */
  struct /* USB Endpt0 Xmit Control */
  {
    unsigned char TP0SIZ0 : 1;
    unsigned char TP0SIZ1 : 1;
    unsigned char TP0SiZ2 : 1;
    unsigned char TP0SIZ3 : 1;
    unsigned char RX0E : 1;
    unsigned char TX0E : 1;
    unsigned char STALL0 : 1;
    unsigned char TSEQ0 : 1;
  } UCON0_bit;
} @ 0xEA;
__sfr __no_init volatile union
{
  unsigned char UDT1; /* USB Endpt1 Data Xmit */
  struct /* USB Endpt1 Data Xmit */
  {
    unsigned char UDT10 : 1;
    unsigned char UDT11 : 1;
    unsigned char UDT12 : 1;
    unsigned char UDT13 : 1;
    unsigned char UDT14 : 1;
    unsigned char UDT15 : 1;
    unsigned char UDT16 : 1;
    unsigned char UDT17 : 1;
  } UDT1_bit;
} @ 0xE6;
__sfr __no_init volatile union
{
  unsigned char UCON1; /* USB Endpt1 Xmit Control */
  struct /* USB Endpt1 Xmit Control */
  {
    unsigned char TP1SIZ0 : 1;
    unsigned char TP1SIZ1 : 1;
    unsigned char TP1SiZ2 : 1;
    unsigned char TP1SIZ3 : 1;
    unsigned char FRESUM : 1;
    unsigned char  : 1;
    unsigned char EP12SEL : 1;
    unsigned char TSEQ1 : 1;
  } UCON1_bit;
} @ 0xEB;
__sfr __no_init volatile union
{
  unsigned char UDT0; /* USB Endpt0 Data Xmit */
  struct /* USB Endpt0 Data Xmit */
  {
    unsigned char UDT00 : 1;
    unsigned char UDT01 : 1;
    unsigned char UDT02 : 1;
    unsigned char UDT03 : 1;
    unsigned char UDT04 : 1;
    unsigned char UDT05 : 1;
    unsigned char UDT06 : 1;
    unsigned char UDT07 : 1;
  } UDT0_bit;
} @ 0xE7;
__sfr __no_init volatile union
{
  unsigned char UCON2; /* USB Control Register */
  struct /* USB Control Register */
  {
    unsigned char STALL1 : 1;
    unsigned char STALL2 : 1;
    unsigned char EP1E : 1;
    unsigned char EP2E : 1;
    unsigned char SOUT : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
  } UCON2_bit;
} @ 0xEC;
__sfr __no_init volatile union
{
  unsigned char UISTA; /* USB Interrupt Status */
  struct /* USB Interrupt Status */
  {
    unsigned char RESUMF : 1;
    unsigned char EOPF : 1;
    unsigned char RXD1F : 1;
    unsigned char RXD0F : 1;
    unsigned char TXD0F : 1;
    unsigned char RSTF : 1;
    unsigned char  : 1;
    unsigned char SUSPND : 1;
  } UISTA_bit;
} @ 0xE8;
__sfr __no_init volatile union
{
  unsigned char USTA; /* USB Endpt0 Status */
  struct /* USB Endpt0 Status */
  {
    unsigned char RP0SIZ0 : 1;
    unsigned char RP0SIZ1 : 1;
    unsigned char RP0SIZ2 : 1;
    unsigned char RP0SIZ3 : 1;
    unsigned char OUT : 1;
    unsigned char IN : 1;
    unsigned char SETUP : 1;
    unsigned char RSEQ : 1;
  } USTA_bit;
} @ 0xED;
__sfr __no_init volatile union
{
  unsigned char UIEN; /* USB Interrupt Enable */
  struct /* USB Interrupt Enable */
  {
    unsigned char RESUMIE : 1;
    unsigned char EOPIE : 1;
    unsigned char TXD1IE : 1;
    unsigned char RXD0IE : 1;
    unsigned char TXD0IE : 1;
    unsigned char RSTFIE : 1;
    unsigned char RSTE : 1;
    unsigned char SUSPNDIE : 1;
  } UIEN_bit;
} @ 0xE9;

/*-------------------------------------------------------------------------
 *   I/O Port
 *-------------------------------------------------------------------------*/

__sfr __no_init volatile union
{
  unsigned char P1; /* Port 1 */
  struct /* Port 1 */
  {
    unsigned char P10 : 1;
    unsigned char P11 : 1;
    unsigned char P12 : 1;
    unsigned char P13 : 1;
    unsigned char P14 : 1;
    unsigned char P15 : 1;
    unsigned char P16 : 1;
    unsigned char P17 : 1;
  } P1_bit;
} @ 0x90;
__sfr __no_init volatile union
{
  unsigned char P4; /* New Port 4 */
  struct /* New Port 4 */
  {
    unsigned char P40 : 1;
    unsigned char P41 : 1;
    unsigned char P42 : 1;
    unsigned char P43 : 1;
    unsigned char P44 : 1;
    unsigned char P45 : 1;
    unsigned char P46 : 1;
    unsigned char P47 : 1;
  } P4_bit;
} @ 0xC0;
__sfr __no_init volatile union
{
  unsigned char P1SFS; /* Port 1 Select Register */
  struct /* Port 1 Select Register */
  {
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char P1S4 : 1;
    unsigned char P1S5 : 1;
    unsigned char P1S6 : 1;
    unsigned char P1S7 : 1;
  } P1SFS_bit;
} @ 0x91;
__sfr __no_init volatile union
{
  unsigned char P0; /* Port 0 */
  struct /* Port 0 */
  {
    unsigned char P00 : 1;
    unsigned char P01 : 1;
    unsigned char P02 : 1;
    unsigned char P03 : 1;
    unsigned char P04 : 1;
    unsigned char P05 : 1;
    unsigned char P06 : 1;
    unsigned char P07 : 1;
  } P0_bit;
} @ 0x80;
__sfr __no_init volatile union
{
  unsigned char P3; /* Port 3 */
  struct /* Port 3 */
  {
    unsigned char P30 : 1;
    unsigned char P31 : 1;
    unsigned char P32 : 1;
    unsigned char P33 : 1;
    unsigned char P34 : 1;
    unsigned char P35 : 1;
    unsigned char P36 : 1;
    unsigned char P37 : 1;
  } P3_bit;
} @ 0xB0;
__sfr __no_init volatile union
{
  unsigned char P2; /* Port 2 */
  struct /* Port 2 */
  {
    unsigned char P20 : 1;
    unsigned char P21 : 1;
    unsigned char P22 : 1;
    unsigned char P23 : 1;
    unsigned char P24 : 1;
    unsigned char P25 : 1;
    unsigned char P26 : 1;
    unsigned char P27 : 1;
  } P2_bit;
} @ 0xA0;
__sfr __no_init volatile union
{
  unsigned char P3SFS; /* Port 3 Select Register */
  struct /* Port 3 Select Register */
  {
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char P3S6 : 1;
    unsigned char P3S7 : 1;
  } P3SFS_bit;
} @ 0x93;
__sfr __no_init volatile union
{
  unsigned char P4SFS; /* Port 4 Select Register */
  struct /* Port 4 Select Register */
  {
    unsigned char P4S0 : 1;
    unsigned char P4S1 : 1;
    unsigned char P4S2 : 1;
    unsigned char P4S3 : 1;
    unsigned char P4S4 : 1;
    unsigned char P4S5 : 1;
    unsigned char P4S6 : 1;
    unsigned char P4S7 : 1;
  } P4SFS_bit;
} @ 0x94;

/*-------------------------------------------------------------------------
 *   PWM
 *-------------------------------------------------------------------------*/

__sfr __no_init volatile unsigned char PWM4P @ 0xAA; /* PWM 4 Period */
__sfr __no_init volatile unsigned char PWM4W @ 0xAB; /* PWM 4 Pulse Width */
__sfr __no_init volatile union
{
  unsigned char PWMCON; /* PWM Control Polarity */
  struct /* PWM Control Polarity */
  {
    unsigned char CFG0 : 1;
    unsigned char CFG1 : 1;
    unsigned char CFG2 : 1;
    unsigned char CFG3 : 1;
    unsigned char CFG4 : 1;
    unsigned char PWME : 1;
    unsigned char PWMP : 1;
    unsigned char PWML : 1;
  } PWMCON_bit;
} @ 0xA1;
__sfr __no_init volatile unsigned char PWM1 @ 0xA3; /* PWM1 Output Duty Cycle */
__sfr __no_init volatile unsigned char PWM2 @ 0xA4; /* PWM2 Output Duty Cycle */
__sfr __no_init volatile unsigned char PWM3 @ 0xA5; /* PWM3 Output Duty Cycle */

/*-------------------------------------------------------------------------
 *   Serial I/O
 *-------------------------------------------------------------------------*/

__sfr __no_init volatile unsigned char SBUF @ 0x99; /* Serial Buffer */
__sfr __no_init volatile union
{
  unsigned char SCON2; /* 2nd UART Ctrl Register */
  struct /* 2nd UART Ctrl Register */
  {
    unsigned char RI : 1;
    unsigned char TI : 1;
    unsigned char RB8 : 1;
    unsigned char TB8 : 1;
    unsigned char REN : 1;
    unsigned char SM2 : 1;
    unsigned char SM1 : 1;
    unsigned char SM0 : 1;
  } SCON2_bit;
} @ 0x9A;
__sfr __no_init volatile unsigned char SBUF2 @ 0x9B; /* 2nd UART Serial Buffer */
__sfr __no_init volatile union
{
  unsigned char SCON; /* Serial Control Register */
  struct /* Serial Control Register */
  {
    unsigned char RI : 1;
    unsigned char TI : 1;
    unsigned char RB8 : 1;
    unsigned char TB8 : 1;
    unsigned char REN : 1;
    unsigned char SM2 : 1;
    unsigned char SM1 : 1;
    unsigned char SM0 : 1;
  } SCON_bit;
} @ 0x98;

/*-------------------------------------------------------------------------
 *   Watchdog timer
 *-------------------------------------------------------------------------*/

__sfr __no_init volatile unsigned char WDKEY @ 0xAE; /* Watch Dog Key Register */
__sfr __no_init volatile unsigned char WDRST @ 0xA6; /* Watch Dog Reset */

/*-------------------------------------------------------------------------
 *   System Management
 *-------------------------------------------------------------------------*/

__sfr __no_init volatile unsigned char S2DAT @ 0xDE; /* Data Hold Register */
__sfr __no_init volatile unsigned char PSCL0L @ 0xB1; /* Prescaler 0 Low (8-bit) */
__sfr __no_init volatile unsigned char RAMBUF @ 0xD4; /* DDC Ram Buffer */
__sfr __no_init volatile unsigned char PSCL0H @ 0xB2; /* Prescaler 0 High (8-bit) */
__sfr __no_init volatile unsigned char DDCDAT @ 0xD5; /* DDC Data xmit register */
__sfr __no_init volatile unsigned char PSCL1L @ 0xB3; /* Prescaler 1 Low (8-bit) */
__sfr __no_init volatile unsigned char PWM0 @ 0xA2; /* Output Duty Cycle */
__sfr __no_init volatile unsigned char S1DAT @ 0xDA; /* Data Hold Register */
__sfr __no_init volatile unsigned char DDCADR @ 0xD6; /* Addr pointer register */
__sfr __no_init volatile unsigned char PSCL1H @ 0xB4; /* Prescaler 1 High (8-bit) */
__sfr __no_init volatile unsigned char S1ADR @ 0xDB; /* DDC I2C address */
__sfr __no_init volatile union
{
  unsigned char DDCCON; /* DDC Control Register */
  struct /* DDC Control Register */
  {
    unsigned char M0 : 1;
    unsigned char SWHINT : 1;
    unsigned char DDC1EN : 1;
    unsigned char DDCINT : 1;
    unsigned char DDC_AX : 1;
    unsigned char SWENB : 1;
    unsigned char EX_DAT : 1;
    unsigned char  : 1;
  } DDCCON_bit;
} @ 0xD7;
__sfr __no_init volatile union
{
  unsigned char PCON; /* Power Ctrl */
  struct /* Power Ctrl */
  {
    unsigned char IDLE : 1;
    unsigned char PD : 1;
    unsigned char TCLK1 : 1;
    unsigned char RCLK1 : 1;
    unsigned char ADSFINT : 1;
    unsigned char LVREN : 1;
    unsigned char SMOD1 : 1;
    unsigned char SMOD : 1;
  } PCON_bit;
} @ 0x87;

/*-------------------------------------------------------------------------
 *   Timer
 *-------------------------------------------------------------------------*/

__sfr __no_init volatile unsigned char TL2 @ 0xCC; /* Timer 2 Low byte */
__sfr __no_init volatile union
{
  unsigned char T2MOD; /* Timer 2 Mode */
  struct /* Timer 2 Mode */
  {
    unsigned char DCEN : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
    unsigned char  : 1;
  } T2MOD_bit;
} @ 0xC9;
__sfr __no_init volatile unsigned char TH0 @ 0x8C; /* Timer 0 High */
__sfr __no_init volatile union
{
  unsigned char TCON; /* Timer / Cntr Control */
  struct /* Timer / Cntr Control */
  {
    unsigned char IT0 : 1;
    unsigned char IE0 : 1;
    unsigned char IT1 : 1;
    unsigned char IE1 : 1;
    unsigned char TR0 : 1;
    unsigned char TF0 : 1;
    unsigned char TR1 : 1;
    unsigned char TF1 : 1;
  } TCON_bit;
} @ 0x88;
__sfr __no_init volatile unsigned char TH2 @ 0xCD; /* Timer 2 High byte */
__sfr __no_init volatile unsigned char TH1 @ 0x8D; /* Timer 1 High */
__sfr __no_init volatile union
{
  unsigned char TMOD; /* Timer / Cntr Mode Control */
  struct /* Timer / Cntr Mode Control */
  {
    unsigned char M00 : 1;
    unsigned char M10 : 1;
    unsigned char C_T0 : 1;
    unsigned char Gate0 : 1;
    unsigned char M01 : 1;
    unsigned char M11 : 1;
    unsigned char C_T1 : 1;
    unsigned char Gate1 : 1;
  } TMOD_bit;
} @ 0x89;
__sfr __no_init volatile unsigned char RCAP2L @ 0xCA; /* Timer 2 Reload low */
__sfr __no_init volatile unsigned char RCAP2H @ 0xCB; /* Timer 2 Reload High */
__sfr __no_init volatile unsigned char TL0 @ 0x8A; /* Timer 0 Low */
__sfr __no_init volatile union
{
  unsigned char T2CON; /* Timer 2 Control */
  struct /* Timer 2 Control */
  {
    unsigned char CP_RL2 : 1;
    unsigned char C_T2 : 1;
    unsigned char TR2 : 1;
    unsigned char EXEN2 : 1;
    unsigned char TCLK : 1;
    unsigned char RCLK : 1;
    unsigned char EXF2 : 1;
    unsigned char TF2 : 1;
  } T2CON_bit;
} @ 0xC8;
__sfr __no_init volatile unsigned char TL1 @ 0x8B; /* Timer 1 Low */

/*-------------------------------------------------------------------------
 *   Analog to Digital Converter (ADC)
 *-------------------------------------------------------------------------*/

__sfr __no_init volatile unsigned char ASCL @ 0x95; /* 8-bit Prescaler for ADC clock */
__sfr __no_init volatile union
{
  unsigned char ADAT; /* ADC Data Register */
  struct /* ADC Data Register */
  {
    unsigned char ADAT0 : 1;
    unsigned char ADAT1 : 1;
    unsigned char ADAT2 : 1;
    unsigned char ADAT3 : 1;
    unsigned char ADAT4 : 1;
    unsigned char ADAT5 : 1;
    unsigned char ADAT6 : 1;
    unsigned char ADAT7 : 1;
  } ADAT_bit;
} @ 0x96;
__sfr __no_init volatile union
{
  unsigned char ACON; /* ADC Control Register */
  struct /* ADC Control Register */
  {
    unsigned char ADSF : 1;
    unsigned char ADST : 1;
    unsigned char ADS0 : 1;
    unsigned char ADS1 : 1;
    unsigned char  : 1;
    unsigned char ADEN : 1;
    unsigned char  : 1;
    unsigned char  : 1;
  } ACON_bit;
} @ 0x97;
/*
 * Interrupt Vectors
 */
#define extern0 0x03 /* External interrupt 0 */
#define IE0_int 0x03 /* External interrupt 0 */
#define timer0 0x0B /* Timer 0 Interrupt */
#define TF0_int 0x0B /* Timer 0 Interrupt */
#define extern1 0x13 /* External interrupt 1 */
#define IE1_int 0x13 /* External interrupt 1 */
#define timer1 0x1B /* Timer 1 Interrupt */
#define TF1_int 0x1B /* Timer 1 Interrupt */
#define sio_ti 0x23 /* Serial Port Interrupt */
#define sio_ri 0x23 /* Serial Port Interrupt */
#define TI_int 0x23 /* Serial Port Interrupt */
#define RI_int 0x23 /* Serial Port Interrupt */

#pragma language=default
#endif  /* __IAR_SYSTEMS_ICC__  */

/***************************************************************************
 *   Assembler definitions
 *
 *   The following SFRs are built in in the a8051.exe and can not be
 *   defined explicitly in this file:
 *     ACC,B,PSW,SP,DPL,DPH
 *   The PSW-bits are built-in in the a8051.exe
 *     OV,AC,F0,RS0,RS1,P
 *
 ***************************************************************************/

#ifdef __IAR_SYSTEMS_ASM__


/*-------------------------------------------------------------------------
 *   Interrupt
 *-------------------------------------------------------------------------*/

IEA DEFINE 0xA7 /* Interrupt Enable (2nd) */
IE DEFINE 0xA8 /* Interrupt Enable */
IE_EX0 DEFINE 0xA8.0
IE_ET0 DEFINE 0xA8.1
IE_EX1 DEFINE 0xA8.2
IE_ET1 DEFINE 0xA8.3
IE_ES DEFINE 0xA8.4
IE_ET2 DEFINE 0xA8.5
IE_EA DEFINE 0xA8.7
IPA DEFINE 0xB7 /* Interrupt Priority (2nd) */
IP DEFINE 0xB8 /* Interrupt Priority */
IP_PX0 DEFINE 0xB8.0
IP_PT0 DEFINE 0xB8.1
IP_PX1 DEFINE 0xB8.2
IP_PT1 DEFINE 0xB8.3
IP_PS DEFINE 0xB8.4
IP_PT2 DEFINE 0xB8.5

/*-------------------------------------------------------------------------
 *   I2C Bus
 *-------------------------------------------------------------------------*/

S1SETUP DEFINE 0xD1 /* DDC I2C (S1) Setup */
S2SETUP DEFINE 0xD2 /* I2C (S2) Setup */
S1CON DEFINE 0xD8 /* DDC I2C Control Reg */
S1CON_CR0 DEFINE 0xD8.0
S1CON_CR1 DEFINE 0xD8.1
S1CON_AA DEFINE 0xD8.2
S1CON_ADDR DEFINE 0xD8.3
S1CON_STO DEFINE 0xD8.4
S1CON_STA DEFINE 0xD8.5
S1CON_ENI1 DEFINE 0xD8.6
S1CON_CR2 DEFINE 0xD8.7
S1STA DEFINE 0xD9 /* DDC I2C Status */
S2CON DEFINE 0xDC /* I2C Bus Control Reg */
S2STA DEFINE 0xDD /* I2C Bus Status */
S2ADR DEFINE 0xDF /* I2C address */

/*-------------------------------------------------------------------------
 *   USB
 *-------------------------------------------------------------------------*/

USCL DEFINE 0xE1 /* 8-bit Prescaler for USB logic */
UDT1 DEFINE 0xE6 /* USB Endpt1 Data Xmit */
UDT0 DEFINE 0xE7 /* USB Endpt0 Data Xmit */
UISTA DEFINE 0xE8 /* USB Interrupt Status */
UISTA_RESUMF DEFINE 0xE8.0
UISTA_EOPF DEFINE 0xE8.1
UISTA_RXD1F DEFINE 0xE8.2
UISTA_RXD0F DEFINE 0xE8.3
UISTA_TXD0F DEFINE 0xE8.4
UISTA_RSTF DEFINE 0xE8.5
UISTA_SUSPND DEFINE 0xE8.7
UIEN DEFINE 0xE9 /* USB Interrupt Enable */
UCON0 DEFINE 0xEA /* USB Endpt0 Xmit Control */
UCON1 DEFINE 0xEB /* USB Endpt1 Xmit Control */
UCON2 DEFINE 0xEC /* USB Control Register */
USTA DEFINE 0xED /* USB Endpt0 Status */
UADR DEFINE 0xEE /* USB Address Register */
UDR0 DEFINE 0xEF /* USB Endpt0 Data Recv */

/*-------------------------------------------------------------------------
 *   I/O Port
 *-------------------------------------------------------------------------*/

P0 DEFINE 0x80 /* Port 0 */
P0_P00 DEFINE 0x80.0
P0_P01 DEFINE 0x80.1
P0_P02 DEFINE 0x80.2
P0_P03 DEFINE 0x80.3
P0_P04 DEFINE 0x80.4
P0_P05 DEFINE 0x80.5
P0_P06 DEFINE 0x80.6
P0_P07 DEFINE 0x80.7
P1 DEFINE 0x90 /* Port 1 */
P1_P10 DEFINE 0x90.0
P1_P11 DEFINE 0x90.1
P1_P12 DEFINE 0x90.2
P1_P13 DEFINE 0x90.3
P1_P14 DEFINE 0x90.4
P1_P15 DEFINE 0x90.5
P1_P16 DEFINE 0x90.6
P1_P17 DEFINE 0x90.7
P1SFS DEFINE 0x91 /* Port 1 Select Register */
P3SFS DEFINE 0x93 /* Port 3 Select Register */
P4SFS DEFINE 0x94 /* Port 4 Select Register */
P2 DEFINE 0xA0 /* Port 2 */
P2_P20 DEFINE 0xA0.0
P2_P21 DEFINE 0xA0.1
P2_P22 DEFINE 0xA0.2
P2_P23 DEFINE 0xA0.3
P2_P24 DEFINE 0xA0.4
P2_P25 DEFINE 0xA0.5
P2_P26 DEFINE 0xA0.6
P2_P27 DEFINE 0xA0.7
P3 DEFINE 0xB0 /* Port 3 */
P3_P30 DEFINE 0xB0.0
P3_P31 DEFINE 0xB0.1
P3_P32 DEFINE 0xB0.2
P3_P33 DEFINE 0xB0.3
P3_P34 DEFINE 0xB0.4
P3_P35 DEFINE 0xB0.5
P3_P36 DEFINE 0xB0.6
P3_P37 DEFINE 0xB0.7
P4 DEFINE 0xC0 /* New Port 4 */
P4_P40 DEFINE 0xC0.0
P4_P41 DEFINE 0xC0.1
P4_P42 DEFINE 0xC0.2
P4_P43 DEFINE 0xC0.3
P4_P44 DEFINE 0xC0.4
P4_P45 DEFINE 0xC0.5
P4_P46 DEFINE 0xC0.6
P4_P47 DEFINE 0xC0.7

/*-------------------------------------------------------------------------
 *   PWM
 *-------------------------------------------------------------------------*/

PWMCON DEFINE 0xA1 /* PWM Control Polarity */
PWM1 DEFINE 0xA3 /* PWM1 Output Duty Cycle */
PWM2 DEFINE 0xA4 /* PWM2 Output Duty Cycle */
PWM3 DEFINE 0xA5 /* PWM3 Output Duty Cycle */
PWM4P DEFINE 0xAA /* PWM 4 Period */
PWM4W DEFINE 0xAB /* PWM 4 Pulse Width */

/*-------------------------------------------------------------------------
 *   Serial I/O
 *-------------------------------------------------------------------------*/

SCON DEFINE 0x98 /* Serial Control Register */
SCON_RI DEFINE 0x98.0
SCON_TI DEFINE 0x98.1
SCON_RB8 DEFINE 0x98.2
SCON_TB8 DEFINE 0x98.3
SCON_REN DEFINE 0x98.4
SCON_SM2 DEFINE 0x98.5
SCON_SM1 DEFINE 0x98.6
SCON_SM0 DEFINE 0x98.7
SBUF DEFINE 0x99 /* Serial Buffer */
SCON2 DEFINE 0x9A /* 2nd UART Ctrl Register */
SBUF2 DEFINE 0x9B /* 2nd UART Serial Buffer */

/*-------------------------------------------------------------------------
 *   Watchdog timer
 *-------------------------------------------------------------------------*/

WDRST DEFINE 0xA6 /* Watch Dog Reset */
WDKEY DEFINE 0xAE /* Watch Dog Key Register */

/*-------------------------------------------------------------------------
 *   System Management
 *-------------------------------------------------------------------------*/

PCON DEFINE 0x87 /* Power Ctrl */
PWM0 DEFINE 0xA2 /* Output Duty Cycle */
PSCL0L DEFINE 0xB1 /* Prescaler 0 Low (8-bit) */
PSCL0H DEFINE 0xB2 /* Prescaler 0 High (8-bit) */
PSCL1L DEFINE 0xB3 /* Prescaler 1 Low (8-bit) */
PSCL1H DEFINE 0xB4 /* Prescaler 1 High (8-bit) */
RAMBUF DEFINE 0xD4 /* DDC Ram Buffer */
DDCDAT DEFINE 0xD5 /* DDC Data xmit register */
DDCADR DEFINE 0xD6 /* Addr pointer register */
DDCCON DEFINE 0xD7 /* DDC Control Register */
S1DAT DEFINE 0xDA /* Data Hold Register */
S1ADR DEFINE 0xDB /* DDC I2C address */
S2DAT DEFINE 0xDE /* Data Hold Register */

/*-------------------------------------------------------------------------
 *   Timer
 *-------------------------------------------------------------------------*/

TCON DEFINE 0x88 /* Timer / Cntr Control */
TCON_IT0 DEFINE 0x88.0
TCON_IE0 DEFINE 0x88.1
TCON_IT1 DEFINE 0x88.2
TCON_IE1 DEFINE 0x88.3
TCON_TR0 DEFINE 0x88.4
TCON_TF0 DEFINE 0x88.5
TCON_TR1 DEFINE 0x88.6
TCON_TF1 DEFINE 0x88.7
TMOD DEFINE 0x89 /* Timer / Cntr Mode Control */
TL0 DEFINE 0x8A /* Timer 0 Low */
TL1 DEFINE 0x8B /* Timer 1 Low */
TH0 DEFINE 0x8C /* Timer 0 High */
TH1 DEFINE 0x8D /* Timer 1 High */
T2CON DEFINE 0xC8 /* Timer 2 Control */
T2CON_CP_RL2 DEFINE 0xC8.0
T2CON_C_T2 DEFINE 0xC8.1
T2CON_TR2 DEFINE 0xC8.2
T2CON_EXEN2 DEFINE 0xC8.3
T2CON_TCLK DEFINE 0xC8.4
T2CON_RCLK DEFINE 0xC8.5
T2CON_EXF2 DEFINE 0xC8.6
T2CON_TF2 DEFINE 0xC8.7
T2MOD DEFINE 0xC9 /* Timer 2 Mode */
RCAP2L DEFINE 0xCA /* Timer 2 Reload low */
RCAP2H DEFINE 0xCB /* Timer 2 Reload High */
TL2 DEFINE 0xCC /* Timer 2 Low byte */
TH2 DEFINE 0xCD /* Timer 2 High byte */

/*-------------------------------------------------------------------------
 *   Analog to Digital Converter (ADC)
 *-------------------------------------------------------------------------*/

ASCL DEFINE 0x95 /* 8-bit Prescaler for ADC clock */
ADAT DEFINE 0x96 /* ADC Data Register */
ACON DEFINE 0x97 /* ADC Control Register */

#endif /* __IAR_SYSTEMS_ASM__*/
#endif /* IOUPSD3254A_H */
// **************************Fichier.h
// Auteur:       Vincent Chouinard
// Date:         20 juillet 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.1
//
// Description:
// *****************************************************************************
#include "_DeclarationGenerale.h" // Raccourcis de programmation & variables
#include "_DeclarationGenerale.h" // Raccourcis Linguistiques utiles
#include "ConversionKeilToIAR.h"  //
#include "CLClavier.h"            // Pour utiliser le clavier
#include "CLEcran.h"              // Pour utiliser l'�cran
#include "stdio.h"                // Pour faire des printf

//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX// **************************TypeCible.h
// Auteur:      Vincent Chouinard
// Date:        4 fevrier 2014
// Version :    1.0
//
// Compilateur: Keil 4.72.9 & IAR 8.1
// Description: Fichier pour choisir le compilateur
//
// *****************************************************************************
#ifndef TYPECIBLEH
  #define TYPECIBLEH

// *****************************************************************************
//           CHOIX DU COMPILATEUR
// *****************************************************************************
  //#define DALLAS89C450             // Uncomment to compile for Dallas DS89C450
  //#define UPSD3254A                // Uncomment to compile for Dallas UPSD3254A

// *****************************************************************************
//           DEFINITION DES REGISTRES DU CPU CHOISI
// *****************************************************************************
#ifdef DALLAS89C450
   #include "ioDS89C450.h"  // I/O access for DS89C450
#endif

#ifdef UPSD3254A
   #include "iouPSD3254A.h" // I/O access for UPSD3254A
#endif

#endif //TYPECIBLEH
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX// ************************** FICHIER: ConversionKeilToIAR.h
//
//  DEFINITION POUR CONVERTIR DU COMPILATEUR KEIL
//  VERS LE COMPILATEUR IAR
//
//  Application realisee avec IAR C++ 8.10
//
//  Definition des fonctions de la classe CLMaison.
//
//  AUTEUR : DANIEL BRETON
//  DATE CREATION :    2012-12-20       VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
// ************************************************************************

#include "_TypeCible.h"

#ifndef CONVERSIONKEILTOIARH
  #define CONVERSIONKEILTOIARH

// *****************************************************************************
//
// DEFINITION DES  MODELES DE MEMOIRE
//
// *****************************************************************************

#define data  __data
#define xdata __xdata
#define code  __code


// *****************************************************************************
#ifdef DALLAS89C450

// Interruption activation
  #define EA            IE_bit.EA
  #define ES            IE_bit.ES0
  #define ES2           IE_bit.ES1
  #define EX0           IE_bit.EX0

// Interruption priorite
  #define LPX0          IP0_bit.LPX0
  #define MPX0          IP1_bit.MPX0

  #define LPS           IP0_bit.LPS0
  #define MPS           IP1_bit.MPS0
  #define LPS2          IP0_bit.LPS1
  #define MPS2          IP1_bit.MPS1

// Interruption niveau activite.
  #define IT0           TCON_bit.IT0
  #define TR1           TCON_bit.TR1

  #define TCLK2         T2CON_bit.TCKL
  #define TRCLK2        T2CON_bit.RCLK
  #define TR2           T2CON_bit.TR2

  #define T2MOD_DCEN    T2MOD_bit.DCEN
//
  #define SMOD          PCON_bit.SMOD_0
  #define SMOD2         WDCON_bit.SMOD_1

  #define SCON          SCON0
  #define SBUF          SBUF0
  #define RI_0          SCON0_bit.RI_0
  #define TI_0          SCON0_bit.TI_0

  #define SCON2         SCON1
  #define SBUF2         SBUF1
  #define RI_2          SCON1_bit.RI_1
  #define TI_2          SCON1_bit.TI_1

  #define SM0_0         SCON0_bit.SM0_FE_0
  #define SM1_0         SCON0_bit.SM1_0
  #define SM2_0         SCON0_bit.SM2_0
  #define REN_0         SCON0_bit.REN_0

  #define SM0_2         SCON1_bit.SM0_FE_1
  #define SM1_2         SCON1_bit.SM1_1
  #define SM2_2         SCON1_bit.SM2_1
  #define REN_2         SCON1_bit.REN_1


  #define P1_0          P1_bit.P10_T2          // Port 1.0
  #define P1_1          P1_bit.P11_T2EX        // Port 1.1
  #define P1_2          P1_bit.P12_RXD1        // Port 1.2
  #define P1_3          P1_bit.P13_TXD1        // Port 1.3
  #define P1_4          P1_bit.P14_INT2        // Port 1.4
  #define P1_5          P1_bit.P15_INT3        // Port 1.5
  #define P1_6          P1_bit.P16_INT4        // Port 1.6
  #define P1_7          P1_bit.P17_INT5        // Port 1.7


  #define P3_0          P3_bit.P30_RXD0        // Port 3.0
  #define P3_1          P3_bit.P31_TXD0        // Port 3.1
  #define P3_2          P3_bit.P32_INT0        // Port 3.2
  #define P3_3          P3_bit.P33_INT1        // Port 3.3
  #define P3_4          P3_bit.P34_T0          // Port 3.4
  #define P3_5          P3_bit.P35_T1          // Port 3.5
  #define P3_6          P3_bit.P36_WR          // Port 3.6
  #define P3_7          P3_bit.P37_RD          // Port 3.7



#endif // DALLAS89C450
// *****************************************************************************

// *****************************************************************************
#ifdef UPSD3254A
// Interruption activation
  #define EA            IE_bit.EA
  #define ES            IE_bit.ES
  #define ES2           IEA_bit.ES2
  #define EX0           IE_bit.EX0

// Interruption priorite
  #define PX0           IP_bit.PX0
  #define PS            IP_bit.PS
  #define PS2           IPA_bit.PS2

// Interruption niveau activite.
  #define IT0           TCON_bit.IT0
  #define TR1           TCON_bit.TR1

  #define TCLK2         T2CON_bit.TCKL
  #define TRCLK2        T2CON_bit.RCLK
  #define TR2           T2CON_bit.TR2

  #define T2MOD_DCEN    T2MOD_bit.DCEN


  #define SMOD          PCON_bit.SMOD
  #define SMOD2         PCON_bit.SMOD1


 // #define ES0 IE_bit.ES

  #define RI_0          SCON_bit.RI
  #define TI_0          SCON_bit.TI
  #define SM0_0         SCON_bit.SM0
  #define SM1_0         SCON_bit.SM1
  #define SM2_0         SCON_bit.SM2
  #define REN_0         SCON_bit.REN

  #define TI_2          SCON2_bit.TI
  #define RI_2          SCON2_bit.RI
  #define SM0_2         SCON2_bit.SM0
  #define SM1_2         SCON2_bit.SM1
  #define SM2_2         SCON2_bit.SM2
  #define REN_2         SCON2_bit.REN

  #define WATCHDOG_OFF WDKEY = 0x55; // Disable watchdog.

  #define P1_0          P1_bit.P10        // Port 1.0
  #define P1_1          P1_bit.P11        // Port 1.1
  #define P1_2          P1_bit.P12        // Port 1.2
  #define P1_3          P1_bit.P13        // Port 1.3
  #define P1_4          P1_bit.P14        // Port 1.4
  #define P1_5          P1_bit.P15        // Port 1.5
  #define P1_6          P1_bit.P16        // Port 1.6
  #define P1_7          P1_bit.P17        // Port 1.7

  #define P3_0          P3_bit.P30        // Port 3.0
  #define P3_1          P3_bit.P31        // Port 3.1
  #define P3_2          P3_bit.P32        // Port 3.2
  #define P3_3          P3_bit.P33        // Port 3.3
  #define P3_4          P3_bit.P34        // Port 3.4
  #define P3_5          P3_bit.P35        // Port 3.5
  #define P3_6          P3_bit.P36        // Port 3.6
  #define P3_7          P3_bit.P37        // Port 3.7

  #define P4_0          P4_bit.P40        // Port 4.0
  #define P4_1          P4_bit.P41        // Port 4.1
  #define P4_2          P4_bit.P42        // Port 4.2
  #define P4_3          P4_bit.P43        // Port 4.3
  #define P4_4          P4_bit.P44        // Port 4.4
  #define P4_5          P4_bit.P45        // Port 4.5
  #define P4_6          P4_bit.P46        // Port 4.6
  #define P4_7          P4_bit.P47        // Port 4.7


#endif // UPSD3254A
// *****************************************************************************

#endif // CONVERSIONKEILTOIARH
// ***************** FICHIER: _DeclarationGenerale.h
//
//  DEFINITION GENERALE POUR UN PROJET
//
//  Application realisee avec Keil 4.72.9 && IAR 8.1
//
//  AUTEUR : DANIEL BRETON
//  DATE CREATION :    4 septembre 2013      VERSION: 1.2
//  DATE MODIFICATION: 23 janvier 2014
//                        ---> Ajout de TypeDEF
//                     6 FEVRIER 2014
//                        ---> Ajout de structures & de headers pour IAR 8.1
// ****************************************************************************
//                           LES INCLUDES
// ****************************************************************************
#include "ConversionKeilToIAR.h"     // Conversion KEIL <--> IAR
#include "TypeCible.h"               // Selection du CPU

#ifndef DECLARATIONGENERALEH
  #define DECLARATIONGENERALEH
// ****************************************************************************
//                            DEFINITION DE MOTS CLES
// ****************************************************************************
#define ACTIF   1
#define INACTIF 0

#define ON      1
#define OFF     0

#define VRAI    1
#define FAUX    0

#define HIGH    1
#define LOW     0

#define ACK     0
#define NOACK   1

#define TRUE    1
#define FALSE   0

#define COMPLET   1
#define INCOMPLET 0

// ****************************************************************************
//                            VARIABLES SHORTCUTS
// ****************************************************************************
#ifndef NULL
  #define NULL 0
#endif

typedef float              F;
typedef signed long        L;
typedef signed char        C;
typedef unsigned  long     UL;
typedef unsigned char      UC;
typedef unsigned int       UI;
typedef signed short int   SI;
typedef unsigned short int USI;
typedef signed char        INT8;
typedef unsigned char      UINT8;
typedef unsigned short int UINT16;
typedef signed long        INT32;
typedef unsigned long int  UINT32;
typedef void               VOID;

#define BARGRAPH1 0xFA00  // Adresses des composantes sur la carte binaire.
#define BARGRAPH2 0xFB00
#define DIPSW1    0xFA00
#define DIPSW2    0xFB00
#define SEGMENT1  0xFD00
#define SEGMENT2  0xFC00

// ****************************************************************************
//                            DEFINITION DES STRUCTURES
// ****************************************************************************
struct STTemps
 {
   UC ucSeconde;
   UC ucMinute;
   UC ucHeure;
 };

struct STChampBit
 {
   UC bBit0 : 1;
   UC bBit1 : 1;
   UC bBit2 : 1;
   UC bBit3 : 1;
   UC bBit4 : 1;
   UC bBit5 : 1;
   UC bBit6 : 1;
   UC bBit7 : 1;
 };

struct STMot
 {
   UC ucPetitMot : 4;
   UC ucGrandMot : 4;
 };

union UNOctetBit
 {
   struct STMot      stMot;
   struct STChampBit stChampBit;
   UC ucOctet;
 };

struct STDoubleOctet
 {
   UC ucOctet1;
   UC ucOctet2;
 };

union UNEntierOctet
 {
   struct STDoubleOctet stDoubleOctet;
   USI uiEntier;
 };

struct STQuadOctet
 {
   UC ucOctet1;
   UC ucOctet2;
   UC ucOctet3;
   UC ucOctet4;
 };

union UNLongOctet
 {
   struct STQuadOctet stQuadOctet;
   UL ulLong;
 };
#endif
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX


// ************************** FICHIER: _TYPECIBLE.H
//
//  Application realisee avec IAR C++ 8.10
//
//  Fichier pour selectionner la CIBLE et pour inclure
//  le fichier de conversion des d�finitions des registres SFR.
//
//  AUTEUR : DANIEL BRETON
//  DATE CREATION :    2013-01-23       VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
// ************************************************************************
#ifndef TYPECIBLEH
  #define TYPECIBLEH

#define DALLAS89C450
//  #define UPSD3254A

// ********************************************************************
//  Fichier de definition des registres en fonction de la CIBLE.
//
  #ifdef DALLAS89C450
    #include <ioDS89C450.h>
  #endif


  #ifdef UPSD3254A
    #include <ioUPSD3254A.h>
  #endif
//
// ********************************************************************
#endif
\end{lstlisting}