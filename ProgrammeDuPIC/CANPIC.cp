#line 1 "J:/Projet_Session5_LNAH/S3_24Nov2014/MIKROC/CANPIC.c"
#line 1 "j:/projet_session5_lnah/s3_24nov2014/mikroc/pic18f258.h"
#line 1 "j:/projet_session5_lnah/s3_24nov2014/mikroc/declarationpic.h"
#line 72 "j:/projet_session5_lnah/s3_24nov2014/mikroc/declarationpic.h"
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
#line 19 "j:/projet_session5_lnah/s3_24nov2014/mikroc/pic18f258.h"
void vDelai(UC ucDelai);
void vInitPic (void);
void vInitRS232 (void);
void vTx232 (UC ucSend);
void vTransChaine (UC *ucpChaine);
#line 1 "j:/projet_session5_lnah/s3_24nov2014/mikroc/declarationpic.h"
#line 16 "J:/Projet_Session5_LNAH/S3_24Nov2014/MIKROC/CANPIC.c"
unsigned char Can_Init_Flags, Can_Send_Flags, Can_Rcv_Flags;
unsigned char Rx_Data_Len;
unsigned char HeureFlag = 0, Acknowledge;
char RxTx_Data[8];
char Msg_RcvdFlag;
char cPoid[8];
const long ID_1st = 0x0007, ID_2nd=0x0004, ID_3rd = 0x0005;
long Rx_ID;
extern UC ucTabRx232[8];
extern UC ucTrame;
extern UC ucNbCaract;
extern UC ucIndiceTampon;

struct STHorloge stHeure;
struct STHorloge stSetHeure;

void main()
{

 vInitPic();
 vInitRS232();

 vTransChaine("RS232OK9600");
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
 CANSetMask(_CAN_MASK_B1,-1,_CAN_CONFIG_STD_MSG);
 CANSetMask(_CAN_MASK_B2,-1,_CAN_CONFIG_STD_MSG);
 CANSetFilter(_CAN_FILTER_B2_F4,ID_2nd,_CAN_CONFIG_STD_MSG);
 CANSetOperationMode(_CAN_MODE_NORMAL,0xFF);

 while (1)
 {
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

 CANWrite(ID_2nd, cPoid, 5, Can_Send_Flags);
 }
#line 112 "J:/Projet_Session5_LNAH/S3_24Nov2014/MIKROC/CANPIC.c"
 }
}
