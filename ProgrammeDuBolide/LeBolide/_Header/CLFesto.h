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

#ifndef CLFESTOH
#define CLFESTOH

#include "CLIOPcf8574.h"


//Signaux venant de la table FESTO
#define CYLINDRE_VENTOUSE_HAUT_OUT        0
#define CYLINDRE_VENTOUSE_BAS_OUT         1
#define DETECTEUR_MAGNETIQUE_PLATEAU      2
#define DETECTEUR_CAPACITIF_PLATEAU       3
#define EJECTEUR_BLOC_ENTREE_OUT          4
#define EJECTEUR_BLOC_SORTIE _OUT         5
#define ELEVATEUR_BAS                     6
#define ELEVATEUR_HAUT                    7
#define POUSSOIR_MAGASINBLOC_ENTREE_OUT   8
#define POUSSOIR_MAGASINBLOC_SORTIE_OUT   9
#define DETECTEUR_OPTIQUE_PLATEAU        10
#define DETECTEUR_OPTIQUE_CHUTE          11
#define BOUTON_DEPART                    12
#define BOUTON_ARRET                     13
#define INDICATIONPRESSION               14
#define DETECTEUR_HAUTEUR                15


//Signaux Entran dans la table

#define DETECTEUR_HAUTEUR_5V              0
#define DETECTEUR_HAUTEUR_GND             1
#define LUMIERE_VERTE                     2
#define CYLINDRE_VENTOUSE_BAS_IN          3
#define CYLINDRE_VENTOUSE_HAUT_IN         4
#define VACUUM_ON                         5
#define ELEVATEUR_POSITION_BASSE          6
#define ELEVATEUR_POSITION_HAUTE          7
#define POUSSOIR_MAGASINBLOC_ENTREE_IN    8
#define POUSSOIR_MAGASINBLOC_SORTIE_IN    9
#define EJECTEUR_BLOC_SORTIE_IN          10
#define RELAIS_CONVOYEUR                 11



//Drive Moteur

#define DRIVE_MOTEUR_MODE        0
#define DRIVE_MOTEUR_STOP        1
#define SELECTION_POSITION_0     2
#define SELECTION_POSITION_1     3
#define SELECTION_POSITION_2     4
#define SELECTION_POSITION_3     5
#define END_STAGE_ENABLE         6
#define CONTROLLER_RELEASE       7
#define LIMIT_SWITCH_0           8
#define LIMIT_SWITCH_1           9
#define START_POSITION_PROCESS  10
#define MODE                    11
#define READY_FOR_OPERATION     12
#define DEFAULT_MOTION_COMPLETE 13
#define DEFAULT_ACK_START       14
#define DEFAULT_ERROR           15
#define ALIMENTATION_GND        16
#define ALIMENTATION_24v        17 


#endif