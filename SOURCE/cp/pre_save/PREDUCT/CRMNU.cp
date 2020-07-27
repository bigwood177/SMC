SUBROUTINE CRMNU
;
;  CRMNU / COP 
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
;		DISPLAY MENU FOR CRMEMO PROGRAM
;
	OPTION	,D
	V	,D
RECORD
	ENTRY	,A3
	INXCTL	,D1
	READ	,D1	,0
	WRITE	,D1	,1
	LOKCTL	,D1
PROC
	XCALL OUTPT (1,1,2,'CREDIT MEMO ENTRY & EDITING',V)
	XCALL OUTPT (5,20,0,'PLEASE SELECT APPLICATION',V)
	XCALL OUTPT (6,25,0,'1. ENTER NEW CREDIT MEMOS',V)
	XCALL OUTPT (7,25,0,'2. CANCEL CREDIT MEMOS',V)
	XCALL OUTPT (8,25,0,'3. PRINT CR MEMO EDIT LIST',V)
	XCALL OUTPT (9,25,0,'4. PRINT CREDIT MEMOS',V)
INPUT,
	XCALL INPUT(5,47,1,1,'#E',ENTRY,INXCTL,V)
	GO TO (END), INXCTL - 1
	IF (ENTRY(2,3).NE.'  ') GOTO INPUT
	ONERROR INPUT
	OPTION = ENTRY(1,1)
	IF (OPTION.LT.1.OR.OPTION.GT.4) GOTO INPUT
	XCALL OUTPT (12,1,0,'PLEASE WAIT ...',V)
	RETURN
END,
	OPTION = 5
	RETURN
	END
