// ************************** FICHIER: CLTest.H  ******************************
//
// Auteur:       Louis-Normand Ang-Houle, Hicham Safoine, Vincent Chouinard
// Date:         1 mai 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.1
//
// Description: Fichier pour faire des tests
// *****************************************************************************
//
// DESCRIPTION DES FONCTIONS
//
//   void vControleTest(void)    Choix des tests a executer
//   void vTestEcran   (void)    Test des fonctions d'ecran
//   void vTestI2C     (void)    Test des fonctions du protocole I2C
//   void vTestCommunic(void)    Test des fonctions de communication serie
//
// *****************************************************************************
#include "DeclarationGenerale.h"
#include "CLInOutBase.h"
#include "CLEcran.h"


#ifdef UPSD3254A
   #include "CLClavier.h"
   #include "CLMCP2515.h" 
   #include "CLHorloge1307.h"
   #include "CLEcran.h"
   #include "CLRS232.h"
   #include "CLIOPCF8574.h"
   #include "CLFesto.h"
#endif

#ifdef DALLAS89C450
   #ifdef SPI_DALLAS
    #include "CLDAC7554.h"
    #include "CLTLV2544.h"
    #include "CLMCP23S09.h"
   #endif

   #ifdef I2C_DALLAS
    #include "CLDAC6574.h"
    #include "CLADCMAX1236.h"
    #include "CLIOPCF8574.h"
   #endif

   #include "CLVehicule.h" 
#endif

#ifndef CLTESTH
   #define CLTESTH

class CLTest
{
public:
   CLTest(void);
  ~CLTest(void);
  
   class CLEcran        clTestEcran;
   
   #ifdef UPSD3254A
   class CLClavier      clTestClavier;
   #endif
   
   void vControleTest    (void);
   void vTestGeneral     (void);
   void vTestEcran       (void);
   void vTestI2C         (void);
   void vTestSPI         (void);
   void vTestCAN         (void);
   void vTestCommunic    (void);
   void vTestVehicule    (void);
   
protected:

private:
 };
#endif
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

