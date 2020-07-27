SUBROUTINE OE6
;
; OE6 / COP 
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
;		DISPLAY MENU FOR CHANGE; CALLED FROM AN OVERLAY REGION
;
	ORDNOA	,D
	OCUSNM	,A
	ODISC	,A
	V	,D
PROC
	XCALL OUTPT (2,1,2,'CHANGE',1)
	XCALL OUTPT (2,12,0,'ORDER: ',1)
	XCALL DSPLY (6,2,19,ORDNOA,1,1)
	XCALL OUTPT (0,0,0,'  CUST: ',V)
	XCALL OUTPT (0,0,0,OCUSNM,V)
	XCALL OUTPT (0,0,0,'  DISC: ',V)
	XCALL OUTPT (0,0,0,ODISC,V)
	XCALL OUTPT (0,0,0,'%',V)
	XCALL OUTPT (3,19,0,'*1. ITEM #',V)
	XCALL OUTPT (4,20,0,'2. DESCRIPTION',V)
	XCALL OUTPT (5,20,0,'3. SEQUENCE NO.',V)
	XCALL OUTPT (6,20,0,'4. UNIT-OF-MEAS',V)
	XCALL OUTPT (7,20,0,'5. QTY ORDERED',V)
	XCALL OUTPT (8,19,0,'*6. QTY B/O OR O/S',V)
	XCALL OUTPT (9,20,0,'7. PRICE',V)
	XCALL OUTPT (10,20,0,'8. DISCOUNT',V)
	XCALL OUTPT (10,51,0,'EXTENDED PRICE:',V)
	RETURN
	END
