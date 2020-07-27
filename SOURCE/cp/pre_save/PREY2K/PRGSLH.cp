;  PRGSLH / COP 
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
;		THIS PROGRAM WILL PURGE RECORDS FROM THE SLSHST FILE
;		BY SELECTED DATE RANGE. ENTRY OF THE PURGE DATE IS DONE
;		IN PGM HSTSEL, AND PASSED IN A MESSAGE (SEND/RECV) TO
;		THIS PROGRAM. (IF NO MESAGE IS RECEIVED, THEN THE USER
;		ELECTED NOT TO PURGE).
;
;		ITEMS ARE PURGED ONLY IF:
;			(1) THEY HAVE BEEN POSTED (IE.. POSTED=2)
;		AND     (2) THEIR INVOICE DATE FALLS BEFORE THE PURGE DATE
;
;		AT INSTALLATION TIME, THE USER MAY CHOOSE ANY OF THE BELOW
;			(1) MAY SAVE THE PURGED DATA IN A USER DEFINED FILE
;			(2) MAY GET A PRINTOUT OF WHAT IS BEING PURGED
;			(3) MAY DO NEITHER
;
RECORD
	,A64,'THIS MATERIAL CONTAINS THE VALUABLE PROPERTIES AND TRADE SECRETS'
	,A62,'OF MCBA, EMBODYING CONFIDENTIAL INFORMATION AND IDEAS, NO PART'
	,A56,'OF WHICH MAY BE USED AND/OR DISCLOSED WITHOUT MCBAs DULY'
	,A55,'AUTHORIZED LICENSE AGREEMENT AND/OR WRITTEN PERMISSION.'
	,A61,'COPYRIGHT (C) MCBA, AN UNPUBLISHED WORK. ALL RIGHTS RESERVED.'

RECORD SLSHST		
		.INCLUDE 'DEF:RD055A.DEF'
RECORD HSTCTL		
		.INCLUDE 'DEF:RD055B.DEF'
RECORD DUMINV		
		.INCLUDE 'DEF:RD041B.DEF'
RECORD
		.INCLUDE 'DEF:RD055D.DEF'
RECORD
		.INCLUDE 'DEF:RD055S.DEF'
RECORD TITLE
		,A34	,'PURGED DETAIL SALES HISTORY REPORT'
RECORD HDR1
		,A4
		,A7	,'INV/CRM'
		,A3
		,A7	,'INV/CRM'
		,A4
		,A5	,'ORDER'
		,A5
		,A4	,'CUST'
		,A3
		,A4	,'CUST'
		,A2
		,A2	,'SL'
		,A26
		,A3	,'PRD'
		,A8
		,A3	,'TAX'
		,A5
		,A3	,'QTY'
		,A8
		,A5	,'SALES'
		,A8
		,A4	,'COST'
		,A9
RECORD HDR2
		,A5
		,A4	,'DATE'
		,A7
		,A2	,'NO'
		,A7
		,A4	,'DATE'
		,A7
		,A2	,'NO'
		,A5
		,A3	,'TYP'
		,A2
		,A2	,'MN'
		,A3
		,A3	,'TER'
		,A4
		,A11	,'ITEM NUMBER'
		,A5
		,A3	,'CAT'
		,A2
		,A3	,'LOC'
		,A3
		,A3	,'FLG'
		,A5
		,A4	,'SOLD'
		,A6
		,A7	,'DOLLARS'
		,A6
		,A6	,'AMOUNT'
		,A8
RECORD BRACKS
		,A50	,']]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]'
		,A27	,']]]]]]]]]]]]]]]]]]]]]]]]]]]'
RECORD
	MASK1	,A8	,'ZX/XX/XX'
	MASK2	,A6	,'ZZZZZX'
	MASK3	,A7	,'ZZ,ZZX-'
	MASK4	,A11	,'ZZZ,ZZZ.XX-'
	PLINE 	,A132
	V	,D1
	SWITCH	,D1
	PRTCTR	,D1
	LINCNT	,D2	,60
	PGCNT	,D6
	PRGREC	,D5
	PRGSW	,D1
	PRGDTA	,A6		;PURGE THRU DATE FROM HSTSEL - YYMMDD
	PRNTSW	,D1		;** MODIFY TO CONTROL REPORT PRINTING
				;	OF DATA BEING PURGED
				; 	'1' MEANS PRINT THE REPORT
	SAVREC	,D1		;** MODIFY TO MATCH CUSTOMERS NEED
				;	TO SAVE PURGED HISTORY.
				;	'1' MEANS SAVE HISTORY IN THE FILE
	WRKDAT	,A6
	ENTRY	,A7
	INXCTL	,D1
	CNGCTL	,D1
	WHATNO	,D1
	RECIN	,D5
	RECOUT	,D5
	SSCNT	,D2	,00
	N	,D2	,01
	DELREC	,D5
	TQTY	,D6
	TSALE	,D9
	TCOST	,D9
	COL2	,D2
	READ	,D1	,0
	WRITE	,D1	,1
	LOKCTL	,D1
	SPLFIL	,A14
	LPARG	,D1
	RPTNUM	,D3
	PRTTYP	,A1
	BLKSIZ	,D5
	LPSW	,D2
	BLANKS	,A10
	JUST 	,D1
PROC
	XCALL TERID (V)
	SWITCH = 5
	XCALL FILES (10,'I',41,SWITCH)
	LOKCTL = 1
	XCALL IO (10,DUMINV,1,READ,LOKCTL)
	JUST = JSTIFY
	XCALL FILES (10,'I',41,4)
	SWITCH = 5
	XCALL FILES (8,'U',55,SWITCH)		;FILE # 55 -- SLSHST FILE
	SWITCH = 1
	XCALL SNMSG (PRGDTA,SWITCH)
	IF (SWITCH.EQ.9) GOTO NOMSG
	SWITCH = 3
	XCALL SNMSG (BLANKS,SWITCH)
	IF (PRGDTA.EQ.'000000'.OR.PRGDTA.EQ.'      ') GO TO NOMSG
SAVREC,
	XCALL OUTPT (1,1,2,'PURGE DETAIL SALES HISTORY',1)
	XCALL OUTPT (10,15,0,'DO YOU WANT TO SAVE ALL PURGED RECORDS ?',1)
	XCALL INPUT (10,60,01,00,'YY',ENTRY,INXCTL,1)
	IF (INXCTL.EQ.1) SAVREC = 1
	IF (INXCTL.EQ.2) SAVREC = 0
PRTRPT,
	XCALL OUTPT (12,15,0,'DO YOU WANT A REPORT OF ALL RECORDS PURGED ?',1)
	XCALL INPUT (12,60,01,00,'YY',ENTRY,INXCTL,1)
	IF (INXCTL.EQ.1) PRNTSW = 1
	IF (INXCTL.EQ.2) PRNTSW = 0
ANYCNG, 
	XCALL OUTPT (24,1,0,'ANY CHANGE ?',1)
	XCALL INPUT (24,15,01,00,'YN',ENTRY,INXCTL,1)
	GO TO (SAVREC), INXCTL
PROCES,
	SPLFIL (5,6) = 'EO'
	LPSW = 4	; MAY BE AUTO-SPOOLED
	IF (PRNTSW.EQ.0) GO TO NOREPT
	XCALL LPON (LPSW,SPLFIL)
	IF (LPSW.EQ.0) PRNTSW = 0
	LPARG = 2
	IF (LPSW.EQ.2.OR.LPSW.EQ.0) LPARG = 4
	XCALL WATE (LPARG,V)
NOREPT,
	IF (SAVREC.EQ.1) CALL OPNOUT
	XCALL WATE (4,V)
	LOKCTL = 1
	XCALL IO (8,HSTCTL,1,READ,LOKCTL)
	RECIN = 1
	RECOUT = 1
REDHST,
	INCR RECIN
	IF (RECIN.GE.MAX055) GOTO EOF
	LOKCTL = 1
	XCALL IO (8,SLSHST,RECIN,READ,LOKCTL)
	IF (SLSHST(1,5).EQ.']]]]]') GOTO EOF
	WRKDAT(1,2) = HINVDT(5,6),'XX'
	WRKDAT(3,6) = HINVDT(1,4),'XXXX'
	PRGSW = 0
	IF (WRKDAT.LE.PRGDTA.AND.POSTED.EQ.2) PRGSW = 1
	IF (PRGSW.EQ.1) CALL PURGE
	IF (PRGSW.EQ.0) CALL SAVE
	GOTO REDHST
EOF,
	IF (PRNTSW.EQ.1) CALL PRTTOT
	IF (SSCNT.NE.0) CALL WRTSSR	;WRITE BACK LAST BLOCK OF PRESERVED RECORDS
	REC055 = RECOUT
	ORG055 = RECOUT
	LOKCTL = 1
	XCALL IO (8,HSTCTL,1,WRITE,LOKCTL)
WRTBRK,
	INCR RECOUT
	IF (RECOUT.EQ.RECIN) GOTO CLOSE
	LOKCTL = 1
	XCALL IO (8,BRACKS,RECOUT,WRITE,LOKCTL)
	GOTO WRTBRK
CLOSE,
	XCALL FILES (8,'U',55,4)
	IF (SAVREC.EQ.1) CALL CLSOUT
	IF (SAVREC.EQ.1) XCALL PGCHN ('CP:PURMSG',1)
	XCALL PGCHN ('CP:SSMENU',1)
CLOSE1,
	XCALL FILES (8,'U',55,4)
	XCALL PGCHN ('CP:SSMENU',1)
;*************************************************************************
SAVE,		;RECORDS ARE TO BE RETAINED ON THE DETAIL SALES HIST FILE
	INCR SSCNT
	RECARR(SSCNT) = SLSHST
	IF (SSCNT.EQ.40) CALL WRTSSR
	RETURN
;*************************
WRTSSR,
	INCR RECOUT
	LOKCTL = 1
	XCALL IO (8,RECARR(N),RECOUT,WRITE,LOKCTL)
	IF (N.EQ.SSCNT) GOTO OUT
	INCR N
	GOTO WRTSSR
OUT,
	SSCNT = 0
	N = 1
	RETURN
;**************************************************************************
;		RECORDS ARE TO BE PURGED FROM THE DETAIL SALES HISTORY FILE
PURGE,
	IF (PRNTSW.EQ.1) CALL PRTPRG
	IF (SAVREC.EQ.1) CALL WRTPRG
	RETURN
;*******************************
WRTPRG,
	LOKCTL = 1
	XCALL IOS (1,SLSHST,WRITE,LOKCTL)
	INCR PRGREC
	RETURN
;*******************************
PRTPRG,
	PLINE(4,11) = HINVDT,MASK1
	PLINE(15,20) = HINVNO,MASK2
	PLINE(24,31) = HORDDT,MASK1
	PLINE(35,40) = HCUSNO,MASK2
	PLINE(44,45) = HCUSCD
	PLINE(49,50) = HSLSMN
	PLINE(54,55) = HTERR
	PLINE(59,73) = HITMNO
	IF (JUST) XCALL LEFTJ (PLINE(59,73),15)
	PLINE(77,78) = HPRDCD
	PLINE(82,83) = HLOC
	PLINE (89,89) = 'N'
	IF (HTXFLG.EQ.'1') PLINE (89,89) = 'Y'
	PLINE(95,101) = HQTY,MASK3
	PLINE(104,114) = HSALE,MASK4
	PLINE(117,127) = HCOST,MASK4
	CALL PRINT
	TQTY = TQTY + HQTY
	TSALE = TSALE + HSALE
	TCOST = TCOST + HCOST
	INCR DELREC
	RETURN
;*******************************
PRTTOT,
	XCALL LINFD (3)
	PLINE(5,10) = DELREC,'ZZ,ZZX'
	PLINE(12,25) = 'RECORDS PURGED'
	PLINE(94,101) = TQTY,'ZZZ,ZZX-'
	PLINE(102,114) = TSALE,'Z,ZZZ,ZZZ.XX-'
	PLINE(115,127) = TCOST,'Z,ZZZ,ZZZ.XX-'
	CALL PRINT
	XCALL LPOFF (LPSW,SPLFIL,PGCNT)
	RETURN
;**************************************************************************
PRINT,
	IF (PRNTSW.EQ.0) RETURN
	XCALL LPOUT (LINCNT,PGCNT,PLINE,TITLE,HDR1,HDR2,'NO HDR',
&		'NO LEGEND',' ',' ',0,0,132,0,LPSW,RPTNUM,PRTTYP)
	RETURN
;*******************************************************************************
NOMSG,		;** SINCE NO MSG WAS RECEIVED, NO PURGE IS REQUIRED.
		;   SO, UNPROTECT FILES, AND RETURN TO CALLING MENU
	XCALL FILES (8,'U',55,4)	;UNPROTECT THE SLSHST FILE
	XCALL PGCHN ('CP:SSMENU',1)
;******************************************************************************
OPNOUT,		;USER WANTS TO SAVE PURGED DATA IN A FILE
	XCALL MOUNT('PURGE SAVE FILE DISK','THE APPROPRIATE DRIVE')
	SWITCH = 3
	XCALL FILES(1,'O',88,SWITCH)
	IF (SWITCH.EQ.9) GOTO INUSE
	LOKCTL = 1
	XCALL IO (8,HSTCTL,1,READ,LOKCTL)
	BLKSIZ = ((SIZ055+2)*(REC055+1)/512) + 1
	XCALL OFILE (1,88,BLKSIZ,SIZ055,SWITCH)	;CREATE SSVDSH FILE USING
						;SLSHST FILE DEFINITIONS
	IF (SWITCH.EQ.1) GO TO NOROOM
	IF (SWITCH.EQ.9) GO TO INUSE1
	HSTCTL =
	LOKCTL = 1
	XCALL IOS (1,HSTCTL,WRITE,LOKCTL)
	PRGREC = 1
	RETURN
NOROOM,
	XCALL MESAG ('CANNOT RUN SELECTION-NEED MORE ROOM ON
&	DEVICE FOR SSVDSH FILE',2)
INUSE1,
	SWITCH = 4
	XCALL FILES (1,'O',88,SWITCH)
INUSE,
	XCALL MESAG('THE PURGE SAVE FILE IS IN USE ... TRY LATER',2)
	XCALL FILES (8,'U',55,4)
	XCALL PGCHN ('CP:SSMENU',1)
;*****************************************************************************
CLSOUT,
	LOKCTL = 1
	XCALL IOS (1,BRACKS,WRITE,LOKCTL)
	XCALL FILES(1,'O',88,4)
	SWITCH = 1
	XCALL FILES(1,'U',88,SWITCH)
	HSTCTL =
	ORG055 = PRGREC
	REC055 = PRGREC
	MAX055 = PRGREC + 1
	LOKCTL = 1
	XCALL IO (1,HSTCTL,1,WRITE,LOKCTL)
	XCALL FILES(1,'U',88,4)
	RETURN
END
