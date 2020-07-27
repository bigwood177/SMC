;  SSMCNT.COP 
;
;		PROGRAM TO UPDATE SORTED RECORD COUNTER AFTER
;		A SORT & TURN OFF FILE PROTECTION
RECORD SSMCTL
		.INCLUDE 'DEF:RD058B.DEF'
RECORD
	PROGNM	,A9
	BLANKS	,A9
	SWITCH	,D1
	V	,D1
	READ	,D1	,0
	WRITE	,D1	,1
	LOKCTL	,D1

PROC (1)
	XCALL TERID (V)
	XCALL OUTPT (2,01,1,'UPDATE RECORD COUNTS',1)
	XCALL WATE (4,V)
	SWITCH = 1
	XCALL FILES (1,'U',058,SWITCH)
	IF (SWITCH.NE.1) GOTO ABORT

	LOKCTL = 1
	XCALL IO (1,SSMCTL,1,READ,LOKCTL)
	ORG058 = REC058
	LOKCTL = 1
	XCALL IO (1,SSMCTL,1,WRITE,LOKCTL)
	XCALL FILES (1,'U',058,4)
	SWITCH = 1
	XCALL SNMSG (PROGNM,SWITCH)
	IF (SWITCH.EQ.9.OR.PROGNM.EQ.BLANKS) GOTO NEXT
	SWITCH = 3
	XCALL SNMSG(BLANKS,SWITCH)
	XCALL PGCHN (PROGNM,1)
ABORT,
	XCALL MESAG ('COULD NOT UPDATE SORTED COUNT IN "SLSSUM" FILE',1)
NEXT,
	XCALL PGCHN ('CP:CLRORD',1)
END