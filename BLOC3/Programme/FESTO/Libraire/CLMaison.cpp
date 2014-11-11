// ***************** FICHIER:CLEcran.cpp
//
//  Description: 
//  
//
//  Application realisee avec IAR
//
//  AUTEUR : Gabriel Fortin-Belanger
//  DATE CREATION :    2014-02-07		 VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
//******************************************************************************

#include "_DeclarationGenerale.h"
#include "CLMaison.h"


//***********************CLMaison(void)
//
//Description:Ce constructeur met l addresse de la maison a 0xFA00 par defaut
//            lors de la creation d un objet 
//
// Nom:CLPiece :: CLMaison(void)
//           
// PARAMETRE D'ENTREE: -
//                  
// 
//
// PARAMETRE DE SORTIE: -             
//
//    
// Membre utilise: usiAdresseMaison
//
//
// DATE DE CREATION: 10 octobre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************
CLMaison :: CLMaison(void)
{
  usiAdresseMaison = 0xFA00;

}


//***********************CLMaison(USI usiAdresse)
//
//Description:Ce constructeur met l addresse de la maison ainsi que les 4 pieces
//             et l horloge.
//
// Nom:CLPiece :: CLMaison :: CLMaison(USI usiAdresse): clPiece1(usiAdresse),
//                                     clPiece2(usiAdresse + 1),
//                                     clPiece3(usiAdresse + 0x0100) , 
//                                    clPiece4(usiAdresse + 0x0101), clHorloge()
//           
// PARAMETRE D'ENTREE: usiAdresse
//                  
// 
//
// PARAMETRE DE SORTIE: -             
//
//    
// Membre utilise: usiAdresseMaison
//                 clPiece1(usiAdresse)
//                 clPiece2(usiAdresse + 1)
//                 clPiece3(usiAdresse + 0x0100)
//                 clPiece4(usiAdresse + 0x0101)
//                 clHorloge()
//
//
// DATE DE CREATION: 10 octobre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************
CLMaison :: CLMaison(USI usiAdresse): clPiece1(usiAdresse),
                                      clPiece2(usiAdresse + 1),
                                      clPiece3(usiAdresse + 0x0100) , 
                                      clPiece4(usiAdresse + 0x0101), clHorloge()
{
  usiAdresseMaison = usiAdresse;

}

//***********************~CLMaison(void)
//
//Description:Destructeur ne fait rien
//            
//
// Nom:CLPiece :: CLMaison(void)
//           
// PARAMETRE D'ENTREE: -
//                  
// 
//
// PARAMETRE DE SORTIE: -             
//
//    
// Membre utilise: -
//
//
// DATE DE CREATION: 10 octobre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************
CLMaison :: ~CLMaison(void)
{

}

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@