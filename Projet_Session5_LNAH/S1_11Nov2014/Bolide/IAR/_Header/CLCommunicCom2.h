#include "DeclarationGenerale.h"
#include "CLEcran.h"

#define LONGEURBUFFER 5
#define LONGEURTRAME  5

#ifndef CLCOMMUNICCOM2H
 #define CLCOMMUNICCOM2H

class CLCommunicCom2
 {
  public:
   CLCommunicCom2 (void);
   CLCommunicCom2 (UC ucLongBuf, UC ucLongTrame, UINT16 uiBaud);
   ~CLCommunicCom2 (void);
   
   UC ucInitLongTrame (UC ucLong);
   UC ucLireNbCaractRecu (void);
   UC ucLireEtatTrame (void);
   UC *ucpLireTrame (void);
   void vTransCaractere (UC ucCar);
   void vTransString (char *cChaine);
   void vSendTrame(UC ucKeyIN);
   UC ucCheckSumCalcul(UC uc1, UC uc2, UC uc3);  
     
  static UC *ucpEcritureTampon;

  protected:
  
  private:  
  
   class CLEcran clCommumicEcran;
      
   UC ucHigh; //Valeur haute du checksum
   UC ucLow;  //Valeur basse du checksum
  
   static UC ucLongeurTampon;
   static UC ucLongeurTrame;
   static UC ucNbCarRecu;
   static UC ucEtatTrame;
 
   static UC *ucpDebutTampon;  
   static UC *ucpFinTampon;
   static UC *ucpLectureTampon; 
   
   static UC ucCheckSUM;
   static UC ucCheckSumLow;
   static UC ucCheckSumHIGH;   
   
    __interrupt static void vInterruptSerial (void);
    void vInitBaudRate (UINT16 uiBaud);
    UC ucValideTrame(void);

 };   

#endif