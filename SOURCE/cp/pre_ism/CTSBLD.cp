$JOB/RT11                 !CTSBLD.COP      CTS300
	TTYIO
$CALL UTL:CTSCMP.MAN
$CALL SRC:CTSCMP.COP
$CALL SRC:CTSLNK.COP
.DELETE/NOQUERY OBJ:*.TMP
.DELETE/NOQUERY OBJ:*.DBL
$EOJ