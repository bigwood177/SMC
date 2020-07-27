; PDACNT / COP 
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
;		PROGRAM TO UPDATE SORTED RECORD COUNTER AFTER
;		A SORT & TURN OFF FILE PROTECTION
;
;
RECORD
	,A64,'THIS MATERIAL CONTAINS THE VALUABLE PROPERTIES AND TRADE SECRETS'
	,A62,'OF MCBA, EMBODYING CONFIDENTIAL INFORMATION AND IDEAS, NO PART'
	,A56,'OF WHICH MAY BE USED AND/OR DISCLOSED WITHOUT MCBAs DULY'
	,A55,'AUTHORIZED LICENSE AGREEMENT AND/OR WRITTEN PERMISSION.'
	,A61,'COPYRIGHT (C) MCBA, AN UNPUBLISHED WORK. ALL RIGHTS RESERVED.'

RECORD PRDACT		
		.INCLUDE 'DEF:RD069B.DEF'
RECORD PROGNM
		,A10
RECORD
	V	,D1
	SWITCH	,D1
RECORD
	READ	,D1	,0
	WRITE	,D1	,1
	LOKCTL	,D1
	BLANKS	,A10
PROC
	XCALL TERID (V)
	XCALL OUTPT (2,1,0,'UPDATE COUNTER',1)
	SWITCH = 5
	XCALL FILES (7,'U',69,SWITCH)		;FILE # 69 -- PRDACT FILE
	LOKCTL = 1
	XCALL IO (7,PRDACT,1,READ,LOKCTL)
	ORG069 = REC069
	LOKCTL = 1
	XCALL IO (7,PRDACT,1,WRITE,LOKCTL)
	XCALL FILES (7,'U',69,4)
	SWITCH = 1
	XCALL SNMSG (PROGNM,SWITCH)
	IF (SWITCH.EQ.9) GOTO END
	SWITCH = 3
	XCALL SNMSG (BLANKS,SWITCH)
END,
	IF (PROGNM.EQ.'      ') XCALL PGCHN ('CP:CPMENU',1)
	XCALL PGCHN (PROGNM,1)
	END
