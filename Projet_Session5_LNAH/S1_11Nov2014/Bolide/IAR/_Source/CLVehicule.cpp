// ************************** FICHIER: CLVEHICULE.CPP ***********************
//
// Fonctions pour l'assemblage bolide
//
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
 clEcranVehicule(0xF800),
 clComBolide    (10,5,9600),
 clRoueAvantD   (R_AVANTD),
 clRoueAvantG   (R_AVANTG),
 clRoueArriereD (R_ARRIERED),
 clRoueArriereG (R_ARRIEREG),  
 clCapteurDroite(SENSEURDROITE),
 clCapteurGauche(SENSEURGAUCHE)
 {
   ucVitesse        = VITESSEINIT;
   ucVitesseTourne  = VITESSEINITTOURNE;
   ucVitRecu        = VITESSEINIT;
   ucVitTourneRecu  = VITESSEINITTOURNE;
   ucMode           = MODEMANUEL;
 }

// Constructeur initialisateur ////////////////////////////////////////////////

CLVehicule :: CLVehicule(UC ucVit, UC ucVitTourne) :
 clEcranVehicule(0xF800),
 clComBolide    (10,5,9600),
 clRoueAvantD   (R_AVANTD),
 clRoueAvantG   (R_AVANTG),
 clRoueArriereD (R_ARRIERED),
 clRoueArriereG (R_ARRIEREG),  
 clCapteurDroite(SENSEURDROITE),
 clCapteurGauche(SENSEURGAUCHE)
 {
   ucVitesse       = ucVit;
   ucVitesseTourne = ucVitTourne; 
   ucVitRecu       = ucVit;
   ucVitTourneRecu = ucVitTourne;
   ucMode          = MODEMANUEL;   
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
   static struct STReceptionTrame *stpTrameRecue = &unReceptionTrame.stTrameRecue; 

   if(clComBolide.ucpLireTrame() != NULL)
    {
      clEcranVehicule.vLCDClr();
 
      unReceptionTrame.uctTrameRecue[0] = clComBolide.ucpLireTrame()[0];
      unReceptionTrame.uctTrameRecue[1] = clComBolide.ucpLireTrame()[1];
      unReceptionTrame.uctTrameRecue[2] = clComBolide.ucpLireTrame()[2];
      unReceptionTrame.uctTrameRecue[3] = clComBolide.ucpLireTrame()[3];
      unReceptionTrame.uctTrameRecue[4] = clComBolide.ucpLireTrame()[4];      
    }
   
   switch(stpTrameRecue->ucCommande)
    {
      case 'F': vAvancer(DROITDEVANT);
      break;
      case 'S': vAvancer(ARRET);
      break;
      case 'R': vAvancer(MARCHEARRIERE);
      break;
      case 'G': vAvancer(GAUCHE);
      break;
      case 'D': vAvancer(DROITE);
      break;      
      case 'P': ucMode = MODEMANUEL;
      break;
      case 'M': ucMode = MODEINCLINO;
      break;
      case 'A': ucMode = MODELIGNE;
      break;
      case 'E': ucMode = MODEEVITEUR;
      break;
      case 'U': ucMode = MODESUIVEUR;
      break;
      case 'T': ucMode = MODETECH;
      break;
      
      case 'V':
        if(stpTrameRecue->ucDonnee1 == '1') 
         {
          ucVitTourneRecu = stpTrameRecue->ucDonnee2;
         }
        if(stpTrameRecue->ucDonnee1 == '0')
         {
          ucVitRecu       = stpTrameRecue->ucDonnee2;        
         }    
      break;   
   }
   
   if(ucMode == MODEINCLINO)
    {
      vInclinometre(stpTrameRecue->ucDonnee1, stpTrameRecue->ucDonnee2);
    } 
 
   if(ucMode == MODELIGNE) 
    {
     vSuivreLigne();
    }
   
   if(ucMode == MODEEVITEUR) 
    {
     vEviterMoi();    
    }
    
   if(ucMode == MODESUIVEUR)   
    {
     vSuivreMoi();
    }   
   
   if(ucMode == MODETECH)
    {
     clEcranVehicule.vLCDCursor(0,1);
     clEcranVehicule.vLCDDisplayCaracChain("**MODE TECHNICIEN**");  
        
     clEcranVehicule.vLCDCursor(0,2);
     clEcranVehicule.vLCDDisplayCaracChain("TRAME:");  
     clEcranVehicule.vLCDDisplayCarac(unReceptionTrame.uctTrameRecue[0]);  
     clEcranVehicule.vLCDDisplayCarac(unReceptionTrame.uctTrameRecue[1]);        
     clEcranVehicule.vLCDDisplayCarac(unReceptionTrame.uctTrameRecue[2]);  
     clEcranVehicule.vLCDDisplayCarac(unReceptionTrame.uctTrameRecue[3]);  
     clEcranVehicule.vLCDDisplayCarac(unReceptionTrame.uctTrameRecue[4]);   
        
     clEcranVehicule.vLCDCursor(0,3);
     clEcranVehicule.vLCDDisplayEtatPort(clSuiveurLigne.ucLireIOPCF());

     clEcranVehicule.vLCDCursor(0,4);
     clEcranVehicule.vLCDDisplayHexCarac(clCapteurDroite.uiLireCapteur());
     clEcranVehicule.vLCDCursor(6,4);
     clEcranVehicule.vLCDDisplayHexCarac(clCapteurGauche.uiLireCapteur());
     clEcranVehicule.vLCDCursor(12,4);        
     clEcranVehicule.vLCDDisplayHexCarac(clLimiteVitesse.ucLimiteVitesse());
     clEcranVehicule.vLCDCursor(16,4);
     clEcranVehicule.vLCDDisplayDecimal(clPile.fLirePile());    
    }
   
   if(ucMode == MODEMANUEL)
    {  
     ucVitesse       = (ucVitRecu * CONVPOURCENT);
     ucVitesseTourne = (ucVitTourneRecu * CONVPOURCENT);
     
     clEcranVehicule.vLCDCursor(0,1);
     clEcranVehicule.vLCDDisplayCaracChain("****MODE MANUEL****");         
     clEcranVehicule.vLCDCursor(0,2);
     clEcranVehicule.vLCDDisplayCaracChain("TRAME:");  
     clEcranVehicule.vLCDDisplayCarac(unReceptionTrame.uctTrameRecue[0]);  
     clEcranVehicule.vLCDDisplayCarac(unReceptionTrame.uctTrameRecue[1]);        
     clEcranVehicule.vLCDDisplayCarac(unReceptionTrame.uctTrameRecue[2]);  
     clEcranVehicule.vLCDDisplayCarac(unReceptionTrame.uctTrameRecue[3]);  
     clEcranVehicule.vLCDDisplayCarac(unReceptionTrame.uctTrameRecue[4]);
     
     clEcranVehicule.vLCDCursor(10,3);
     clEcranVehicule.vLCDDisplayDecimal(clPile.fLirePile());
        
     clEcranVehicule.vLCDCursor(0,3);
         
     clEcranVehicule.vLCDCursor(0,4);
     clEcranVehicule.vLCDDisplayCaracChain("VIT1:"); 
     clEcranVehicule.vLCDDisplayHexCarac(ucVitesse);
     clEcranVehicule.vLCDDisplayCaracChain(" VIT2:");
     clEcranVehicule.vLCDDisplayHexCarac(ucVitesseTourne); 
    
     if(stpTrameRecue->ucCommande == 'F') vAvancer(DROITDEVANT);
     if(stpTrameRecue->ucCommande == 'S') vAvancer(ARRET);
     if(stpTrameRecue->ucCommande == 'R') vAvancer(MARCHEARRIERE);
     if(stpTrameRecue->ucCommande == 'G') vAvancer(GAUCHE);
     if(stpTrameRecue->ucCommande == 'D') vAvancer(DROITE);  
   }
   

 }

///////////////////////////////////////////////////////////////////////////////
// void CLVehicule :: vInclinometre(void)
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
 
void CLVehicule :: vInclinometre(UC ucHorizontal, UC ucVertical)
 {   
   if((ucVertical > 0x7F) && (ucHorizontal > 0x7F))
    {
       ucVitesse       = ucVertical   - 0x7F;
       ucVitesseTourne = ucHorizontal - 0x7F;    
    
       if(ucVitesseTourne > 0x40) vAvancer(GAUCHE);
       else                       vAvancer(AVANTGAUCHE);
    } 
   if((ucVertical > 0x7F) && (ucHorizontal < 0x7F))
    {
       ucVitesse       = ucVertical - 0x7F;
       ucVitesseTourne = ucHorizontal;    
       
       if(ucVitesseTourne > 0x40) vAvancer(GAUCHE);
       else                       vAvancer(ARRIEREGAUCHE);
    }
   if((ucVertical < 0x7F) && (ucHorizontal > 0x7F))
    {
       ucVitesse       = ucVertical;
       ucVitesseTourne = ucHorizontal - 0x7F;    
    
       if(ucVitesseTourne > 0x40) vAvancer(DROITE);
       else                       vAvancer(AVANTDROITE);
    }
   if((ucVertical < 0x7F) && (ucHorizontal < 0x7F))
    {
       ucVitesse       = ucVertical;
       ucVitesseTourne = ucHorizontal;
       
       if(ucVitesseTourne > 0x40) vAvancer(DROITE);
       else                       vAvancer(ARRIEREDROITE);
    } 
   clEcranVehicule.vLCDCursor(0,1);
   clEcranVehicule.vLCDDisplayCaracChain("***INCLINOMETRE***");  
      
   clEcranVehicule.vLCDCursor(0,4);
   clEcranVehicule.vLCDDisplayCaracChain("VIT1:"); 
   clEcranVehicule.vLCDDisplayHexCarac(ucVitesse);
   clEcranVehicule.vLCDDisplayCaracChain(" VIT2:");
   clEcranVehicule.vLCDDisplayHexCarac(ucVitesseTourne); 
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
    vVerifieVitesse();

    clEcranVehicule.vLCDCursor(0,3);
    clEcranVehicule.vLCDDisplayCaracChain("    ");  
    clEcranVehicule.vLCDCursor(0,3);
    
    if(ucDirection == GAUCHE)
     {
       clEcranVehicule.vLCDDisplayCaracChain("G");  
       clRoueAvantD.vMarcheAvant  (ucVitesseTourne);       
       clRoueAvantG.vMarcheArriere(ucVitesseTourne);
       clRoueArriereD.vMarcheAvant  (ucVitesseTourne);
       clRoueArriereG.vMarcheArriere(ucVitesseTourne);   
     }  
    
    if(ucDirection == DROITE)
     {
       clEcranVehicule.vLCDDisplayCaracChain("D");  
       clRoueAvantD.vMarcheArriere(ucVitesseTourne);       
       clRoueAvantG.vMarcheAvant  (ucVitesseTourne);
       clRoueArriereD.vMarcheArriere(ucVitesseTourne);
       clRoueArriereG.vMarcheAvant  (ucVitesseTourne); 
     }
    
    if(ucDirection == AVANTGAUCHE)
     {
       if((ucVitesseTourne > ucVitesse) && (ucVitesse > 0x10))
        {
          ucVitesseTourne = ucVitesse - 0x10;
        }
       clEcranVehicule.vLCDDisplayCaracChain("AVG");        
       clRoueAvantD.vMarcheAvant  (ucVitesse);       
       clRoueAvantG.vMarcheAvant  (ucVitesseTourne);
       clRoueArriereD.vMarcheAvant(ucVitesse);
       clRoueArriereG.vMarcheAvant(ucVitesseTourne); 
     }
    
    if(ucDirection == AVANTDROITE)
     {
       if((ucVitesseTourne > ucVitesse) && (ucVitesse > 0x10))
        {
          ucVitesseTourne = ucVitesse - 0x10;
        } 
       clEcranVehicule.vLCDDisplayCaracChain("AVD");
       clRoueAvantD.vMarcheAvant  (ucVitesseTourne);       
       clRoueAvantG.vMarcheAvant  (ucVitesse);
       clRoueArriereD.vMarcheAvant(ucVitesseTourne);
       clRoueArriereG.vMarcheAvant(ucVitesse); 
     }
    
    if(ucDirection == ARRIEREGAUCHE)
     {
       if((ucVitesseTourne > ucVitesse) && (ucVitesse > 0x10))
        {
          ucVitesseTourne = ucVitesse - 0x10;
        }
       clEcranVehicule.vLCDDisplayCaracChain("ARG");
       clRoueAvantD.vMarcheArriere  (ucVitesse);       
       clRoueAvantG.vMarcheArriere  (ucVitesseTourne);
       clRoueArriereD.vMarcheArriere(ucVitesse);
       clRoueArriereG.vMarcheArriere(ucVitesseTourne);        
     }
    
    if(ucDirection == ARRIEREDROITE)
     {
       if((ucVitesseTourne > ucVitesse) && (ucVitesse > 0x10))
        {
          ucVitesseTourne = ucVitesse - 0x10;
        }
       clEcranVehicule.vLCDDisplayCaracChain("ARD");
       clRoueAvantD.vMarcheArriere  (ucVitesseTourne);       
       clRoueAvantG.vMarcheArriere  (ucVitesse);
       clRoueArriereD.vMarcheArriere(ucVitesseTourne);
       clRoueArriereG.vMarcheArriere(ucVitesse);        
     } 
    
    if(ucDirection == DROITDEVANT)
     {    
       clEcranVehicule.vLCDDisplayCaracChain("AVT");
       clRoueAvantD.vMarcheAvant(ucVitesse);       
       clRoueAvantG.vMarcheAvant(ucVitesse);
       clRoueArriereD.vMarcheAvant(ucVitesse);
       clRoueArriereG.vMarcheAvant(ucVitesse);         
     }  
    
    if(ucDirection == ARRET)
     {
       clEcranVehicule.vLCDDisplayCaracChain("STP");
       clRoueAvantD.vArret();       
       clRoueAvantG.vArret();
       clRoueArriereD.vArret();
       clRoueArriereG.vArret();      
     } 
    if (ucDirection == MARCHEARRIERE)
     {
       clEcranVehicule.vLCDDisplayCaracChain("ARR");
       clRoueAvantD.vMarcheArriere(ucVitesse);       
       clRoueAvantG.vMarcheArriere(ucVitesse);
       clRoueArriereD.vMarcheArriere(ucVitesse);
       clRoueArriereG.vMarcheArriere(ucVitesse);  
     }       
 }

