//**********************  Fichier: CLSPI.cpp
//  Description  : Fonctions necessaire pour communiquer en SPI.
//
//  Composition  : aucune
//  Heritage     : aucune
//
//  Programmeur  : Vincent Chouinard
//  Cours        : 247-636
//
//  Date         : 22 Octobre 2014
//
//  Compilateur  : IAR 8.1
//
//  Modification :
//
//////////////////////////////////////////////////////////////////////////////
#include "CLSPI.h"                // Inclue le fichier d'entete I2CPort.h.
#include "_DeclarationGenerale.h" // inclue DeclarationGenerale.h
#include "MCP2515.h"              // define des registres du MCP2515
//******************************************************************************
//                            LE CONSTRUCTEUR PAR DEFAUT
// *****************************************************************************
CLSPI :: CLSPI(void)
{
MOSI     = LOW;  // Commence a bas  
MISO     = LOW;  // Commence a bas  
SCLK     = LOW;  // Commence a bas
CS       = HIGH; // Commence a bas
}

//******************************************************************************
//                            LE CONSTRUCTEUR INITIALISATEUR
// *****************************************************************************
CLSPI :: CLSPI(UC Directions)
{
MOSI     = LOW;        // Commence a bas  
MISO     = LOW;        // Commence a bas  
SCLK     = LOW;        // Commence a bas
CS       = HIGH;       // Commence a bas
Direction(Directions); // Initialise les directions
}

// *****************************************************************************
//                            LE DESTRUCTEUR
// *****************************************************************************
CLSPI :: ~CLSPI(void)
{

}

//*****************************************************************************
// Nom de la fct       : vSPIEcire
// Description         : Fonction qui permet de lire et d'ecrire un octet
//                     : sous les 4 different mode SPI
//
// INCLUDE             : #include "_DeclarationGenerale.h", #include "CLSPI.h"
//
// Prototype           : UC ucSPIEcire(UC ucValeur, UC ucMode);
//
//
// Parametre d'entree  : ucValeur pour la valeur a envoyer ucMode pour le mode
//
// Parametre de sortie : ucDonneeLue pour la donnee lue
//
// Procedure appelees  : aucune
//
// Exemple d'appel     : val = clComSPI.ucSPIEcire(0xAA);
//
// Fait par            : Vincent Chouinard
// Date                : 23 septembre 2014
// Revision            : A
// Modification
//*****************************************************************************
UC CLSPI :: Write(UC ucValeur, UC ucMode)
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

UI CLSPI :: Write16(UI uiValeur, UC ucMode)
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

//*****************************************************************************
// Nom de la fct:       : Direction
// Description:         : Fonction qui permet de modifier la direction des ports
//                      : du MCP23S08
//
// INCLUDE:             : #include "_DeclarationGenerale.h", #include "CLSPI.h"
//
// Prototype:           : Direction(UC ucDirection)
//
//
// Parametre d'entree:  : ucDirection pour la direction des I/O.
//
// Parametre de sortie: : aucun
//
// Procedure appelees:  : aucune
//
// Exemple d'appel:     : val = clComSPI.ucSPIEcire(0xAA);
//
// Fait par             : Vincent Chouinard
// Date:                : 23 septembre 2014
// Revision             :
// Modification         :
//*****************************************************************************
void CLSPI :: Direction (UC ucDirection)
{
CS = BAS             ; // Chip select bas
Write(0x40, 0)       ; // Envoie l'adresse du boitier
Write(0x00, 0)       ; // Envoie le registre a modifier
Write(ucDirection, 0); // Envoie la direction
CS = HAUT            ; // Chip Select haut
}

UC CLSPI :: WriteMPC (UC Data)
{
UC maVar = 0           ;  
CS = LOW               ; // Selectionne le MPC via chip select
Write(0x40, 0)         ; // Envoie l'adresse du boitier
Write(0x09, 0)         ; // Envoie l'adresse du reistre des IO
maVar = Write(Data, 0) ; // Envoie la donnee
CS = HIGH              ; // End chip select
return(maVar)          ; // Envoie la donnee hexa a ecrire sur les IO
}

UC CLSPI :: ReadMPC (void)
{
CS       = LOW            ; // Selectionne le MPC via chip select  
Write(0x41, 0)            ; // Envoie l'adresse du boitier
Write(0x09, 0)            ; // Envoie l'adresse du reistre des IO
UC maVar = Write(NULL, 0) ; // Lit le contenu du MPC
CS       = HIGH           ; // End chip select
return(maVar); // Lit la donnee hexa a correspondant aux IO
}

UC CLSPI :: WritePOT (UC Data)
{
CS       = LOW           ; // Selectionne le MPC via chip select  
Write(0x00, 0)           ; // Pour activer le mode ecriture
UC maVar = Write(Data, 0); // Ecrit une valeur sur le POT
CS       = HIGH          ; // Selectionne le MPC via chip select
return(maVar)            ; // Ecrit la valeur sur le POT numerique
}

UC CLSPI :: WriteDAC (UC ucPin, int iData)
{
UC ucHaut;
UC ucBas;
CSDA = LOW; // DAC CHip Select ON

switch (ucPin)
  { 
  case 1:     // Write on DAC A
     ucHaut    = (iData << 8) & 0x000F; 
     ucHaut    = ucHaut |       0x80  ;    
     ucBas     = iData  &       0x00FF;    
     Write(ucHaut, 0);
     Write(ucBas,  0);
  break;
  
  case 2:     // Write on DAC B
     ucHaut    = (iData << 8) & 0x000F; 
     ucHaut    = ucHaut |       0x90  ;    
     ucBas     = iData  &       0x00FF;   
     Write(ucHaut, 0);
     Write(ucBas,  0); 
  break;

  case 3:     // Write on DAC C
     ucHaut    = (iData << 8) & 0x000F; 
     ucHaut    = ucHaut |       0xA0  ;    
     ucBas     = iData  &       0x00FF;   
     Write(ucHaut, 0);
     Write(ucBas,  0); 
  break;

  case 4:     // Write on DAC D
     ucHaut    = (iData << 8) & 0x000F; 
     ucHaut    = ucHaut |       0xB0  ;    
     ucBas     = iData  &       0x00FF;    
     Write(ucHaut, 0);
     Write(ucBas,  0);      
  break;  
 }

CSDA = HIGH;// DAC CHip Select OFF
return(NULL);
}

UC CLSPI :: WriteMPC(UC NombreDonneesEnvoyer, UC Donnee1, UC Donnee2, UC Donnee3)
{
UC i;

UC Donnees[3] = {0x00};
   Donnees[0] = Donnee1;
   Donnees[1] = Donnee2;
   Donnees[2] = Donnee3;

CS = LOW;   // Un chip select

for(i = 0; i < NombreDonneesEnvoyer; i++)
  {
   Write(Donnees[i], 0);      // = Donnees[k];
   Delai(1);   // Delai au moins tant que le module du SPI est occupé 
  }

CS = HIGH;   // Un chip select
return(0x01);
}

void CLSPI :: Delai(unsigned long Temps)
{
unsigned long k;
for(k = 0; k < Temps; k++);  
}
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX

