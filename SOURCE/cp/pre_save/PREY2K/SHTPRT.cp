;  SHTPRT / COP 
;
;
;		::PCPYCOP.DEF::
;*********************************************************************
;		CUSTOMER ORDER PROCESSING 
;		
;		RELEASED: AUGUST 1, 1984 (d70s10)
;***********************************************************************
;
;		PROPRIETARY RIGHTS NOTICE:  All rights reserved.  This
;		material contains the valuable properties and trade secrets
;		of MCBA, Glendale, California, USA embodying substantial
;		creative effort and confidential information and ideas, no
;		part of which may be used and/or disclosed without MCBA's
;		duly authorized license agreement and/or written permission.
;
;		COPYRIGHT NOTICE:  Copyright <C> 1978, 1981, 1982, 1983, 1984
;		MCBA, AN UNPUBLISHED WORK.  ALL RIGHTS RESERVED.
;
;
;		COMPILE & LINK PER INSTALLATION OR TECHNICAL NOTES.
;
;:
;
;		PRINTS THE SHIP-TO ADDRESS LIST
;
RECORD
	,A64,'THIS MATERIAL CONTAINS THE VALUABLE PROPERTIES AND TRADE SECRETS'
	,A62,'OF MCBA, EMBODYING CONFIDENTIAL INFORMATION AND IDEAS, NO PART'
	,A56,'OF WHICH MAY BE USED AND/OR DISCLOSED WITHOUT MCBAs DULY'
	,A55,'AUTHORIZED LICENSE AGREEMENT AND/OR WRITTEN PERMISSION.'
	,A61,'COPYRIGHT (C) MCBA, AN UNPUBLISHED WORK. ALL RIGHTS RESERVED.'
RECORD SHIPTO
		.INCLUDE 'DEF:RD171A.DEF'
RECORD SHPCTL,X    
		.INCLUDE 'DEF:RD171B.DEF'
RECORD,X
		.INCLUDE 'DEF:RD171C.DEF'
RECORD CUSMAS	
		.INCLUDE 'DEF:RD001A.DEF'
RECORD CUSCTL,X	
		.INCLUDE 'DEF:RD001B.DEF'
RECORD CUSIDX
		.INCLUDE 'DEF:RD002A.DEF'
RECORD ARTCDE
		.INCLUDE 'DEF:RD169A.DEF'
RECORD ARTCTL,X
		.INCLUDE 'DEF:RD169B.DEF'
RECORD TITLE
		,A25,	'SHIP-TO ADDRESS PRINT-OUT'
RECORD LEGND1
		,A17,	'RANGE: CUSTOMERS '
	LCUST1	,A6
		,A7,	' THRU  '
	LCUST2	,A6
RECORD HDR1
		,A1
		,A4,	'CUST'
		,A3
		,A12,	'BILL-TO NAME'
		,A20
		,A7,	'SHIP-TO'
		,A2
		,A12,	'SHIP-TO NAME'
		,A20
		,A7,	'SHIP-TO'
		,A3
		,A11,	'DESCRIPTION'
RECORD HDR2
		,A2
		,A2,	'NO'
		,A4
		,A15,	'BILL-TO ADDRESS'
		,A19
		,A2,	'NO'
		,A5
		,A15,	'SHIP-TO ADDRESS'
		,A17
		,A8,	'TAX CODE'
RECORD CTL
	ROW	,D2
		,A1
	COL	,D2
		,A1
	MAX	,D2
		,A1
	MIN	,D2
		,A1
	TYPE	,A2
RECORD
	BS171   ,D5
	BS001   ,D5
	BS169	,D5
	BSEND   ,D5
	BSMID	,D5
	ENDNO	,A6
	ENDNO1	,A6
	KEY     ,A4
	LINCNT	,D2
	LOKCTL	,D1
	LPARG   ,D1
	LPONSW	,D1
	LPSW	,D1
	MAXCNT  ,D5
	PGCNT	,D3
	PLINE	,A132
	PRTTYP  ,A1
	READ    ,D1     ,0
	RECCNT  ,D5
	RECNO   ,D5
	RPTNUM  ,D3
	SAVCUS	,A6
	SPLFIL  ,A14
	SRCCTL	,D1
	STXCTL	,D1
	SWITCH	,D1
	STARTN  ,A6
	START1	,A6
	V	,D1
	WRITE	,D1	,1
	XHCSNO	,A6
	XSTART	,A6
