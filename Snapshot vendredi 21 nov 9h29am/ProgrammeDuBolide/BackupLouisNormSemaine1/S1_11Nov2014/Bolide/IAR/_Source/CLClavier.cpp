// **************************Clavier.cpp
// Auteur:      Vincent Chouinard
// Date:        17 avril 2014
// Version :    1.0
//
//
// Compilateur: IAR 8.1
//
// Description: Fichier permettant d'utiliser le clavier de l'uPSD
//
///////////////////////////////////////////////////////////////////////////////
//                     Infos relatives au montage du clavier sur le uPSD     
// Utilise un 74HC922                                                       
// 74HCC922     uPSD
//        A sur D0
//        B sur D1
//        C sur D2
//        D sur D3                                                          
//       OE sur CS1     (OutputEnable sur chip select 1)                     
//       DA sur INT0    (DataAvailible sur interrupt0)                       
///////////////////////////////////////////////////////////////////////////////
#include "CLClavier.h"            // Fichier de definitions du clavier

UC  CLClavier  :: ucDonnee;
UC  *CLClavier :: ucPtrAdresse;

//******************************************************************************
//                            LE CONSTRUCTEUR PAR DEFAUT
// *****************************************************************************
CLClavier :: CLClavier(void)           
{
   ucDonnee = '5';
   EA  = 0;      // Disable interrupt.
   IT0 = 1;      // Pour que l'interrupt se fassent sur une transition
   EA  = 1;      // Enable tout les interrupt
   EX0 = 1;      // Enable interrupt 0
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
   // ***Tableau des caracteres du clavier***
   static UC ucTableau[16] = {'1','2','3','A',
                              '4','5','6','B',
                              '7','8','9','C',
                              '*','0','#','D'};

  return(ucTableau[ucDonnee]); //Renvoie le caractere appuye
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
EA = 0;                              //Empeche l'interruption d'etre interrompue
ucPtrAdresse = (UC *)CS1;            //Initialiser pointeur sur l'adresse du 922
ucDonnee     = *ucPtrAdresse & 0x0F; //Lit la donnee du 74922
TCON_bit.IE0 = 0;                    //Re-active le flag de l'INTERRUPT0
EA  = 1;                             //Re-autorise les interruptions
}
//******************************************************************************
