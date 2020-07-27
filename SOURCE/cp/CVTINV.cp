RECORD ITMIDX
			;ITEM MASTER INDEX FILE "RD042A.DEF"
		;	RECORD SIZE	= 022
		;	DEVICE FILE #	= 042
		;	FILE NAME	= "ITMIDX"
		;
		; NOTE: FILE IS NORMALLY SORTED 
		;       IN ITEM NUMBER SEQUENCE.
		;
	IITMNO	,A15  		; KEY - ITEM NUMBER
	IRC041	,D5   		; RELATIVE RECORD # IN "ITMMAS" FILE
	IPRCAT	,A2   		; PRODUCT CATEGORY
;:
RECORD NEWITM
		,A175
	UCCNUM	,D5		; UCC BAR CODE NUMBER
		,A15		; FILLER
RECORD ITMMAS	,X
		; ITEM MASTER RECORD DEFINITION  "RD041A.DEF"
		;	RELEASE 1.1
		;	RECORD SIZE	= 195
		;	DEVICE FILE#	= 041
		;	FILE NAME	= "ITMMAS"
	ITEMNO	,A15		; ITEM NUMBER
	DESCR	,A30		; DESCRIPTION
	PRDCAT	,A2		; PRODUCT CATEGORY
	USRDEF	,A2		; USER-DEFINED FIELD
	AVGCST	,D9		; AVERAGE COST		($ XXX,XXX.XXX)
	PRICCD	,1A2		;   PRICE CODE
	PRICE	,1D9		;   SELLING PRICE ARRAY	($ XXX,XXX.XXX)
	LOC	,1A2		;   LOCATION CODE
	QTYONH	,1D6		;   QUANTITY ON HAND	(XXX,XXX-)
	QTYCOM	,1D6		;   QUANTITY COMMITTED	(XXX,XXX)
	QTYONO	,1D6		;   QUANTITY ON ORDER	(XXX,XXX-)
	REOLVL	,1D5		; REORDER LEVEL		(XX,XXX)
	ORDUPT	,1D6		; ORDER UP-TO QUANTITY	(XXX,XXX)
	PIKSEQ	,1A2		; ITEM PICKING SEQUENCE
	STOCK	,A1		; STOCK / NONSTOCK FLAG "S" OR "N"
				;
	WEIGHT	,D6		; ITEM WEIGHT			(X,XXX.XX)
	SUOFM	,A2		; SELLING UNIT OF MEASURE
	USEMTD	,D7		; USAGE MONTH-TO-DATE
	USEYTD	,D7		; USAGE YEAR-TO-DATE
	QTYMTD	,D7		; QTY SOLD MONTH-TO-DATE	(XXX,XXX)
	QTYYTD	,D7		; QTY SOLD YEAR-TO-DATE		(XXX,XXX)
	SLSMTD	,D8		; SALES $ MONTH-TO-DATE		(XXX,XXX.XX)
	SLSYTD	,D9		; SALES $ YEAR-TO-DATE		(X,XXX,XXX.XX)
	CSTMTD	,D8		; COST MONTH-TO-DATE		(XXX,XXX.XX)
	CSTYTD	,D9		; COST YEAR-TO-DATE		(X,XXX,XXX.XX)
	BOCODE	,D1		; BACK ORDER CODE
	TXFLAG	,A1		; TAX FLAG
				;  "Y" = TAXABLE ITEM
				;  "N" = NON-TAXABLE ITEM
;:
RECORD NEWCTL
		,A20
	ITMCTL	,A175
