BL51 BANKED LINKER/LOCATER V6.22.2.0                                                    11/02/2022  13:28:57  PAGE 1


BL51 BANKED LINKER/LOCATER V6.22.2.0, INVOKED BY:
C:\KEIL_V5\C51\BIN\BL51.EXE main.obj, smg.obj, ds18b20.obj, public.obj TO DS18B20 RAMSIZE (256)


MEMORY MODEL: SMALL


INPUT MODULES INCLUDED:
  main.obj (MAIN)
  smg.obj (SMG)
  ds18b20.obj (DS18B20)
  public.obj (PUBLIC)
  C:\KEIL_V5\C51\LIB\C51S.LIB (?C_STARTUP)
  C:\KEIL_V5\C51\LIB\C51S.LIB (?C_INIT)


LINK MAP OF MODULE:  DS18B20 (MAIN)


            TYPE    BASE      LENGTH    RELOCATION   SEGMENT NAME
            -----------------------------------------------------

            * * * * * * *   D A T A   M E M O R Y   * * * * * * *
            REG     0000H     0008H     ABSOLUTE     "REG BANK 0"
            DATA    0008H     0009H     UNIT         ?DT?SMG
            DATA    0011H     0001H     UNIT         ?DT?DS18B20_CHECK?DS18B20
            IDATA   0012H     0001H     UNIT         ?STACK

            * * * * * * *   C O D E   M E M O R Y   * * * * * * *
            CODE    0000H     0003H     ABSOLUTE     
                    0003H     07FDH                  *** GAP ***
            CODE    0800H     008DH     UNIT         ?PR?SMG_SHOWLED?SMG
            CODE    088DH     008CH     UNIT         ?C_C51STARTUP
            CODE    0919H     0053H     UNIT         ?PR?DS18B20_CHECK?DS18B20
            CODE    096CH     0014H     UNIT         ?PR?_DE18B20_WRITE_BYTE?DS18B20
            CODE    0980H     0010H     UNIT         ?PR?PUBLIC_T0_INIT?PUBLIC
            CODE    0990H     000EH     UNIT         ?C_INITSEG
            CODE    099EH     000EH     UNIT         ?PR?DS18B20_RESET?DS18B20
            CODE    09ACH     000AH     UNIT         ?CO?SMG
            CODE    09B6H     0007H     UNIT         ?PR?_PUBLIC_US_DELAY?PUBLIC
            CODE    09BDH     0006H     UNIT         ?PR?DS18B20_INIT?DS18B20
            CODE    09C3H     0005H     UNIT         ?PR?MAIN?MAIN



OVERLAY MAP OF MODULE:   DS18B20 (MAIN)


SEGMENT
  +--> CALLED SEGMENT
---------------------
?C_C51STARTUP
  +--> ?PR?MAIN?MAIN
  +--> ?C_INITSEG

?PR?MAIN?MAIN
  +--> ?PR?PUBLIC_T0_INIT?PUBLIC

BL51 BANKED LINKER/LOCATER V6.22.2.0                                                  11/02/2022  13:28:57  PAGE 2




SYMBOL TABLE OF MODULE:  DS18B20 (MAIN)

  VALUE           TYPE          NAME
  ----------------------------------

  -------         MODULE        MAIN
  C:0000H         SYMBOL        _ICE_DUMMY_
  D:0090H         PUBLIC        P1
  D:00B0H         PUBLIC        P3
  D:00A8H         PUBLIC        IE
  D:00B8H         PUBLIC        IP
  C:09C3H         PUBLIC        main
  D:0098H         PUBLIC        SCON
  D:0088H         PUBLIC        TCON
  D:00C8H         PUBLIC        T2CON
  D:00D0H         PUBLIC        PSW
  -------         PROC          MAIN
  C:09C3H         LINE#         3
  C:09C3H         LINE#         6
  C:09C6H         LINE#         8
  C:09C6H         LINE#         10
  -------         ENDPROC       MAIN
  -------         ENDMOD        MAIN

  -------         MODULE        SMG
  C:0000H         SYMBOL        _ICE_DUMMY_
  D:0080H         PUBLIC        P0
  D:0090H         PUBLIC        P1
  D:00A0H         PUBLIC        P2
  D:00B0H         PUBLIC        P3
  D:00A8H         PUBLIC        IE
  C:09ACH         PUBLIC        LedChar
  D:00B8H         PUBLIC        IP
  D:0009H         PUBLIC        LedBuff
  D:0098H         PUBLIC        SCON
  D:0088H         PUBLIC        TCON
  B:00A0H.2       PUBLIC        ADDR0
  B:00A0H.3       PUBLIC        ADDR1
  B:00A0H.4       PUBLIC        ADDR2
  C:0800H         PUBLIC        smg_ShowLed
  D:00C8H         PUBLIC        T2CON
  D:00D0H         PUBLIC        PSW
  -------         PROC          SMG_SHOWLED
  -------         DO            
  D:0008H         SYMBOL        i
  -------         ENDDO         
  C:0800H         LINE#         10
  C:0800H         LINE#         13
  C:0803H         LINE#         14
  C:082CH         LINE#         15
  C:0838H         LINE#         16
  C:0844H         LINE#         17
  C:0850H         LINE#         18
  C:085CH         LINE#         19
  C:0868H         LINE#         20
