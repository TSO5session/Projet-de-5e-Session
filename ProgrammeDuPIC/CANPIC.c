//****************************************************************************//
// Application CAN sur carte PIC18F258
//
// Application permet l'ecriture et la lecture sur le bus CAN. On monitore le
// système via le port série qui permet d'envoyer ou de recevoir les commandes
// via le code.
//
// Realise par - Louis-Normand Ang-Houle, Vincent CHouinard, Gabriel Fortin-Bélanger
//               et Hicham Safoine
// MikroC Pro PIC 6.4.0
// Le 5 novembre 2014
//
// EPR 2012-2015
//****************************************************************************//
#include "PIC18F258.h"
#include "I2CPIC18F258.h"
#include "DeclarationPIC.h"

unsigned char Can_Init_Flags, Can_Send_Flags, Can_Rcv_Flags; //can flags
unsigned char Rx_Data_Len;                                   //received data length in bytes
unsigned char HeureFlag = 0, Acknowledge;

char RxTx_Data[8];                                           //can rx/tx data buffer
char cPoid    [5];
char cTemps   [5];
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
  vInitPic();                                            //Init PIC18F258 4Mhz
  vInitRS232();                                          //Init RS232 9600
  //vTransChaine("Test");
  
  vInitI2CMaster();
  vI2CEcrireDS1307(ADRHOR, 9, 40, 51); // 9 h 51
  
   /*
  vI2CEcrireDS1307(ADRHOR, stHMS.ucHeure, stHMS.ucMinute, stHMS.ucSeconde);*/
  
  Can_Init_Flags = 0;                                    //
  Can_Send_Flags = 0;                                    //clear flags
  Can_Rcv_Flags  = 0;
  Can_Send_Flags = _CAN_TX_PRIORITY_0 &                  //form value to be used
                   _CAN_TX_STD_FRAME &                   //with CANWrite
                   _CAN_TX_NO_RTR_FRAME;
  Can_Init_Flags = _CAN_CONFIG_SAMPLE_THRICE &           // form value to be used
                   _CAN_CONFIG_PHSEG2_PRG_ON &           // with CANInit
                   _CAN_CONFIG_STD_MSG &
                   _CAN_CONFIG_DBL_BUFFER_ON &
                   _CAN_CONFIG_VALID_STD_MSG;
  CANInitialize(1,1,3,3,1,Can_Init_Flags);                  //Initialize CAN module
  //250000KBPS, 1SJW, 3PH1, 3PH2, 8TQ, 1PHDel
  CANSetOperationMode(_CAN_MODE_CONFIG,0xFF);               //set CONFIGURATION mode
  CANSetMask  (_CAN_MASK_B1,-1,_CAN_CONFIG_STD_MSG);        //set all mask1 bits to ones
  CANSetMask  (_CAN_MASK_B2,-1,_CAN_CONFIG_STD_MSG);        //set all mask2 bits to ones
  CANSetFilter(_CAN_FILTER_B2_F4,ID_2nd,_CAN_CONFIG_STD_MSG);//set id of filter B2_F4 to 2nd node ID
  CANSetOperationMode(_CAN_MODE_NORMAL,0xFF);               //set NORMAL mode
  
  CANWrite(ID_2nd, "BONJOUR", 7, Can_Send_Flags);
  
  while (1)
   {
     vI2CLireDS1307(0xD0); // Envoie l'adresse du DS1307
     CANWrite(0x0012, "A", 1, Can_Send_Flags);// send incremented data back
     if(ucTrame == COMPLETE)
      {
        cPoid[0] = ucTabRx232[11];
        cPoid[1] = ucTabRx232[12];
        cPoid[2] = ucTabRx232[13];
        cPoid[3] = ucTabRx232[14];
        cPoid[4] = ucTabRx232[15];
        ucIndiceTampon = 0;
        ucNbCaract = 0;
        ucTrame = INCOMPLETE;            //Trame incomplete

        CANWrite(ID_3rd, cPoid, 5, Can_Send_Flags); // send incremented data back
        
        cTemps[0] = 0x36;
        cTemps[1] = ucTABHMS[0];
        cTemps[2] = ucTABHMS[1];
        cTemps[3] = ucTABHMS[2];
        cTemps[4] = 0x20;
        CANWrite(ID_2nd, cTemps, 5, Can_Send_Flags);
      }
      
/*if(HeureFlag)
      {
        vI2CEcrireDS1307(ADRHOR, stHMS.ucHeure, stHMS.ucMinute, stHMS.ucSeconde);
        HeureFlag = 0;
      }


     Msg_RcvdFlag = CANRead(&Rx_ID , RxTx_Data , &Rx_Data_Len, &Can_Rcv_Flags); // receive message
     
     if((Msg_RcvdFlag) && (Rx_ID == ID_1st))
      {
        CANWrite(0x0012, "A", 1, Can_Send_Flags);// send incremented data back
        switch(RxTx_Data[0])
         {
           case '6':
           stHMS.ucHeure     = RxTx_Data[2];
           stHMS.ucMinute    = RxTx_Data[3];
           stHMS.ucSeconde   = RxTx_Data[4];
           HeureFlag = 1;
           break;
         }
      }*/
   }
}
//LinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxLinuxTUX