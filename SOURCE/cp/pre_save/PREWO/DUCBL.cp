SUBROUTINE DUCBL
;
;
;
	OORDNO	,D
	ODISC	,D
	RUNTOT	,D
	TAXTOT	,D
	WHLORD	,D
	TAXFLG	,A
GLOBAL DUCK
		.INCLUDE 'DEF:RD175D.DEF'
ENDGLOBAL

GLOBAL PAR	;;;,INIT
RECORD PARAM
	.INCLUDE 'DEF:PARAM.DEF'
ENDGLOBAL

RECORD PITEM
	.INCLUDE 'DEF:RD041W.DEF'

RECORD DUCFIL	; Table of all parameters necessary
	.INCLUDE 'DEF:RD174A.DEF'

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
	ENTRY	,A20
	ALPHA	,A20
	J	,D2
	V	,D1,	1
	DEC	,D10
	CNGCTL	,D1
	INXCTL	,D1
	LOKCTL	,D1
	WHATNO	,D2
	DECMAL	,D18
	SUB	,D1
	READ	,D1,	0
	WRITE	,D1,	1
	STORE	,D1,	2
	DELETE	,D1,	3
	BSMID	,D5
	BSEND	,D5
	SRCCTL	,D1
	DEC1	,D18
	DEC2	,D18
	DEC3	,D18
	DEC4	,D18
	KEY	,A15
	CNGACC	,D1
	CNGSLP	,D1
	CNGTDC	,D1
	CNGSTY	,D1
	OLDACC	,D1
	DSUB	,D5
	DEFLT	,D1,0
	ORGINV	,D5
	BLANKS	,A15
	FILENM	,A14
	SWITCH	,D1
PROC

FNDDUC,
	DUCTOR = OORDNO
	LOKCTL = 1
	XCALL ISIO (5,DUCACC,DUCTOR,READ,LOKCTL)
	IF (LOKCTL.NE.0) GOTO NOFIND
	IF (DUCTOR.NE.OORDNO) GOTO NOFIND
	GOTO DSPDUC
NXTDUC,
	LOKCTL = 1
	XCALL IOS (5,DUCACC,READ,LOKCTL)
	IF (LOKCTL.NE.0) GOTO NOMORE
	IF (DUCTOR.NE.OORDNO) GOTO NOMORE
	GOTO DSPDUC
NOMORE,
	XCALL MESAG ('NO MORE DUCT RECORDS FOR THIS ORDER',2)
	RETURN
NOFIND,
	XCALL MESAG ('NO DUCT RECORDS FOUND FOR THIS ORDER',2)
	RETURN
DSPDUC,
	IF (WHLORD) GOTO CHANGE
BEGIN,
	CNGSTY =
	CNGSLP =
	CNGTDC =
	OLDACC =
	CNGCTL =

	XCALL OUTPT (3,1,2,'\',1)
	XCALL OE10
		; Get the parameter information for that gauge
	XCALL FFILE (174,FILENM,SWITCH)
	OPEN (1,I,FILENM)
	LOKCTL = 1
	XCALL IO (1,DUCFIL,GAUGE,READ,LOKCTL)
	CLOSE 1

	XCALL DSPDU 

	XCALL OUTPT (24,1,1,'BILL THIS DUCT TRANSACTION <Y> ? ',1)
	CTL = '24,34,01,00,YY'
	CALL INPUT
	IF (INXCTL.EQ.2) 
	BEGIN
	  FLG175 =
	  GOTO NOBILL
	END
	GOTO ANYCNG

CAT,
	CTL = '04,19,01,00,# '
;;;	FOR I = 1 STEP 1 UNTIL 4 
;;;	  DO XCALL OUTPT (ROW+I-1,65,0,DCAT(I),V)
	for i from 1 thru 4 XCALL OUTPT (ROW+I-1,65,0,DCAT(I),V)
	CALL INPUT
	GOTO (BEGIN), INXCTL
	CAT = ENTRY
	IF (CAT.EQ.0) CAT = 1
	IF (CAT.LT.1.OR.CAT.GT.4) GOTO CAT
	ALPHA =
	ALPHA (1,1) = CAT,'X'
	ALPHA (5,19) = DCAT(CAT)
	XCALL OUTPT (ROW,19,0,ALPHA,V)
	J = 4
	CALL CLRTAG
	GOTO (ANYCNG), CNGCTL

JOINT,
	CTL = '08,19,06,00,#-'
	CALL INPUT
	GOTO (BEGIN), INXCTL
	JOINT = ENTRY
	IF (JOINT.EQ.0) GOTO JOINT
	GOTO (RECALC), CNGCTL

SIZE1,
	CTL = '09,19,03,00,# '
	CALL INPUT
	GOTO (BEGIN), INXCTL
	SIZE1 = ENTRY
	IF (SIZE1.LE.0) GOTO SIZE1
	XCALL OUTPT (ROW,22,0,' X ',V)

SIZE2,
	CTL = '09,25,02,00,# '
	CALL INPUT
	GOTO (SIZE1), INXCTL
	SIZE2 = ENTRY
	IF (SIZE2.LE.0) GOTO SIZE2
	XCALL OUTPT (ROW,28,0,' X ',V)

SIZE3,
	CTL = '09,31,02,00,# '
	CALL INPUT
	GOTO (SIZE1), INXCTL
	SIZE3 = ENTRY
	IF (SIZE3.LE.0) GOTO SIZE3
	IF (SIZE3.NE.4.AND.SIZE3.NE.5) GOTO SIZE3	;4 or 5 feet only

	GOTO (RECALC), CNGCTL	; If the size of the thing has changed, 
				; must recalc the square feet, and pounds.


RECALC,
		; Get the parameter information for that gauge
	XCALL FFILE (174,FILENM,SWITCH)
	OPEN (1,I,FILENM)
	LOKCTL = 1
	XCALL IO (1,DUCFIL,GAUGE,READ,LOKCTL)
	CLOSE 1

		; Calculate the square feet
	DEC1 =
	DEC2 =
	DEC3 =
	DEC4 =
	SQFEET =
	DEC4 = SIZE3 * 12
		; Get the length in inches

	DEC1 = ( ( SIZE1 * DEC4 ) * 2 )
		; DEC1 = square feet of 2 slip sides in inches

	DEC2 = ( ( SIZE2 * DEC4 ) * 2 )
		; DEC2 = Square feet of 2 drive sides in inches

	DEC3 = ( DEC1 + DEC2 ) * JOINT
		; Total square feet, is slip sides, plus drive sides
		; times the number of joints

	SQFEET = ( ( DEC3 * 10 ) / 144 ) #1
		; Convert to square feet

	ALPHA =
	ALPHA(1,11) = 'Duct   Sqft'
	ALPHA(12,20) =  SQFEET, 'ZZZZ,ZZX-' 
	XCALL OUTPT (9,40,0,ALPHA(1,20),V)

		;  Calculate the pounds of sheet metal, seam allowance, 
		;  and waste factor.
	DEC1 = 
	DEC2 =
	DEC3 =
	POUNDS =

	DEC1 = ( DUCLBS * SQFEET )
		;  Calculate the total actual number of pounds

	DEC3 = ( DUCSEA * ( SIZE3 * JOINT ) )
	IF ((SIZE1+SIZE2).GE.120) DEC3 = ( ( DUCSEA * 2 )*( SIZE3 * JOINT ) )
		; Calculate the seam allowance, by the foot, from total length
		; If size1+size2 .ge.120 then add seam allow twice

	DEC2 = ( DUCWAS * (DEC1+DEC3) ) #5
		; Calculate the total waste pounds, based on above acutal #
		; Round back 5 digts cuz of decimal places.
		; Changed to figure waste last cuz waste was not figured on
		; seam allowance and it should be

	POUNDS = ( DEC1 + DEC3 + DEC2 ) #3
		; The total pounds, is the actual number of pounds
		; plus the seam allowance
		; plus the waste
	IF (DUTYPE.EQ.2) POUNDS = ( ( DEC1 + DEC3 + DEC2 ) / 3 ) #3
		; Aluminum pounds is 1/3 galvanized

	ALPHA =
	ALPHA(1,11) = 'Duct Pounds'
	ALPHA(12,20) =  POUNDS, 'ZZZZ,ZZX-' 
	XCALL OUTPT (10,40,0,ALPHA(1,20),V)

	IF (CNGCTL) CALL CALLIN			; Recalc liner if changes

	GOTO (ANYCNG), CNGCTL

LOCAT,
	CTL = '12,19,15,00,A '
	CALL INPUT
	GOTO (BEGIN), INXCTL
	LOCAT = ENTRY
	GOTO (ANYCNG), CNGCTL
GPRICE,
	CTL = '10,73,06,00,#N'
	CALL INPUT
	GOTO (BEGIN), INXCTL
	GPRICE = ENTRY
	ALPHA (1,7) = GPRICE,'ZZZ.XXX'
	XCALL OUTPT (ROW,COL,0,ALPHA(1,7),V)
	GOTO (ANYCNG), CNGCTL
LINPRC,
	CTL = '11,73,06,00,#N'
	CALL INPUT
	GOTO (BEGIN), INXCTL
	LINPRC = ENTRY
	ALPHA (1,7) = LINPRC,'ZZZ.XXX'
	XCALL OUTPT (ROW,COL,0,ALPHA(1,7),V)
	GOTO (ANYCNG), CNGCTL

ACC,
	IF (CNGCTL) OLDACC = ACC
	CTL = '14,19,01,00,# '
;;;	FOR I = 1 STEP 1 UNTIL 2
;;;	  DO XCALL OUTPT (ROW+I-1,65,0,DACC(I),V)
	for i from 1 thru 2 XCALL OUTPT (ROW+I-1,65,0,DACC(I),V)
	CALL INPUT
	GOTO (BEGIN), INXCTL
	ACC = ENTRY
	IF (ACC.EQ.0) ACC = 2
	IF (ACC.LT.1.OR.ACC.GT.2) GOTO ACC
	ALPHA =
	ALPHA (1,1) = ACC,'X'
	ALPHA (5,19) = DACC(ACC)
	XCALL OUTPT (ROW,19,0,ALPHA(1,19),V)
;;;	FOR I = 1 STEP 1 UNTIL 2
;;;	  DO XCALL OUTPT (ROW+I-1,65,1,'\',V)
	for i from 1 thru 2 XCALL OUTPT (ROW+I-1,65,1,'\',V)

	IF (CNGCTL.EQ.0) GOTO (SLIPS,ANYCNG), ACC
			;      ^^^^^|^^^^^^
			;            no acces so goto anycng
			;      yes acces so enter them

	IF (ACC.EQ.2) CALL CLRACC
		; If no accessories, clear the accessory fields & screen

	IF (CNGCTL.EQ.1.AND.ACC.EQ.1)
	BEGIN
	  IF (CNGSLP.EQ.1) GOTO SLIPS
		; If they want accessories, and style is 1, must enter SLIPS

	  IF (OLDACC.NE.1) GOTO SLIPS
		; If they want accessories, and style is 1, must enter SLIPS

	  IF (CNGTDC.EQ.2) GOTO TCORN
		; If they want accessories, and style is 2, enter access

	  IF (OLDACC.NE.2) GOTO TCORN
		; If they want accessories, and style is 2, enter access
	END

	GOTO (ANYCNG), CNGCTL

SLIPS,
	SLIPS	=		;---------------------
	SLPITM	=		;Slips
	SLPPRC	=		;
	SLPDES	=		;---------------------
	IF (STY.EQ.2.AND.CNGCTL) GOTO BADCNG
		; Can't change the slips if TDC

	IF (STY.EQ.2) GOTO TCORN	; If the style is TDC, no slips/drives
	CTL = '15,19,05,00,# '
	XCALL OUTPT (ROW,COL,1,'\',V)
	CALL INPUT
	GOTO (BEGIN), INXCTL
	SLIPS = ENTRY
	IF (ENTRY.EQ.'     ') SLIPS = JOINT * 2
	IF (SLIPS.NE.0)
	BEGIN
	  ALPHA =
	  ALPHA (1,6) = SLIPS,'ZZZZX-'
	  ALPHA (7,9) = 'Qty'
	  XCALL OUTPT (ROW,19,1,ALPHA(1,9),V)
	END
	IF (SLIPS.EQ.0) XCALL OUTPT (ROW,19,1,'None',1)

	XCALL OUTPT (ROW,65,0,' Qty OK <Y> ? ',V)
	CTL (4,14) = '79,01,00,YY'
	CALL INPUT
	XCALL OUTPT (ROW,65,1,'\',V)
	IF (INXCTL.NE.1) GOTO SLIPS
	IF (SLIPS.EQ.0) GOTO ENDSLP

		; Set up the default slip size ( for inventory read )
	SLPITM =

	XCALL DFITM (1,SIZE2,SLPITM)

GETSLP,
		; Get the item from inventory
	XCALL OUTPT (ROW,31,0,SLPITM,V)
	IF (SLPITM.EQ.BLANKS) GOTO ENTSLP
	KEY = SLPITM
	CALL ITMMAS
	IF (SRCCTL) GOTO ENTSLP
	SLPPRC = PRICE
	SLPDES = DESCR
	GOTO ENDSLP

ENTSLP,
		; Enter the slip sizes ( item numbers here )
	CTL = '15,31,15,01,A '
	XCALL OUTPT (ROW,COL,1,'\',V)
	CALL INPUT
	GOTO (SLIPS), INXCTL
	SLPITM = ENTRY
	GOTO GETSLP
ENDSLP,
	IF (CNGSTY.EQ.1.AND.STY.EQ.1) GOTO DRIVES
		; If the style has been changed to 1, then they must enter
		; the drives also.

	GOTO (ANYCNG), CNGCTL
DRIVES,
	DRIVES	=		;---------------------
	DRVITM	=		;Drives
	DRVPRC	=		;
	DRVDES	=		;---------------------
	IF (STY.EQ.2.AND.CNGCTL) GOTO BADCNG
		; Can't change the drives if TDC

	IF (STY.EQ.2) GOTO TCORN	; If the style is TDC, no slips/drives
	CTL = '16,19,05,00,# '
	XCALL OUTPT (ROW,COL,1,'\',V)
	CALL INPUT
	GOTO (BEGIN), INXCTL
	DRIVES = ENTRY
	IF (ENTRY.EQ.'     ') DRIVES = JOINT * 2
	IF (DRIVES.NE.0)
	BEGIN
	  ALPHA =
	  ALPHA (1,6) = DRIVES,'ZZZZX-'
	  ALPHA (7,9) = 'Qty'
	  XCALL OUTPT (ROW,19,1,ALPHA(1,9),V)
	END
	IF (DRIVES.EQ.0) XCALL OUTPT (ROW,19,1,'None',V)

	XCALL OUTPT (ROW,65,0,' Qty OK <Y> ? ',V)
	CTL (4,14) = '79,01,00,YY'
	CALL INPUT
	XCALL OUTPT (ROW,65,1,'\',V)
	IF (INXCTL.NE.1) GOTO DRIVES
	IF (DRIVES.EQ.0) GOTO ENDDRV

		; Set up the default drive size ( for inventory read )
	DRVITM =

	XCALL DFITM (2,SIZE2,DRVITM)

GETDRV,
		; Get the item from inventory
	XCALL OUTPT (ROW,31,0,DRVITM,V)
	IF (DRVITM.EQ.BLANKS) GOTO ENTDRV
	KEY = DRVITM
	CALL ITMMAS
	IF (SRCCTL) GOTO ENTDRV
	DRVPRC = PRICE
	DRVDES = DESCR
	GOTO ENDDRV

ENTDRV,
		; Enter the drive sizes ( item numbers here )
	CTL = '16,31,15,01,A '
	XCALL OUTPT (ROW,COL,1,'\',V)
	CALL INPUT
	GOTO (DRIVES), INXCTL
	DRVITM = ENTRY
	GOTO GETDRV
ENDDRV,
	GOTO (ANYCNG), CNGCTL

TCORN,
	TCORN	= 		;---------------------
	CORITM	= 		;Corners
	CORPRC	=		;
	CORDES	=		;---------------------
	IF ( STY.NE.2.AND.CNGCTL ) GOTO BADCNG
		; Can't change the corners if not TDC
	IF ( STY.NE.2 ) GOTO ANYCNG
		; Do this only for TDC duct 
	CTL = '17,19,05,00,# '
	XCALL OUTPT (ROW,COL,1,'\',V)
	CALL INPUT
	GOTO (BEGIN), INXCTL
	TCORN = ENTRY
	IF (ENTRY.EQ.'     ') IF (SIZE1.LT.60.AND.SIZE2.LT.60) TCORN = JOINT * 8
	IF (TCORN.NE.0)
	BEGIN
	  ALPHA =
	  ALPHA (1,6) = TCORN,'ZZZZX-'
	  ALPHA (7,9) = 'Qty'
	  XCALL OUTPT (ROW,19,1,ALPHA(1,9),V)
	END
	IF (TCORN.EQ.0) XCALL OUTPT (ROW,19,1,'None',V)

	XCALL OUTPT (ROW,65,0,' Qty OK <Y> ? ',V)
	CTL (4,14) = '79,01,00,YY'
	CALL INPUT
	XCALL OUTPT (ROW,65,1,'\',V)
	IF (INXCTL.NE.1) GOTO TCORN
	IF (TCORN.EQ.0) GOTO ENDCOR

		; Set up the default corner ( for inventory read )
;;;	CORITM = 'TDCCR'
	CORITM = 'TCR'		;SSQ 7-18-97

GETCOR,
		; Get the item from inventory
	XCALL OUTPT (ROW,31,0,CORITM,V)
	IF (CORITM.EQ.BLANKS) GOTO ENTCOR
	KEY = CORITM
	CALL ITMMAS
	IF (SRCCTL) GOTO ENTCOR
	CORPRC = PRICE
	CORDES = DESCR
	GOTO ENDCOR

ENTCOR,
		; Enter corner item number here
	CTL = '17,31,15,01,A '
	XCALL OUTPT (ROW,COL,1,'\',V)
	CALL INPUT
	GOTO (TCORN), INXCTL
	CORITM = ENTRY
	GOTO GETCOR
ENDCOR,
	IF ( CNGSTY.EQ.1.AND.STY.EQ.2 ) GOTO TNBQTY
		; If they changed the style to 2 ( TDC ) , they must enter
		; all of the accessories for TDC
	GOTO (ANYCNG), CNGCTL


TNBQTY,
	TNBQTY	=		;---------------------
	TNBITM	=		;TDC nuts & bolts
	TNBPRC	=		;
	TNBDES	=		;---------------------
	IF ( STY.NE.2.AND.CNGCTL ) GOTO BADCNG
		; Can't change the nuts & bolts if not TDC
	IF ( STY.NE.2 ) GOTO ANYCNG
		; Do this only for TDC duct 
	CTL = '18,19,05,00,# '
	XCALL OUTPT (ROW,COL,1,'\',V)
	CALL INPUT
	GOTO (BEGIN), INXCTL
	TNBQTY = ENTRY
	IF (ENTRY.EQ.'     ') IF (TCORN) TNBQTY = TCORN / 2
	IF (TNBQTY.NE.0)
	BEGIN
	  ALPHA =
	  ALPHA (1,6) = TNBQTY,'ZZZZX-'
	  ALPHA (7,9) = 'Qty'
	  XCALL OUTPT (ROW,19,1,ALPHA(1,9),V)
	END
	IF (TNBQTY.EQ.0) XCALL OUTPT (ROW,19,1,'None',V)

	XCALL OUTPT (ROW,65,0,' Qty OK <Y> ? ',V)
	CTL (4,14) = '79,01,00,YY'
	CALL INPUT
	XCALL OUTPT (ROW,65,1,'\',V)
	IF (INXCTL.NE.1) GOTO TNBQTY
	IF (TNBQTY.EQ.0) GOTO ENDTNB

		; Set up the default TNB nust & bolts item number
;;;	TNBITM = 'TDCNB'
	TNBITM = 'TN'		;SSQ 7-18-97

GETTNB,
		; Get the item from inventory
	XCALL OUTPT (ROW,31,0,TNBITM,V)
	IF (TNBITM.EQ.BLANKS) GOTO ENTTNB
	KEY = TNBITM
	CALL ITMMAS
	IF (SRCCTL) GOTO ENTTNB
	TNBPRC = PRICE
	TNBDES = DESCR
	GOTO ENDTNB

ENTTNB,
		; Enter TNB nuts/bolts item number here
	CTL = '18,31,15,01,A '
	XCALL OUTPT (ROW,COL,1,'\',V)
	CALL INPUT
	GOTO (TNBQTY), INXCTL
	TNBITM = ENTRY
	GOTO GETTNB
ENDTNB,
	IF (CNGSTY.EQ.1.AND.STY.EQ.2) GOTO TGAQTY
		; If they changed the style to 2 ( TDC ) , they must enter
		; all of the accessories for TDC
	GOTO (ANYCNG), CNGCTL


TGAQTY,
	TGAQTY	=		;---------------------
	TGAITM	=		;Gasket
	TGAPRC	=		;
	TGADES	=		;---------------------
	IF ( STY.NE.2.AND.CNGCTL ) GOTO BADCNG
		; Can't change gasket if not TDC
	IF ( STY.NE.2 ) GOTO ANYCNG
		; Do this only for TDC duct 
	CTL = '19,19,05,00,# '
	XCALL OUTPT (ROW,COL,1,'\',V)
	CALL INPUT
	GOTO (BEGIN), INXCTL
	TGAQTY = ENTRY
	IF (ENTRY.EQ.'     ') TGAQTY = POUNDS / ((DUCLBS * SIZE3) #3)
	IF (TGAQTY.NE.0)
	BEGIN
	  ALPHA =
	  ALPHA (1,6) = TGAQTY,'ZZZZX-'
	  ALPHA (7,9) = 'Ft '
	  XCALL OUTPT (ROW,19,1,ALPHA(1,9),V)
	END
	IF (TGAQTY.EQ.0) XCALL OUTPT (ROW,19,1,'None',V)

	XCALL OUTPT (ROW,65,0,' Qty OK <Y> ? ',V)
	CTL (4,14) = '79,01,00,YY'
	CALL INPUT
	XCALL OUTPT (ROW,65,1,'\',V)
	IF (INXCTL.NE.1) GOTO TGAQTY
	IF (TGAQTY.EQ.0) GOTO ENDTGA

		; Set up the default TNB gasket item number
;;;	TGAITM = 'TDCGS'
	TGAITM = 'TG'		;SSQ 7-18-97

GETTGA,
		; Get the item from inventory
	XCALL OUTPT (ROW,31,0,TGAITM,V)
	IF (TGAITM.EQ.BLANKS) GOTO ENTTGA
	KEY = TGAITM
	CALL ITMMAS
	IF (SRCCTL) GOTO ENTTGA
	TGAPRC = PRICE
	TGADES = DESCR
	GOTO ENDTGA

ENTTGA,
		; Enter TDC gasket item number here
	CTL = '19,31,15,01,A '
	XCALL OUTPT (ROW,COL,1,'\',V)
	CALL INPUT
	GOTO (TGAQTY), INXCTL
	TGAITM = ENTRY
	GOTO GETTGA
ENDTGA,
	IF (CNGSTY.EQ.1.AND.STY.EQ.2) GOTO TCLQTY
		; If they changed the style to 2 ( TDC ) , they must enter
		; all of the accessories for TDC
	GOTO (ANYCNG), CNGCTL

TCLQTY,
	TCLQTY	=		;---------------------
	TCLITM	=		;Cleats
	TCLPRC	=		;
	TCLDES	=		;---------------------
	IF ( STY.NE.2.AND.CNGCTL ) GOTO BADCNG
		; Can't change if not TDC
	IF ( STY.NE.2 ) GOTO ANYCNG
		; Do this only for TDC duct 
	CTL = '20,19,05,00,# '
	XCALL OUTPT (ROW,COL,1,'\',V)
	CALL INPUT
	GOTO (BEGIN), INXCTL
	TCLQTY = ENTRY
	IF (ENTRY.EQ.'     ') TCLQTY = ( ( TGAQTY * 100 ) / DUCCLE )#1
	IF (TCLQTY.NE.0)
	BEGIN
	  ALPHA =
	  ALPHA (1,6) = TCLQTY,'ZZZZX-'
	  ALPHA (7,9) = 'Qty'
	  XCALL OUTPT (ROW,19,1,ALPHA(1,9),V)
	END
	IF (TCLQTY.EQ.0) XCALL OUTPT (ROW,19,1,'None',V)

	XCALL OUTPT (ROW,65,0,' Qty OK <Y> ? ',V)
	CTL (4,14) = '79,01,00,YY'
	CALL INPUT
	XCALL OUTPT (ROW,65,1,'\',V)
	IF (INXCTL.NE.1) GOTO TCLQTY
	IF (TCLQTY.EQ.0) GOTO ENDTCL

		; Set up the default item number
;;;	TCLITM = 'TDCCL'
	TCLITM = 'TC'		;SSQ 7-18-97

GETTCL,
		; Get the item from inventory
	XCALL OUTPT (ROW,31,0,TCLITM,V)
	IF (TCLITM.EQ.BLANKS) GOTO ENTTCL
	KEY = TCLITM
	CALL ITMMAS
	IF (SRCCTL) GOTO ENTTCL
	TCLPRC = PRICE
	TCLDES = DESCR
	GOTO ENDTCL

ENTTCL,
		; Enter item number here
	CTL = '20,31,15,01,A '
	XCALL OUTPT (ROW,COL,1,'\',V)
	CALL INPUT
	GOTO (TCLQTY), INXCTL
	TCLITM = ENTRY
	GOTO GETTCL
ENDTCL,
	IF (CNGSTY.EQ.1.AND.STY.EQ.2) GOTO TBAQTY
		; If they changed the style to 2 ( TDC ) , they must enter
		; all of the accessories for TDC
	GOTO (ANYCNG), CNGCTL

TBAQTY,
	TBAQTY	=		;---------------------
	TBAITM	=		;TDC bar
	TBAPRC	=		;
	TBADES	=		;---------------------
	IF ( STY.NE.2.AND.CNGCTL ) GOTO BADCNG
		; Can't change if not TDC
	IF ( STY.NE.2 ) GOTO ANYCNG
		; Do this only for TDC duct 
	CTL = '21,19,05,00,# '
	XCALL OUTPT (ROW,COL,1,'\',V)
	CALL INPUT
	GOTO (BEGIN), INXCTL
	TBAQTY = ENTRY
	IF (ENTRY.EQ.'     ') IF (SIZE1.GE.60.OR.SIZE2.GE.60)
&		TBAQTY = (((SIZE1 + SIZE2) * 4 ) * JOINT)
	IF (TBAQTY.NE.0)
	BEGIN
	  ALPHA =
	  ALPHA (1,6) = TBAQTY,'ZZZZX-'
	  ALPHA (7,10) = 'Inch'
	  XCALL OUTPT (ROW,19,1,ALPHA(1,11),V)
	END
	IF (TBAQTY.EQ.0) XCALL OUTPT (ROW,19,1,'None',V)

	XCALL OUTPT (ROW,65,0,' Qty OK <Y> ? ',V)
	CTL (4,14) = '79,01,00,YY'
	CALL INPUT
	XCALL OUTPT (ROW,65,1,'\',V)
	IF (INXCTL.NE.1) GOTO TBAQTY
	IF (TBAQTY.EQ.0) GOTO ENDTBA

		; Set up the default item number
	TBAITM = 'TDCBAR'

GETTBA,
		; Get the item from inventory
	XCALL OUTPT (ROW,31,0,TBAITM,V)
	IF (TBAITM.EQ.BLANKS) GOTO ENTTBA
	KEY = TBAITM
	CALL ITMMAS
	IF (SRCCTL) GOTO ENTTBA
	TBAPRC = PRICE
	TBADES = DESCR
	GOTO ENDTBA

ENTTBA,
		; Enter item number here
	CTL = '21,31,15,01,A '
	XCALL OUTPT (ROW,COL,1,'\',V)
	CALL INPUT
	GOTO (TBAQTY), INXCTL
	TBAITM = ENTRY
	GOTO GETTBA
ENDTBA,
	IF (CNGSTY.EQ.1.AND.STY.EQ.2) GOTO TBNQTY
		; If they changed the style to 2 ( TDC ) , they must enter
		; all of the accessories for TDC
	GOTO (ANYCNG), CNGCTL

TBNQTY,
	TBNQTY	=		;---------------------
	TBNITM	=		;TDC bar nuts & bolts
	TBNPRC	=		;
	TBNDES	=		;---------------------
	IF ( STY.NE.2.AND.CNGCTL ) GOTO BADCNG
		; Can't change if not TDC
	IF ( STY.NE.2 ) GOTO ANYCNG
		; Do this only for TDC duct 
	CTL = '22,19,05,00,# '
	XCALL OUTPT (ROW,COL,1,'\',V)
	CALL INPUT
	GOTO (BEGIN), INXCTL
	TBNQTY = ENTRY
	IF (ENTRY.EQ.'     ') IF (TBAQTY) TBNQTY = ( JOINT * 8 ) / 2
	IF (TBNQTY.NE.0)
	BEGIN
	  ALPHA =
	  ALPHA (1,6) = TBNQTY,'ZZZZX-'
	  ALPHA (7,9) = 'N/B'
	  XCALL OUTPT (ROW,19,1,ALPHA(1,9),V)
	END
	IF (TBNQTY.EQ.0) XCALL OUTPT (ROW,19,1,'None',V)

	XCALL OUTPT (ROW,65,0,' Qty OK <Y> ? ',V)
	CTL (4,14) = '79,01,00,YY'
	CALL INPUT
	XCALL OUTPT (ROW,65,1,'\',V)
	IF (INXCTL.NE.1) GOTO TBNQTY
	IF (TBNQTY.EQ.0) GOTO ENDTBN

		; Set up the default item number
;;;	TBNITM = 'TDCBNB'
	TBNITM = 'TN5'		;SSQ 7-18-97

GETTBN,
		; Get the item from inventory
	XCALL OUTPT (ROW,31,0,TBNITM,V)
	IF (TBNITM.EQ.BLANKS) GOTO ENTTBN
	KEY = TBNITM
	CALL ITMMAS
	IF (SRCCTL) GOTO ENTTBN
	TBNPRC = PRICE
	TBNDES = DESCR
	GOTO ENDTBN

ENTTBN,
		; Enter item number here
	CTL = '22,31,15,01,A '
	XCALL OUTPT (ROW,COL,1,'\',V)
	CALL INPUT
	GOTO (TBNQTY), INXCTL
	TBNITM = ENTRY
	GOTO GETTBN
ENDTBN,

	GOTO ANYCNG
NOKEYC,
	XCALL MESAG ('CANNOT CHANGE KEY - DELETE DUCT RECORD AND REENTER',2)
	GOTO ANYCNG
BADCNG,
	CNGCTL = 3
ANYCNG,
	XCALL ANYCN (CNGCTL,WHATNO)

	IF (CNGCTL)
	BEGIN
	 GOTO(NOKEYC,CAT,NOKEYC,NOKEYC,NOKEYC,JOINT,SIZE1,NOKEYC,NOKEYC,LOCAT,
&	 ACC,SLIPS,DRIVES,TCORN,TNBQTY,TGAQTY,TCLQTY,TBAQTY,TBNQTY,
&	 GPRICE,LINPRC), WHATNO
	 GOTO BADCNG
	END

CHANGE,
	DECMAL = (POUNDS*GPRICE)#1
	IF (LINER.GT.0.AND.LINER.LE.8) DECMAL = DECMAL + (SQFLIN*LINPRC)#1
	IF (ACC.EQ.1)
	BEGIN
	  IF (SLIPS)  DECMAL = DECMAL + (SLIPS*SLPPRC)#1
	  IF (DRIVES) DECMAL = DECMAL + (DRIVES*DRVPRC)#1
	  IF (TCORN)  DECMAL = DECMAL + (TCORN*CORPRC)#1
	  IF (TNBQTY) DECMAL = DECMAL + (TNBQTY*TNBPRC)#1
	  IF (TGAQTY) DECMAL = DECMAL + (TGAQTY*TGAPRC)#1
	  IF (TCLQTY) DECMAL = DECMAL + (TCLQTY*TCLPRC)#1
	  IF (TBAQTY) DECMAL = DECMAL + (TBAQTY*TBAPRC)#1
	  IF (TBNQTY) DECMAL = DECMAL + (TBNQTY*TBNPRC)#1
	END
	DECMAL = DECMAL - ((DECMAL * ODISC) #2)
	RUNTOT = RUNTOT + DECMAL
;;;	IF (TAXFLG.NE.'   ') TAXTOT = TAXTOT + DECMAL
	TAXTOT = TAXTOT + DECMAL			;;;10/14/93 force taxable
	FLG175 = 1		;SET BILLING SELECT FLAG IN DUCACC
NOBILL,
	LOKCTL = 1
	XCALL ISIO (5,DUCACC,KEY175,WRITE,LOKCTL)
	GOTO NXTDUC
INPUT,
	XCALL INPUT (ROW,COL,MAX,MIN,TYPE,ENTRY,INXCTL,1)
	RETURN

CALLIN,
		; Calculate the number of square feet of liner for this item
	DEC1 = 
	DEC2 =
	DEC3 =
	SQFLIN =

	DEC1 = ( DLINE * SQFEET ) #2
		; DLINE is a overage % of square feet ( SEE DUCMNT.COP )

	DEC1 = ( DEC1 + 500 ) #3

	SQFLIN = DEC1 + SQFEET
		; Calculate the waste, and add square feet of duct

	ALPHA =
	ALPHA(1,11) = 'Liner  Sqft'
	IF (LINER.EQ.5) SQFLIN =
	ALPHA(12,20) =  SQFLIN, 'ZZZZ,ZZX-' 
	XCALL OUTPT (11,40,0,ALPHA(1,20),V)
	
	RETURN

ITMMAS,
	XCALL GETIM (9,10,KEY,ORGINV,SRCCTL,PITEM)			;;;
	IF (SRCCTL)
	BEGIN
	  XCALL MESAG ('Invalid item number',2)
	  RETURN
	END
	XCALL OUTPT (ROW,40,0,DESCR,V)
			; Display the description of the item.

	XCALL OUTPT (ROW,64,0,' Item OK <Y> ? ',V)
	CTL (4,14) = '79,01,00,YY'
	CALL INPUT
	XCALL OUTPT (ROW,64,1,'\',V)
	IF (INXCTL.NE.1) SRCCTL = 1
	RETURN

CLRTAG,
;;;	FOR I = 1 STEP 1 UNTIL J
;;;	  DO XCALL OUTPT (ROW+I-1,65,1,'\',V)
	for i from 1 thru j XCALL OUTPT (ROW+I-1,65,1,'\',V)
	RETURN
CLRACC,
;;;	FOR I = 14 STEP 1 UNTIL 22
;;;	  DO XCALL OUTPT (I,19,1,'\',V)
	for i from 14 thru 22 XCALL OUTPT (I,19,1,'\',V)

	SLIPS	=		;---------------------
	SLPITM	=		;Slips
	SLPPRC	=		;
	SLPDES	=		;---------------------
	DRIVES	=		;---------------------
	DRVITM	=		;Drives
	DRVPRC	=		;
	DRVDES	=		;---------------------
	TCORN	= 		;---------------------
	CORITM	= 		;Corners
	CORPRC	=		;
	CORDES	=		;---------------------
	TNBQTY	=		;---------------------
	TNBITM	=		;TDC nuts & bolts
	TNBPRC	=		;
	TNBDES	=		;---------------------
	TGAQTY	=		;---------------------
	TGAITM	=		;Gasket
	TGAPRC	=		;
	TGADES	=		;---------------------
	TCLQTY	=		;---------------------
	TCLITM	=		;Cleats
	TCLPRC	=		;
	TCLDES	=		;---------------------
	TBAQTY	=		;---------------------
	TBAITM	=		;TDC bar
	TBAPRC	=		;
	TBADES	=		;---------------------
	TBNQTY	=		;---------------------
	TBNITM	=		;TDC bar nuts & bolts
	TBNPRC	=		;
	TBNDES	=		;---------------------
	RETURN
END
