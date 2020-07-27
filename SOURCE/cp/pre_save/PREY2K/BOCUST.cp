;  BOCUST / COP 
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
;		PGM TO PRINT CUSTOMER ORDER STATUS REPORTS BY CUSTOMER
;
RECORD
	,A64,'THIS MATERIAL CONTAINS THE VALUABLE PROPERTIES AND TRADE SECRETS'
	,A62,'OF MCBA, EMBODYING CONFIDENTIAL INFORMATION AND IDEAS, NO PART'
	,A56,'OF WHICH MAY BE USED AND/OR DISCLOSED WITHOUT MCBAs DULY'
	,A55,'AUTHORIZED LICENSE AGREEMENT AND/OR WRITTEN PERMISSION.'
	,A61,'COPYRIGHT (C) MCBA, AN UNPUBLISHED WORK. ALL RIGHTS RESERVED.'

RECORD BOINDX  		
		.INCLUDE 'DEF:RD052A.DEF'
RECORD DUMINV		
		.INCLUDE 'DEF:RD041B.DEF'
RECORD BAKORD, X  		
		.INCLUDE 'DEF:RD051A.DEF'
RECORD ,X		
		.INCLUDE 'DEF:RD051B.DEF'
RECORD LEGND1
		,A14,'FOR LOCATION: '
	LEGLOC	,A3
		,A3
		,A3,'BY '
	DATTYP	,A9
		,A5,' DATE'
		,A3
		,A5,'FROM '
	LGSTDT	,A8
		,A4,' TO '
	LGENDT	,A8
RECORD LEGND2
		,A48,'STOCKED CODE (STK): "S"=STOCKED  "N"=NON-STOCKED'
		,A4
		,A38,'("*" INDICATES NON-BACKORDERABLE ITEM)'
RECORD LEGND3
		,A41,'NOTE: DOLLAR AMOUNTS ARE FULLY DISCOUNTED'
RECORD HDR1
		,A15,'CUSTOMER NUMBER'
		,A12
		,A5,'ORDER'
		,A3
	SCHORD	,A7
		,A54
		,A3,'QTY'
		,A3
		,A3,'QTY'
		,A5
		,A3,'NET'
		,A3
		,A3,'STK'
		,A3
		,A8,'CUSTOMER'
RECORD HDR2
		,A13,'CUSTOMER NAME'
		,A14
		,A6,'NUMBER'
		,A4
		,A4,'DATE'
		,A4
		,A11,'ITEM NUMBER'
		,A6
		,A16,'ITEM DESCRIPTION'
		,A18
		,A3,'ORD'
		,A3
		,A3,'B/O'
		,A4
		,A6,'AMOUNT'
		,A4
		,A3,'LOC'
		,A2
		,A4,'PO-#'
RECORD TITLE
	RPTNAM	,A54
RECORD
	RNAME1	,A35,'PRINT CUSTOMER ORDER STATUS REPORTS'
	DASHES	,A30,'------------------------------'
	CUSCNT	,D4
	ENDSW	,D1
	LSTCUS	,D6
	DATE	,D6
	DTMASK	,A8,'ZX/XX/XX'
	MASK	,A7, 'ZZZ,ZZX'
	MASK2	,A14,'$$$,$$$,$$$.XX'
	TOTQTY	,D6
	STRTCS	,D6
	ENDCUS	,D6
	STXCTL	,D1
	LINCNT	,D2,60
	LIT1	,A10,'$ ORDERED:'
	LIT2	,A9,'$ ON B/O:'
	BLANKS	,A6
	LOTN	,A2
	PGCNT	,D6
	PLINE	,A132
	PRTCTL	,D3
	SPLFIL	,A14
	SAVNAM	,A25
	CONTER	,D4
	TOTORD	,D6
	ORDAMT	,D9
	BORAMT	,D9
	TORAMT	,D10
	TBOAMT	,D10
	TOSAMT	,D10
	NETAMT	,D8
	LPONSW	,D1
	DECMAL	,D8
	SWITCH	,D1
	DATEFL	,A1
	LPSW	,D2
	LPARG	,D1
	RPTNUM	,D3
	PRTTYP	,A1
	RPTYP	,D1
	V	,D1
	READ	,D1	,0
	WRITE	,D1	,1
	LOKCTL	,D1
	JUST	,D1
