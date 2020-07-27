SUBROUTINE PRTD2
;
;	PRINT DUCT LINE FOR BILLING EDIT LIST
;
	OORDNO	,D
	PLINE	,A
	STATUS	,D
	DUCTOT	,D
	LINTOT	,D
	ACCTOT	,D
;
GLOBAL DUCK;;;, INIT
		.INCLUDE 'DEF:RD175D.DEF'
ENDGLOBAL
;
RECORD PARAM
		.INCLUDE 'DEF:PARAM2.DEF'
RECORD
	QTY	,D5
	ITM	,A15
	DES	,A30
	PRC	,D7
	ACCUOM	,A2
	COMPA	,A57
	COMPB	,A57
RECORD ACCREC
	.INCLUDE 'DEF:ACCREC.DEF'
RECORD
	READ	,D1,0
	LOKCTL	,D1
	DECMAL	,D10
	BLANKS	,A20
PROC
;
;	STATUS CODE:
;	(INCOMIMG)	0 - FIND FIRST DUCT RECORD
;			1 - SETUP DUCT INFO
;			2 - SETUP LINER INFO
;			3 - FIND NEXT DUCT
;			4 - SETUP SUMM ACC INFO
;
;	(OUTGOING)	1 - PRINT DUCT INFO
;			2 - PRINT LINER INFO
;			3 - PRINT SUMM DUCT INFO
;			8 - ERROR IN ACC ARRAY PRINT & CONTINUE
;			9 - FINISHED WITH DUCT - CONTINUE
;
	GOTO (PRTDUC,LINER,NXTDUC,PRTSA2), STATUS

;;;
;	FIND FIRST DUCT RECORD
;;;
	DUCTOR = OORDNO
	LOKCTL = 1
	XCALL ISIO (5,DUCACC,DUCTOR,READ,LOKCTL)
	IF (LOKCTL.NE.0.OR.DUCTOR.NE.OORDNO) GOTO ORDTOT
	GOTO PRTDUC

;;;
;	FIND NEXT DUCT RECORD
;;;
NXTDUC,
	DUCTOR = OORDNO
	LOKCTL = 1
	XCALL IOS (5,DUCACC,READ,LOKCTL)
	IF (LOKCTL.NE.0.OR.DUCTOR.NE.OORDNO) GOTO PRTSAC

PRTDUC,
	PLINE (2,3) = GAUGE,'XX'
	PLINE (4,5) = 'GA'
	IF (DUTYPE.EQ.2.OR.DUTYPE.EQ.3) PLINE (2,5) = THICK,'.XXX'
	PLINE (7,9) = SIZE1,'ZZX'
	PLINE (10,12) = ' X '
	PLINE (13,14) = SIZE2,'ZX'
	PLINE (15,17) = ' X '
	PLINE (18,19) = SIZE3,'ZX'
	PLINE (22,25) = DTYPE(DUTYPE)
	PLINE (27,32) = DCAT(CAT)
	PLINE (34,36) = DSTY(STY)
	PLINE (38,40) = DSEAM(SEAM)
	IF (SEAL.EQ.1) PLINE (42,45) = 'SEAL'
	PLINE (47,52) = JOINT,'ZZZZX-'
	PLINE (53,54) = 'JT'
	PLINE (62,68) = POUNDS,'ZZZZZX-'
	PLINE (69,70) = 'LB'
	
	PLINE (73,83) = GPRICE,'ZZZ,ZZZ.XXX'
	PLINE (88,89) = 'LB'
	DECMAL = (GPRICE * POUNDS)#1
	PLINE (94,104) = DECMAL,'ZZZ,ZZZ.XX-'
	PLINE (114,124) = DECMAL,'ZZZ,ZZZ.XX-'
	DUCTOT = DUCTOT + DECMAL
	STATUS = 1
	RETURN

LINER,
	PLINE (22,28) = DLINER(LINER) 
	PLINE (30,34) = 'LINER'
	PLINE (40,50) = LOCAT
	PLINE (62,68) = SQFLIN,'ZZZZZX-'
	PLINE (69,70) = 'SQF'
	PLINE (73,83) = LINPRC,'ZZZ,ZZZ.XXX'
	PLINE (88,89) = 'SF'
	DECMAL = (LINPRC * SQFLIN)#1
	PLINE (94,104) = DECMAL,'ZZZ,ZZZ.XX-'
	PLINE (114,124) = DECMAL,'ZZZ,ZZZ.XX-'
	LINTOT = LINTOT + DECMAL
	STATUS = 2

