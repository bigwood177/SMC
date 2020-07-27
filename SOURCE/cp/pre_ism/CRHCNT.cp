;  CRHCNT / COP 
;
;
;		::PCPYCOP.DEF::
;*********************************************************************
;		CUSTOMER ORDER PROCESSING 
;		
;		RELEASED: AUGUST 1, 1984 (d70s10)
;***********************************************************************
;
;		PROPRIETARY RIGHTS NOTICE:  All rights reserved.  This
;		material contains the valuable properties and trade secrets
;		of MCBA, Glendale, California, USA embodying substantial
;		creative effort and confidential information and ideas, no
;		part of which may be used and/or disclosed without MCBA's
;		duly authorized license agreement and/or written permission.
;
;		COPYRIGHT NOTICE:  Copyright <C> 1978, 1981, 1982, 1983, 1984
;		MCBA, AN UNPUBLISHED WORK.  ALL RIGHTS RESERVED.
;
;
;		COMPILE & LINK PER INSTALLATION OR TECHNICAL NOTES.
;
;:
;
;
RECORD
	,A64,'THIS MATERIAL CONTAINS THE VALUABLE PROPERTIES AND TRADE SECRETS'
	,A62,'OF MCBA, EMBODYING CONFIDENTIAL INFORMATION AND IDEAS, NO PART'
	,A56,'OF WHICH MAY BE USED AND/OR DISCLOSED WITHOUT MCBAs DULY'
	,A55,'AUTHORIZED LICENSE AGREEMENT AND/OR WRITTEN PERMISSION.'
	,A61,'COPYRIGHT (C) MCBA, AN UNPUBLISHED WORK. ALL RIGHTS RESERVED.'

RECORD SNDMSG
		,A3,'CP:'
		,A6,'ALNINV'
		,A10
		,D3,047
		,A3
RECORD NXTMSG
		,A3,'CP:'
		,A6,'PRTCRM'
RECORD RVCMSG
		,A10
RECORD
	V	,D1
	SWITCH	,D1
	BLANKS	,A10
PROC
	XCALL TERID (V)
	SWITCH = 1
	XCALL SNMSG (RVCMSG,SWITCH)
	IF (SWITCH.EQ.9) GOTO RECEVE
	SWITCH = 3
	XCALL SNMSG (BLANKS,SWITCH)
RECEVE,
	SWITCH = 2
	XCALL SNMSG (SNDMSG,SWITCH)
	SWITCH = 2
	XCALL SNMSG (NXTMSG,SWITCH)
	XCALL PGCHN ('CP:SRTCRL',0)
	END
