
#include "CLMCP2515.h"

#include "CLSerialPortInterface.h"



/* Fonction permettant d'initialiser le « MCP2515 ».
La fréquence du bus CAN est configuré à 125 kHZ.


Paramètres d'entrée :

Aucun.

Valeur de retour :

Aucune.
*/

CLMCP2515 :: CLMCP2515(void)
{
 InitialisationMCP2515();
}
CLMCP2515 :: ~CLMCP2515(void)
{}

void CLMCP2515 :: InitialisationMCP2515(void)
{
	/* Envoi de la commande de « RESET », qui consiste en l'envoi de l'octet « 0xC0 », par le bus SPI. */
	EcrireDonnesMCP2515(1, MCP2515_RESET, 0x00, 0x00);
	
	for(USI i = 0; i < 1000; i++);	/* Délai permettant de s'assurer que le cicruit « MCP2515 » soit bien réinitialisé. */



/* Passage du circuit MCP2515 en « Configuration mode », nécéssaire pour pouvoir effectuer les opérations de configurations qui suivent */

	EcrireRegistreMCP2515(MCP2515_CANCTRL, 0x87);	/* Registre 0x0F.
									  - REQOP2 = 1,
									  - REQOP1 = 0,
									  - REQOP0 = 0 : le circuit est passé en « Configuration mode »,
									  - ABAT = 0 : ne pas annuler toutes les transmissons en attentes, si nécéssaire,
									  - OSM : renvois des messages, si nécessaire,
									  - CLKEN = 1 : la broche « CLKOUT » est activée,
									  - CLKPRE1 = 1,
									  - CLKPRE0 = 1 : réglage du prédiviseur de l'horloge de la broche « CLKOUT » à 8,
									  - F_CLKOUT = System Clock / 8 */

	EcrireRegistreMCP2515(MCP2515_TX01_INT, 0x3C); /* Registre 0x0C */
	EcrireRegistreMCP2515(MCP2515_TXRTSCTRL, 0x00); /* Registre 0x0D.
									L'envoi d'un message - RTS - ne se fait pas sur le passage à « 0 » d'une broche,
									mais après l'envoi de la commande « RTS », par l'intermédiaire du bus SPI */


/* Initialisations des registres des compteurs d'erreurs */

	EcrireRegistreMCP2515(MCP2515_TEC, 0x00); /* Registre 0x1C.
		Mise à zéro du compteur d'erreurs en émission.*/
	EcrireRegistreMCP2515(MCP2515_REC, 0x00); /* Registre 0x1D.
		Mise à zéro du compteur d'erreurs en réception.*/


	
/* Configurations du « Bit Timing » */
							
	EcrireRegistreMCP2515(MCP2515_CNF1, 0xC0 ); /* Registre 0x2A.
		- SJW = 0 : 1 x TQ,
		- BRP = 3. */
	EcrireRegistreMCP2515(MCP2515_CNF2, 0x88 ); /* Registre 0x29.
		- BTLMODE = 1,
		- SAM = 0,
		- PHSEG1 = 2,
		- PRSEG = 0. */
	EcrireRegistreMCP2515(MCP2515_CNF3, 0x03 ); /* Registre 0x28.
		- SOF = 0 : Broche « CLKOUT » activée pour la fonction de répétition de l'horloge,
		- WAKFIL = 0 : Wake-up filter désactivé,
		- PHSEG : 2. */

//C0/88/03

/* Configurations des interruptions du circuit MCP2515 */

	EcrireRegistreMCP2515(MCP2515_CANINTE, 0x01); /* Registre 0x2B.
		Autorisation des interruptions suite à la réception d'une donnée par le module « RXB0 ». */

	EcrireRegistreMCP2515(MCP2515_CANINTF, 0x00); /* Registre 0x2C.
		Acquittement des éventuelles interruptions qui seraient en attente .*/
	
	EcrireRegistreMCP2515(MCP2515_EFLG, 0x00); /* Registre 0x2D */

	EcrireRegistreMCP2515(MCP2515_RXB0CTRL, 0x20); /* Registre 0x60 */
	
	

/* Configuration initiale du module « TXB0 » */

	EcrireRegistreMCP2515(MCP2515_TXB0CTRL, 0x03); /* Registre 0x30.
								      TXP = 0b11 : les messages ont la plus haute priorité. */

	EcrireRegistreMCP2515(MCP2515_TXB0DLC, 0x01); /* Registre 0x35.
								     Nombre d'octets occupés par les données à envoyer : 1 octet.*/


									 
/* Configurations de l'identifiant en réception par le filtre 0 du circuit MCP2515 */
		
	EcrireRegistreMCP2515(MCP2515_RXF0SIDH, 0x00);	/* Registre 0x00.
		Identifiant initial de réception H. */

	EcrireRegistreMCP2515(MCP2515_RXF0SIDL, 0xD0);	/* Registre 0x01.
		Identifiant initial de réception L + configurations initiales du mode de fonctionnement des identifiants en réceptions. */



/* Configurations du masque de réception initial utilisé par le filtre 0 du circuit MCP2515 */

	EcrireRegistreMCP2515(MCP2515_RXM0SIDH, 0x00);	/* Registre 0x20.
		Masque de réception initial H. */
									   
	EcrireRegistreMCP2515(MCP2515_RXM0SIDL, 0x00);	/* Registre 0x21.
		Masque de réception initial L. + configurations initiales du mode de fonctionnement des masque de réceptions. */




/* Configurations de l'identifiant en émission par le module « TXB0 » du circuit MCP2515 */

	EcrireRegistreMCP2515(MCP2515_TXB0SIDH, 0x00);	/* Registre 0x31.
		Identifiant initial d'émission H. */

	EcrireRegistreMCP2515(MCP2515_TXB0SIDL, 0x00);	/* Registre 0x32.
		Identifiant initial d'émission L + configurations initiales du mode de fonctionnement des identifiants en émissions. */

	
/* Passage du circuit MCP2515 en « Normal Operation mode » */
	
	EcrireRegistreMCP2515(MCP2515_CANCTRL, 0x07); /* Registre 0x0F.
		 - REQOP2 = 1,
		 - REQOP1 = 0,
		 - REQOP0 = 0 : le circuit est passé en « Normal Operation mode ». 
		 - Les réglages précédemment évoqués restent inchangés. */

}



/* Fonction permettant d'écrire une donnée dans un registre du « MCP2515 »,
par l'intermédiaire du bus SPI


Paramètres d'entrée :

unsigned char Address - Adresse du registre dans lequel écrire,
unsigned char Data - Octet à écrire dans le registre.

Valeur de retour :

Aucune.
*/
void CLMCP2515 :: LireMCP2515(void)
{     
        UC D1, D2, D3, D4, D5, D6, D7, D8;
	BROCHE_MCP2515_CS = 1;
	BROCHE_MCP2515_SCK = 0;
	BROCHE_MCP2515_SDO = 0;
	BROCHE_MCP2515_CS = 1;     
	ChoisirIdentifiantTX0(MCP2515_CHOIX_IDENTIFIANT);
        BROCHE_MCP2515_CS = 0;
        ucSPITransferMOD0(0x03);           
        ucSPITransferMOD0(0x66);  
        
        D1 = ucSPITransferMOD0(0x00);
        D2 = ucSPITransferMOD0(0x00);
        D3 = ucSPITransferMOD0(0x00);
        D4 = ucSPITransferMOD0(0x00);
        D5 = ucSPITransferMOD0(0x00);  
        D6 = ucSPITransferMOD0(0x00);
        D7 = ucSPITransferMOD0(0x00);
        D8 = ucSPITransferMOD0(0x00);
       
        BROCHE_MCP2515_CS = 1;    
        
          Tab [0] = D1;
          Tab [1] = D2;
          Tab [2] = D3;
          Tab [3] = D4;
          Tab [4] = D5;
          Tab [5] = D6;
          Tab [6] = D7;
          Tab [7] = D8; 
        AcquitterInterruptionsMCP2515 ();
}
 
 
 


void CLMCP2515 :: EcrireRegistreMCP2515(unsigned char Address, unsigned char Data)
{
	EcrireDonnesMCP2515(3, MCP2515_WRITE, Address, Data);	/* Envoi de 3 octets :
		- La commande d'écriture ;
		- L'adresse du registre dans lequel écrire ;
		- L'octet à écrire dans le registre. */
}



/* Configuration de l'identifiant d'envoi utilisé par le module « TXB0 ».


Paramètres d'entrée :

int identifiant - Identifiant, sur 11 bits, que doit utiliser le module « TXB0 ».

Valeur de retour :

Aucune.
*/
void CLMCP2515 :: ChoisirIdentifiantTX0(int Identifiant)
{
	unsigned char Contenu_MCP2515_TXB0SIDH = 0;
	unsigned char Contenu_MCP2515_TXB0SIDL = 0;

	Contenu_MCP2515_TXB0SIDH = (unsigned char)(0x00FF & (Identifiant >> 3));	/* On récupère les 8 bits de poids fort de l'identifiant à configurer,
qui doivent être placés tels quels dans le registre « MCP2515_TXB0SIDH ». */

	Contenu_MCP2515_TXB0SIDL = (unsigned char)(0x00E0 & (Identifiant << 5));	/* On récupère les 3 bits de poids faible de l'identifiant à configurer,
qui doivent être placés dans le registre « MCP2515_TXB0SIDL »,
aux bits « MCP2515_TXB0SIDL<5> », « MCP2515_TXB0SIDL<6> » et « MCP2515_TXB0SIDL<7> ». */

	EcrireRegistreMCP2515(MCP2515_TXB0SIDH, Contenu_MCP2515_TXB0SIDH);	/* Identifiant Emission H */
	EcrireRegistreMCP2515(MCP2515_TXB0SIDL, Contenu_MCP2515_TXB0SIDL);	/* Identifiant Emission L + Configurations du mode de fonctionnement des identifiants */
}



/* Envoi d'un message d'un maximum de 8 caractères, par le module « TXB0 ».


Paramètres d'entrée :

unsigned char * message - Pointeur sur le début d'une chaîne d'un maximum de 8 caractères,
à tranmettre par le module « TXB0 ».

Valeur de retour :

Aucune.
*/
void CLMCP2515 :: EnvoyerTrameMCP2515(const unsigned char * Message)
{
	unsigned char TailleDuMessage = 0;
	unsigned char k;
	unsigned char PointeurRegistre = MCP2515_TXB0D0;

	/* Détermination du nombre d'octets de données à transmettre, et limitation à 8 octets au maximum. */
	TailleDuMessage = Longueur(Message);

	if(TailleDuMessage > 8)	/* Si le nombre d'octets de données à transmettre dépasse le nombre maximal d'octets possible. */
	{
		TailleDuMessage = 8;	/* Le nombre maximal d'octets possible sera tranmis par le circuit MCP2515. */
	}

	EcrireRegistreMCP2515(MCP2515_TXB0DLC, TailleDuMessage);	/* Le MCP2515 est informé du nombre d'octets de données qu'il aura à tranmettre. */

	/* Chargement du message dans le MCP2515 */
	for(k = 0; k < TailleDuMessage; k++)
	{
		EcrireRegistreMCP2515(PointeurRegistre, Message[k]);	/* Les registres de données du module « TXB0 »,
dont les adresses sont consécutives, sont remplis,
en commencant par le registre « MCP2515_TXB0D0 », d'adresse 0x36. */
		PointeurRegistre++;
	}

	/* Envoi de la commande « RTS », qui consiste en l'envoi de l'octet « 0xC0 », par le bus SPI. */
	EcrireDonnesMCP2515(1, MCP2515_RTS_TX0, 0x00, 0x00);

	for(UC i = 0; i < 10; i++);
}



/* Acquittement des interruptions du circuit MCP2515.


Paramètres d'entrée :

Aucun.

Valeur de retour :

Aucune.
*/
void CLMCP2515 :: AcquitterInterruptionsMCP2515(void)
{
	EcrireRegistreMCP2515(MCP2515_CANCTRL, 0x87);	/* Registe 0x0F.
									   Le circuit est passé en « Configuration mode ». */
	EcrireRegistreMCP2515(MCP2515_CANINTF, 0x00);	/* Registre 0x2C.
									   Acquittement des interruptions du circuit MCP2515. */
	EcrireRegistreMCP2515(MCP2515_CANCTRL, 0x07);	/* Registe 0x0F.
									   Le circuit est passé en « Normal Operation mode ». */
}


unsigned char CLMCP2515 :: EcrireDonnesMCP2515(unsigned char NombreDonneesEnvoyer, unsigned char Donnee1, unsigned char Donnee2, unsigned char Donnee3)
{
	unsigned char k;

	unsigned char Donnees[3] = {0x00};

	Donnees[0] = Donnee1;
	Donnees[1] = Donnee2;
	Donnees[2] = Donnee3;

	BROCHE_MCP2515_CS = 0;	/* ~CS_MCP2515 = 0 */

	for(k = 0; k < NombreDonneesEnvoyer; k++)
	{
         ucSPITransferMOD0(Donnees[k]);
	 for(UC i = 0; i < 10; i++); /* Delai au moins tant que le module du SPI est occupé */	
	}

	BROCHE_MCP2515_CS = 1;	/* ~CS_MCP2515 = 1 */

	return 0x01;
}


unsigned char CLMCP2515 :: Longueur(const unsigned char * Contenu)
{
	unsigned char Compteur = 0;

	while(Contenu[Compteur] != '\0')
	{
		Compteur++;
	}
	
        return Compteur;
}

