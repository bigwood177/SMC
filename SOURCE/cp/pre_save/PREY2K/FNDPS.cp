SUBROUTINE FNDPS
;
; FNDPS / COP 
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
;		PROGRAM TO FIND THE STOCKED COMPONENTS OF A NONSTOCKED
;		LINE ITEM ORDERED
;
	INVMAS	,A
	ANYMOR	,D
	LITMNO	,A
	RECNO	,D
	LQTYOR	,D
	LOCTNS	,D
	SAVITM	,A
	PIKQTY	,D
	BSEND	,D
	COMPIK	,A
	LOCATN	,A

RECORD PRDSTR		
		.INCLUDE 'DEF:RD091A.DEF'
RECORD TNVMAS		
		.INCLUDE 'DEF:RD041A.DEF'
RECORD SAVE
	ITEMNM	,12A15
	ITEMN	,12D5
	QTYS	,12D7
	LEVEL	,D3
	BADBIL	,D1
RECORD
	KEY	,A15
	BSMID	,D5
	SRCCTL	,D1
	ERRSWT	,D1
	DECMAL	,D14
	FSTREC	,D5
	FNDSWT	,D1
	QTYCTR	,D2
	STKPTR	,D2
	LOCCTR	,D2
	BLANKS	,A328
	READ	,D1	,0
	WRITE	,D1	,1
	LOKCTL	,D1
PROC
	FSTREC = RECNO
	SAVE = SAVITM
	TNVMAS = INVMAS
	IF (SAVE.NE.BLANKS) GOTO TEST1
NXTREC,
	INCR RECNO
	LOKCTL = 1
	XCALL IO (12,PRDSTR,RECNO,READ,LOKCTL)
	IF (PRDSTR.EQ.']]]]]]]]') GOTO LSTREC		;RETURN TO PIKTIK, NO
							;MORE RECORDS TO PROCESS
	IF (PITMNO.LT.LITMNO) GOTO NXTREC
	IF (PITMNO.GT.LITMNO) GOTO LSTREC		;RETURN TO PIKTIK
	IF (CITMNO.EQ.']]]DEL') GOTO NXTREC
	IF (OBSFAG.NE.'A') GOTO NXTREC
	LEVEL =
DWNLVL,
	INCR LEVEL
	IF (LEVEL.GT.12) GOTO LVLERR
	ITEMNM(LEVEL) = PITMNO
	ITEMN(LEVEL) = RECNO
	QTYS(LEVEL) = QTYPER
SAMLVL,
	LOKCTL = 1
	XCALL IO (7,TNVMAS,CRECNO,READ,LOKCTL)
	IF (STOKED.NE.'S') GOTO TEST1		;KEEP GOING TILL WE
						;REACH A STOCKED LEVEL
	QTYCTR =
	DECMAL = LQTYOR * 10000
CHAINQ,
	INCR QTYCTR
	IF (QTYCTR.GT.LEVEL) GOTO TOTQTY
	DECMAL = (DECMAL * QTYS(QTYCTR)) # 4
	GOTO CHAINQ
TOTQTY,
	LOCCTR =
FNDSTK,
	INCR LOCCTR
	IF (LOCCTR.GT.LOCTNS.OR.LOC(LOCCTR).EQ.'  ') GOTO NOLOC
	IF (LOC(LOCCTR).NE.MFGLOC) GOTO FNDSTK
	INVMAS = TNVMAS
	PIKQTY = DECMAL
	SAVITM = SAVE
	LOCCTR =
FNDLOC,
	INCR LOCCTR
	IF (LOCCTR.GT.LOCTNS .OR. LOC(LOCCTR).EQ.'  ') GO TO NOSEQ
	IF (LOC(LOCCTR).NE.LOCATN) GO TO FNDLOC
	COMPIK = PIKSEQ (LOCCTR)	;Bin location for the component
	RETURN
NOSEQ,
	COMPIK =
	RETURN					;RETURN TO PIKTIK TO PRINT
TEST1,
	IF (BADBIL.EQ.1) GOTO NXTREC
	IF (BADBIL.EQ.2) GOTO ENDOFF
