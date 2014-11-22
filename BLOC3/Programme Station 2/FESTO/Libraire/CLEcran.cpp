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

#include "CLEcran.h"
#include "CLInOutBase.h"
#include "_DeclarationGenerale.h"

//*******************************Constantes************************************
  //#define LCD_CONTROL   0xF800          //registre de controle
  #define LCD_FLAG      usiAdresseEcran + 1 //Busy Flag
  #define LCD_WR_DATA   usiAdresseEcran + 2 //Ecriture des donnees
  #define LCD_RD_DATA   usiAdresseEcran + 3 //Lecture des donnees
//******************************************************************************



//***********************CLEcran(void)
//
//Description:Constructeur par defaut initialise l ecran a l addresse  
//            0xF800.
//           
// NOM: CLEcran :: CLEcran(void)
//           
// PARAMETRE D'ENTREE: Aucun
//                   
// 
//
// PARAMETRE DE SORTIE: Aucun              
//
//    
// Membre Utilise:
//     Fonction: vLcdInit()
//     Memmbre:  usiAdresseEcran
//
// DATE DE CREATION: 10 octobre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************

  CLEcran :: CLEcran(void)                        //constructeur defaut
   {
     usiAdresseEcran = 0xF800;                    //addresse par defaut
     vLcdInit();                                  //initialise ecran
   
   }

//***********************CLEcran(void)
//
//Description:Constructeur initialisateur permet de choisir l addresse 
//            ou se situe l ecran.
//           
// NOM: CLEcran :: CLEcran(void)
//           
// PARAMETRE D'ENTREE: USI usiAdresse
//                   
// 
//
// PARAMETRE DE SORTIE: Aucun              
//
//    
// Membre Utilise:
//     Fonction: vLcdInit()
//     Memmbre:  usiAdresseEcran
//
// DATE DE CREATION: 10 octobre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************  
  CLEcran :: CLEcran(unsigned short int usiAdresse)//constructeur initialisateur
  {                                                //pour changer addresse
    usiAdresseEcran = usiAdresse;                  //Nouvel addresse          
    vLcdInit();                                    //initialise ecran
  }


//***********************~CLEcran(void)
//
//Description:Destructeur  qui efface ecran
//           
//           
// NOM: CLEcran :: ~CLEcran(void)
//           
// PARAMETRE D'ENTREE: Aucun
//                   
// 
//
// PARAMETRE DE SORTIE: Aucun              
//
//    
// Membre Utilise:
//     Fonction: vLcdClr()
//     Memmbre:  
//
// DATE DE CREATION: 10 octobre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************  
  CLEcran :: ~CLEcran(void) //destructeur 
  {
   vLcdClr();               //efface l ecran
    
  }

//***********************vLcdAffCar
//
//Description:Cette fonction permet d'afficher un caractere
// 
//           
// NOM:void CLEcran :: vLcdAffCar(UC ucCarac)
//           
// PARAMETRE D'ENTREE: ucCarac: Code ascii du caractere a entrer
//                   
// 
//
// PARAMETRE DE SORTIE: Aucun              
//
//    
// Membre Utilise:
//
// DATE DE CREATION: 10 octobre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************
  void CLEcran :: vLcdAffCar(UC ucCarac)
  {
   vLcdBusy(); 
   vOut(LCD_WR_DATA,ucCarac); //Cursor at home  
  }
  
//***********************vLcdClr
//
//Description:Cette fonction permet d'effacerl'ecran
// 
//           
// NOM:void CLEcran :: vLcdClr(void)
//           
// PARAMETRE D'ENTREE: Aucun
//                   
// 
//
// PARAMETRE DE SORTIE: Aucun              
//
//    
// Methode utilise:
//
// DATE DE CREATION: 10 octobre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************  
  void CLEcran :: vLcdClr(void)
  {
   vLcdBusy();                   //
   vOut(usiAdresseEcran, 0x01); //Clr display et retourne a adresse 0   
  } 

//***********************vLcdPoscurC0L1
//
//Description:Cette fonction permet de positionner le curseur
// 
//           
// NOM:void CLEcran :: vLcdPoscurC0L1(UC col,UC ligne)
//           
// PARAMETRE D'ENTREE: UC col: colonne de depart
//                     UC ligne: ligne de depart
// 
//
// PARAMETRE DE SORTIE: Aucun              
//
//   
// Methode utilise:
//
// DATE DE CREATION: 10 octobre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************
  void CLEcran :: vLcdPoscurC0L1(UC col,UC ligne)
  {
   switch(ligne)
    {
      case 1:                                        //SI Ligne 1
         vLcdBusy();                                 //Attendre flag baisser
         vOut(usiAdresseEcran,(0x80 |(0x00 + col)));//Bit 7=1,add ligne1 + pos       
         break;
      case 2:                                        //SI Ligne 2
         vLcdBusy();                                 //Attendre flag baisser
         vOut(usiAdresseEcran,(0x80 |(0x40 + col)));//Bit 7=1,add ligne2 + pos     
         break;
      
      case 3:                                         //SI Ligne 3
         vLcdBusy();                                  //Attendre flag baisser
         vOut(usiAdresseEcran,(0x80 |(0x14 + col)));//Bit 7=1,add ligne3 + pos        
         break;
      
      case 4:                                         //SI Ligne 4
         vLcdBusy();                                  //Attendre flag baisser
         vOut(usiAdresseEcran,(0x80 |(0x54 + col)));//Bit 7=1,add ligne4 + pos        
         break;
      
    }
  } 
  
//***********************vLcdInit
//
//Description:Cette fonction permet d'iinitialiser l'ecran LCD en mode 8 bit
//            2 lignes, metrice 5*7, curseur off, blink off 
//           
// NOM:void CLEcran :: vLcdInit(void)          
// PARAMETRE D'ENTREE:Aucun
//                   
// 
//
// PARAMETRE DE SORTIE: Aucun              
//
//    
// Membre Utilise:
//
// DATE DE CREATION: 10 octobre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************  
void CLEcran :: vLcdInit(void)
  {
    unsigned int i;         //indice pour la boucle
  
    for(i=0;i<3;i++)        //Faire 3 fois
    {
      vOut(usiAdresseEcran, 0x38);//Function set:8bit,2lignes,5*7,cureur off
      vDelaisEcran(10000);         //Delai  
    }

    vLcdBusy();  
    vOut(usiAdresseEcran, 0x38);// Display ON, cursor off, blink off
    vLcdBusy();                   //Attend la fin de l'instruction
    vOut(usiAdresseEcran, 0x0D); //Cursor shift a droite 
    vLcdBusy();                    //Attend la fin de l'instruction    
    vOut(usiAdresseEcran, 0x01); //Clr display et retourne a adresse 0
    vLcdBusy();                   //Attend la fin de l'instruction
    vOut(usiAdresseEcran, 0x06);    
    vLcdBusy(); 

  
  }

//***********************vLcdAffChaine
//
//Description:Cette fonction permet d'afficher une chaine de caractere 
// 
//           
// Nom: void CLEcran :: vLcdAffChaine(UC const *ucpMessage) 
//           
// PARAMETRE D'ENTREE:UC *ucpMessage: Pointe vers la chaine de caractere
//                     
// 
//
// PARAMETRE DE SORTIE: Aucun              
//
//    
// methode utilise:
//
// DATE DE CREATION: 16 octobre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************  
  void CLEcran :: vLcdAffChaine(char *ucpMessage)
  {
   int i = 0;
   while(ucpMessage[i]!= 0x00)      //tant que pas a fin ligne
    {
      vLcdAffCar(ucpMessage[i]); //Affiche un caractere de la chaine
      i++;                       //prochain caractere
    }   
  }

//***********************vLcdAffEcran
//
//Description:Cette fonction permet d'afficher un Ecran pre enregistre 
// 
//           
// Nom:void CLEcran :: vLcdAffEcran(UC const *ucpEcran)
//           
// PARAMETRE D'ENTREE:UC *ucpEcran: Pointe vers le tableau qui contien l ecran
//                     
// 
//
// PARAMETRE DE SORTIE: Aucun              
//
//    
// Methode utilise:
//
// DATE DE CREATION: 16 octobre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************  
  void CLEcran :: vLcdAffEcran(char *ucpEcran)
  {
   UC i;                      // indice pour la boucle
   for(i=1;i<=4;i++)          //faire pour le nombre de ligne
    {
      vLcdPoscurC0L1(0,i);    //positionne curseur
      vLcdAffChaine(ucpEcran);//Affiche la chaine
      ucpEcran = ucpEcran + 20;//deplace le pointeur
   
    }   
      
  }

 
//***********************vLcdAffCarHex
//
//Description:Cette fonction permet d'afficher un octet en hexa a l'ecran 
// 
//           
// Nom:void CLEcran :: vLcdAffCarHex(UC ucCarac)
//           
// PARAMETRE D'ENTREE:UC ucCarac:Octet Hexa a afficher
// 
//
// PARAMETRE DE SORTIE: Aucun              
//
//    
// Methode:
//
// DATE DE CREATION: 16 octobre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************

  void CLEcran :: vLcdAffCarHex(UC ucCarac)
  {
   UC ucHi;                       //Variable Partie haute 
   UC ucLo;                       //Variable Partie basse

   ucHi = (ucCarac & 0xF0) >> 4;  //isole la partie Haute
   ucLo = (ucCarac & 0x0F);       //isole la partie basse

   if(ucHi >= 0 && ucHi <= 9)     //Si partie haute est un chiffre
    {
      ucHi = ucHi + 0x30;         //Ajoute 0x30 pour Ascii
    }

   if(ucHi >= 0x0A && ucHi <= 0x0F)//Si partie haute une lettre
    {
      ucHi = ucHi + 0x37;         //Ajoute 0x37 Pour Ascii
    }
   

   if(ucLo >= 0 && ucLo <= 9)    //Si partie basse est un chiffre
    {
      ucLo = ucLo + 0x30;        //Ajoute 0x30 pour Ascii
    }

   if(ucLo >= 0x0A && ucLo <= 0x0F)//Si partie basse une lettre
    {
      ucLo = ucLo + 0x37;          //Ajoute 0x37 Pour Ascii
    }

   vLcdAffCar(ucHi);              //Affiche partie haute
   vLcdAffCar(ucLo);              //Affiche partie basse
  }

//***********************vLcdCarGen
//
//Description:Cette fonction permet de creer un caractere personalisée  
// 
//           
// Nom:void CLEcran :: vLcdCarGen(UC *ucTabCarac
//           
// PARAMETRE D'ENTREE:UC *ucTabCarac:Code du nouveau caracter 
// 
//
// PARAMETRE DE SORTIE: Aucun              
//
//    
//  Methode Utilise:
//
// DATE DE CREATION: 16 octobre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************
  void CLEcran :: vLcdCarGen(UC *ucTabCarac)
  {

   UC i;
   vLcdBusy(); 
   vOut(usiAdresseEcran,0x40);
   for(i=0;i<8;i++)
    {
      vLcdBusy(); 
      vOut(LCD_WR_DATA,ucTabCarac[i]);
    }
  }

//***********************vLcdBusy
//
//Description:Cette fonction permet d'attendre la fin d'une instruction 
//            sur l'ecran LCD en fesant du polling sur le bit busyflag
//           
//
// NOM:void CLEcran :: vLcdBusy(void)
//           
// PARAMETRE D'ENTREE:Aucun
//                   
// 
//
// PARAMETRE DE SORTIE: Aucun              
//
//    
// Membre utilise:
//
// DATE DE CREATION: 10 octobre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//***************************************************************************** 
  void CLEcran :: vLcdBusy(void)
  {
    while((ucIn(LCD_FLAG) & 0x80)); //Lit le Busy flag et ne fait rien
                                          //Tant qu'il est a 1
  }
  


//***********************vDelaisEcran
//
//Description:Cette fonction permet de faire un delais 
// 
//           
// NOM: void CLEcran :: vDelaisEcran(UINT16 usiTemps)
//            
// PARAMETRE D'ENTREE:usiTemps: Grandeur du delai
//                   
// 
//
// PARAMETRE DE SORTIE: Aucun              
//
//    
// Membre utilise:
//
// DATE DE CREATION: 10 octobre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************
void CLEcran :: vDelaisEcran(UINT16 usiTemps)
  {
    UINT16 i;   //indice pour conter le delais
    for(i=0;i<usiTemps;i++);//Boucle pour faire un delais choisi   
  }


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@