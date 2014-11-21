


 

// ********************** FICHIER: CLCommunic.h ******************************
// Descrtiption : La classe contient des fonctions pour controler le port
//                serie du uPSD ou du DALLAS.
//
// Fonctions    : ucInitLongTrame -- Initialise longueur trame
//                vTransCaractere -- Envoie caractere sur port
//                vTransChaine    -- Envoie chaine sur port
//                *ucpLireTrame   -- Pointeur sur la trame
//                ucLireNbCaract  -- Retourne nombre caract recu
//                ucLireEtatTrame -- Retourne etat reception trame
//                vInitBaudRate   -- Initialise Baud
//                ucValideTrame   -- Retourne etat trame valide
//                __interrupt void CLCommunic :: vInterruptSerial (void)
//                
//                
//                
//
//  AUTEUR :Gabriel Fortin-Belanger
//  DATE CREATION :    27/03/2014		 VERSION: 1.0
//
// ****************************************************************************


#ifndef CLCOMMUNICH
   #define  CLCOMMUNICH
   #include "_DeclarationGenerale.h"



class CLCommunic
{
   public:
     CLCommunic(void);
     CLCommunic(UC ucLongBuf, UC ucLongTrame,UINT uiBaud);
     ~CLCommunic(void);
     UC ucInitLongTrame(UC ucLong);
     UC ucLireNbCaractRecu(void);
     UC ucLireEtatTrame(void);
     UC *ucpLireTrame(void);
     void vTransCaractere(UC ucCar);
     void vTransString(char const *ucChaine);
     
   private:
   //  __interrupt static void vInteruptSerial(void);
     void vInitBaudRate(UINT uiBaud);
     UC ucValideTrame(void);
     
     static UC *ucpDebutTampon;
     static UC *ucpFinTampon;
     static UC *ucpEcritureTampon;
     static UC *ucpLireTampon;
     static UC ucLongeurTampon;
     static UC ucLongeurTrame;
     static UC ucCompteurCarac;
     static UC ucTrameRecu;
 
   protected:


};

#endif

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@