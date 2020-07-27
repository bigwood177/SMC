;TBLMNT.COP
;
;		AUTHOR: SHERWOOD S. QUIRING
;		DATE  : 18-DEC-1996
;
RECORD	COPTBL
	.INCLUDE 'DEF:COPTBL.DEF'

RECORD	

RECORD	DPKEY
	K_GAUGE	,D3
	K_TYPE	,D1
	K_CAT	,D1
	K_STYLE	,D1

RECORD	CHANNEL
	CHN182	,D2

RECORD	VARS
	OPNOK	,D1
	ENTRY	,A30
	INXCTL	,D1
	WHATNO	,D2
	CNGCTL	,D1
	READ	,D1,0
	WRITE	,D1,1
	LOKCTL	,D1
	SWITCH	,D1
	V	,D1
PROC
	XCALL TERID (V)
	XCALL OUTPT (1,1,2,'DUCT PRICING TABLE',1)
	CALL OPENS
	IF (.NOT. OPNOK)
		BEGIN
		CALL CLOSE
		XCALL PGCHN ('CP:CPMENU',1)
		END

DISPLA,
	CLEAR CNGCTL
	XCALL OUTPT (1,1,2,'DUCT PRICING TABLE',1)
	XCALL OUTPT ( 4,4,0,'1. GAUGE',1)
	XCALL OUTPT ( 6,4,0,'2. TYPE',1)
	XCALL OUTPT ( 8,4,0,'3. CAT',1)
	XCALL OUTPT (10,4,0.'4. STYLE',1)
	XCALL OUTPT (12,4,0,'5. PRICE',1)
DP_GAUGE,
	XCALL INPUT (4,13,03,00,'#E',ENTRY,INXCTL,1)
	GOTO (DISPLA,ENDOFF),INXCTL
	DP_GAUGE = ENTRY(1,3)
	IF (DP_GAUGE.NE.18 .AND.
&	    DP_GAUGE.NE.20 .AND.
&	    DP_GAUGE.NE.22 .AND.
&	    DP_GAUGE.NE.24 .AND.
&	    DP_GAUGE.NE.26) GOTO DP_GAUGE
	GOTO (ANYCNG),CNGCTL
DP_TYPE,
	XCALL INPUT (6,13,01,00,'# ',ENTRY,INXCTL,1)
	GOTO (DISPLA),INXCTL
	DP_TYPE = ENTRY(1,1)
	IF (DP_TYPE .EQ. 0)
		BEGIN
		DP_TYPE = 1
		XCALL OUTPT (6,13,0,'1',1)
		END


OPENS,	;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	CLEAR OPNOK

	SWITCH = 5
	XCALL FILES (1,'SU',182,SWITCH)		;182 - COPTBL
	IF (SWITCH .EQ. 9) RETURN
	CHN182 = 1
	RETURN
;------------------------------------

CLOSE,	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	IF (CHN182) CLOSE CHN182
	RETURN
;------------------------------------