///////////////////////////////////////////////////////////////////////////////
//void CLVehicule :: vSetVitesse(UC ucVit, UC ucVitTourne)
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
 
void CLVehicule :: vSetVitesse(UC ucVit, UC ucVitTourne)
 {
   ucVitesse       = ucVit;
   ucVitesseTourne = ucVitTourne;   
 }

///////////////////////////////////////////////////////////////////////////////
//void CLVehicule :: vVerifieVitesse(void)
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
 
void CLVehicule :: vVerifieVitesse(void)
 {
   ucLimiteVitesse = clLimiteVitesse.ucLimiteVitesse();
   if(ucVitesse > ucLimiteVitesse)
    {
      ucVitesse = ucLimiteVitesse;
    } 
 }
 
///////////////////////////////////////////////////////////////////////////////
//void CLVehicule :: vSuitLigne(void)
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
   clEcranVehicule.vLCDCursor(0,1);
   clEcranVehicule.vLCDDisplayCaracChain("****SUIVIE LIGNE****");  
     
   clEcranVehicule.vLCDCursor(0,2);
   clEcranVehicule.vLCDDisplayCaracChain("TRAME:");  
   clEcranVehicule.vLCDDisplayCarac(unReceptionTrame.uctTrameRecue[0]);  
   clEcranVehicule.vLCDDisplayCarac(unReceptionTrame.uctTrameRecue[1]);        
   clEcranVehicule.vLCDDisplayCarac(unReceptionTrame.uctTrameRecue[2]);  
   clEcranVehicule.vLCDDisplayCarac(unReceptionTrame.uctTrameRecue[3]);  
   clEcranVehicule.vLCDDisplayCarac(unReceptionTrame.uctTrameRecue[4]);   
        
   clEcranVehicule.vLCDCursor(0,3);
         
   clEcranVehicule.vLCDCursor(0,4);
   clEcranVehicule.vLCDDisplayCaracChain("VIT1:"); 
   clEcranVehicule.vLCDDisplayHexCarac(ucVitesse);
   clEcranVehicule.vLCDDisplayCaracChain(" VIT2:");
   clEcranVehicule.vLCDDisplayHexCarac(ucVitesseTourne);
    
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
 }
 
///////////////////////////////////////////////////////////////////////////////
//void CLVehicule :: vSuivreMoi(void)
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
 
void CLVehicule :: vSuivreMoi(void)
 { 
   clEcranVehicule.vLCDCursor(0,1);
   clEcranVehicule.vLCDDisplayCaracChain("****MODE SUIVEUR****"); 
     
   clEcranVehicule.vLCDCursor(0,2);
   clEcranVehicule.vLCDDisplayCaracChain("TRAME:");  
   clEcranVehicule.vLCDDisplayCarac(unReceptionTrame.uctTrameRecue[0]);  
   clEcranVehicule.vLCDDisplayCarac(unReceptionTrame.uctTrameRecue[1]);        
   clEcranVehicule.vLCDDisplayCarac(unReceptionTrame.uctTrameRecue[2]);  
   clEcranVehicule.vLCDDisplayCarac(unReceptionTrame.uctTrameRecue[3]);  
   clEcranVehicule.vLCDDisplayCarac(unReceptionTrame.uctTrameRecue[4]);   
        
   clEcranVehicule.vLCDCursor(0,3);
         
   clEcranVehicule.vLCDCursor(0,4);
   clEcranVehicule.vLCDDisplayCaracChain("VIT1:"); 
   clEcranVehicule.vLCDDisplayHexCarac(ucVitesse);
   clEcranVehicule.vLCDDisplayCaracChain(" VIT2:");
   clEcranVehicule.vLCDDisplayHexCarac(ucVitesseTourne); 

   ucVitesse       = 0x30;
   ucVitesseTourne = 0x7F; 
   
   if(clCapteurGauche.uiLireCapteur() >= 0x0300) ucTourne = DROITDEVANT;
   if(clCapteurDroite.uiLireCapteur() >= 0x0300) ucTourne = DROITDEVANT;   
  
   if(clCapteurGauche.uiLireCapteur() >= 0x0700) ucTourne = DROITE;
   if(clCapteurDroite.uiLireCapteur() >= 0x0700) ucTourne = GAUCHE;
   
   if(clCapteurGauche.uiLireCapteur() >= 0x0A00) ucTourne = ARRET;
   if(clCapteurDroite.uiLireCapteur() >= 0x0A00) ucTourne = ARRET;   

   if(clCapteurGauche.uiLireCapteur() >= 0x0B00) ucTourne = MARCHEARRIERE;
   if(clCapteurDroite.uiLireCapteur() >= 0x0B00) ucTourne = MARCHEARRIERE;   
  
       
   if((ucBoucle != 0) &&(ucTourne != 0xFF))
    {
      if(ucTourne == GAUCHE)        vAvancer(GAUCHE);
      if(ucTourne == DROITE)        vAvancer(DROITE);
      if(ucTourne == ARRET)         vAvancer(ARRET);
      if(ucTourne == MARCHEARRIERE) vAvancer(MARCHEARRIERE);      
    }
   
   else
    {
      ucBoucle = 0x04;
      ucTourne = 0xFF;
      vAvancer(DROITDEVANT);
    }
   ucBoucle--;
 }
 
///////////////////////////////////////////////////////////////////////////////
//void CLVehicule :: vEviterMoi(void) 
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
 
void CLVehicule :: vEviterMoi(void) 
 {
   clEcranVehicule.vLCDCursor(0,1);   
   clEcranVehicule.vLCDDisplayCaracChain("****MODE EVITEUR****");  
     
   clEcranVehicule.vLCDCursor(0,2);
   clEcranVehicule.vLCDDisplayCaracChain("TRAME:");  
   clEcranVehicule.vLCDDisplayCarac(unReceptionTrame.uctTrameRecue[0]);  
   clEcranVehicule.vLCDDisplayCarac(unReceptionTrame.uctTrameRecue[1]);        
   clEcranVehicule.vLCDDisplayCarac(unReceptionTrame.uctTrameRecue[2]);  
   clEcranVehicule.vLCDDisplayCarac(unReceptionTrame.uctTrameRecue[3]);  
   clEcranVehicule.vLCDDisplayCarac(unReceptionTrame.uctTrameRecue[4]);   
        
   clEcranVehicule.vLCDCursor(0,3);
         
   clEcranVehicule.vLCDCursor(0,4);
   clEcranVehicule.vLCDDisplayCaracChain("VIT1:"); 
   clEcranVehicule.vLCDDisplayHexCarac(ucVitesse);
   clEcranVehicule.vLCDDisplayCaracChain(" VIT2:");
   clEcranVehicule.vLCDDisplayHexCarac(ucVitesseTourne); 
     
   
   
   ucVitesse       = 0x50;
   ucVitesseTourne = 0x7F; 
   
   if(clCapteurGauche.uiLireCapteur() >= 0x0300) ucTourne = GAUCHE;
   if(clCapteurDroite.uiLireCapteur() >= 0x0300) ucTourne = DROITE;
   if(clCapteurGauche.uiLireCapteur() >= 0x0B00) ucTourne = MARCHEARRIERE;
   if(clCapteurDroite.uiLireCapteur() >= 0x0B00) ucTourne = MARCHEARRIERE; 

   if((ucBoucle != 0) &&(ucTourne != 0xFF))
    {
      if(ucTourne == GAUCHE) vAvancer(GAUCHE);
      if(ucTourne == DROITE) vAvancer(DROITE);
      if(ucTourne == MARCHEARRIERE) vAvancer(MARCHEARRIERE); 
    }
   else
    {
      ucBoucle = 0x0F;
      ucTourne = 0xFF;
      vAvancer(DROITDEVANT);
    }
   
   ucBoucle--;
 }
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!