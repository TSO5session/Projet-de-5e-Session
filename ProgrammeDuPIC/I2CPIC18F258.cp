#line 1 "C:/Synchro/Dropbox/Travaux/Automne 2014/ProjetSession5/ProgrammeDuPIC/I2CPIC18F258.c"
#line 1 "c:/synchro/dropbox/travaux/automne 2014/projetsession5/programmedupic/i2cpic18f258.h"
#line 1 "c:/synchro/dropbox/travaux/automne 2014/projetsession5/programmedupic/pic18f258.h"
#line 1 "c:/synchro/dropbox/travaux/automne 2014/projetsession5/programmedupic/declarationpic.h"
#line 70 "c:/synchro/dropbox/travaux/automne 2014/projetsession5/programmedupic/declarationpic.h"
typedef unsigned char UC;
typedef unsigned int UI;
typedef char C;
typedef unsigned short int US;

struct STHorloge
 {
 UC ucHeure;
 UC ucMinute;
 UC ucSeconde;
 };
#line 20 "c:/synchro/dropbox/travaux/automne 2014/projetsession5/programmedupic/pic18f258.h"
void vDelai (UC ucDelai);
void vInitPic (void);
void vInitRS232 (void);
void vTx232 (UC ucSend);
void vTransChaine (UC *ucpChaine);
#line 28 "c:/synchro/dropbox/travaux/automne 2014/projetsession5/programmedupic/i2cpic18f258.h"
void vInitI2CMaster (void);
void vInitI2CSlave (void);
void vI2CStart (void);
void vI2CStop (void);
void vI2CReStart (void);
void vI2CCheck (void);
void vSendACK (UC ucAck);
UC ucReadACK (void);
UC ucI2CLireOctet (UC ucAck);
void vI2CEcrireOctet (UC ucData, UC ucRW);
void vDelaiI2C (UI uiDelai);
void vI2CEcrireDS1307 (UC ucADR, UC ucH, UC ucM, UC ucS);
void vI2CLireDS1307 (UC ucADR);
void vI2CEcrireEEPROM (UC ucData, UI uiAdr, UC ucAdrChip);
UC ucI2CLireEEPROM (UI uiAdr, UC ucAdrChip);
void vI2CEcrirePCF8574 (UC ucAdr, UC ucData);
UC ucI2CLirePCF8574 (UC ucAdr);
#line 24 "C:/Synchro/Dropbox/Travaux/Automne 2014/ProjetSession5/ProgrammeDuPIC/I2CPIC18F258.c"
UC ucTABHMS[3];
#line 40 "C:/Synchro/Dropbox/Travaux/Automne 2014/ProjetSession5/ProgrammeDuPIC/I2CPIC18F258.c"
void vInitI2CMaster (void)
 {
 TRISC4_bit = 1;
 TRISC3_bit = 0;
 SSPSTAT.SMP = 1;
 SSPSTAT.CKE = 0;
 SSPADD = 0x09;
 SSPCON1 = 0b00101000;
 SSPCON2 = 0b00000000;

 }
#line 66 "C:/Synchro/Dropbox/Travaux/Automne 2014/ProjetSession5/ProgrammeDuPIC/I2CPIC18F258.c"
void vInitI2CSlave (void)
 {
 TRISB4_bit = 1;
 TRISB6_bit = 1;
 SSPSTAT.SMP = 1;
 SSPSTAT.CKE = 0;
 SSPADD = 0b00110000;
 SSPCON1 = 0b00110110;

 }
#line 91 "C:/Synchro/Dropbox/Travaux/Automne 2014/ProjetSession5/ProgrammeDuPIC/I2CPIC18F258.c"
void vI2CCheck (void)
 {
 while (SSPCON2.ACKEN) ;
 while (SSPCON2.RCEN) ;
 while (SSPCON2.PEN) ;
 while (SSPCON2.SEN) ;
 while (SSPCON2.RSEN) ;
 while (SSPSTAT.R_NOT_W);
 }
#line 115 "C:/Synchro/Dropbox/Travaux/Automne 2014/ProjetSession5/ProgrammeDuPIC/I2CPIC18F258.c"
void vI2CStart (void)
 {
 vI2CCheck();
 SSPCON2.SEN = 1;
 }
#line 135 "C:/Synchro/Dropbox/Travaux/Automne 2014/ProjetSession5/ProgrammeDuPIC/I2CPIC18F258.c"
void vI2CStop (void)
 {
 vI2CCheck();
 SSPCON2.PEN = 1;
 }
#line 155 "C:/Synchro/Dropbox/Travaux/Automne 2014/ProjetSession5/ProgrammeDuPIC/I2CPIC18F258.c"
void vI2CReStart (void)
 {
 vI2CCheck();
 SSPCON2.RSEN = 1;
 }
#line 175 "C:/Synchro/Dropbox/Travaux/Automne 2014/ProjetSession5/ProgrammeDuPIC/I2CPIC18F258.c"
UC ucReadACK (void)
 {
 return(SSPCON2.ACKSTAT);
 }
#line 194 "C:/Synchro/Dropbox/Travaux/Automne 2014/ProjetSession5/ProgrammeDuPIC/I2CPIC18F258.c"
void vSendACK (UC ucAck)
 {
 vI2CCheck();
 SSPCON2.ACKDT = ucAck;
 SSPCON2.ACKEN = 1;
 }
