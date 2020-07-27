;POPX.MAN
;		AUTHOR: SHERWOOD S. QUIRING
;		POPUP WINDOW ROUTINE

;		this version has no Title, Header, or Borders


SUBROUTINE	POPX
	POPAR	,A		;POP UP WINDOW DATA
	PALET	,D		;OPTIONAL PALLET	
	.INCLUDE 'DEF:WINDOWS.DEF'

RECORD	POPARA
	.INCLUDE 'DEF:POP1.DEF'

RECORD	FUNKEY
	.INCLUDE 'DEF:FUNKEY.DEF'

RECORD	WRKLIN
	ARO	,A1
		,A1
	REST	,A80

RECORD	VARS
	STAT	,D1
	STAT_KEY	,D3
	DEC	,D6
	ALPHA	,A3
	WHDR	,A80
	F_KEY	,D3
	I	,D5
	VAL	,D1
	WROW	,D2
	WCOL	,D2
	FIRST_ROW	,D2
	LAST_ROW	,D2
	SAVE_ROW	,D2
	X	,D2
	Y	,D2
	HT	,D2
	LN	,D2
	MAXROW	,D2
	WLEN	,D2
	TITLEN	,D2
PROC
	POPARA = POPAR		;POP UP DATA

	CALL DSPWND		;DISPLAY WINDOW

	CLEAR VAL
	CLEAR SAVE_ROW

;;;	FIRST_ROW = 3
;;;	WROW = 3

	FIRST_ROW = 1
	WROW = 1

	I = 1
	CALL DSPLIN

DSPLOP,
	IF (SAVE_ROW .NE. 0)	CALL CLEAR_LAST_LINE

	WROW = WROW + VAL
	IF (WROW .GT. LAST_ROW) CALL SCROLL_DN
	IF (WROW .LT. FIRST_ROW) CALL SCROLL_UP

	I = I + VAL
	IF (I .LE. 0) I = 1
	IF (I .GT. NUMARA) I = NUMARA

	CALL DSPLIN
	CALL INPUT
	USING F_KEY SELECT
	(EXIT_KEY),	BEGIN
			CLEAR PI
			CLEAR P_ACTION
			END
	(UP_ARO),	BEGIN
			VAL = - 1
			GOTO DSPLOP
			END
	(DN_ARO),	BEGIN
			VAL =  1
			GOTO DSPLOP
			END
	(RGHT_ARO),	BEGIN
			P_ACTION = 1
			PI = I		;SAVE SELECTED ARRAY EL.
			PFLAGS(I) = 1
			END
	(LEFT_ARO),	BEGIN
			P_ACTION = 1
			PI = I		;SAVE SELECTED ARRAY EL.
			PFLAGS(I) = 0
			END
	(CR_KEY),	BEGIN
			P_ACTION = 4	;next page
			PI = I		;SAVE SELECTED ARRAY EL.
			END
	(PAGE_DN),	BEGIN
			P_ACTION = 6	;next page
			PI = I		;SAVE SELECTED ARRAY EL.
			END
	(INS_KEY),	BEGIN
			P_ACTION = 2	;ADD NEW
			PI = I
			END
	(DEL_KEY),	BEGIN
			P_ACTION = 3	;DELETE
			PI = I
			END
	ENDUSING
	
	POPAR = POPARA		;POP UP DATA

	XCALL W_PROC(WP_REMOVE,POP_WND)
	XCALL W_PROC(WP_DELETE,POP_WND)
	XCALL W_UPDT
	RETURN

DSPLIN,	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;;; move arrow, highlight selected line
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	ARO = '>'
	REST = PARRY(I)
	XCALL W_DISP (POP_WND,WD_ATTR,ATTR_SET+ATTR_RVRS)
	XCALL W_DISP (POP_WND,WD_POS,WROW,1,WRKLIN(1,WLEN))
	XCALL W_DISP (POP_WND,WD_POS,WROW,1)
	IF (%PASSED(PALET)) XCALL W_AREA (POP_WND, WA_COLOR, PALET)	;ssq 12/11
	SAVE_ROW = WROW
	RETURN
;----------------------------------------------------------------------

CLEAR_LAST_LINE,	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
			;;; CLEAR HI-LITE ON PREV LINE
			;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	CLEAR ARO
	IF (I.GT.0)
		BEGIN
		IF (PFLAGS(I).EQ.1)
		THEN	WRKLIN(WLEN,WLEN) = '*'
		ELSE	CLEAR WRKLIN(WLEN,WLEN)
		PARRY(I) = REST(1,WLEN)
		END
	XCALL W_DISP (POP_WND,WD_ATTR,ATTR_CLR+ATTR_RVRS)
	XCALL W_DISP (POP_WND,WD_POS,SAVE_ROW,1,WRKLIN(1,WLEN))
	RETURN
