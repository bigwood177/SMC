;  CLRCRL / COP 
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
;		CLEARS CREDIT MEMO LINE ITEM FILE WITH BRACKET RECORDS
;
RECORD
	,A64,'THIS MATERIAL CONTAINS THE VALUABLE PROPERTIES AND TRADE SECRETS'
	,A62,'OF MCBA, EMBODYING CONFIDENTIAL INFORMATION AND IDEAS, NO PART'
	,A56,'OF WHICH MAY BE USED AND/OR DISCLOSED WITHOUT MCBAs DULY'
	,A55,'AUTHORIZED LICENSE AGREEMENT AND/OR WRITTEN PERMISSION.'
	,A61,'COPYRIGHT (C) MCBA, AN UNPUBLISHED WORK. ALL RIGHTS RESERVED.'

RECORD CRMLIN   	
		.INCLUDE 'DEF:RD047B.DEF'
RECORD BRACKS		
		.INCLUDE 'DEF:RD047C.DEF'
RECORD
	SWITCH	,D1
	WRTCNT	,D5,00001
	V	,D1
	READ	,D1	,0
	WRITE	,D1	,1
	LOKCTL	,D1
PROC
	XCALL TERID (V)
	SWITCH = 5
	XCALL FILES (7,'U',47,SWITCH)		;FILE # 47 -- CRMLIN
	LOKCTL = 1
	XCALL IO (7,CRMLIN,1,READ,LOKCTL)
RITE,
	INCR WRTCNT
	LOKCTL = 1
	XCALL IO (7,BRACKS,WRTCNT,WRITE,LOKCTL)
	IF (WRTCNT.LT.REC047) GOTO RITE
	REC047 = 1
	LOKCTL = 1
	XCALL IO (7,CRMLIN,1,WRITE,LOKCTL)
	XCALL PGCHN ('CP:UNPRCM',1)
END
