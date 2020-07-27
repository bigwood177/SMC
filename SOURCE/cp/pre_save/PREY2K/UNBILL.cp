;  UNBILL / COP 
;
;

RECORD ORDHDR   	
		.INCLUDE 'DEF:RD044A.DEF'
RECORD ORDLIN   	
		.INCLUDE 'DEF:RD045A.DEF'
RECORD	,X		
		.INCLUDE 'DEF:RD045D.DEF'
RECORD DUCACC
		.INCLUDE 'DEF:RD175A.DEF'
RECORD COPCTL
		.INCLUDE 'DEF:RD060A.DEF'
RECORD ARTERM
		.INCLUDE 'DEF:RD170A.DEF'
RECORD ARTCTL
		.INCLUDE 'DEF:RD170B.DEF'

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;RECORD SHPVIA
;;;		.INCLUDE 'DEF:RD172A.DEF'
;;;RECORD SHVCTL
;;;		.INCLUDE 'DEF:RD172B.DEF'
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

RECORD SHIPTO
		.INCLUDE 'DEF:RD171A.DEF'
RECORD SHPCTL
		.INCLUDE 'DEF:RD171B.DEF'
RECORD CUSMAS  		
		.INCLUDE 'DEF:RD001A.DEF'
RECORD CUSCTL	
		.INCLUDE 'DEF:RD001B.DEF'
RECORD CUSIDX  		
		.INCLUDE 'DEF:RD002A.DEF'
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
	SWITCH	,D1,1
	L	,2D1
	V	,D1
	ENDLIN	,D1
	ENTRY	,A7
	INXCTL	,D1
	DECMAL	,D18
	OPTION	,D1
	KEYNO	,D6
	MASK	,A8,'XXXX-XXX'
	ORGORD	,D5
	ORGLIN	,D5
	ORECNO	,D5,00001
	LRECNO	,D5,00001
	ALPHA	,A10
	COUNT	,D1
	BLANKS	,A35
	ROW2	,D2
	READ	,D1	,0
	WRITE	,D1	,1
	LOKCTL	,D1
	BSEND	,D5
	BSMID	,D5
	SRCCTL	,D1
PROC
	XCALL TERID(V)
	CALL OPENS
	GO TO UNSEL
END,
	XCALL WATE(3,V)
	CALL CLOSES
	GO TO END1
END9,
	CALL CLOSE8
	GO TO END1
END8,
	CALL CLOSE7
	GO TO END1
END7,
	CALL CLOSE6
	GO TO END1
END6,
	CALL CLOSE5
	GO TO END1
END5,
	CALL CLOSE4
	GO TO END1
END4,
	CALL CLOSE3
	GO TO END1
END3,
	CALL CLOSE2
	GO TO END1
END2,
	CALL CLOSE1
END1,
	XCALL PGCHN ('CP:BILLS',1)
UNSEL,
	CALL DSPORD
	IF (INXCTL.EQ.2)GO TO END
	CALL UNSET
	GO TO UNSEL
;
;
OPENS,
	SWITCH = 1
	XCALL FILES (4,'SU',44,SWITCH)		;#44 - ORDHDR
	IF (SWITCH.EQ.9) GO TO END1
	XCALL FILES (5,'SU',45,SWITCH)		;#45 - ORDLIN
	IF (SWITCH.EQ.9) GO TO END2
	SWITCH = 1
	XCALL FILES (3,'I',60,SWITCH)		;#60 - COPCTL
	IF (SWITCH.EQ.9) GO TO END3
	SWITCH = 1
	XCALL FILES (6,'I',170,SWITCH)		; FILE # 170 -- ARTERM
	IF (SWITCH.EQ.9) GO TO END4
	SWITCH = 1
	XCALL FILES (7,'I',171,SWITCH)		; FILE # 171 -- SHIPTO
	IF (SWITCH.EQ.9) GO TO END5
	SWITCH = 1
	XCALL FILES (8,'I',172,SWITCH)		; FILE # 172 -- SHPVIA
	IF (SWITCH.EQ.9) GO TO END6
	SWITCH = 1
	XCALL FILES (9,'I',002,SWITCH)		; FILE # 002 -- CUSIDX
	IF (SWITCH.EQ.9) GO TO END7
	SWITCH = 1
	XCALL FILES (10,'I',001,SWITCH)		; FILE # 001 -- CUSMAS
	IF (SWITCH.EQ.9) GO TO END8
	SWITCH = 1
	XCALL FILES (2,'SU',175,SWITCH)		; FILE # 175 -- DUCACC
	IF (SWITCH.EQ.9) GOTO END9
	LOKCTL = 1
	XCALL IO (10,CUSCTL,1,READ,LOKCTL)
