// ***************** FICHIER:CLHorlogeIO.cpp
//
//  Description: Contient les definitions de fonction pour communiquer avec 
//               le materiel d une horloge
//
//  Application realisee avec IAR
//
//  AUTEUR : Gabriel Fortin-Belanger
//  DATE CREATION :    2014-02-07		 VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
//******************************************************************************
#include "CLInOutBase.h"
#include "_DeclarationGenerale.h"
#include "CLHorlogeIO.h"



//***********************CLHorlogeIO(void)
//
//Description:Ce constructeur met l addresse de l horlogr a 0xFC00 par defaut
//            lors de la creation d un objet 
//
// Nom:CLPiece :: CLHorlogeIO(void)
//           
// PARAMETRE D'ENTREE: -
//                  
// 
//
// PARAMETRE DE SORTIE: -             
//
//    
// Membre utilise:  usiAdresseHorloge
//
//
// DATE DE CREATION: 10 octobre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************
CLHorlogeIO :: CLHorlogeIO(void)
{
  usiAdresseHorloge = 0xFC00;
}

//***********************CLHorlogeIO(USI usiAdresse)
//
//Description:Ce constructeur met l addresse de l horlogr addresse choisit 
//            lors de la creation d un objet 
//
// Nom:CLPiece :: CLHorlogeIO(USI usiAdresse)
//           
// PARAMETRE D'ENTREE: usiAdresse
//                  
// 
//
// PARAMETRE DE SORTIE: -             
//
//    
// Membre utilise:  usiAdresseHorloge
//
//
// DATE DE CREATION: 10 octobre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************
CLHorlogeIO :: CLHorlogeIO(USI usiAdresse)
{
  
  usiAdresseHorloge = usiAdresse;

}

//***********************~CLHorlogeIO(void)
//
//Description:Destructeur ne fait rien
//           
//
// Nom:CLPiece :: ~CLHorlogeIO(void)
//           
// PARAMETRE D'ENTREE: -
//                  
// 
//
// PARAMETRE DE SORTIE: -             
//
//    
// Membre utilise:  -
//
//
// DATE DE CREATION: 10 octobre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************
CLHorlogeIO :: ~CLHorlogeIO(void)
{


}

//***********************vReadTime(void)
//
//Description:Cette fonction permet de lire Heure HMS d une horloge
//            
//
// Nom:CLPiece :: vReadTime(void)
//           
// PARAMETRE D'ENTREE:-
//                  
// 
//
// PARAMETRE DE SORTIE: -             
//
//    
// Membre utilise: ucIn()
//                 stHorlogeHMS.ucHeure
//                 stHorlogeHMS.ucMinute
//                 stHorlogeHMS.ucSeconde
//                 usiAdresseHorloge
//
//
// DATE DE CREATION: 10 octobre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************
void CLHorlogeIO :: vReadTime(void)
{
  stHorlogeHMS.ucHeure = ucIn(usiAdresseHorloge);
  stHorlogeHMS.ucMinute = ucIn(usiAdresseHorloge + 1);
  stHorlogeHMS.ucSeconde = ucIn(usiAdresseHorloge + 0x0100);

}

//***********************vWriteTime(void)
//
//Description:Cette fonction permet d ecrire l Heure HMS d une horloge
//            
//
// Nom:CLPiece :: vWriteTime(void)
//           
// PARAMETRE D'ENTREE:-
//                  
// 
//
// PARAMETRE DE SORTIE: -             
//
//    
// Membre utilise: ucOut()
//                 stHorlogeHMS.ucHeure
//                 stHorlogeHMS.ucMinute
//                 stHorlogeHMS.ucSeconde
//                 usiAdresseHorloge
//                 
//
//
// DATE DE CREATION: 10 octobre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************
void CLHorlogeIO :: vWriteTime(void)
{
  vOut(usiAdresseHorloge ,stHorlogeHMS.ucHeure);
  vOut(usiAdresseHorloge + 1 ,stHorlogeHMS.ucMinute);
  vOut(usiAdresseHorloge + 0x0100 ,stHorlogeHMS.ucSeconde);
  
}

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@