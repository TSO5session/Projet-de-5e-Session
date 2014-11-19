// ************************** FICHIER: CLVEHICULE.CPP ***********************
//
// Fonctions pour l'assemblage bolide
//
// Application realisee avec IAR C++ 8.10
//
//
// LIMITATION DU COMPILATEUR:
// Impossible de faire de l'heritage multiple.
//
// Note: on peut utiliser XAR pour creer des librairies.
// On peut mettre les librairies dans le projets et Exclure de la compilation
// les modules qui sont contenus dans la librairie.
//
// Pour Windows 7 on utilise la VMware pour programmer le upsd 3254A avec CAPS.
//
// AUTEUR : LOUIS-NORMAND ANG HOULE
// DATE CREATION : 2014/04/24 VERSION: 1.0
// DATE MODIFICATION: ****-**-**
//
// *****************************************************************************
#include "CLVehicule.h"

// Constructeur par defaut ////////////////////////////////////////////////////
CLVehicule :: CLVehicule(void) :
 LCD(0xF800)                ,
 clRoueAvantD   (R_AVANTD)  ,
 clRoueAvantG   (R_AVANTG)  ,
 clRoueArriereD (R_ARRIERED),
 clRoueArriereG (R_ARRIEREG)  
 { 
   ucMode           = MODEMANUEL;
   
   #ifdef SPI_DALLAS
      uiVitesse        = VITESSEINIT;
      uiVitesseTourne  = VITESSEINITTOURNE;
   #endif
   
   #ifdef I2C_DALLAS
      ucVitesse       = VITESSEINIT;
      ucVitesseTourne = VITESSEINITTOURNE; 
   #endif
 }

// Constructeur initialisateur ////////////////////////////////////////////////
CLVehicule :: CLVehicule(USI uiVit, USI uiVitTourne) :
 LCD            (0xF800)    ,
 clRoueAvantD   (R_AVANTD)  ,
 clRoueAvantG   (R_AVANTG)  ,
 clRoueArriereD (R_ARRIERED),
 clRoueArriereG (R_ARRIEREG) 
 { 
   ucMode          = MODEMANUEL;
   
   #ifdef SPI_DALLAS
      uiVitesse       = uiVit;
      uiVitesseTourne = uiVitTourne;  
   #endif
   
   #ifdef I2C_DALLAS
      ucVitesse       = uiVit;
      ucVitesseTourne = uiVitTourne; 
   #endif 
 }

// Destructeur ////////////////////////////////////////////////////////////////
CLVehicule :: ~CLVehicule(void)
{
   
}
 
///////////////////////////////////////////////////////////////////////////////
//void CLVehicule :: vControleBolide(void)
///////////////////////////////////////////////////////////////////////////////
//
// Description: 
//
// Parametres d'entrees: null
//
// Parametres de sortie: null
//
// Appel de la fonction: void (void);
//
// Cree le  par Louis-Normand Ang Houle
//
// Modifications:
// -
//
///////////////////////////////////////////////////////////////////////////////
void CLVehicule :: vControleBolide(void)
{  
vSuivreLigne();
}

///////////////////////////////////////////////////////////////////////////////
//void CLVehicule :: vAvancer(UC ucDirection)
///////////////////////////////////////////////////////////////////////////////
//
// Description: 
//
// Parametres d'entrees: null
//
// Parametres de sortie: null
//
// Appel de la fonction: void (void);
//
// Cree le  par Louis-Normand Ang Houle
//
// Modifications:
// -
//
///////////////////////////////////////////////////////////////////////////////
void CLVehicule :: vAvancer(UC ucDirection)
{
    LCD.vLCDCursor(0,3);
    LCD.String("    ");  
    LCD.vLCDCursor(0,3);
    
    #ifdef SPI_DALLAS
    if(ucDirection == GAUCHE)
     {
       LCD.String("GAU");  
       clRoueAvantD.vMarcheAvant    (uiVitesseTourne);       
       clRoueAvantG.vMarcheArriere  (uiVitesseTourne);
       clRoueArriereD.vMarcheAvant  (uiVitesseTourne);
       clRoueArriereG.vMarcheArriere(uiVitesseTourne);   
     }  
    
    if(ucDirection == DROITE)
     {
       LCD.String("DRO");  
       clRoueAvantD.vMarcheArriere  (uiVitesseTourne);       
       clRoueAvantG.vMarcheAvant    (uiVitesseTourne);
       clRoueArriereD.vMarcheArriere(uiVitesseTourne);
       clRoueArriereG.vMarcheAvant  (uiVitesseTourne); 
     }
    
    if(ucDirection == DROITDEVANT)
     {    
       LCD.String("AVT");
       clRoueAvantD.vMarcheAvant  (uiVitesse);       
       clRoueAvantG.vMarcheAvant  (uiVitesse);
       clRoueArriereD.vMarcheAvant(uiVitesse);
       clRoueArriereG.vMarcheAvant(uiVitesse);         
     }  
    
    if(ucDirection == ARRET)
     {
       LCD.String("STP");
       clRoueAvantD.vArret  ();       
       clRoueAvantG.vArret  ();
       clRoueArriereD.vArret();
       clRoueArriereG.vArret();      
     } 
    if (ucDirection == MARCHEARRIERE)
     {
       LCD.String("ARR");
       clRoueAvantD.vMarcheArriere  (uiVitesse);       
       clRoueAvantG.vMarcheArriere  (uiVitesse);
       clRoueArriereD.vMarcheArriere(uiVitesse);
       clRoueArriereG.vMarcheArriere(uiVitesse);  
     }       
    #endif
    
    #ifdef I2C_DALLAS
    if(ucDirection == GAUCHE)
     {
       LCD.String("GAU");  
       clRoueAvantD.vMarcheAvant    (ucVitesseTourne);       
       clRoueAvantG.vMarcheArriere  (ucVitesseTourne);
       clRoueArriereD.vMarcheAvant  (ucVitesseTourne);
       clRoueArriereG.vMarcheArriere(ucVitesseTourne);   
     }  
    
    if(ucDirection == DROITE)
     {
       LCD.String("DRO");  
       clRoueAvantD.vMarcheArriere  (ucVitesseTourne);       
       clRoueAvantG.vMarcheAvant    (ucVitesseTourne);
       clRoueArriereD.vMarcheArriere(ucVitesseTourne);
       clRoueArriereG.vMarcheAvant  (ucVitesseTourne); 
     }
    
    if(ucDirection == DROITDEVANT)
     {    
       LCD.String("AVT");
       clRoueAvantD.vMarcheAvant  (ucVitesse);       
       clRoueAvantG.vMarcheAvant  (ucVitesse);
       clRoueArriereD.vMarcheAvant(ucVitesse);
       clRoueArriereG.vMarcheAvant(ucVitesse);         
     }  
    
    if(ucDirection == ARRET)
     {
       LCD.String("STP");
       clRoueAvantD.vArret  ();       
       clRoueAvantG.vArret  ();
       clRoueArriereD.vArret();
       clRoueArriereG.vArret();      
     } 
    if (ucDirection == MARCHEARRIERE)
     {
       LCD.String("ARR");
       clRoueAvantD.vMarcheArriere  (ucVitesse);       
       clRoueAvantG.vMarcheArriere  (ucVitesse);
       clRoueArriereD.vMarcheArriere(ucVitesse);
       clRoueArriereG.vMarcheArriere(ucVitesse);  
     }
    #endif
 }
 
///////////////////////////////////////////////////////////////////////////////
//void CLVehicule :: vSuivreLigne(void)
///////////////////////////////////////////////////////////////////////////////
//
// Description: 
//
// Parametres d'entrees: null
//
// Parametres de sortie: null
//
// Appel de la fonction: void (void);
//
// Cree le  par Louis-Normand Ang Houle
//
// Modifications:
// -
//
///////////////////////////////////////////////////////////////////////////////
void CLVehicule :: vSuivreLigne(void)
 {
#ifdef SPI_DALLAS
   LCD.vLCDCursor(0,1);
   LCD.String("SUIVIE LIGNE SPI");  // Pourquoi ça ne s'affiche pas?

   uiVitesse       = 0x0280; 

   switch(clSuiveurLigne.ucSuivreLigne())
    {
    case GAUCHE:
      uiVitesseTourne = 0x0700;
      vAvancer(GAUCHE);
    break;
    
    case DROITE:
      uiVitesseTourne = 0x0700;
      vAvancer(DROITE);
    break;
 
    case DROITDEVANT:
      vAvancer(DROITDEVANT);
    break;
    }
#endif
   
#ifdef I2C_DALLAS
   LCD.vLCDCursor(0,1);
   LCD.String("SUIVIE LIGNE I2C");  

   ucVitesse       = 0x28; 

   switch(clSuiveurLigne.ucSuivreLigne())
    {
    case GAUCHE:
      ucVitesseTourne = 0x70;
      vAvancer(GAUCHE);
    break;
    
    case GAUCHELENT:
      ucVitesseTourne = 0x30;
      vAvancer(GAUCHE);
    break;  
    
    case DROITE:
      ucVitesseTourne = 0x70;
      vAvancer(DROITE);
    break;
    
    case DROITELENT:  
      ucVitesseTourne = 0x30;
      vAvancer(DROITE);
    break;  
      
    case DROITDEVANT:
      vAvancer(DROITDEVANT);
    break;
    
    case ARRET:
      vAvancer(ARRET);
    break;
    }
#endif
 }
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@