RDCTL,
	LOKCTL = 1
	XCALL IOS (3,COPCTL,READ,LOKCTL)
	RETURN
CLOSES,
	XCALL FILES (2,'SU',175,4)
CLOSE8,
	XCALL FILES (10,'I',001,4)
CLOSE7,
	XCALL FILES (9,'I',002,4)
CLOSE6,
	XCALL FILES (8,'I',172,4)
CLOSE5,
	XCALL FILES (7,'I',171,4)
CLOSE4,
	XCALL FILES (6,'I',170,4)
CLOSE3,
	XCALL FILES (3,'I',60,4)
CLOSE2,
	XCALL FILES (5,'SU',45,4)
CLOSE1,
	XCALL FILES (4,'SU',44,4)
	RETURN
INPUT,
	XCALL INPUT(ROW,COL,MAX,MIN,TYPE,ENTRY,INXCTL,V)
	RETURN
DSPORD,
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;	LOKCTL = 1
;;;	XCALL IO (8,SHVCTL,1,READ,LOKCTL)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	LOKCTL = 1
	XCALL IO (6,ARTCTL,1,READ,LOKCTL)

	CALL DISPL1
	IF (INXCTL.EQ.2) RETURN
	XCALL OUTPT (12,1,1,'RIGHT ORDER ?',V)
	CTL = '12,16,01,01,YN'
	CALL INPUT
	IF (INXCTL.EQ.2) GO TO DSPORD
	RETURN
DISPL1,
	XCALL OE1 (DSTFLG,V)
	XCALL OUTPT (2,1,0,'UNSELECT',1)
	XCALL OUTPT (2,3,0,'*',V)
	CTL = '02,16,06,01,#E'
	CALL INPUT
	IF (INXCTL.EQ.2) RETURN
	OORDNO = ENTRY
	LOKCTL = 1
	XCALL ISIO (4,ORDHDR,OORDNO,READ,LOKCTL)
	IF (LOKCTL) GO TO NOFIND
	OCOST =
DSPDAT,
	CTL = '02,40'
	DECMAL(1,6) = OORDDT
	CALL DSPDTE
	CTL = '02,68'
	DECMAL(1,6) = OSHDAT
	CALL DSPDTE
	CTL = '03,16,05'
	DECMAL = OCUSNO
	CALL DSPNUM
	XCALL OUTPT (3,24,0,OCUSNM,V)
	CTL = '04,16,02'
	DECMAL = OSLMAN
	CALL DSPNUM
	XCALL OUTPT (4,35,0,OLOC,V)

	XCALL OUTPT (8,53,0,OSCAC,1)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;	XCALL OUTPT (8,53,0,OSHVIA,1)
;;;	SRCCTL = 2
;;;	BSEND = ORG172
;;;	XCALL SERCH (8,SHPVIA,OSHVIA,1,1,BSEND,BSMID,SRCCTL,1,2,7,0,0,0,0)
;;;	GO TO (SHVNFD), SRCCTL
;;;	XCALL OUTPT (9,53,0,SHPVDS,1)	
;;;	GO TO SHVOK
;;;SHVNFD,
;;;	XCALL OUTPT (9,53,0,'SHIP-VIA NOT ON FILE',1)
;;;SHVOK,
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

	XCALL OUTPT (4,69,0,OPONO,V)
	CTL = '05,16,02'
	DECMAL = ODISC
	CALL DSPNUM
	XCALL OUTPT (10,33,0,OTERMS,1)
	SRCCTL = 2
	BSEND = ORG170
	XCALL SERCH (6,ARTERM,OTERMS,1,1,BSEND,BSMID,SRCCTL,1,2,7,0,0,0,0)
	GO TO (TRMNFD), SRCCTL
	XCALL OUTPT (11,33,0,ARTRDS,1)
	GO TO TERMOK
