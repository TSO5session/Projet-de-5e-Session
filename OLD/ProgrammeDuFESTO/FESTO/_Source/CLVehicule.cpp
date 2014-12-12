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

#ifdef DALLAS89C450
#include "CLVehicule.h"

//******************************************************************************
//                            LE CONSTRUCTEUR PAR DEFAUT
// *****************************************************************************
CLVehicule :: CLVehicule(void) :
              clEcranVehicule(0xF800)    ,
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

//******************************************************************************
//                            LE CONSTRUCTEUR INITIALISATEUR
// *****************************************************************************
 CLVehicule :: CLVehicule(USI uiVit, USI uiVitTourne) :
              clEcranVehicule(0xF800),
              clRoueAvantD   (R_AVANTD),
              clRoueAvantG   (R_AVANTG),
              clRoueArriereD (R_ARRIERED),
              clRoueArriereG (R_ARRIEREG) 
 { 
   ucMode            = MODEMANUEL;
   
   #ifdef SPI_DALLAS
     uiVitesse       = uiVit;
     uiVitesseTourne = uiVitTourne;  
   #endif
   
   #ifdef I2C_DALLAS
     ucVitesse       = uiVit;
     ucVitesseTourne = uiVitTourne; 
   #endif 
 }

// *****************************************************************************
//                            LE DESTRUCTEUR
// *****************************************************************************
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
    clEcranVehicule.vLCDCursor(0,3);
    clEcranVehicule.vLCDDisplayCaracChain("    ");  
    clEcranVehicule.vLCDCursor(0,3);
    
    #ifdef SPI_DALLAS
    if(ucDirection == GAUCHE)
     {
       clEcranVehicule.vLCDDisplayCaracChain("GAU");  
       clRoueAvantD.vMarcheAvant    (uiVitesseTourne);       
       clRoueAvantG.vMarcheArriere  (uiVitesseTourne);
       clRoueArriereD.vMarcheAvant  (uiVitesseTourne);
       clRoueArriereG.vMarcheArriere(uiVitesseTourne);   
     }  
    
    if(ucDirection == DROITE)
     {
       clEcranVehicule.vLCDDisplayCaracChain("DRO");  
       clRoueAvantD.vMarcheArriere  (uiVitesseTourne);       
       clRoueAvantG.vMarcheAvant    (uiVitesseTourne);
       clRoueArriereD.vMarcheArriere(uiVitesseTourne);
       clRoueArriereG.vMarcheAvant  (uiVitesseTourne); 
     }
    
    if(ucDirection == DROITDEVANT)
     {    
       clEcranVehicule.vLCDDisplayCaracChain("AVT");
       clRoueAvantD.vMarcheAvant  (uiVitesse);       
       clRoueAvantG.vMarcheAvant  (uiVitesse);
       clRoueArriereD.vMarcheAvant(uiVitesse);
       clRoueArriereG.vMarcheAvant(uiVitesse);         
     }  
    
    if(ucDirection == ARRET)
     {
       clEcranVehicule.vLCDDisplayCaracChain("STP");
       clRoueAvantD.vArret  ();       
       clRoueAvantG.vArret  ();
       clRoueArriereD.vArret();
       clRoueArriereG.vArret();      
     } 
    
    if (ucDirection == MARCHEARRIERE)
     {
       clEcranVehicule.vLCDDisplayCaracChain("ARR");
       clRoueAvantD.vMarcheArriere  (uiVitesse);       
       clRoueAvantG.vMarcheArriere  (uiVitesse);
       clRoueArriereD.vMarcheArriere(uiVitesse);
       clRoueArriereG.vMarcheArriere(uiVitesse);  
     }       
    #endif
    
    #ifdef I2C_DALLAS
    if(ucDirection == GAUCHE)
     {
       clEcranVehicule.vLCDDisplayCaracChain("GAU");  
       clRoueAvantD.vMarcheArriere    (ucVitesseTourne);       
       clRoueAvantG.vMarcheArriere  (ucVitesseTourne);
       clRoueArriereD.vMarcheAvant  (ucVitesseTourne);
       clRoueArriereG.vMarcheAvant (ucVitesseTourne);   
     }  
    
    if(ucDirection == DROITE)
     {
       clEcranVehicule.vLCDDisplayCaracChain("DRO");  
       clRoueAvantD.vMarcheAvant  (ucVitesseTourne);       
       clRoueAvantG.vMarcheAvant    (ucVitesseTourne);
       clRoueArriereD.vMarcheArriere(ucVitesseTourne);
       clRoueArriereG.vMarcheArriere  (ucVitesseTourne); 
     }
    
    if(ucDirection == DROITDEVANT)
     {    
       clEcranVehicule.vLCDDisplayCaracChain("AVT");
       clRoueAvantD.vMarcheAvant  (ucVitesse);       
       clRoueAvantG.vMarcheAvant  (ucVitesse);
       clRoueArriereD.vMarcheAvant(ucVitesse);
       clRoueArriereG.vMarcheAvant(ucVitesse);         
     }  
    
    if(ucDirection == ARRET)
     {
       clEcranVehicule.vLCDDisplayCaracChain("STP");
       clRoueAvantD.vArret  ();       
       clRoueAvantG.vArret  ();
       clRoueArriereD.vArret();
       clRoueArriereG.vArret();      
     } 
    
    if (ucDirection == MARCHEARRIERE)
     {
       clEcranVehicule.vLCDDisplayCaracChain("ARR");
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
   clEcranVehicule.vLCDCursor(0,1);
   clEcranVehicule.vLCDDisplayCaracChain("****SUIVIE LIGNE****");   

   uiVitesse          = 0x0280; 

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
   clEcranVehicule.vLCDCursor(0,1);
   clEcranVehicule.vLCDDisplayCaracChain("****SUIVIE LIGNE****");  

   ucVitesse         = 0x28; 

   switch(clSuiveurLigne.ucSuivreLigne())
    {
    case GAUCHE:
      ucVitesseTourne = 0x40;
      vAvancer(GAUCHE);
    break;
    
    case GAUCHELENT:
      ucVitesseTourne = 0x30;
      vAvancer(GAUCHE);
    break;  
    
    case DROITE:
      ucVitesseTourne = 0x40;
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
 
// ********************** FONCTION: BattryInfo()
//
// DESCRIPTION:         Fonction pour lire l'énergie de la pile et l'envoyer sur Xbee
//
// INCLUDE:             "clVehicule.h"
//
// PROTOTYPE:           void BattryInfo(void)
//
// PROCEDURE D'APPEL:   BattryInfo()
//
// PARAMETRE D'ENTREE:  AUCUN
//
// PARAMETRE DE SORTIE: AUCUN
//
// Auteur:              Vincent Chouinard
// Date:                21 novembre 2014 (Version 1.0)
// *****************************************************************************
 void CLVehicule :: BattryInfo (void)
 {
  Xbee.SendNumber((int)Battry.fLirePile());
 }
 
// ********************** FONCTION: SpeedInfo()
//
// DESCRIPTION:         Fonction pour lire la vitesse du bolide et l'envoyer sur Xbee
//
// INCLUDE:             "clVehicule.h"
//
// PROTOTYPE:           void SpeedInfo(void)
//
// PROCEDURE D'APPEL:   SpeedInfo()
//
// PARAMETRE D'ENTREE:  AUCUN
//
// PARAMETRE DE SORTIE: AUCUN
//
// Auteur:              Vincent Chouinard
// Date:                21 novembre 2014 (Version 1.0)
// *****************************************************************************
  void CLVehicule :: SpeedInfo (void)
 {
  Xbee.SendNumber(NULL); // Code à écrire 
 }
 
// ********************** FONCTION: GetPosition()
//
// DESCRIPTION:         Fonction pour lire la position du bolide et l'envoyer sur Xbee
//
// INCLUDE:             "clVehicule.h"
//
// PROTOTYPE:           void GetPosition(void)
//
// PROCEDURE D'APPEL:   GetPosition()
//
// PARAMETRE D'ENTREE:  AUCUN
//
// PARAMETRE DE SORTIE: AUCUN
//
// Auteur:              Vincent Chouinard
// Date:                21 novembre 2014 (Version 1.0)
// *****************************************************************************
 void CLVehicule :: GetPosition (void)
 {  
 UC ucPosition = Xbee.GetChar(); // Hmmm... Qui envoie la position du véhicule, le véhicule lui-même ou le poste actif?
  
 switch(ucPosition)
  { 
   case 1:
      Xbee.SendString("Je suis à la table FESTO");
   break;

   case 2:
      Xbee.SendString("Je suis à la tstation de pesée");
   break;
  }  
 }
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#endif 
 