// ************************** FICHIER: CLInOutBase.CPP  ************************
// *****************************************************************************
#include "CLInOutBase.h"

void CLInOutBase :: vOutPort(USI uiAdresse, UC ucData)
{
UC xdata *ucpPointeur;         //Initialisation pointeur sur memoire externe

ucpPointeur  = (UC xdata *) uiAdresse;// Adressage de la case memoire
*ucpPointeur = ucData;                // Ecriture de bits sur le bus de donnees
}

UC CLInOutBase :: ucInPort(USI uiAdresse)
{
UC xdata *ucpPointeur;         //Initialisation pointeur sur memoire externe
UC ucData   = 0;               //Initialisation d'une variable de reception
ucpPointeur = (UC xdata *)uiAdresse; //Adressage de la case memoire
ucData      = *ucpPointeur;          //Lecture de bits sur le bus de donnees
return ucData;
}

void CLInOutBase :: vOut(USI uiAdresse, UC ucData)
{
vOutPort(uiAdresse, ucData);
}

void CLInOutBase :: vOut(USI uiAdresse, USI uiDonnee, UC ucTypeTransfert)
{
union UNEntierOctet unData;
unData.uiEntier = uiDonnee;

if(ucTypeTransfert == SAMELSB)
  {
   vOutPort(uiAdresse, unData.stDoubleOctet.ucOctet1);
   vOutPort(uiAdresse, unData.stDoubleOctet.ucOctet1);
  }

if(ucTypeTransfert == SAMEMSB)
  {
   vOutPort(uiAdresse, unData.stDoubleOctet.ucOctet2);
   vOutPort(uiAdresse, unData.stDoubleOctet.ucOctet2);
  }

if(ucTypeTransfert == SUITELSB)
  {
   vOutPort(uiAdresse, unData.stDoubleOctet.ucOctet1);
   vOutPort(uiAdresse, unData.stDoubleOctet.ucOctet2);
  }

if(ucTypeTransfert == SUITEMSB)
  {
   vOutPort(uiAdresse, unData.stDoubleOctet.ucOctet2);
   vOutPort(uiAdresse, unData.stDoubleOctet.ucOctet1);
  }
}

UC CLInOutBase :: ucIn(USI uiAdresse)
{
UC ucData = 0;                 //Initialisation d'une variable de reception
ucData    = ucInPort(uiAdresse);
return ucData;
}

UC CLInOutBase :: ucIn(USI uiAdresse, UC ucTypeTransfert)
{
union UNEntierOctet unData;
unData.uiEntier = 0x00;

unData.stDoubleOctet.ucOctet1 = 0x00;
unData.stDoubleOctet.ucOctet2 = 0x00;

if(ucTypeTransfert == SAMELSB)
  {
   unData.stDoubleOctet.ucOctet1 = ucInPort(uiAdresse);
   unData.stDoubleOctet.ucOctet1 = ucInPort(uiAdresse);
  }

if(ucTypeTransfert == SAMEMSB)
  {
   unData.stDoubleOctet.ucOctet2 = ucInPort(uiAdresse);
   unData.stDoubleOctet.ucOctet2 = ucInPort(uiAdresse);
  }

if(ucTypeTransfert == SUITELSB)
   {
    unData.stDoubleOctet.ucOctet1 = ucInPort(uiAdresse);
    unData.stDoubleOctet.ucOctet2 = ucInPort(uiAdresse);
   }

if(ucTypeTransfert == SUITEMSB)
  {
   unData.stDoubleOctet.ucOctet2 = ucInPort(uiAdresse);
   unData.stDoubleOctet.ucOctet1 = ucInPort(uiAdresse);
  }
return unData.uiEntier;
}
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX

