
_main:

;CANPIC.c,40 :: 		void main()
;CANPIC.c,42 :: 		vInitPic();                                            //Init PIC18F258 4Mhz
	CALL        _vInitPic+0, 0
;CANPIC.c,43 :: 		vInitRS232();                                          //Init RS232 9600
	CALL        _vInitRS232+0, 0
;CANPIC.c,46 :: 		vInitI2CMaster();
	CALL        _vInitI2CMaster+0, 0
;CANPIC.c,47 :: 		vI2CEcrireDS1307(ADRHOR, 9, 40, 51); // 9 h 51
	MOVLW       208
	MOVWF       FARG_vI2CEcrireDS1307_ucADR+0 
	MOVLW       9
	MOVWF       FARG_vI2CEcrireDS1307_ucH+0 
	MOVLW       40
	MOVWF       FARG_vI2CEcrireDS1307_ucM+0 
	MOVLW       51
	MOVWF       FARG_vI2CEcrireDS1307_ucS+0 
	CALL        _vI2CEcrireDS1307+0, 0
;CANPIC.c,52 :: 		Can_Init_Flags = 0;                                    //
	CLRF        _Can_Init_Flags+0 
;CANPIC.c,53 :: 		Can_Send_Flags = 0;                                    //clear flags
	CLRF        _Can_Send_Flags+0 
;CANPIC.c,54 :: 		Can_Rcv_Flags  = 0;
	CLRF        _Can_Rcv_Flags+0 
;CANPIC.c,57 :: 		_CAN_TX_NO_RTR_FRAME;
	MOVLW       252
	MOVWF       _Can_Send_Flags+0 
;CANPIC.c,62 :: 		_CAN_CONFIG_VALID_STD_MSG;
	MOVLW       187
	MOVWF       _Can_Init_Flags+0 
;CANPIC.c,63 :: 		CANInitialize(1,1,3,3,1,Can_Init_Flags);                  //Initialize CAN module
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
;CANPIC.c,65 :: 		CANSetOperationMode(_CAN_MODE_CONFIG,0xFF);               //set CONFIGURATION mode
	MOVLW       128
	MOVWF       FARG_CANSetOperationMode_mode+0 
	MOVLW       255
	MOVWF       FARG_CANSetOperationMode_WAIT+0 
	CALL        _CANSetOperationMode+0, 0
;CANPIC.c,66 :: 		CANSetMask  (_CAN_MASK_B1,-1,_CAN_CONFIG_STD_MSG);        //set all mask1 bits to ones
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
;CANPIC.c,67 :: 		CANSetMask  (_CAN_MASK_B2,-1,_CAN_CONFIG_STD_MSG);        //set all mask2 bits to ones
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
;CANPIC.c,68 :: 		CANSetFilter(_CAN_FILTER_B2_F4,ID_2nd,_CAN_CONFIG_STD_MSG);//set id of filter B2_F4 to 2nd node ID
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
;CANPIC.c,69 :: 		CANSetOperationMode(_CAN_MODE_NORMAL,0xFF);               //set NORMAL mode
	CLRF        FARG_CANSetOperationMode_mode+0 
	MOVLW       255
	MOVWF       FARG_CANSetOperationMode_WAIT+0 
	CALL        _CANSetOperationMode+0, 0
;CANPIC.c,71 :: 		CANWrite(ID_2nd, "BONJOUR", 7, Can_Send_Flags);
	MOVLW       4
	MOVWF       FARG_CANWrite_id+0 
	MOVLW       0
	MOVWF       FARG_CANWrite_id+1 
	MOVLW       0
	MOVWF       FARG_CANWrite_id+2 
	MOVLW       0
	MOVWF       FARG_CANWrite_id+3 
	MOVLW       ?lstr1_CANPIC+0
	MOVWF       FARG_CANWrite_data_+0 
	MOVLW       hi_addr(?lstr1_CANPIC+0)
	MOVWF       FARG_CANWrite_data_+1 
	MOVLW       7
	MOVWF       FARG_CANWrite_DataLen+0 
	MOVF        _Can_Send_Flags+0, 0 
	MOVWF       FARG_CANWrite_CAN_TX_MSG_FLAGS+0 
	CALL        _CANWrite+0, 0
;CANPIC.c,73 :: 		while (1)
L_main0:
;CANPIC.c,75 :: 		vI2CLireDS1307(0xD0); // Envoie l'adresse du DS1307
	MOVLW       208
	MOVWF       FARG_vI2CLireDS1307_ucADR+0 
	CALL        _vI2CLireDS1307+0, 0
