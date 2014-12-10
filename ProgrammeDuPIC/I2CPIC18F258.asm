
_vInitI2CMaster:

;I2CPIC18F258.c,40 :: 		void vInitI2CMaster (void)
;I2CPIC18F258.c,42 :: 		TRISC4_bit  = 1;           // SDA IN
	BSF         TRISC4_bit+0, BitPos(TRISC4_bit+0) 
;I2CPIC18F258.c,43 :: 		TRISC3_bit  = 0;           // SCL OUT
	BCF         TRISC3_bit+0, BitPos(TRISC3_bit+0) 
;I2CPIC18F258.c,44 :: 		SSPSTAT.SMP = 1;           // No slew rate
	BSF         SSPSTAT+0, 7 
;I2CPIC18F258.c,45 :: 		SSPSTAT.CKE = 0;           // Disable SMBus inputs
	BCF         SSPSTAT+0, 6 
;I2CPIC18F258.c,46 :: 		SSPADD      = 0x09;        // 100 KHz
	MOVLW       9
	MOVWF       SSPADD+0 
;I2CPIC18F258.c,47 :: 		SSPCON1     = 0b00101000;  // I2C Master mode
	MOVLW       40
	MOVWF       SSPCON1+0 
;I2CPIC18F258.c,48 :: 		SSPCON2     = 0b00000000;  // Reset ALL
	CLRF        SSPCON2+0 
;I2CPIC18F258.c,50 :: 		}
L_end_vInitI2CMaster:
	RETURN      0
; end of _vInitI2CMaster

_vInitI2CSlave:

;I2CPIC18F258.c,66 :: 		void vInitI2CSlave (void)
;I2CPIC18F258.c,68 :: 		TRISB4_bit  = 1;          // SDA IN
	BSF         TRISB4_bit+0, BitPos(TRISB4_bit+0) 
;I2CPIC18F258.c,69 :: 		TRISB6_bit  = 1;          // SCL IN
	BSF         TRISB6_bit+0, BitPos(TRISB6_bit+0) 
;I2CPIC18F258.c,70 :: 		SSPSTAT.SMP = 1;          // No slew rate
	BSF         SSPSTAT+0, 7 
;I2CPIC18F258.c,71 :: 		SSPSTAT.CKE = 0;          // Disable SMBus inputs
	BCF         SSPSTAT+0, 6 
;I2CPIC18F258.c,72 :: 		SSPADD      = 0b00110000; // Adresse SLAVE 0x30
	MOVLW       48
	MOVWF       SSPADD+0 
;I2CPIC18F258.c,73 :: 		SSPCON1     = 0b00110110; // slave I2C start
	MOVLW       54
	MOVWF       SSPCON1+0 
;I2CPIC18F258.c,75 :: 		}
L_end_vInitI2CSlave:
	RETURN      0
; end of _vInitI2CSlave

_vI2CCheck:

;I2CPIC18F258.c,91 :: 		void vI2CCheck (void)
;I2CPIC18F258.c,93 :: 		while (SSPCON2.ACKEN)  ;  // ACKEN not cleared, wait
L_vI2CCheck0:
	BTFSS       SSPCON2+0, 4 
	GOTO        L_vI2CCheck1
	GOTO        L_vI2CCheck0
L_vI2CCheck1:
;I2CPIC18F258.c,94 :: 		while (SSPCON2.RCEN)   ;  // RCEN not cleared, wait
L_vI2CCheck2:
	BTFSS       SSPCON2+0, 3 
	GOTO        L_vI2CCheck3
	GOTO        L_vI2CCheck2
L_vI2CCheck3:
;I2CPIC18F258.c,95 :: 		while (SSPCON2.PEN)    ;  // STOP not cleared, wait
L_vI2CCheck4:
	BTFSS       SSPCON2+0, 2 
	GOTO        L_vI2CCheck5
	GOTO        L_vI2CCheck4
L_vI2CCheck5:
;I2CPIC18F258.c,96 :: 		while (SSPCON2.SEN)    ;  // Start not cleared, wait
L_vI2CCheck6:
	BTFSS       SSPCON2+0, 0 
	GOTO        L_vI2CCheck7
	GOTO        L_vI2CCheck6
L_vI2CCheck7:
;I2CPIC18F258.c,97 :: 		while (SSPCON2.RSEN)   ;  // Rep start not cleared, wait
L_vI2CCheck8:
	BTFSS       SSPCON2+0, 1 
	GOTO        L_vI2CCheck9
	GOTO        L_vI2CCheck8
