//************************** FICHIER: CLMCP23S09.CPP ***********************
//
// Fonctions pour l'extension d'I/O SPI MCP23S09
//
// Application realisee avec IAR C++ 8.10
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
// DATE CREATION : 2014/11/11 VERSION: 1.0
// DATE MODIFICATION: ****-**-**
//
// *****************************************************************************

#include "CLMCP23S09.h"

// Constructeur par defaut ////////////////////////////////////////////////////

CLMCP23S09 :: CLMCP23S09(void)
 {
     SLVSLCT_MCP23S09 = 1;  
 }

// Destructeur ////////////////////////////////////////////////////////////////

CLMCP23S09 :: ~CLMCP23S09(void)
 {
 }

///////////////////////////////////////////////////////////////////////////////
// UC ucLireMCP23S09(void);
///////////////////////////////////////////////////////////////////////////////
//
// Description: Lecture du I/O expander
//
// Parametres d'entrees: null
//
// Parametres de sortie: 
// -UC ucLecture: Donnees recues du MCP23S09
//
// Appel de la fonction: void (void);
//
// Cree le 2014/11/11 par Louis-Normand Ang Houle
//
// Modifications:
// -
//
///////////////////////////////////////////////////////////////////////////////

void CLMCP23S09 :: vSetModeMCP23S09(UC ucMode, UC ucPort)
{
  switch(ucMode)
  {
  case LECTURE_MCP23S09:
     SLVSLCT_MCP23S09 = 0;
      ucSPITransferMOD0(0x40); // Adresse de I/O expander
      ucSPITransferMOD0(0x00); // Va dans le registe I/O direction 
      ucSPITransferMOD0(ucPort); // Les mets en lecture
     SLVSLCT_MCP23S09 = 1;      
     
     SLVSLCT_MCP23S09 = 0;
      ucSPITransferMOD0(0x40); // Adresse de I/O expander
      ucSPITransferMOD0(0x01); 
      ucSPITransferMOD0(0x00); 
     SLVSLCT_MCP23S09 = 1;    
     
     SLVSLCT_MCP23S09 = 0;
      ucSPITransferMOD0(0x40); // Adresse de I/O expander
      ucSPITransferMOD0(0x06); // Va dans le registre des pull-up
      ucSPITransferMOD0(0x00); // Desactive les pull-up
     SLVSLCT_MCP23S09 = 1;     
    break;
  
  case ECRITURE_MCP23S09:
      SLVSLCT_MCP23S09 = 0;
      ucSPITransferMOD0(0x40); // Adresse de I/O expander
      ucSPITransferMOD0(0x00); // Va dans le registe I/O direction 
      ucSPITransferMOD0(ucPort ^= 0xFF); // Les mets tous en ecriture
     SLVSLCT_MCP23S09 = 1;
     
     SLVSLCT_MCP23S09 = 0;
      ucSPITransferMOD0(0x40); // Adresse de I/O expander
      ucSPITransferMOD0(0x01);  
      ucSPITransferMOD0(0x00); 
     SLVSLCT_MCP23S09 = 1;   
     
     SLVSLCT_MCP23S09 = 0;
      ucSPITransferMOD0(0x40); // Adresse de I/O expander
      ucSPITransferMOD0(0x06); // Va dans le registre des pull-up
      ucSPITransferMOD0(0x00); // Desactive les pull-up
     SLVSLCT_MCP23S09 = 1;  
 
     SLVSLCT_MCP23S09 = 0;
      ucSPITransferMOD0(0x40); // Adresse de I/O expander
      ucSPITransferMOD0(0x0A); // Va dans le registe I/O direction 
      ucSPITransferMOD0(ucPort ^= 0xFF); // Les mets en ecriture
     SLVSLCT_MCP23S09 = 1;   
    break;
  }
}

///////////////////////////////////////////////////////////////////////////////
// UC ucLireMCP23S09(void);
///////////////////////////////////////////////////////////////////////////////
//
// Description: Lecture du I/O expander
//
// Parametres d'entrees: null
//
// Parametres de sortie: 
// -UC ucLecture: Donnees recues du MCP23S09
//
// Appel de la fonction: void (void);
//
// Cree le 2014/11/11 par Louis-Normand Ang Houle
//
// Modifications:
// -
//
///////////////////////////////////////////////////////////////////////////////

UC CLMCP23S09 :: ucLireMCP23S09(void)
 { 
   UC ucLecture;
   SLVSLCT_MCP23S09 = 0;
    ucSPITransferMOD0(0x41);      // Lit la puce
    ucSPITransferMOD0(0x09);      // Lit le registre des I/O
    ucLecture = ucSPITransferMOD0(0x00); // Aquiert la donnée
   SLVSLCT_MCP23S09 = 1;
  
   return(ucLecture);
 }

///////////////////////////////////////////////////////////////////////////////
// void vEcrireMCP23S09(UC ucDonnee);
///////////////////////////////////////////////////////////////////////////////
//
// Description: Ecriture sur le I/O expander
//
// Parametres d'entrees: 
// -UC ucDonnee: Donnees envoye sur le MCP23S09
//
// Parametres de sortie: null
//
// Appel de la fonction: void (void);
//
// Cree le 2014/11/11 par Louis-Normand Ang Houle
//
// Modifications:
// -
//
///////////////////////////////////////////////////////////////////////////////

void CLMCP23S09 :: vEcrireMCP23S09(UC ucDonnee)
 {
   SLVSLCT_MCP23S09 = 0;
    ucSPITransferMOD0(0x40);      // Ecrit sur la puce
    ucSPITransferMOD0(0x09);      // Ecrit sur le registre des I/O
    ucSPITransferMOD0(ucDonnee);  // Envoi de la donnee
   SLVSLCT_MCP23S09 = 1;
 }

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@