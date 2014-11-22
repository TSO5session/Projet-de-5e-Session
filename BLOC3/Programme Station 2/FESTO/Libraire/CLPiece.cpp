// ***************** FICHIER:CLPiece.cpp
//
//  Description:Ce fichier contient la definition des differentes fonction 
//              pour controler les pieces
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
#include "CLPiece.h"



//***********************CLPiece(void)
//
//Description:Ce constructeur met l addresse de la piece a 0xFA00 par defaut
//            lors de la creation d un objet 
//
// Nom:CLPiece :: CLPiece(void)
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
CLPiece :: CLPiece(void)   //Constructeur defaut
{
  usiAdresseMaison = 0xFA00;//Adresse par defaut 
}

//***********************CLPiece(USI usiAddresse
//
//Description:Ce constructeur met l addresse de la piece a l adresse passer
//            en parametre.
//
// Nom:CLPiece :: CLPiece(USI usiAddresse
//           
// PARAMETRE D'ENTREE: usiAddresse : Adresse choisit en fonction du systeme
//                                   utiliser avec le simulateur de maison.
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
CLPiece :: CLPiece(USI usiAddresse)//Constructeur initialisateur
{
 usiAdresseMaison = usiAddresse;//Adresse de la piece est celle que l on choisit
}

//***********************~CLPiece(void)
//
//Description:Ce constructeur met l addresse de la piece a l adresse passer
//            en parametre.
//
// Nom:CLPiece :: ~CLPiece(void)
//           
// PARAMETRE D'ENTREE:  -
//                        
//                  
// 
//
// PARAMETRE DE SORTIE: -             
//
//    
// Membre utilise: vSetLumiere();
//
//
// DATE DE CREATION: 10 octobre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************
CLPiece :: ~CLPiece(void)//destructeur qui reinitialise la piece
{
  vSetLumiere(0 , 0xFA00,0x00);
}


//***********************fEtatTemperature
//
//Description:Cette fonction permet de lire la temperature de la piece.
//            
//
// Nom:CLPiece :: fEtatTemperature(void)
//           
// PARAMETRE D'ENTREE: -
//                        
//                  
// 
//
// PARAMETRE DE SORTIE: fTemperature             
//
//    
// Membre utilise: vLirePiece();
//                 unPiece.stPiece.ucTemperature;
//                 unPiece.stPiece.ucTemperaturePrecis
//
//
//
// DATE DE CREATION: 10 octobre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************
float CLPiece :: fEtatTemperature(void)
{
  float fTemperature; 
  
  vLirePiece(usiAdresseMaison);//Lit A l adresse de la piece
  fTemperature = (float)unPiece.stPiece.ucTemperature;//Temperature lu
  if(unPiece.stPiece.ucTemperaturePrecis == 1)// Si LSB a 1
  {
    fTemperature = fTemperature + 0,5;       //Ajoute 0,5 pour plus de pecision
  }
  else
  {
    fTemperature = fTemperature + 0,0;       //Sinon ajoute rien
  }
  return(fTemperature + 15);                // plus 15 car c est la reference
}


//***********************ucEtatChauffage
//
//Description:Cette fonction permet de lire l etat ON ou OFF du chauffage dans
//            une des pieces de la maison
//
// Nom:CLPiece :: ucEtatChauffage(void)
//           
// PARAMETRE D'ENTREE:  -
//                        
//                  
// 
//
// PARAMETRE DE SORTIE: unPiece.stPiece.ucEtatChauffage            
//
//    
// Membre utilise: vLirePiece(usiAdresseMaison)
//                 unPiece.stPiece.ucEtatChauffage
//
//
// DATE DE CREATION: 10 octobre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************
UC CLPiece :: ucEtatChauffage(void)
{
  vLirePiece(usiAdresseMaison);
  return(unPiece.stPiece.ucEtatChauffage);
}



//***********************ucEtatLumiere
//
//Description:Cette fonction permet de lire l etat ON ou OFF de la lumiere dans
//            une des pieces de la maison
//
// Nom:CLPiece :: ucEtatLumiere(void)
//           
// PARAMETRE D'ENTREE: -
//                        
//                  
// 
//
// PARAMETRE DE SORTIE: unPiece.stPiece.ucEtatLumiere            
//
//    
// Membre utilise: vLirePiece(usiAdresseMaison)
//                 unPiece.stPiece.ucEtatLumiere
//
//
// DATE DE CREATION: 10 octobre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************
UC CLPiece :: ucEtatLumiere(void)
{
  vLirePiece(usiAdresseMaison);
  return(unPiece.stPiece.ucEtatLumiere);
}


