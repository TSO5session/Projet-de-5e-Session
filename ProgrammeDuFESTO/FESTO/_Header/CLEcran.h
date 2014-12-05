// ************************** FICHIER: CLEcran.H  ******************************
// Auteur:       Louis-Normand Ang-Houle, Hicham Safoine, Vincent Chouinard
// Date:         1 mai 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.1
//
// Description:
// *****************************************************************************
//
// DESCRIPTION DES FONCTIONS
//
// CLEcran(void);
// CLEcran(USI uiAdresse);
// ~CLEcran(void);
//
// void vLCDClr(void);
// void vLCDInit(void);
// void vLCDCursor(UC ucCol, UC ucLine);
//
// void vLCDDisplayCarac(UC ucCaractere);
// void vLCDDisplayCarac(char cCaractere);
//
// void vLCDDisplayCaracChain(const UC *ucpMessage);
// void vLCDDisplayCaracChain(const char *cpMessage);
//
// void vHexToASCII(UC ucHexCar, UC *ucpHi, UC *ucpLo);
// void vLCDDisplayHexCarac(UC ucHexCar);
//
// void vLCDDisplayScreen(const UC *ucpEcran);
// void vLCDBusy(void);
// void vDelaiLCD(USI uiDelai);
//
// *****************************************************************************
#include "DeclarationGenerale.h"
#include "CLInOutBase.h"

#ifndef CLECRANH
   #define CLECRANH

#define ECRANCONFIG 0
#define ECRANFLAG   1
#define ECRANWR     2
#define ECRANRD     3

class CLEcran : public CLInOutBase
{
public:
   CLEcran(void);
   CLEcran(USI uiAdresse);
  ~CLEcran(void);

   void vLCDClr         (void);
   void vLCDInit        (void);
   void vLCDCursor      (UC   ucCol, UC ucLine);
   void vLCDDisplayCarac(UC   ucCaractere);
   void vLCDDisplayCarac(char cCaractere);

   void vHexToASCII     (UC  ucHexCar,   UC *ucpHi,      UC *ucpLo);
   void vHexToASCII     (USI uiHexCar,   UC *ucpHiOctHi, UC *ucpLoOctHi,
                         UC *ucpHiOctLo, UC *ucpLoOctLo);

   void vLCDDisplayHexCarac  (UC          ucHexCar);
   void vLCDDisplayHexCarac  (USI         uiHexCar);
   void vLCDDisplayCaracChain(const UC   *ucpMessage);
   void vLCDDisplayCaracChain(const char *cpMessage);
   void vLCDDisplayScreen    (const UC   *ucpEcran);
   void vLCDDisplayEtatPort  (UC          ucEtatPort);
   void vLCDDisplayDecimal   (F           fDecimal);
   void vLCDDisplayDecimal   (SI          siDecimal);

protected:

private:
   USI  uiAdresseEcran;
   void vLCDBusy (void);
   void vDelaiLCD(USI uiDelai);
};
#endif
