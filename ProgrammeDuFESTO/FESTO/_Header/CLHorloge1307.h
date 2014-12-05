// ************************** FICHIER: CLHorloge1307.H *************************
// Auteur:       Louis-Normand Ang-Houle, Hicham Safoine, Vincent Chouinard
// Date:         1 mai 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.1
//
// Description:  Fonctions pour l'horloge RTC I2C DS1307
// *****************************************************************************
#include "CLI2CPort.h"

#ifndef CLHORLOGE1307H
   #define CLHORLOGE1307H

#define BOITIER1307 0xD0  // Adresse DS1307
#define SQW1307     0x07  // Registre Onde Carree
#define ANNEE1307   0x06  // Registre Annee
#define MOIS1307    0x05  // Registre Mois
#define JOUR1307    0x04  // Registre Jour
#define HEURE1307   0x02  // Registre Heure
#define MIN1307     0x01  // Registre Minute
#define SEC1307     0x00  // Registre Seconde

struct STDate
{
UC ucJour;
UC ucMois;
UC ucAnnee;
};

class CLHorloge1307 : public CLI2CPort
{
public:
   CLHorloge1307(void);
  ~CLHorloge1307(void);

   void vReadTime  (void);
   void vWriteTime (void);
   void vReadDate  (void);
   void vWriteDate (void);

   struct STTemps  stTemps;
   struct STDate   stDate;

protected:

private:
   struct STTemps  stHMS;
   struct STDate   stJMA;
 };
#endif
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