L_vI2CCheck9:
;I2CPIC18F258.c,98 :: 		while (SSPSTAT.R_NOT_W);  // TX not done wait
L_vI2CCheck10:
	BTFSS       SSPSTAT+0, 2 
	GOTO        L_vI2CCheck11
	GOTO        L_vI2CCheck10
L_vI2CCheck11:
;I2CPIC18F258.c,99 :: 		}
L_end_vI2CCheck:
	RETURN      0
; end of _vI2CCheck

_vI2CStart:

;I2CPIC18F258.c,115 :: 		void vI2CStart (void)
;I2CPIC18F258.c,117 :: 		vI2CCheck();          //Check bus is clear
	CALL        _vI2CCheck+0, 0
;I2CPIC18F258.c,118 :: 		SSPCON2.SEN = 1;      //Start condition
	BSF         SSPCON2+0, 0 
;I2CPIC18F258.c,119 :: 		}
L_end_vI2CStart:
	RETURN      0
; end of _vI2CStart

_vI2CStop:

;I2CPIC18F258.c,135 :: 		void vI2CStop (void)
;I2CPIC18F258.c,137 :: 		vI2CCheck();          //Check bus is clear
	CALL        _vI2CCheck+0, 0
;I2CPIC18F258.c,138 :: 		SSPCON2.PEN = 1;      //Stop condition
	BSF         SSPCON2+0, 2 
;I2CPIC18F258.c,139 :: 		}
L_end_vI2CStop:
	RETURN      0
; end of _vI2CStop

_vI2CReStart:

;I2CPIC18F258.c,155 :: 		void vI2CReStart (void)
;I2CPIC18F258.c,157 :: 		vI2CCheck();          //Check bus is clear
	CALL        _vI2CCheck+0, 0
;I2CPIC18F258.c,158 :: 		SSPCON2.RSEN = 1;     //Repeated start condition
	BSF         SSPCON2+0, 1 
;I2CPIC18F258.c,159 :: 		}
L_end_vI2CReStart:
	RETURN      0
; end of _vI2CReStart

_ucReadACK:

;I2CPIC18F258.c,175 :: 		UC ucReadACK (void)
;I2CPIC18F258.c,177 :: 		return(SSPCON2.ACKSTAT); //Return ACK value sent by slave device
	MOVLW       0
	BTFSC       SSPCON2+0, 6 
	MOVLW       1
	MOVWF       R0 
;I2CPIC18F258.c,178 :: 		}
L_end_ucReadACK:
	RETURN      0
; end of _ucReadACK

_vSendACK:

;I2CPIC18F258.c,194 :: 		void vSendACK (UC ucAck)
;I2CPIC18F258.c,196 :: 		vI2CCheck();             //Check I2C bus IDLE
	CALL        _vI2CCheck+0, 0
;I2CPIC18F258.c,197 :: 		SSPCON2.ACKDT = ucAck;   //ACK value into ACKDT (ACK data)
	BTFSC       FARG_vSendACK_ucAck+0, 0 
	GOTO        L__vSendACK33
	BCF         SSPCON2+0, 5 
	GOTO        L__vSendACK34
L__vSendACK33:
	BSF         SSPCON2+0, 5 
L__vSendACK34:
;I2CPIC18F258.c,198 :: 		SSPCON2.ACKEN = 1;       //Start ACK/NACK write sequence
	BSF         SSPCON2+0, 4 
;I2CPIC18F258.c,199 :: 		}
L_end_vSendACK:
	RETURN      0
; end of _vSendACK

_vI2CEcrireOctet:

;I2CPIC18F258.c,216 :: 		void vI2CEcrireOctet (UC ucData, UC ucRW)
;I2CPIC18F258.c,218 :: 		vI2CCheck();                //Check I2C bus IDLE
	CALL        _vI2CCheck+0, 0
;I2CPIC18F258.c,219 :: 		switch (ucRW)               //Switch, READ or WRITE?
	GOTO        L_vI2CEcrireOctet12
;I2CPIC18F258.c,221 :: 		case READ:               //Case read
L_vI2CEcrireOctet14:
;I2CPIC18F258.c,222 :: 		SSPBUF = ucData + 1;   //Add 1 to Adress, data into I2C buffer
	MOVF        FARG_vI2CEcrireOctet_ucData+0, 0 
	ADDLW       1
	MOVWF       SSPBUF+0 
