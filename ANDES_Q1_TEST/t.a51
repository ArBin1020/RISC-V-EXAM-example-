	ORG 0000H
    AJMP START
START:
    ORG 0030H ;避免蓋掉中斷的區域
    MOV TMOD, #00100000B ;設定timer1為工作模式2
    MOV TH1, #0FDH ;
    SETB TR1 
    MOV SCON, #01110000B
    MOV R1, #3
    AJMP LCD_INIT

MAIN:
    READ_DATA:
        JNB P2.0, READ_TEMPERATURE
        JNB P2.1, READ_HUMIDITY
        JNB P2.2, READ_PM25
	    ACALL WAIT
        AJMP READ_DATA

    READ:
        CLR RI
        JNB RI, $
        MOV A, SBUF
        RET

   LCD_SEND_DATA_VALUE:
        MOV P0, A
        SETB P1.6
        SETB P1.7
        MOV R2, #1
        ACALL DELAY
        CLR P1.7
        AJMP CALL_FUNC

    CALL_FUNC: 
        ACALL READ
        CJNE A, #23H, LCD_SEND_DATA_VALUE
        AJMP READ_DATA

    READ_TEMPERATURE:
        MOV R5, #0
        MOV DPTR, #TEMPERATURE
	    CJNE R1, #0, CLEAR
        AJMP SEND

    READ_HUMIDITY:
        MOV R5, #1
        MOV DPTR, #HUMIDITY
        CJNE R1, #1, CLEAR
        AJMP SEND
        
    READ_PM25:
        MOV R5, #2
        MOV DPTR, #PM25
        CJNE R1, #2, CLEAR
        AJMP SEND

    SEND:
        MOV R6, #85H
        ACALL LCD_SEND_CMD
        ACALL SEND_TYPE
        AJMP CALL_FUNC
    CLEAR:
        MOV R1, R5
        ACALL LCD_CLEAR
        ACALL WAIT
        ACALL SEND_STRING
        AJMP SEND


TEMPERATURE:
    DB "TEMP"
    DB ": "
HUMIDITY:
    DB "HUMI"
    DB ": "
PM25:
    DB "PM25"
    DB ": "

LCD_INIT:
    MOV R6, #38H
    ACALL LCD_SEND_CMD
    MOV R6, #0CH
    ACALL LCD_SEND_CMD
    MOV R6, #06H
    ACALL LCD_SEND_CMD
    ACALL LCD_CLEAR
    AJMP MAIN

LCD_CLEAR:
    MOV R6, #01H
    ACALL LCD_SEND_CMD
    MOV R6, #02H
    ACALL LCD_SEND_CMD
    RET

LCD_SEND_DATA:
    MOV P0, R7
    SETB P1.6
    SETB P1.7
	MOV R2, #1
    ACALL DELAY
    CLR P1.7
    RET

LCD_SEND_CMD:
    MOV P0, R6
    CLR P1.6
    SETB P1.7
	MOV R2, #4
    ACALL DELAY
    CLR P1.7
    RET

SEND_STRING:
    MOV R0, #0
    SEND_BYTE:
        MOV A, R0
        MOVC A, @A+DPTR
        CJNE A, #020H, NEXT
    RET
    NEXT: 
	    MOV R7, A
	    ACALL LCD_SEND_DATA
        INC R0
        AJMP SEND_BYTE
        

SEND_TYPE:
    CLR TI
    MOV SBUF, R5
    JNB TI, $
    RET

DELAY:
    MOV R3, #20
    DELAY_SUB:
        MOV R4, #125
        DJNZ R4, $
        DJNZ R3, DELAY_SUB
	DJNZ R2, DELAY
    RET 
WAIT:
    MOV R2, #100
    ACALL DELAY
    RET
END