BL51 BANKED LINKER/LOCATER V6.22.2.0                                                  11/02/2022  13:28:57  PAGE 3


  C:0874H         LINE#         21
  C:0880H         LINE#         22
  C:088CH         LINE#         23
  C:088CH         LINE#         24
  -------         ENDPROC       SMG_SHOWLED
  -------         ENDMOD        SMG

  -------         MODULE        DS18B20
  C:0000H         SYMBOL        _ICE_DUMMY_
  D:0090H         PUBLIC        P1
  D:00B0H         PUBLIC        P3
  C:099EH         PUBLIC        ds18b20_reset
  D:00A8H         PUBLIC        IE
  D:00B8H         PUBLIC        IP
  C:09BDH         PUBLIC        ds18b20_init
  C:096CH         PUBLIC        _de18b20_write_byte
  B:00B0H.7       PUBLIC        DS18B20_IO
  D:0098H         PUBLIC        SCON
  D:0088H         PUBLIC        TCON
  D:00C8H         PUBLIC        T2CON
  C:0919H         PUBLIC        ds18b20_check
  D:00D0H         PUBLIC        PSW
  -------         PROC          DS18B20_RESET
  C:099EH         LINE#         4
  C:099EH         LINE#         5
  C:09A0H         LINE#         6
  C:09A5H         LINE#         7
  C:09A7H         LINE#         8
  -------         ENDPROC       DS18B20_RESET
  -------         PROC          DS18B20_CHECK
  -------         DO            
  D:0011H         SYMBOL        time_temp
  -------         ENDDO         
  C:0919H         LINE#         12
  C:0919H         LINE#         14
  C:091CH         LINE#         15
  C:092AH         LINE#         16
  C:092CH         LINE#         17
  C:0931H         LINE#         18
  C:0933H         LINE#         19
  C:0941H         LINE#         20
  C:0944H         LINE#         23
  C:0952H         LINE#         24
  C:0954H         LINE#         25
  C:0959H         LINE#         26
  C:095BH         LINE#         27
  C:0969H         LINE#         28
  C:096BH         LINE#         29
  -------         ENDPROC       DS18B20_CHECK
  -------         PROC          DS18B20_INIT
  C:09BDH         LINE#         32
  C:09BDH         LINE#         33
  C:09C0H         LINE#         34
  -------         ENDPROC       DS18B20_INIT
  -------         PROC          _DE18B20_WRITE_BYTE
  D:0007H         SYMBOL        dat
  -------         DO            
BL51 BANKED LINKER/LOCATER V6.22.2.0                                                  11/02/2022  13:28:57  PAGE 4


  D:0005H         SYMBOL        i
  D:0006H         SYMBOL        temp
  -------         ENDDO         
  C:096CH         LINE#         38
  C:096CH         LINE#         40
  C:096DH         LINE#         41
  C:0978H         LINE#         42
  C:097CH         LINE#         43
  C:097FH         LINE#         44
  -------         ENDPROC       _DE18B20_WRITE_BYTE
  -------         ENDMOD        DS18B20

  -------         MODULE        PUBLIC
  C:0000H         SYMBOL        _ICE_DUMMY_
  C:0980H         PUBLIC        public_T0_init
  D:0090H         PUBLIC        P1
  D:00B0H         PUBLIC        P3
  B:00A8H.7       PUBLIC        EA
  D:00A8H         PUBLIC        IE
  D:00B8H         PUBLIC        IP
  D:0098H         PUBLIC        SCON
  D:0089H         PUBLIC        TMOD
  D:0088H         PUBLIC        TCON
  C:09B6H         PUBLIC        _public_us_delay
  B:00A8H.1       PUBLIC        ET0
  D:008CH         PUBLIC        TH0
  D:008AH         PUBLIC        TL0
  B:0088H.4       PUBLIC        TR0
  D:00C8H         PUBLIC        T2CON
  D:00D0H         PUBLIC        PSW
  -------         PROC          PUBLIC_T0_INIT
  C:0980H         LINE#         4
  C:0980H         LINE#         7
  C:0982H         LINE#         9
  C:0985H         LINE#         11
  C:0988H         LINE#         12
  C:098BH         LINE#         14
  C:098DH         LINE#         16
  C:098FH         LINE#         17
  -------         ENDPROC       PUBLIC_T0_INIT
  -------         PROC          _PUBLIC_US_DELAY
  D:0007H         SYMBOL        z
  C:09B6H         LINE#         20
  C:09B6H         LINE#         21
  C:09BCH         LINE#         22
  -------         ENDPROC       _PUBLIC_US_DELAY
  -------         ENDMOD        PUBLIC

*** WARNING L16: UNCALLED SEGMENT, IGNORED FOR OVERLAY PROCESS
    SEGMENT: ?PR?SMG_SHOWLED?SMG

*** WARNING L16: UNCALLED SEGMENT, IGNORED FOR OVERLAY PROCESS
    SEGMENT: ?CO?SMG

*** WARNING L16: UNCALLED SEGMENT, IGNORED FOR OVERLAY PROCESS
    SEGMENT: ?PR?DS18B20_INIT?DS18B20

BL51 BANKED LINKER/LOCATER V6.22.2.0                                                  11/02/2022  13:28:57  PAGE 5


*** WARNING L16: UNCALLED SEGMENT, IGNORED FOR OVERLAY PROCESS
    SEGMENT: ?PR?_DE18B20_WRITE_BYTE?DS18B20

******************************************************************************
* RESTRICTED VERSION WITH 0800H BYTE CODE SIZE LIMIT; USED: 013BH BYTE (15%) *
******************************************************************************

Program Size: data=19.0 xdata=0 code=459
LINK/LOCATE RUN COMPLETE.  4 WARNING(S),  0 ERROR(S)
