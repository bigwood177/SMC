;STPWKO.COP - STOP WORK ORDER PRINT PROCESS
;
;
RECORD MESARA
			.INCLUDE 'DEF:MES001.DEF'
RECORD,X
			.INCLUDE 'DEF:MES002.DEF'
RECORD
	V	,D1
	SYTTNO	,D3
	TERM	,D3
	TTNOSW	,D1
	LOKCTL	,D1
	READ	,D1,0
	WRITE	,D1,1
	DFLD	,D1
	ANS	,A1
PROC
	OPEN (15,I,'TT:')
;ASK,
;	DISPLAY (15,13,10,'WORK ORDER PRINT PROGRAM: 0=STOP / 1=START: ')
;	READS (15,ANS,EOF)
;	ONERROR ASK
;	DFLD = ANS
;	OFFERROR
;	GOTO (STOP,START), DFLD+1
;	GOTO ASK
STOP,
	OPEN (13,U,'UT:MESARA.DDF')
	LOKCTL = 1
	XCALL IO (13,MESARA,83,READ,LOKCTL)
	CMPCOD =
	CMPPOS =
	SECREC =
	SPOLDV =
	LOKCTL = 1
	XCALL IO (13,MESARA,83,WRITE,LOKCTL)
	CLOSE 13
	DISPLAY (15,13,10,'*** Stopping work order print process ***',13,10)
	SEND (']]]]]]]]','WRKORD')
	STOP
;START,
;	OPEN (13,U,'UT:MESARA.DDF')
;	LOKCTL = 1
;	XCALL IO (13,MESARA,84,READ,LOKCTL)
;	XCALL IO (13,MESARA,83,WRITE,LOKCTL)
;	DISPLAY (15,13,10,'*** Starting work order print process ***',13,10)
;	STOP '@CP:WRKORD'
EOF,
	STOP
END