PROC
	XCALL TERID (V)
	XCALL OUTPT (2,1,1,'\',1)
	SWITCH = 5
	XCALL FILES (10,'I',41,SWITCH)
	LOKCTL = 1
	XCALL IO (10,DUMINV,1,READ,LOKCTL)
	JUST = JSTIFY
	CLOSE 10
	DUMINV =
	SWITCH = 5
	XCALL FILES(6,'I',51,SWITCH)
	LOKCTL = 1
	XCALL IO (6,BAKORD,1,READ,LOKCTL)
	RPTYP = RPTTYP
	CALL RPTYPE
	LEGLOC = RPTLOC
	IF (RPTLOC.EQ.'  ') LEGLOC = 'ALL'
	DATTYP = 'REQUESTED'
	IF (DATFLG.EQ.'P') DATTYP = 'PROMISED'
	LGSTDT = STDATE, DTMASK
	LGENDT = ENDATE, DTMASK
DISPLA,
	LINCNT = 60
	TORAMT =
	TBOAMT =
	TOSAMT =
	LSTCUS =
	XCALL OUTPT (1,1,2,RNAME1,1)
	XCALL OUTPT (2,1,0,TITLE,1)
	STXCTL = 1
	XCALL STENO (STRTCS,ENDCUS,'CUSTOMER #',6,STXCTL,V)
	IF (STXCTL) GOTO END
	ENDSW =
	CUSCNT =
	XCALL WATE(3,V)
	CLOSE 7
	SWITCH = 5
	XCALL FILES (7,'I',52,SWITCH)		;FILE # 52 -- BOINDX
	LOKCTL = 1
	XCALL IO (6,BAKORD,1,READ,LOKCTL)
	IF (DATFLG.EQ.'P') SCHORD = 'PROMISED'
	IF (DATFLG.EQ.'R') SCHORD = 'REQUEST'
	DATEFL = DATFLG
	LOTN = RPTLOC
	LOKCTL = 1
	XCALL IOS (7,BOINDX,READ,LOKCTL)
	IF (LOKCTL.EQ.2) GO TO NOFIND
FNDCUS,
	LOKCTL = 1
	XCALL IOS (7,BOINDX,READ,LOKCTL)
	IF (LOKCTL.EQ.2) GO TO NOFIND
	IF (BIITMN.EQ.']]]]]]') GOTO NOFIND
	IF (STRTCS.EQ.0) GO TO FOUND
	IF (BICUNO.GT.ENDCUS) GOTO NOFIND
	IF (BICUNO.GE.STRTCS.AND.BICUNO.LE.ENDCUS) GO TO FOUND
	IF (BICUNO.LT.STRTCS) GO TO FNDCUS
NOFIND,
	IF (STRTCS.EQ.0) GOTO NOBAKS
	XCALL MESAG('NO CUSTOMER FOUND IN RANGE',1)
	GO TO DISPLA
NOBAKS,
	XCALL MESAG ('NO ITEMS EXIST FOR THIS REPORT',1)
	GOTO END
RPTYPE,
	IF (RPTYP.EQ.1) RPTNAM =
&		'BACKORDER REPORT BY CUSTOMER - STOCKED ITEMS ONLY'
	IF (RPTYP.EQ.2) RPTNAM =
&		'BACKORDER REPORT BY CUSTOMER - NON-STOCKED ITEMS'
	IF (RPTYP.EQ.3) RPTNAM =
&		'BACKORDER REPORT BY CUSTOMER - ALL ITEMS'
	IF (RPTYP.EQ.4) RPTNAM =
&		'OPEN ORDER REPORT BY CUSTOMER - NON-STOCKED ITEMS'
	IF (RPTYP.EQ.5) RPTNAM = 'OPEN ORDER REPORT BY CUSTOMER - ALL ITEMS'
	RETURN
RLOOP,
	LOKCTL = 1
	XCALL IOS (7,BOINDX,READ,LOKCTL)
	IF (LOKCTL.EQ.2) GO TO EOF2
	IF (BIITMN.EQ.']]]]]]') GOTO EOF2
	IF (STRTCS.EQ.0) GO TO FOUND
	IF (BICUNO.GT.ENDCUS) GO TO EOF2
FOUND,
	LOKCTL = 1
	XCALL IO (6,BAKORD,IRC051,READ,LOKCTL)
	IF (CONTER.EQ.1) PLINE(1,25) = SAVNAM
	IF (BCUSNO.NE.LSTCUS) CALL PSUB
	INCR CONTER
	TOTORD = TOTORD + BQTYOR
	TOTQTY = TOTQTY + BQTYBO
	NETAMT = (BUNPRC*BQTYOR) - (BUNPRC*BQTYOR*BLDISC/100)
	NETAMT = NETAMT - (NETAMT*BODISC/100)
	PLINE (28,33) = BORDNO, 'ZZZZZX'
	DATE (5,6) = BORDDT (1,2)
	DATE (1,4) = BORDDT (3,6)
	PLINE (36,43) = DATE,DTMASK
	IF (BORTYP.EQ.'O') PLINE (45,45) = '*'
	PLINE (46,60) = BITMNO
	IF (JUST) XCALL LEFTJ (PLINE(46,60),15)
	PLINE (63,92) = BDESCR
	PLINE (95,99) = BQTYOR,MASK
	PLINE (101,105) = BQTYBO, MASK
	PLINE (107,116) = NETAMT,'ZZZ,ZZZ.XX'
	PLINE (118,118) = BSTOKD
	PLINE (120,121) = BLOC
	PLINE (123,132) = BCUSPO
	ORDAMT = ORDAMT + NETAMT
	TORAMT = TORAMT + NETAMT
	DECMAL = (BUNPRC*BQTYBO) - (BUNPRC*BQTYBO*BLDISC/100)
	DECMAL = DECMAL - (DECMAL*BODISC/100)
	BORAMT = BORAMT + DECMAL
	IF (BORTYP.NE.'O') TBOAMT = TBOAMT + DECMAL
	IF (BORTYP.EQ.'O') TOSAMT = TOSAMT + DECMAL
	CALL PRINT
	GO TO RLOOP
PSUB,
	IF (LSTCUS.EQ.0) GO TO FIRST
	IF (CONTER.EQ.1) CALL PRINT
	IF (CONTER.EQ.1) GOTO NOSUB
	XCALL LINFD (1)
	INCR LINCNT
	PLINE (28,43) = 'CUSTOMER TOTALS:'
	PLINE (73,79) = TOTORD, MASK
	PLINE (81,87) = 'ORDERED'
	PLINE (99,105) = TOTQTY, MASK
	PLINE (107,117) = 'BACKORDERED'
	CALL PRINT
	PLINE (69,78) = LIT1
	PLINE (79,91) = ORDAMT,MASK2
	PLINE (98,106) = LIT2
	PLINE (107,119) = BORAMT,MASK2
	CALL PRINT
NOSUB,
	PLINE (1,30) = DASHES
	PLINE (31,60) = DASHES
	PLINE (61,90) = DASHES
	PLINE (91,120) = DASHES
	PLINE (121,132) = DASHES
	CALL PRINT
	XCALL LINFD (1)
	LINCNT = LINCNT + 1
	TOTORD =
	TOTQTY =
	ORDAMT =
	BORAMT =
	IF (ENDSW.EQ.1) RETURN
FIRST,
	INCR CUSCNT
	LSTCUS = BCUSNO
	PLINE (1,6) = BCUSNO
	CONTER =
	SAVNAM = BCUSNM
	RETURN
;**********************************************************
PRINT,
	IF (LPONSW.EQ.0) CALL PRNTON
	XCALL LPOUT(LINCNT,PGCNT,PLINE,TITLE,HDR1,HDR2,'NO HDR',LEGND1,
&		LEGND2,LEGND3,0,132,PRTCTL,0,LPSW,RPTNUM,PRTTYP)
	RETURN
PRNTON,
	SPLFIL (5,6) = 'EG'			; BACKORDER ITEMS - STOCKED
	IF (RPTYP.EQ.2) SPLFIL (6,6) = 'H'	; BACKORDER ITEMS - NON STOCKED
	IF (RPTYP.EQ.3) SPLFIL (6,6) = 'I'	; BACKORDER ITEMS - ALL
	IF (RPTYP.EQ.4) SPLFIL (6,6) = 'J'	; OPEN CUSTOMER ORDER - NON STKD
	IF (RPTYP.EQ.5) SPLFIL (6,6) = 'K'	; OPEN CUSTOMER ORDER - ALL
	LPSW = 1
	XCALL LPON (LPSW,SPLFIL)
	IF (LPSW.EQ.0) XCALL PGCHN ('CP:UNPRBO',1)
	LPARG = 2
	IF (LPSW.EQ.2) LPARG = 4
	XCALL WATE (LPARG,V)
	PGCNT = 0
	LINCNT = 61
	LPONSW = 1
	RETURN
;**********************************************************
EOF2,
	ENDSW = 1
	IF (CONTER.EQ.1) PLINE (1,25) = SAVNAM
	CALL PSUB
	LSTCUS =
	IF (LPONSW.EQ.0) XCALL MESAG ('NO RECORDS FIT THESE PARAMETERS',1)
	IF (STRTCS.NE.0.AND.LPONSW.EQ.1) XCALL LPOFF (LPSW,SPLFIL,PGCNT)
	IF (STRTCS.NE.0.AND.LPONSW.EQ.1) LPONSW = 0
	IF (STRTCS.NE.0) GO TO DISPLA
	LOKCTL = 1
	XCALL IO (6,BAKORD,1,READ,LOKCTL)
	PLINE (4,8) = CUSCNT, MASK
	PLINE (10,39) = 'CUSTOMERS REPORTED AT LOCATION'
	PLINE(41,42) = LOTN
	IF (LOTN.EQ.BLANKS) PLINE (32,44) = 'ALL LOCATIONS'
	IF (DATFLG.EQ.'R') PLINE(46,62) = 'REQUESTED BETWEEN'
	IF (DATFLG.EQ.'P') PLINE(47,62) = 'PROMISED BETWEEN'
	PLINE (64,71) = STDATE,DTMASK
	PLINE (73,75) = 'AND'
	PLINE (77,84) = ENDATE,DTMASK
	IF (STDATE.EQ.ENDATE) PLINE (56,84) = 'ON                           '
	IF (STDATE.EQ.ENDATE) PLINE (59,66) = STDATE,DTMASK
	IF (STDATE.EQ.0) PLINE(46,84) =
	PLINE (89,104) = 'TOTAL $ ORDERED:'
	PLINE (105,118) = TORAMT,MASK2
	LINCNT = LINCNT - 3
	CALL PRINT
	PLINE (90,104) = 'TOTAL $ ON B/O:'
	PLINE (105,118) = TBOAMT,MASK2
	CALL PRINT
	PLINE (93,104) = 'TOTAL $ O/S:'
	PLINE (105,118) = TOSAMT, MASK2
	CALL PRINT
END,
	IF (LPONSW.EQ.1) XCALL LPOFF (LPSW,SPLFIL,PGCNT)
	XCALL WATE (4,V)
	XCALL PGCHN ('CP:UNPRBO',1)
END