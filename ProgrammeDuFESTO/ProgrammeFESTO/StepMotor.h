// **************************StepMotor.h
// Auteur:       Vincent Chouinard
// Date:         20 juillet 2014
// Version:      1.0
// Modification: Aucune
//
// Compilateur:  IAR 8.1
//
// Description:
// *****************************************************************************
#include "_DeclarationGenerale.h"  // Raccourcis de programmation & variables

#ifndef STEPMOTORH
  #define STEPMOTORH

#define Bobine1   P1_0
#define Bobine2   P1_1
#define Bobine3   P1_2
#define Bobine4   P1_3
#define InterStep 1000

class StepMotor //: public CLAutreClasse
{
public:
   StepMotor(void);                        // ***Constructeur par defaut
   StepMotor(unsigned char ucParametre);   // ***Constructeur initialisateur
  ~StepMotor(void);                        // ***Destructeur
  
   void ClockWise(void);
   void CounterClockWise(void);
   
protected:

private:
   void High (UC Enroulement);
   void Low  (UC Enroulement);
   void Delay(void);
};
#endif
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
