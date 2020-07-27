NO LONGER USED
; TRADED / COP 
;
;
;		::PCPYCOP.DEF::
;*********************************************************************
;		CUSTOMER ORDER PROCESSING 
;		
;		RELEASED: AUGUST 1, 1984 (d70s10)
;		MODIFIED: JULY 24, 1985 1296 - 376+258
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
RECORD
	,A64,'THIS MATERIAL CONTAINS THE VALUABLE PROPERTIES AND TRADE SECRETS'
	,A62,'OF MCBA, EMBODYING CONFIDENTIAL INFORMATION AND IDEAS, NO PART'
	,A56,'OF WHICH MAY BE USED AND/OR DISCLOSED WITHOUT MCBAs DULY'
	,A55,'AUTHORIZED LICENSE AGREEMENT AND/OR WRITTEN PERMISSION.'
	,A61,'COPYRIGHT (C) MCBA, AN UNPUBLISHED WORK. ALL RIGHTS RESERVED.'
RECORD INVMAS		
		.INCLUDE 'DEF:RD041B.DEF'
RECORD HDR
	,A40,	'   PROD   DISC      PROD   DISC      PRO'
	,A40,	'D   DISC      PROD   DISC      PROD   DC'
RECORD
	V	,D1
	SWITCH	,D1
	ARRSIZ	,D2	,45	;VALUE IS ARRAY SIZE USUALLY 45
	ARPNTR	,D2
	CTR	,D2
	WROW	,D2
	WCOL	,D3
	HDCNTA	,A3
	HDCNTR	,D2
	ENTRY	,A6
	INXCTL	,D1
	WCUSNO	,D6
	CNGCTL	,D1
	WHATNO	,D2
	TCHAR	,D3
	SELECT	,D1
	DISCA	,A2
	ARRCNT	,D2
	COL2	,D2
	ROW2	,D2
	READ	,D1	,0
	WRITE	,D1	,1
	LOKCTL	,D1
PROC
	XCALL TERID(V)
	SWITCH = 3
	XCALL FILES(2,'I',42,SWITCH)	;FILE#42 -- ITMIDX FILE
	IF (SWITCH.EQ.9) GOTO END
	SWITCH = 5
	XCALL FILES(1,'U',41,SWITCH)		;FILE#41 -- INVMAS FILE
	IF (SWITCH.EQ.9) GO TO END1
	LOKCTL = 1
	XCALL IO (1,INVMAS,1,READ,LOKCTL)
	CNGCTL =
	IF (DPRDCD(1).NE.'  ') CNGCTL = 1
DISPLA,
	XCALL OUTPT (1,1,2,'TRADE DISCOUNT MAINTENANCE',V)
	XCALL OUTPT (2,1,0,HDR,V)
	HDCNTR =
LOOP01,
	INCR HDCNTR
	IF (HDCNTR.GE.(ARRSIZ+1)) GO TO MODE
	IF (HDCNTR.GT.36) GOTO COLFIV
	IF (HDCNTR.GT.27) GOTO COLFOR
	IF (HDCNTR.GT.18) GOTO COLTRE
	IF (HDCNTR.GT.9) GOTO COLTWO
COLONE,
	WCOL = 32
	WROW = HDCNTR + 2
	GOTO DSPHDR
COLTWO,
	WCOL = 48
	WROW = HDCNTR - 7
	GOTO DSPHDR
COLTRE,
	WCOL = 65
	WROW = HDCNTR - 16
	GOTO DSPHDR
COLFOR,
	WCOL = 82
	WROW = HDCNTR - 25
	GOTO DSPHDR
COLFIV,
	WCOL = 99
	WROW = HDCNTR - 34
DSPHDR,
	HDCNTA = HDCNTR,'ZX.'
	COL2 = WCOL-31
	XCALL OUTPT (WROW,COL2,0,HDCNTA,V)
	GOTO LOOP01
MODE,
	IF (CNGCTL.NE.0) GO TO CHANGE
	ARPNTR =
NEW1,
	INCR ARPNTR
	IF (ARPNTR.GT.45) GO TO ANYCNG
	HDCNTR = ARPNTR
ADDENT,
	IF (HDCNTR.GT.36) GOTO COLMFV
	IF (HDCNTR.GT.27) GOTO COLMFR
	IF (HDCNTR.GT.18) GOTO COLMTH
	IF (HDCNTR.GT.9) GOTO COLMTW
COLMON,
	WCOL = 5
	WROW = HDCNTR + 2
	GOTO ENTER
COLMTW,
	WCOL = 22
	WROW = HDCNTR - 7
	GOTO ENTER
COLMTH,
	WCOL = 39
	WROW = HDCNTR - 16
	GOTO ENTER
COLMFR,
	WCOL = 56
	WROW = HDCNTR - 25
	GOTO ENTER
