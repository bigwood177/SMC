; SAPCAT.COP
;
;
;
;		SALES ANALYSIS BY PRODUCT CATEGORY
;
;		CUSTOM FOR SHEET METAL CONNECTORS
;
;
;
RECORD INVMAS
		.INCLUDE 'DEF:RD041A.DEF'
RECORD DUMINV
		.INCLUDE 'DEF:RD041B.DEF'
RECORD SAPIDX
		.INCLUDE 'DEF:RD049A.DEF'
RECORD TITLE
		,A34, 'SALES ANALYSIS BY PRODUCT CATEGORY'
RECORD LEGND1
		,A9
RECORD HDR1
		,A3, 'CAT'
		,A4
		,A7, 'ITEM-NO'
		,A7
		,A16, 'ITEM DESCRIPTION'
		,A26
		,A3, 'QTY'
		,A7
		,A7, 'COST-OF'
		,A19
		,A7, '%-SALES'
		,A8
		,A5, 'GROSS'
		,A5
		,A8, '%-PROFIT'

RECORD HDR2
		,A43
		,A8, 'AVG-COST'
		,A11
		,A4, 'SOLD'
		,A8
		,A5, 'SALES'
		,A10
		,A5, 'SALES'
		,A6
		,A6, 'OF-CAT'
		,A8
		,A6, 'PROFIT'
		,A5
		,A6, 'OF-CAT'
		,A1

RECORD HDR3
		,A3, 'PRD'
		,A3
		,A1, '#'
		,A3
		,A23, '-----------------------'
		,A13, 'MONTH-TO-DATE'
		,A24, '------------------------'
		,A2
		,A24, '------------------------'
		,A12, 'YEAR-TO-DATE'
		,A24, '------------------------'

RECORD HDR4
		,A3, 'CAT'
		,A1
		,A5, 'ITEMS'
		,A1
		,A13, 'COST-OF-SALES'
		,A7
		,A5, 'SALES'
		,A5
		,A7, '%-SALES'
		,A2
		,A12, 'GROSS-PROFIT'
		,A2
		,A7, '%-PROFT'
		,A2
		,A13, 'COST-OF-SALES'
		,A8
		,A5, 'SALES'
		,A4
		,A7, '%-SALES'
		,A2
		,A12, 'GROSS-PROFIT'
		,A2
		,A7, '%-PROFT'

RECORD
	ENTRY	,A2
	INXCTL	,D1
	ENDSW	,D1
	LINE	,A25, '-------------------------'
	LSTCAT	,A2, ']]'
	MASK	,A14, 'ZZ,ZZZ,ZZZ.XX-'
	MASK2	,A11, 'ZZ,ZZZ,ZZX-'
	RDCTL	,D5
	RDCTL2	,D5
	CATCNT	,D2
	CTCSTM	,D10
	CTCSTY	,D10
	CTPCPM	,D5
	CTPCPY	,D5
	CTPCSM	,D5
	CTPCSY	,D5
	CTPRFM	,D10
	CTPRFY	,D10
	CTQTYM	,D7
	CTQTYY	,D8
	CTSLSM	,D10
	CTSLSY	,D10
	ITMCNT	,D5
	ITMPFM	,D10
	ITMPFY	,D10
	PCTPFM	,D5
	PCTPFY	,D5
	PCTSLM	,D5
	PCTSLY	,D5
	TCSTM	,D10
	TCSTY	,D10
	TOTITM	,D5
	TPCPFM	,D5
	TPCPFY	,D5
	TPCSLM	,D5
	TPCSLY	,D5
	TPRFM	,D10
	TPRFY	,D10
	TSLSM	,D10
	TSLSY	,D10
	LINCNT	,D2,60
	PGCNT	,D3
	PLINE	,A132
	PRTCTL	,D3
	LPSW	,D2
	LPARG	,D1
	SPLFIL	,A14
	RPTNUM	,D3
	PRTTYP	,A1
	SWITCH	,D1
	V	,D1
	READ	,D1	,0
	WRITE	,D1	,1
	LOKCTL	,D1
	SUMMM	,D1,0
;;;	NOPRINT	,D1,1
PROC
	XCALL TERID (V)
	XCALL OUTPT (2,1,0,'PRINT OUT',1)
	SPLFIL (5,6) = 'EM'
	LPSW = 1
	XCALL LPON(LPSW,SPLFIL)
	IF (LPSW.EQ.0) XCALL PGCHN ('CP:UNPRSA',1)
	LPARG = 2
	IF (LPSW.EQ.2) LPARG = 4
	SUMMM = 0
	XCALL OUTPT ( 12,10,0,' DO YOU WANT ONLY SUMMARY PAGE ',1)
	XCALL INPUT ( 12,41,01,00,'A',ENTRY,INXCTL,1 )
	IF ( ENTRY( 1,1 ).EQ.'Y' ) SUMMM = 1
	XCALL WAIT (LPARG,V)
	SWITCH = 1
	XCALL FILES(1,'I',41,SWITCH)		;FILE # 41 -- INVMAS FILE
	IF (SWITCH.EQ.9) GO TO END
	LOKCTL = 1
	XCALL IO (1,DUMINV,1,READ,LOKCTL)
	SWITCH = 5
	XCALL FILES (9,'I',49,SWITCH)		;FILE # 49 -- SAPIDX FILE
	LEGND1 = 'NO LEGEND'
	RDCTL = 1

RDIDX,
	INCR RDCTL
	LOKCTL = 1
	XCALL IO (9,SAPIDX,RDCTL,READ,LOKCTL)
	IF (SRECNO.EQ.0) GOTO RDIDX
	IF (SPRCAT.EQ.']]') GO TO EOFIDX
	IF (SPRCAT.NE.LSTCAT) CALL NEWCAT
	LOKCTL = 1
	XCALL IO (1,INVMAS,SRECNO,READ,LOKCTL)
	PLINE (1,2) = PRDCAT
	IF (PRDCAT.EQ.'  ') PLINE (1,4) = '(BL)'
;;;	IF (ITEMNO.EQ.'SPV361020') NOPRINT =
	PLINE (6,20) = ITEMNO
	PLINE (22,51) = DESCR
	PLINE (55,58) = 'MTD:'
	PLINE (61,67) = QTYMTD, MASK2
	PLINE (72,82) = CSTMTD, MASK
	PLINE (87,97) = SLSMTD, MASK
	PCTSLM =
	ON ERROR DIV0A
	PCTSLM = (SLSMTD*100000/CTSLSM) #1

DIV0A,
	OFFERROR
	PLINE (101,107) = PCTSLM, MASK
	ITMPFM = SLSMTD - CSTMTD
	PLINE (112,122) = ITMPFM, MASK
	PCTPFM =
	ON ERROR DIV0B
	PCTPFM = (ITMPFM*100000/CTPRFM) #1

DIV0B,
	OFFERROR
	PLINE (126,132) = PCTPFM, MASK
	IF ( SUMMM.EQ.0 ) CALL PRINT
	PLINE =
	PLINE (42,51) = AVGCST, 'ZZ,ZZZ.XXX'
	PLINE (55,58) = 'YTD:'
	PLINE (60,67) = QTYYTD, MASK2
	PLINE (72,82) = CSTYTD, MASK
	PLINE (87,97) = SLSYTD, MASK
	PCTSLY =
	ON ERROR DIV0C
	PCTSLY = (SLSYTD*100000/CTSLSY) # 1

DIV0C,
	OFFERROR
	PLINE (101,107) = PCTSLY, MASK
	ITMPFY = SLSYTD - CSTYTD
	PLINE (112,122) = ITMPFY, MASK
	PCTPFY =
	ON ERROR DIV0D
	PCTPFY = (ITMPFY*100000/CTPRFY) #1

DIV0D,
	OFFERROR
	PLINE (126,132) = PCTPFY, MASK
	IF ( SUMMM.EQ.0 ) CALL PRINT
	INCR ITMCNT
	CTQTYM = CTQTYM + QTYMTD
	CTQTYY = CTQTYY + QTYYTD
	CTPCSM = CTPCSM + PCTSLM
	CTPCSY = CTPCSY + PCTSLY
	CTPCPM = CTPCPM + PCTPFM
	CTPCPY = CTPCPY + PCTPFY
	IF ( SUMMM.EQ.0 )
		BEGIN
			XCALL LINFD (1)
			INCR LINCNT
		END
	GO TO RDIDX

NEWCAT,
	IF (LSTCAT.EQ.']]') GO TO NXTTOT
	PLINE (58,82) = LINE
	PLINE (83,107) = LINE
	PLINE (108,132) = LINE
	IF ( SUMMM.EQ.0 )
		BEGIN
			CALL PRINT
			LINCNT = LINCNT - 2
			PLINE (5,12) = 'CATEGORY'
			PLINE (16,21) = ITMCNT, MASK2
			PLINE (22,26) = 'ITEMS'
			PLINE (52,55) = 'MTD:'
			PLINE (58,67) = CTQTYM, MASK2
			PLINE (69,82) = CTCSTM, MASK
			PLINE (84,97) = CTSLSM, MASK
			PLINE (101,107) = CTPCSM, MASK
			CTPRFM = CTSLSM - CTCSTM
			PLINE (109,122) = CTPRFM, MASK
			PLINE (126,132) = CTPCPM, MASK
			CALL PRINT
			PLINE (7,13) = 'TOTALS:'
			PLINE (52,55) = 'YTD:'
			PLINE (57,67) = CTQTYY, MASK2
			PLINE (69,82) = CTCSTY, MASK
			PLINE (84,97) = CTSLSY, MASK
			PLINE (101,107) = CTPCSY, MASK
			CTPRFY = CTSLSY - CTCSTY
			PLINE (109,122) = CTPRFY, MASK
			PLINE (126,132) = CTPCPY, MASK
			CALL PRINT
		END
	TCSTM = TCSTM + CTCSTM
	TCSTY = TCSTY + CTCSTY
	TSLSM = TSLSM + CTSLSM
	TSLSY = TSLSY + CTSLSY
	TPRFM = TPRFM + CTPRFM
	TPRFY = TPRFY + CTPRFY
	ITMCNT =
	CTQTYM =
	CTQTYY =
	CTCSTM =
	CTCSTY =
	CTSLSM =
	CTSLSY =
	CTPCSM =
	CTPCSY =
	CTPRFM =
	CTPRFY =
	CTPCPM =
	CTPCPY =
	IF ( SUMMM.EQ.0 )
		BEGIN
			XCALL LINFD (2)
			LINCNT = LINCNT + 4
		END
	IF (ENDSW.EQ.1) RETURN

NXTTOT,
	LSTCAT = SPRCAT
	RDCTL2 = RDCTL - 1

ACCUM,
	INCR RDCTL2
	LOKCTL = 1
	XCALL IO (9,SAPIDX,RDCTL2,READ,LOKCTL)
	IF (SRECNO.EQ.0) GOTO ACCUM
	IF (SPRCAT.NE.LSTCAT.OR.SPRCAT.EQ.']]') GO TO ENDNXT
	LOKCTL = 1
	XCALL IO (1,INVMAS,SRECNO,READ,LOKCTL)
	CTCSTM = CTCSTM + CSTMTD
	CTCSTY = CTCSTY + CSTYTD
	CTSLSM = CTSLSM + SLSMTD
	CTSLSY = CTSLSY + SLSYTD
	GO TO ACCUM

ENDNXT,
	CTPRFM = CTSLSM - CTCSTM
	CTPRFY = CTSLSY - CTCSTY
	LOKCTL = 1
	XCALL IO (9,SAPIDX,RDCTL,READ,LOKCTL)
	RETURN

EOFIDX,
	ENDSW = 1
	CALL NEWCAT

SUMMRY,
	IF (LPSW.LT.0) SLEEP 2
	IF (LPSW.LT.0) LPSW = -LPSW
	LSTCAT = ']]'
	LINCNT = 60
	LEGND1 = 'SUMMARY'
	HDR1 = HDR3
	HDR2 = HDR4
	RDCTL = 1

RDIDX2,
	INCR RDCTL
	LOKCTL = 1
	XCALL IO (9,SAPIDX,RDCTL,READ,LOKCTL)
	IF (SRECNO.EQ.0) GOTO RDIDX2
	IF (SPRCAT.NE.LSTCAT) CALL NEWCT2
	IF (SPRCAT.EQ.']]') GO TO ENDSUM
	LOKCTL = 1
	XCALL IO (1,INVMAS,SRECNO,READ,LOKCTL)
	INCR ITMCNT
	CTCSTM = CTCSTM + CSTMTD
	CTCSTY = CTCSTY + CSTYTD
	CTSLSM = CTSLSM + SLSMTD
	CTSLSY = CTSLSY + SLSYTD
	GO TO RDIDX2

NEWCT2,
	IF (LSTCAT.EQ.']]') GO TO ENDNW2
	PLINE (1,2) = LSTCAT
	IF (LSTCAT.EQ.'  ') PLINE (1,4) = '(BL)'
	PLINE (5,9) = ITMCNT, 'ZZZZX'
	PLINE (11,24) = CTCSTM, MASK
	PLINE (26,39) = CTSLSM, MASK
	PCTSLM =
	ON ERROR DIV0E
	PCTSLM = (CTSLSM*100000/TSLSM) #1

DIV0E,
	OFFERROR
	PLINE (41,47) = PCTSLM, MASK
	CTPRFM = CTSLSM - CTCSTM
	PLINE (49,62) = CTPRFM, MASK
	PCTPFM =
	ON ERROR DIV0F
	PCTPFM = (CTPRFM*100000/TPRFM) #1

DIV0F,
	OFFERROR
	PLINE (64,70) = PCTPFM, MASK
	PLINE (73,86) = CTCSTY, MASK
	PLINE (88,101) = CTSLSY, MASK
	PCTSLY =
	ON ERROR DIV0G
	PCTSLY = (CTSLSY*100000/TSLSY) #1

DIV0G,
	OFFERROR
	PLINE (103,109) = PCTSLY, MASK
	CTPRFY = CTSLSY - CTCSTY
	PLINE (111,124) = CTPRFY, MASK
	PCTPFY =
	ON ERROR DIV0H
	PCTPFY = (CTPRFY*100000/TPRFY) #1

DIV0H,
	OFFERROR
	PLINE (126,132) = PCTPFY, MASK
	CALL PRINT
	PLINE =
	INCR CATCNT
	TOTITM = TOTITM + ITMCNT
	TPCSLM = TPCSLM + PCTSLM
	TPCSLY = TPCSLY + PCTSLY
	TPCPFM = TPCPFM + PCTPFM
	TPCPFY = TPCPFY + PCTPFY
	XCALL LINFD (1)
	LINCNT = LINCNT + 1
	ITMCNT =
	CTCSTM =
	CTCSTY =
	CTSLSM =
	CTSLSY =

ENDNW2,
	LSTCAT = SPRCAT
	RETURN

PRINT,
;;;	IF (NOPRINT) PLINE =
;;;	IF (NOPRINT) RETURN
	XCALL LPOUT(LINCNT,PGCNT,PLINE,TITLE,HDR1,HDR2,'NO HDR3',
&		LEGND1,'NO LEGEND2',' ',0,132,PRTCTL,1,LPSW,RPTNUM,PRTTYP)
	RETURN

ENDSUM,
	CALL NEWCT2
	PLINE (1,13) = 'GRAND TOTALS:'
	CALL PRINT
	LINCNT = LINCNT - 2
	XCALL LINFD (1)
	PLINE (4,5) = CATCNT
	PLINE (7,16) = 'CATEGORIES'
	CALL PRINT
	XCALL LINFD (1)
	PLINE (4,10) = TOTITM, MASK2
	PLINE (11,24) = TCSTM, MASK
	PLINE (26,39) = TSLSM, MASK
	PLINE (41,47) = TPCSLM, MASK
	PLINE (49,62) = TPRFM, MASK
	PLINE (64,70) = TPCPFM, MASK
	PLINE (73,86) = TCSTY, MASK
	PLINE (88,101) = TSLSY, MASK
	PLINE (103,109) = TPCSLY, MASK
	PLINE (111,124) = TPRFY, MASK
	PLINE (126,132) = TPCPFY, MASK
	CALL PRINT
	IF (CATCNT.EQ.0) GO TO END
	XCALL LINFD (1)
	LINCNT = LINCNT + 3
	PLINE (1,18) = 'CATEGORY AVERAGES:'
	CALL PRINT
	XCALL LINFD (1)
	LINCNT = LINCNT - 1
	PLINE (4,10) = (TOTITM*10/CATCNT), 'Z,ZZZ.X'
	PLINE (11,24) = (TCSTM*10/CATCNT) #1, MASK
	PLINE (26,39) = (TSLSM*10/CATCNT) #1, MASK
	PLINE (41,47) = (TPCSLM*10/CATCNT) #1, MASK
	PLINE (49,62) = (TPRFM*10/CATCNT) #1, MASK
	PLINE (64,70) = (TPCPFM*10/CATCNT) #1, MASK
	PLINE (73,86) = (TCSTY*10/CATCNT) #1, MASK
	PLINE (88,101) = (TSLSY*10/CATCNT) #1, MASK
	PLINE (103,109) = (TPCSLY*10/CATCNT) #1, MASK
	PLINE (111,124) = (TPRFY*10/CATCNT) #1, MASK
	PLINE (126,132) = (TPCPFY*10/CATCNT) #1, MASK
	CALL PRINT

END,
	XCALL LPOFF(LPSW,SPLFIL,PGCNT)
	CLOSE 9
	SWITCH = 7
	XCALL FILES(9,'I',49,SWITCH)		;DELETE SAPIDX FILE -- #49
	IF (SWITCH.NE.9) XCALL FILES(1,'I',41,4)
	XCALL PGCHN ('CP:UNPRSA',1)
	END
