#include "_DeclarationGenerale.h"
#ifndef CLTESTH
 #define CLTESTH
 #include "CLEcran.h"

//******************************************************************************
#ifdef DALLAS89C450
  #include "CLInOutBase.h"
  //#include "CLHorloge.h"
  //#include "CLHOrlogeIO"
#endif
//******************************************************************************
#ifdef UPSD3254A
  #include "CLInOutBase.h"
  //#include "CLHorloge.h"
  //#include "CLHOrlogeIO"
#endif
//******************************************************************************

class CLTest
{ 
 public:
   CLTest(void);
   
   class CLEcran clEcran;
  // class CLHorloge clHorloge;
   //class CLHorlogeIO clHorlogeIO;
   //class CLInOutBase clInOutBase;
   
   void vControle(void);
   
   void vDelais(UINT16 usiTemps);
   void vTestEcran(void);
   //void vTestHorloge(void);
   
 protected:
 private:
  
};

#endif
