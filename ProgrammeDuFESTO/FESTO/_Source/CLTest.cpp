// ************************** FICHIER: CLTEST.CPP  *****************************
//
//  Application realisee avec IAR C++ 8.10
//
//  LIMITATION DU COMPILATEUR:
//  Impossible de faire de l'heritage multiple.
//
//  Fonctions de test pour l'ensemble des objets créés
//
//  Note: on peut utiliser XAR pour creer des librairies.
//  On peut mettre les librairies dans le projets et Exclure de la compilation
//  les modules qui sont contenus dans la librairie.
//
//  AUTEUR : LOUIS-NORMAND ANG HOULE
//  DATE CREATION :    2014/03/20       VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
// *****************************************************************************

#include "CLTest.h"

   UC VAR1,VAR2;
   void ucECRIRE( UC ucACTUATEUR , UC ucEtat);
   UC ucLIRE( UC ucACTUATEUR );
   UC ucLireCapteur(void);
   UC ucFin = 0;
   UC ucType;
   class CLIOPCF8574 IN_1(0x44), IN_2 (0x46), OUT_1 (0x40), OUT_2 (0x42);
   
// Constructeur par defaut ////////////////////////////////////////////////////
CLTest :: CLTest(void)    
: clTestEcran (0xF800)     // Adresse de l'ecran: 0xF800 
 {
    
 }
 
// Destructeur //////////////////////////////////////////////////////////////// 
CLTest :: ~CLTest(void)
{
  
}

///////////////////////////////////////////////////////////////////////////////
// void CLTest :: vControleTest(void)
///////////////////////////////////////////////////////////////////////////////
//
// Description: Cette fonction permet de faire le choix entre diverses routines 
//              de tests. 
//
// Parametres d'entrees: null
//            
// Parametres de sortie: null
//
// Appel de la fonction: vControleTest();
//
// Cree le  14 avril 2014 par Louis-Normand Ang Houle 
// 
// Modifications:   
// -
//
/////////////////////////////////////////////////////////////////////////////// 

void CLTest :: vControleTest(void)
 {  
//   vTestGeneral();
//   vTestEcran();
//   vTestI2C();
//   vTestSPI();
//   vTestCommunic();
   vTestCAN(); 
//   vTestVehicule();
 }
 
///////////////////////////////////////////////////////////////////////////////
// void CLTest :: vTestGeneral(void)
///////////////////////////////////////////////////////////////////////////////
//
// Description: Fonction de test 
//
// Parametres d'entrees: null
//            
// Parametres de sortie: null
//
// Appel de la fonction: vTestGeneral();
//
// Cree le  30 septembre 2014 par Louis-Normand Ang Houle 
// 
// Modifications:   
// -
//
/////////////////////////////////////////////////////////////////////////////// 
 
void CLTest :: vTestGeneral(void)
{ 

}
  
///////////////////////////////////////////////////////////////////////////////
// void CLTest :: vTestEcran(void)
///////////////////////////////////////////////////////////////////////////////
//
// Description: Fonction de test du LCD
//
// Parametres d'entrees: null
//            
// Parametres de sortie: null
//
// Appel de la fonction: vTestEcran();
//
// Cree le  4 avril 2014 par Louis-Normand Ang Houle 
// 
// Modifications:   
// -
//
/////////////////////////////////////////////////////////////////////////////// 
 
void CLTest :: vTestEcran(void)
 { 
   UC  ucValeurHex = 0x17;
   USI uiValeurHex = 0xABCD;
   SI  siValeurDec = 1245;
     
   while(1)
    {
      clTestEcran.vLCDCursor(0,1); //Positionne le curseur sur ligne 1 colonne 0
      clTestEcran.vLCDDisplayCarac('T');     //Affiche T
      clTestEcran.vLCDDisplayCarac('E');     //Affiche E
      clTestEcran.vLCDDisplayCarac('S');     //Affiche S
      clTestEcran.vLCDDisplayCarac('T');     //Affiche T
      clTestEcran.vLCDDisplayCarac('S');     //Affiche S  
      
      clTestEcran.vLCDCursor(9,1); //Positionne le curseur sur ligne 1 colonne 10        
      clTestEcran.vLCDDisplayDecimal(siValeurDec);
      
      #ifdef UPSD3254A
      clTestEcran.vLCDCursor(19,1); //Positionne le curseur sur ligne 1 colonne 10  
      clTestEcran.vLCDDisplayCarac(clTestClavier.ucBoutonAppuye());
      #endif
      
      clTestEcran.vLCDCursor(0,2); //Positionne le curseur sur ligne 2 colonne 0
      clTestEcran.vLCDDisplayHexCarac(ucValeurHex);//Affichage val. hexadecimal
     
      clTestEcran.vLCDCursor(10,2);
      clTestEcran.vLCDDisplayHexCarac(uiValeurHex);//Affichage val. hexadecimal
      
      clTestEcran.vLCDCursor(0,3);//Positiondne le curseur sur ligne 3 colonne 0
      clTestEcran.vLCDDisplayCaracChain("Je teste l'ecran");//Affichage chaine  
      
      clTestEcran.vLCDCursor(0,4);
      clTestEcran.vLCDDisplayEtatPort(0x77);
      clTestEcran.vLCDCursor(10,4);
      clTestEcran.vLCDDisplayEtatPort(0x55);  

    }
 }
///////////////////////////////////////////////////////////////////////////////
// void CLTest :: vTestI2C(void)
///////////////////////////////////////////////////////////////////////////////
//
// Description: Fonction de test de l'objet du protocole I2C
//
// Parametres d'entrees: null
//            
// Parametres de sortie: null
//
// Appel de la fonction: vTestI2C();
//
// Cree le  4 avril 2014 par Louis-Normand Ang Houle 
// 
// Modifications:   
// -
//
/////////////////////////////////////////////////////////////////////////////// 

void CLTest :: vTestI2C(void)
 {
   #ifdef I2C_DALLAS
   class CLDAC6574    clTestDAC6574;
   class CLADCMAX1236 clTestADCMAX1236;
   class CLIOPCF8574  clTestIOPCF;
   
   USI uiVitesse = 0;       
   while(1)
   {
      clTestEcran.vLCDCursor(0,1);
      clTestEcran.vLCDDisplayCaracChain("TEST I2C");//Affichage chaine  
      clTestEcran.vLCDCursor(0,2);
      clTestEcran.vLCDDisplayEtatPort(clTestIOPCF.ucLireIOPCF());
      clTestEcran.vLCDCursor(0,3);
      clTestEcran.vLCDDisplayHexCarac(clTestADCMAX1236.uiLireValeur(3));
      
      clTestDAC6574.vConfigurerDAC6574(0, 0x0040);
      clTestDAC6574.vConfigurerDAC6574(1, 0x0040);
      clTestDAC6574.vConfigurerDAC6574(2, 0x0040);
      clTestDAC6574.vConfigurerDAC6574(3, 0x0040);
      
      uiVitesse++;
      if(uiVitesse == 1023) uiVitesse = 0;
   }
   #endif
 }
 
///////////////////////////////////////////////////////////////////////////////
// void CLTest :: vTestSPI(void)
///////////////////////////////////////////////////////////////////////////////
//
// Description: Fonction de test de l'objet du protocole SPI
//
// Parametres d'entrees: null
//            
// Parametres de sortie: null
//
// Appel de la fonction: vTestSPI();
//
// Cree le 16 septembre 2014 par Louis-Normand Ang Houle 
// 
// Modifications:   
// -
//
/////////////////////////////////////////////////////////////////////////////// 
 
void CLTest :: vTestSPI(void) 
 {
   #ifdef SPI_DALLAS   
   class CLDAC7554      clTestDAC7554;
   class CLTLV2544      clTestTLV2544;
   class CLMCP23S09     clTestMCP23S09;
   
   USI uiVitesse = 0;
   
   clTestMCP23S09.vSetModeMCP23S09(LECTURE_MCP23S09, 0xFF);
   
   while(1)
   {
      clTestEcran.vLCDCursor(0,1);
      clTestEcran.vLCDDisplayCaracChain("TEST SPI");//Affichage chaine  
      clTestEcran.vLCDCursor(0,2);
      clTestEcran.vLCDDisplayEtatPort(clTestMCP23S09.ucLireMCP23S09());
      clTestEcran.vLCDCursor(0,3);
      clTestEcran.vLCDDisplayHexCarac(clTestTLV2544.uiLireConversion(TLV2554_CAN3));
      
      clTestDAC7554.vWriteChannel(uiVitesse,0);
      clTestDAC7554.vWriteChannel(uiVitesse,1);
      clTestDAC7554.vWriteChannel(uiVitesse,2);
      clTestDAC7554.vWriteChannel(uiVitesse,3);
      
      uiVitesse++;
      if(uiVitesse == 4095) uiVitesse = 0;
   }
   #endif
 }
 
///////////////////////////////////////////////////////////////////////////////
// void CLTest :: vTestCommunic(void) 
///////////////////////////////////////////////////////////////////////////////
//
// Description: Fonction de test de la communication serie
//
// Parametres d'entrees: null
//            
// Parametres de sortie: null
//
// Appel de la fonction: vTestCommunic();
//
// Cree le 24 avril 2014 par Louis-Normand Ang Houle 
// 
// Modifications:   
// -
//
/////////////////////////////////////////////////////////////////////////////// 
 
void CLTest :: vTestCommunic(void)
 {
  
 }
 
///////////////////////////////////////////////////////////////////////////////
// void CLTest :: vTestCAN(void) 
///////////////////////////////////////////////////////////////////////////////
//
// Description: Fonction de test de la communication CAN
//
// Parametres d'entrees: null
//            
// Parametres de sortie: null
//
// Appel de la fonction: vTestCAN();
//
// Cree le 11 novembre 2014 par Louis-Normand Ang Houle 
// 
// Modifications:   
// -
//
/////////////////////////////////////////////////////////////////////////////// 
 
