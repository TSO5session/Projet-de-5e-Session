// ************************** FICHIER: CLSERIALPORTINTERFACE.CPP **************
//
// Fonctions pour le serial port interface
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
// DATE CREATION : 2014/09/15 VERSION: 1.0
// DATE MODIFICATION: ****-**-**
//
// *****************************************************************************
#include "CLSerialPortInterface.h"

// Constructeur par defaut ////////////////////////////////////////////////////
CLSerialPortInterface :: CLSerialPortInterface(void)
{
SCLK = 0;
MISO = 0;
}
 
// Destructeur ////////////////////////////////////////////////////////////////
CLSerialPortInterface :: ~CLSerialPortInterface(void)
{
  
}

///////////////////////////////////////////////////////////////////////////////
//
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
// Cree par Louis-Normand Ang Houle
//
// Modifications:
// -
//
///////////////////////////////////////////////////////////////////////////////
UC CLSerialPortInterface :: ucSPITransferMOD0(UC ucSPIbyte)
{
for (UC ucSPIcount = 8; ucSPIcount > 0; ucSPIcount--)
  {
   if(ucSPIbyte & 0x80) MOSI = 1;
   else                 MOSI = 0;
   ucSPIbyte = ucSPIbyte << 1; 
      
   SCLK = 1;      
   ucSPIbyte |= MISO;      
   SCLK = 0;
  }
return (ucSPIbyte);
} 

///////////////////////////////////////////////////////////////////////////////
//
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
UC CLSerialPortInterface :: ucSPITransferMOD1(UC ucSPIbyte)
 {

   for (UC ucSPIcount = 8; ucSPIcount > 0; ucSPIcount--)
    {
      SCLK = 1; 
      
      if(ucSPIbyte & 0x80) MOSI = 1;
      else                 MOSI = 0;
      ucSPIbyte = ucSPIbyte << 1; 
      
      SCLK = 0;
      ucSPIbyte |= MISO; 
     }
   return (ucSPIbyte);
 } 

///////////////////////////////////////////////////////////////////////////////
//
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
UC CLSerialPortInterface :: ucSPITransferMOD2(UC ucSPIbyte)
 {
   for (UC ucSPIcount = 8; ucSPIcount > 0; ucSPIcount--)
    {
      if(ucSPIbyte & 0x80) MOSI = 1;
      else                 MOSI = 0;
      ucSPIbyte = ucSPIbyte << 1;     
      
      SCLK = 0;
      
      ucSPIbyte |= MISO; 
      
      SCLK = 1; 
     }
   return (ucSPIbyte);
 }

///////////////////////////////////////////////////////////////////////////////
//
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
UC CLSerialPortInterface :: ucSPITransferMOD3(UC ucSPIbyte)
 {
   for (UC ucSPIcount = 8; ucSPIcount > 0; ucSPIcount--)
    {
      SCLK = 0; 
      
      if(ucSPIbyte & 0x80) MOSI = 1;
      else                 MOSI = 0;
      ucSPIbyte = ucSPIbyte << 1; 
      
      SCLK = 1;
      ucSPIbyte |= MISO;  
     }
   return (ucSPIbyte);
 } 

UC CLSerialPortInterface :: WriteMPC (UC Data)
{
UC maVar = 0           ;  
CS = LOW               ; // Selectionne le MPC via chip select
Write(0x40, 0)         ; // Envoie l'adresse du boitier
Write(0x09, 0)         ; // Envoie l'adresse du reistre des IO
maVar = Write(Data, 0) ; // Envoie la donnee
CS = HIGH              ; // End chip select
return(maVar)          ; // Envoie la donnee hexa a ecrire sur les IO
}

UC CLSerialPortInterface :: ReadMPC (void)
{
CS       = LOW            ; // Selectionne le MPC via chip select  
Write(0x41, 0)            ; // Envoie l'adresse du boitier
Write(0x09, 0)            ; // Envoie l'adresse du reistre des IO
UC maVar = Write(NULL, 0) ; // Lit le contenu du MPC
CS       = HIGH           ; // End chip select
return(maVar); // Lit la donnee hexa a correspondant aux IO
}

UC CLSerialPortInterface :: WriteMPC(UC NombreDonneesEnvoyer, UC Donnee1, UC Donnee2, UC Donnee3)
{
UC i;

UC Donnees[3] = {0x00};
   Donnees[0] = Donnee1;
   Donnees[1] = Donnee2;
   Donnees[2] = Donnee3;

CS = LOW;   // Un chip select

for(i = 0; i < NombreDonneesEnvoyer; i++)
  {
   Write(Donnees[i], 0); // = Donnees[k];
   Delai(1);             // Delai au moins tant que le module du SPI est occupé 
  }

CS = HIGH;   // Un chip select
return(0x01);
}

void CLSerialPortInterface :: Delai(unsigned long Temps)
{
unsigned long k;
for(k = 0; k < Temps; k++);  
}

