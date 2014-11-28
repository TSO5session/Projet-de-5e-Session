
_vInitPic:

;PIC18F258.c,35 :: 		void vInitPic (void)
;PIC18F258.c,37 :: 		INTCON = 0xC0;      //ENABLE GLOBAL INTERRUPT, ENABLE PERIPHERAL INTERRUPT
	MOVLW       192
	MOVWF       INTCON+0 
;PIC18F258.c,38 :: 		OSCCON = 0b00000000;//4MHZINTRC
	CLRF        OSCCON+0 
;PIC18F258.c,39 :: 		ADCON0.ADON = 0;    //DEACTIVATE analog PIC18F258
	BCF         ADCON0+0, 0 
;PIC18F258.c,40 :: 		TRISC = 0b10000000; //RX IN, TX OUT
	MOVLW       128
	MOVWF       TRISC+0 
;PIC18F258.c,41 :: 		TRISB = 0b00001000; //CAN TX/RX set up
	MOVLW       8
	MOVWF       TRISB+0 
;PIC18F258.c,42 :: 		}
L_end_vInitPic:
	RETURN      0
; end of _vInitPic

_vInitRS232:

;PIC18F258.c,59 :: 		void vInitRS232 (void)
;PIC18F258.c,61 :: 		PIE1 = 0x20;          //Receive enable
	MOVLW       32
	MOVWF       PIE1+0 
;PIC18F258.c,62 :: 		SPBRG = 0x19;         //9600BDs
	MOVLW       25
	MOVWF       SPBRG+0 
;PIC18F258.c,63 :: 		RCSTA = 0x90;         //Set le registre de reception serie
	MOVLW       144
	MOVWF       RCSTA+0 
;PIC18F258.c,64 :: 		TXSTA = 0x24;         //Set le registre de transmission serie, BRGH 1 HSPEED
	MOVLW       36
	MOVWF       TXSTA+0 
;PIC18F258.c,65 :: 		}
L_end_vInitRS232:
	RETURN      0
; end of _vInitRS232

_vTx232:

;PIC18F258.c,82 :: 		void vTx232 (UC ucSend)
;PIC18F258.c,84 :: 		while (PIR1.TXIF == 0);//Tant que dernier envoie pas terminé fait rien
L_vTx2320:
	BTFSC       PIR1+0, 4 
	GOTO        L_vTx2321
	GOTO        L_vTx2320
L_vTx2321:
;PIC18F258.c,85 :: 		TXREG = ucSend;        //Valeur entree dans TXREG, envoi serie
	MOVF        FARG_vTx232_ucSend+0, 0 
	MOVWF       TXREG+0 
;PIC18F258.c,86 :: 		}
L_end_vTx232:
	RETURN      0
; end of _vTx232

_vTransChaine:

;PIC18F258.c,102 :: 		void vTransChaine (UC *ucpChaine)
;PIC18F258.c,104 :: 		while (*ucpChaine != 0x00)   //Tant qu'on n'atteint pas la fin de la chaine
L_vTransChaine2:
	MOVFF       FARG_vTransChaine_ucpChaine+0, FSR0
	MOVFF       FARG_vTransChaine_ucpChaine+1, FSR0H
	MOVF        POSTINC0+0, 0 
	XORLW       0
	BTFSC       STATUS+0, 2 
	GOTO        L_vTransChaine3
;PIC18F258.c,106 :: 		vTx232(*ucpChaine);       //Affiche caractere de la chaine
	MOVFF       FARG_vTransChaine_ucpChaine+0, FSR0
	MOVFF       FARG_vTransChaine_ucpChaine+1, FSR0H
	MOVF        POSTINC0+0, 0 
	MOVWF       FARG_vTx232_ucSend+0 
	CALL        _vTx232+0, 0
;PIC18F258.c,107 :: 		ucpChaine++;              //Incremente position pour aff tout les carac
	INFSNZ      FARG_vTransChaine_ucpChaine+0, 1 
	INCF        FARG_vTransChaine_ucpChaine+1, 1 
;PIC18F258.c,108 :: 		}
	GOTO        L_vTransChaine2
L_vTransChaine3:
;PIC18F258.c,109 :: 		}
L_end_vTransChaine:
	RETURN      0
; end of _vTransChaine

_interrupt:

;PIC18F258.c,130 :: 		void interrupt (void)
;PIC18F258.c,132 :: 		INTCON.GIE = 0;   //Disable all interrupts
	BCF         INTCON+0, 7 
;PIC18F258.c,134 :: 		if (PIR1.RCIF)    //Receive serial flag up?
	BTFSS       PIR1+0, 5 
	GOTO        L_interrupt4
;PIC18F258.c,136 :: 		if (ucIndiceTampon >= INDICETAMPON){ucIndiceTampon = 0;}
	MOVLW       26
	SUBWF       _ucIndiceTampon+0, 0 
	BTFSS       STATUS+0, 0 
	GOTO        L_interrupt5
	CLRF        _ucIndiceTampon+0 
L_interrupt5:
;PIC18F258.c,138 :: 		ucTabRx232[ucIndiceTampon] = RCREG; //Val recue dans le tab de reception
	MOVLW       _ucTabRx232+0
	MOVWF       FSR1 
	MOVLW       hi_addr(_ucTabRx232+0)
	MOVWF       FSR1H 
	MOVF        _ucIndiceTampon+0, 0 
	ADDWF       FSR1, 1 
	BTFSC       STATUS+0, 0 
	INCF        FSR1H, 1 
	MOVF        RCREG+0, 0 
	MOVWF       POSTINC1+0 
;PIC18F258.c,139 :: 		ucIndiceTampon++;                   //increm indice reception
	MOVF        _ucIndiceTampon+0, 0 
	ADDLW       1
	MOVWF       R0 
	MOVF        R0, 0 
	MOVWF       _ucIndiceTampon+0 
;PIC18F258.c,140 :: 		if (ucNbCaract < LONGUEURTRAME - 1) //Si nb caractere < long trame?
	MOVLW       25
	SUBWF       _ucNbCaract+0, 0 
	BTFSC       STATUS+0, 0 
	GOTO        L_interrupt6
;PIC18F258.c,142 :: 		ucNbCaract++;                    //increm nb caract recu
	MOVF        _ucNbCaract+0, 0 
	ADDLW       1
	MOVWF       R0 
	MOVF        R0, 0 
	MOVWF       _ucNbCaract+0 
;PIC18F258.c,143 :: 		ucTrame = INCOMPLETE;            //Trame incomplete
	MOVLW       1
	MOVWF       _ucTrame+0 
;PIC18F258.c,144 :: 		}
	GOTO        L_interrupt7
L_interrupt6:
;PIC18F258.c,147 :: 		ucIndiceTampon = 0;              //INdice tampon a 0
	CLRF        _ucIndiceTampon+0 
;PIC18F258.c,148 :: 		ucNbCaract = 0;                  //nb caract a 0
	CLRF        _ucNbCaract+0 
;PIC18F258.c,149 :: 		ucTrame = COMPLETE;              //wouhou! trame complete
	CLRF        _ucTrame+0 
;PIC18F258.c,150 :: 		}
L_interrupt7:
;PIC18F258.c,152 :: 		if(ucNbCaract > 13)
	MOVF        _ucNbCaract+0, 0 
	SUBLW       13
	BTFSC       STATUS+0, 0 
	GOTO        L_interrupt8
;PIC18F258.c,154 :: 		if(ucTabRx232[13] != '.')
	MOVF        _ucTabRx232+13, 0 
	XORLW       46
	BTFSC       STATUS+0, 2 
	GOTO        L_interrupt9
;PIC18F258.c,156 :: 		ucIndiceTampon = 0;
	CLRF        _ucIndiceTampon+0 
;PIC18F258.c,157 :: 		ucNbCaract = 0;
	CLRF        _ucNbCaract+0 
;PIC18F258.c,158 :: 		ucTrame = INCOMPLETE;
	MOVLW       1
	MOVWF       _ucTrame+0 
;PIC18F258.c,159 :: 		}
L_interrupt9:
;PIC18F258.c,160 :: 		}
L_interrupt8:
;PIC18F258.c,161 :: 		}
L_interrupt4:
;PIC18F258.c,162 :: 		INTCON.GIE = 1;               //Re-Active interruption generale
	BSF         INTCON+0, 7 
;PIC18F258.c,163 :: 		PIR1.RCIF = 0;                //Baisse flag pour permettre seconde interrupt
	BCF         PIR1+0, 5 
;PIC18F258.c,164 :: 		}
L_end_interrupt:
L__interrupt18:
	RETFIE      1
; end of _interrupt

_vDelai:

;PIC18F258.c,166 :: 		void vDelai (UC ucDelai)
;PIC18F258.c,168 :: 		for (; ucDelai>0; ucDelai--);
L_vDelai10:
	MOVF        FARG_vDelai_ucDelai+0, 0 
	SUBLW       0
	BTFSC       STATUS+0, 0 
	GOTO        L_vDelai11
	DECF        FARG_vDelai_ucDelai+0, 1 
	GOTO        L_vDelai10
L_vDelai11:
;PIC18F258.c,169 :: 		}
L_end_vDelai:
	RETURN      0
; end of _vDelai