;I2CPIC18F258.c,223 :: 		break;
	GOTO        L_vI2CEcrireOctet13
;I2CPIC18F258.c,225 :: 		case WRITE:              //Case Write
L_vI2CEcrireOctet15:
;I2CPIC18F258.c,226 :: 		SSPBUF = ucData + 0;   //Data into I2C buffer
	MOVF        FARG_vI2CEcrireOctet_ucData+0, 0 
	MOVWF       SSPBUF+0 
;I2CPIC18F258.c,227 :: 		break;
	GOTO        L_vI2CEcrireOctet13
;I2CPIC18F258.c,228 :: 		}
L_vI2CEcrireOctet12:
	MOVF        FARG_vI2CEcrireOctet_ucRW+0, 0 
	XORLW       0
	BTFSC       STATUS+0, 2 
	GOTO        L_vI2CEcrireOctet14
	MOVF        FARG_vI2CEcrireOctet_ucRW+0, 0 
	XORLW       1
	BTFSC       STATUS+0, 2 
	GOTO        L_vI2CEcrireOctet15
L_vI2CEcrireOctet13:
;I2CPIC18F258.c,229 :: 		while (SSPSTAT.BF  != 0);   //Wait for buffer to be empty
L_vI2CEcrireOctet16:
	BTFSS       SSPSTAT+0, 0 
	GOTO        L_vI2CEcrireOctet17
	GOTO        L_vI2CEcrireOctet16
L_vI2CEcrireOctet17:
;I2CPIC18F258.c,230 :: 		while (ucReadACK() != 0);   //Wait for slave ACK
L_vI2CEcrireOctet18:
	CALL        _ucReadACK+0, 0
	MOVF        R0, 0 
	XORLW       0
	BTFSC       STATUS+0, 2 
	GOTO        L_vI2CEcrireOctet19
	GOTO        L_vI2CEcrireOctet18
L_vI2CEcrireOctet19:
;I2CPIC18F258.c,231 :: 		}
L_end_vI2CEcrireOctet:
	RETURN      0
; end of _vI2CEcrireOctet

_ucI2CLireOctet:

;I2CPIC18F258.c,246 :: 		UC ucI2CLireOctet (UC ucAck)
;I2CPIC18F258.c,248 :: 		vI2CCheck();                   //Check I2C bus Idle
	CALL        _vI2CCheck+0, 0
;I2CPIC18F258.c,249 :: 		SSPCON2.RCEN = 1;              //Enable receiver
	BSF         SSPCON2+0, 3 
;I2CPIC18F258.c,250 :: 		while    (SSPCON2.RCEN != 0);  //Creates I2C Read sequence
L_ucI2CLireOctet20:
	BTFSS       SSPCON2+0, 3 
	GOTO        L_ucI2CLireOctet21
	GOTO        L_ucI2CLireOctet20
L_ucI2CLireOctet21:
;I2CPIC18F258.c,251 :: 		vSendACK (ucAck);              //Send the ack/Nack value
	MOVF        FARG_ucI2CLireOctet_ucAck+0, 0 
	MOVWF       FARG_vSendACK_ucAck+0 
	CALL        _vSendACK+0, 0
;I2CPIC18F258.c,252 :: 		return   (SSPBUF);             //return I2C buffer data
	MOVF        SSPBUF+0, 0 
	MOVWF       R0 
;I2CPIC18F258.c,253 :: 		}
L_end_ucI2CLireOctet:
	RETURN      0
; end of _ucI2CLireOctet

_vI2CEcrireEEPROM:

;I2CPIC18F258.c,271 :: 		void vI2CEcrireEEPROM (UC ucData, UI uiAdr, UC ucAdrChip)
;I2CPIC18F258.c,274 :: 		ucAdrH = ((uiAdr & 0xFF00) >> 8);  // Isolates adr high nibbles
	MOVLW       0
	ANDWF       FARG_vI2CEcrireEEPROM_uiAdr+0, 0 
	MOVWF       R3 
	MOVF        FARG_vI2CEcrireEEPROM_uiAdr+1, 0 
	ANDLW       255
	MOVWF       R4 
	MOVF        R4, 0 
	MOVWF       R0 
	CLRF        R1 
	MOVF        R0, 0 
	MOVWF       vI2CEcrireEEPROM_ucAdrH_L0+0 
