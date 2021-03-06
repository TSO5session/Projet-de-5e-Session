#line 1 "C:/Synchro/Dropbox/Travaux/Automne 2014/ProjetSession5/ProgrammeDuPIC/PIC18F258.c"
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
#line 17 "C:/Synchro/Dropbox/Travaux/Automne 2014/ProjetSession5/ProgrammeDuPIC/PIC18F258.c"
volatile UC ucTrame =  1 , ucNbCaract = 0,
 ucIndiceTampon = 0, ucValPortB = 0, ucTxDataI2C, ucRxDataI2C;
UC ucTabRx232[26];
#line 37 "C:/Synchro/Dropbox/Travaux/Automne 2014/ProjetSession5/ProgrammeDuPIC/PIC18F258.c"
void vInitPic (void)
 {
 INTCON = 0xC0;
 OSCCON = 0b00000000;
 ADCON0.ADON = 0;
 TRISC = 0b10000000;
 TRISB = 0b00001000;
 }
#line 62 "C:/Synchro/Dropbox/Travaux/Automne 2014/ProjetSession5/ProgrammeDuPIC/PIC18F258.c"
void vInitRS232 (void)
 {
 PIE1 = 0x20;
 SPBRG = 0x19;
 RCSTA = 0x90;
 TXSTA = 0x24;
 }
#line 86 "C:/Synchro/Dropbox/Travaux/Automne 2014/ProjetSession5/ProgrammeDuPIC/PIC18F258.c"
void vTx232 (UC ucSend)
 {
 while (PIR1.TXIF == 0);
 TXREG = ucSend;
 }
#line 107 "C:/Synchro/Dropbox/Travaux/Automne 2014/ProjetSession5/ProgrammeDuPIC/PIC18F258.c"
void vTransChaine (UC *ucpChaine)
 {
 while (*ucpChaine != 0x00)
 {
 vTx232(*ucpChaine);
 ucpChaine++;
 }
 }
#line 136 "C:/Synchro/Dropbox/Travaux/Automne 2014/ProjetSession5/ProgrammeDuPIC/PIC18F258.c"
void interrupt (void)
 {
 INTCON.GIE = 0;

 if (PIR1.RCIF)
 {
 if (ucIndiceTampon >=  26 ){ucIndiceTampon = 0;}

 ucTabRx232[ucIndiceTampon] = RCREG;
 ucIndiceTampon++;

 if (ucNbCaract <  26  - 1)
 {
 ucNbCaract++;
 ucTrame =  1 ;
 }
 else
 {
 ucIndiceTampon = 0;
 ucNbCaract = 0;
 ucTrame =  0 ;
 }

 if(ucNbCaract > 13)
 {
 if(ucTabRx232[13] != '.')
 {
 ucIndiceTampon = 0;
 ucNbCaract = 0;
 ucTrame =  1 ;
 }
 }
 }
 INTCON.GIE = 1;
 PIR1.RCIF = 0;
 }

void vDelai (UC ucDelai)
 {
 for (; ucDelai>0; ucDelai--);
 }