#line 216 "C:/Synchro/Dropbox/Travaux/Automne 2014/ProjetSession5/ProgrammeDuPIC/I2CPIC18F258.c"
void vI2CEcrireOctet (UC ucData, UC ucRW)
 {
 vI2CCheck();
 switch (ucRW)
 {
 case  0 :
 SSPBUF = ucData + 1;
 break;

 case  1 :
 SSPBUF = ucData + 0;
 break;
 }
 while (SSPSTAT.BF != 0);
 while (ucReadACK() != 0);
 }
#line 246 "C:/Synchro/Dropbox/Travaux/Automne 2014/ProjetSession5/ProgrammeDuPIC/I2CPIC18F258.c"
UC ucI2CLireOctet (UC ucAck)
 {
 vI2CCheck();
 SSPCON2.RCEN = 1;
 while (SSPCON2.RCEN != 0);
 vSendACK (ucAck);
 return (SSPBUF);
 }
#line 271 "C:/Synchro/Dropbox/Travaux/Automne 2014/ProjetSession5/ProgrammeDuPIC/I2CPIC18F258.c"
void vI2CEcrireEEPROM (UC ucData, UI uiAdr, UC ucAdrChip)
 {
 UC ucAdrH, ucAdrL;
 ucAdrH = ((uiAdr & 0xFF00) >> 8);
 ucAdrL = (uiAdr & 0x00FF);

 vI2CStart();
 vI2CEcrireOctet(ucAdrChip,  1 );
 vI2CEcrireOctet(ucAdrH,  1 );
 vI2CECrireOctet(ucAdrL,  1 );
 vI2CEcrireOctet(ucData,  1 );
 vI2CStop();

 }
#line 301 "C:/Synchro/Dropbox/Travaux/Automne 2014/ProjetSession5/ProgrammeDuPIC/I2CPIC18F258.c"
UC ucI2CLireEEPROM (UI uiAdr, UC ucAdrChip)
 {
 UC ucAdrH, ucAdrL, ucDataReturn;
 ucAdrH = ((uiAdr & 0xFF00) >> 8);
 ucAdrL = (uiAdr & 0x00FF);

 vI2CStart();
 vI2CEcrireOctet(ucAdrChip,  1 );
 vI2CEcrireOctet(ucAdrH,  1 );
 vI2CEcrireOctet(ucAdrL,  1 );
 vI2CReStart();

 vI2CEcrireOctet(ucAdrChip,  0 );
 ucDataReturn = ucI2CLireOctet( 1 );
 vI2CStop();

 return (ucDataReturn);
 }
#line 335 "C:/Synchro/Dropbox/Travaux/Automne 2014/ProjetSession5/ProgrammeDuPIC/I2CPIC18F258.c"
void vI2CEcrirePCF8574 (UC ucAdr, UC ucData)
 {
 vI2CStart();
 vI2CEcrireOctet(ucAdr,  1 );
 vI2CEcrireOctet(ucData,  1 );
 vI2CStop();
 }
#line 357 "C:/Synchro/Dropbox/Travaux/Automne 2014/ProjetSession5/ProgrammeDuPIC/I2CPIC18F258.c"
UC ucI2CLirePCF8574 (UC ucAdr)
 {
 UC ucDataReturn;
 vI2CStart();
 vI2CEcrireOctet(ucAdr,  0 );
 ucDataReturn = ucI2CLireOctet( 1 );
 vI2CStop();
 return (ucDataReturn);
 }

void vI2CEcrireDS1307 (UC ucADR, UC ucH, UC ucM, UC ucS)
 {
 vI2CStart();
 vI2CEcrireOctet(ucADR,  1 );
 vI2CEcrireOctet( 0x02 ,  1 );
 vI2CEcrireOctet(ucH,  1 );
 vI2CStop ();

 vI2CStart();
 vI2CEcrireOctet(ucADR,  1 );
 vI2CEcrireOctet( 0x01 ,  1 );
 vI2CEcrireOctet(ucM,  1 );
 vI2CStop ();

 vI2CStart();
 vI2CEcrireOctet(ucADR,  1 );
 vI2CEcrireOctet( 0x00 ,  1 );
 vI2CEcrireOctet(ucS,  1 );
 vI2CStop ();
 }

void vI2CLireDS1307 (UC ucADR)
 {
 UC ucDataDS1307[3];

 vI2CStart();
 vI2CEcrireOctet(ucADR,  1 );
 vI2CEcrireOctet( 0x02 ,  1 );
 vI2CReStart();
 vI2CEcrireOctet(ucADR,  0 );
 ucTABHMS[0] = ucI2CLireOctet( 1 );
 vI2CStop();

 vI2CStart();
 vI2CEcrireOctet(ucADR,  1 );
 vI2CEcrireOctet( 0x01 ,  1 );
 vI2CReStart();
 vI2CEcrireOctet(ucADR,  0 );
 ucTABHMS[1] = ucI2CLireOctet( 1 );
 vI2CStop();

 vI2CStart();
 vI2CEcrireOctet(ucADR,  1 );
 vI2CEcrireOctet( 0x00 ,  1 );
 vI2CReStart();
 vI2CEcrireOctet(ucADR,  0 );
 ucTABHMS[2] = ucI2CLireOctet( 1 );
 vI2CStop();
 }
#line 431 "C:/Synchro/Dropbox/Travaux/Automne 2014/ProjetSession5/ProgrammeDuPIC/I2CPIC18F258.c"
void vDelaiI2C (UI uiDelai)
 {
 for (; uiDelai>0; uiDelai--);
 }
