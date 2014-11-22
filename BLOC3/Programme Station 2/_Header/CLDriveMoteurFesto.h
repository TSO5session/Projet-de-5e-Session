// ************************** FICHIER: CLDriveMoteurFesto.H *********************
//
// Fonctions pour la drive de moteur Festo
//
// Application realisee avec IAR C++ 8.10
//
// AUTEUR : LOUIS-NORMAND ANG HOULE
// DATE CREATION : 2014/11/21 VERSION: 1.0
// DATE MODIFICATION: ****-**-**
//
// *****************************************************************************
// 
// DESCRIPTION DES FONCTIONS
// 
// vPositionner(UC ucPosition): Positionnement du moteur aux positions assignes
//
//
// *****************************************************************************

#include "DeclarationGenerale.h"
#include "CLI2CPort.h"

#ifndef CLDRIVEMOTEURFESTOH
#define CLDRIVEMOTEURFESTOH

#define RECEPTACLE 0
#define RESERVOIR1 1
#define RESERVOIR2 2
#define RESERVOIR3 3
#define CHUTE      4

#define RECORDSLCT0 
#define RECORDSLCT1
#define RECORDSLCT2
#define RECORDSLCT3
#define STARTPOS
#define STOPDRV
#define ENABLEDRV

#define DRVREADY
#define MOTIONCPLT
#define DRVERROR

class CLDriveMoteurFesto : CLI2CPort
{
   public:  
   CLDriveMoteurFesto(void);
  ~CLDriveMoteurFesto(void);
   UC ucPositionner(UC ucPosition);
   
   protected:

   private:

};

#endif

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@