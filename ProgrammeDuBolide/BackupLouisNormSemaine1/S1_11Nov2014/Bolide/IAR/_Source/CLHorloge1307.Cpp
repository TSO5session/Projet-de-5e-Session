// ************************** FICHIER: CLHORLOGE1307.CPP ***********************
//
// Fonctions pour l'horloge RTC I2C DS1307
//
// Application realisee avec IAR C++ 8.10
//
// LIMITATION DU COMPILATEUR:
// Impossible de faire de l'heritage multiple.
//
// Note: on peut utiliser XAR pour creer des librairies.
// On peut mettre les librairies dans le projets et Exclure de la compilation
// les modules qui sont contenus dans la librairie.
//
// Pour Windows 7 on utilise la VMware pour programmer le upsd 3254A avec CAPS.
//
// AUTEUR : LOUIS-NORMAND ANG HOULE
// DATE CREATION : 2014/03/27 VERSION: 1.0
// DATE MODIFICATION: ****-**-**
//
// *****************************************************************************

#include "CLHorloge1307.h"

// Constructeur par defaut ////////////////////////////////////////////////////

CLHorloge1307 :: CLHorloge1307 (void)
 {
 }

// Destructeur ////////////////////////////////////////////////////////////////

CLHorloge1307 :: ~CLHorloge1307(void)
 {
 }

///////////////////////////////////////////////////////////////////////////////
// void CLHorloge1307 :: vReadTime (void)
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

void CLHorloge1307 :: vReadTime (void)
 {
    stHMS.ucHeure   = ucI2CLireDonnee(BOITIER1307, HEURE1307);
    stHMS.ucMinute  = ucI2CLireDonnee(BOITIER1307, MIN1307);
    stHMS.ucSeconde = ucI2CLireDonnee(BOITIER1307, SEC1307);

    stTemps.ucHeure   = stHMS.ucHeure;
    stTemps.ucMinute  = stHMS.ucMinute;
    stTemps.ucSeconde = stHMS.ucSeconde;
 }

///////////////////////////////////////////////////////////////////////////////
// void CLHorloge1307 :: vWriteTime (void)
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

void CLHorloge1307 :: vWriteTime (void)
 {
    stHMS.ucHeure   = stTemps.ucHeure;
    stHMS.ucMinute  = stTemps.ucMinute;
    stHMS.ucSeconde = stTemps.ucSeconde;

    vI2CEcrireDonnee(BOITIER1307, HEURE1307, stHMS.ucHeure);
    vI2CEcrireDonnee(BOITIER1307, MIN1307,stHMS.ucMinute);
    vI2CEcrireDonnee(BOITIER1307, SEC1307,stHMS.ucSeconde);
 }

///////////////////////////////////////////////////////////////////////////////
// void CLHorloge1307 :: vReadDate(void)
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

void CLHorloge1307 :: vReadDate(void)
 {
    stJMA.ucAnnee = ucI2CLireDonnee(BOITIER1307, ANNEE1307);
    stJMA.ucMois  = ucI2CLireDonnee(BOITIER1307, MOIS1307);
    stJMA.ucJour  = ucI2CLireDonnee(BOITIER1307, JOUR1307);

    stDate.ucAnnee = stJMA.ucAnnee;
    stDate.ucMois  = stJMA.ucMois;
    stDate.ucJour  = stJMA.ucJour;
 }

///////////////////////////////////////////////////////////////////////////////
// void CLHorloge1307 :: vWriteDate (void)
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

void CLHorloge1307 :: vWriteDate (void)
 {
    stJMA.ucAnnee = stDate.ucAnnee;
    stJMA.ucMois  = stDate.ucMois;
    stJMA.ucJour  = stDate.ucJour;

    vI2CEcrireDonnee(BOITIER1307, ANNEE1307, stJMA.ucAnnee);
    vI2CEcrireDonnee(BOITIER1307, MOIS1307 , stJMA.ucMois);
    vI2CEcrireDonnee(BOITIER1307, JOUR1307 , stJMA.ucJour);

 }

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
