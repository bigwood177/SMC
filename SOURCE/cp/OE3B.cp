SUBROUTINE OE3B
;
; OE3B / COP - MODIFIED FOR 3 SALES TAX FIELDS
;
;
;		DISPLAY MENU FOR BILLS; CALLED FROM AN OVERLAY REGION
;
	ORDNOA	,A
	CUSNOA	,A
	CUSNAM	,A
	OMLMSC	,A
	OMLTAX	,A
	OMLFRT	,A
	V	,D
PROC
	XCALL OUTPT (1,20,2,'CUSTOMER: ',V)
	XCALL OUTPT (0,0,0,CUSNOA,V)
	XCALL OUTPT (0,0,0,' ',V)
	XCALL OUTPT (0,0,0,CUSNAM,V)
	XCALL OUTPT (1,66,0,'ORDER #: ',V)
	XCALL OUTPT (0,0,0,ORDNOA,V)
	XCALL OUTPT (2,13,0,'ORDER NET =',V)
	XCALL OUTPT (2,42,0,'WEIGHT (LBS) =',V)
	XCALL OUTPT (3,10,0,'(TAXABLE AMT =             )',V)
	XCALL OUTPT (4,7,0,'1. FREIGHT',V)
	IF (OMLMSC.EQ.'Y') XCALL OUTPT (4,32,0,'ACCT-#:',V)
	XCALL OUTPT (5,7,0,'2. MISC CHGS',V)
	IF (OMLFRT.EQ.'Y') XCALL OUTPT (5,32,0,'ACCT-#:',V)
	XCALL OUTPT (6,10,0,'(TAXABLE MISC =           )',V)
	XCALL OUTPT (14,7,0,'3. SLS TAX-1',1)
	IF (OMLTAX.EQ.'Y') XCALL OUTPT (14,32,0,'ACCT-#:',1)
	XCALL OUTPT (15,7,0,'4. SLS TAX-2',1)
	IF (OMLTAX.EQ.'Y') XCALL OUTPT (15,32,0,'ACCT-#:',1)
	XCALL OUTPT (16,7,0,'5. SLS TAX-3',1)
	IF (OMLTAX.EQ.'Y') XCALL OUTPT (16,32,0,'ACCT-#:',1)
	XCALL OUTPT (17,22,0,'--------',1)
	XCALL OUTPT (18,7,0,'   TAX TOTAL',1)
	XCALL OUTPT (18,32,0,'TAX CD: ',1)
	XCALL OUTPT (20,10,0,'TOTAL =',1)
;;;	XCALL OUTPT (9,7,0,'4. COMMIS AMT',V)
;;;	XCALL OUTPT (10,7,0,'5. COMMIS PCT',V)
	RETURN
END
