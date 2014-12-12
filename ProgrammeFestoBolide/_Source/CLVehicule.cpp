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

#include "DeclarationGenerale.h"

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
              clRoueArriereG (R_ARRIEREG),
              clXbeeVehicule(5, 5, 9600)  
 { 
     ucMode          = MODEMANUEL;
     ucCompteur      = 0;
     ucPosition      = 0;
     ucSens          = HORAIRE;
     ucVitesse       = VITESSEINIT;
     ucVitesseTourne = VITESSEINITTOURNE; 
     
     TrameTxVehicule[0] = '3';
     TrameTxVehicule[1] = ' ';
     TrameTxVehicule[2] = '0';
     TrameTxVehicule[3] = '0';
     TrameTxVehicule[4] = '0';
 }

//******************************************************************************
//                            LE CONSTRUCTEUR INITIALISATEUR
// *****************************************************************************
CLVehicule :: CLVehicule(USI uiVit, USI uiVitTourne) :
              clEcranVehicule(0xF800),
              clRoueAvantD   (R_AVANTD),
              clRoueAvantG   (R_AVANTG),
              clRoueArriereD (R_ARRIERED),
              clRoueArriereG (R_ARRIEREG),
              clXbeeVehicule(5, 5, 9600)
 { 
     ucMode          = MODEMANUEL;
     ucCompteur      = 0;
     ucPosition      = 0;
     ucSens          = HORAIRE;
     ucVitesse       = uiVit;
     ucVitesseTourne = uiVitTourne;
     
     TrameTxVehicule[0] = '3';
     TrameTxVehicule[1] = ' ';
     TrameTxVehicule[2] = '0';
     TrameTxVehicule[3] = '0';
     TrameTxVehicule[4] = '0';
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
// Cree le 2014/04/24 par Louis-Normand Ang Houle
//
// Modifications:
// -
//
///////////////////////////////////////////////////////////////////////////////
void CLVehicule :: vControleBolide(void)
{  
  static UC ucStart = 1;
  static UC ucFlagVehicule = 0; 

  TrameRxVehicule = clXbeeVehicule.ucpLireTrame();
  vInfoPosition();

  clEcranVehicule.vLCDCursor(10,2);
  clEcranVehicule.vLCDDisplayHexCarac(ucSens);
  
  if(TrameRxVehicule != NULL)
   {    
     clEcranVehicule.vLCDCursor(0,2);
     clEcranVehicule.vLCDDisplayCaracChain(TrameRxVehicule);
     if(TrameRxVehicule[0] == '2' &&   // Commande recue de la station 2
        TrameRxVehicule[1] == ' ')
     {   
       switch(TrameRxVehicule[2])
       {
       case 'A':
         TrameRxVehicule = NULL;
         ucMode = MODEMANUEL;        
       break;
         
       case 'L':    
         ucStart = 1;     
         if(TrameRxVehicule[4] == '1')
          {
            ucMode = MODESUIVEUR;
            ucSens = HORAIRE;
            ucFlagVehicule = 1;
            TrameRxVehicule = NULL;
          }
         
         if(TrameRxVehicule[4] == '2')
          {
            ucMode = MODESUIVEUR;
            ucSens = ANTIHORAIRE; 
           TrameRxVehicule = NULL; 
          }
         
         if(TrameRxVehicule[4] == '0')
         {
           ucMode = MODEMANUEL;
           TrameRxVehicule = NULL;
         }
         TrameRxVehicule = NULL;
         break; 
         
       default:
         break;
        }
     }
     else clXbeeVehicule.vResetTampon();
   }
  
  if (ucPosition == 1) ucMode = MODEMANUEL;
  if (ucPosition == 3) ucMode = MODEMANUEL;

  switch(ucMode)
  {
  case MODEMANUEL:
    vAvancer(ARRET);
    TrameTxVehicule[2] = 'A';
    TrameTxVehicule[3] = (ucPosition + 0x30);
    clXbeeVehicule.vTransChaine(TrameTxVehicule);
    break;
    
  case MODESUIVEUR:
    
    if(ucSens == HORAIRE)
     {
       if(ucFlagVehicule == 1)
       {
          if(ucCompteur == 1) {
            ucStart = 0;
            vAvancer(GAUCHE);
            for(UI i = 0; i<65000; i++);
            for(UI i = 0; i<65000; i++); 
            for(UI i = 0; i<65000; i++);
            for(UI i = 0; i<65000; i++); 
            for(UI i = 0; i<65000; i++);   
            vAvancer(DROITDEVANT);
            for(UI i = 0; i<65000; i++);
            for(UI i = 0; i<65000; i++);
            for(UI i = 0; i<65000; i++); 
            for(UI i = 0; i<65000; i++);
            for(UI i = 0; i<65000; i++); 
         }
       
          if(ucCompteur == 2) {
            vAvancer(DROITE);
            for(UI i = 0; i<65000; i++);
            for(UI i = 0; i<65000; i++); 
            for(UI i = 0; i<65000; i++);
            for(UI i = 0; i<65000; i++); 
            for(UI i = 0; i<65000; i++);
            vAvancer(DROITDEVANT);
            for(UI i = 0; i<65000; i++);
            for(UI i = 0; i<65000; i++);
            for(UI i = 0; i<65000; i++); 
            for(UI i = 0; i<65000; i++);
            for(UI i = 0; i<65000; i++); 
            ucCompteur = 0;
         }
          ucFlagVehicule = 0;
       }
     }
    if(ucSens == ANTIHORAIRE)
     {   
       if(ucCompteur == 1)
        {
         ucStart = 0;
         clEcranVehicule.vLCDCursor(10,4);
         clEcranVehicule.vLCDDisplayCaracChain("BOBAA");
         ucCompteur = 0;
         ucVitesse         = 0x40; 
         vAvancer(DROITDEVANT);
         for(UI i = 0; i<65000; i++); 
         for(UI i = 0; i<65000; i++); 
         for(UI i = 0; i<65000; i++); 
        }
     }
    vSuivreLigne();
    TrameTxVehicule[2] = 'L';
    TrameTxVehicule[3] = (ucPosition + 0x30);
    clXbeeVehicule.vTransChaine(TrameTxVehicule);
    break;
  default:
    break;
  }
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
// Cree le 2014/04/24 par Louis-Normand Ang Houle
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
// Cree le 2014/04/24 par Louis-Normand Ang Houle
//
// Modifications:
// -
//
///////////////////////////////////////////////////////////////////////////////
void CLVehicule :: vSuivreLigne(void)
 { 
 
   clEcranVehicule.vLCDCursor(0,1);
   clEcranVehicule.vLCDDisplayCaracChain("****SUIVIE LIGNE****");   
#ifdef SPI_DALLAS
   uiVitesse          = 0x0270; 
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
   ucVitesse         = 0x27; 
   switch(clSuiveurLigne.ucSuivreLigne())
    {
    case GAUCHE:
      ucVitesseTourne = 0x3A;
      vAvancer(GAUCHE);
    break;
    
    case GAUCHELENT:
      ucVitesseTourne = 0x30;
      vAvancer(GAUCHE);
    break;  
    
    case DROITE:
      ucVitesseTourne = 0x3A;
      vAvancer(DROITE);
    break;
    
    case DROITELENT:  
      ucVitesseTourne = 0x30;
      vAvancer(DROITE);
    break;  
      
    case DROITDEVANT:
      vAvancer(DROITDEVANT);
    break;
    case DROITVITE:
      ucVitesse         = 0x40; 
      vAvancer(DROITDEVANT);
    break;  
    case ARRET:
      vAvancer(ARRET);
    break;
    }
#endif
 }
 
///////////////////////////////////////////////////////////////////////////////
//void CLVehicule :: vInfoBatterie(void)
///////////////////////////////////////////////////////////////////////////////
//
// Description: Fonction de lecture du niveau de la pile
//
// Parametres d'entrees: null
//
// Parametres de sortie: null
//
// Appel de la fonction: void (void);
//
// Cree le 04/12/2014 par Louis-Normand Ang Houle
//
// Modifications:
// -
//
///////////////////////////////////////////////////////////////////////////////
void CLVehicule :: vInfoBatterie(void)
{
  
}

///////////////////////////////////////////////////////////////////////////////
//void CLVehicule :: vInfoPosition(void) 
///////////////////////////////////////////////////////////////////////////////
//
// Description: Fonction de 
//
// Parametres d'entrees: null
//
// Parametres de sortie: null
//
// Appel de la fonction: void (void);
//
// Cree le 04/12/2014 par Louis-Normand Ang Houle
//
// Modifications:
// -
//
///////////////////////////////////////////////////////////////////////////////
void CLVehicule :: vInfoPosition(void) 
{
  static UC ucFlag = 0;
  unCapteurPos.ucOctet = clSuiveurLigne.ucLireCapteurs();  
  
  if((unCapteurPos.stChampBit.bBit0 == 0) &&
     (unCapteurPos.stChampBit.bBit1 == 1) &&
     (unCapteurPos.stChampBit.bBit2 == 0) && 
      ucFlag == 0)
     {
       ucPosition = 1;
       if((unCapteurPos.stChampBit.bBit5 == 0) &&
          (unCapteurPos.stChampBit.bBit6 == 0) && 
          (unCapteurPos.stChampBit.bBit7 == 0))
       {ucPosition = 3;}  
       ucFlag = 1;
     }  
  
  if((unCapteurPos.stChampBit.bBit0 == 0) &&
     (unCapteurPos.stChampBit.bBit1 == 0) &&
     (unCapteurPos.stChampBit.bBit2 == 0) &&
       
     (unCapteurPos.stChampBit.bBit5 == 0) &&
     (unCapteurPos.stChampBit.bBit6 == 0) && 
     (unCapteurPos.stChampBit.bBit7 == 0) &&        
      ucFlag == 0)
     {
       ucCompteur ++;
       ucFlag = 1;
     }  
  
   if((unCapteurPos.stChampBit.bBit0 == 0) ||
      (unCapteurPos.stChampBit.bBit1 == 0) ||
      (unCapteurPos.stChampBit.bBit2 == 0) &&
       
      (unCapteurPos.stChampBit.bBit5 == 1) &&
      (unCapteurPos.stChampBit.bBit6 == 0) && 
      (unCapteurPos.stChampBit.bBit7 == 0) &&        
       ucFlag == 0)
     {
       ucVitesse         = 0x40; 
       vAvancer(DROITDEVANT);       
       ucFlag = 1;
     } 
  
  if((unCapteurPos.stChampBit.bBit0 == 1) &&
     (unCapteurPos.stChampBit.bBit1 == 1) &&
     (unCapteurPos.stChampBit.bBit2 == 1))
     {
       ucFlag = 0;
       ucPosition = 0;
     }
  
  clEcranVehicule.vLCDCursor(0,4);
  clEcranVehicule.vLCDDisplayHexCarac(ucPosition);
  
  clEcranVehicule.vLCDCursor(10,4);
  clEcranVehicule.vLCDDisplayHexCarac(ucCompteur);
}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#endif 
 