SUBROUTINE UNCOM
;
;  UNCOM / COP 
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
	LITMNO	,A
	RECNO	,D
	LQTYOR	,D
	LOCTNS	,D
	BSEND	,D
	BADBIL	,D
RECORD PRDSTR		
		.INCLUDE 'DEF:RD091A.DEF'
RECORD ITMMAS		
		.INCLUDE 'DEF:RD041A.DEF'
RECORD
	KEY	,A15
	BSMID	,D5
	SRCCTL	,D1
	ITEMNM	,12A15
	ITEMN	,12D5
	QTYS	,12D7
	LEVEL	,D3
	STKPTR	,D2
	FNDSWT	,D1
	ERRSWT	,D1
	DECMAL	,D14
	QTYCTR	,D2
	LOCCTR	,D2
	FSTREC	,D5
	READ	,D1	,0
	WRITE	,D1	,1
	LOKCTL	,D1
PROC
	FSTREC = RECNO
	BADBIL =
NXTREC,
	INCR RECNO
	LOKCTL = 1
	XCALL IO (12,PRDSTR,RECNO,READ,LOKCTL)
	IF (PRDSTR.EQ.']]]]]]]]') RETURN	;RETURN TO CANCEL,
						;NO MORE RECORDS TO PROCESS
	IF (PITMNO.LT.LITMNO) GOTO NXTREC
	IF (PITMNO.GT.LITMNO) RETURN		;RETURN TO CANCEL
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
	CALL NEWCMP
	UNLOCK 1
	IF (BADBIL.EQ.1) GOTO NXTREC
	IF (BADBIL.EQ.2) GOTO ENDOFF
	CALL FNDCMP
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
FNDCMP,
	FNDSWT =
	IF (STOKED.EQ.'S') RETURN	;DON'T PROCEED ANY FURTHER DOWN BILL,
					;HAVE REACHED A STOCKING LEVEL
	KEY = CITMNO
	SRCCTL = 2
	XCALL SERCH (12,PRDSTR,KEY,1,15,BSEND,BSMID,SRCCTL,4,18,23,0,0,0,0)
	IF (SRCCTL) RETURN
BAKUP1,
	BSMID = BSMID - 1
	LOKCTL = 1
	XCALL IO (12,PRDSTR,BSMID,READ,LOKCTL)
	IF (PITMNO.EQ.KEY) GOTO BAKUP1
	INCR BSMID
	RECNO = BSMID
REDPRD,
	LOKCTL = 1
	XCALL IO (12,PRDSTR,RECNO,READ,LOKCTL)
	IF (PITMNO.NE.KEY) RETURN
	IF (CITMNO.EQ.']]]DEL') GOTO NXTRC1
	IF (OBSFAG.NE.'A') GOTO NXTRC1
	STKPTR = LEVEL
STKCHK,
	IF (ITEMNM(STKPTR).EQ.CITMNO) GOTO BILERR
	STKPTR = STKPTR - 1
	IF (STKPTR.GE.1) GOTO STKCHK
	FNDSWT = 1
	RETURN
NXTRC1,
	INCR RECNO
	GOTO REDPRD
ENDOFF,
	BADBIL = 1
	RETURN				;RETURN TO CALLING PROGRAM
BILERR,
	ERRSWT = 1
	RETURN
LVLERR,
	XCALL MESAG ('02 - BILL HAS GREATER THAN 12 LEVELS',2)
BADMSG,
	IF (BADBIL.EQ.1) RETURN		;GO BACK TO CANCEL AND DON'T ALLOW
					;THIS LINE TO BE ORDERED
	XCALL MESAG ('ERROR ENCOUNTERED - RECOMMITTING INVENTORY
&		 PLEASE WAIT...',4)
	BADBIL = 1
	RECNO = FSTREC
	GOTO NXTREC
BILLER,
	XCALL MESAG ('BAD STRUCTURE - COMPONENT OF SELF',1)
	GOTO BADMSG
NEWCMP,
	LOKCTL = 1
	XCALL IO (1,ITMMAS,CRECNO,READ,LOKCTL)
	IF (STOKED.NE.'S') RETURN		;KEEP GOING TILL WE REACH
						;A STOCKED LEVEL
	IF (CNTRLD.NE.'C') RETURN		;LEAVE QTY COMMITTED UNADJUSTED
						;FOR NON-CONTROLLED ITEM
	QTYCTR =
	DECMAL = LQTYOR * 10000
CHAINQ,
	INCR QTYCTR
	IF (QTYCTR.GT.LEVEL) GOTO TOTQTY
	DECMAL = (DECMAL * QTYS(QTYCTR)) # 4
	GOTO CHAINQ
TOTQTY,
	IF (DECMAL.GT.0.AND.DECMAL.LT.+5000) DECMAL = DECMAL + 10000
	IF (DECMAL.LT.0.AND.DECMAL.GT.-5000) DECMAL = DECMAL - 10000
	DECMAL = ((DECMAL)#4) * 10000
		;ROUND QTYPER, BUT ASSURE THAT ANYTHING BETWEEN 1 AND -1
		;END UP AS BEING 1 OR -1 INSTEAD OF ZERO.
	LOCCTR =
FNDSTK,
	INCR LOCCTR
	IF (LOCCTR.GT.LOCTNS.OR.LOC(LOCCTR).EQ.'  ') GOTO NOLOC
	IF (LOC(LOCCTR).NE.MFGLOC) GOTO FNDSTK
	IF (BADBIL.NE.1) QTYCOM(LOCCTR) = QTYCOM(LOCCTR) - (DECMAL/10000)
	IF (BADBIL.EQ.1) QTYCOM(LOCCTR) = QTYCOM(LOCCTR) + (DECMAL/10000)
	IF (QTYCOM(LOCCTR).LT.0) QTYCOM(LOCCTR) =
	LOKCTL = 1
	XCALL IO (1,ITMMAS,CRECNO,WRITE,LOKCTL)
	RETURN
NOLOC,
	IF (BADBIL.EQ.1) GOTO NOLOC2
	XCALL MESAG ('01 - MANUFACTURING LOCATION DOES NOT EXIST',2)
	BADBIL = 1
	RECNO = FSTREC
	RETURN				;RETURN TO NEWCMP CALL
NOLOC2,
	BADBIL = 2
	RETURN				;RETURN TO NEWCMP CALL
END