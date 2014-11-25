// **************************StepMotor.cpp
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
#include "StepMotor.h"             // Fichier de definitions du clavier


//******************************************************************************
//                            LE CONSTRUCTEUR PAR DEFAUT
// *****************************************************************************
StepMotor :: StepMotor(void)
{

}

//******************************************************************************
//                            LE CONSTRUCTEUR PAR DEFAUT
// *****************************************************************************
StepMotor :: StepMotor(UC ucParametre)
{

}


// *****************************************************************************
//                            LE DESTRUCTEUR
// *****************************************************************************
StepMotor :: ~StepMotor(void)
{

}

void StepMotor :: ClockWise(void)
{
High(1); Low (2); Low (3); Low (4); Delay();
Low (1); High(2); Low (3); Low (4); Delay();
Low (1); Low (2); High(3); Low (4); Delay();
Low (1); Low (2); Low (3); High(4); Delay();
}

void StepMotor :: CounterClockWise(void)
{
Low (1); Low (2); Low (3); High(4); Delay();
Low (1); Low (2); High(3); Low (4); Delay();
Low (1); High(2); Low (3); Low (4); Delay();
High(1); Low (2); Low (3); Low (4); Delay(); 
}

void StepMotor :: High(UC Enroulement)
{
switch(Enroulement)
  { 
   case 1:
      Bobine1 = HIGH;
   break;

   case 2:
      Bobine2 = HIGH;
   break;

   case 3:
      Bobine3 = HIGH;
   break;

   case 4:
      Bobine4 = HIGH;
   break;
  }
}

void StepMotor :: Low(UC Enroulement)
{
switch(Enroulement)
  { 
   case 1:
      Bobine1 = LOW;
   break;

   case 2:
      Bobine2 = LOW;
   break;

   case 3:
      Bobine3 = LOW;
   break;

   case 4:
      Bobine4 = LOW;
   break;
  }  
}

void StepMotor :: Delay(void)
{
int i;
for(i = 0; i < InterStep; i++){/* Rien, hahaha! */ }
}
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX
