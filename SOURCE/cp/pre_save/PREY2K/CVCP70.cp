;  CVCP70 / COP 
;
;		
RECORD OLDHDR
	TORDNO	,D6	; ORDER NUMBER
		,A2
	TCUSCD	,A2	; CUSTOMER TYPE CODE
	TORDDT	,D6	; ORDER DATE (MM/DD/YY)
	TCUSNO	,D6	; CUSTOMER NUMBER
	TCUSNM	,A25	; CUSTOMER NAME
	TSHPNM	,A25	; SHIP-TO-NAME
	TSHAD1	,A25	; SHIP-TO ADDRESS LINE 1
	TSHAD2	,A21	; SHIP-TO ADDRESS LINE 2
	TSHAD3	,A29	; SHIP-TO ADDRESS LINE 3
	TPONO	,A10	; CUSTOMER'S PURCHASE ORDER NUMBER
	TJOBNO	,A10	; JOB NUMBER
	TCLPPD	,D1	; COLLECT OR PREPAID CODE
	TTERMS	,D1	; TERMS OF PAYMENT CODE
	TTRMSD	,D2	; TERMS DISCOUNT PERCENTAGE (X.X%)
	TDSCAL	,D6	; TERMS DISCOUNT ALLOWED ($X,XXX.XX)
		,D1	; SHIP VIA CODE -  OLD FIELD NOT USED --- SEE BELOW
	TINVNO	,D6	; INVOICE NUMBER
	TINVDT	,D6	; INVOICE DATE (MM/DD/YY)
	TSALE	,D8	; AMOUNT OF SALE ($XXX,XXX.XX)
	TARACT	,D7	; A/R ACCOUNT NUMBER (XXXX-XXX)
	TMISC	,D6	; MISCELLANEOUS CHARGE AMOUNT ($X,XXX.XX)
	TMSACT	,D7	; MISCELLANEOUS CHARGES ACCOUNT NUMBER (XXXX-XXX)
	TTAX	,D7	; SALES TAX AMOUNT ($XX,XXX.XX)
	TTXACT	,D7	; SALES TAX ACCOUNT NUMBER (XXXX-XXX)
	TFRGHT	,D6	; FREIGHT CHARGES AMOUNT ($X,XXX.XX)
	TFRACT	,D7	; FREIGHT CHARGES ACCOUNT NUMBER (XXXX-XXX)
	TDISC	,D2	; ORDER DISCOUNT PERCENTAGE (XX%)
	TSLMAN	,D2	; SALESMAN NUMBER
	TCOMNT	,2A34	; ORDER COMMENTS
	TPICK	,D2	; PICKING TICKET PRINTED ( 01 = YES )
	TCOST	,D8	; COST OF ORDER ($XXX,XXX.XX)
	TCOMDU	,D7	; COMMISSION DUE ($XX,XXX.XX)
	TFLAG	,D1	; SELECTED FOR BILLING FLAG (0=NOT SELECTED,1=SELECTED
			;                            2=INVOICE PRINTED)
	TRDTYP	,A1	; ORDER TYPE
	TRDSEQ	,D2	; ORDER SEQUENCE
	TSTTAX	,A2	; STATE TAX CODE FOR COMPUTING TAX 	
	TSHVIA	,D2	; NEW SHIP VIA CODE
	TPROMD	,D6	; PROMISED DATE
	TSHDAT	,D6	; SHIP DATE	

RECORD	,X
		,A27
	ORDCOM	,2A35	; DEFAULT COMMENTS
		,A85
	LSTORD	,D6	; LAST ORDER NUMBER USED
		,D6
		,A107	
	ODSTFL	,A1	; G/L DISTRIBUTION FLAG ("Y" OR "N")
	OMLAR	,A1	; MULTIPLE A/R ACCOUNTS FLAG ("Y" OR "N")
	ODEFAR	,D7	; DEFAULT A/R ACCOUNT NUMBER (XXXX-XXX)
	OMLMSC	,A1	; MULTIPLE MISCELLANEOUS ACCOUNTS FLAG ("Y" OR "N")
	ODEFMS	,D7	; DEFAULT MISCELLANEOUS ACCOUNT NUMBER (XXXX-XXX)
	OMLTAX	,A1	; MULTIPLE SALES TAX ACCOUNT FLAG  ("Y" OR "N")
	ODEFTX	,D7	; DEFAULT SALES TAX ACCOUNT NUMBER (XXXX-XXX)
	OMLFRT	,A1	; MULTIPLE FREIGHT ACCOUNTS FLAG ("Y" OR "N")
	ODEFRT	,D7	; DEFAULT FREIGHT ACCOUNT NUMBER (XXXX-XXX)
		,A2
	ORG044	,D5	; ORGANIZED RECORDS COUNT
	REC044	,D5	; RECORD COUNT
	MAX044	,D5	; MAXIMUM RECORDS ALLOWED COUNT
	DEL044	,D3	; NUMBER OF DELETED RECORDS IN FILE
