// ***************** FICHIER:CLHorloge.cpp
//
//  Description: Contient les definitions de fonction pour communiquer avec 
//               l horloge du simulateur de maison
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
#include "CLHorloge.h"




    
    
//***********************CLHorloge(void)
//
//Description:Ce constructeur met l addresse de l horlogr a 0xFC00 par defaut
//            lors de la creation d un objet 
//
// Nom:CLPiece :: CLHorloge(void)
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
CLHorloge :: CLHorloge(void)
{
   usiAdresseHorloge = 0xFC00;

}

//***********************CLHorloge(USI usiAdresse)
//
//Description:Ce constructeur met l addresse de l horloge choisit 
//            par utilisateur lors de la creation d un objet 
//
// Nom:CLPiece :: CLHorloge(void)
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
CLHorloge :: CLHorloge(USI usiAdresse)
{

  usiAdresseHorloge = usiAdresse;
  
}



//***********************vSetHeureHMS
//
//Description:Cette fonction permet de choisir l heure de l horloge 
//            du simulateur de maison
//           
//
// Nom:CLPiece :: vSetHeureHMS(UC ucHeure, UC ucMinute, UC ucSeconde)
//           
// PARAMETRE D'ENTREE: ucHeure
//                     ucMinute
//                     ucSeconde
//
// PARAMETRE DE SORTIE: -             
//
//    
// Membre utilise: stHorlogeHMS.ucHeure
//                 stHorlogeHMS.ucMinute
//                 stHorlogeHMS.ucSeconde
//                 vWriteTime()
//
//
// DATE DE CREATION: 10 octobre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************
void CLHorloge :: vSetHeureHMS(UC ucHeure, UC ucMinute, UC ucSeconde)
{
  stHorlogeHMS.ucHeure = ucHeure;
  stHorlogeHMS.ucMinute = ucMinute;
  stHorlogeHMS.ucSeconde = ucSeconde;
  
  vWriteTime();
}



//*********************** stpGetHeureHMS
//
//Description:Ce constructeur met l addresse de l horloge choisit 
//            par utilisateur lors de la creation d un objet 
//
// Nom:struct  STHorlogeHMS * CLHorloge :: stpGetHeureHMS(void)
//           
// PARAMETRE D'ENTREE: -
//                  
// 
//
// PARAMETRE DE SORTIE: stpHorlogeHMS            
//
//    
// Membre utilise:  stHorlogeHMS
//                  vReadTime()
//
//
// DATE DE CREATION: 10 octobre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************

struct  STHorlogeHMS * CLHorloge :: stpGetHeureHMS(void)
{
   STHorlogeHMS *stpHorlogeHMS;
   stpHorlogeHMS = &stHorlogeHMS;
   
   vReadTime();
   
   return(stpHorlogeHMS);
}







//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@