;  CSLHJL / COP 
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
;		CREATES A RECORD FOR EACH LINE ITEM BEING CREDITED, WHICH (AFTER
;		SORTING) GOES INTO THE DETAIL SALES HISTORY FILE SO AS TO UPDATE
;		THE SALES HISTORY SYSTEM WITH A RECORD OF THIS CREDIT.OPTIONALLY,
;		(SEE VALUE OF PRNTSW), PRINTS AN AUDIT REPORT OF THE RECORDS
;
RECORD
	,A64,'THIS MATERIAL CONTAINS THE VALUABLE PROPERTIES AND TRADE SECRETS'
	,A62,'OF MCBA, EMBODYING CONFIDENTIAL INFORMATION AND IDEAS, NO PART'
	,A56,'OF WHICH MAY BE USED AND/OR DISCLOSED WITHOUT MCBAs DULY'
	,A55,'AUTHORIZED LICENSE AGREEMENT AND/OR WRITTEN PERMISSION.'
	,A61,'COPYRIGHT (C) MCBA, AN UNPUBLISHED WORK. ALL RIGHTS RESERVED.'

RECORD CRMHDR		
		.INCLUDE 'DEF:RD046A.DEF'
RECORD HDRCTL	,X	
		.INCLUDE 'DEF:RD046B.DEF'
RECORD CRMLIN		
		.INCLUDE 'DEF:RD047A.DEF'
RECORD LINCTL	,X	
		.INCLUDE 'DEF:RD047B.DEF'
RECORD SLSHST		
		.INCLUDE 'DEF:RD055A.DEF'
RECORD HSTCTL		
		.INCLUDE 'DEF:RD055B.DEF'
RECORD CUSMAS   	
		.INCLUDE 'DEF:RD001A.DEF'
RECORD DUMCUS		
		.INCLUDE 'DEF:RD001B.DEF'
RECORD CUSIDX		
		.INCLUDE 'DEF:RD002A.DEF'
RECORD INVMAS		
		.INCLUDE 'DEF:RD041A.DEF'
RECORD DUMINV,X		
		.INCLUDE 'DEF:RD041B.DEF'
RECORD INVIDX  		
		.INCLUDE 'DEF:RD042A.DEF'
RECORD
		.INCLUDE 'DEF:RD055S.DEF'
RECORD TITLE
		,A36	,'SALES HISTORY JOURNAL - CREDIT MEMOS'
RECORD HDR1
		,A3
		,A8	,'CRD MEMO'
		,A2
		,A8	,'CRD MEMO'
		,A3
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
		,A7
		,A7	,'DOLLARS'
		,A7
		,A4	,'COST'
		,A20
RECORD HDR2
		,A5
		,A4	,'DATE'
		,A7
		,A2	,'NO'
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
		,A4
		,A6	,'CREDIT'
		,A5
		,A6	,'CREDIT'
		,A7
		,A6	,'CREDIT'
		,A19
RECORD SNDMSG
		,A3	,'CP:'
	PRGNAM	,A6	,'PSTSLH'
	RCNT	,D5
	OCNT	,D5
		,D3	,057
		,D3
RECORD NXTMSG
		,A3	,'CP:'
	MSGPRG	,A6	,'CLRCRH'
RECORD DASHES
		,A50,'--------------------------------------------------'
		,A50,'--------------------------------------------------'
		,A32,'--------------------------------'
RECORD
	MASK1	,A8	,'ZX/XX/XX'
	MASK2	,A6	,'ZZZZZX'
	MASK3	,A7	,'ZZ,ZZX-'
	MASK4	,A11	,'ZZZ,ZZZ.XX-'
	PLINE 	,A132
	V	,D1
	SWITCH	,D1	,1
	CLRCP7	,A13	,'057,CP:CSLHJL'
	KEY	,A6
	BSEND	,D5
	BSEND1	,D5
	SPLFIL	,A14
	RPTNUM	,D3
	PRTTYP	,A1
	LPARG	,D1
	BSEND2	,D5
	BSMID	,D5
	SRCCTL	,D1
	PRTCTR	,D1
	LRECNO	,D5	,00001
	ORECNO	,D5	,00001
	FSTSWT	,D1	,1
	LSTSWT	,D1
	INVQTY	,D6
	INVPRC	,D9
	INVCST	,D9
	DATQTY	,D6
	DATPRC	,D9
	DATCST	,D9
	SAVDAT	,D6
	LINCNT	,D2	,60
	LINNUM	,D3
	PGCNT	,D6
	LNFEED	,D2
	SAVLCT	,D5
	SAVOCT	,D5
	INVALO	,D1
	DECMAL	,D10
	PRNTSW	,D1	,1	;MODIFY TO CONTROL REPORT PRINTING
				;'1' MEANS PRINT THE REPORT
				;MODIFY TO MEET CUSTOMER'S NEED TO PRINT
				;CREDIT MEMOS
	RECCNT	,D5
	SIZE	,D5
	READ	,D1	,0
	WRITE	,D1	,1
	LOKCTL	,D1
	LPSW	,D2
	JUST	,D1
PROC
	XCALL TERID (V)
	ORG055 = 1
	RECCNT = 1
	XCALL OUTPT (1,1,2,TITLE,V)
	XCALL WATE (4,V)
	SWITCH = 5
	XCALL FILES (10,'I',41,SWITCH)
	LOKCTL = 1
	XCALL IO (10,DUMINV,1,READ,LOKCTL)
	JUST = JSTIFY
	XCALL FILES (10,'I',41,4)
	SWITCH = 3
	XCALL FILES (7,'O',57,SWITCH)		;FILE # 57 -- SLHWRK FILE
	IF (SWITCH.EQ.9) GOTO INUSE
	SWITCH = 5
	XCALL FILES(2,'I',02,SWITCH)
	XCALL FILES(3,'I',42,SWITCH)
	XCALL FILES (1,'I',01,SWITCH)		;FILE # 01 -- CUSMAS FILE
	XCALL FILES (6,'I',41,SWITCH)		;FILE # 41 -- INVMAS FILE
	XCALL FILES (4,'I',46,SWITCH)		;FILE # 46 -- CRMHDR FILE
	XCALL FILES (5,'I',47,SWITCH) 		;FILE # 47 -- CRMLIN FILE
	LOKCTL = 1
	XCALL IO (1,DUMCUS,1,READ,LOKCTL)
	BSEND = ORG001
	LOKCTL = 1
	XCALL IO (6,DUMINV,1,READ,LOKCTL)
	BSEND2 = ORG041
	LOKCTL = 1
	XCALL IO (4,HDRCTL,1,READ,LOKCTL)
	SAVOCT = REC046
	BSEND1 = ORG046
	LOKCTL = 1
	XCALL IO (5,LINCTL,1,READ,LOKCTL)
	SAVLCT = REC047
	SIZE = ((REC047+2)*(SIZ055+2)+2)/512 + 1
	XCALL OFILE (7,57,SIZE,SIZ055,SWITCH)	;TEMPORARY SLSHST DATA
						;FOR SLHWRK FILE
	IF (SWITCH.EQ.1) GO TO NOROOM
	LOKCTL = 1
	XCALL IOS (7,HSTCTL,WRITE,LOKCTL)
	IF (LOKCTL.EQ.3) GO TO NOROOM
LPON,
	LPSW = 4	; MAY BE AUTO-SPOOLED
	IF (PRNTSW.EQ.0) GO TO REDLIN
	SPLFIL (5,6) = 'EE'
	XCALL LPON (LPSW,SPLFIL)
	IF (LPSW.EQ.0) XCALL MESAG 
&	('Sales History Journal must be either SPOOLED or PRINTED.',2)
	IF (LPSW.EQ.0) GO TO LPON
	LPARG = 2
	IF (LPSW.EQ.2 .OR. LPSW.EQ.0) LPARG = 4
	XCALL WATE(LPARG,V)
REDLIN,
	INVALO =
	INCR LRECNO
	IF (LRECNO.GT.SAVLCT) GOTO EOFLIN
	LOKCTL = 1
	XCALL IO (5,CRMLIN,LRECNO,READ,LOKCTL)
	IF (CLITEM.EQ.'???'.AND.CLQTY.EQ.0) GOTO REDLIN
	IF (CLDESC.EQ.']]]CANCEL') GO TO REDLIN
	IF (CLQTY.EQ.0) GOTO REDLIN
	GOTO CHKORD
;*******************************************************************************
;		SEARCH INVIDX FILE TO GET ITEM DESCRIPTION
EOFLIN,
	LSTSWT = 1
CHKORD,
	IF (CLCRNO.NE.CCRMNO.OR.FSTSWT.OR.LSTSWT) CALL NEWORD
	FSTSWT =
	IF (LSTSWT) GOTO CLOSE
	IF (INVALO) GOTO REDLIN
	HPRDCD =
	HTXFLG = '0'
	XCALL SERCH (3,INVIDX,CLITEM,1,15,BSEND2,BSMID,SRCCTL,4,16,20,0,0,0,0)
	IF (SRCCTL) GOTO NOFIND
	LOKCTL = 1
	XCALL IO (6,INVMAS,IRC041,READ,LOKCTL)
	HPRDCD = PRDCAT
	IF (TXFLAG.EQ.'Y'.AND.TAXFLG.NE.'   ') HTXFLG = '1'
;*******************************************************************************
;		PRINT CREDIT MEMO TOTALS
NOFIND,
	INCR LINNUM
	HBOFLG =
	HLOC = CLLOC
	HITMNO = CLITEM
	HPRDC2 =
	IF (CLQTY.GT.0) CLQTY = CLQTY * (-1)
	HQTY = CLQTY
	DECMAL = CLQTY * CLPRCE
	DECMAL = DECMAL - ((DECMAL*CLDISC)/100)
	HSALE = DECMAL - ((DECMAL*CDSCNT)/100)
	HCOST = CLQTY * CLCOST
	INCR RECCNT
	LOKCTL = 1
	XCALL IOS (7,SLSHST,WRITE,LOKCTL)
	IF (LOKCTL.EQ.3) GO TO NOROOM
	IF (LINNUM.GT.1) GO TO SKIP1
	PLINE(4,11) = HINVDT,MASK1
	PLINE(15,20) = HINVNO,MASK2
	PLINE(24,29) = HCUSNO,MASK2
	PLINE(33,34) = HCUSCD
	PLINE(38,39) = HSLSMN
	PLINE(43,44) = HTERR
SKIP1,
	PLINE(48,62) = HITMNO
	IF (JUST) XCALL LEFTJ (PLINE(48,62),15)
	PLINE(66,67) = HPRDCD
	PLINE(71,72) = HLOC
	PLINE (78,78) = 'N'
	IF (HTXFLG.EQ.'1') PLINE (78,78) = 'Y'
	PLINE(84,90) = HQTY,MASK3
	PLINE(93,103) = HSALE,MASK4
	PLINE(106,116) = HCOST,MASK4
	CALL PRINT
	INVQTY = INVQTY + HQTY
	INVPRC = INVPRC + HSALE
	INVCST = INVCST + HCOST
	GOTO REDLIN
NEWORD,
	IF (FSTSWT) GOTO REDORD
	XCALL LINFD (1)
	PLINE(60,78) = 'CREDIT MEMO TOTALS:'
	PLINE(83,90) = INVQTY,'ZZZ,ZZX-'
	PLINE(91,103) = INVPRC,'Z,ZZZ,ZZZ.XX-'
	PLINE(104,116) = INVCST,'Z,ZZZ,ZZZ.XX-'
	CALL PRINT
	PLINE = DASHES
	CALL PRINT
	XCALL LINFD (1)
	LINCNT = LINCNT + 2
	DATQTY = DATQTY + INVQTY
	DATPRC = DATPRC + INVPRC
	DATCST = DATCST + INVCST
	INVQTY =
	INVPRC =
	INVCST =
	IF (LSTSWT) GOTO DATTOT
;*******************************************************************************
REDORD,
	LINNUM =
	INCR ORECNO
	IF (ORECNO.GT.SAVOCT) GOTO FNDORD
	LOKCTL = 1
	XCALL IO (4,CRMHDR,ORECNO,READ,LOKCTL)
	IF (CCRMDT.EQ.0.OR.CCUSNM.EQ.']]]CANCEL') GO TO REDORD
	IF (CCRMNO.LT.CLCRNO) GOTO REDORD
	IF (CCRMNO.GT.CLCRNO) GOTO FNDORD
CHKDAT,
	IF (FSTSWT) SAVDAT = CCRMDT
	IF (CCRMDT.EQ.SAVDAT) GOTO GETCUS
;*******************************************************************************
;		PRINT DATE TOTALS
DATTOT,
;	PLINE(67,78) = 'DATE TOTALS:'
;	PLINE(83,90) = DATQTY,'ZZZ,ZZX-'
;	PLINE(91,103) = DATPRC,'Z,ZZZ,ZZZ.XX-'
;	PLINE(104,116) = DATCST,'Z,ZZZ,ZZZ.XX-'
;	CALL PRINT
;	LINCNT = 60
	DATQTY =
	DATPRC =
	DATCST =
	IF (LSTSWT) RETURN
	SAVDAT = CCRMDT
GETCUS,
	HCUSNO = CCUSNO
	HINVDT = CCRMDT
	HINVNO = CCRMNO
	HORDDT =
	HSLSMN = CSLMAN
	KEY = CCUSNO,'XXXXXX'
	XCALL SERCH (2,CUSIDX,KEY,1,6,BSEND,BSMID,SRCCTL,4,7,11,0,0,0,0)
	IF (SRCCTL) GOTO NTFOND
	LOKCTL = 1
	XCALL IO (1,CUSMAS,IRC001,READ,LOKCTL)
	HCUSCD = CUSCD
	HCUSC2 = CUSCD2
	HTERR = TERR
NTFOND,
	IF (SRCCTL) HCUSCD =
	IF (SRCCTL) HCUSC2 =
	IF (SRCCTL) HTERR =
	RETURN
FNDORD,
	KEY = CLCRNO,'XXXXXX'
	XCALL SERCH (4,CRMHDR,KEY,1,6,BSEND1,BSMID,SRCCTL,4,7,11,0,0,0,0)
	IF (SRCCTL) GOTO NOTFND
	ORECNO = BSMID
	GOTO CHKDAT
;*******************************************************************************
;		CREDIT MEMO HEADER NOT FOUND
NOTFND,
	XCALL LINFD (0)
	PLINE(1,48) = '*** NO CREDIT MEMO HEADER RECORD FOUND FOR ORDER'
	PLINE(50,55) = CLCRNO,'XXXXXX'
	PLINE(57,97) = '- LINE ITEM NOT ADDED TO HISTORY FILE ***'
	CALL PRINT
	LINCNT = LINCNT + 2
	INVALO = 1
	RETURN
;*******************************************************************************
PRINT,
	IF (PRNTSW.EQ.0) RETURN
	XCALL LPOUT (LINCNT,PGCNT,PLINE,TITLE,HDR1,HDR2,'NO HDR',
&		'NO LEGEND',' ',' ',0,0,132,0,LPSW,RPTNUM,PRTTYP)
	RETURN
INUSE,
	SWITCH = 2
	XCALL SNMSG (CLRCP7,SWITCH)
	XCALL PGCHN ('UT:CLROF2',2)
CLOSE,
	CLOSE 7
	SWITCH = 5
	XCALL FILES (7,'U',57,SWITCH)
	HSTCTL =
	ORG055 = RECCNT
	REC055 = RECCNT
	MAX055 = RECCNT
	DEL055 = 0
	LOKCTL = 1
	XCALL IO (7,HSTCTL,1,WRITE,LOKCTL)
	IF (PRNTSW) XCALL LPOFF (LPSW,SPLFIL,PGCNT)
	IF (PRNTSW) XCALL WATE(4,V)
	XCALL FILES (3,'I',42,4)
	CLOSE 1
	CLOSE 4
	CLOSE 5
	CLOSE 6
	CLOSE 7
	RCNT = RECCNT
	OCNT = 1
	SWITCH = 2
	XCALL SNMSG (SNDMSG,SWITCH)
	SWITCH = 2
	XCALL SNMSG (NXTMSG,SWITCH)
	XCALL PGCHN ('CP:SRTSLH',0)
NOROOM,
	XCALL MESAG ('NO ROOM ON DEVICE FOR TEMPORARY SLHWRK FILE',2)
	STOP
END