COLMFV,
	WCOL = 73
	WROW = HDCNTR - 34
ENTER,
	XCALL INPUT (WROW,WCOL,02,00,'A ',ENTRY,INXCTL,V)
	IF (INXCTL.EQ.2.AND.CNGCTL.EQ.1) GO TO ENTER
	GOTO (DISPLA), INXCTL
	IF (ENTRY(1,2).EQ.'  '.AND.CNGCTL.EQ.0) GO TO CHANGE
	IF (ENTRY(1,2).EQ.'  ') GOTO DELETE
	DPRDCD(ARPNTR) = ENTRY(1,2)
NODUPS,
	CTR =
NODUP1,
	INCR CTR
	IF (CTR.GE.ARPNTR) GOTO ITISOK
	IF (DPRDCD(ARPNTR).EQ.DPRDCD(CTR)) GOTO BAD1
	GOTO NODUP1
BAD1,
	XCALL MESAG('DUPLICATE CODES NOT ALLOWED',1)
	GOTO ENTER
ITISOK,
	XCALL OUTPT (WROW,WCOL,0,DPRDCD(ARPNTR),V)
ENTER1,
	WCOL = WCOL + 6
	XCALL INPUT (WROW,WCOL,02,01,'# ',ENTRY,INXCTL,V)
	GOTO (ENTER), INXCTL
	DDISC(ARPNTR) = ENTRY(1,2)
	DISCA = DDISC(ARPNTR),'ZX'
	XCALL OUTPT (WROW,WCOL,0,DISCA,V)
	IF (CNGCTL.EQ.0) INCR ARRCNT
	GO TO (NEW1,ANYCNG), CNGCTL + 1
CHANGE,
	CALL DSPARR
ANYCNG,
	XCALL ANYCN(CNGCTL,WHATNO)
	GO TO (PROCES,CNGBR), CNGCTL + 1
CNGBR,
	IF (WHATNO.LT.1.OR.WHATNO.GE.(ARRSIZ+1)) GOTO ANYCNG
	IF (WHATNO.EQ.(ARRCNT+1)) INCR ARRCNT
	IF (WHATNO.GT.(ARRCNT+1)) CALL FIX
	HDCNTR = WHATNO
	ARPNTR = WHATNO
	GO TO ADDENT
DSPARR,
	HDCNTR =
	ARRCNT =
LOOP02,
	INCR HDCNTR
	IF (HDCNTR.GT.ARRSIZ) RETURN
	IF (DPRDCD(HDCNTR).NE.'  ') INCR ARRCNT
	IF (HDCNTR.GT.36) GOTO COLV
	IF (HDCNTR.GT.27) GOTO COLIV
	IF (HDCNTR.GT.18) GOTO COLIII
	IF (HDCNTR.GT.9) GOTO COLII
COLI,
	WCOL = 36
	WROW = HDCNTR + 2
	GOTO DSPDIS
COLII,
	WCOL = 53
	WROW = HDCNTR - 7
	GOTO DSPDIS
COLIII,
	WCOL = 70
	WROW = HDCNTR - 16
	GOTO DSPDIS
COLIV,
	WCOL = 87
	WROW = HDCNTR - 25
	GOTO DSPDIS
COLV,
	WCOL = 104
	WROW = HDCNTR - 34
DSPDIS,
	IF (DPRDCD(HDCNTR).EQ.'  '.AND.DDISC(HDCNTR).EQ.0) THEN
		DISCA = DDISC(HDCNTR),'ZZ'
	ELSE
		DISCA = DDISC(HDCNTR),'ZX'
	COL2 = WCOL-31
	XCALL OUTPT (WROW,COL2,0,DPRDCD(HDCNTR),V)
	COL2 = WCOL+2-31
	XCALL OUTPT (WROW,COL2,0,'    ',V)
	COL2 = WCOL+6-31
	XCALL OUTPT (WROW,COL2,0,DISCA,V)
	GOTO LOOP02
DELETE,
	IF (DPRDCD(ARPNTR+1).EQ.'  '.OR.(ARPNTR+1).GT.ARRSIZ) GOTO CLRSPT
	DPRDCD(ARPNTR) = DPRDCD(ARPNTR+1)
	DDISC(ARPNTR) = DDISC(ARPNTR+1)
	INCR ARPNTR
	GOTO DELETE
CLRSPT,
	DPRDCD(ARPNTR) =
	DDISC(ARPNTR) =
	CALL DSPARR
	GOTO ANYCNG
FIX,
	INCR ARRCNT
	WHATNO = ARRCNT
	RETURN
PROCES,
	XCALL WATE(3,V)
	LOKCTL = 1
	XCALL IO (1,INVMAS,1,WRITE,LOKCTL)
	CLOSE 1
END1,
	XCALL FILES (2,'I',42,4)
END,
	XCALL PGCHN ('CP:SPCFUN',1)
	END
