; SV2MNT.COP - SHIPVIA2 MAINTENANCE PROGRAM
;
;
RECORD TRKMAS
		.INCLUDE 'DEF:RD180A.DEF'	
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
		,A1
	POS	,D2

RECORD
	V	,D1
	LOKCTL	,D1
	READ	,D1,0
	WRITE	,D1,1
	STORE	,D1,2
	DELETE	,D1,3
	INXCTL	,D1
	ENTRY	,A25
	SWITCH	,D1
	CNGCTL	,D1
	WHATNO	,D2
	BLANKS	,A15
	SELECT	,D1
	ALPHA	,A15
	KTRKNAM	,A15
PROC
	XCALL TERID (V)
	XCALL OUTPT (1,1,2,'TRUCK LINE MAINTENANCE',1)
OPENS,
	SWITCH = 1
	XCALL FILES (80,'SU',180,SWITCH)
	IF (SWITCH.NE.9) GOTO DISPLA
	GOTO ABORT
DISPLA,
	UNLOCK 80
	TRKMAS =
	SELECT =
	XCALL OUTPT ( 6,10,2,'1. TRUCKING COMPANY NAME',1)
	XCALL OUTPT ( 8,10,0,'2. TELEPHONE NUMBER 1 (TRAFFIC)',1)
	XCALL OUTPT (10,10,0,'3. CONTACT PERSON   1',1)
	XCALL OUTPT (12,10,0,'4. TELEPHONE NUMBER 2 (TRACING)',1)
	XCALL OUTPT (14,10,0,'5. CONTACT PERSON   2',1)

TRKNAM,
	CTL = '06,42,15,01,AE,00'
ASK1B,
	CALL CINPUT
	GOTO (DISPLA,ENDOFF,TRKNAM,ASK1C), INXCTL
	KTRKNAM = ENTRY
	IF (POS) TRKNAM(1,POS) = ENTRY(1,POS)
	IF (POS) READ (80,TRKMAS,TRKNAM(1,POS)) [KEY=ASK1B, EOF=ASK1B]
	XCALL OUTPT (ROW,COL,0,TRKNAM,1)
	GOTO ASK1B	
ASK1C,
	IF (ENTRY.EQ.BLANKS) GOTO DISPLA
	IF (TRKNAM(1,POS).EQ.ENTRY(1,POS)) 
	BEGIN
	  SELECT = 2
	  GOTO DSPREC
	END
	XCALL OUTPT (24,1,1,'NO RECORD FOR THIS TRUCK LINE - ADD <Y> ?',1)
	CTL = '24,43,01,00,YY'
	CALL INPUT
	IF (INXCTL.NE.1) GOTO DISPLA
	SELECT = 1
	TRKNAM = KTRKNAM
TKTEL1,
	CTL = '08,42,10,00,# '
	CALL INPUT
	GOTO (DISPLA), INXCTL
	TKTEL1 = ENTRY
	ALPHA(1,13) = TKTEL1,'(XXX)XXX-XXXX'
	IF (TKTEL1(1,3).EQ.0) ALPHA(1,13) = TKTEL1,'ZZZZZXXX-XXXX'
	XCALL OUTPT (ROW,COL,0,ALPHA(1,13),1)
	GOTO (ANYCNG), CNGCTL
TKCON1,
	CTL = '10,42,25,00,A '
	CALL INPUT
	GOTO (DISPLA), INXCTL
	TKCON1 = ENTRY
	GOTO (ANYCNG), CNGCTL
TKTEL2,
	CTL = '12,42,10,00,# '
	CALL INPUT
	GOTO (DISPLA), INXCTL
	TKTEL2 = ENTRY
	ALPHA(1,13) = TKTEL2,'(XXX)XXX-XXXX'
	IF (TKTEL2(1,3).EQ.0) ALPHA(1,13) = TKTEL2,'ZZZZZXXX-XXXX'
	XCALL OUTPT (ROW,COL,0,ALPHA(1,13),1)
	GOTO (ANYCNG), CNGCTL
TKCON2,
	CTL = '14,42,25,00,A '
	CALL INPUT
	GOTO (DISPLA), INXCTL
	TKCON2 = ENTRY
	GOTO ANYCNG
DSPREC,
	CTL = '06,42,15,01,AE,00'
	XCALL OUTPT (ROW,COL,0,TRKNAM,1)
	CTL = '08,42,10,0,# '
	ALPHA(1,13) = TKTEL1,'(XXX)XXX-XXXX'
	IF (TKTEL1(1,3).EQ.0) ALPHA(1,13) = TKTEL1,'ZZZZZXXX-XXXX'
	XCALL OUTPT (ROW,COL,0,ALPHA(1,13),1)
	XCALL OUTPT (10,42,0,TKCON1,1)
	CTL = '12,42,10,0,# '
	ALPHA(1,13) = TKTEL2,'(XXX)XXX-XXXX'
	IF (TKTEL2(1,3).EQ.0) ALPHA(1,13) = TKTEL2,'ZZZZZXXX-XXXX'
	XCALL OUTPT (ROW,COL,0,ALPHA(1,13),1)
	XCALL OUTPT (14,42,0,TKCON2,1)
ANYCNG,
	XCALL ANYCN (CNGCTL,WHATNO)
	IF (CNGCTL) 
	BEGIN
	  GOTO (ASKDEL,TKTEL1,TKCON1,TKTEL2,TKCON2), WHATNO
	  GOTO ANYCNG
	END
	GOTO (ADD,CHANGE), SELECT
	GOTO DISPLA
ASKDEL,
	XCALL OUTPT (24,1,1,'CANNOT CHANGE TRUCK LINE NAME - DELETE <N> ?',1)
	CTL = '24,46,01,00,YN'
	CALL INPUT
	IF (INXCTL.NE.1) GOTO ANYCNG	
DELETE,
	LOKCTL = 1
	XCALL ISIO (80,TRKMAS,TRKNAM,DELETE,LOKCTL)
	XCALL MESAG ('RECORD DELETED',2)
	GOTO DISPLA
CHANGE,
	LOKCTL = 1
	XCALL ISIO (80,TRKMAS,TRKNAM,WRITE,LOKCTL)
	GOTO DISPLA
ADD,
	LOKCTL = 1
	XCALL ISIO (80,TRKMAS,TRKNAM,STORE,LOKCTL)
	GOTO DISPLA
ENDOFF,
	CALL CLOSES
ABORT,
	XCALL PGCHN ('CP:BLADIN',1)
CLOSES,
	XCALL FILES (80,'SU',180,4)
	RETURN
INPUT,
	XCALL INPUT (ROW,COL,MAX,MIN,TYPE,ENTRY,INXCTL,1)
	RETURN
CINPUT,
	XCALL CINPUT (ROW,COL,MAX,MIN,TYPE,ENTRY,INXCTL,POS)
	RETURN
END
