// ***************** FICHIER:CLI2CPort.cpp
//
//  Description:Contient les fonctions haut niveau pour communiquer avec 
//              l I2C.
//             
//
//  Application realisee avec IAR
//
//  AUTEUR : Gabriel Fortin-Belanger
//  DATE CREATION :    2014-02-07		 VERSION: 1.0
//  DATE MODIFICATION: ****-**-**
//
//******************************************************************************
#include "_DeclarationGenerale.h"
#include "CLMCP2515.h"


#define MCP2515_RXF0SIDH	0x00
#define MCP2515_RXF0SIDL	0x01
#define MCP2515_RXF0EID8	0x02
#define MCP2515_RXF0EID0	0x03
#define MCP2515_RXF1SIDH	0x04
#define MCP2515_RXF1SIDL	0x05
#define MCP2515_RXF1EID8	0x06
#define MCP2515_RXF1EID0	0x07
#define MCP2515_RXF2SIDH	0x08
#define MCP2515_RXF2SIDL	0x09
#define MCP2515_RXF2EID8	0x0A
#define MCP2515_RXF2EID0	0x0B
#define MCP2515_CANSTAT		0x0E
#define MCP2515_CANCTRL		0x0F
#define MCP2515_RXF3SIDH	0x10
#define MCP2515_RXF3SIDL	0x11
#define MCP2515_RXF3EID8	0x12
#define MCP2515_RXF3EID0	0x13
#define MCP2515_RXF4SIDH	0x14
#define MCP2515_RXF4SIDL	0x15
#define MCP2515_RXF4EID8	0x16
#define MCP2515_RXF4EID0	0x17
#define MCP2515_RXF5SIDH	0x18
#define MCP2515_RXF5SIDL	0x19
#define MCP2515_RXF5EID8	0x1A
#define MCP2515_RXF5EID0	0x1B
#define MCP2515_TEC			0x1C
#define MCP2515_REC			0x1D
#define MCP2515_RXM0SIDH	0x20
#define MCP2515_RXM0SIDL	0x21
#define MCP2515_RXM0EID8	0x22
#define MCP2515_RXM0EID0	0x23
#define MCP2515_RXM1SIDH	0x24
#define MCP2515_RXM1SIDL	0x25
#define MCP2515_RXM1EID8	0x26
#define MCP2515_RXM1EID0	0x27
#define MCP2515_CNF3		0x28
#define MCP2515_CNF2		0x29
#define MCP2515_CNF1		0x2A
#define MCP2515_CANINTE		0x2B
#define MCP2515_CANINTF		0x2C
#define MCP2515_EFLG		0x2D
#define MCP2515_TXB1CTRL	0x40
#define MCP2515_TXB2CTRL	0x50
#define MCP2515_RXB0CTRL	0x60
#define MCP2515_RXB0SIDH	0x61
#define MCP2515_RXB1CTRL	0x70
#define MCP2515_RXB1SIDH	0x71


#define MCP2515_TX_INT		0x1C
#define MCP2515_TX01_INT	0x0C
#define MCP2515_RX_INT		0x03
#define MCP2515_NO_INT		0x00

#define MCP2515_TX01_MASK	0x14
#define MCP2515_TX_MASK		0x54



#define MCP2515_WRITE		0x02

#define MCP2515_READ		0x03

#define MCP2515_BITMOD		0x05

#define MCP2515_LOAD_TX0	0x40
#define MCP2515_LOAD_TX1	0x42
#define MCP2515_LOAD_TX2	0x44

#define MCP2515_RTS_TX0		0x81
#define MCP2515_RTS_TX1		0x82
#define MCP2515_RTS_TX2		0x84
#define MCP2515_RTS_ALL		0x87

#define MCP2515_READ_RX0	0x90
#define MCP2515_READ_RX1	0x94

#define MCP2515_READ_STATUS	0xA0

#define MCP2515_RX_STATUS	0xB0

#define MCP2515_RESET		0xC0



