//**********************  Fichier: CLCommunic.cpp
//  Description : Fonctions necessaire pour communiquer avec le port serie:
//
//
//CLCommunic()                                         Constructeur par defaut
//CLCommunic(UC ucLongBuf, UC ucLongTrame, UI uiBaud)  Construct initialisateur
//~CLCommunic()                                        Destructeur
//
//UC ucInitLongTrame(UC ucLong)               Pour initialiser longueur trame
//UC static ucLireNbCaractRecu()              Fct pour lire nombre de caractere recu
//UC ucLireEtatTrame()                        Fct pour lire l'etat de la trame
//char *ucpLireTrame()                        Fct qui retourne adresse du debut lecture
//vend(UC ucCar)                              Fct pour transmettre un caractere
//SendNumber(UI uiChiffreAAfficher)           Fct pour transmettre un chiffre
//SendString(char const *ucpMessage)          Fct pour transmettre chaine de caractere
//void vInitBaudRate(UI uiBaud)               Fct pour intialiser le baudrate et timer
//__interrupt static void vInteruptSerial();  Fct pour recevoir un caractere
//UC ucValideTrame()                          Fct pour valider une trame
//
//  Composition : aucune
//  Heritage    : aucun
//
//  Programmeur : Vincent Chouinard
//  Cours       : 247-436
//
//  Date        : 10 avril 2014
//                                                                           //
//  Compilateur : IAR 8.1
//                                                                           //
//  Modification:                                                            //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////
#include "CLCommunicUpsdPort1.h"             //inclue CLCommunic.h.
#include "ConversionKeilToIAR.h"

 ///// Initialise les variables statiques.
UC    CLCommunic :: ucEtatTrame       = INCOMPLET      ; // Trame incomplete.
UC    CLCommunic :: ucNbCaractRecu    = 0              ; // Nombre de caractere recu = 0
UC    CLCommunic :: ucLongueurTrame   = LONGUEURTRAME  ; // Initialise les longueur du
UC    CLCommunic :: ucLongueurTampon  = LONGUEURTAMPON ; // buffer et trame.
UC    CLCommunic :: ucCaractereRecu   = NULL           ;
UC    CLCommunic :: ucEtatReception   = INACTIF        ;
char *CLCommunic :: cpDebutTrame      = NULL           ; // Initialise lse pointeur a NULL.
char *CLCommunic :: cpFinTrame        = NULL           ;
char *CLCommunic :: cptrEcriture      = NULL           ;
char *CLCommunic :: cptrLecture       = NULL           ;
char *CLCommunic :: cTabCaractereRecu = NULL           ;


