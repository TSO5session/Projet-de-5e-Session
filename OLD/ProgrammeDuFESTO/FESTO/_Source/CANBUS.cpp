// **************************CANBUS.cpp
// Auteur:       Vincent Chouinard
// Date:         27 octobre 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.1
//
// Description:
// *****************************************************************************
#include "DeclarationGenerale.h" // Raccourcis de programmation & variables
#include "CANBUS.h"               // Fichier de definitions du bus CAN
#include "MCP2515.h"              // define des registres du MCP2515
#include "CLSerialPortInterface.h"// Pour utiliser le bus SPI
// *****************************************************************************
#define MCP2415                   // Pour la compilation conditionnelle
#define MCP2515_CS P1_7;          // Chip Select
#define MCP2515_CHOIX_IDENTIFIANT 0x0A0
// *****************************************************************************

//******************************************************************************
//                            LE CONSTRUCTEUR PAR DEFAUT
// *****************************************************************************
CanBus :: CanBus(void)
{
MCP24515_init();                                  // Initialise le MCP2515
ChoisirIdentifiantTX0(MCP2515_CHOIX_IDENTIFIANT); // Envoie 0x0A0
}

//******************************************************************************
//                            LE CONSTRUCTEUR INITIALISATEUR
// *****************************************************************************
CanBus :: CanBus(UC ucParametre) // Initialisation du CAN via MCP2515
{

}

// *****************************************************************************
//                            LE DESTRUCTEUR
// *****************************************************************************
CanBus :: ~CanBus(void)
{
  
}

UC CanBus :: ReadMCP(void) // Cette Fonction n'est pas encore fonctionnelle
{
bool gotMessage;  // Note: fonction non fonctionnelle
UC   val = 0;
/*
val = SPI.WriteMPC(MCP2515_CANINTF);                 // Obtention de la longueur

if(LireRegistreMCP2515(val, MCP2515_RX0IF) == 1) // Si une data est availible
  {
   gotMessage = true;                            // L�ve le flag d'availibilit�
  }

if(gotMessage == true)
  {

  }
*/

return(val);
}

void CanBus :: MCP24515_init(void)
{
// Envoi de la commande de   RESET  , qui consiste en l'envoi de l'octet   0xC0  , par le bus SPI. 
   SPI.WriteMPC(3, MCP2515_RESET, 0x00, 0x00);
   Delai(1000);   // D�lai permettant de s'assurer que le MCP2515 soit bien r�initialis�.
        
// Passage du circuit MCP2515 en   Configuration mode  , n�c�ssaire 
// pour pouvoir effectuer les op�rations de configurations qui suivent 

   EcrireRegistreMCP2515(MCP2515_CANCTRL, 0x87);   /* Registre 0x0F.
                             - REQOP2   = 1 :
                             - REQOP1   = 0 :
                             - REQOP0   = 0 : le circuit est pass� en   Configuration mode  ,
                             - ABAT     = 0 : ne pas annuler toutes les transmissons en attentes, si n�c�ssaire,
                             - OSM          : renvois des messages, si n�cessaire,
                             - CLKEN    = 1 : la broche   CLKOUT   est activ�e,
                             - CLKPRE1  = 1 : 
                             - CLKPRE0  = 1 : r�glage du pr�diviseur de l'horloge de la broche   CLKOUT   � 8,
                             - F_CLKOUT = System Clock / 8 */        
             
EcrireRegistreMCP2515(MCP2515_TX01_INT,  0x3C); /* Registre 0x0C */
EcrireRegistreMCP2515(MCP2515_TXRTSCTRL, 0x00); /* Registre 0x0D.
                           L'envoi d'un message - RTS - ne se fait pas sur le passage �   0   d'une broche,
                           mais apr�s l'envoi de la commande   RTS  , par l'interm�diaire du bus SPI */
   
/* Initialisations des registres des compteurs d'erreurs */
EcrireRegistreMCP2515(MCP2515_TEC, 0x00); /* Registre 0x1C.
                          Mise � z�ro du compteur d'erreurs en �mission.*/
EcrireRegistreMCP2515(MCP2515_REC, 0x00); /* Registre 0x1D.
                          Mise � z�ro du compteur d'erreurs en r�ception.*/
  
/* Configurations du   Bit Timing   */                 
EcrireRegistreMCP2515(MCP2515_CNF1, 0xC0); /* Registre 0xC0.
                            - SJW = 0 : 1 x TQ,
                            - BRP = 3. */
EcrireRegistreMCP2515(MCP2515_CNF2, 0x9A); /* Registre 0x9A.
                            - BTLMODE = 1,
                            - SAM     = 0,
                            - PHSEG1  = 2,
                            - PRSEG   = 0. */
EcrireRegistreMCP2515(MCP2515_CNF3, 0x07); /* Registre 0x07.
                            - SOF     = 0 : Broche   CLKOUT   activ�e pour la fonction de r�p�tition de l'horloge,
                            - WAKFIL  = 0 : Wake-up filter d�sactiv�,
                            - PHSEG : 2. */

/* Configurations des interruptions du circuit MCP2515 */
EcrireRegistreMCP2515(MCP2515_CANINTE,  0x01); /* Registre 0x2B.
                            Autorisation des interruptions suite � la r�ception d'une donn�e par le module   RXB0  . */
EcrireRegistreMCP2515(MCP2515_CANINTF,  0x00); /* Registre 0x2C.
                             Acquittement des �ventuelles interruptions qui seraient en attente .*/
EcrireRegistreMCP2515(MCP2515_EFLG,     0x00); /* Registre 0x2D */
EcrireRegistreMCP2515(MCP2515_RXB0CTRL, 0x20); /* Registre 0x60 */
   
/* Configuration initiale du module   TXB0   */
EcrireRegistreMCP2515(MCP2515_TXB0CTRL, 0x03); /* Registre 0x30.
                              TXP = 0b11 : les messages ont la plus haute priorit�. */
EcrireRegistreMCP2515(MCP2515_TXB0DLC, 0x01);  /* Registre 0x35.
                             Nombre d'octets occup�s par les donn�es � envoyer : 1 octet.*/
                      
/* Configurations de l'identifiant en r�ception par le filtre 0 du circuit MCP2515 */    
EcrireRegistreMCP2515(MCP2515_RXF0SIDH, 0x00);   /* Registre 0x00.
                              Identifiant initial de r�ception H. */
EcrireRegistreMCP2515(MCP2515_RXF0SIDL, 0x20);   /* Registre 0x01.
                              Identifiant initial de r�ception L + configurations initiales du mode de fonctionnement des identifiants en r�ceptions. */

/* Configurations du masque de r�ception initial utilis� par le filtre 0 du circuit MCP2515 */
EcrireRegistreMCP2515(MCP2515_RXM0SIDH, 0x00);   /* Registre 0x20.
                              Masque de r�ception initial H. */                              
EcrireRegistreMCP2515(MCP2515_RXM0SIDL, 0x20);   /* Registre 0x21.
                              Masque de r�ception initial L. + configurations initiales du mode de fonctionnement des masque de r�ceptions. */
   
/* Configurations de l'identifiant en �mission par le module   TXB0   du circuit MCP2515 */
EcrireRegistreMCP2515(MCP2515_TXB0SIDH, 0x00);   /* Registre 0x31.
                              Identifiant initial d'�mission H. */
EcrireRegistreMCP2515(MCP2515_TXB0SIDL, 0x00);   /* Registre 0x32.
                              Identifiant initial d'�mission L + configurations initiales du mode de fonctionnement des identifiants en �missions. */
  
/* Passage du circuit MCP2515 en   Normal Operation mode   */
EcrireRegistreMCP2515(MCP2515_CANCTRL, 0x07); /* Registre 0x0F.
                              - REQOP2 = 1,
                              - REQOP1 = 0,
                              - REQOP0 = 0 : le circuit est pass� en   Normal Operation mode  . 
                              - Les r�glages pr�c�demment �voqu�s restent inchang�s. */        
}

void CanBus :: EcrireRegistreMCP2515(UC Address, UC Data)
{
SPI.WriteMPC(3, MCP2515_WRITE, Address, Data);   /* Envoi de 3 octets :
                                       - La commande d'�criture ;
                                       - L'adresse du registre dans lequel �crire ;
                                       - L'octet � �crire dans le registre. */ 
}

void CanBus :: ChoisirIdentifiantTX0(int Identifiant)
{
UC Contenu_MCP2515_TXB0SIDH = 0;
UC Contenu_MCP2515_TXB0SIDL = 0;

// On r�cup�re les 8 bits de poids fort de l'identifiant � configurer,
// qui doivent �tre plac�s tels quels dans le registre   MCP2515_TXB0SIDH  . 
Contenu_MCP2515_TXB0SIDH = (UC)(0x00FF & (Identifiant >> 3));   

// On r�cup�re les 3 bits de poids faible de l'identifiant � configurer,
// qui doivent �tre plac�s dans le registre   MCP2515_TXB0SIDL  ,
// aux bits   MCP2515_TXB0SIDL<5>  ,   MCP2515_TXB0SIDL<6>   et   MCP2515_TXB0SIDL<7>  .   
Contenu_MCP2515_TXB0SIDL = (UC)(0x00E0 & (Identifiant << 5));   
   
   //Identifiant Emission H 
EcrireRegistreMCP2515(MCP2515_TXB0SIDH, Contenu_MCP2515_TXB0SIDH);   
   // Identifiant Emission L + Configurations du mode de fonctionnement des identifiants */  
EcrireRegistreMCP2515(MCP2515_TXB0SIDL, Contenu_MCP2515_TXB0SIDL);   
}

void CanBus :: AcquitterInterruptionsMCP2515(void)
{
EcrireRegistreMCP2515(MCP2515_CANCTRL, 0x87);   /* Registe 0x0F.
Le circuit est pass� en   Configuration mode  . */
EcrireRegistreMCP2515(MCP2515_CANINTF, 0x00);   /* Registre 0x2C.
Acquittement des interruptions du circuit MCP2515. */
EcrireRegistreMCP2515(MCP2515_CANCTRL, 0x07);   /* Registe 0x0F.
Le circuit est pass� en   Normal Operation mode  . */  
}

void CanBus :: SendMCP(const UC *Message)
{
UC TailleDuMessage = 0;
UC k;
UC PointeurRegistre = MCP2515_TXB0D0;

//D�termination du nombre d'octets de donn�es � transmettre, et limitation � 8 octets au maximum
TailleDuMessage = Longueur(Message);

//Si le nombre d'octets de donn�es � transmettre d�passe le nombre maximal d'octets possible
if(TailleDuMessage > 8)   
  {                     // Le nombre maximal d'octets possible
   TailleDuMessage = 8; // sera tranmis par le circuit MCP2515
  }

//Le MCP2515 est inform� du nombre d'octets de donn�es qu'il aura � tranmettre
EcrireRegistreMCP2515(MCP2515_TXB0DLC, TailleDuMessage); 

for(k = 0; k < TailleDuMessage; k++) // Chargement du message dans le MCP2515
  {
   EcrireRegistreMCP2515(PointeurRegistre, Message[k]); /* Les registres de donn�es du module   TXB0  ,
   dont les adresses sont cons�cutives, sont remplis,
   en commencant par le registre   MCP2515_TXB0D0  , d'adresse 0x36. */
   PointeurRegistre++;
  }

/* Envoi de la commande   RTS  , qui consiste en l'envoi de l'octet   0xC0  , par le bus SPI. */
SPI.WriteMPC(1, MCP2515_RTS_TX0, 0x00, 0x00);
Delai(10);  
}

UC CanBus :: LireRegistreMCP2515(UC Address, UC Data)
{
SPI.WriteMPC(Address);  
return(SPI.WriteMPC(Data));
}

UC CanBus :: Longueur(const UC *Contenu)
{
UC Compteur = 0;

while(Contenu[Compteur] != '\0')
  {
   Compteur++;
  }
return(Compteur);  
}

void CanBus :: Delai(unsigned long Temps)
{
unsigned long k;
for(k = 0; k < Temps; k++);  
}
 
void CanBus :: ModeLoopbackInit(void)
{
 EcrireRegistreMCP2515(MCP2515_CANCTRL, 0x47); 
}
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