void CLTest :: vTestCAN(void)
 {
#define STATION_2 
   
#ifdef UPSD3254A 
  #ifdef STATION_1
   class CLMCP2515     Can;
   class CLRS232       Serie;
   class CLHorloge1307 Horloge;  
   class CLEcran       Ecran;
   char *ptr;

   
   
   UC  Menu[4][20] = {"H:   M:   S:      ",
                      "                  ",
                      "                  ",
                      "                  "};  
   Ecran.vLCDDisplayScreen(*Menu); 
   while (1)
     {
       Can.LireMCP2515(); 
       if (Serie.ucLireEtatTrame());
        {         
          ptr = Serie.ucpLireTrame();
          Can.Tab[0] = 0x04;              
          for (UC i = 1; i< 6; i++)
           {
            Can.Tab [i] = ptr [ i -1 ];
           }         
          Can.EnvoyerTrameMCP2515 (Can.Tab);         
          Can.Tab[0] = 0x06;
          Can.Tab[1] = Horloge.stTemps.ucHeure;
          Can.Tab[2] = Horloge.stTemps.ucMinute;
          Can.Tab[3] = Horloge.stTemps.ucSeconde;           
          Can.EnvoyerTrameMCP2515 (Can.Tab);  
        }  
        
       switch (Can.Tab [0])
       {
        case 0x06:
         if (Can.Tab [1] == 0x00)
           {
             Horloge.stTemps.ucHeure   =  ((Can.Tab [2] / 10)<<4) + (Can.Tab [2] % 10);             
             Horloge.stTemps.ucMinute  =  ((Can.Tab [3] / 10)<<4) + (Can.Tab [3] % 10);
             Horloge.stTemps.ucSeconde =  ((Can.Tab [4] / 10)<<4) + (Can.Tab [4] % 10);    
           }         
         break;
        case 0xAA:
          Serie.Send (0xAA);        
         break;        
       }
      Horloge.vReadTime ();
      Ecran.vLCDCursor (2,1);
      Ecran.vLCDDisplayHexCarac (Horloge.stTemps.ucHeure);  
      Ecran.vLCDCursor (7,1);
      Ecran.vLCDDisplayHexCarac (Horloge.stTemps.ucMinute);
      Ecran.vLCDCursor (12,1); 
      Ecran.vLCDDisplayHexCarac (Horloge.stTemps.ucSeconde);
     }     
   #endif
  #ifdef STATION_2
    class CLEcran Ecran;
    while (1)
    {
      UC is, io;
      VAR1 = 0xFF;
      VAR2 = 0xFF;
#define OFF 1
#define ON  0  
#define ACTIF 1
#define INACTIF 0

         is = IN_1.ucLireIOPCF();
         io = IN_2.ucLireIOPCF();
         
         Ecran.vLCDCursor (0,1);
         Ecran.vLCDDisplayEtatPort(is);
         Ecran.vLCDCursor (0,2);
         Ecran.vLCDDisplayEtatPort(io);
      if(ucLIRE(BOUTON_DEPART) == ACTIF)
        { 

         Ecran.vLCDDisplayHexCarac((UC) 'A');
         

          while((ucLIRE(BOUTON_ARRET) == INACTIF) || (ucFin == 0))
          {      
            Ecran.vLCDDisplayHexCarac((UC) 'A');	   
            ucECRIRE(LUMIERE_VERTE , ON); 
            while(ucLIRE(DETECTEUR_CAPACITIF_PLATEAU) == INACTIF) ucECRIRE( POUSSOIR_MAGASINBLOC_ENTREE_OUT , ON);
            Ecran.vLCDDisplayHexCarac((UC) 'A');
            ucECRIRE( POUSSOIR_MAGASINBLOC_ENTREE_OUT , OFF);
            
	    ucType = ucLireCapteur();
           
            while(ucLIRE(ELEVATEUR_HAUT) == INACTIF) ucECRIRE( ELEVATEUR_POSITION_HAUTE , ON);
            ucECRIRE(ELEVATEUR_POSITION_HAUTE , OFF);
           
            
	    while(ucLIRE(DETECTEUR_CAPACITIF_PLATEAU) == INACTIF) ucECRIRE( POUSSOIR_MAGASINBLOC_SORTIE_IN , ON);
            ucECRIRE( POUSSOIR_MAGASINBLOC_SORTIE_IN , OFF);
           
            while(ucLIRE(ELEVATEUR_BAS) == INACTIF)  ucECRIRE( ELEVATEUR_POSITION_BASSE , ON);       
            ucECRIRE( ELEVATEUR_POSITION_BASSE , OFF); 
            
            while(ucLIRE(DETECTEUR_OPTIQUE_CHUTE) == INACTIF)  ucECRIRE( RELAIS_CONVOYEUR , ON); 
            ucECRIRE( RELAIS_CONVOYEUR , OFF);
            
            while((  ucLIRE(CYLINDRE_VENTOUSE_BAS_OUT)  == ACTIF ) && (ucLIRE(CYLINDRE_VENTOUSE_HAUT_OUT) == INACTIF))  ucECRIRE( CYLINDRE_VENTOUSE_HAUT_IN , ON);
            ucECRIRE( CYLINDRE_VENTOUSE_HAUT_IN , OFF);
            
            //DRIVE(P0);
            while(ucLIRE(CYLINDRE_VENTOUSE_BAS_OUT) == INACTIF) { ucECRIRE( CYLINDRE_VENTOUSE_BAS_IN , ON);}
            ucECRIRE( CYLINDRE_VENTOUSE_BAS_IN , OFF);
            ucECRIRE( VACUUM_ON , ON);
			
            while((  ucLIRE(CYLINDRE_VENTOUSE_BAS_OUT)  == ACTIF ) && (ucLIRE(CYLINDRE_VENTOUSE_HAUT_OUT) == INACTIF))  ucECRIRE( CYLINDRE_VENTOUSE_HAUT_IN , ON);
            ucECRIRE( CYLINDRE_VENTOUSE_HAUT_IN , OFF);
             //DRIVE(P4);
            ucECRIRE( VACUUM_ON , OFF);
            //DRIVE(P0);
           ucFin = 1;
          }  
        ucFin = 0;
        //OFF = 1;      
        }
    //   Ecran.vLCDDisplayHexCarac('a');              

  #endif  
 #endif 
 }
}
 