PROC
	XCALL TERID(V)
	SWITCH = 1
	XCALL FILES (1,'I',171,SWITCH)		;FILE # 171 -- SHIPTO
	IF (SWITCH.EQ.9) GO TO INU171
	LOKCTL = 0
	XCALL IO (1,SHPCTL,1,READ,LOKCTL)
	RECCNT = REC171
	BS171 = ORG171
	MAXCNT = MAX171
	IF (RECCNT.LE.1) GO TO END
	SWITCH = 1
	XCALL FILES (2,'I',02,SWITCH)		;FILE # 002 -- CUSIDX
	IF (SWITCH.EQ.9) GO TO INU002
	SWITCH = 1
	XCALL FILES (3,'I',01,SWITCH)		;FILE # 003 -- CUSMAS
	IF (SWITCH.EQ.9) GO TO INU003
	SWITCH = 1
	XCALL FILES (4,'I',169,SWITCH)		;FILE # 169 -- ARTCDE
	IF (SWITCH.EQ.9) GO TO INU004
	LOKCTL = 0
	XCALL IO (3,CUSCTL,1,READ,LOKCTL)
	BS001 = ORG001
	LOKCTL = 0
	XCALL IO (4,ARTCTL,1,READ,LOKCTL)
	BS169 = ORG169
DISPLA,
	BSMID =
	LPONSW =
	XCALL OUTPT (1,1,2,'SHIP-TO FILE MAINTENANCE',V)
	XCALL OUTPT (2,1,0,'PRINT OUT SHIP-TO LIST',1)
	STXCTL = 1
	XCALL STENO (START1,ENDNO1,'CUSTOMER',6,STXCTL,V)
	IF (STXCTL) GO TO ENDOFF
	STARTN = START1
	ENDNO = ENDNO1
	IF (ENDNO.LT.STARTN) XCALL MESAG ('INVALID RANGE',1)
	IF (ENDNO.LT.STARTN) GO TO DISPLA
	IF (STARTN.NE.'  ') LCUST1 = STARTN
	IF (ENDNO.NE.'[[') LCUST2 = ENDNO
	IF (STARTN.EQ.'  ') LCUST1 = 'ALL'
	IF (STARTN.EQ.'  ') LCUST2 = 'ALL'
PROCES,
	XCALL WATE (4,V)
	LINCNT = 60
	PGCNT =
	SRCCTL = 4
	BSEND = BS171
;	XSTART = STARTN ,'XXXXXX'		;COP36
	XSTART = STARTN				;COP36
	XCALL SERCH (1,SHIPTO,XSTART,1,6,BSEND,BSMID,SRCCTL,6,11,16,0,0,0,0)
	IF (SRCCTL.EQ.2) GO TO DISPLA
	RECNO = BSMID - 1
	IF (RECNO.EQ.0) RECNO = 1
RECORD,
	INCR RECNO
	IF (RECNO.GT.MAXCNT) GO TO END
	XCALL IO (1,SHIPTO,RECNO,READ,LOKCTL)
	IF (SHIPTO(1,6).EQ.']]]]]]') GO TO END
	IF (DFL171.EQ.']]]DEL') GO TO RECORD
	XHCSNO = SHCSNO , 'XXXXXX'
	IF (XHCSNO.GT.ENDNO .AND. RECNO.LT.BS171) RECNO = BS171    ;OVERFLOW
	IF (XHCSNO.GT.ENDNO .AND. RECNO.LT.BS171) GO TO RECORD
	IF (XHCSNO.LT.STARTN .OR. XHCSNO.GT.ENDNO) GO TO RECORD
NXTCUS,
	SAVCUS = XHCSNO
	CALL GETCUS
	CALL FMTLIN
NXTSHP,
	INCR RECNO
	IF (RECNO.GT.MAXCNT) GO TO END
	XCALL IO (1,SHIPTO,RECNO,READ,LOKCTL)
	IF (SHIPTO(1,6).EQ.']]]]]]') GO TO END
	IF (DFL171.EQ.']]]DEL') GO TO NXTSHP
	XHCSNO = SHCSNO , 'XXXXXX'
	IF (XHCSNO.GT.ENDNO .AND. RECNO.LT.BS171) RECNO = BS171    ;OVERFLOW
	IF (XHCSNO.GT.ENDNO .AND. RECNO.LT.BS171) GO TO NXTSHP
	IF (XHCSNO.LT.STARTN .OR. XHCSNO.GT.ENDNO) GO TO NXTSHP
	IF (SAVCUS.NE.XHCSNO) GO TO NXTCUS
	CALL FMTSHP
	GO TO NXTSHP
FMTLIN,
	PLINE(1,6) = SHCSNO , 'XXXXXX'
	PLINE(9,38) = NAME
	PLINE(42,45) = SHTONO , 'XXXX'
	PLINE(50,79) = SHTONA
	PLINE(84,86) = SHTOTC
	CALL GTTXDS
	PLINE(92,121) = ARTDSC
	CALL PRINT
	PLINE =
	PLINE(9,38) = ADD1
	PLINE(50,79) = SHTOAD(1)
	CALL PRINT
	PLINE =
	PLINE(9,30) = ADD2
	PLINE(50,79) = SHTOAD(2)
	CALL PRINT
	PLINE =
	PLINE(9,23) = CITY
	PLINE(25,26) = STATE
	PLINE(29,38) = ZIP
	PLINE(50,79) = SHTOAD(3)
	CALL PRINT
	PLINE =
	CALL PRINT
	RETURN
FMTSHP,
	PLINE(42,45) = SHTONO , 'XXXX'
	PLINE(50,79) = SHTONA
	PLINE(84,86) = SHTOTC
	CALL GTTXDS
	PLINE(92,121) = ARTDSC
	CALL PRINT
	PLINE =
	PLINE(50,79) = SHTOAD(1)
	CALL PRINT
	PLINE =
	PLINE(50,79) = SHTOAD(2)
	CALL PRINT
	PLINE =
	PLINE(50,79) = SHTOAD(3)
	CALL PRINT
	PLINE =
	CALL PRINT
	RETURN
END,
	IF (RECCNT.LE.1)
&		XCALL MESAG ('DEPARTMENT CROSS REFERENCE TABLE FILE IS EMPTY',1)
	IF (RECCNT.LE.1) GO TO ENDOFF
	IF (LPONSW.EQ.0) XCALL MESAG ('NO RECORDS WITHIN RANGE',1)
	IF (LPONSW.EQ.0) GO TO DISPLA
	XCALL LPOFF (LPSW,SPLFIL,PGCNT)
	LOKCTL = 0
	XCALL IO (1,SHPCTL,1,READ,LOKCTL)
	IF (STARTN.NE.'  ') GO TO DISPLA	;range was selected
ENDOFF,
	XCALL WATE (3,V)
	XCALL FILES (4,'I',169,4)
INU004,
	XCALL FILES (3,'I',01,4)
INU003,
	XCALL FILES (2,'I',02,4)
INU002,
	XCALL FILES (1,'I',171,4)
INU171,
	XCALL PGCHN ('CP:SHTMNT',1)
;*******************************************************************************
PRINT,
	IF (LPONSW.EQ.0) GO TO PRNTON
	XCALL LPOUT (LINCNT,PGCNT,PLINE,TITLE,HDR1,HDR2,'NO HDR',LEGND1
& 		,'NO LEGEND','NO LEGEND',0,132,132,1,LPSW,RPTNUM,PRTTYP)
	RETURN
PRNTON,
	SPLFIL (5,6) = 'EZ'
	LPSW = 1
	XCALL LPON (LPSW,SPLFIL)
	IF (LPSW.EQ.0) GO TO ENDOFF
	LPARG = 2
	IF (LPSW.EQ.2) LPARG = 4
	XCALL WATE (LPARG,V)
	LPONSW = 1
	GO TO PRINT
;********************************************************************************
GETCUS,
	BSEND = BS001
;	SRCCTL = 4		;COP36
	SRCCTL = 3		;COP36
	XCALL SERCH (2,CUSIDX,SHCSNO,1,6,BSEND,BSMID,SRCCTL,4,7,11,0,0,0,0)
	IF (SRCCTL.EQ.1) GO TO NOTFND
	LOKCTL = 1
	XCALL IO (3,CUSMAS,IRC001,READ,LOKCTL)
	GO TO FOUND
NOTFND,
	NAME = '**** CUSTOMER NOT FOUND ***'
	ADD1 =
	ADD2 =
	CITY =
	STATE =
	ZIP =
FOUND,	
	RETURN
;********************************************************************************
GTTXDS,
	IF (SHTOTC.EQ.'   ') ARTDSC =
	IF (SHTOTC.EQ.'   ') RETURN
	SRCCTL = 4
	XCALL SERCH (4,ARTCDE,SHTOTC,1,3,BS169,BSMID,SRCCTL,4,4,9,0,0,0,0)
	IF (SRCCTL.EQ.1) ARTDSC = ' ***** TAX CODE NOT FOUND **** '
	RETURN
;********************************************************************************
END