ACCESS,
	IF (ACC.EQ.2) RETURN

	IF (SLIPS)
	BEGIN
	  QTY = SLIPS
	  ITM = SLPITM
	  PRC = SLPPRC
	  DES = SLPDES
	  CALL SUMACC
	END
	IF (DRIVES)
	BEGIN
	  QTY = DRIVES
	  ITM = DRVITM
	  PRC = DRVPRC
	  DES = DRVDES
	  CALL SUMACC
	END
	IF (TCORN)
	BEGIN
	  QTY = TCORN
	  ITM = CORITM
	  PRC = CORPRC
	  DES = CORDES
	  CALL SUMACC
	END
	IF (TNBQTY)
	BEGIN
	  QTY = TNBQTY
	  ITM = TNBITM
	  PRC = TNBPRC
	  DES = TNBDES
	  CALL SUMACC
	END
	IF (TGAQTY)
	BEGIN
	  QTY = TGAQTY
	  ITM = TGAITM
	  PRC = TGAPRC
	  DES = TGADES
	  CALL SUMACC
	END
	IF (TCLQTY)
	BEGIN
	  QTY = TCLQTY
	  ITM = TCLITM
	  PRC = TCLPRC
	  DES = TCLDES
	  CALL SUMACC
	END
	IF (TBAQTY)
	BEGIN
	  QTY = (JOINT * 4)
	  ITM = TBAITM
	  ITM (10,13) = SIZE1,'ZZX"'
	  PRC = TBAPRC
	  DES = TBADES
	  CALL SUMACC
	  QTY = (JOINT * 4)
	  ITM = TBAITM
	  ITM (10,13) = SIZE2,'ZZX"'
	  PRC = TBAPRC
	  DES = TBADES
	  CALL SUMACC
	END
	IF (TBNQTY)
	BEGIN
	  QTY = TBNQTY
	  ITM = TBNITM
	  PRC = TBNPRC
	  DES = TBNDES
	  CALL SUMACC
	END

	RETURN

SUMACC,
		; Check to see if the accessories have all ready 
		; been on this order
	I =
	DO BEGIN
	  INCR I
	  ACCREC = SACCRC(I)
	END
	UNTIL (ACCITM.EQ.ITM.OR.ACCITM.EQ.BLANKS.OR.I.GE.MAXACC-1)
	IF (I.GE.MAXACC-1) GOTO BADACC

	ACCQTY = ACCQTY + QTY
	ACCITM = ITM
	ACCPRC = PRC
	ACCDES = DES
	SACCRC(I) = ACCREC

	RETURN
BADACC,
	PLINE = '***** ACCESSORY ARRAY LIMIT REACHED, NOT ALL ITEMS PRINTED *****'
	STATUS = 8
	RETURN
PRTSAC,
;
;	BUBBLE SORT ACCREC ARRAY
;
;;;	FOR I = 1 STEP 1 UNTIL MAXACC
;;;	DO BEGIN
	for i from 1 thru maxacc
	BEGIN
	  ACCREC = SACCRC(I)
	  IF (ACCQTY.EQ.0) GOTO PRTSA1
	  COMPA = ACCITM
	  ACCREC = SACCRC(I+1)
	  IF (ACCQTY.EQ.0) GOTO PRTSA1
	  COMPB = ACCITM
	  IF (COMPA.GT.COMPB)
	  BEGIN
	    SACCRC(I+1) = SACCRC(I)
	    SACCRC(I) = ACCREC
	    I = I - 2
	    IF (I.LT.0) I = 0
	  END
	END
	GOTO BADACC
PRTSA1,		; Print summarized accessories from this order
	I =
PRTSA2,
	INCR I
	IF (I.GT.MAXACC) GOTO BADACC
	ACCREC = SACCRC(I)
	IF (ACCITM.EQ.BLANKS) GOTO ORDTOT
	PLINE (2,16) = ACCITM
	PLINE (18,47) = ACCDES
	PLINE (62,68) = ACCQTY, 'ZZZZZX-'
	ACCUOM = 'EA'
	IF (ACCITM(4,6).EQ.'GS ') ACCUOM = 'FT'
	IF (ACCITM(4,6).EQ.'BAR') 
	BEGIN
	  ACCUOM = 'IN'
	  DECMAL = ACCITM(10,12)
	  ACCQTY = ACCQTY * DECMAL
	END
	PLINE (73,83) = ACCPRC,'ZZZ,ZZZ.XXX'
	PLINE (88,89) = ACCUOM
	DECMAL = (ACCQTY * ACCPRC) #1
	PLINE (94,104) = DECMAL,'ZZZ,ZZZ.ZZ-'
	PLINE (114,124) = DECMAL,'ZZZ,ZZZ.ZZ-'
	ACCTOT = ACCTOT + DECMAL
	SACCRC(I) =
	STATUS = 3
	RETURN
ORDTOT,
	STATUS = 9
	RETURN