UC CLSerialPortInterface :: Write(UC ucValeur, UC ucMode)
{
UC i;                               // Pour boucle
UC ucDonneeLue = 0;                 // Pour la donnee a transmettre
//CS             = LOW;

if(ucMode == 0)                     // Si mode 0?
  {
   SCLK  = BAS;                     // Met la clock a 0

   for(i = 0; i < 8; i++)           // Fait 8 fois
     {
      if((ucValeur & 0x80) == 0x80) //fait un masque si egale a 1
        {
         MOSI = 1;                  // Envoie 1
        }
       else                         // Sinon
        {
         MOSI =0;                   // Envoie 0.
        }

       ucValeur    = ucValeur    << 1  ; // Decale la valeur a envoyer
       ucDonneeLue = ucDonneeLue << 1  ; // Decale la valeur lue
       SCLK        = HAUT              ; // Clock a 1
       ucDonneeLue = ucDonneeLue + MISO; // Aditionne l'etat de MISO avec
                                         // le reste de la donnee lue
       SCLK        = BAS               ; // Clock a 0.
     }
   }

if(ucMode == 1)          // Si mode 1?
  {
   SCLK  = HAUT;
   for(i = 0; i < 8; i++)
     {
      ucDonneeLue = ucDonneeLue << 1;
      SCLK        = HAUT;

      if((ucValeur & 0x80) == 0x80)
        {
         MOSI = 1;
        }
      else
        {
         MOSI =0;
        }
      ucDonneeLue = ucDonneeLue + MISO;
      SCLK        = BAS;                // Met la clock a 0
     }
     SCLK         = HAUT;
   }

if(ucMode == 2)          // Si mode 2?
  {
   for(i = 0; i < 8; i++)
     {
      ucDonneeLue = ucDonneeLue << 1;
      if((ucValeur & 0x80) == 0x80)
        {
         MOSI = 1;
        }
      else
        {
         MOSI =0;
        }
       ucDonneeLue = ucDonneeLue + MISO;
       SCLK        = BAS;
       SCLK        = HAUT;
     }
   }

if(ucMode == 3)          // Si mode 3?
  {
   for(i = 0; i < 8; i++)
     {
      ucDonneeLue = ucDonneeLue << 1;
      SCLK        = BAS;
      if((ucValeur & 0x80) == 0x80)
        {
         MOSI = 1;
        }
      else
        {
         MOSI = 0;
        }
      ucDonneeLue = ucDonneeLue + MISO;
      SCLK        = HAUT;
     }
   }
//CS = HIGH;
return(ucDonneeLue);
}

UI CLSerialPortInterface :: Write16(UI uiValeur, UC ucMode)
{
UC i;                      // Pour boucle
UI uiDonneeLue= 0;         // Pour la donnee a transmettre
CS = LOW;
if(ucMode == 0)            // Si mode 0?
  {
   SCLK = BAS;             // Met la clock a 0
   for(i = 0; i < 16; i++) // Fait 8 fois
     {
      if((uiValeur & 0x8000) == 0x8000)//fait un masque si egale a 1
        {
         MOSI = 1;          // Envoie 1
        }
      else                  // Sinon
        {
         MOSI =0;           // Envoie 0.
        }

      uiValeur    = uiValeur    << 1  ;  // Decale la valeur a envoyer
      uiDonneeLue = uiDonneeLue << 1  ;  // Decale la valeur lue
      SCLK        = HAUT              ; // Clock a 1
      uiDonneeLue = uiDonneeLue + MISO; // Aditionne l'etat de MISO avec
                                        // le reste de la donnee lue
      SCLK        = BAS               ; // Clock a 0.
     }
   }

   if(ucMode == 1)          // Si mode 1?
    {
     SCLK = HAUT;
     for(i = 0; i < 16; i++)
       {
        uiDonneeLue = uiDonneeLue << 1;
        SCLK        = HAUT;
        if((uiValeur & 0x8000) == 0x8000)
         {
          MOSI = 1;
         }
        else
         {
          MOSI =0;
         }
        uiDonneeLue = uiDonneeLue + MISO;
        SCLK        = BAS;   // Met la clock a 0
       }
     SCLK = HAUT;
    }
  if(ucMode == 2)          // Si mode 2?
    {
     for(i = 0; i < 16; i++)
       {
        uiDonneeLue = uiDonneeLue << 1;
        if((uiValeur & 0x8000) == 0x8000)
          {
           MOSI = 1;
          }
        else
         {
          MOSI =0;
         }
       uiDonneeLue = uiDonneeLue + MISO;
       SCLK        = BAS;
       SCLK        = HAUT;
      }
   }

   if(ucMode == 3)          // Si mode 3?
     {
      for(i = 0; i < 16; i++)
        {
         uiDonneeLue = uiDonneeLue << 1;
         SCLK        = BAS;
         if((uiValeur & 0x8000) == 0x8000)
           {
            MOSI = 1;
           }
         else
           {
            MOSI =0;
           }
         uiDonneeLue = uiDonneeLue + MISO;
         SCLK        = HAUT;
        }

      }
CS = HIGH;
return(uiDonneeLue);
}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@