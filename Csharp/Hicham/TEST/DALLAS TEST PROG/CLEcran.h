// ************************** FICHIER: CLEcran.H  ******************************

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
// void Lettre(UC ucCaractere);
// void Lettre(char cCaractere);
//
// void String(const UC *ucpMessage);
// void String(const char *cpMessage);
//
// void vHexToASCII(UC ucHexCar, UC *ucpHi, UC *ucpLo);
// void vLCDDisplayHexCarac(UC ucHexCar);
//
// void vLCDDisplayScreen(const UC *ucpEcran);
// void vLCDBusy(void);
// void vDelaiLCD(USI uiDelai);
//
// *****************************************************************************
#include "_DeclarationGenerale.h"
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

   void vLCDClr              (void);
   void vLCDInit             (void);
   void vLCDCursor           (UC   ucCol, UC ucLine);
   void Lettre               (UC   ucCaractere);
   void Lettre               (char cCaractere);
   void String               (const UC   *ucpMessage);
   void String               (const char *cpMessage);   

   void vHexToASCII          (UC   ucHexCar,   UC *ucpHi,      UC *ucpLo);
   void vHexToASCII          (USI  uiHexCar,   UC *ucpHiOctHi, UC *ucpLoOctHi,
                              UC  *ucpHiOctLo, UC *ucpLoOctLo);

   void vLCDDisplayHexCarac  (UC          ucHexCar);
   void vLCDDisplayHexCarac  (USI         uiHexCar);
   void vLCDDisplayScreen    (const UC   *ucpEcran);
   void vLCDDisplayEtatPort  (UC          ucEtatPort);
   void vLCDDisplayFloat     (float       fInputFloat);

protected:    
                              
private:
   USI  uiAdresseEcran;
   void vLCDBusy (void);
   void vDelaiLCD(USI uiDelai);
};
#endif
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