///////////////////////////////////////////////////////////////////////////////
// void CLTest :: vTestVehicule(void) 
///////////////////////////////////////////////////////////////////////////////
//
// Description: Fonction de test du bolide
//
// Parametres d'entrees: null
//            
// Parametres de sortie: null
//
// Appel de la fonction: vTestCommunic();
//
// Cree le 11 novembre 2014 par Louis-Normand Ang Houle 
// 
// Modifications:   
// -
//
/////////////////////////////////////////////////////////////////////////////// 
void CLTest :: vTestVehicule(void)
 {
   #ifdef DALLAS89C450
   class CLVehicule clTestVehicule;
   while(1)
    {
      clTestVehicule.vControleBolide();
    }
   #endif
 }



void ucECRIRE( UC ucACTUATEUR , UC ucEtat)
{ 
   switch(ucACTUATEUR)
   {
     case LUMIERE_VERTE:
	 VAR1 = (ucEtat == ON ?  ( VAR1 & 0xFE) :  ( VAR1 | 0x01) );
	 OUT_1.vEcrireIOPCF(VAR1);
     break; 
     
	 case CYLINDRE_VENTOUSE_BAS_IN:
	 VAR1 = (ucEtat == ON ?  VAR1 & 0xBF : VAR1 | 0x40 );
     OUT_2.vEcrireIOPCF( VAR1);
     break;
     
	 case CYLINDRE_VENTOUSE_HAUT_IN:
     VAR1 = ((ucEtat == ON) ?  VAR1 & 0xDF : VAR1 | 0x20 );
	 OUT_2.vEcrireIOPCF( VAR1  );
     break;
     
	 case VACUUM_ON:
	 VAR1 = ((ucEtat == ON) ? VAR1 & 0xEF : VAR1 | 0x10 );
     OUT_2.vEcrireIOPCF( VAR1);
     break;
     
	 case ELEVATEUR_POSITION_BASSE:
     VAR1 = ((ucEtat == ON) ?  VAR1 & 0xF7 : VAR1 | 0x08 );
	 OUT_2.vEcrireIOPCF( VAR1 );
     break;
     
	 case ELEVATEUR_POSITION_HAUTE:
     VAR1 = ((ucEtat == ON) ? VAR1 & 0xFB :  VAR1 | 0x04 );
	 OUT_2.vEcrireIOPCF( VAR1  );
     break;
     
	 case POUSSOIR_MAGASINBLOC_ENTREE_IN:
     VAR1 = ((ucEtat == ON) ?  VAR1 & 0xFD :  VAR1 | 0x02 );
	 OUT_2.vEcrireIOPCF( VAR1 );
     break;
     
	 case POUSSOIR_MAGASINBLOC_SORTIE_IN:
     VAR1 = ((ucEtat == ON) ?  VAR1 & 0xFE : VAR1 | 0x01 );
	 OUT_2.vEcrireIOPCF( VAR1 );
     break;
     
	 case EJECTEUR_BLOC_SORTIE_IN:
     VAR1 = ((ucEtat == ON) ?  VAR1 & 0x7F : VAR1 | 0x80 );
	 OUT_1.vEcrireIOPCF( VAR2  );
     break;
     case RELAIS_CONVOYEUR:
     VAR1 = ((ucEtat == ON) ?  VAR1 & 0xBF : VAR1 | 0x40 );
      OUT_1.vEcrireIOPCF( VAR2);
     break; 
   }
}