//*****************************************************************************
// Nom de la fct       : CLCommunic(void)
// Description         : Constructeur qui permet d'initialiser par defaut le port
//                     : serie du micro controleur a  9600 bdr, un tampon de 12
//                     : et une trame a 4 characteres. Initialise les differents
//                     : pointeurs au debut et la la fin du tampon.
//
// INCLUDE             :#include "_TypeCible.h", "CLCommunic.h"
// Prototype           : CLCommunic(void);
//
//
// Parametre d'entree  : Aucune
//
// Parametre de sortie : Aucune
//
// Procedure appelees  : vInitBaudRate(),
//
// Exemple d'appel     : class CLCommunic clCommunic();
//
// Fait par            : Vincent Chouinard
// Date                : 10 avril 2014
// Revision            : A
// Modification        :
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
// Nom de la fct        : CLCommunic
// Description          : Constructeur qui permet d'initialiser  le port
//                        serie du micro controleur a  la vitesse voulue, un tampon
//                        de taille dynamique et la longueur de la trame.
//                        Initialise les differents pointeurs au debut et la la fin
//                        du tampon.
//
// INCLUDE              : #include "_TypeCible.h", "CLCommunic.h"
// Prototype            : CLCommunic(UC ucLongBuf, UC ucLongTrame, UI uiBaud);
//
//
// Parametre d'entree   : ucLongBuf pour longueur du trableau
//                        ucLongTrame pour longueur trame
//                        uiBaud pour la vitesse du port serie
//
// Parametre de sortie  : Aucune
//
// Procedure appelees   : vInitBaudRate(), ucInitLongTrame()
//
// Exemple d'appel      : class CLCommunic clCommunic();
//
// Fait par             : Vincent Chouinard
// Date                 : 10 avril 2014
// Revision             : A
// Modification         :
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
// Nom de la fct        :~CLCommunic
// Description          : Desctructeur qui libert la memoire pris par le tampon.
//
// INCLUDE              : #include "_TypeCible.h", "CLCommunic.h"
// Prototype            :~CLCommunic(void);
//
//
// Parametre d'entree   : aucun
//
// Parametre de sortie  : Aucun
//
// Procedure appelees   : aucun
//
// Exemple d'appel      :
//
// Fait par             : Vincent Chouinard
// Date                 : 10 avril 2014
// Revision             : A
// Modification         :
//*****************************************************************************
CLCommunic :: ~CLCommunic(void)
{
if(cTabCaractereRecu)              // Verification pour s'assurer que le
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
// Fait par: Vincent Chouinard
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
// Fait par: Vincent Chouinard
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
// Nom de la fct:   Send                  Fait par: Vincent Chouinard
// Date:            2 octobre 2013
// Revision :       A
// Modification :
// INCLUDE:         #include "_TypeCible.h", "CLCommunic.h"
// Prototype:       void Send(UC ucCar);
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
// Exemple d'appel: clCommunic.Send('A')
//*****************************************************************************
void CLCommunic :: Send(UC ucCar)
{
SBUF0 = ucCar;             // Envoye le caractere dans SBUF0 pour le transmetre sur TX
while(TI_0 ==0);           // Si le flag TI_0 se met a 1 (termine)
TI_0  = 0;                 // Remet le flag a 0.
}



//*****************************************************************************
// Nom de la fct:   SendString
// Description:     Transmet une chaine de caracteres sur le port serie.
//
// INCLUDE:        #include "_TypeCible.h", "CLCommunic.h"
// Prototype:      void SendString(char const *ucpMessage)
//
//
// Parametre d'entre: *ucpMessage pour chaine de caractere.
//
// Parametre de sortie: aucun
//
// Procedure appelees: Send()
//
// Exemple d'appel: clCommunic.SendString("TEST");
//
// Fait par: Vincent Chouinrd
// Date:            10 avril 2014
// Revision :       A
// Modification :
//*****************************************************************************
void CLCommunic :: SendString(char const *ucpMessage)
{
while(*ucpMessage != 0x00)          // Tant qu'on a pas atteint la fin de
  {                                 // la chaine.
   Send(*ucpMessage);     // Transmet le caractere.
   ucpMessage++;                    // Passe au caractere suivant.
  }
}

//*****************************************************************************
// Nom de la fct:   ucLireNbCaractRecu                Fait par: VIncent Chouinard
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
// Nom de la fct:   ucLireEtatTrame                  Fait par: VIncent Chouinard
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
// Nom de la fct:   *ucpLireTrame                   Fait par: Vincent Chouinard
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
// Exemple d'appel:Send('A')
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
// Nom de la fct:   vInitBaudRate                  Fait par: Vincent Chouinard
// Date:            2 octobre 2013         version base
//                  10 avril 2014          version avec uPSD.
// Revision :       B
// Modification :
// INCLUDE:         #include "_TypeCible.h", "CLCommunic.h"
// Prototype:       void vInitBaudRate(UI uiBaud);
//
// Description:     Fonction qui permet d' initialiser le port série au
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
// Nom de la fct:   vInteruptSerial                  Fait par: VIncent CHouinard
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
// Nom de la fct:   SendNumber
// Description:     Fonction qui permet transmettre  un nombre de 0 a
//                  65000 sur le port serie.
// INCLUDE:       #include "_TypeCible.h", "CLCommunic.h"
// Prototype:     void SendNumber(UI uiChiffreAAfficher);
//
//
// Parametre d'entree: uiChiffreAAfficher pour chiffre a afficher
//
// Parametre de sortie: aucun
//
// Procedure appelees: Send();
//
//
// Exemple d'appel: vLcdAffChiffre(12345)
//
// Fait par: Vincent Chouinard
// Date:            14 novembre 2013
// Revision :       A
// Modification :
//*****************************************************************************
void CLCommunic :: SendNumber(UI uiChiffreAAfficher)
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

if(ucChiffre4 != 0x30)                 // Si Dizaine de mille  = 0
  {                                    // Ne l'affiche pas
   Send(ucChiffre4);                   // Transmet les Dizaine de mille.
  }

if((ucChiffre4 != 0x30) || (ucChiffre3 != 0x30))// Si les 2 premiers chiffres
  {                                             // sont different de 0.
   Send(ucChiffre3);                            // Transmet les millier.
  }

if((ucChiffre4 != 0x30) || (ucChiffre3 != 0x30)||(ucChiffre2 != 0x30))
  {                                  // Si les 3 1er chiffres sont different
                                     // de 0?
   Send(ucChiffre2);                 // Transmet les centaines.
  }

if((ucChiffre4 != 0x30)||(ucChiffre3 != 0x30)||(ucChiffre2 != 0x30)||(ucChiffre1 != 0x30))
                                  // Si les 4 premier chiffres sont
  {                              // different de 0.
   Send(ucChiffre1);             // Transmet les dizianes.
  }
 Send(ucChiffre0);               // Transmetles unitees.
}

UC CLCommunic :: GetChar(void)
{
ucEtatReception = INACTIF;
return(ucCaractereRecu);
}

UC CLCommunic :: ucLireEtatReception(void)
{
return(ucEtatReception);            // Retourne l'etat de la trame.
}


//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX






