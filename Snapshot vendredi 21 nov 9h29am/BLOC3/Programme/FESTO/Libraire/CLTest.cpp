#include "_DeclarationGenerale.h"
#include "CLTest.h"
#include "CLInOutBase.h"
#include "CLEcran.h"
//#include "CLHolrlogeIO.h"
//#include "CLHorloge.h"

//**********Constante***********************************************************
//#define DELAISZERO        2U //constante entiere unsigned 16 bits
//#define ACK               0U
//#define NOACK             1U
//******************************************************************************
CLTest :: CLTest(void)
{


}

//******************************************************************************

void CLTest :: vControle(void)
{
  //On ajoute les appel de fonction interne losque l on a besoin de fair un test
  //vTestEcran();
  //vTestHorloge();
  
}

//******************************************************************************


void CLTest :: vTestEcran(void)
{

  clEcran.vLcdClr();

}
//******************************************************************************
/*

void CLTest :: vTestHorloge
{
  //initialisation de l horloge
  while(1)
  { 
    //Lecture horloge
  }
}
*/
//******************************************************************************
void CLTest :: vDelais(UINT16 usiTemps)
{
  UINT16 uiCompte;
  for(uiCompte=0;uiCompte<usiTemps;uiCompte++);
}
//******************************************************************************