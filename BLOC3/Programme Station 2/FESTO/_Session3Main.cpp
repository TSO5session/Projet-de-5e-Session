

// ************************** FICHIER: ProjetSessionCinqMain.CPP  ****
//  Application realisee avec IAR C++ 8.10
//  LABORATOIRE PROJET FIN SESSION
//
//  VITESSE DE COMMUNICATION 19200
//
//  LIMITATION DU COMPILATEUR:
//    Impossible de faire de l'heritage multiple.
//
//  Programme principal.
//
//  Note on peut utiliser XAR pour creer des librairies.
//  On peut mettre les librairies dans le projets et Exclure de la compilation
//  les modules qui sont contenus dans la librairie.
//
//  Pour Windows 7 on utilise la VMware pour programmer le upsd 3254A avec CAPS.
//
//  AUTEUR : Gabriel Fortin-B
//  DATE CREATION :    2012-12-20		 VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
// ************************************************************************
#include "_DeclarationGenerale.h"

#include "_Session3Main.h"
#include <stdio.h>
 

 
void vInit_CPU(void); // initialise le microcontroller
 
   CLSPI clSPI;
   CLEcran clEcran;
   CLADDA clADDA;
   CLDelai clDelai;
   
   

void main(void)
{
  

   
  


    
  int x;
   P1_4 = 1;
   P1_3 =1;
   vInit_CPU();
   UC ucValue;
        
   
   
   P1_4 = 0;
      clSPI.ucSPITransfert(0x00,0x41);
      clSPI.ucSPITransfert(0x00,0x0F);
      P1_4 = 1;
     
      
      
      P1_4 = 0;
        clSPI.ucSPITransfert(0x00,0x00);
        clSPI.ucSPITransfert(0x00,0X00);
       P1_4 = 1;

        
       P1_3 =0;
    
    clSPI.ucSPITransfert(0x00,0x40);
     clSPI.ucSPITransfert(0x00,0x00);
     clSPI.ucSPITransfert(0x00,0xF0);
       P1_3 =1;
    
   while(1)  //faire sans fin
    {

  
     
  
      P1_3 =0;
     clSPI.ucSPITransfert(0x00,0x41);
    clSPI.ucSPITransfert(0x00,0x09);
   clEcran.vLcdPoscurC0L1(0,1);
    
    ucValue = (clSPI.ucSPITransfert(0x00,0xF0) &  0xF0);
    clEcran.vLcdAffCarHex(  ucValue );
  P1_3 =1;
     

      
           P1_4 = 0;
        clSPI.ucSPITransfert(0x00,0x00);
        clSPI.ucSPITransfert(0x00, ucValue);
         P1_4 = 1;

    
      
      
      for( UC i =0;i<127;i++)
      {
         
         P1_4 = 0;
        clSPI.ucSPITransfert(0x00,0x04);
         P1_4 = 1;
      for(x=0;x<30000;x++);
    
     
     }
    
   
     
     for(UC i=127;i>0;i--)
      {
        P1_4 = 0;
         clSPI.ucSPITransfert(0x00,0x08);
         P1_4 = 1;
         for(x=0;x<30000;x++);
  
     
      }
 
   
      
    
    
    }

    }// void main (void)


//************************ TITRE : vInit_CPU    ***************************
//
//  DESCRIPTION :Initialisation du microcontroleur
//
//  NOM: void vInit_CPU (void)
//
//  PARAMETRE D'ENTREE:  AUCUN
//
//  PARAMETRE DE SORTIE: AUCUN
//
//  MEMBRES UTILISES:
//       Fonctions       : AUCUNE
//       Donnees         : AUCUNE
//                      :
//  AUTEUR : DANIEL BRETON
//  DATE CREATION :    2012-12-20		 VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
// ****************************************************************************

void vInit_CPU(void)
{
  #ifdef UPSD3254A
     WDKEY =0x55;  //desactive le watchdog du upsd
  #endif
} // void vInit_CPU (void)


// ****************************************************************************







