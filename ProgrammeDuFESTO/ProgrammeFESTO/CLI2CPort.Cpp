// ************************** FICHIER: CLI2CPORT.CPP ************************
#include "CLI2CPort.h"

// *****************************************************************************
//                            LES CONSTRUCTEURS
// *****************************************************************************
CLI2CPort :: CLI2CPort(void)
{

}

// *****************************************************************************
//                            LE DESTRUCTEUR
// *****************************************************************************
CLI2CPort :: ~CLI2CPort(void)
{

}

///////////////////////////////////////////////////////////////////////////////
// UC CLI2CPort :: ucI2CLireDonnee(UC ucAdrBoitier, UC ucAdrRegistre)
///////////////////////////////////////////////////////////////////////////////
//
// Description:
//
// Parametres d'entrees: null
//
// Parametres de sortie: null
//
// Appel de la fonction:
//
// Cree le  4 avril 2014 par Louis-Normand Ang Houle
//
// Modifications:
// -
//
///////////////////////////////////////////////////////////////////////////////

UC CLI2CPort :: ucI2CLireDonnee(UC ucAdrBoitier, UC ucAdrRegistre)
 {
   UC ucReadOctet = 0;

   vI2CStart();
   while(ucI2CEcrireOctet(ucAdrBoitier + WRITE)== NACK)
    {
      vI2CStart();
    }
   while(ucI2CEcrireOctet(ucAdrRegistre)       == NACK);
   vI2CStart();
   while(ucI2CEcrireOctet(ucAdrBoitier + READ) == NACK)
    {
      vI2CStart();
    }
   ucReadOctet = ucI2CLireOctet(NACK);
   vI2CStop();
   return(ucReadOctet);
 }

///////////////////////////////////////////////////////////////////////////////
//void CLI2CPort :: vI2CLireDonnee(UC ucAdrBoitier, USI uiAdrRegistre,
//                                 UC ucTypeAdr ,UC *ucpRecevoirDonnee,
//                                 UC ucNbrLectures)
///////////////////////////////////////////////////////////////////////////////
//
// Description:
//
// Parametres d'entrees: null
//
// Parametres de sortie: null
//
// Appel de la fonction:
//
// Cree le  4 avril 2014 par Louis-Normand Ang Houle
//
// Modifications:
// -
//
///////////////////////////////////////////////////////////////////////////////

void CLI2CPort :: vI2CLireDonnee(UC ucAdrBoitier,USI uiAdrRegistre,UC ucTypeAdr
                                 ,UC *ucpRecevoirDonnee ,UC ucNbrLectures)
 {
   union UNEntierOctet unAdresse;

   unAdresse.uiEntier = uiAdrRegistre;

//----------------------------------------------------------------------
   switch (ucTypeAdr)
     {
      case PASADR:
       vI2CStart();
       while(ucI2CEcrireOctet(ucAdrBoitier + READ) == NACK)
         {
           vI2CStart();
         }
      break;
//----------------------------------------------------------------------
      case ADR8BIT:
       vI2CStart();
       while(ucI2CEcrireOctet(ucAdrBoitier + WRITE)             == NACK)
         {
           vI2CStart();
         }
       while(ucI2CEcrireOctet(unAdresse.stDoubleOctet.ucOctet1) == NACK);
       vI2CStart();
       while(ucI2CEcrireOctet(ucAdrBoitier + READ)              == NACK)
         {
           vI2CStart();
         }
      break;
//----------------------------------------------------------------------
      case ADR16BIT:
       vI2CStart();
       while(ucI2CEcrireOctet(ucAdrBoitier + WRITE)             == NACK)
         {
           vI2CStart();
         }
       while(ucI2CEcrireOctet(unAdresse.stDoubleOctet.ucOctet1) == NACK);
       while(ucI2CEcrireOctet(unAdresse.stDoubleOctet.ucOctet2) == NACK);
       vI2CStart();
       while(ucI2CEcrireOctet(ucAdrBoitier + READ)              == NACK)
         {
           vI2CStart();
         }
      break;
//----------------------------------------------------------------------
      default:
      break;
    }
//----------------------------------------------------------------------

   if(ucNbrLectures > 1)
    {
      for(UC i = 0; i < ucNbrLectures - 1; i++)
       {
         ucpRecevoirDonnee[i] = ucI2CLireOctet(ACK);
       }
    }
   ucpRecevoirDonnee[ucNbrLectures - 1] = ucI2CLireOctet(NACK);
   vI2CStop();
  }