;CANPIC.c,76 :: 		CANWrite(0x0012, "A", 1, Can_Send_Flags);// send incremented data back
	MOVLW       18
	MOVWF       FARG_CANWrite_id+0 
	MOVLW       0
	MOVWF       FARG_CANWrite_id+1 
	MOVWF       FARG_CANWrite_id+2 
	MOVWF       FARG_CANWrite_id+3 
	MOVLW       ?lstr2_CANPIC+0
	MOVWF       FARG_CANWrite_data_+0 
	MOVLW       hi_addr(?lstr2_CANPIC+0)
	MOVWF       FARG_CANWrite_data_+1 
	MOVLW       1
	MOVWF       FARG_CANWrite_DataLen+0 
	MOVF        _Can_Send_Flags+0, 0 
	MOVWF       FARG_CANWrite_CAN_TX_MSG_FLAGS+0 
	CALL        _CANWrite+0, 0
;CANPIC.c,77 :: 		if(ucTrame == COMPLETE)
	MOVF        _ucTrame+0, 0 
	XORLW       0
	BTFSS       STATUS+0, 2 
	GOTO        L_main2
;CANPIC.c,79 :: 		cPoid[0] = ucTabRx232[11];
	MOVF        _ucTabRx232+11, 0 
	MOVWF       _cPoid+0 
;CANPIC.c,80 :: 		cPoid[1] = ucTabRx232[12];
	MOVF        _ucTabRx232+12, 0 
	MOVWF       _cPoid+1 
;CANPIC.c,81 :: 		cPoid[2] = ucTabRx232[13];
	MOVF        _ucTabRx232+13, 0 
	MOVWF       _cPoid+2 
;CANPIC.c,82 :: 		cPoid[3] = ucTabRx232[14];
	MOVF        _ucTabRx232+14, 0 
	MOVWF       _cPoid+3 
;CANPIC.c,83 :: 		cPoid[4] = ucTabRx232[15];
	MOVF        _ucTabRx232+15, 0 
	MOVWF       _cPoid+4 
;CANPIC.c,84 :: 		ucIndiceTampon = 0;
	CLRF        _ucIndiceTampon+0 
;CANPIC.c,85 :: 		ucNbCaract = 0;
	CLRF        _ucNbCaract+0 
;CANPIC.c,86 :: 		ucTrame = INCOMPLETE;            //Trame incomplete
	MOVLW       1
	MOVWF       _ucTrame+0 
;CANPIC.c,88 :: 		CANWrite(ID_3rd, cPoid, 5, Can_Send_Flags); // send incremented data back
	MOVLW       5
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
;CANPIC.c,90 :: 		cTemps[0] = 0x36;
	MOVLW       54
	MOVWF       _cTemps+0 
;CANPIC.c,91 :: 		cTemps[1] = ucTABHMS[0];
	MOVF        _ucTABHMS+0, 0 
	MOVWF       _cTemps+1 
;CANPIC.c,92 :: 		cTemps[2] = ucTABHMS[1];
	MOVF        _ucTABHMS+1, 0 
	MOVWF       _cTemps+2 
;CANPIC.c,93 :: 		cTemps[3] = ucTABHMS[2];
	MOVF        _ucTABHMS+2, 0 
	MOVWF       _cTemps+3 
;CANPIC.c,94 :: 		cTemps[4] = 0x20;
	MOVLW       32
	MOVWF       _cTemps+4 
;CANPIC.c,95 :: 		CANWrite(ID_2nd, cTemps, 5, Can_Send_Flags);
	MOVLW       4
	MOVWF       FARG_CANWrite_id+0 
	MOVLW       0
	MOVWF       FARG_CANWrite_id+1 
	MOVLW       0
	MOVWF       FARG_CANWrite_id+2 
	MOVLW       0
	MOVWF       FARG_CANWrite_id+3 
	MOVLW       _cTemps+0
	MOVWF       FARG_CANWrite_data_+0 
	MOVLW       hi_addr(_cTemps+0)
	MOVWF       FARG_CANWrite_data_+1 
	MOVLW       5
	MOVWF       FARG_CANWrite_DataLen+0 
	MOVF        _Can_Send_Flags+0, 0 
	MOVWF       FARG_CANWrite_CAN_TX_MSG_FLAGS+0 
	CALL        _CANWrite+0, 0
;CANPIC.c,96 :: 		}
L_main2:
;CANPIC.c,120 :: 		}
	GOTO        L_main0
;CANPIC.c,121 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
