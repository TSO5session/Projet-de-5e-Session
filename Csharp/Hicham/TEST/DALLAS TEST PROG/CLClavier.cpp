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
  
ucToucheClavier = ucIn(0xF900)    ;
ucEtatClavier   = INACTIF         ;
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