RECORD ,X	; OLD CUST ORD HED CONTROL
		;  RECORD SIZE = 342	FILE # 44
	OHDBRK	,A6
;
RECORD ORDHDR		; REC SIZE 396
		.INCLUDE 'DEF:RD044A.DEF'
;
RECORD OLDLIN
	DORDNO	,D6	; ORDER NUMBER
	DITMNO	,A15	; ITEM NUMBER
	DDESCR	,A30	; ITEM DESCRIPTION
	DQTYOR	,D5	; QUANTITY ORDERED
	DQTYSH	,D5	; QUANTITY SHIPPED
	DQTYBO	,D5	; QUANTITY BACK ORDERED
	DPRDCD	,A2	; PRODUCT CATEGORY
	DUOFM	,A2	; UNIT OF MEASURE
	DPRICE	,D8	; PRICE ($XX,XXX.XXX)
	DODISC	,D2	; ORDER DISCOUNT (XX%)
	DDISC	,D2 	; LINE DISCOUNT (XX%)
	DSTATS	,D1	; LINE STATUS (1=BACKORDER STATUS, B/Oable item,
			;	       2=BACKORDER STATUS, Non-B/Oable item.)
	DCOST	,D7	; UNIT COST ($XX,XXX.XX)
	DFLAG	,D1	; SELECT FOR BILLING FLAG (0=NOT SELECTED, 1=SELECTED
		       	;       2=INVOICED, 3=REMOVED FROM FILE)
	DITMWT	,D6	; ITEM WEIGHT (X,XXX.XX)
	DTXFLG	,D1	; ITEM TAX FLAG (0=NON-TAXABLE, 1=TAXABLE)
	DINSEQ	,D2
		,A8	; UNUSED

RECORD DUMLIN
		,A90	; UNUSED
	DOR045	,D5	; ORGANIZED RECORDS COUNT
	DRC045	,D5	; RECORD COUNT
	DMX045	,D5	; MAXIMUM RECORDS COUNT
	DDL045	,D3	; NUMBER OF DELETED RECORDS IN FILE
;
RECORD  ,X		; OLD CUST ORD LINE CONTROL REC SIZE 110
	OLNBRK	,A6
;
RECORD ORDLIN		; REC SIZE 122 REL. 7.0
		.INCLUDE 'DEF:RD045A.DEF'
RECORD	,X
		.INCLUDE 'DEF:RD045D.DEF'
