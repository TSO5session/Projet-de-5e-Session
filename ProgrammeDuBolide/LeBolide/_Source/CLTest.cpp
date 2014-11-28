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
   class CLIOPCF8574 IN_1(0x44), IN_2 (0x46), OUT_1 (0x40), OUT_2 (0x42);
     

    UC var = 0x01; 
    while (1)
    {
   //   clTestEcran.vLCDCursor(0,1);
   //   clTestEcran.vLCDDisplayCaracChain("TEST");
   //   clTestEcran.vLCDCursor(0,2);
   //   clTestEcran.vLCDDisplayEtatPort(IN_2.ucLireIOPCF());
   //   clTestEcran.vLCDCursor(10,2);
   //   clTestEcran.vLCDDisplayEtatPort(IN_1.ucLireIOPCF());
      OUT_1.vEcrireIOPCF (0x00);
    //  OUT_2.vEcrireIOPCF (0x00);  
     /* 
      for (UC i=0; i < 8; i++)
       {         
         clTestEcran.vLCDCursor(0,2);
         clTestEcran.vLCDDisplayEtatPort(var);
         clTestEcran.vLCDCursor(0,3);
         clTestEcran.vLCDDisplayEtatPort(IN_1.ucLireIOPCF());
         OUT_1.vEcrireIOPCF (var);
         for (long i=0; i < 65000; i++);
         var = var << 1;
       } 
      var = 0x01; 
      for (UC i=0; i < 8; i++)
       {      
         clTestEcran.vLCDCursor(10,2);
         clTestEcran.vLCDDisplayEtatPort(var); 
         clTestEcran.vLCDCursor(10,3);
         clTestEcran.vLCDDisplayEtatPort(IN_2.ucLireIOPCF());           
         OUT_2.vEcrireIOPCF (var);
         for (long i=0; i < 65000; i++);
         var = var << 1;
       } 
      var = 0x01; */
    }  
  #endif   
 #endif 
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
 
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