;I2CPIC18F258.c,275 :: 		ucAdrL = (uiAdr & 0x00FF);         // Isolates adr low nibbles
	MOVLW       255
	ANDWF       FARG_vI2CEcrireEEPROM_uiAdr+0, 0 
	MOVWF       vI2CEcrireEEPROM_ucAdrL_L0+0 
;I2CPIC18F258.c,277 :: 		vI2CStart();                       // Start I2C bus
	CALL        _vI2CStart+0, 0
;I2CPIC18F258.c,278 :: 		vI2CEcrireOctet(ucAdrChip, WRITE); // Writes EEPROM physical adress on I2C
	MOVF        FARG_vI2CEcrireEEPROM_ucAdrChip+0, 0 
	MOVWF       FARG_vI2CEcrireOctet_ucData+0 
	MOVLW       1
	MOVWF       FARG_vI2CEcrireOctet_ucRW+0 
	CALL        _vI2CEcrireOctet+0, 0
;I2CPIC18F258.c,279 :: 		vI2CEcrireOctet(ucAdrH, WRITE);    // Write ADRH nibble
	MOVF        vI2CEcrireEEPROM_ucAdrH_L0+0, 0 
	MOVWF       FARG_vI2CEcrireOctet_ucData+0 
	MOVLW       1
	MOVWF       FARG_vI2CEcrireOctet_ucRW+0 
	CALL        _vI2CEcrireOctet+0, 0
;I2CPIC18F258.c,280 :: 		vI2CECrireOctet(ucAdrL, WRITE);    // Write ADRL nibble
	MOVF        vI2CEcrireEEPROM_ucAdrL_L0+0, 0 
	MOVWF       FARG_vI2CEcrireOctet_ucData+0 
	MOVLW       1
	MOVWF       FARG_vI2CEcrireOctet_ucRW+0 
	CALL        _vI2CEcrireOctet+0, 0
;I2CPIC18F258.c,281 :: 		vI2CEcrireOctet(ucData, WRITE);    // Write data to EEPROM
	MOVF        FARG_vI2CEcrireEEPROM_ucData+0, 0 
	MOVWF       FARG_vI2CEcrireOctet_ucData+0 
	MOVLW       1
	MOVWF       FARG_vI2CEcrireOctet_ucRW+0 
	CALL        _vI2CEcrireOctet+0, 0
;I2CPIC18F258.c,282 :: 		vI2CStop();                        // Stop I2C bus
	CALL        _vI2CStop+0, 0
;I2CPIC18F258.c,284 :: 		}
L_end_vI2CEcrireEEPROM:
	RETURN      0
; end of _vI2CEcrireEEPROM

_ucI2CLireEEPROM:

;I2CPIC18F258.c,301 :: 		UC ucI2CLireEEPROM (UI uiAdr, UC ucAdrChip)
;I2CPIC18F258.c,304 :: 		ucAdrH = ((uiAdr & 0xFF00) >> 8);    //Isolates adr high nibbles
	MOVLW       0
	ANDWF       FARG_ucI2CLireEEPROM_uiAdr+0, 0 
	MOVWF       R3 
	MOVF        FARG_ucI2CLireEEPROM_uiAdr+1, 0 
	ANDLW       255
	MOVWF       R4 
	MOVF        R4, 0 
	MOVWF       R0 
	CLRF        R1 
	MOVF        R0, 0 
	MOVWF       ucI2CLireEEPROM_ucAdrH_L0+0 
;I2CPIC18F258.c,305 :: 		ucAdrL = (uiAdr & 0x00FF);           //Isolates adr low nibbles
	MOVLW       255
	ANDWF       FARG_ucI2CLireEEPROM_uiAdr+0, 0 
	MOVWF       ucI2CLireEEPROM_ucAdrL_L0+0 
;I2CPIC18F258.c,307 :: 		vI2CStart();                         //Start I2C
	CALL        _vI2CStart+0, 0
;I2CPIC18F258.c,308 :: 		vI2CEcrireOctet(ucAdrChip, WRITE);   //Writes EEPROM physical adress on I2C
	MOVF        FARG_ucI2CLireEEPROM_ucAdrChip+0, 0 
	MOVWF       FARG_vI2CEcrireOctet_ucData+0 
	MOVLW       1
	MOVWF       FARG_vI2CEcrireOctet_ucRW+0 
	CALL        _vI2CEcrireOctet+0, 0
;I2CPIC18F258.c,309 :: 		vI2CEcrireOctet(ucAdrH,    WRITE);   //Write ADRH nibble
	MOVF        ucI2CLireEEPROM_ucAdrH_L0+0, 0 
	MOVWF       FARG_vI2CEcrireOctet_ucData+0 
	MOVLW       1
	MOVWF       FARG_vI2CEcrireOctet_ucRW+0 
	CALL        _vI2CEcrireOctet+0, 0
;I2CPIC18F258.c,310 :: 		vI2CEcrireOctet(ucAdrL,    WRITE);   //Write ADRL nibble
	MOVF        ucI2CLireEEPROM_ucAdrL_L0+0, 0 
	MOVWF       FARG_vI2CEcrireOctet_ucData+0 
	MOVLW       1
	MOVWF       FARG_vI2CEcrireOctet_ucRW+0 
	CALL        _vI2CEcrireOctet+0, 0
;I2CPIC18F258.c,311 :: 		vI2CReStart();                       //ReStart I2C
	CALL        _vI2CReStart+0, 0
;I2CPIC18F258.c,313 :: 		vI2CEcrireOctet(ucAdrChip, READ);    //Write EEPROM, Read operation follows
	MOVF        FARG_ucI2CLireEEPROM_ucAdrChip+0, 0 
	MOVWF       FARG_vI2CEcrireOctet_ucData+0 
	CLRF        FARG_vI2CEcrireOctet_ucRW+0 
	CALL        _vI2CEcrireOctet+0, 0
;I2CPIC18F258.c,314 :: 		ucDataReturn = ucI2CLireOctet(NACK); //Reads data from EEPROM
	MOVLW       1
	MOVWF       FARG_ucI2CLireOctet_ucAck+0 
	CALL        _ucI2CLireOctet+0, 0
	MOVF        R0, 0 
	MOVWF       ucI2CLireEEPROM_ucDataReturn_L0+0 
;I2CPIC18F258.c,315 :: 		vI2CStop();                          //Stop I2C
	CALL        _vI2CStop+0, 0
;I2CPIC18F258.c,317 :: 		return (ucDataReturn);               //Returns EEPROM data
	MOVF        ucI2CLireEEPROM_ucDataReturn_L0+0, 0 
	MOVWF       R0 
;I2CPIC18F258.c,318 :: 		}
L_end_ucI2CLireEEPROM:
	RETURN      0
; end of _ucI2CLireEEPROM

_vI2CEcrirePCF8574:

;I2CPIC18F258.c,335 :: 		void vI2CEcrirePCF8574 (UC ucAdr, UC ucData)
;I2CPIC18F258.c,337 :: 		vI2CStart();                    // Start I2C comm
	CALL        _vI2CStart+0, 0
;I2CPIC18F258.c,338 :: 		vI2CEcrireOctet(ucAdr,  WRITE); // Write adress to I2C bus
	MOVF        FARG_vI2CEcrirePCF8574_ucAdr+0, 0 
	MOVWF       FARG_vI2CEcrireOctet_ucData+0 
	MOVLW       1
	MOVWF       FARG_vI2CEcrireOctet_ucRW+0 
	CALL        _vI2CEcrireOctet+0, 0
;I2CPIC18F258.c,339 :: 		vI2CEcrireOctet(ucData, WRITE); // Write data to adress on I2C
	MOVF        FARG_vI2CEcrirePCF8574_ucData+0, 0 
	MOVWF       FARG_vI2CEcrireOctet_ucData+0 
	MOVLW       1
	MOVWF       FARG_vI2CEcrireOctet_ucRW+0 
	CALL        _vI2CEcrireOctet+0, 0
;I2CPIC18F258.c,340 :: 		vI2CStop();                     // Stops the com
	CALL        _vI2CStop+0, 0
;I2CPIC18F258.c,341 :: 		}
L_end_vI2CEcrirePCF8574:
	RETURN      0
; end of _vI2CEcrirePCF8574

_ucI2CLirePCF8574:

;I2CPIC18F258.c,357 :: 		UC ucI2CLirePCF8574 (UC ucAdr)
;I2CPIC18F258.c,360 :: 		vI2CStart();                          //Start I2C bus
	CALL        _vI2CStart+0, 0