UC ucLIRE(UC ucACTUATEUR)
{
   UC ucLecture;
   switch(ucACTUATEUR)
   {
     case CYLINDRE_VENTOUSE_HAUT_OUT :
     ucLecture = IN_2.ucLireIOPCF() & 0x01;
     break;
     
	 case CYLINDRE_VENTOUSE_BAS_OUT :
     ucLecture = IN_2.ucLireIOPCF() & 0x02;
     break;
     
	 case DETECTEUR_MAGNETIQUE_PLATEAU :
     ucLecture = IN_2.ucLireIOPCF() & 0x04;
     break;
     
	 case DETECTEUR_CAPACITIF_PLATEAU :
     ucLecture = IN_2.ucLireIOPCF() & 0x08;
     break;
      
     
	 case EJECTEUR_BLOC_ENTREE_OUT :
     ucLecture = IN_2.ucLireIOPCF() & 0x10;
     break;
     
	 case EJECTEUR_BLOC_SORTIE_OUT :
     ucLecture = IN_2.ucLireIOPCF() & 0x20;
     break;
     
	 case ELEVATEUR_BAS :
     ucLecture = IN_2.ucLireIOPCF() & 0x40;
     break;
     
	 case ELEVATEUR_HAUT :
     ucLecture = IN_2.ucLireIOPCF() & 0x80;
     break;
     
     
     case POUSSOIR_MAGASINBLOC_ENTREE_OUT :
     ucLecture = IN_1.ucLireIOPCF() & 0x01;
     break;
     
	 case POUSSOIR_MAGASINBLOC_SORTIE_OUT :
     ucLecture = IN_2.ucLireIOPCF() & 0x02;
     break;
     
	 case DETECTEUR_OPTIQUE_PLATEAU :
     ucLecture = IN_2.ucLireIOPCF() & 0x04;
     break;
     
	 case DETECTEUR_OPTIQUE_CHUTE :
     ucLecture = IN_2.ucLireIOPCF() & 0x08;
     break;
      
     case BOUTON_DEPART :
     ucLecture = IN_2.ucLireIOPCF() & 0x10;
     break;
     
	 case BOUTON_ARRET :
     ucLecture = IN_2.ucLireIOPCF() & 0x20;
     break;
     
	 case INDICATIONPRESSION :
     ucLecture = IN_2.ucLireIOPCF() & 0x40;
     break;
     
	 case DETECTEUR_HAUTEUR :
     ucLecture = IN_2.ucLireIOPCF() & 0x80;
     break; 
   } 
   return ((ucLecture == 0) ? INACTIF : ACTIF); 
  }
  
  
  void vDrive(UC ucPostion)
  {
    
  
  
  
  
  }
  
  
  UC ucLireCapteur(void)
  {
    if((ucLIRE(DETECTEUR_MAGNETIQUE_PLATEAU) == ACTIF) && (ucLIRE(DETECTEUR_CAPACITIF_PLATEAU) == ACTIF)) return(METAL);
    if(ucLIRE(DETECTEUR_OPTIQUE_PLATEAU) == ACTIF)return(NOIR);
    if((ucLIRE(DETECTEUR_MAGNETIQUE_PLATEAU) == INACTIF) && (ucLIRE(DETECTEUR_CAPACITIF_PLATEAU) == ACTIF) && (ucLIRE(DETECTEUR_OPTIQUE_PLATEAU) == INACTIF)) return(ORANGE);
    return(0xFF);
  }

 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
