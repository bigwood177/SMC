$JOB/RT11	 !CTSLNK.COP
	TTYIO
.R LINK
*EXE:ALNINV.TSD=OBJ:ALNINV.TMP,UT:UTIL,SY:TDIBOL/B:100000/C
*UT:TERID.TM1,UT:PGCHN.TM1/O:1/C
*UT:LPON.TM1/O:1/C
*UT:LPOUT.TM1,UT:LINFD.TM1/O:1/C
*UT:LPOFF.TM1/O:1/C
*UT:FILES.TM1/O:1/C
*UT:FFILE.TM1/O:2/C
*UT:MOUNT.TM1,UT:DSPLY.TM1/O:2/C
*UT:SNMSG.TM1/O:2
*EXE:ANALYS.TSD=OBJ:ANALYS.TMP,UT:UTIL,SY:TDIBOL/B:100000/C
*UT:TERID.TM1,UT:PGCHN.TM1/O:1/C
*UT:FILES.TM1/O:1
*EXE:BAKORD.TSD=OBJ:BAKORD.TMP,UT:UTIL,SY:TDIBOL/B:100000/C
*UT:TERID.TM1,UT:PGCHN.TM1/O:1/C
*UT:FILES.TM1/O:1/C
*UT:OFILE.TM1,UT:MESAG.TM1/O:1
*EXE:BILEDT.TSD=OBJ:BILEDT.TMP,UT:UTIL,SY:TDIBOL/B:100000/C
*UT:TERID.TM1,UT:PGCHN.TM1/O:1/C
*UT:FILES.TM1/O:1/C
*UT:LPON.TM1/O:1/C
*UT:LPOUT.TM1,UT:LINFD.TM1/O:1/C
*UT:LPOFF.TM1/O:1/C
*UT:INPUT.TM1/O:2/C
*UT:SERCH.TM1/O:2/C
*UT:IO.TM1/O:2/C
*UT:IOS.TM1/O:2/C
*UT:ISIO.TM1/O:3/C
*UT:STENO.TM1/O:3/C
*UT:MESAG.TM1,UT:DSPLY.TM1/O:3
*EXE:BILLS.TSD=OBJ:BILLS.TMP,UT:UTIL,SY:TDIBOL/B:100000/C
*UT:TERID.TM1,UT:PGCHN.TM1/O:1/C
*OBJ:ORDBL.TMP/O:1/C
*OBJ:LINBL.TMP/O:1/C
*UT:FILES.TM1/O:2/C
*UT:DSPLY.TM1,UT:MESAG.TM1,UT:INPUT.TM1/O:2/C
*UT:SERCH.TM1,UT:IO.TM1/O:2/C
*UT:IOS.TM1,UT:ISIO.TM1/O:2/C
*UT:SNMSG.TM1,UT:WATE.TM1/O:2/C
*UT:ANYCN.TM1/O:3/C
*UT:GETAC.TM1/O:3/C
*OBJ:BLMNU.TMP/O:3/C
*OBJ:OE1.TMP/O:3/C
*OBJ:OE3.TMP/O:3/C
*OBJ:OE4.TMP/O:3/C
*OBJ:OE7.TMP/O:3
*EXE:BLDSLH.TSD=OBJ:BLDSLH.TMP,UT:UTIL,SY:TDIBOL/B:100000/C
*UT:TERID.TM1,UT:PGCHN.TM1/O:1/C
*UT:FILES.TM1/O:1
*EXE:BOCUST.TSD=OBJ:BOCUST.TMP,UT:UTIL,SY:TDIBOL/B:100000/C
*UT:TERID.TM1,UT:PGCHN.TM1/O:1/C
*UT:FILES.TM1/O:1/C
*UT:LPON.TM1/O:1/C
*UT:LPOUT.TM1/O:1/C
*UT:LPOFF.TM1/O:1
*EXE:BOITEM.TSD=OBJ:BOITEM.TMP,UT:UTIL,SY:TDIBOL/B:100000/C
*UT:TERID.TM1,UT:PGCHN.TM1/O:1/C
*UT:FILES.TM1/O:1/C
*UT:LPON.TM1/O:1/C
*UT:LPOUT.TM1/O:1/C
*UT:LPOFF.TM1/O:1
$EOD
.R REDUCE
*EXE:ALNINV.TSD/N
*EXE:ANALYS.TSD/N
*EXE:BAKORD.TSD/N
*EXE:BILEDT.TSD/N
*EXE:BILLS.TSD/N
*EXE:BLDSLH.TSD/N
*EXE:BOCUST.TSD/N
*EXE:BOITEM.TSD/N
$EOD
.R LINK
*EXE:CCTMNT.TSD=OBJ:CCTMNT.TMP,UT:UTIL,SY:TDIBOL/B:100000
*EXE:CANCEL.TSD=OBJ:CANCEL.TMP,UT:UTIL,SY:TDIBOL/B:100000/C
*UT:TERID.TM1,UT:PGCHN.TM1/O:1/C
*OBJ:UNCOM.TMP/O:1/C
*OBJ:OE1.TMP/O:1/C
*UT:FILES.TM1/O:1
*EXE:CHANGE.TSD=OBJ:CHANGE.TMP,UT:UTIL,SY:TDIBOL/B:100000/C
*UT:TERID.TM1,UT:PGCHN.TM1/O:1/C
*UT:FILES.TM1/O:1/C
*OBJ:ORDCN.TMP/O:1/C
*OBJ:LINCN.TMP/O:1/C
*OBJ:RECOM.TMP/O:2/C
*OBJ:OE1.TMP/O:2/C
*OBJ:OE4.TMP/O:2/C
*OBJ:OE6.TMP/O:2/C
*UT:INPUT.TM1/O:2/C
*UT:SERCH.TM1/O:3/C
*UT:IO.TM1/O:3/C
*UT:IOS.TM1/O:3/C
*UT:ISIO.TM1/O:3/C
*UT:DSPLY.TM1/O:3/C
*UT:MESAG.TM1/O:3/C
*UT:WATE.TM1,UT:FRMAT.TM1/O:3
*EXE:CLRCRH.TSD=OBJ:CLRCRH.TMP,UT:UTIL,SY:TDIBOL/B:100000
*EXE:CLRCRL.TSD=OBJ:CLRCRL.TMP,UT:UTIL,SY:TDIBOL/B:100000
*EXE:CLRHDR.TSD=OBJ:CLRHDR.TMP,UT:UTIL,SY:TDIBOL/B:100000
*EXE:CLRLIN.TSD=OBJ:CLRLIN.TMP,UT:UTIL,SY:TDIBOL/B:100000
*EXE:CLRMSS.TSD=OBJ:CLRMSS.TMP,UT:UTIL,SY:TDIBOL/B:100000
$EOD
.R REDUCE
*EXE:CCTMNT.TSD/N
*EXE:CANCEL.TSD/N
*EXE:CHANGE.TSD/N
*EXE:CLRCRH.TSD/N
*EXE:CLRCRL.TSD/N
*EXE:CLRHDR.TSD/N
*EXE:CLRLIN.TSD/N
*EXE:CLRMSS.TSD/N
$EOD
.R LINK
*EXE:CLRYSS.TSD=OBJ:CLRYSS.TMP,UT:UTIL,SY:TDIBOL/B:100000
*EXE:CPFILS.TSD=OBJ:CPFILS.TMP,UT:UTIL,SY:TDIBOL/B:100000
*EXE:CPMENU.TSD=OBJ:CPMENU.TMP,UT:UTIL,SY:TDIBOL/B:100000
*EXE:CPRSLS.TSD=OBJ:CPRSLS.TMP,UT:UTIL,SY:TDIBOL/B:100000/C
*UT:TERID.TM1,UT:PGCHN.TM1/O:1/C
*UT:FILES.TM1/O:1/C
*UT:LPON.TM1/O:1/C
*UT:LPOUT.TM1/O:1/C
*UT:LPOFF.TM1/O:1/C
*UT:SERCH.TM1,UT:IO.TM1/O:1
*EXE:CPSPOL.TSD=OBJ:CPSPOL.TMP,UT:UTIL,SY:TDIBOL/B:100000
*EXE:CRHCNT.TSD=OBJ:CRHCNT.TMP,UT:UTIL,SY:TDIBOL/B:100000
$EOD
.R REDUCE
*EXE:CLRYSS.TSD/N
*EXE:CPFILS.TSD/N
*EXE:CPMENU.TSD/N
*EXE:CPRSLS.TSD/N
*EXE:CPSPOL.TSD/N
*EXE:CRHCNT.TSD/N
$EOD
.R LINK
*EXE:CRMAR.TSD=OBJ:CRMAR.TMP,UT:UTIL,SY:TDIBOL/B:100000
*EXE:CRMCNC.TSD=OBJ:CRMCNC.TMP,CR4.TMP,UT:UTIL,SY:TDIBOL/B:100000
*EXE:CRMEDT.TSD=OBJ:CRMEDT.TMP,UT:UTIL,SY:TDIBOL/B:100000/C
*UT:TERID.TM1,UT:PGCHN.TM1/O:1/C
*UT:FILES.TM1/O:1/C
*UT:LPON.TM1/O:1/C
*UT:LPOUT.TM1/O:1/C
*UT:LPOFF.TM1/O:1
*EXE:CRMENT.TSD=OBJ:CRMENT.TMP,UT:UTIL,SY:TDIBOL/B:100000/C
*UT:TERID.TM1,UT:PGCHN.TM1/O:1/C
*UT:FILES.TM1/O:1/C
*OBJ:CMSC1.TMP/O:1/C
*OBJ:CMSC2.TMP/O:1/C
*OBJ:CMSC3.TMP/O:1/C
*OBJ:CRMNU.TMP/O:2/C
*OBJ:CR1.TMP/O:2/C
*OBJ:CR2.TMP/O:2/C
*OBJ:CR3.TMP/O:2
*EXE:CRMINV.TSD=OBJ:CRMINV.TMP,UT:UTIL,SY:TDIBOL/B:100000
*EXE:CSLHJL.TSD=OBJ:CSLHJL.TMP,UT:UTIL,SY:TDIBOL/B:100000/C
*UT:TERID.TM1,UT:PGCHN.TM1/O:1/C
*UT:FILES.TM1/O:1/C
*UT:LPON.TM1/O:1/C
*UT:LPOUT.TM1,UT:LINFD.TM1/O:1/C
*UT:LPOFF.TM1/O:1/C
*UT:SERCH.TM1,UT:IO.TM1,UT:IOS.TM1/O:1
*EXE:CUSSLS.TSD=OBJ:CUSSLS.TMP,UT:UTIL,SY:TDIBOL/B:100000/C
*UT:TERID.TM1,UT:PGCHN.TM1/O:1/C
*UT:FILES.TM1/O:1/C
*UT:LPON.TM1/O:1/C
*UT:LPOUT.TM1/O:1/C
*UT:LPOFF.TM1/O:1
*EXE:HSTSEL.TSD=OBJ:HSTSEL.TMP,UT:UTIL,SY:TDIBOL/B:100000
$EOD
.R REDUCE
*EXE:CRMAR.TSD/N
*EXE:CRMCNC.TSD/N
*EXE:CRMEDT.TSD/N
*EXE:CRMENT.TSD/N
*EXE:CRMINV.TSD/N
*EXE:CSLHJL.TSD/N
*EXE:CUSSLS.TSD/N
*EXE:HSTSEL.TSD/N
$EOD
.R LINK
*EXE:INITCP.TSD=OBJ:INITCP.TMP,UT:UTIL,SY:TDIBOL/B:100000
*EXE:INQUIR.TSD=OBJ:INQUIR.TMP,UT:UTIL,SY:TDIBOL/B:100000/C
*UT:TERID.TM1,UT:PGCHN.TM1/O:1/C
*UT:FILES.TM1/O:1/C
*OBJ:OE1.TMP/O:1/C
*OBJ:OE2.TMP/O:1/C
*UT:INPUT.TM1/O:2/C
*UT:SERCH.TM1/O:2/C
*UT:IO.TM1,UT:IOS.TM1/O:2/C
*UT:ISIO.TM1/O:2
*EXE:INVOIC.TSD=OBJ:INVOIC.TMP,UT:UTIL,SY:TDIBOL/B:100000/C
*UT:TERID.TM1,UT:PGCHN.TM1/O:1/C
*UT:FILES.TM1/O:1/C
*UT:LPON.TM1/O:1/C
*UT:LPOUT.TM1,UT:LINFD.TM1/O:1/C
*UT:LPOFF.TM1/O:1/C
*UT:FFILE.TM1/O:1/C
*UT:IO.TM1,UT:IOS.TM1/O:1/C
*UT:ISIO.TM1,UT:SERCH.TM1/O:1/C
*UT:STENO.TM1,UT:MOUNT.TM1,UT:DSPLY.TM1/O:1/C
*UT:RDATE.TM1,UT:LEFTJ.TM1,UT:WATE.TM1/O:1
*EXE:LINIDX.TSD=OBJ:LINIDX.TMP,UT:UTIL,SY:TDIBOL/B:100000
*EXE:OEMNU.TSD=OBJ:OEMNU.TMP,UT:UTIL,SY:TDIBOL/B:100000
*EXE:ORDADD.TSD=OBJ:ORDADD.TMP,UT:UTIL,SY:TDIBOL/B:100000/C
*UT:TERID.TM1,UT:PGCHN.TM1/O:1/C
*UT:FILES.TM1/O:1/C
*OBJ:SCRN1.TMP/O:1/C
*OBJ:SCRN2.TMP/O:1/C
*OBJ:COMIT.TMP/O:2/C
*OBJ:OE1.TMP/O:2/C
*OBJ:OE2.TMP/O:2/C
*OBJ:OE4.TMP/O:2/C
*UT:INPUT.TM1/O:2/C
*UT:SERCH.TM1/O:3/C
*UT:IO.TM1/O:3/C
*UT:MESAG.TM1/O:3/C
*UT:DSPLY.TM1/O:3/C
*UT:ISIO.TM1/O:3/C
*UT:WATE.TM1,UT:RDATE.TM1,UT:GETAC.TM1/O:3/C
*UT:FRMAT.TM1,UT:ANYCN.TM1/O:3
*EXE:ORDEDT.TSD=OBJ:ORDEDT.TMP,UT:UTIL,SY:TDIBOL/B:100000/C
*UT:TERID.TM1,UT:PGCHN.TM1/O:1/C
*UT:FILES.TM1/O:1/C
*UT:LPON.TM1/O:1/C
*UT:LPOUT.TM1,UT:LINFD.TM1/O:1/C
*UT:LPOFF.TM1/O:1/C
*UT:INPUT.TM1/O:2/C
*UT:SERCH.TM1/O:2/C
*UT:IO.TM1,UT:IOS.TM1/O:2/C
*UT:ISIO.TM1/O:2
*EXE:ORGPDA.TSD=OBJ:ORGPDA.TMP,UT:UTIL,SY:TDIBOL/B:100000
$EOD
.R REDUCE
*EXE:INITCP.TSD/N
*EXE:INQUIR.TSD/N
*EXE:INVOIC.TSD/N
*EXE:LINIDX.TSD/N
*EXE:OEMNU.TSD/N
*EXE:ORDADD.TSD/N
*EXE:ORDEDT.TSD/N
*EXE:ORGPDA.TSD/N
$EOD
.R LINK
*EXE:ORGSHV.TSD=OBJ:ORGSHV.TMP,UT:UTIL,SY:TDIBOL/B:100000
*EXE:ORGSHT.TSD=OBJ:ORGSHT.TMP,UT:UTIL,SY:TDIBOL/B:100000/C
*UT:TERID.TM1,UT:PGCHN.TM1/O:1/C
*UT:FILES.TM1/O:1/C
*UT:SNMSG.TM1,UT:IO.TM1/O:1
*EXE:ORGSLS.TSD=OBJ:ORGSLS.TMP,UT:UTIL,SY:TDIBOL/B:100000/C
*UT:TERID.TM1,UT:PGCHN.TM1/O:1/C
*UT:FILES.TM1/O:1
*EXE:PDACNT.TSD=OBJ:PDACNT.TMP,UT:UTIL,SY:TDIBOL/B:100000
*EXE:PDALST.TSD=OBJ:PDALST.TMP,UT:UTIL,SY:TDIBOL/B:100000/C
*UT:TERID.TM1,UT:PGCHN.TM1/O:1/C
*UT:FILES.TM1/O:1/C
*UT:LPON.TM1/O:1/C
*UT:LPOUT.TM1/O:1/C
*UT:LPOFF.TM1/O:1
*EXE:PDAMNT.TSD=OBJ:PDAMNT.TMP,UT:UTIL,SY:TDIBOL/B:100000
*EXE:PIKTIK.TSD=OBJ:PIKTIK.TMP,UT:UTIL,SY:TDIBOL/B:100000/C
*UT:TERID.TM1,UT:PGCHN.TM1/O:1/C
*UT:LPON.TM1/O:1/C
*UT:LPOUT.TM1,UT:LINFD.TM1/O:1/C
*UT:LPOFF.TM1/O:1/C
*UT:FILES.TM1/O:1/C
*OBJ:FNDPS.TMP/O:1/C
*UT:SERCH.TM1/O:2/C
*UT:IO.TM1/O:2/C
*UT:IOS.TM1/O:2/C
*UT:ISIO.TM1/O:2/C
*UT:STENO.TM1/O:2/C
*UT:MOUNT.TM1/O:2/C
*UT:SNMSG.TM1/O:2/C
*UT:MESAG.TM1/O:2/C
*UT:FFILE.TM1/O:2/C
*UT:RDATE.TM1,UT:LEFTJ.TM1/O:2
*EXE:POSTAR.TSD=OBJ:POSTAR.TMP,UT:UTIL,SY:TDIBOL/B:100000/C
*UT:TERID.TM1,UT:PGCHN.TM1/O:1/C
*UT:FILES.TM1/O:1/C
*UT:SERCH.TM1,UT:IOS.TM1/O:1
$EOD
.R REDUCE
*EXE:ORGSHV.TSD/N
*EXE:ORGSHT.TSD/N
*EXE:ORGSLS.TSD/N
*EXE:PDACNT.TSD/N
*EXE:PDALST.TSD/N
*EXE:PDAMNT.TSD/N
*EXE:PIKTIK.TSD/N
*EXE:POSTAR.TSD/N
$EOD
.R LINK
*EXE:PRCCNG.TSD=OBJ:PRCCNG.TMP,UT:UTIL,SY:TDIBOL/B:100000
*EXE:PRCMNT.TSD=OBJ:PRCMNT.TMP,UT:UTIL,SY:TDIBOL/B:100000
*EXE:PRCSEL.TSD=OBJ:PRCSEL.TMP,UT:UTIL,SY:TDIBOL/B:100000
*EXE:PRCSLS.TSD=OBJ:PRCSLS.TMP,UT:UTIL,SY:TDIBOL/B:100000/C
*UT:TERID.TM1,UT:PGCHN.TM1/O:1/C
*UT:FILES.TM1/O:1/C
*UT:LPON.TM1/O:1/C
*UT:LPOUT.TM1,UT:LINFD.TM1/O:1/C
*UT:LPOFF.TM1/O:1
*EXE:PRDSEL.TSD=OBJ:PRDSEL.TMP,UT:UTIL,SY:TDIBOL/B:100000
*EXE:PRDSLS.TSD=OBJ:PRDSLS.TMP,UT:UTIL,SY:TDIBOL/B:100000/C
*UT:TERID.TM1,UT:PGCHN.TM1/O:1/C
*UT:FILES.TM1/O:1/C
*UT:LPON.TM1/O:1/C
*UT:LPOUT.TM1,UT:LINFD.TM1/O:1/C
*UT:LPOFF.TM1/O:1
*EXE:PRGSLH.TSD=OBJ:PRGSLH.TMP,UT:UTIL,SY:TDIBOL/B:100000/C
*UT:TERID.TM1,UT:PGCHN.TM1/O:1/C
*UT:FILES.TM1/O:1/C
*UT:LPON.TM1/O:1/C
*UT:LPOUT.TM1/O:1/C
*UT:LPOFF.TM1/O:1/C
*UT:SNMSG.TM1,UT:MOUNT.TM1/O:1
*EXE:PRICES.TSD=OBJ:PRICES.TMP,UT:UTIL,SY:TDIBOL/B:100000/C
*UT:TERID.TM1,UT:PGCHN.TM1/O:1/C
*UT:FILES.TM1/O:1/C
*UT:LPON.TM1/O:1/C
*UT:LPOUT.TM1/O:1/C
*UT:LPOFF.TM1/O:1
$EOD
.R REDUCE
*EXE:PRCCNG.TSD/N
*EXE:PRCMNT.TSD/N
*EXE:PRCSEL.TSD/N
*EXE:PRCSLS.TSD/N
*EXE:PRDSEL.TSD/N
*EXE:PRDSLS.TSD/N
*EXE:PRGSLH.TSD/N
*EXE:PRICES.TSD/N
$EOD
.R LINK
*EXE:PRTCRM.TSD=OBJ:PRTCRM.TMP,UT:UTIL,SY:TDIBOL/B:100000/C
*UT:TERID.TM1,UT:PGCHN.TM1/O:1/C
*UT:FILES.TM1/O:1/C
*UT:LPON.TM1/O:1/C
*UT:LPOUT.TM1/O:1/C
*UT:LPOFF.TM1/O:1
*EXE:PSTCRM.TSD=OBJ:PSTCRM.TMP,UT:UTIL,SY:TDIBOL/B:100000
*EXE:PSTINV.TSD=OBJ:PSTINV.TMP,UT:UTIL,SY:TDIBOL/B:100000/C
*UT:TERID.TM1,UT:PGCHN.TM1/O:1/C
*OBJ:BPOST.TMP/O:1/C
*UT:FILES.TM1/O:1
*EXE:PSTSLH.TSD=OBJ:PSTSLH.TMP,UT:UTIL,SY:TDIBOL/B:100000
*EXE:PURMSG.TSD=OBJ:PURMSG.TMP,UT:UTIL,SY:TDIBOL/B:100000
*EXE:RSTCOM.TSD=OBJ:RSTCOM.TMP,COMSB.TMP,UT:UTIL,SY:TDIBOL/B:100000/C
*UT:TERID.TM1,UT:PGCHN.TM1/O:1/C
*UT:FILES.TM1/O:1/C
*UT:LPON.TM1/O:1/C
*UT:LPOUT.TM1,UT:LINFD.TM1/O:1/C
*UT:LPOFF.TM1/O:1/C
*UT:SERCH.TM1,UT:IO.TM1,UT:IOS.TM1/O:1
*EXE:SAPCAT.TSD=OBJ:SAPCAT.TMP,UT:UTIL,SY:TDIBOL/B:100000/C
*UT:TERID.TM1,UT:PGCHN.TM1/O:1/C
*UT:FILES.TM1/O:1/C
*UT:LPON.TM1/O:1/C
*UT:LPOUT.TM1/O:1/C
*UT:LPOFF.TM1/O:1
*EXE:SHVCNT.TSD=OBJ:SHVCNT.TMP,UT:UTIL,SY:TDIBOL/B:100000
$EOD
.R REDUCE
*EXE:PRTCRM.TSD/N
*EXE:PSTCRM.TSD/N
*EXE:PSTINV.TSD/N
*EXE:PSTSLH.TSD/N
*EXE:PURMSG.TSD/N
*EXE:RSTCOM.TSD/N
*EXE:SAPCAT.TSD/N
*EXE:SHVCNT.TSD/N
$EOD
.R LINK
*EXE:SHVMNT.TSD=OBJ:SHVMNT.TMP,UT:UTIL,SY:TDIBOL/B:100000
*EXE:SHVPRT.TSD=OBJ:SHVPRT.TMP,UT:UTIL,SY:TDIBOL/B:100000/C
*UT:TERID.TM1,UT:PGCHN.TM1/O:1/C
*UT:FILES.TM1/O:1/C
*UT:LPON.TM1/O:1/C
*UT:LPOUT.TM1,UT:LINFD.TM1/O:1/C
*UT:LPOFF.TM1/O:1
*EXE:SHTCNT.TSD=OBJ:SHTCNT.TMP,UT:UTIL,SY:TDIBOL/B:100000
*EXE:SHTMNT.TSD=OBJ:SHTMNT.TMP,UT:UTIL,SY:TDIBOL/B:100000/C
*UT:TERID.TM1,UT:PGCHN.TM1/O:1/C
*UT:FILES.TM1/O:1
*EXE:SHTPRT.TSD=OBJ:SHTPRT.TMP,UT:UTIL,SY:TDIBOL/B:100000/C
*UT:TERID.TM1,UT:PGCHN.TM1/O:1/C
*UT:FILES.TM1/O:1/C
*UT:LPON.TM1/O:1/C
*UT:LPOUT.TM1/O:1/C
*UT:LPOFF.TM1/O:1
*EXE:SLHEDT.TSD=OBJ:SLHEDT.TMP,UT:UTIL,SY:TDIBOL/B:100000/C
*UT:TERID.TM1,UT:PGCHN.TM1/O:1/C
*UT:FILES.TM1/O:1/C
*UT:LPON.TM1/O:1/C
*UT:LPOUT.TM1/O:1/C
*UT:LPOFF.TM1/O:1
*EXE:SLHJNL.TSD=OBJ:SLHJNL.TMP,UT:UTIL,SY:TDIBOL/B:100000/C
*UT:OFILE.TM1/O:1/C
*UT:FILES.TM1/O:1/C
*UT:LPON.TM1/O:1/C
*UT:LPOUT.TM1,UT:LINFD.TM1/O:1/C
*UT:LPOFF.TM1/O:1/C
*UT:TERID.TM1,UT:PGCHN.TM1/O:1/C
*UT:SERCH.TM1/O:1/C
*UT:IO.TM1,UT:IOS.TM1/O:1
*EXE:SPCFUN.TSD=OBJ:SPCFUN.TMP,UT:UTIL,SY:TDIBOL/B:100000
$EOD
.R REDUCE
*EXE:SHVMNT.TSD/N
*EXE:SHVPRT.TSD/N
*EXE:SHTCNT.TSD/N
*EXE:SHTMNT.TSD/N
*EXE:SHTPRT.TSD/N
*EXE:SLHEDT.TSD/N
*EXE:SLHJNL.TSD/N
*EXE:SPCFUN.TSD/N
$EOD
.R LINK
*EXE:SRTBCU.TSD=OBJ:SRTBCU.TMP,UT:UTIL,SY:TDIBOL/B:100000
*EXE:SRTBIT.TSD=OBJ:SRTBIT.TMP,UT:UTIL,SY:TDIBOL/B:100000
*EXE:SRTBLD.TSD=OBJ:SRTBLD.TMP,UT:UTIL,SY:TDIBOL/B:100000
*EXE:SRTCRH.TSD=OBJ:SRTCRH.TMP,UT:UTIL,SY:TDIBOL/B:100000
*EXE:SRTCRL.TSD=OBJ:SRTCRL.TMP,UT:UTIL,SY:TDIBOL/B:100000
*EXE:SRTLIX.TSD=OBJ:SRTLIX.TMP,UT:UTIL,SY:TDIBOL/B:100000
*EXE:SRTPDA.TSD=OBJ:SRTPDA.TMP,UT:UTIL,SY:TDIBOL/B:100000
*EXE:SRTPIX.TSD=OBJ:SRTPIX.TMP,UT:UTIL,SY:TDIBOL/B:100000
$EOD
.R REDUCE
*EXE:SRTBCU.TSD/N
*EXE:SRTBIT.TSD/N
*EXE:SRTBLD.TSD/N
*EXE:SRTCRH.TSD/N
*EXE:SRTCRL.TSD/N
*EXE:SRTLIX.TSD/N
*EXE:SRTPDA.TSD/N
*EXE:SRTPIX.TSD/N
$EOD
.R LINK
*EXE:SRTPRC.TSD=OBJ:SRTPRC.TMP,UT:UTIL,SY:TDIBOL/B:100000
*EXE:SRTSHV.TSD=OBJ:SRTSHV.TMP,UT:UTIL,SY:TDIBOL/B:100000
*EXE:SRTSHT.TSD=OBJ:SRTSHT.TMP,UT:UTIL,SY:TDIBOL/B:100000
*EXE:SRTSIX.TSD=OBJ:SRTSIX.TMP,UT:UTIL,SY:TDIBOL/B:100000
*EXE:SRTSLH.TSD=OBJ:SRTSLH.TMP,UT:UTIL,SY:TDIBOL/B:100000
*EXE:STSAPC.TSD=OBJ:STSAPC.TMP,UT:UTIL,SY:TDIBOL/B:100000
*EXE:SSCNT.TSD=OBJ:SSCNT.TMP,UT:UTIL,SY:TDIBOL/B:100000
*EXE:SSIUPD.TSD=OBJ:SSIUPD.TMP,UT:UTIL,SY:TDIBOL/B:100000
*EXE:SSMENU.TSD=OBJ:SSMENU.TMP,UT:UTIL,SY:TDIBOL/B:100000
$EOD
.R REDUCE
*EXE:SRTPRC.TSD/N
*EXE:SRTSHV.TSD/N
*EXE:SRTSHT.TSD/N
*EXE:SRTSIX.TSD/N
*EXE:SRTSLH.TSD/N
*EXE:STSAPC.TSD/N
*EXE:SSCNT.TSD/N
*EXE:SSIUPD.TSD/N
*EXE:SSMENU.TSD/N
$EOD
.R LINK
*EXE:SSSET.TSD=OBJ:SSSET.TMP,UT:UTIL,SY:TDIBOL/B:100000
*EXE:SSSFMN.TSD=OBJ:SSSFMN.TMP,UT:UTIL,SY:TDIBOL/B:100000
*EXE:SSUPD.TSD=OBJ:SSUPD.TMP,UT:UTIL,SY:TDIBOL/B:100000
*EXE:TERMSD.TSD=OBJ:TERMSD.TMP,UT:UTIL,SY:TDIBOL/B:100000
*EXE:TRADED.TSD=OBJ:TRADED.TMP,UT:UTIL,SY:TDIBOL/B:100000
*EXE:UNBILL.TSD=OBJ:UNBILL.TMP,OE1.TMP,UT:UTIL,SY:TDIBOL/B:100000/C
*UT:TERID.TM1,UT:PGCHN.TM1/O:1/C
*UT:FILES.TM1/O:1/C
*UT:INPUT.TM1/O:1/C
*UT:IO.TM1/O:2/C
*UT:IOS.TM1/O:2/C
*UT:ISIO.TM1/O:2/C
*UT:MESAG.TM1,UT:DSPLY.TM1/O:2/C
*UT:SERCH.TM1/O:2
*EXE:UNPRBL.TSD=OBJ:UNPRBL.TMP,UT:UTIL,SY:TDIBOL/B:100000
$EOD
.R REDUCE
*EXE:SSSET.TSD/N
*EXE:SSSFMN.TSD/N
*EXE:SSUPD.TSD/N
*EXE:TERMSD.TSD/N
*EXE:TRADED.TSD/N
*EXE:UNBILL.TSD/N
*EXE:UNPRBL.TSD/N
$EOD
.R LINK
*EXE:UNPRBO.TSD=OBJ:UNPRBO.TMP,UT:UTIL,SY:TDIBOL/B:100000
*EXE:UNPRCM.TSD=OBJ:UNPRCM.TMP,UT:UTIL,SY:TDIBOL/B:100000
*EXE:UNPRSA.TSD=OBJ:UNPRSA.TMP,UT:UTIL,SY:TDIBOL/B:100000
*EXE:UNPSLH.TSD=OBJ:UNPSLH.TMP,UT:UTIL,SY:TDIBOL/B:100000
*EXE:CVCP70.TSD=OBJ:CVCP70.TMP,UT:UTIL,SY:TDIBOL/B:100000
$EOD
.R REDUCE
*EXE:UNPRBO.TSD/N
*EXE:UNPRCM.TSD/N
*EXE:UNPRSA.TSD/N
*EXE:UNPSLH.TSD/N
*EXE:CVCP70.TSD/N
$EOD
$EOJ