#define MODE_NORMAL     0x00
#define MODE_SLEEP      0x20
#define MODE_LOOPBACK   0x40
#define MODE_LISTENONLY 0x60
#define MODE_CONFIG     0x80
#define MODE_POWERUP	0xE0
#define MODE_MASK		0xE0
#define ABORT_TX        0x10
#define MODE_ONESHOT	0x08
#define CLKOUT_ENABLE	0x04
#define CLKOUT_DISABLE	0x00
#define CLKOUT_PS1		0x00
#define CLKOUT_PS2		0x01
#define CLKOUT_PS4		0x02
#define CLKOUT_PS8		0x03



#define SJW1            0x00
#define SJW2            0x40
#define SJW3            0x80
#define SJW4            0xC0



#define BTLMODE			0x80
#define SAMPLE_1X       0x00
#define SAMPLE_3X       0x40



#define SOF_ENABLE		0x80
#define SOF_DISABLE		0x00
#define WAKFIL_ENABLE	0x40
#define WAKFIL_DISABLE	0x00



#define MCP2515_RX0IF		0x01
#define MCP2515_RX1IF		0x02
#define MCP2515_TX0IF		0x04
#define MCP2515_TX1IF		0x08
#define MCP2515_TX2IF		0x10
#define MCP2515_ERRIF		0x20
#define MCP2515_WAKIF		0x40
#define MCP2515_MERRF		0x80


/* Registres permettant de contr�ler le module d'envoi � TX0 � */

#define MCP2515_TXB0CTRL	0x30
#define MCP2515_TXB0SIDH	0x31
#define MCP2515_TXB0SIDL	0x32
#define MCP2515_TXB0EID8	0x33
#define MCP2515_TXB0EID0	0x34
#define MCP2515_TXB0DLC	0x35
#define MCP2515_TXB0D0	0x36
#define MCP2515_TXB0D1	0x37
#define MCP2515_TXB0D2	0x38
#define MCP2515_TXB0D3	0x39
#define MCP2515_TXB0D4	0x3A
#define MCP2515_TXB0D5	0x3B
#define MCP2515_TXB0D6	0x3C
#define MCP2515_TXB0D7	0x3D
#define MCP2515_TXB0CANSTAT	0x3E
#define MCP2515_TXB0CANCTRL	0x3F


/* Registres permettant de contr�ler le module de r�ception � RX0 � */

#define MCP2515_RXB0CTRL	0x60
#define MCP2515_RXB0SIDH	0x61
#define MCP2515_RXB0SIDL	0x62
#define MCP2515_RXB0EID8	0x63
#define MCP2515_RXB0EID0	0x64
#define MCP2515_RXB0DLC	0x65
#define MCP2515_RXB0D0	0x66
#define MCP2515_RXB0D1	0x67
#define MCP2515_RXB0D2	0x68
#define MCP2515_RXB0D3	0x69
#define MCP2515_RXB0D4	0x6A
#define MCP2515_RXB0D5	0x6B
#define MCP2515_RXB0D6	0x6C
#define MCP2515_RXB0D7	0x6D
#define MCP2515_RXB0CANSTAT	0x6E
#define MCP2515_RXB0CANCTRL	0x6F


#define MCP2515_BFPCTRL		0x0C
#define MCP2515_TXRTSCTRL	0x0D
#define MCP2515_CHOIX_IDENTIFIANT 0x05


CLMCP2515 :: CLMCP2515(void)
{

 
}


CLMCP2515 :: ~CLMCP2515(void)
{


}


