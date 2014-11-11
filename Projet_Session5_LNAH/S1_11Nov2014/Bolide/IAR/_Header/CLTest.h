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
#include "CLClavier.h"

#include "CLDAC7554.h"
#include "CLTLV2544.h"

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
   
   class CLDAC7554      clTestDAC7554;
   class CLTLV2544      clTestTLV2544;
   
   void vControleTest    (void);
   void vTestGeneral     (void);
   void vTestEcran       (void);
   void vTestI2C         (void);
   void vTestSPI         (void);
   void vTestCommunic    (void);
   
protected:

private:
 };
#endif
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

