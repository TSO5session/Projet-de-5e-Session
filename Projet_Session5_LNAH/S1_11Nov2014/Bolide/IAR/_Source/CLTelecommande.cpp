#include "CLTelecommande.h"

CLTelecommande :: CLTelecommande(void):
 clEcranuPSD(0xF800),
 clCommunicuPSD(5,5,9600)
 {
    clInclinometre.vInitialiseInclinometre();
    ucChoix = '0';
    ucTouchePese = '5';
    ucVitesseTourne = 100;
    ucVitesse       = 100;
 }

CLTelecommande :: ~CLTelecommande (void)
 {}   

////////////////////////////////////////////////////////////////////////////////
 
void CLTelecommande :: vControleTelecommande(void)
{
 char cTransmission[6];
 UC ucChecksumHI;
 UC ucChecksumLO;
 
 clInclinometre.vMultiplexageLed();
 
 clEcranuPSD.vLCDCursor(0,1);
 clEcranuPSD.vLCDDisplayCaracChain("TELECOMMANDE uPSD");//Affichage chaine  
 
 clEcranuPSD.vLCDCursor(0,3);
 clEcranuPSD.vLCDDisplayHexCarac(ucVitesse);
 clEcranuPSD.vLCDCursor(10,3);
 clEcranuPSD.vLCDDisplayHexCarac(ucVitesseTourne);
 
 if(clClavier.ucBoutonAppuye() != NULL) 
  {
    ucTouchePese = clClavier.ucBoutonAppuye();
    clEcranuPSD.vLCDCursor(0,2);
    clEcranuPSD.vLCDDisplayCarac(ucTouchePese);
  }
 

 switch(ucTouchePese)
  {
   case 'A': // Mode suiveur de ligne
      clEcranuPSD.vHexToASCII(clCommunicuPSD.ucCheckSumCalcul('A', '0', '0'),
                              &ucChecksumHI,&ucChecksumLO);
      cTransmission[0] = 'A';
      cTransmission[1] = '0';
      cTransmission[2] = '0';
      cTransmission[3] = ucChecksumHI; 
      cTransmission[4] = ucChecksumLO;
      cTransmission[5] = '\0';
       
      clCommunicuPSD.vTransString (cTransmission); 
      
      ucAncienneTouche = ucTouchePese;
      
      clEcranuPSD.vLCDCursor(0,4);
      clEcranuPSD.vLCDDisplayCaracChain("                    ");            
      clEcranuPSD.vLCDCursor(0,4);
      clEcranuPSD.vLCDDisplayCaracChain("Mode suiveur ligne");//Affichage chaine  
   break;
     
   case 'B': // Controle manuel

      cTransmission[0] = 'M';
      cTransmission[1] = clInclinometre.clADCuPSD.ucConversion(CANAL0);
      cTransmission[2] = clInclinometre.clADCuPSD.ucConversion(CANAL1);
      
      clEcranuPSD.vHexToASCII
      (clCommunicuPSD.ucCheckSumCalcul
      (cTransmission[0],cTransmission[1],cTransmission[2]),
       &ucChecksumHI,&ucChecksumLO);
      
      cTransmission[3] = ucChecksumHI; 
      cTransmission[4] = ucChecksumLO;
      cTransmission[5] = '\0';
      
      for(UC i = 0; i < 10; i++) clCommunicuPSD.vTransString (cTransmission);      
      ucAncienneTouche = ucTouchePese;
      clEcranuPSD.vLCDCursor(0,4);
      clEcranuPSD.vLCDDisplayCaracChain("                    ");            
      clEcranuPSD.vLCDCursor(0,4);
      clEcranuPSD.vLCDDisplayCaracChain("Mode Inclinometre");//Affichage chaine  
   break;
   
   case 'C': // Mode suivi(capteur infrarouge) 
      clEcranuPSD.vHexToASCII(clCommunicuPSD.ucCheckSumCalcul('U', '0', '0'),
                              &ucChecksumHI,&ucChecksumLO);
      cTransmission[0] = 'U';
      cTransmission[1] = '0';
      cTransmission[2] = '0';
      cTransmission[3] = ucChecksumHI; 
      cTransmission[4] = ucChecksumLO;
      cTransmission[5] = '\0';
        
      clCommunicuPSD.vTransString (cTransmission); 
      ucAncienneTouche = ucTouchePese;
      
      clEcranuPSD.vLCDCursor(0,4);
      clEcranuPSD.vLCDDisplayCaracChain("                    ");            
      clEcranuPSD.vLCDCursor(0,4);
      clEcranuPSD.vLCDDisplayCaracChain("Mode suiveur");//Affichage chaine  
   break;
   
   case 'D': // Mode evitement(capteur infrarouge)
      clEcranuPSD.vHexToASCII(clCommunicuPSD.ucCheckSumCalcul('E', '0', '0'),
                              &ucChecksumHI,&ucChecksumLO);
      cTransmission[0] = 'E';
      cTransmission[1] = '0';
      cTransmission[2] = '0';
      cTransmission[3] = ucChecksumHI; 
      cTransmission[4] = ucChecksumLO;
      cTransmission[5] = '\0';
       
      clCommunicuPSD.vTransString (cTransmission);    
      ucAncienneTouche = ucTouchePese;
      
      clEcranuPSD.vLCDCursor(0,4);
      clEcranuPSD.vLCDDisplayCaracChain("                    ");            
      clEcranuPSD.vLCDCursor(0,4);
      clEcranuPSD.vLCDDisplayCaracChain("Mode évitement");//Affichage chaine  
   break; 
   
    case '2': // Avance
      clEcranuPSD.vHexToASCII(clCommunicuPSD.ucCheckSumCalcul('F', '0', '0'),
                              &ucChecksumHI,&ucChecksumLO);
      cTransmission[0] = 'F';
      cTransmission[1] = '0';
      cTransmission[2] = '0';
      cTransmission[3] = ucChecksumHI; 
      cTransmission[4] = ucChecksumLO;
      cTransmission[5] = '\0';      
        
      clCommunicuPSD.vTransString (cTransmission);
      ucAncienneTouche = ucTouchePese;
      
      clEcranuPSD.vLCDCursor(0,4);
      clEcranuPSD.vLCDDisplayCaracChain("                    ");            
      clEcranuPSD.vLCDCursor(0,4);
      clEcranuPSD.vLCDDisplayCaracChain("Avant");//Affichage chaine  
   break;

   case '4':  // Tourne a gauche
      clEcranuPSD.vHexToASCII(clCommunicuPSD.ucCheckSumCalcul('G', '0', '0'),
                              &ucChecksumHI,&ucChecksumLO);
      cTransmission[0] = 'G';
      cTransmission[1] = '0';
      cTransmission[2] = '0';
      cTransmission[3] = ucChecksumHI; 
      cTransmission[4] = ucChecksumLO;
      cTransmission[5] = '\0';      
        
      clCommunicuPSD.vTransString (cTransmission); 
      ucAncienneTouche = ucTouchePese;
      
      clEcranuPSD.vLCDCursor(0,4);
      clEcranuPSD.vLCDDisplayCaracChain("                    ");            
      clEcranuPSD.vLCDCursor(0,4);
      clEcranuPSD.vLCDDisplayCaracChain("Gauche");//Affichage chaine  
   break;

   case '5':  // Mode arret
      clEcranuPSD.vHexToASCII(clCommunicuPSD.ucCheckSumCalcul('S', '0', '0'),
                              &ucChecksumHI,&ucChecksumLO);
      cTransmission[0] = 'S';
      cTransmission[1] = '0';
      cTransmission[2] = '0';
      cTransmission[3] = ucChecksumHI; 
      cTransmission[4] = ucChecksumLO;
      cTransmission[5] = '\0';      
        
      clCommunicuPSD.vTransString (cTransmission); 
      ucAncienneTouche = ucTouchePese;
      clEcranuPSD.vLCDCursor(0,4);
      clEcranuPSD.vLCDDisplayCaracChain("                    ");            
      clEcranuPSD.vLCDCursor(0,4);
      clEcranuPSD.vLCDDisplayCaracChain("Arret");//Affichage chaine  
   break;

   case '6':  // Tourne a droite
      clEcranuPSD.vHexToASCII(clCommunicuPSD.ucCheckSumCalcul('D', '0', '0'),
                              &ucChecksumHI,&ucChecksumLO);
      cTransmission[0] = 'D';
      cTransmission[1] = '0';
      cTransmission[2] = '0';
      cTransmission[3] = ucChecksumHI; 
      cTransmission[4] = ucChecksumLO;
      cTransmission[5] = '\0';      
        
      clCommunicuPSD.vTransString (cTransmission); 
      ucAncienneTouche = ucTouchePese;
      
      clEcranuPSD.vLCDCursor(0,4);
      clEcranuPSD.vLCDDisplayCaracChain("                    ");            
      clEcranuPSD.vLCDCursor(0,4);
      clEcranuPSD.vLCDDisplayCaracChain("Droite");//Affichage chaine  
   break;
   
   case '8':  // Mode recule
      clEcranuPSD.vHexToASCII(clCommunicuPSD.ucCheckSumCalcul('R', '0', '0'),
                              &ucChecksumHI,&ucChecksumLO);
      cTransmission[0] = 'R';
      cTransmission[1] = '0';
      cTransmission[2] = '0';
      cTransmission[3] = ucChecksumHI; 
      cTransmission[4] = ucChecksumLO;
      cTransmission[5] = '\0';      
        
      clCommunicuPSD.vTransString (cTransmission); 
      ucAncienneTouche = ucTouchePese;
      
      clEcranuPSD.vLCDCursor(0,4);
      clEcranuPSD.vLCDDisplayCaracChain("                    ");            
      clEcranuPSD.vLCDCursor(0,4);
      clEcranuPSD.vLCDDisplayCaracChain("Recule");//Affichage chaine  
   break;
   
    case '#':  // Vitesse UP
      if((ucVitesse < 100) && (ucChoix == '0')) 
       {
         ucVitesse ++;
         cTransmission[0] = 'V';
         cTransmission[1] = ucChoix;
         cTransmission[2] = ucVitesse;
       }
          
      if((ucVitesseTourne < 100) && (ucChoix == '1'))
       {
         ucVitesseTourne ++;
         cTransmission[0] = 'V';
         cTransmission[1] = ucChoix;
         cTransmission[2] = ucVitesseTourne;            
       } 
          
      clEcranuPSD.vHexToASCII
      (clCommunicuPSD.ucCheckSumCalcul
      (cTransmission[0],cTransmission[1],cTransmission[2]),
       &ucChecksumHI,&ucChecksumLO);
      
      cTransmission[3] = ucChecksumHI; 
      cTransmission[4] = ucChecksumLO;
      cTransmission[5] = '\0';
      for(UC i = 0; i < 50; i++) clCommunicuPSD.vTransString (cTransmission);

      ucTouchePese = ucAncienneTouche;  
   break;
   
   case '*':  // Vitesse DOWN
      if((ucVitesse > 0) && (ucChoix == '0')) 
       {
         ucVitesse --;
         cTransmission[0] = 'V';
         cTransmission[1] = ucChoix;
         cTransmission[2] = ucVitesse;
       }
          
      if((ucVitesseTourne > 0) && (ucChoix == '1'))
       {
         ucVitesseTourne --;
         cTransmission[0] = 'V';
         cTransmission[1] = ucChoix;
         cTransmission[2] = ucVitesseTourne;            
       } 
          
      clEcranuPSD.vHexToASCII
      (clCommunicuPSD.ucCheckSumCalcul
      (cTransmission[0],cTransmission[1],cTransmission[2]),
       &ucChecksumHI,&ucChecksumLO);
      
      cTransmission[3] = ucChecksumHI; 
      cTransmission[4] = ucChecksumLO;
      cTransmission[5] = '\0';
      
      for(UC i = 0; i < 50; i++) clCommunicuPSD.vTransString (cTransmission); 
      ucTouchePese = ucAncienneTouche;        
   break;
   
   case '1':
      clEcranuPSD.vHexToASCII(clCommunicuPSD.ucCheckSumCalcul('P', '0', '0'),
                              &ucChecksumHI,&ucChecksumLO);
      cTransmission[0] = 'P';
      cTransmission[1] = '0';
      cTransmission[2] = '0';
      cTransmission[3] = ucChecksumHI; 
      cTransmission[4] = ucChecksumLO;
      cTransmission[5] = '\0';      
        
      clCommunicuPSD.vTransString (cTransmission); 
      ucAncienneTouche = ucTouchePese; 
      
      clEcranuPSD.vLCDCursor(0,4);
      clEcranuPSD.vLCDDisplayCaracChain("                    ");            
      clEcranuPSD.vLCDCursor(0,4);
      clEcranuPSD.vLCDDisplayCaracChain("Mode Manuel");//Affichage chaine  
      
   break; 
   
   case '3':
      clEcranuPSD.vHexToASCII(clCommunicuPSD.ucCheckSumCalcul('T', '0', '0'),
                              &ucChecksumHI,&ucChecksumLO);
      
      cTransmission[0] = 'T';
      cTransmission[1] = '0';
      cTransmission[2] = '0';
      cTransmission[3] = ucChecksumHI; 
      cTransmission[4] = ucChecksumLO;
      cTransmission[5] = '\0';      
        
      clCommunicuPSD.vTransString (cTransmission); 
      ucAncienneTouche = ucTouchePese; 
      
      clEcranuPSD.vLCDCursor(0,4);
      clEcranuPSD.vLCDDisplayCaracChain("                    ");            
      clEcranuPSD.vLCDCursor(0,4);
      clEcranuPSD.vLCDDisplayCaracChain("Mode Technicien");//Affichage chaine  
   break;
   
   case '0':
      if(ucChoix == '1') ucChoix = '0';
      else               ucChoix = '1';
      
      ucTouchePese = ucAncienneTouche;    
   break;
   
   case '7':
   break;
   
   case '9':
   break;
  }  
  clEcranuPSD.vLCDCursor(4,2);
  clEcranuPSD.vLCDDisplayCaracChain(cTransmission);
}
