SUBROUTINE CR2
;
;  CR2 / COP 
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
;		DISPLAY MENU FOR CRMEMO; CALLED FROM AN OVERLAY REGION
;
	CCUSNM	,A
	CDISCT	,A
	V	,D
PROC
	XCALL OUTPT (1,1,1,'CR MEMO ENTRY & EDITING',V)
	XCALL OUTPT (2,1,1,'ADD',1)
	XCALL OUTPT (1,29,0,CCUSNM,V)
	XCALL OUTPT (1,62,0,'DISCOUNT: ',V)
	XCALL OUTPT (0,0,0,CDISCT,V)
	XCALL OUTPT (0,0,0,'%',V)
	XCALL OUTPT (2,1,1,'ITEM #',V)
	XCALL OUTPT (2,17,0,'DESCRIPTION',V)
	XCALL OUTPT (2,49,0,'QTY',V)
	XCALL OUTPT (2,56,0,'PRICE',V)
	XCALL OUTPT (2,64,0,'DISC',V)
	XCALL OUTPT (2,70,0,'EXT-PRICE',V)
	RETURN
	END
