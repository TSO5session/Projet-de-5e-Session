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

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@