TRMNFD,
	XCALL OUTPT (11,33,0,'TERM NOT ON FILE',1)
TERMOK,
	XCALL OUTPT (10,53,0,OCLPPD,1)
	XCALL OUTPT (5,69,0,OJOBNO,V)
DSPADD,
	XCALL OUTPT (6,16,0,OSHPTO,V)
	XCALL OUTPT (13,13,0,OSHPNM,1)
	XCALL OUTPT (14,13,0,OSHAD1,1)
	XCALL OUTPT (15,13,0,OSHAD2,1)
	XCALL OUTPT (16,13,0,OSHAD3,1)
	XCALL OUTPT (10,16,0,OCOMNT(1),V)
	XCALL OUTPT (11,16,0,OCOMNT(2),V)
	IF (DSTFLG.NE.'Y') RETURN
	ALPHA (1,8) = OARACT, MASK
	XCALL OUTPT (11,73,0,ALPHA(1,8),V)
	RETURN
NOFIND,
	XCALL MESAG ('ORDER NOT FOUND',1)
	GO TO DISPL1
DSPNUM,
	OPTION = 1
	GOTO CALDSP
DSPDTE,
	OPTION = 2
	GOTO CALDSP
DSPDLR,
	OPTION = 3
CALDSP,
	XCALL DSPLY(MAX,ROW,COL,DECMAL,OPTION,V)
	RETURN
UNSET,
	OFLAG =
	ODSCAL =
	ENDLIN =
	LOKCTL = 1
	XCALL ISIO (4,ORDHDR,OORDNO,WRITE,LOKCTL)
	CALL FNDFST
	IF (ENDLIN) GO TO FNDDUC
RDIT,
	LFLAG =
	LOKCTL = 1
	XCALL ISIO (5,ORDLIN,ORDKEY,WRITE,LOKCTL)
	CALL RDLIN
	IF (ENDLIN) GO TO FNDDUC
	GO TO RDIT
FNDDUC,
	DUCTOR = OORDNO
	LOKCTL = 1
	XCALL ISIO (2,DUCACC,DUCTOR,READ,LOKCTL)
	IF (LOKCTL.NE.0.OR.DUCTOR.NE.OORDNO) GOTO EOFDUC
	GOTO UNSELD
NXTDUC,
	LOKCTL = 1
	XCALL IOS (2,DUCACC,READ,LOKCTL)
	IF (LOKCTL.NE.0.OR.DUCTOR.NE.OORDNO) GOTO EOFDUC
UNSELD,
	FLG175 =
	LOKCTL = 1
	XCALL ISIO (2,DUCACC,KEY175,WRITE,LOKCTL)
	GOTO NXTDUC
EOFDUC,
	UNLOCK 2
UNMSG,
	XCALL MESAG ('ORDER UNSELECTED',2)
	RETURN
FNDFST,
	LORDNO = OORDNO
	LINSEQ =
	LOKCTL = 1
	XCALL ISIO (5,ORDLIN,ORDKEY,READ,LOKCTL)
	IF (LOKCTL.EQ.3) GO TO NOLINE
	IF (LORDNO.NE.OORDNO) GO TO NOLINE
	RETURN
NOLINE,
	XCALL MESAG ('NO ITEMS IN THIS ORDER',1)
	GOTO EOFLIN
RDLIN,
	LOKCTL = 1
	XCALL IOS (5,ORDLIN,READ,LOKCTL)
	IF (LOKCTL.EQ.2) GO TO EOFLIN
	IF (LORDNO.NE.OORDNO) GO TO EOFLIN
	IF (LQTYOR.EQ.0) GO TO RDLIN
	RETURN
EOFLIN,
	ENDLIN = 1
	UNLOCK 5
	RETURN
END