;I2CPIC18F258.c,361 :: 		vI2CEcrireOctet(ucAdr, READ);         //Init read procedure
	MOVF        FARG_ucI2CLirePCF8574_ucAdr+0, 0 
	MOVWF       FARG_vI2CEcrireOctet_ucData+0 
	CLRF        FARG_vI2CEcrireOctet_ucRW+0 
	CALL        _vI2CEcrireOctet+0, 0
;I2CPIC18F258.c,362 :: 		ucDataReturn = ucI2CLireOctet(NACK);  //Read value to variable
	MOVLW       1
	MOVWF       FARG_ucI2CLireOctet_ucAck+0 
	CALL        _ucI2CLireOctet+0, 0
	MOVF        R0, 0 
	MOVWF       ucI2CLirePCF8574_ucDataReturn_L0+0 
;I2CPIC18F258.c,363 :: 		vI2CStop();                           //Stop I2C
	CALL        _vI2CStop+0, 0
;I2CPIC18F258.c,364 :: 		return (ucDataReturn);                //Return read value
	MOVF        ucI2CLirePCF8574_ucDataReturn_L0+0, 0 
	MOVWF       R0 
;I2CPIC18F258.c,365 :: 		}
L_end_ucI2CLirePCF8574:
	RETURN      0
; end of _ucI2CLirePCF8574

_vI2CEcrireDS1307:

;I2CPIC18F258.c,367 :: 		void vI2CEcrireDS1307 (UC ucADR, UC ucH, UC ucM, UC ucS)
;I2CPIC18F258.c,369 :: 		vI2CStart();
	CALL        _vI2CStart+0, 0
;I2CPIC18F258.c,370 :: 		vI2CEcrireOctet(ucADR, WRITE);
	MOVF        FARG_vI2CEcrireDS1307_ucADR+0, 0 
	MOVWF       FARG_vI2CEcrireOctet_ucData+0 
	MOVLW       1
	MOVWF       FARG_vI2CEcrireOctet_ucRW+0 
	CALL        _vI2CEcrireOctet+0, 0
;I2CPIC18F258.c,371 :: 		vI2CEcrireOctet(HEURE, WRITE);
	MOVLW       2
	MOVWF       FARG_vI2CEcrireOctet_ucData+0 
	MOVLW       1
	MOVWF       FARG_vI2CEcrireOctet_ucRW+0 
	CALL        _vI2CEcrireOctet+0, 0
;I2CPIC18F258.c,372 :: 		vI2CEcrireOctet(ucH,   WRITE);
	MOVF        FARG_vI2CEcrireDS1307_ucH+0, 0 
	MOVWF       FARG_vI2CEcrireOctet_ucData+0 
	MOVLW       1
	MOVWF       FARG_vI2CEcrireOctet_ucRW+0 
	CALL        _vI2CEcrireOctet+0, 0
;I2CPIC18F258.c,373 :: 		vI2CStop ();
	CALL        _vI2CStop+0, 0
;I2CPIC18F258.c,375 :: 		vI2CStart();
	CALL        _vI2CStart+0, 0
;I2CPIC18F258.c,376 :: 		vI2CEcrireOctet(ucADR,  WRITE);
	MOVF        FARG_vI2CEcrireDS1307_ucADR+0, 0 
	MOVWF       FARG_vI2CEcrireOctet_ucData+0 
	MOVLW       1
	MOVWF       FARG_vI2CEcrireOctet_ucRW+0 
	CALL        _vI2CEcrireOctet+0, 0
;I2CPIC18F258.c,377 :: 		vI2CEcrireOctet(MINUTE, WRITE);
	MOVLW       1
	MOVWF       FARG_vI2CEcrireOctet_ucData+0 
	MOVLW       1
	MOVWF       FARG_vI2CEcrireOctet_ucRW+0 
	CALL        _vI2CEcrireOctet+0, 0
;I2CPIC18F258.c,378 :: 		vI2CEcrireOctet(ucM,    WRITE);
	MOVF        FARG_vI2CEcrireDS1307_ucM+0, 0 
	MOVWF       FARG_vI2CEcrireOctet_ucData+0 
	MOVLW       1
	MOVWF       FARG_vI2CEcrireOctet_ucRW+0 
	CALL        _vI2CEcrireOctet+0, 0
;I2CPIC18F258.c,379 :: 		vI2CStop ();
	CALL        _vI2CStop+0, 0
;I2CPIC18F258.c,381 :: 		vI2CStart();
	CALL        _vI2CStart+0, 0
;I2CPIC18F258.c,382 :: 		vI2CEcrireOctet(ucADR,   WRITE);
	MOVF        FARG_vI2CEcrireDS1307_ucADR+0, 0 
	MOVWF       FARG_vI2CEcrireOctet_ucData+0 
	MOVLW       1
	MOVWF       FARG_vI2CEcrireOctet_ucRW+0 
	CALL        _vI2CEcrireOctet+0, 0
;I2CPIC18F258.c,383 :: 		vI2CEcrireOctet(SECONDE, WRITE);
	CLRF        FARG_vI2CEcrireOctet_ucData+0 
	MOVLW       1
	MOVWF       FARG_vI2CEcrireOctet_ucRW+0 
	CALL        _vI2CEcrireOctet+0, 0
;I2CPIC18F258.c,384 :: 		vI2CEcrireOctet(ucS,     WRITE);
	MOVF        FARG_vI2CEcrireDS1307_ucS+0, 0 
	MOVWF       FARG_vI2CEcrireOctet_ucData+0 
	MOVLW       1
	MOVWF       FARG_vI2CEcrireOctet_ucRW+0 
	CALL        _vI2CEcrireOctet+0, 0
;I2CPIC18F258.c,385 :: 		vI2CStop ();
	CALL        _vI2CStop+0, 0
;I2CPIC18F258.c,386 :: 		}
L_end_vI2CEcrireDS1307:
	RETURN      0
; end of _vI2CEcrireDS1307

_vI2CLireDS1307:

;I2CPIC18F258.c,388 :: 		void vI2CLireDS1307 (UC ucADR)
;I2CPIC18F258.c,392 :: 		vI2CStart();
	CALL        _vI2CStart+0, 0
;I2CPIC18F258.c,393 :: 		vI2CEcrireOctet(ucADR, WRITE); // Envoie l'adresse du DS1307
	MOVF        FARG_vI2CLireDS1307_ucADR+0, 0 
	MOVWF       FARG_vI2CEcrireOctet_ucData+0 
	MOVLW       1
	MOVWF       FARG_vI2CEcrireOctet_ucRW+0 
	CALL        _vI2CEcrireOctet+0, 0
;I2CPIC18F258.c,394 :: 		vI2CEcrireOctet(HEURE, WRITE); // Envoie le registre des heures
	MOVLW       2
	MOVWF       FARG_vI2CEcrireOctet_ucData+0 
	MOVLW       1
	MOVWF       FARG_vI2CEcrireOctet_ucRW+0 
	CALL        _vI2CEcrireOctet+0, 0
;I2CPIC18F258.c,395 :: 		vI2CReStart();
	CALL        _vI2CReStart+0, 0
;I2CPIC18F258.c,396 :: 		vI2CEcrireOctet(ucADR, READ);  // Prépare une lecture des heures
	MOVF        FARG_vI2CLireDS1307_ucADR+0, 0 
	MOVWF       FARG_vI2CEcrireOctet_ucData+0 
	CLRF        FARG_vI2CEcrireOctet_ucRW+0 
	CALL        _vI2CEcrireOctet+0, 0
;I2CPIC18F258.c,397 :: 		ucTABHMS[0] = ucI2CLireOctet(NACK); // Lit les heures
	MOVLW       1
	MOVWF       FARG_ucI2CLireOctet_ucAck+0 
	CALL        _ucI2CLireOctet+0, 0
	MOVF        R0, 0 
	MOVWF       _ucTABHMS+0 
;I2CPIC18F258.c,398 :: 		vI2CStop();
	CALL        _vI2CStop+0, 0
;I2CPIC18F258.c,400 :: 		vI2CStart();
	CALL        _vI2CStart+0, 0
;I2CPIC18F258.c,401 :: 		vI2CEcrireOctet(ucADR,  WRITE);  // Envoie l'adresse du DS1307
	MOVF        FARG_vI2CLireDS1307_ucADR+0, 0 
	MOVWF       FARG_vI2CEcrireOctet_ucData+0 
	MOVLW       1
	MOVWF       FARG_vI2CEcrireOctet_ucRW+0 
	CALL        _vI2CEcrireOctet+0, 0
;I2CPIC18F258.c,402 :: 		vI2CEcrireOctet(MINUTE, WRITE);  // Envoie le registre des secondes
	MOVLW       1
	MOVWF       FARG_vI2CEcrireOctet_ucData+0 
	MOVLW       1
	MOVWF       FARG_vI2CEcrireOctet_ucRW+0 
	CALL        _vI2CEcrireOctet+0, 0
;I2CPIC18F258.c,403 :: 		vI2CReStart();
	CALL        _vI2CReStart+0, 0
;I2CPIC18F258.c,404 :: 		vI2CEcrireOctet(ucADR, READ);   // Prépare une lecture des minutes
	MOVF        FARG_vI2CLireDS1307_ucADR+0, 0 
	MOVWF       FARG_vI2CEcrireOctet_ucData+0 
	CLRF        FARG_vI2CEcrireOctet_ucRW+0 
	CALL        _vI2CEcrireOctet+0, 0
;I2CPIC18F258.c,405 :: 		ucTABHMS[1] = ucI2CLireOctet(NACK); // Lit les minutes
	MOVLW       1
	MOVWF       FARG_ucI2CLireOctet_ucAck+0 
	CALL        _ucI2CLireOctet+0, 0
	MOVF        R0, 0 
	MOVWF       _ucTABHMS+1 
;I2CPIC18F258.c,406 :: 		vI2CStop();
	CALL        _vI2CStop+0, 0
;I2CPIC18F258.c,408 :: 		vI2CStart();
	CALL        _vI2CStart+0, 0
;I2CPIC18F258.c,409 :: 		vI2CEcrireOctet(ucADR,   WRITE);  // Envoie l'adresse du DS1307
	MOVF        FARG_vI2CLireDS1307_ucADR+0, 0 
	MOVWF       FARG_vI2CEcrireOctet_ucData+0 
	MOVLW       1
	MOVWF       FARG_vI2CEcrireOctet_ucRW+0 
	CALL        _vI2CEcrireOctet+0, 0
;I2CPIC18F258.c,410 :: 		vI2CEcrireOctet(SECONDE, WRITE);  // Envoie le registre des minutes
	CLRF        FARG_vI2CEcrireOctet_ucData+0 
	MOVLW       1
	MOVWF       FARG_vI2CEcrireOctet_ucRW+0 
	CALL        _vI2CEcrireOctet+0, 0
;I2CPIC18F258.c,411 :: 		vI2CReStart();
	CALL        _vI2CReStart+0, 0
;I2CPIC18F258.c,412 :: 		vI2CEcrireOctet(ucADR, READ);     // Prépare une lecture des secondes
	MOVF        FARG_vI2CLireDS1307_ucADR+0, 0 
	MOVWF       FARG_vI2CEcrireOctet_ucData+0 
	CLRF        FARG_vI2CEcrireOctet_ucRW+0 
	CALL        _vI2CEcrireOctet+0, 0
;I2CPIC18F258.c,413 :: 		ucTABHMS[2] = ucI2CLireOctet(NACK); // Lit les secondes
	MOVLW       1
	MOVWF       FARG_ucI2CLireOctet_ucAck+0 
	CALL        _ucI2CLireOctet+0, 0
	MOVF        R0, 0 
	MOVWF       _ucTABHMS+2 
;I2CPIC18F258.c,414 :: 		vI2CStop();
	CALL        _vI2CStop+0, 0
;I2CPIC18F258.c,415 :: 		}
L_end_vI2CLireDS1307:
	RETURN      0
; end of _vI2CLireDS1307

_vDelaiI2C:

;I2CPIC18F258.c,431 :: 		void vDelaiI2C (UI uiDelai)
;I2CPIC18F258.c,433 :: 		for (; uiDelai>0; uiDelai--);  //Wait for it
L_vDelaiI2C22:
	MOVLW       0
	MOVWF       R0 
	MOVF        FARG_vDelaiI2C_uiDelai+1, 0 
	SUBWF       R0, 0 
	BTFSS       STATUS+0, 2 
	GOTO        L__vDelaiI2C44
	MOVF        FARG_vDelaiI2C_uiDelai+0, 0 
	SUBLW       0
L__vDelaiI2C44:
	BTFSC       STATUS+0, 0 
	GOTO        L_vDelaiI2C23
	MOVLW       1
	SUBWF       FARG_vDelaiI2C_uiDelai+0, 1 
	MOVLW       0
	SUBWFB      FARG_vDelaiI2C_uiDelai+1, 1 
	GOTO        L_vDelaiI2C22
L_vDelaiI2C23:
;I2CPIC18F258.c,434 :: 		}
L_end_vDelaiI2C:
	RETURN      0
; end of _vDelaiI2C
