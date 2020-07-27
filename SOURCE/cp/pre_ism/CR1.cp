SUBROUTINE CR1
;
;  CR1 / COP 
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
	CMLAR	,A
	V	,D
PROC
	XCALL OUTPT (1,1,2,'CR MEMO ENTRY & EDITING',V)
	XCALL OUTPT (2,1,0,'ADD',1)
	XCALL OUTPT (2,6,0,'*CR MEMO #',V)
	XCALL OUTPT (2,32,0,'1. APPLY-TO',V)
	XCALL OUTPT (2,57,0,'2. DATE',V)
	XCALL OUTPT (3,3,0,'3. CUSTOMER #',V)
	XCALL OUTPT (4,3,0,'4. SALESMAN',V)
	XCALL OUTPT (4,32,0,'5. LOCATION',V)
	XCALL OUTPT (5,3,0,'6. CUST PO #',V)
	XCALL OUTPT (5,32,0,'7. DISCOUNT %',V)
	XCALL OUTPT (6,3,0,'8. SHIPPED TO #',V)
	XCALL OUTPT (13,7,0,'9.',1)
	XCALL OUTPT (14,6,0,'10.',1)
	XCALL OUTPT (15,6,0,'11.',1)
	XCALL OUTPT (16,6,0,'12.',1)
	XCALL OUTPT (10,2,0,'13. COMMENTS',V)
	IF (CMLAR.EQ.'Y') XCALL OUTPT (10,58,0,'14. A/R ACCT',V)
	RETURN
	END