FNDCMP,
	FNDSWT =
	IF (STOKED.EQ.'S') GOTO TEST2	;DON'T PROCEED ANY FURTHER DOWN BILL,
					;HAVE REACHED A STOCKING LEVEL
	KEY = CITMNO
	SRCCTL = 2
	XCALL SERCH (12,PRDSTR,KEY,1,15,BSEND,BSMID,SRCCTL,4,18,23,0,0,0,0)
	IF (SRCCTL) GOTO TEST2
BAKUP1,
	BSMID = BSMID - 1
	LOKCTL = 1
	XCALL IO (12,PRDSTR,BSMID,READ,LOKCTL)
	IF (PITMNO.EQ.KEY) GOTO BAKUP1
	INCR BSMID
	RECNO = BSMID - 1
REDPRD,
	INCR RECNO
	LOKCTL = 1
	XCALL IO (12,PRDSTR,RECNO,READ,LOKCTL)
	IF (PITMNO.NE.KEY) GOTO TEST2
	IF (CITMNO.EQ.']]]DEL') GOTO REDPRD
	IF (OBSFAG.NE.'A') GOTO REDPRD
	STKPTR = LEVEL
STKCHK,
	IF (ITEMNM(STKPTR).EQ.CITMNO) GOTO BILERR
	STKPTR = STKPTR - 1
	IF (STKPTR.GE.1) GOTO STKCHK
	FNDSWT = 1
TEST2,
	IF (ERRSWT) GOTO BILLER
	IF (FNDSWT) GOTO DWNLVL
UPLVL,
	STOKED =
	IF (LEVEL.EQ.1) RECNO = ITEMN(LEVEL)
	IF (LEVEL.EQ.1) GOTO NXTREC
	INCR ITEMN(LEVEL)
	LOKCTL = 1
	XCALL IO (12,PRDSTR,ITEMN(LEVEL),READ,LOKCTL)
	IF (PRDSTR.EQ.']]]]]]]]') GOTO CLRLVL
	IF (CITMNO.EQ.']]]DEL') GOTO UPLVL
	IF (OBSFAG.NE.'A') GOTO UPLVL
	IF (PITMNO.NE.ITEMNM(LEVEL)) GOTO CLRLVL
	QTYS(LEVEL) = QTYPER
	STKPTR = LEVEL
STCKCK,
	IF (ITEMNM(STKPTR).EQ.CITMNO) GOTO BILLER
	STKPTR = STKPTR - 1
	IF (STKPTR.GE.1) GOTO STCKCK
	GOTO SAMLVL
CLRLVL,
	IF (LEVEL.EQ.1) RECNO = RECNO - 1
	ITEMNM(LEVEL) =
	ITEMN(LEVEL) =
	LEVEL = LEVEL - 1
	IF (LEVEL.LE.0) GOTO NXTREC
	GOTO UPLVL
NOLOC,
	IF (BADBIL.EQ.1) GOTO ENDOFF
	XCALL MESAG ('MFG LOC DOES NOT EXIST FOR THIS ITEM',1)
	BADBIL = 1
	RECNO = FSTREC
	GOTO NXTREC
LVLERR,
	XCALL MESAG ('*** BILL HAS GREATER THAN 12 LEVELS ***',1)
BADMSG,
	IF (BADBIL.EQ.1) RETURN		;GO BACK TO PIKTIK AND DON'T ALLOW
					;THIS LINE TO BE ORDERED
	XCALL MESAG ('ERROR ENCOUNTERED - PLEASE WAIT.',4)
	BADBIL = 1
	RECNO = FSTREC
	GOTO NXTREC
BILLER,
	XCALL MESAG ('*** BAD STRUCTURE - COMPONENT OF SELF ***',1)
	GOTO BADMSG
BILERR,
	ERRSWT = 1
	GOTO TEST2
ENDOFF,
	BADBIL = 1
	RETURN			; RETURN TO CALLING PROGRAM DUE TO ERROR
LSTREC,
	ANYMOR = 1
	RETURN
	END