void CLMCP2515 :: InitialisationMCP2515(void)
{
	/* Envoi de la commande de � RESET �, qui consiste en l'envoi de l'octet � 0xC0 �, par le bus SPI. */
	EcrireDonnesMCP2515(1, MCP2515_RESET, 0x00, 0x00);
	
	Delai(1000);	/* D�lai permettant de s'assurer que le cicruit � MCP2515 � soit bien r�initialis�. */



/* Passage du circuit MCP2515 en � Configuration mode �, n�c�ssaire pour pouvoir effectuer les op�rations de configurations qui suivent */

	EcrireRegistreMCP2515(MCP2515_CANCTRL, 0x87);	/* Registre 0x0F.
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
		
	EcrireRegistreMCP2515(MCP2515_RXF0SIDH, 0x00);	/* Registre 0x00.
									   Identifiant initial de r�ception H. */

	EcrireRegistreMCP2515(MCP2515_RXF0SIDL, 0xC0);	/* Registre 0x01.
									   Identifiant initial de r�ception L + configurations initiales du mode de fonctionnement des identifiants en r�ceptions. */



/* Configurations du masque de r�ception initial utilis� par le filtre 0 du circuit MCP2515 */

	EcrireRegistreMCP2515(MCP2515_RXM0SIDH, 0x00);	/* Registre 0x20.
									   Masque de r�ception initial H. */
									   
	EcrireRegistreMCP2515(MCP2515_RXM0SIDL, 0xE0);	/* Registre 0x21.
									   Masque de r�ception initial L. + configurations initiales du mode de fonctionnement des masque de r�ceptions. */




/* Configurations de l'identifiant en �mission par le module � TXB0 � du circuit MCP2515 */

	EcrireRegistreMCP2515(MCP2515_TXB0SIDH, 0x00);	/* Registre 0x31.
									   Identifiant initial d'�mission H. */

	EcrireRegistreMCP2515(MCP2515_TXB0SIDL, 0x00);	/* Registre 0x32.
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
	EcrireDonnesMCP2515(3, MCP2515_WRITE, Address, Data);	/* Envoi de 3 octets :
													- La commande d'�criture ;
													- L'adresse du registre dans lequel �crire ;
													- L'octet � �crire dans le registre. */
}


UC CLMCP2515 :: LireRegistreMCP2515(unsigned char Address)
{
 // EcrireDonnesMCP2515(3, MCP2515_READ, Address, 0xFF);
  return(LireDonnesMCP2515(3, MCP2515_READ, Address, 0xFF));	/* Envoi de 3 octets :
 													//- La commande d'�criture ;
													- L'adresse du registre dans lequel �crire													- L'octet � �crire dans le registre. */
}



/* Configuration de l'identifiant d'envoi utilis� par le module � TXB0 �.


Param�tres d'entr�e :

int identifiant - Identifiant, sur 11 bits, que doit utiliser le module � TXB0 �.

Valeur de retour :

Aucune.
*/
void CLMCP2515 :: ChoisirIdentifiantTX0(int Identifiant)
{
	unsigned char Contenu_MCP2515_TXB0SIDH = 0;
	unsigned char Contenu_MCP2515_TXB0SIDL = 0;

	Contenu_MCP2515_TXB0SIDH = (unsigned char)(0x00FF & (Identifiant >> 3));	/* On r�cup�re les 8 bits de poids fort de l'identifiant � configurer,
qui doivent �tre plac�s tels quels dans le registre � MCP2515_TXB0SIDH �. */

	Contenu_MCP2515_TXB0SIDL = (unsigned char)(0x00E0 & (Identifiant << 5));	/* On r�cup�re les 3 bits de poids faible de l'identifiant � configurer,
qui doivent �tre plac�s dans le registre � MCP2515_TXB0SIDL �,
aux bits � MCP2515_TXB0SIDL<5> �, � MCP2515_TXB0SIDL<6> � et � MCP2515_TXB0SIDL<7> �. */

	EcrireRegistreMCP2515(MCP2515_TXB0SIDH, Contenu_MCP2515_TXB0SIDH);	/* Identifiant Emission H */
	EcrireRegistreMCP2515(MCP2515_TXB0SIDL, Contenu_MCP2515_TXB0SIDL);	/* Identifiant Emission L + Configurations du mode de fonctionnement des identifiants */
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
	unsigned char TailleDuMessage = 0;
	unsigned char k;
	unsigned char PointeurRegistre = MCP2515_TXB0D0;

	/* D�termination du nombre d'octets de donn�es � transmettre, et limitation � 8 octets au maximum. */
	TailleDuMessage = Longueur(Message);

	if(TailleDuMessage > 8)	/* Si le nombre d'octets de donn�es � transmettre d�passe le nombre maximal d'octets possible. */
	{
		TailleDuMessage = 8;	/* Le nombre maximal d'octets possible sera tranmis par le circuit MCP2515. */
	}

	EcrireRegistreMCP2515(MCP2515_TXB0DLC, TailleDuMessage);	/* Le MCP2515 est inform� du nombre d'octets de donn�es qu'il aura � tranmettre. */

	/* Chargement du message dans le MCP2515 */
	for(k = 0; k < TailleDuMessage; k++)
	{
		EcrireRegistreMCP2515(PointeurRegistre, Message[k]);	/* Les registres de donn�es du module � TXB0 �,
dont les adresses sont cons�cutives, sont remplis,
en commencant par le registre � MCP2515_TXB0D0 �, d'adresse 0x36. */
		PointeurRegistre++;
	}

	/* Envoi de la commande � RTS �, qui consiste en l'envoi de l'octet � 0xC0 �, par le bus SPI. */
	EcrireDonnesMCP2515(1, MCP2515_RTS_TX0, 0x00, 0x00);

	Delai(10);
}





UC*  CLMCP2515 :: LireTrameMCP2515(void)
{
   UC ucTrame;
  // UC ucID;
  
   
  
   
   // ucID = LireRegistreMCP2515(MCP2515_RXB0DLC);
   //ucBuf[0] = ucTrame;
   
 ucTrame = LireRegistreMCP2515(MCP2515_RXB0DLC);
   ucBuf[0] = ucTrame;
   
 
   
  for(UC uci=0;uci < ucTrame; uci++)
   {

      ucBuf[uci + 1] = LireRegistreMCP2515( MCP2515_RXB0D0 + uci);
       Delai(1000);
   }
 
  
  return (ucBuf);
  
}




/* Acquittement des interruptions du circuit MCP2515.


Param�tres d'entr�e :

Aucun.

Valeur de retour :

Aucune.
*/
void CLMCP2515 :: AcquitterInterruptionsMCP2515(void)
{
	EcrireRegistreMCP2515(MCP2515_CANCTRL, 0x87);	/* Registe 0x0F.
									   Le circuit est pass� en � Configuration mode �. */
	EcrireRegistreMCP2515(MCP2515_CANINTF, 0x00);	/* Registre 0x2C.
									   Acquittement des interruptions du circuit MCP2515. */
	EcrireRegistreMCP2515(MCP2515_CANCTRL, 0x07);	/* Registe 0x0F.
									   Le circuit est pass� en � Normal Operation mode �. */
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
			ucSPITransfert( 0x00 , Donnees[k]);
			for(int V =0 ;V<100;V++);	/* Delai au moins tant que le module du SPI est occup� */	
	}

	BROCHE_MCP2515_CS = 1;	/* ~CS_MCP2515 = 1 */

	return 0x01;
}



unsigned char CLMCP2515 :: LireDonnesMCP2515(unsigned char NombreDonneesEnvoyer, unsigned char Donnee1, unsigned char Donnee2, unsigned char Donnee3)
{
	unsigned char k;
        unsigned char buf;
	unsigned char Donnees[3] = {0x00};

	Donnees[0] = Donnee1;
	Donnees[1] = Donnee2;
	Donnees[2] = Donnee3;

	BROCHE_MCP2515_CS = 0;	/* ~CS_MCP2515 = 0 */

	for(k = 0; k < NombreDonneesEnvoyer; k++)
	{
		        buf = ucSPITransfert( 0x00 , Donnees[k]);
			for(int V =0 ;V<100;V++);	/* Delai au moins tant que le module du SPI est occup� */	
	}

	BROCHE_MCP2515_CS = 1;	/* ~CS_MCP2515 = 1 */

	return buf;
}






void CLMCP2515 :: Delai(unsigned long Temps)
{
	unsigned long k;

	for(k = 0; k < Temps; k++);
}

unsigned char CLMCP2515 :: Longueur(const  unsigned char * Contenu)
{
	unsigned char Compteur = 0;

	while(Contenu[Compteur] != '\0')
	{
		Compteur++;
	}

	return Compteur;
}


