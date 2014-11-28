// ************************** FICHIER: CLInOutBase.CPP  ************************
//
//  Fonctions pour les ecritures et lectures sur memoire externe
//
//  Application realisee avec IAR C++ 8.10
//
//  LIMITATION DU COMPILATEUR:
//    Impossible de faire de l'heritage multiple.
//
//  Note: on peut utiliser XAR pour creer des librairies.
//  On peut mettre les librairies dans le projets et Exclure de la compilation
//  les modules qui sont contenus dans la librairie.
//
//  AUTEUR : LOUIS-NORMAND ANG HOULE
//  DATE CREATION :    2014/02/20       VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
// *****************************************************************************

#include "CLInOutBase.h"

///////////////////////////////////////////////////////////////////////////////
// void CLInOutBase :: vOutPort(USI uiAdresse, UC ucData)
///////////////////////////////////////////////////////////////////////////////
//
// Description: 
// Fonction d'ecriture sur la memoire externe
//
// Parametres d'entrees:   
// - uiAdresse: variable utilise pour l'adressage d'une case memoire
// - ucData   : byte ecrit sur la case memoire indique
//        
// Parametres de sortie: null
//
// Appel de la fonction: vOutPort(UI uiAdresse, UC ucData);
//
// Cree le 10 octobre 2013 par Louis-Normand Ang Houle 
// 
// Modifications:   
// -
//
//
///////////////////////////////////////////////////////////////////////////////

void CLInOutBase :: vOutPort(USI uiAdresse, UC ucData)
 {
   UC xdata *ucpPointeur;         //Initialisation pointeur sur memoire externe 
   
   ucpPointeur  = (UC xdata *) uiAdresse;   //Adressage de la case memoire
   *ucpPointeur = ucData;         //Ecriture de bits sur le bus de donnees
 }

///////////////////////////////////////////////////////////////////////////////
// UC CLInOutBase :: ucInPort(USI uiAdresse)
///////////////////////////////////////////////////////////////////////////////
//
// Description: 
// Fonction de lecture sur la memoire externe
//
// Parametres d'entrees:
// - uiAdresse: variable utilise pour l'adressage d'une case memoire
//             
// Parametres de sortie: 
// - ucData   : byte lue sur la case memoire indique
//
// Appel de la fonction: ucInPort(UI uiAdresse);
//
// Cree le 10 octobre 2013 par Louis-Normand Ang Houle 
// 
// Modifications:   
// -
//
//
///////////////////////////////////////////////////////////////////////////////

UC CLInOutBase :: ucInPort(USI uiAdresse)
 {
   UC xdata *ucpPointeur;         //Initialisation pointeur sur memoire externe 
   UC ucData = 0;                 //Initialisation d'une variable de reception

   ucpPointeur = (UC xdata *)uiAdresse; //Adressage de la case memoire
   ucData      = *ucpPointeur;          //Lecture de bits sur le bus de donnees
   
   return ucData;         
 }

///////////////////////////////////////////////////////////////////////////////
// void CLInOutBase :: vOut(USI uiAdresse, UC ucData)
///////////////////////////////////////////////////////////////////////////////
//
// Description: 
// Fonction d'ecriture sur la memoire externe
//
// Parametres d'entrees:   
// - uiAdresse: variable utilise pour l'adressage d'une case memoire
// - ucData   : byte ecrit sur la case memoire indique
//        
// Parametres de sortie: null
//
// Appel de la fonction: vOut(UI uiAdresse, UC ucData);
//
// Cree le 10 octobre 2013 par Louis-Normand Ang Houle 
// 
// Modifications:   
// -
//
//
///////////////////////////////////////////////////////////////////////////////

void CLInOutBase :: vOut(USI uiAdresse, UC ucData)
 {
   vOutPort(uiAdresse, ucData); 
 }

///////////////////////////////////////////////////////////////////////////////
// void CLInOutBase :: vOut(USI uiAdresse, USI uiDonnee, UC ucTypeTransfert)
///////////////////////////////////////////////////////////////////////////////
//
// Description: 
// Fonction d'ecriture sur la memoire externe
//
// Parametres d'entrees:   
// - uiAdresse       : variable utilise pour l'adressage d'une case memoire
// - ucData          : byte ecrit sur la case memoire indique
// - ucTypeTransfert : type du transfert 
//
// Parametres de sortie: null
//
// Appel de la fonction: vOut(UI uiAdresse, UC ucData);
//
// Cree le 10 octobre 2013 par Louis-Normand Ang Houle 
// 
// Modifications:   
// -
//
//
///////////////////////////////////////////////////////////////////////////////

void CLInOutBase :: vOut(USI uiAdresse, USI uiDonnee, UC ucTypeTransfert)
 {  
   union UNEntierOctet unData;
   
   unData.uiEntier = uiDonnee;

   if(ucTypeTransfert == SAMELSB)
    {
      vOutPort(uiAdresse, unData.stDeuxOctet.ucOctet1);
      vOutPort(uiAdresse, unData.stDeuxOctet.ucOctet1);
    }
   if(ucTypeTransfert == SAMEMSB)
    {
      vOutPort(uiAdresse, unData.stDeuxOctet.ucOctet2);
      vOutPort(uiAdresse, unData.stDeuxOctet.ucOctet2);
    }
   if(ucTypeTransfert == SUITELSB)
    {
      vOutPort(uiAdresse, unData.stDeuxOctet.ucOctet1);
      vOutPort(uiAdresse, unData.stDeuxOctet.ucOctet2);
    }
   if(ucTypeTransfert == SUITEMSB)
    {
      vOutPort(uiAdresse, unData.stDeuxOctet.ucOctet2);
      vOutPort(uiAdresse, unData.stDeuxOctet.ucOctet1);
    }
 }
 
///////////////////////////////////////////////////////////////////////////////
// UC CLInOutBase :: ucIn(USI uiAdresse)
///////////////////////////////////////////////////////////////////////////////
//
// Description: 
// Fonction de lecture sur la memoire externe
//
// Parametres d'entrees:
// - uiAdresse: variable utilise pour l'adressage d'une case memoire
//             
// Parametres de sortie: 
// - ucData   : byte lue sur la case memoire indique
//
// Appel de la fonction: ucIn(UI uiAdresse);
//
// Cree le 10 octobre 2013 par Louis-Normand Ang Houle 
// 
// Modifications:   
// -
//
//
///////////////////////////////////////////////////////////////////////////////
 
UC CLInOutBase :: ucIn(USI uiAdresse)
 {
   UC ucData = 0;                 //Initialisation d'une variable de reception
   
   ucData = ucInPort(uiAdresse);  
   return ucData;         
 }

///////////////////////////////////////////////////////////////////////////////
//  UC CLInOutBase :: ucIn(USI uiAdresse, UC ucTypeTransfert)   
///////////////////////////////////////////////////////////////////////////////
//
// Description: 
// Fonction de lecture sur la memoire externe
//
// Parametres d'entrees:
// - uiAdresse: variable utilise pour l'adressage d'une case memoire
// - ucTypeTransfert : type du transfert
//             
// Parametres de sortie: 
// - ucData   : byte lue sur la case memoire indique
//
// Appel de la fonction: ucIn(UI uiAdresse);
//
// Cree le 10 octobre 2013 par Louis-Normand Ang Houle 
// 
// Modifications:   
// -
//
//
///////////////////////////////////////////////////////////////////////////////
 
UC CLInOutBase :: ucIn(USI uiAdresse, UC ucTypeTransfert)   
 {
   union UNEntierOctet unData;
   
   unData.uiEntier = 0x00;
   
   unData.stDeuxOctet.ucOctet1 = 0x00;
   unData.stDeuxOctet.ucOctet2 = 0x00;
     
   if(ucTypeTransfert == SAMELSB)
    {
      unData.stDeuxOctet.ucOctet1 = ucInPort(uiAdresse);
      unData.stDeuxOctet.ucOctet1 = ucInPort(uiAdresse);
    }
   if(ucTypeTransfert == SAMEMSB)
    {
      unData.stDeuxOctet.ucOctet2 = ucInPort(uiAdresse);
      unData.stDeuxOctet.ucOctet2 = ucInPort(uiAdresse);
    }
   if(ucTypeTransfert == SUITELSB)
    {
      unData.stDeuxOctet.ucOctet1 = ucInPort(uiAdresse);
      unData.stDeuxOctet.ucOctet2 = ucInPort(uiAdresse);  
    }
   if(ucTypeTransfert == SUITEMSB)
    {
      unData.stDeuxOctet.ucOctet2 = ucInPort(uiAdresse);
      unData.stDeuxOctet.ucOctet1 = ucInPort(uiAdresse);
    }
   
   return unData.uiEntier;         
 }
 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@