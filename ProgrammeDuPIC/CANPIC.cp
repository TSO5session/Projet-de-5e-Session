#line 1 "C:/Synchro/Dropbox/Travaux/Automne 2014/ProjetSession5/ProgrammeDuPIC/CANPIC.c"
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
#line 1 "c:/synchro/dropbox/travaux/automne 2014/projetsession5/programmedupic/i2cpic18f258.h"
#line 1 "c:/synchro/dropbox/travaux/automne 2014/projetsession5/programmedupic/pic18f258.h"
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
#line 1 "c:/synchro/dropbox/travaux/automne 2014/projetsession5/programmedupic/declarationpic.h"
#line 19 "C:/Synchro/Dropbox/Travaux/Automne 2014/ProjetSession5/ProgrammeDuPIC/CANPIC.c"
unsigned char Can_Init_Flags, Can_Send_Flags, Can_Rcv_Flags;
unsigned char Rx_Data_Len;
unsigned char HeureFlag = 0, Acknowledge;

char RxTx_Data[8];
char cPoid [5];
char cTemps [5];
char Msg_RcvdFlag;


const long ID_1st = 0x0007, ID_2nd=0x0004, ID_3rd = 0x0005;
long Rx_ID;

extern UC ucTABHMS[3];
extern UC ucTabRx232[8];
extern UC ucTrame;
extern UC ucNbCaract;
extern UC ucIndiceTampon;

struct STHorloge stHMS;

void main()
{
 vInitPic();
 vInitRS232();


 vInitI2CMaster();
 vI2CEcrireDS1307( 0xD0 , 9, 40, 51);
#line 52 "C:/Synchro/Dropbox/Travaux/Automne 2014/ProjetSession5/ProgrammeDuPIC/CANPIC.c"
 Can_Init_Flags = 0;
 Can_Send_Flags = 0;
 Can_Rcv_Flags = 0;
 Can_Send_Flags = _CAN_TX_PRIORITY_0 &
 _CAN_TX_STD_FRAME &
 _CAN_TX_NO_RTR_FRAME;
 Can_Init_Flags = _CAN_CONFIG_SAMPLE_THRICE &
 _CAN_CONFIG_PHSEG2_PRG_ON &
 _CAN_CONFIG_STD_MSG &
 _CAN_CONFIG_DBL_BUFFER_ON &
 _CAN_CONFIG_VALID_STD_MSG;
 CANInitialize(1,1,3,3,1,Can_Init_Flags);

 CANSetOperationMode(_CAN_MODE_CONFIG,0xFF);
 CANSetMask (_CAN_MASK_B1,-1,_CAN_CONFIG_STD_MSG);
 CANSetMask (_CAN_MASK_B2,-1,_CAN_CONFIG_STD_MSG);
 CANSetFilter(_CAN_FILTER_B2_F4,ID_2nd,_CAN_CONFIG_STD_MSG);
 CANSetOperationMode(_CAN_MODE_NORMAL,0xFF);

 CANWrite(ID_2nd, "BONJOUR", 7, Can_Send_Flags);

 while (1)
 {
 vI2CLireDS1307(0xD0);
 CANWrite(0x0012, "A", 1, Can_Send_Flags);
 if(ucTrame ==  0 )
 {
 cPoid[0] = ucTabRx232[11];
 cPoid[1] = ucTabRx232[12];
 cPoid[2] = ucTabRx232[13];
 cPoid[3] = ucTabRx232[14];
 cPoid[4] = ucTabRx232[15];
 ucIndiceTampon = 0;
 ucNbCaract = 0;
 ucTrame =  1 ;

 CANWrite(ID_3rd, cPoid, 5, Can_Send_Flags);

 cTemps[0] = 0x36;
 cTemps[1] = ucTABHMS[0];
 cTemps[2] = ucTABHMS[1];
 cTemps[3] = ucTABHMS[2];
 cTemps[4] = 0x20;
 CANWrite(ID_2nd, cTemps, 5, Can_Send_Flags);
 }
#line 120 "C:/Synchro/Dropbox/Travaux/Automne 2014/ProjetSession5/ProgrammeDuPIC/CANPIC.c"
 }
}
