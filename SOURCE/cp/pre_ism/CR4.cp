SUBROUTINE CR4
;
;  CR4 / COP 
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
	V	,D
PROC
	XCALL OUTPT (1,30,2,'\',V)
	XCALL OUTPT (2,22,0,'*CR MEMO #',V)
	XCALL OUTPT (3,20,0,'1. APPLY-TO',V)
	XCALL OUTPT (4,20,0,'2. DATE',V)
	XCALL OUTPT (5,20,0,'3. CUSTOMER #',V)
	XCALL OUTPT (6,20,0,'4. SALESMAN',V)
	XCALL OUTPT (7,20,0,'5. LOCATION',V)
	XCALL OUTPT (8,20,0,'6. CUST PO #',V)
	XCALL OUTPT (9,20,0,'7. DISCOUNT %',V)
	XCALL OUTPT (10,20,0,'8. COMMENTS',V)
	RETURN
	END