//***********************vSetLumiere
//
//Description:Cette fonction permet d allumer ou d eteindre les lumieres sans
//            toucher au chauffage.
//
// Nom:CLPiece :: vSetLumiere(UC ucLumiere,USI usiAdresseConsigne, UC ucPiece)
//           
// PARAMETRE D'ENTREE: ucLumiere: Etat ON ou OFF
//                     usiAdresseConsigne: adresseou se situe la consigne 
//                     ucPiece:0x00 = Piece 1
//                             0x01 = Piece 2
//                             0x10 = Piece 3
//                             0x11 = Piece 4
// 
//
// PARAMETRE DE SORTIE: -             
//
//    
// Membre utilise: fGetTemperatureConsigne(usiAdresseConsigne,ucPiece)
//                 Va lire la temperature de consigne
//
//                 unPiece.stPiece.ucEtatChauffage
//                 unPiece.stPiece.ucEtatLumiere
//                 unPiece.stPiece.ucTemperaturePrecis
//                 unPiece.stPiece.ucTemperature
//                 ucTemperatureHexa
//                 vEcrirePiece(usiAdresseMaison);
//
//
// DATE DE CREATION: 10 octobre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************
void CLPiece :: vSetLumiere(UC ucLumiere,USI usiAdresseConsigne, UC ucPiece)
{
  
  fGetTemperatureConsigne(usiAdresseConsigne,ucPiece);
  unPiece.stPiece.ucEtatChauffage = 0;
  unPiece.stPiece.ucEtatLumiere = ucLumiere;
  unPiece.stPiece.ucTemperaturePrecis = ucTemperatureHexa & 0x01;
  unPiece.stPiece.ucTemperature = ucTemperatureHexa & 0x3C;
  vEcrirePiece(usiAdresseMaison);

}

//***********************fGetTemperatureConsigne
//
//Description:Cette fonction permet de lire la temperature de consigne
//            
//
// Nom:CLPiece :: fGetTemperatureConsigne(USI usiAdresseConsigne, UC ucPiece)
//           
// PARAMETRE D'ENTREE: usiAdresseConsigne: adresse ou se situe la consigne 
//                     ucPiece:0x00 = Piece 1
//                             0x01 = Piece 2
//                             0x10 = Piece 3
//                             0x11 = Piece 4
// 
//
// PARAMETRE DE SORTIE: fTemperature             
//
//    
// Membre utilise: unPiece.stPiece.ucEtatChauffage
//                 unPiece.stPiece.ucEtatLumiere
//                 vEcrirePiece( usiAdresseConsigne)
//                 ucTemperatureHexa
//                 vLirePiece(usiAdresseConsigne)
//                 unPiece.stPiece.ucTemperature
//                 unPiece.stPiece.ucTemperaturePrecis
//
//
// DATE DE CREATION: 10 octobre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************
float CLPiece :: fGetTemperatureConsigne(USI usiAdresseConsigne, UC ucPiece)
{
  float fTemperature;
  
  unPiece.stPiece.ucEtatChauffage = ucPiece & 0x01; 
  unPiece.stPiece.ucEtatLumiere = ucPiece & 0x10;
  vEcrirePiece( usiAdresseConsigne);
  
  
  vLirePiece(usiAdresseConsigne);
  ucTemperatureHexa = (unPiece.stPiece.ucTemperature << 1) + 
                      (unPiece.stPiece.ucTemperaturePrecis);
  
  fTemperature = (float)unPiece.stPiece.ucTemperature;
  if(unPiece.stPiece.ucTemperaturePrecis == 1)
  {
    fTemperature = fTemperature + 0,5;
  }
  else
  {
    fTemperature = fTemperature + 0,0;
  }
  return(fTemperature + 15);

}


//***********************vLirePiece
//
//Description:Cette fonction permet de lire l etat de la piece
//            
//
// Nom:CLPiece :: vLirePiece(USI usiAdresse)
//           
// PARAMETRE D'ENTREE: usiAddresse
//                        
//                  
// 
//
// PARAMETRE DE SORTIE: -             
//
//    
// Membre utilise: ucIn(usiAdresse)
//                 unPiece.ucPiece
//                 
//
//
// DATE DE CREATION: 10 octobre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************
void CLPiece :: vLirePiece(USI usiAdresse)
{

  unPiece.ucPiece = ucIn(usiAdresse); // Lecture direct sur le materiel
  for(unsigned int i = 0; i<60000;i++);

}


//***********************vEcrirePiece
//
//Description:Cette fonction permet d ecrire l etat de la piece.
//            
//
// Nom:CLPiece :: vEcrirePiece(USI usiAdresse)
//           
// PARAMETRE D'ENTREE: usiAddresse
//                        
//                  
// 
//
// PARAMETRE DE SORTIE: -             
//
//    
// Membre utilise: vOut();
//                 unPiece.ucPiece
//                 
//
//
// DATE DE CREATION: 10 octobre 2013    AUTEUR: Gabriel Fortin-B
// DATE DE MODIFICATION:	
//*****************************************************************************
void CLPiece :: vEcrirePiece(USI usiAdresse)
{
  vOut(usiAdresse,unPiece.ucPiece);// Ecriture direct sur le materiel
  for(unsigned int i = 0; i<60000;i++);

}

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@