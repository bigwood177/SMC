;SRTPRC.cp
;dbl sort template
RECORD	SRTREC
.INCLUDE 'DEF:RD059B.DEF'
 
RECORD	FFILE
	FILNUM	,D3
	CLCTL	,D1
	REDFIL	,A14
 
RECORD SNDMSG
		,A3
	PRGNAM	,A6
	RCNT	,D5
	OCNT	,D5
	MFIL	,D3
		,A3
 
RECORD,X
	PROGRM	,A9
 
RECORD	HEADER
		,A7,	'DBSORT '
	HFILE	,A14
 
RECORD	VARS
	V	,D1
	MSG	,A14
	XFIL	,D3,	059
	SWITCH	,D1
PROC
	XCALL TERID (V)
 
	SWITCH = 1
	XCALL SNMSG (SNDMSG,SWITCH)	;GET MESSAGE, IF ANY
	IF (SWITCH .EQ. 9)
		BEGIN
		FILNUM = XFIL		;HARD CODE IF NO MESSAGE
		GOTO NOMSG		;NO MESSAGE
		END
	SWITCH = 3
	XCALL SNMSG (' ',SWITCH)	;DELETE MESSAGE
 
NOMSG,
	FILNUM = XFIL			;HARD CODE IF NO MESSAGE
	XCALL FFILE (FILNUM,REDFIL,CLCTL)	;GET FILE SPEC
	HFILE = REDFIL
 
	XCALL OUTPT (2,1,2,HEADER,1)
 
	SORT (IN=REDFIL,
&		RECORD=SRTREC,
&		KEY = (SIPROD,SICUS)
&		)
 
	XCALL PGCHN (PROGRM,1)
	END
 
