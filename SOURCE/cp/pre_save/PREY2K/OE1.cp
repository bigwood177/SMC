SUBROUTINE OE1
;
; OE1 / COP 
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
;		DISPLAY MENU FOR OE; CALLED FROM AN OVERLAY REGION
;
	OMLTAR	,A
	V	,D
PROC
	XCALL OUTPT (1,25,2,'\',V)
	XCALL OUTPT (2,4,0,'1. ORDER #',V)
	XCALL OUTPT (2,31,0,'2. DATE',V)
	XCALL OUTPT (2,50,0,'3. PROMISED DATE',V)
	XCALL OUTPT (3,4,0,'4. CUST #',V)
	XCALL OUTPT (3,50,0,'   CREDIT CODE  ',V)	;;; ADDED DS 1/7/87
	XCALL OUTPT (4,4,0,'5. SALESMN',V)
	XCALL OUTPT (4,23,0,'6. ORD/EST ',V)
	XCALL OUTPT (4,40,0,'7. SHIP VIA',V)
	XCALL OUTPT (4,59,0,'8. PO #',V)
	XCALL OUTPT (5,4,0,'9. DISCNT',V)
	XCALL OUTPT (5,22,0,'10. TERMS',V)
	XCALL OUTPT (5,39,0,'11. COLL/PPD',V)
	XCALL OUTPT (5,58,0,'12. JOB #',V)
	XCALL OUTPT (6,3,0,'13. SHIP-TO',V)
	XCALL OUTPT (13,7,0,'14.',1)
	XCALL OUTPT (14,7,0,'15.',1)
	XCALL OUTPT (15,7,0,'16.',1)
	XCALL OUTPT (16,7,0,'17.',1)
	XCALL OUTPT (10,3,0,'18. COMMENT',V)
	XCALL OUTPT (10,58,0,'19. AR ACCT #',V)
	XCALL OUTPT (11,58,0,'20. TAX FLAG ',V)
	RETURN
END