RECORD	,X
		,A20
		;ITEM MASTER CONTROL RECORD "RD041B.DEF"
		;	RELEASE 1.1
		;	RECORD SIZE	= 175
		;	DEVICE FILE #	= 041
		;	FILE NAME	= "ITMMAS"
		;
		,A79		; (FILLER)
	SPCFLG	,D1		;RESET POINTERS IN SPC FLAG
				; 1 = RESET, 0 = DO NOT RESET
	JSTIFY	,D1		; RIGHT JUSTIFY NUMERIC ITEM NUMBERS (1=YES)
	DFLTLO	,A2		; DEFAULT LOCATION
				;
		,A65
				;
	TYPSYS	,D1		; SYSTEM TYPE (DEFINED AT FILE INITIALIZATION)
				; 1 = IM INSTALLED ONLY
				; 2 = IM AND COP
				; 3 = IM AND BOMP
				; 4 = IM, BOMP, AND COP INSTALLED
	NUMPRC	,D2		; DIMENSION OF PRICING ARRAY.
	NUMLOC	,D2		; DIMENSION OF LOCATIONS ARRAY.
	NUMVEN	,D2		; DIMENSION OF VENDORS ARRAY.
	DFL041	,D1		; DELETION FLAG
	SFL041	,D1		; SORTING FLAG
	ORG041	,D5		; ORGANIZED RECORD COUNT
	REC041	,D5		; RECORD COUNT
	MAX041	,D5		; MAXIMUM RECORDS ALLOWED COUNT
	DEL041	,D3		; NUMBER OF DELETED RECORDS IN THE FILE
;:
RECORD
	RECNO	,D5
	TITEM	,A15
PROC (15)
	OPEN (15,I,'TT:')
	OPEN (1,I,'SMC:ITMMAS.SMC')
	OPEN (2,I,'SMC:ITMIDX.SMC')
	OPEN (21,O,'ITMMAS.NEW')
	OPEN (22,O,'ITMIDX.NEW')
RDHDR,
	READ (1,ITMCTL,1)
	WRITES (21,NEWCTL)
	READS (2,ITMIDX)
	ITMIDX =
	WRITES (22,ITMIDX)
	RECNO = 1	
RDLOOP,
	READS (2,ITMIDX,EOF)
	IF (ITMIDX.EQ.']]]]]]]]]]') GOTO BRACK
	IF (IRC041.EQ.0) 
	BEGIN
	  DEL041 = DEL041 - 1
	  MAX041 = MAX041 - 1
	  GOTO RDLOOP
	END
	READ (1,ITMMAS,IRC041)
	INCR RECNO
	UCCNUM = RECNO
	WRITES (21,NEWITM)
	IRC041 = RECNO
	WRITES (22,ITMIDX)
	IF (IITMNO.NE.'SP'.AND.IITMNO.NE.'SPV') GOTO RDLOOP
	IF (IITMNO(5,6).EQ.'20'.OR.IITMNO(3,4).EQ.'CC'.OR.IITMNO(3,3).EQ.'H')
&		GOTO RDLOOP
	TITEM = IITMNO
	IF (TITEM(1,3).EQ.'SPV')
	THEN 
	BEGIN
	  IITMNO = 'SX'
	  IITMNO(3,4) = TITEM(4,5)
	  IITMNO(5,6) = TITEM(8,9)
	END
	ELSE
	BEGIN
	  IITMNO = 'SG'
	  IITMNO(3,4) = TITEM(3,4)
	  IITMNO(5,6) = TITEM(7,8)
	END
	ITEMNO = IITMNO
	SUOFM = 'EA'
	USEMTD =
	USEYTD =
	QTYMTD =
	QTYYTD =
	SLSMTD =
	SLSYTD =
	CSTMTD =
	CSTYTD =
	INCR RECNO
	UCCNUM = RECNO
	IRC041 = RECNO
	WRITES (21,NEWITM)
	WRITES (22,ITMIDX)
	GOTO RDLOOP
BRACK,
	READ (1,ITMMAS,MAX041)
	ITMMAS(176,195) = ITMIDX
	WRITES (21,NEWITM)
	WRITES (22,ITMIDX)
	GOTO RDLOOP
EOF,
	CLOSE 1
	CLOSE 2
	CLOSE 21
	CLOSE 22
	OPEN (21,U,'ITMMAS.NEW')
	MAX041 = MAX041 + RECNO - REC041 + 1
	REC041 = RECNO
	ORG041 = 1
	WRITE (21,NEWCTL,1)
	CLOSE 21
	STOP
END
