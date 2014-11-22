// ********************** FICHIER: CLPcf8574.h******************************
// Descrtiption : La classe contient des fonctions pour controler le PCF
//              : 8574 sur le suiveur de ligne et sur le bolide
//
// Composition  : CLI2CPort
//
// Heritage     : Aucun
//
// Fonctions    : void vWritePCF8574 (ucAdresse, ucDonnee)//Ecrit Adr, Donnee
//                UC ucReadPCF8574 (UC ucAdresse)  //Read un canal du ADC
//
//  AUTEUR :Gabriel Fortin-Bélanger
//  DATE CREATION :    12/02/2014		 VERSION: 1.0
//
// ****************************************************************************

#ifndef CLIOPCF8574H
#define CLIOPCF8574H

#include "CLI2CPort.h"
#include "_DeclarationGenerale.h"
class CLIOPcf8574 : public CLI2CPort
 {
   public :
    CLIOPcf8574(void);
    ~CLIOPcf8574(void);
    CLIOPcf8574(UC ucAdresse, UC ucDonnee);
    
    void vWritePCF8574(UC ucAdresse, UC ucDonnee);
    UC ucReadPCF8574(UC ucAdrChip, US usiAdrDepart,UC ucTypeAdr);
    
   protected :
   
   private :
     UC ucAdressePCF8574; //Donnee membre, adresse PCF8574, membre privee
 };

#endif