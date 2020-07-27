;prtbr2.dbl
;
;PRTBAR.CP
;

RECORD	COPTBL
	.INCLUDE 'DEF:RD182A.DEF'

RECORD	ITMMAS
	.INCLUDE 'DEF:RD041A.def'

RECORD	ITMKEY
	.INCLUDE 'DEF:RD041K.DEF'

RECORD	MM
	FM1	,A30
	FM2	,A30
	FM3	,A30

RECORD	PBUFF
	PLINE	,A80

RECORD	PARAM
	STCAT	,A2
	ENCAT	,A2
	STITM	,A15
	ENITM	,A15
	F1	,D3
	F2	,D3
	F3	,D5
	AF1	,A3
	AF2	,A3
	AF3	,A5

RECORD	PRINT
	PGCNT	,D5
	LINCNT	,D5
	HLINE	,A80

RECORD	CHANNEL
	CHN041	,D2
	CHN182	,D2

RECORD	VARS
	mmkey	,a2
	GA	,D2
	XGA	,D2
	DLEN	,D2
	TL	,D2
	LEN	,D2
	B_DATA	,A100
	B_STRNG	,A100
	LN	,D3
	OPNOK	,D1
	A5	,A5
	D5	,D5
	BLANKS	,A30
	ENTRY	,A30
	INXCTL	,D1
	CNGCTL	,D1
	WHATNO	,D2
	LOKCTL	,D1
	READ	,D1,0
	WRITE	,D1,1
	SWITCH	,D1
	V	,D1
;
PROC
	XCALL TERID(V)
	XCALL OUTPT (1,1,2,'PRINT INVENTORY BARCODE SHEETS - special',1)
;
	CALL OPENS
	IF (.NOT. OPNOK) GOTO ENDOFF

	HLINE(60,80) = 'COUNT'
DISPLA,	
	CLEAR CNGCTL
	XCALL OUTPT (1,1,2,'PRINT INVENTORY BARCODE SHEETS',1)
	XCALL OUTPT ( 4,5,0,'1. PRDCAT      THRU',1)
	XCALL OUTPT ( 6,5,0,'2. ITEM                   THRU',1)
	XCALL OUTPT ( 8,5,0,'3. F1 NOTE',1)
	XCALL OUTPT (10,5,0,'4. F2 NOTE',1)
	XCALL OUTPT (12,5,0,'5. F3 NOTE',1)
	XCALL OUTPT (14,5,0,'6. LENGTH',1)
	XCALL OUTPT (16,5,0,'7. GAUGE',1)

STCAT,
	XCALL INPUT (04,15,02,00,'AE',ENTRY,INXCTL,1)
	GOTO (DISPLA,ENDOFF),INXCTL
	STCAT = ENTRY(1,2)
	IF (STCAT .EQ. BLANKS)
	THEN	BEGIN
		ENCAT = 'ZZ'
		XCALL OUTPT (4,15,0,'ALL',1)
		END

	ELSE	BEGIN
		XCALL INPUT (04,25,02,00,'AE',ENTRY,INXCTL,1)
		GOTO (DISPLA,ENDOFF),INXCTL
		ENCAT = ENTRY(1,2)
		IF (ENCAT .EQ. BLANKS)
			BEGIN
			ENCAT = STCAT
			XCALL OUTPT (4,25,0,ENCAT,1)
			END
		END

	GOTO (ANYCN),CNGCTL
STITM,
	XCALL INPUT (06,13,15,00,'AE',ENTRY,INXCTL,1)
	GOTO (DISPLA,ENDOFF),INXCTL
	STITM = ENTRY(1,15)
	XCALL INPUT (06,36,15,00,'A ',ENTRY,INXCTL,1)
	GOTO (DISPLA),INXCTL
	ENITM = ENTRY(1,15)
	IF (ENITM .EQ. BLANKS)
		BEGIN
		ENITM = STITM
		XCALL OUTPT (6,36,0,ENITM,1)
		END
	GOTO (ANYCN),CNGCTL
F1,
	XCALL INPUT (08,17,03,00,'# ',ENTRY,INXCTL,1)
	GOTO (DISPLA),INXCTL
	AF1 = ENTRY(1,3)
	D5 = ENTRY(1,3)
	F1 = D5
	IF (AF1 .EQ. A5)
	THEN	XCALL OUTPT (8,17,1,'0   ',1)
	ELSE	BEGIN
		IF (D5 .NE. 0)
			BEGIN
			mmkey = 'M1'
			CALL MEMO_KEY
			XCALL OUTPT (8,24,0,MM_LONG,1)	
			END
		END
	GOTO (ANYCN),CNGCTL
F2,
	XCALL INPUT (10,17,03,00,'# ',ENTRY,INXCTL,1)
	GOTO (DISPLA),INXCTL
	AF2 = ENTRY(1,3)
	D5 = ENTRY(1,3)
	F2 = D5
	IF (AF2 .EQ. A5)
	THEN	XCALL OUTPT (10,17,1,'0   ',1)
	ELSE	BEGIN
		IF (D5 .NE. 0)
			BEGIN
			mmkey = 'M2'
			CALL MEMO_KEY
			XCALL OUTPT (10,24,0,MM_LONG,1)	
			END
		END
	GOTO (ANYCN),CNGCTL
F3,
	XCALL INPUT (12,17,03,00,'# ',ENTRY,INXCTL,1)
	GOTO (DISPLA),INXCTL
	AF3 = ENTRY(1,3)
	D5 = ENTRY(1,3)
	F3 = D5
	IF (AF3 .EQ. A5)
	THEN	XCALL OUTPT (12,17,1,'0  ',1)
	ELSE	BEGIN
		IF (D5 .NE. 0)
			BEGIN
			mmkey = 'M3'
			CALL MEMO_KEY
			XCALL OUTPT (12,24,0,MM_LONG,1)	
			END
		END
	GOTO (ANYCN),CNGCTL