///////////////////////////////////////////////////////////////////////////////
// void CLI2CPort :: vI2CEcrireDonnee(UC ucAdrBoitier,UC ucAdrRegistre,
//                                    UC ucDonnee)
///////////////////////////////////////////////////////////////////////////////
//
// Description:
//
// Parametres d'entrees: null
//
// Parametres de sortie: null
//
// Appel de la fonction:
//
// Cree le  4 avril 2014 par Louis-Normand Ang Houle
//
// Modifications:
// -
//
///////////////////////////////////////////////////////////////////////////////
void CLI2CPort :: vI2CEcrireDonnee(UC ucAdrBoitier, UC ucAdrRegistre,
                                   UC ucDonnee)
 {
   vI2CStart();
   while(ucI2CEcrireOctet(ucAdrBoitier + WRITE) == NACK)
    {
      vI2CStart();
    }
   while(ucI2CEcrireOctet(ucAdrRegistre)        == NACK);
   while(ucI2CEcrireOctet(ucDonnee)             == NACK);
   vI2CStop();
 }

///////////////////////////////////////////////////////////////////////////////
//void CLI2CPort :: vI2CEcrireDonnee(UC ucAdrBoitier, USI uiAdrRegistre,
//                                   UC ucTypeAdr, UC *ucpDonnee,
//                                   UC ucNbrEcritures)
///////////////////////////////////////////////////////////////////////////////
//
// Description:
//
// Parametres d'entrees: null
//
// Parametres de sortie: null
//
// Appel de la fonction:
//
// Cree le  4 avril 2014 par Louis-Normand Ang Houle
//
// Modifications:
// -
//
///////////////////////////////////////////////////////////////////////////////

void CLI2CPort :: vI2CEcrireDonnee(UC ucAdrBoitier, USI uiAdrRegistre,
                                   UC ucTypeAdr,UC *ucpDonnee,UC ucNbrEcritures)
 {
   union UNEntierOctet unAdresse;

   unAdresse.uiEntier = uiAdrRegistre;
//----------------------------------------------------------------------
   switch (ucTypeAdr)
    {
      case PASADR:
        vI2CStart();
        while(ucI2CEcrireOctet(ucAdrBoitier + WRITE)             == NACK)
         {
           vI2CStart();
         }
      break;
//----------------------------------------------------------------------
      case ADR8BIT:
        vI2CStart();
        while(ucI2CEcrireOctet(ucAdrBoitier + WRITE)             == NACK)
         {
           vI2CStart();
         }
        while(ucI2CEcrireOctet(unAdresse.stDoubleOctet.ucOctet1) == NACK);
      break;
//----------------------------------------------------------------------
      case ADR16BIT:
        vI2CStart();
        while(ucI2CEcrireOctet(ucAdrBoitier + WRITE)             == NACK)
         {
           vI2CStart();
         }
        while(ucI2CEcrireOctet(unAdresse.stDoubleOctet.ucOctet1) == NACK);
        while(ucI2CEcrireOctet(unAdresse.stDoubleOctet.ucOctet2) == NACK);
      break;
//----------------------------------------------------------------------
      default:
      break;
    }
//----------------------------------------------------------------------
   if(ucNbrEcritures > 1)
    {
      for(UC i = 0; i < ucNbrEcritures; i++)
       {
         while(ucI2CEcrireOctet(ucpDonnee[i])== NACK);
       }
    }
   else while(ucI2CEcrireOctet(ucpDonnee[0])== NACK);
   vI2CStop();
 }
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX

