// ***************** FICHIER:CLI2CPort.cpp
//
//  Description:Contient les fonctions haut niveau pour communiquer avec 
//              l I2C.
//             
//
//  Application realisee avec IAR
//
//  AUTEUR : Gabriel Fortin-Belanger
//  DATE CREATION :    2014-02-07       VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
//******************************************************************************
#include "_DeclarationGenerale.h"
#include "CLMCP2515.h"
#include "CLSPI.h"

//******************************************************************************
//                            LE CONSTRUCTEUR PAR DEFAUT
// *****************************************************************************
CLMCP2515 :: CLMCP2515(void)
{
 
}


// *****************************************************************************
//                            LE DESTRUCTEUR
// *****************************************************************************
CLMCP2515 :: ~CLMCP2515(void)
{

}


void CLMCP2515 :: InitialisationMCP2515(void)
{
   /* Envoi de la commande de � RESET �, qui consiste en l'envoi de l'octet � 0xC0 �, par le bus SPI. */
   EcrireDonnesMCP2515(1, MCP2515_RESET, 0x00, 0x00);
   
   Delai(1000);   /* D�lai permettant de s'assurer que le cicruit � MCP2515 � soit bien r�initialis�. */



/* Passage du circuit MCP2515 en � Configuration mode �, n�c�ssaire pour pouvoir effectuer les op�rations de configurations qui suivent */

   EcrireRegistreMCP2515(MCP2515_CANCTRL, 0x87);   /* Registre 0x0F.
                             - REQOP2 = 1,
                             - REQOP1 = 0,
                             - REQOP0 = 0 : le circuit est pass� en � Configuration mode �,
                             - ABAT = 0 : ne pas annuler toutes les transmissons en attentes, si n�c�ssaire,
                             - OSM : renvois des messages, si n�cessaire,
                             - CLKEN = 1 : la broche � CLKOUT � est activ�e,
                             - CLKPRE1 = 1,
                             - CLKPRE0 = 1 : r�glage du pr�diviseur de l'horloge de la broche � CLKOUT � � 8,
                             - F_CLKOUT = System Clock / 8 */

   EcrireRegistreMCP2515(MCP2515_TX01_INT, 0x3C); /* Registre 0x0C */
   EcrireRegistreMCP2515(MCP2515_TXRTSCTRL, 0x00); /* Registre 0x0D.
                           L'envoi d'un message - RTS - ne se fait pas sur le passage � � 0 � d'une broche,
                           mais apr�s l'envoi de la commande � RTS �, par l'interm�diaire du bus SPI */


/* Initialisations des registres des compteurs d'erreurs */

   EcrireRegistreMCP2515(MCP2515_TEC, 0x00); /* Registre 0x1C.
                         Mise � z�ro du compteur d'erreurs en �mission.*/
   EcrireRegistreMCP2515(MCP2515_REC, 0x00); /* Registre 0x1D.
                         Mise � z�ro du compteur d'erreurs en r�ception.*/


   
/* Configurations du � Bit Timing � */
                     
   EcrireRegistreMCP2515(MCP2515_CNF1, 0xC0 ); /* Registre 0x2A.
                            - SJW = 0 : 1 x TQ,
                            - BRP = 3. */
   EcrireRegistreMCP2515(MCP2515_CNF2, 0x88); /* Registre 0x29.
                            - BTLMODE = 1,
                            - SAM = 0,
                            - PHSEG1 = 2,
                            - PRSEG = 0. */
   EcrireRegistreMCP2515(MCP2515_CNF3, 0x03 ); /* Registre 0x28.
                            - SOF = 0 : Broche � CLKOUT � activ�e pour la fonction de r�p�tition de l'horloge,
                            - WAKFIL = 0 : Wake-up filter d�sactiv�,
                            - PHSEG : 2. */

/* Configurations des interruptions du circuit MCP2515 */

   EcrireRegistreMCP2515(MCP2515_CANINTE, 0x01); /* Registre 0x2B.
                            Autorisation des interruptions suite � la r�ception d'une donn�e par le module � RXB0 �. */

   EcrireRegistreMCP2515(MCP2515_CANINTF, 0x00); /* Registre 0x2C.
                             Acquittement des �ventuelles interruptions qui seraient en attente .*/
   
   EcrireRegistreMCP2515(MCP2515_EFLG, 0x00); /* Registre 0x2D */

   EcrireRegistreMCP2515(MCP2515_RXB0CTRL, 0x20); /* Registre 0x60 */
   
   

/* Configuration initiale du module � TXB0 � */

   EcrireRegistreMCP2515(MCP2515_TXB0CTRL, 0x03); /* Registre 0x30.
                              TXP = 0b11 : les messages ont la plus haute priorit�. */

   EcrireRegistreMCP2515(MCP2515_TXB0DLC, 0x01); /* Registre 0x35.
                             Nombre d'octets occup�s par les donn�es � envoyer : 1 octet.*/


                            
/* Configurations de l'identifiant en r�ception par le filtre 0 du circuit MCP2515 */
      
   EcrireRegistreMCP2515(MCP2515_RXF0SIDH, 0x00);   /* Registre 0x00.
                              Identifiant initial de r�ception H. */

   EcrireRegistreMCP2515(MCP2515_RXF0SIDL, 0xC0);   /* Registre 0x01.
                              Identifiant initial de r�ception L + configurations initiales du mode de fonctionnement des identifiants en r�ceptions. */



/* Configurations du masque de r�ception initial utilis� par le filtre 0 du circuit MCP2515 */

   EcrireRegistreMCP2515(MCP2515_RXM0SIDH, 0x00);   /* Registre 0x20.
                              Masque de r�ception initial H. */
                              
   EcrireRegistreMCP2515(MCP2515_RXM0SIDL, 0xE0);   /* Registre 0x21.
                              Masque de r�ception initial L. + configurations initiales du mode de fonctionnement des masque de r�ceptions. */




/* Configurations de l'identifiant en �mission par le module � TXB0 � du circuit MCP2515 */

   EcrireRegistreMCP2515(MCP2515_TXB0SIDH, 0x00);   /* Registre 0x31.
                              Identifiant initial d'�mission H. */

   EcrireRegistreMCP2515(MCP2515_TXB0SIDL, 0x00);   /* Registre 0x32.
                              Identifiant initial d'�mission L + configurations initiales du mode de fonctionnement des identifiants en �missions. */

   
/* Passage du circuit MCP2515 en � Normal Operation mode � */
   EcrireRegistreMCP2515(MCP2515_CANCTRL, 0x07); /* Registre 0x0F
   //EcrireRegistreMCP2515(MCP2515_CANCTRL, 0x07); * Registre 0x0F.
                              - REQOP2 = 1,
                              - REQOP1 = 0,
                              - REQOP0 = 0 : le circuit est pass� en � Normal Operation mode �. 
                              - Les r�glages pr�c�demment �voqu�s restent inchang�s. */

}




void CLMCP2515 :: EcrireRegistreMCP2515(unsigned char Address, unsigned char Data)
{
   EcrireDonnesMCP2515(3, MCP2515_WRITE, Address, Data);   /* Envoi de 3 octets :
                                       - La commande d'�criture ;
                                       - L'adresse du registre dans lequel �crire ;
                                       - L'octet � �crire dans le registre. */
}


UC CLMCP2515 :: LireRegistreMCP2515(unsigned char Address)
{
 // EcrireDonnesMCP2515(3, MCP2515_READ, Address, 0xFF);
  return(LireDonnesMCP2515(3, MCP2515_READ, Address, 0xFF));   /* Envoi de 3 octets :
                                        //- La commande d'�criture ;
                                       - L'adresse du registre dans lequel �crire                                       - L'octet � �crire dans le registre. */
}



/* Configuration de l'identifiant d'envoi utilis� par le module � TXB0 �.


Param�tres d'entr�e :

int identifiant - Identifiant, sur 11 bits, que doit utiliser le module � TXB0 �.

Valeur de retour :

Aucune.
*/
void CLMCP2515 :: ChoisirIdentifiantTX0(int Identifiant)
{
   UC Contenu_MCP2515_TXB0SIDH = 0;
   UC Contenu_MCP2515_TXB0SIDL = 0;

   Contenu_MCP2515_TXB0SIDH = (UC)(0x00FF & (Identifiant >> 3));   /* On r�cup�re les 8 bits de poids fort de l'identifiant � configurer,
qui doivent �tre plac�s tels quels dans le registre � MCP2515_TXB0SIDH �. */

   Contenu_MCP2515_TXB0SIDL = (UC)(0x00E0 & (Identifiant << 5));   /* On r�cup�re les 3 bits de poids faible de l'identifiant � configurer,
qui doivent �tre plac�s dans le registre � MCP2515_TXB0SIDL �,
aux bits � MCP2515_TXB0SIDL<5> �, � MCP2515_TXB0SIDL<6> � et � MCP2515_TXB0SIDL<7> �. */

   EcrireRegistreMCP2515(MCP2515_TXB0SIDH, Contenu_MCP2515_TXB0SIDH);   /* Identifiant Emission H */
   EcrireRegistreMCP2515(MCP2515_TXB0SIDL, Contenu_MCP2515_TXB0SIDL);   /* Identifiant Emission L + Configurations du mode de fonctionnement des identifiants */
}





/* Envoi d'un message d'un maximum de 8 caract�res, par le module � TXB0 �.


Param�tres d'entr�e :

unsigned char * message - Pointeur sur le d�but d'une cha�ne d'un maximum de 8 caract�res,
� tranmettre par le module � TXB0 �.

Valeur de retour :

Aucune.
*/
void CLMCP2515 :: EnvoyerTrameMCP2515(const  unsigned char * Message)
{
   UC TailleDuMessage = 0;
   UC k;
   UC PointeurRegistre = MCP2515_TXB0D0;

   /* D�termination du nombre d'octets de donn�es � transmettre, et limitation � 8 octets au maximum. */
   TailleDuMessage = Longueur(Message);

   if(TailleDuMessage > 8)   /* Si le nombre d'octets de donn�es � transmettre d�passe le nombre maximal d'octets possible. */
   {
      TailleDuMessage = 8;   /* Le nombre maximal d'octets possible sera tranmis par le circuit MCP2515. */
   }

   EcrireRegistreMCP2515(MCP2515_TXB0DLC, TailleDuMessage);   /* Le MCP2515 est inform� du nombre d'octets de donn�es qu'il aura � tranmettre. */

   /* Chargement du message dans le MCP2515 */
   for(k = 0; k < TailleDuMessage; k++)
   {
      EcrireRegistreMCP2515(PointeurRegistre, Message[k]);   /* Les registres de donn�es du module � TXB0 �,
dont les adresses sont cons�cutives, sont remplis,
en commencant par le registre � MCP2515_TXB0D0 �, d'adresse 0x36. */
      PointeurRegistre++;
   }

   /* Envoi de la commande � RTS �, qui consiste en l'envoi de l'octet � 0xC0 �, par le bus SPI. */
   EcrireDonnesMCP2515(1, MCP2515_RTS_TX0, 0x00, 0x00);

   Delai(10);
}





UC*  CLMCP2515 :: Read(void)
{
 UC ucTrame; 
 ucTrame  = LireRegistreMCP2515(MCP2515_RXB0DLC);
 ucBuf[0] = ucTrame;
    
 for(UC uci = 0; uci < ucTrame; uci++)
   {
    ucBuf[uci + 1] = LireRegistreMCP2515( MCP2515_RXB0D0 + uci);
    Delai(1000);
   }
  return(ucBuf);
}

void CLMCP2515 :: AcquitterInterruptionsMCP2515(void)
{
   EcrireRegistreMCP2515(MCP2515_CANCTRL, 0x87);   /* Registe 0x0F.
                              Le circuit est pass� en � Configuration mode �. */
   EcrireRegistreMCP2515(MCP2515_CANINTF, 0x00);   /* Registre 0x2C.
                              Acquittement des interruptions du circuit MCP2515. */
   EcrireRegistreMCP2515(MCP2515_CANCTRL, 0x07);   /* Registe 0x0F.
                              Le circuit est pass� en � Normal Operation mode �. */
}


UC CLMCP2515 :: EcrireDonnesMCP2515(UC NombreDonneesEnvoyer, UC Donnee1, UC Donnee2, UC Donnee3)
{
   UC k;
   UC Donnees[3] = {0x00};

   Donnees[0] = Donnee1;
   Donnees[1] = Donnee2;
   Donnees[2] = Donnee3;

   CS = 0;  

   for(k = 0; k < NombreDonneesEnvoyer; k++)
   {
    SPI.Write(0x00, Donnees[k]);
    for(int V =0 ;V<100;V++);   /* Delai au moins tant que le module du SPI est occup� */   
   }

   CS = 1;  

   return(0x01);
}



unsigned char CLMCP2515 :: LireDonnesMCP2515(unsigned char NombreDonneesEnvoyer, unsigned char Donnee1, unsigned char Donnee2, unsigned char Donnee3)
{
   UC k;
   UC buf;
   UC Donnees[3] = {0x00};

   Donnees[0] = Donnee1;
   Donnees[1] = Donnee2;
   Donnees[2] = Donnee3;

   CS = 0;   

   for(k = 0; k < NombreDonneesEnvoyer; k++)
   {
    buf = SPI.Write( 0x00 , Donnees[k]);
    for(int V = 0 ; V < 100; V++);   /* Delai au moins tant que le module du SPI est occup� */   
   }

   CS = 1;   

   return(buf);
}



void CLMCP2515 :: Delai(unsigned long Temps)
{
 unsigned long k;
 for(k = 0; k < Temps; k++);
}

unsigned char CLMCP2515 :: Longueur(const  unsigned char * Contenu)
{
UC Compteur = 0;
while(Contenu[Compteur] != '\0')
  {
   Compteur++;
  }
return(Compteur);
}

//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX