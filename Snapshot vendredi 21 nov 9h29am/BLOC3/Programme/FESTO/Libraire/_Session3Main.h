


// ************************** FICHIER: ProjetSessionCinqMain.H
//
//  Application realisee avec IAR C++ 8.10
//
//  Definition des fonctions des fonctions d'entree/sortie.
//
//  AUTEUR : DANIEL BRETON
//  DATE CREATION :    2012-12-20		 VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
// ****************************************************************************
//****************************************************************************
//
//                                    DALLAS   DS89C450
//                              ------------------------------
//   Signal  ---------------- 1 | P1.0 - T2              Vcc | 40
//                            2 | P1.1 - T2 EX    AD0 - P0.0 | 39
//                            3 | P1.2            AD1 - P0.1 | 38
//                            4 | P1.3            AD2 - P0.2 | 37
//                            5 | P1.4 - /SS      AD3 - P0.3 | 36
//                            6 | P1.5 - MISO     AD4 - P0.4 | 35
//                            7 | P1.6 - MOSI     AD5 - P0.5 | 34
//                            8 | P1.7 - SClk     AD6 - P0.6 | 33
//                            9 | RESET           AD7 - P0.7 | 32
//              RX Data------10 | P3.0 - RX              /EA | 31
//              Tx Data------11 | P3.1 - TX              ALE | 30
//   Gnd--Switch ACCEPTE-----12 | P3.2 - /INT0         /PSEN | 29
//   Gnd--Switch SELECT------13 | P3.3 - /INT1    A15 - P2.7 | 28
//   Gnd--Switch RETOUR------14 | P3.4 - T0       A14 - P2.6 | 27
//         5V--Led--R330ohm--15 | P3.5 - T1       A13 - P2.5 | 26
//                           16 | P3.6 - /WR      A12 - P2.4 | 25
//                           17 | P3.7 - /RD      A11 - P2.3 | 24
//                           18 | XTAL2           A10 - P2.2 | 23
//                           19 | XTAL1            A9 - P2.1 | 22
//                           20 | GND              A8 - P2.0 | 21
//                              ------------------------------
//
//****************************************************************************

// *****************************************************************************
//
// FICHIER D'INCLUSION POUR LE PROGRAMME PRINCIPAL EN FONCTION DE COMPILATION
// CONDITIONNELLE DE L'APPLICATION COMPILEE.
//
// *****************************************************************************

#ifdef TEST_SECTION
  #include "CLTest.H"
//  #define ACK                  0U
//  #define NOACK                1U
#endif


#ifdef ECRAN_SECTION
  #include "CLEcran.h"
#endif

#ifdef INOUT_SECTION
  #include "CLInOutBase.h"
#endif

#ifdef MAISON_SECTION
  #include "CLMaison.h"
#endif

#ifdef I2C_SECTION
  #include "CLI2CBase.h"
  #include "CLI2CPort.h"
  #include "CLIOPcf8574.h"
// include "CLI2CReg.h"
#endif 

#ifdef HORLOGE_1307_SECTION
  #include "CLHorloge1307.h"
#endif 

#ifdef COMM_SECTION
  #include "CLCommunic.h" 
#endif


#include "CLSPI.h"
#include "CLADDA.h"
// include "CLDelai.h"
#include "CLTLV2544.h"
#include "CLMCP2515.h"
#include "CLDAC7554.h"


// *****************************************************************************
//
// DEFINITION DES CLASSES POUR LE PROGRAMME PRINCIPAL EN FONCTION DE COMPILATION
// CONDITIONNELLE DE L'APPLICATION COMPILEE.
//
// *****************************************************************************

#ifdef TEST_SECTION
  class CLTest clTest;
#endif



// L'extension carte binaire redirige les CS du DALLLAS 89C450
// vers les adresses de la carte du simulateur binaire.
// PIECE1   0xFA00 vers 0x0300
// PIECE2   0xFA01 vers 0x0301
//
// PIECE3   0xFB00 vers 0x0304
// PIECE4   0xFB01 vers 0x0305
//
// HORLOGE  0xFC00 vers 0x0308 Heure
// HORLOGE  0xFC01 vers 0x0309 Minute

// HORLOGE  0xFD00 vers 0x030C Seconde
// CONSIGNE 0XFD01 vers 0x030D Consigne

// *****************************************************************************
//
// CONFIGURATION DANS CAPS
//     CS 0X300    Pa0.ECS.pa0  : FA00  FAFF    CS2    READ/WRITE   ACTIF LOW
//     CS 0X304    Pa1.ECS.pa1  : FB00  FBFF    CS3    READ/WRITE   ACTIF LOW
//     CS 0X308    Pa2.ECS.pa2  : FC00  FCFF    CS4    READ/WRITE   ACTIF LOW
//     CS 0X30C    Pa3.ECS.pa3  : FD00  FDFF    CS5    READ/WRITE   ACTIF HIGH

//     ECRAN GRAPJ Pa3.ECS.pa3  : FD00  FDFF    CS5    READ/WRITE   ACTIF HIGH
//     ECRAN TEXTE Pc7.ECS.pc7  : F800  F8FF    CS0    READ/WRITE   ACTIF HIGH
//     CALVIER     Pc2.ECS.pc2  : F900  F9FF    CS1    READ/WRITE   ACTIF LOW
//
// *****************************************************************************

#define BARGRAPHE_HAUT_0X300       0XFA00
#define INTERRUPT_GAUCHE_0X300     0XFA00

#define BARGRAPHE_BAS_0X304        0XFB00
#define INTERRUPT_DROIT_0X304      0XFB00

#define SEGMENT_GAUCHE_0X308       0XFC00

#define SEGMENT_DROIT_0X30C        0XFD00


void vInit_CPU (void);
void vDelais(UINT16 usiTemps);


/*
struct STChamp
{
UC b4BitBas  : 4;
UC b4BitHaut : 4;
};

union UNOctet
{
struct STChamp stChamp;
UC ucOctet;
};
*/




// ****************************************************************************