;----------------------------------------------------------------------
INPUT,	;;;;;;;;;;;;;;;;;;;;;;;
	;;; FUNCTION KEY INPUT
	;;;;;;;;;;;;;;;;;;;;;;;

	XCALL W_DISP(POP_WND,WD_ACCEPT,STAT_KEY)
	XCALL TTSTS(STAT)
	IF (STAT) 
	THEN	XCALL W_DISP(POP_WND,WD_ACCEPT,F_KEY)
	ELSE	F_KEY = STAT_KEY

	CASE F_KEY OF
	BEGINCASE
	079:	F_KEY = 027
	133:	F_KEY = 027
	008:	F_KEY = 027		;<BS>
	010:	F_KEY = 013		;<CR>
	ENDCASE

	RETURN

GETCHR,	
	XCALL W_DISP(POP_WND,WD_ACCEPT,ALPHA)
	XCALL DECML (ALPHA, DEC)
	RETURN

;----------------------------------------------------------------------
;----------------------------------------------------------------------

;;; WINDOW SCROLLING ROUTINES
SCROLL_DN,
	WROW = LAST_ROW
	IF (I .EQ. NUMARA) RETURN
	XCALL W_AREA(POP_WND,WA_SCROLL,WAS_UP,1)
	XCALL W_DISP(POP_WND,WD_POS,1,1,WD_CLR,WDC_EOL )
;;;	XCALL W_DISP(POP_WND,WD_POS,1,1,WHDR(1,PLEN) )
;;;	XCALL W_DISP(POP_WND,WD_HLINE,2,1,PLEN+2)
	RETURN

SCROLL_UP,
	WROW = FIRST_ROW
	IF (I .EQ. 1) RETURN
	XCALL W_AREA(POP_WND,WA_SCROLL,WAS_DOWN,1)
	XCALL W_DISP(POP_WND,WD_POS,1,1,WD_CLR,WDC_EOL )
;;;	XCALL W_DISP(POP_WND,WD_POS,1,1,WHDR(1,PLEN) )
;;;	XCALL W_DISP(POP_WND,WD_HLINE,2,1,PLEN+2)
	RETURN
;--------------------------

DSPWND,	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	;;; DISPLAY WINDOW, FILL W/ DATA
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; determine height & length of window, x & y coordinates
;;; to center window on screen.
	LAST_ROW = NUMROW				; + 1
	IF (NUMROW .GT. NUMARA) LAST_ROW = NUMARA	; + 1
;3-7-17	INCR LAST_ROW		;SSQ 6-17-98

	HT = LAST_ROW		;HEIGHT OF WINDOW, LEAVE ROOM FOR HEADER
	LN = PLEN + 2		;LENGHT OF WINDOW
	
	LN = LN + 1		;FOR "*"

	WHDR = DLINE

	IF (WX .LE. 0)
	THEN	X = (24-HT)/2		;X CO-ORDINATE
	ELSE	X = WX
	IF (WY .LE. 0)
	THEN	Y = (80-LN)/2		;Y CO-ORDINATE
	ELSE 	Y = WY

;;; place window...
	XCALL W_PROC(WP_FIND,POP_WND,POP_WID)
	IF (.NOT. POP_WND) XCALL W_PROC(WP_CREATE,POP_WND,POP_WID,HT,LN)

;;;	TITLEN = %TRIM(POP_TITLE)
;;;	IF (TITLEN .GT.0)
;;;&	 XCALL W_BRDR(POP_WND,WB_TITLE,POP_TITLE(1,TITLEN),WB_TPOS,WBT_TOP,WBT_CENTER)
	
	xcall w_brdr (pop_wnd, WB_DRAGOFF, WB_OFF)		;TURN OFF THE BORDER
	XCALL W_PROC(WP_PLACE,POP_WND,X,Y)
	XCALL W_DISP(POP_WND,WD_CLEAR)

;;;	XCALL W_DISP (POP_WND,WD_ATTR,ATTR_CLR+ATTR_RVRS)
;;;	XCALL W_DISP(POP_WND,WD_POS,1,1,WHDR(1,PLEN) )
;;;	XCALL W_DISP(POP_WND,WD_HLINE,2,1,PLEN+2)

;;; fill window w/ data...
	CLEAR ARO
	WLEN = LN
	WROW = 		;2
	FOR I FROM 1 THRU LAST_ROW		;-2
		BEGIN
		INCR WROW
		DLINE = PARRY(I)
		REST = DLINE(1,PLEN)
		XCALL W_DISP(POP_WND,WD_POS,WROW,1,WRKLIN(1,WLEN) )
		END
	IF (%PASSED(PALET)) XCALL W_AREA (POP_WND, WA_COLOR, PALET)	;ssq 12/11

	RETURN
;---------------------------------------------------------------------