;
RECORD OLDDUC
	ODDUCTOR	,D6	; Order number --- 000000 === DELETE FIELDB
	ODDUTYPE	,D1	; Type of duct 1-GALV,2-ALUM,3-STAIN STEEL,4-OTHER
	ODGAUGE	,D2	; Gauge ( 26,24,22,20,18 )
	ODCAT	,D1	; Catagory 1-LSHAP,2-WRAPAROUND,3-4 PC,4-OTHER
	ODSTY	,D1	; Style 1-SLIP/DRIVE,2-TDC,3-NEXUS,4-OTHER
	ODSEAM	,D1	; Seam  1-SNAP/LOCK,2-PITTSBURG
	ODSEAL	,D1	; Sealnant 1-YES,2-NO
	ODJOINT	,D5	; Number of joints ( quantity)
	ODSIZ1	,D3	; SLIP
	ODSIZ2	,D2	; DRIVE
	ODSIZ3	,D2	; LENGTH
	ODLINER	,D1	; Liner 1-
	ODLOCAT	,A10	; Location ( comment )
	ODACC	,D1	; Accessories 1-YES,2-NO
	ODSLIPS	,D5	; Quantity of slips
	ODSLPITM	,A15	; Slip item number ( from inventory )
	ODSLPPRC	,D8	; Price of the slip ( from inventory  XXXXX.XXX
	ODSLPDES	,A30	; Description of slip from inventory
	ODDRIVES	,D5	; Quantity of drives
	ODDRVITM	,A15	; Drive item number ( from inventory )
	ODDRVPRC	,D8	; Price of the drive ( from inventory  XXXXX.XXX
	ODDRVDES	,A30	; Description of drive from inventory
	ODSQFEET	,D6	; Square feet of material ( calculated )
	ODPOUNDS	,D6	; Pounds of material ( calculated )
	ODSQFLIN	,D6	; Square feet of liner 
	ODTCORN	,D5	; Quantity of corners
	ODCORITM	,A15	; Corner item number ( from inventory )
	ODCORPRC	,D8	; Price of the corner ( from inventory  XXXXX.XXX
	ODCORDES	,A30	; Description of corner from inventory
	ODDUTT	,A1	; Type of duct O = order, E = estimate
	ODTNBITM	,A15	; item number ( from inventory )
	ODTNBQTY	,D5	; Quantity of TDC nuts/bolts
	ODTNBPRC	,D8	; Price of TDC nuts/bolts ( from inventory  XXXXX.XXX
	ODTNBDES	,A30	; Description of nut/bolts from inventory
	ODTGAITM	,A15	; item number ( from inventory )
	ODTGAQTY	,D5	; Quantity of gasket ( in feet )
	ODTGAPRC	,D8	; Price of gasket ( from inventory  XXXXX.XXX
	ODTGADES	,A30	; Description of gasket inventory
	ODTCLITM	,A15	; item number ( from inventory )
	ODTCLQTY	,D5	; Quantity of cleats
	ODTCLPRC	,D8	; Price of cleat ( from inventory  XXXXX.XXX
	ODTCLDES	,A30	; Description of cleat from inventory
	ODTBAITM	,A15	; item number ( from inventory ) 
	ODTBAQTY	,D5	; Quantity of TDC Bar (in feet)
	ODTBAPRC	,D8	; Price of TDC bar ( from inventory  XXXXX.XXX
	ODTBADES	,A30	; Description of bar from inventory
	ODTBNITM	,A15	; item number ( from inventory )
	ODTBNQTY	,D5	; Quantity of TDC nuts/bolts
	ODTBNPRC	,D8	; Price of TDC bar nut/bolt( from inventory  XXXXX.XXX
	ODTBNDES	,A30	; Description of bar nut/bolt from inventory
	ODGPRICE	,D8	; Price per pound of material
	ODLINPRC	,D8	; Price per square feet of liner 
		,A10	; Filler
		,D10	; Filler
;
RECORD DUCACC
		.INCLUDE 'DEF:RD065A.DEF'
;
RECORD OLDITM
		;	RECORD SIZE	= 120
		;	DEVICE FILE#	= 041
		;	FILE NAME	= "INVMAS"
	OIITEMNO	,A15	; ITEM NUMBER
	OIDESCR		,A30	; DESCRIPTION
	OIPRDCAT	,A2	; PRODUCT CATEGORY
	OIAVGCST	,D9	; AVERAGE COST		($ XXX,XXX.XXX)
	OIPRICE		,D8	; SELLING PRICE ARRAY	($ XXX,XXX.XX)
	OIWEIGHT	,D6	; ITEM WEIGHT			(X,XXX.XX)
	OISUOFM		,A2	; SELLING UNIT OF MEASURE
	OIQTYMTD	,D6	; QTY SOLD MONTH-TO-DATE	(XXX,XXX)
	OIQTYYTD	,D6	; QTY SOLD YEAR-TO-DATE		(XXX,XXX)
	OISLSMTD	,D8	; SALES $ MONTH-TO-DATE		(XXX,XXX.XX)
	OISLSYTD	,D9	; SALES $ YEAR-TO-DATE		(X,XXX,XXX.XX)
	OICSTMTD	,D8	; COST MONTH-TO-DATE		(XXX,XXX.XX)
	OICSTYTD	,D9	; COST YEAR-TO-DATE		(X,XXX,XXX.XX)
	OIBOCODE	,D1	; BACK ORDER CODE		(X)
				;  0 = BACK-ORDER
				;  1 = NO BACK-ORDER
	OITXFLAG	,A1		; TAX FLAG
				;  "Y" = TAXABLE ITEM
				;  "N" = NON-TAXABLE ITEM
;
RECORD ITMMAS
	.INCLUDE 'DEF:RD041A.DEF'
RECORD ITMCTL
	.INCLUDE 'DEF:RD041B.DEF'
;
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
;
RECORD  ALLBRK
		,A40, ']]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]'
		,A40, ']]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]'
		,A40, ']]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]'
		,A40, ']]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]'
		,A40, ']]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]'
		,A40, ']]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]'
		,A40, ']]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]'
		,A40, ']]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]'
		,A12, ']]]]]]]]]]]]'
RECORD OUTNAM
	OUTFIL	,A14,'XXX:XXXXXX.XXX'
		,A1,'['
	BLOCKS	,D4
		,A1,']'
RECORD
	RECNO	,D5
	V	,D1
	ERN	,D3
	ERL	,D3
RECORD	,X
	ARECNO	,A5
PROC(3)
	OPEN (15,I,'TT:')
	DISPLAY (15,13,10,
&	'This application will convert SMC data files to new software',13,10)
	GOTO ORDHDR
ITMMAS,
	DISPLAY (15,13,10,'Convert ITMMAS file',13,10)
	OPEN (1,I,'DU0:ITMMAS.SMC')
	OPEN (2,U,'DU3:ITMMAS.NEW')
	READ (2,ITMCTL,1)
	RECNO = 1
I1,
	INCR RECNO
	DISPLAY (15,13,ARECNO)
	READ (1,OLDITM,RECNO)
	IF (OLDITM.EQ.']]]]]]]]]]') GOTO I9
	ITEMNO = OIITEMNO
	DESCR = OIDESCR
	PRDCAT = OIPRDCAT
	USRDEF = 
	AVGCST = OIAVGCST
	PRICCD(1) = 
	PRICE(1) = OIPRICE
	LOC(1) =
	QTYONH(1) =
	QTYCOM(1) = 
	QTYONO(1) = 
	REOLVL(1) = 
	ORDUPT(1) = 
	PIKSEQ(1) = 
	WEIGHT = OIWEIGHT
	SUOFM = OISUOFM
	USEMTD = 
	USEYTD = 
	QTYMTD = OIQTYMTD
	QTYYTD = OIQTYYTD
	SLSMTD = OISLSMTD
	SLSYTD = OISLSYTD
	CSTMTD = OICSTMTD
	CSTYTD = OICSTYTD
	BOCODE = OIBOCODE
	TXFLAG = OITXFLAG
	INCR REC041
	WRITE (2,ITMMAS,REC041)
	GOTO I1
I9,
	CLOSE 1
	CLOSE 2
ORDHDR,
	DISPLAY (15,13,10,'Convert ORDHDR file',13,10)
	OPEN (1,I,'DU0:ORDHDR.SMC')
	OPEN (2,SU,'DU0:ORDHDR.ISM')
	RECNO = 1
OH1,
	INCR RECNO
	DISPLAY (15,13,ARECNO)
	READ (1,OLDHDR,RECNO)
	IF (OLDHDR.EQ.']]]]]]]]]]') GOTO OH9
	IF (TORDNO.LT.11500) GOTO OH1
	OORDNO = TORDNO
	OLOC = 
	OCUSCD = TCUSCD
	OORDDT = TORDDT
	OCUSNO = TCUSNO
	OCUSNM = TCUSNM
	OSHPTO =
	OSHPNM = TSHPNM
	OSHAD1 = TSHAD1
	OSHAD2 = TSHAD2
	OSHAD3 = TSHAD3
	OPONO = TPONO
	OJOBNO = TJOBNO
	OCLPPD = TCLPPD
	OTERMS = TTERMS
	OTRMSD = TTRMSD
	ODSCAL = TDSCAL
	OSHVIA = TSHVIA
	OINVNO = TINVNO
	OINVDT = TINVDT
	OSALE = TSALE
	OARACT = TARACT
	OMISC = TMISC
	OMSACT = TMSACT
	OTAX = TTAX
	OTXACT = TTXACT
	OFRGHT = TFRGHT
	OFRACT = TFRACT
	ODISC = TDISC
	OSLMAN = TSLMAN
	OCOMNT = TCOMNT
	OCOST = TCOST
	OCOMDU = TCOMDU
	OFLAG = TFLAG
	ORDTYP = TRDTYP
	ORDSEQ = TRDSEQ
	OPROMD = TPROMD
	OSHDAT = TSHDAT
	ONERROR OH2
	STORE (2,ORDHDR,OORDNO)
	GOTO OH1
OH2,
	OFFERROR
	XCALL ERROR (ERN,ERL)
	IF (ERN.EQ.54)
	BEGIN
	  DISPLAY (15,13,10,'DUPLIC: ',ORDHDR,13,10)
	  GOTO OH1
	END
	CLOSE 1
	CLOSE 2
	STOP
OH9,
	CLOSE 1
	CLOSE 2
ORDLIN,
	DISPLAY (15,13,10,'Convert ORDLIN file',13,10)
	OPEN (1,I,'DU0:ORDLIN.SMC')
	OPEN (2,SU,'DU0:ORDLIN.ISM') 
	RECNO = 1
OL1,
	INCR RECNO
	DISPLAY (15,13,ARECNO)
	READ (1,OLDLIN,RECNO)
	IF (OLDLIN.EQ.']]]]]]]]]]') GOTO OL9
	IF (DORDNO.LT.11500) GOTO OL1
	LORDNO = DORDNO
	LINSEQ = DINSEQ
	LITMNO = DITMNO
	LDESCR = DDESCR
	LQTYOR = DQTYOR
	LQTYSH = DQTYSH
	LQTYBO = DQTYBO
	LLOC = 'O'
	LPRDCD = DPRDCD
	LUOFM = DUOFM
	LPRICE = DPRICE
	LODISC = DODISC
	LDISC = DDISC
	LSTATS = DSTATS
	LPICSQ = 
	LCOST = DCOST
	LFLAG = DFLAG
	LITMWT = DITMWT
	LTXFLG = DTXFLG
	LSTOKT =
	LEXSDT = 
	LPRMDT = 
	STORE (2,ORDLIN,ORDKEY)
	GOTO OL1
OL9,
	CLOSE 1
	CLOSE 2
DUCACC,
	DISPLAY (15,13,10,'Convert DUCACC file',13,10)
	OPEN (1,I,'DU0:DUCACC.SMC')
	OPEN (2,SU,'DU0:DUCACC.ISM')
	RECNO = 1
DU1,
	INCR RECNO
	DISPLAY (15,13,ARECNO)
	READ (1,OLDDUC,RECNO)
	IF (OLDDUC.EQ.']]]]]]]]]]') GOTO DU9
	IF (ODDUCTOR.LT.11500) GOTO DU1
	DUCTOR = ODDUCTOR
	DUTYPE = ODDUTYPE
	STY = ODSTY
	LINER = ODLINER
	SEAM = ODSEAM
	SEAL = ODSEAL
	GAUGE = ODGAUGE
	THICK =

	  IF (DUTYPE.EQ.2) CASE GAUGE OF
	  BEGINCASE
	  24:	THICK = 024	;ALUMINUM
	  22:	THICK = 032	;ALUMINUM
	  20:	THICK = 040	;ALUMINUM
	  18:	THICK = 050	;ALUMINUM
	  ENDCASE

	  IF (DUTYPE.EQ.3) CASE GAUGE OF
	  BEGINCASE
	  24:	THICK = 024	;STAINLESS
	  22:	THICK = 030	;STAINLESS
	  20:	THICK = 036	;STAINLESS
	  ENDCASE 

	CAT = ODCAT
	JOINT = ODJOINT
	SIZE1 = ODSIZ1
	SIZE2 = ODSIZ2
	SIZE3 = ODSIZ3
	LOCAT = ODLOCAT
	ACC = ODACC
	SLIPS = ODSLIPS
	SLPITM = ODSLPITM
	SLPPRC = ODSLPPRC
	SLPDES = ODSLPDES
	DRIVES = ODDRIVES
	DRVITM = ODDRVITM
	DRVPRC = ODDRVPRC
	DRVDES = ODDRVDES
	SQFEET = ODSQFEET
	POUNDS = ODPOUNDS
	SQFLIN = ODSQFLIN
	TCORN = ODTCORN
	CORITM = ODCORITM
	CORPRC = ODCORPRC
	CORDES = ODCORDES
	DUCTT = ODDUTT
	TNBITM = ODTNBITM
	TNBQTY = ODTNBQTY
	TNBPRC = ODTNBPRC
	TNBDES = ODTNBDES
	TGAITM = ODTGAITM
	TGAQTY = ODTGAQTY
	TGAPRC = ODTGAPRC
	TGADES = ODTGADES
	TCLITM = ODTCLITM
	TCLQTY = ODTCLQTY
	TCLPRC = ODTCLPRC
	TCLDES = ODTCLDES
	TBAITM = ODTBAITM
	TBAQTY = ODTBAQTY
	TBAPRC = ODTBAPRC
	TBADES = ODTBADES
	TBNITM = ODTBNITM
	TBNQTY = ODTBNQTY
	TBNPRC = ODTBNPRC
	TBNDES = ODTBNDES
	GPRICE = ODGPRICE
	LINPRC = ODLINPRC
	RST065 =
	FLG065 =
	STORE (2,DUCACC,KEY065)
	GOTO DU1
DU9,
	DISPLAY (15,13,10)
	CLOSE 1
	CLOSE 2
	STOP
END
