// ********************** FICHIER: CLCommunic.cpp ******************************
// Descrtiption : La classe contient des fonctions pour controler le port
//                serie du uPSD ou du DALLAS.
//
// Fonctions    : ucInitLongTrame -- Initialise longueur trame
//                vTransCaractere -- Envoie caractere sur port
//                vTransChaine    -- Envoie chaine sur port
//                *ucpLireTrame   -- Pointeur sur la trame
//                ucLireNbCaract  -- Retourne nombre caract recu
//                ucLireEtatTrame -- Retourne etat reception trame
//                vInterrupt      -- Fonction d'interrupt serie
//                vInitBaudRate   -- Initialise Baud
//                ucValideTrame   -- Retourne etat trame valide
//                
//                
//
//  AUTEUR : Jean-Francois Bilodeau
//  DATE CREATION :    27/03/2014		 VERSION: 1.0
//
// ****************************************************************************
#include "DeclarationGenerale.h"
#ifndef CLCOMMUNICH
 #define CLCOMMUNICH

 #define LONGUEURTRAME 8
 #define LONGUEURBUFFER 16
 #define INITBAUDDEFAUT 9600

class CLCommunic
 {
   public:
     CLCommunic (void);
     CLCommunic (UC ucLongBuf, UC ucLongTrame, UINT16 usiBaud);
     ~CLCommunic (void);
     UC ucInitLongTrame (UC ucLong);
     static UC ucLireNbCaractRecu (void);
     UC ucLireEtatTrame (void);
     UC *ucpLireTrame (void);
     void vResetTampon(void);
     void vTransCaractere (UC ucCar);
     void vTransChaine (const UC *ucpChaine);
     void vTransCarBuffer (UC ucL, char *ucDat);
   protected:
     
     
   private:
     __interrupt static void vInterruptSerial (void);
     void vInitBaudRate (UINT16 usiBaudRate);
     UC ucValideTrame (void);
     UC ucChecksum(const UC *ucpChaine);

     ///////////////////////////////////////////////////////////////////////////
     // MEMBRES STATIQUES
     //
     static UC * ucpTabCaractereRecu;
     static UC * ucpDebutTampon;  
     static UC * ucpFinTampon;   
     static UC * ucpEcrireTampon;
     static UC * ucpLireTampon;
     static UC * ucpLectureTampon;
     static UC ucLongueurBuffer;
     static UC ucLongueurTrame;
     static UC ucNbCaractRecu;
     static UC ucEtatTrame;
 };


#endif