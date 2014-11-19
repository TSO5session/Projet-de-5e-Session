// ***************** FICHIER:CLHorloge1307.cpp
//
//  Description: Contient les definitions de fonction pour communiquer avec 
//               le materiel d une horloge 1307
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
#include "CLHorloge1307.h"
#include "CLI2CPort.h"



//***********************CLHorloge1307(void)
//
//Description:Ce constructeur met l addresse de l horlogr a 0xFC00 par defaut
//            lors de la creation d un objet 
//
// Nom:CLPiece :: CLHorloge1307(void)
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
CLHorloge1307 :: CLHorloge1307(void)
{
  usiAdresseHorloge = 0xFC00;
}

//***********************CLHorloge1307(USI usiAdresse)
//
//Description:Ce constructeur met l addresse de l horlogr addresse choisit 
//            lors de la creation d un objet 
//
// Nom:CLPiece :: CLHorloge1307(USI usiAdresse)
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
CLHorloge1307 :: CLHorloge1307(USI usiAdresse)
{
  
  usiAdresseHorloge = usiAdresse;

}

//***********************~CLHorloge1307(void)
//
//Description:Destructeur ne fait rien
//           
//
// Nom:CLPiece :: ~CLHorloge1307(void)
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
CLHorloge1307 :: ~CLHorloge1307(void)
{


}

//***********************vReadTime(void)
//
//Description:Cette fonction permet de lire Heure HMS d une horloge 1307
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
void CLHorloge1307 :: vReadTime(void)
{
  stHorlogeHMS.ucSeconde =  ucI2CLireDonnee(0xD0, 0x00,ADR8BIT);//Lit seconde
                                                                  // dans rtc
  stHorlogeHMS.ucMinute  =  ucI2CLireDonnee(0xD0, 0x01,ADR8BIT);// lit minute
                                                                  //dans rtc
  stHorlogeHMS.ucHeure   =  ucI2CLireDonnee(0xD0, 0x02,ADR8BIT);//lit heure
                                                                  //dans rtc

}

//***********************vWriteTime(void)
//
//Description:Cette fonction permet d ecrire l Heure HMS d une horloge 1307
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
void CLHorloge1307 :: vWriteTime(void)
{
    vI2CEcrireDonnee(0xD0,0x00,ADR8BIT,stHorlogeHMS.ucSeconde);//Ecrit seconde
                                                                //dans rtc 
    vI2CEcrireDonnee(0xD0,0x01,ADR8BIT,stHorlogeHMS.ucMinute); //Ecrit Minute
                                                                //dans rtc
    vI2CEcrireDonnee(0xD0,0x02,ADR8BIT,stHorlogeHMS.ucHeure);  //Ecrit Heure
                                                                //dans rtc

  
}

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@