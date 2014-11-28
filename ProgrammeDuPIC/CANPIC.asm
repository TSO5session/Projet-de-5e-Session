
_main:

;CANPIC.c,32 :: 		void main()
;CANPIC.c,35 :: 		vInitPic();                                            //Init PIC18F258 4Mhz
	CALL        _vInitPic+0, 0
;CANPIC.c,36 :: 		vInitRS232();                                          //Init RS232 9600
	CALL        _vInitRS232+0, 0
;CANPIC.c,38 :: 		vTransChaine("RS232OK9600");                           //Test RS232
	MOVLW       ?lstr1_CANPIC+0
	MOVWF       FARG_vTransChaine_ucpChaine+0 
	MOVLW       hi_addr(?lstr1_CANPIC+0)
	MOVWF       FARG_vTransChaine_ucpChaine+1 
	CALL        _vTransChaine+0, 0
;CANPIC.c,39 :: 		Can_Init_Flags = 0;                                    //
	CLRF        _Can_Init_Flags+0 
;CANPIC.c,40 :: 		Can_Send_Flags = 0;                                    //clear flags
	CLRF        _Can_Send_Flags+0 
;CANPIC.c,41 :: 		Can_Rcv_Flags  = 0;
	CLRF        _Can_Rcv_Flags+0 
;CANPIC.c,44 :: 		_CAN_TX_NO_RTR_FRAME;
	MOVLW       252
	MOVWF       _Can_Send_Flags+0 
;CANPIC.c,49 :: 		_CAN_CONFIG_VALID_STD_MSG;
	MOVLW       187
	MOVWF       _Can_Init_Flags+0 
;CANPIC.c,50 :: 		CANInitialize(1,1,3,3,1,Can_Init_Flags);                  //Initialize CAN module
	MOVLW       1
	MOVWF       FARG_CANInitialize_SJW+0 
	MOVLW       1
	MOVWF       FARG_CANInitialize_BRP+0 
	MOVLW       3
	MOVWF       FARG_CANInitialize_PHSEG1+0 
	MOVLW       3
	MOVWF       FARG_CANInitialize_PHSEG2+0 
	MOVLW       1
	MOVWF       FARG_CANInitialize_PROPSEG+0 
	MOVLW       187
	MOVWF       FARG_CANInitialize_CAN_CONFIG_FLAGS+0 
	CALL        _CANInitialize+0, 0
;CANPIC.c,52 :: 		CANSetOperationMode(_CAN_MODE_CONFIG,0xFF);               //set CONFIGURATION mode
	MOVLW       128
	MOVWF       FARG_CANSetOperationMode_mode+0 
	MOVLW       255
	MOVWF       FARG_CANSetOperationMode_WAIT+0 
	CALL        _CANSetOperationMode+0, 0
;CANPIC.c,53 :: 		CANSetMask(_CAN_MASK_B1,-1,_CAN_CONFIG_STD_MSG);          //set all mask1 bits to ones
	CLRF        FARG_CANSetMask_CAN_MASK+0 
	MOVLW       255
	MOVWF       FARG_CANSetMask_val+0 
	MOVLW       255
	MOVWF       FARG_CANSetMask_val+1 
	MOVWF       FARG_CANSetMask_val+2 
	MOVWF       FARG_CANSetMask_val+3 
	MOVLW       255
	MOVWF       FARG_CANSetMask_CAN_CONFIG_FLAGS+0 
	CALL        _CANSetMask+0, 0
;CANPIC.c,54 :: 		CANSetMask(_CAN_MASK_B2,-1,_CAN_CONFIG_STD_MSG);          //set all mask2 bits to ones
	MOVLW       1
	MOVWF       FARG_CANSetMask_CAN_MASK+0 
	MOVLW       255
	MOVWF       FARG_CANSetMask_val+0 
	MOVLW       255
	MOVWF       FARG_CANSetMask_val+1 
	MOVWF       FARG_CANSetMask_val+2 
	MOVWF       FARG_CANSetMask_val+3 
	MOVLW       255
	MOVWF       FARG_CANSetMask_CAN_CONFIG_FLAGS+0 
	CALL        _CANSetMask+0, 0
;CANPIC.c,55 :: 		CANSetFilter(_CAN_FILTER_B2_F4,ID_2nd,_CAN_CONFIG_STD_MSG);//set id of filter B2_F4 to 2nd node ID
	MOVLW       5
	MOVWF       FARG_CANSetFilter_CAN_FILTER+0 
	MOVLW       4
	MOVWF       FARG_CANSetFilter_val+0 
	MOVLW       0
	MOVWF       FARG_CANSetFilter_val+1 
	MOVLW       0
	MOVWF       FARG_CANSetFilter_val+2 
	MOVLW       0
	MOVWF       FARG_CANSetFilter_val+3 
	MOVLW       255
	MOVWF       FARG_CANSetFilter_CAN_CONFIG_FLAGS+0 
	CALL        _CANSetFilter+0, 0
;CANPIC.c,56 :: 		CANSetOperationMode(_CAN_MODE_NORMAL,0xFF);               //set NORMAL mode
	CLRF        FARG_CANSetOperationMode_mode+0 
	MOVLW       255
	MOVWF       FARG_CANSetOperationMode_WAIT+0 
	CALL        _CANSetOperationMode+0, 0
;CANPIC.c,58 :: 		while (1)
L_main0:
;CANPIC.c,60 :: 		if(ucTrame == COMPLETE)
	MOVF        _ucTrame+0, 0 
	XORLW       0
	BTFSS       STATUS+0, 2 
	GOTO        L_main2
;CANPIC.c,62 :: 		cPoid[0] = ucTabRx232[11];
	MOVF        _ucTabRx232+11, 0 
	MOVWF       _cPoid+0 
;CANPIC.c,63 :: 		cPoid[1] = ucTabRx232[12];
	MOVF        _ucTabRx232+12, 0 
	MOVWF       _cPoid+1 
;CANPIC.c,64 :: 		cPoid[2] = ucTabRx232[13];
	MOVF        _ucTabRx232+13, 0 
	MOVWF       _cPoid+2 
;CANPIC.c,65 :: 		cPoid[3] = ucTabRx232[14];
	MOVF        _ucTabRx232+14, 0 
	MOVWF       _cPoid+3 
;CANPIC.c,66 :: 		cPoid[4] = ucTabRx232[15];
	MOVF        _ucTabRx232+15, 0 
	MOVWF       _cPoid+4 
;CANPIC.c,67 :: 		ucIndiceTampon = 0;
	CLRF        _ucIndiceTampon+0 
;CANPIC.c,68 :: 		ucNbCaract = 0;
	CLRF        _ucNbCaract+0 
;CANPIC.c,69 :: 		ucTrame = INCOMPLETE;            //Trame incomplete
	MOVLW       1
	MOVWF       _ucTrame+0 
;CANPIC.c,71 :: 		CANWrite(ID_2nd, cPoid, 5, Can_Send_Flags);
	MOVLW       4
	MOVWF       FARG_CANWrite_id+0 
	MOVLW       0
	MOVWF       FARG_CANWrite_id+1 
	MOVLW       0
	MOVWF       FARG_CANWrite_id+2 
	MOVLW       0
	MOVWF       FARG_CANWrite_id+3 
	MOVLW       _cPoid+0
	MOVWF       FARG_CANWrite_data_+0 
	MOVLW       hi_addr(_cPoid+0)
	MOVWF       FARG_CANWrite_data_+1 
	MOVLW       5
	MOVWF       FARG_CANWrite_DataLen+0 
	MOVF        _Can_Send_Flags+0, 0 
	MOVWF       FARG_CANWrite_CAN_TX_MSG_FLAGS+0 
	CALL        _CANWrite+0, 0
;CANPIC.c,72 :: 		}
L_main2:
;CANPIC.c,112 :: 		}
	GOTO        L_main0
;CANPIC.c,113 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