LEN,	
	XCALL INPUT (14,17,02,00,'# ',ENTRY,INXCTL,1)
	GOTO (DISPLA),INXCTL
	LEN = ENTRY(1,2)
	GOTO (ANYCN),CNGCTL

GA,
	XCALL INPUT (16,17,02,00,'# ',ENTRY,INXCTL,1)
	GOTO (DISPLA),INXCTL
	GA = ENTRY(1,2)

ANYCN,
	XCALL ANYCN (CNGCTL, WHATNO)
	GOTO (PROCES, CNGBR), CNGCTL+1
CNGBR,
	GOTO (STCAT, STITM, F1, F2, F3, LEN, GA), WHATNO
	GOTO ANYCN
PROCES,
	CLEAR LINCNT
	CLEAR PGCNT

	OPEN (14,O,'SPL:PHY.SPL')
	WRITES (14,HLINE)

	CLEAR ITMKEY
	K_ITEM = STITM
	K_F1 = F1,	'XXX'
	K_F2 = F2,	'XXX'
	K_F3 = F3,	'XXXXX'

	FIND (CHN041, ITMMAS, STITM, KRF=1) [ERR=LOOP]
LOOP,
	READS (CHN041, ITMMAS, EOF)
	IF (PRDCAT.LT.STCAT .OR. PRDCAT.GT.ENCAT) GOTO LOOP
	IF (ITEMNO .GT. ENITM) GOTO EOF
;;;>	IF (STOCK .NE. 'S') GOTO LOOP

;;;	IF (AF1.NE.A5 .AND. IF1.NE.K_F1) GOTO LOOP
;;;	IF (AF2.NE.A5 .AND. IF2.NE.K_F2) GOTO LOOP
;;;	IF (AF3.NE.A5 .AND. IF3.NE.K_F3) GOTO LOOP

	IF (IF1.NE.K_F1) GOTO LOOP
	IF (IF2.NE.K_F2) GOTO LOOP
	IF (IF3.NE.K_F3) GOTO LOOP
	TL = %TRIM(ITEMNO)
	IF (TL .LT. 3) GOTO LOOP

	ONERROR NOT_NUM
	DLEN = ITEMNO(TL-1,TL)
	OFFERROR
	GOTO N_OK
NOT_NUM,
	OFFERROR
	GOTO LOOP
N_OK,
	IF (DLEN .NE. LEN) GOTO LOOP
	if (%instr(1,itemno,'+') ) goto loop	;skip inches

	ONERROR NOT_GA
	XGA = ITEMNO(5,6)
	OFFERROR
	GOTO GA_OK
NOT_GA,
	OFFERROR
	GOTO LOOP
GA_OK,
	IF (XGA .NE. GA) GOTO LOOP

	D5 = IF1
	mmkey = 'M1'
	CALL MEMO_KEY
	IF (LOKCTL.EQ.0) FM1 = MM_LONG

	D5 = IF2
	mmkey = 'M2'
	CALL MEMO_KEY
	IF (LOKCTL.EQ.0) FM2 = MM_LONG

	D5 = IF3
	mmkey = 'M3'
	CALL MEMO_KEY
	IF (LOKCTL.EQ.0) FM3 = MM_LONG

	B_DATA = "I" + ITEMNO + IF1 + IF2 + IF3
	XCALL B128 (B_DATA, B_STRNG, 70)
	LN = %TRIM (B_STRNG)
	PLINE (1,15) = ITEMNO
	PLINE (16,45) = DESCR
	if (lincnt .ge. 8) call newpag

	call print
	PLINE = FM1(1,%trim(fm1)) + FM2(1,%trim(fm2)) + FM3(1,%trim(fm3))
	call print
	call print
	PLINE  = B_STRNG(1,LN)
	incr lincnt
	call print
	XCALL OF128
	pline = b_data(2,28)
	pline (60,80) = '___________'
	call print
	call print
	call print

	GOTO LOOP
EOF,
	forms (14,0)
	CLOSE 14
	LPQUE ('SPL:PHY.SPL')

ENDOFF,
	CALL CLOSE
	XCALL PGCHN ('CP:PHYMNU',1)
	XCALL FLAGS (7000000)
	STOP
;===========================================================

MEMO_KEY,	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	CLEAR TBL_KEY
	TBLCOD = 'MM'
	TBLCOD = MMKEY
	MM_KEY = D5
	READ (CHN182,COPTBL,TBL_KEY)[ERR=NOT_KEY]
	RETURN
NOT_KEY,
	CLEAR COPTBL
	RETURN
;-------------------------------------------------------

print,	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	WRITES (14, PLINE)
	clear pline
	return
;------------------------------------------

newpag,	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	forms (14,0)
	writes (14,hline)

	clear lincnt
	incr pgcnt

	return
;------------------------------------------
OPENS,	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	CLEAR OPNOK
	
	SWITCH = 5
	XCALL FILES (1, 'SI', 041, SWITCH)	;ITMMAS.ISM
	IF (SWITCH .EQ. 9) RETURN
	CHN041 = 1

	SWITCH = 5
	XCALL FILES (2, 'SI', 182, SWITCH)
	IF (SWITCH .EQ. 9) RETURN
	CHN182 = 2

	OPNOK = 1
	RETURN
;----------------------------------------

CLOSE,	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

	IF (CHN041) CLOSE CHN041
	IF (CHN182) CLOSE CHN182

	RETURN
;----------------------------------------

END
