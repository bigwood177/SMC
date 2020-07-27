!*****************************************************************************
!  T32CMP.COP
!
!         COMMAND FILE TO COMPILE COP RELEASE 7.0 ON TSX-32
!
!*****************************************************************************

ASSIGN C:\MCBA\SOURCE\COP\ SRC
ASSIGN C:\MCBA\SOURCE\DEF\ DEF
ASSIGN C:\MCBA\SOURCE\TEMP\ OBJ
ASSIGN C:\MCBA\EXECUTE\UT\ UT

DBR UT:GSORT
SRC:SRTBCU.COP
OBJ:SRTBCU.DBL

DBR UT:GSORT
SRC:SRTBIT.COP
OBJ:SRTBIT.DBL

DBR UT:GSORT
SRC:SRTBIX.COP
OBJ:SRTBIX.DBL

DBR UT:GSORT
SRC:SRTBLD.COP
OBJ:SRTBLD.DBL

DBR UT:GSORT
SRC:SRTLIX.COP
OBJ:SRTLIX.DBL

DBR UT:GSORT
SRC:SRTPDA.COP
OBJ:SRTPDA.DBL

DBR UT:GSORT
SRC:SRTPIX.COP
OBJ:SRTPIX.DBL

DBR UT:GSORT
SRC:SRTPRC.COP
OBJ:SRTPRC.DBL

DBR UT:GSORT
SRC:SRTSHT.COP
OBJ:SRTSHT.DBL

DBR UT:GSORT
SRC:SRTSHV.COP
OBJ:SRTSHV.DBL

DBR UT:GSORT
SRC:SRTSIX.COP
OBJ:SRTSIX.DBL

DBR UT:GSORT
SRC:SRTSLH.COP
OBJ:SRTSLH.DBL

DBR UT:GSORT
SRC:SRTSSM.COP
OBJ:SRTSSM.DBL

DBR UT:GSORT
SRC:STSAPC.COP
OBJ:STSAPC.DBL

DBL /OBJ=OBJ:ALNINV.TMP/R:DEBUG SRC:ALNINV.COP
DBL /OBJ=OBJ:ANALYS.TMP/R:DEBUG SRC:ANALYS.COP
DBL /OBJ=OBJ:BAKORD.TMP/R:DEBUG SRC:BAKORD.COP
DBL /OBJ=OBJ:BILEDT.TMP/R:DEBUG SRC:BILEDT.COP
DBL /OBJ=OBJ:BILIDX.TMP/R:DEBUG SRC:BILIDX.COP
DBL /OBJ=OBJ:BILLS.TMP/R:DEBUG SRC:BILLS.COP
DBL /OBJ=OBJ:BLADIN.TMP/R:DEBUG SRC:BLADIN.COP
DBL /OBJ=OBJ:BLDSLH.TMP/R:DEBUG SRC:BLDSLH.COP
DBL /OBJ=OBJ:BLMNU.TMP/R:DEBUG SRC:BLMNU.COP
DBL /OBJ=OBJ:BOCUST.TMP/R:DEBUG SRC:BOCUST.COP
DBL /OBJ=OBJ:BOITEM.TMP/R:DEBUG SRC:BOITEM.COP
DBL /OBJ=OBJ:CANCEL.TMP/R:DEBUG SRC:CANCEL.COP
DBL /OBJ=OBJ:CANEST.TMP/R:DEBUG SRC:CANEST.COP
DBL /OBJ=OBJ:CCTMNT.TMP/R:DEBUG SRC:CCTMNT.COP
DBL /OBJ=OBJ:CHANGE.TMP/R:DEBUG SRC:CHANGE.COP
DBL /OBJ=OBJ:CLRORD.TMP/R:DEBUG SRC:CLRORD.COP
!DBL /OBJ=OBJ:CLRMSS.TMP/R:DEBUG SRC:CLRMSS.COP
!DBL /OBJ=OBJ:CLRYSS.TMP/R:DEBUG SRC:CLRYSS.COP
!DBL /OBJ=OBJ:CMSC1.TMP/R:DEBUG SRC:CMSC1.COP
!DBL /OBJ=OBJ:CMSC2.TMP/R:DEBUG SRC:CMSC2.COP
!DBL /OBJ=OBJ:CMSC3.TMP/R:DEBUG SRC:CMSC3.COP
DBL /OBJ=OBJ:CPFILS.TMP/R:DEBUG SRC:CPFILS.COP
DBL /OBJ=OBJ:CPMENU.TMP/R:DEBUG SRC:CPMENU.COP
!DBL /OBJ=OBJ:CPRSLS.TMP/R:DEBUG SRC:CPRSLS.COP
DBL /OBJ=OBJ:CPSPOL.TMP/R:DEBUG SRC:CPSPOL.COP
!DBL /OBJ=OBJ:CUSSLS.TMP/R:DEBUG SRC:CUSSLS.COP
DBL /OBJ=OBJ:DETHIS.TMP/R:DEBUG SRC:DETHIS.COP
DBL /OBJ=OBJ:DUCBL.TMP/R:DEBUG SRC:DUCBL.COP
DBL /OBJ=OBJ:DUCMNT.TMP/R:DEBUG SRC:DUCMNT.COP
DBL /OBJ=OBJ:DFITM.TMP/R:DEBUG SRC:DFITM.COP
DBL /OBJ=OBJ:DSPDU.TMP/R:DEBUG SRC:DSPDU.COP
DBL /OBJ=OBJ:DUCCN.TMP/R:DEBUG SRC:DUCCN.COP
DBL /OBJ=OBJ:GETIM.TMP/R:DEBUG SRC:GETIM.COP
!DBL /OBJ=OBJ:HSTSEL.TMP/R:DEBUG SRC:HSTSEL.COP
DBL /OBJ=OBJ:INITCP.TMP/R:DEBUG SRC:INITCP.COP
DBL /OBJ=OBJ:INQUIR.TMP/R:DEBUG SRC:INQUIR.COP
DBL /OBJ=OBJ:INVOIC.TMP/R:DEBUG SRC:INVOIC.COP
DBL /OBJ=OBJ:LINBL.TMP/R:DEBUG SRC:LINBL.COP
DBL /OBJ=OBJ:LINCN.TMP/R:DEBUG SRC:LINCN.COP
DBL /OBJ=OBJ:OE1.TMP/R:DEBUG SRC:OE1.COP
DBL /OBJ=OBJ:OE2.TMP/R:DEBUG SRC:OE2.COP
DBL /OBJ=OBJ:OE3B.TMP/R:DEBUG SRC:OE3B.COP
DBL /OBJ=OBJ:OE4.TMP/R:DEBUG SRC:OE4.COP
DBL /OBJ=OBJ:OE6.TMP/R:DEBUG SRC:OE6.COP
DBL /OBJ=OBJ:OE7.TMP/R:DEBUG SRC:OE7.COP
DBL /OBJ=OBJ:OE10.TMP/R:DEBUG SRC:OE10.COP
DBL /OBJ=OBJ:OEMNU.TMP/R:DEBUG SRC:OEMNU.COP
DBL /OBJ=OBJ:ORDADD.TMP/R:DEBUG SRC:ORDADD.COP
DBL /OBJ=OBJ:ORDBL.TMP/R:DEBUG SRC:ORDBL.COP
DBL /OBJ=OBJ:ORDCN.TMP/R:DEBUG SRC:ORDCN.COP
DBL /OBJ=OBJ:ORDEDT.TMP/R:DEBUG SRC:ORDEDT.COP
DBL /OBJ=OBJ:ORDINQ.TMP/R:DEBUG SRC:ORDINQ.COP
DBL /OBJ=OBJ:ORDNUM.TMP/R:DEBUG SRC:ORDNUM.COP
DBL /OBJ=OBJ:ORGPDA.TMP/R:DEBUG SRC:ORGPDA.COP
!DBL /OBJ=OBJ:ORGSLS.TMP/R:DEBUG SRC:ORGSLS.COP
DBL /OBJ=OBJ:ORGSHV.TMP/R:DEBUG SRC:ORGSHV.COP
DBL /OBJ=OBJ:ORGSHT.TMP/R:DEBUG SRC:ORGSHT.COP
DBL /OBJ=OBJ:OSTATS.TMP/R:DEBUG SRC:OSTATS.COP
DBL /OBJ=OBJ:PDACNT.TMP/R:DEBUG SRC:PDACNT.COP
DBL /OBJ=OBJ:PDALST.TMP/R:DEBUG SRC:PDALST.COP
DBL /OBJ=OBJ:PDAMNT.TMP/R:DEBUG SRC:PDAMNT.COP
!DBL /OBJ=OBJ:PIKTIK.TMP/R:DEBUG SRC:PIKTIK.COP
DBL /OBJ=OBJ:POSTAR.TMP/R:DEBUG SRC:POSTAR.COP
DBL /OBJ=OBJ:PRCCNG.TMP/R:DEBUG SRC:PRCCNG.COP
DBL /OBJ=OBJ:PRCSEL.TMP/R:DEBUG SRC:PRCSEL.COP
!DBL /OBJ=OBJ:PRCSLS.TMP/R:DEBUG SRC:PRCSLS.COP
DBL /OBJ=OBJ:PRDSEL.TMP/R:DEBUG SRC:PRDSEL.COP
!DBL /OBJ=OBJ:PRDSLS.TMP/R:DEBUG SRC:PRDSLS.COP
DBL /OBJ=OBJ:PRGSLH.TMP/R:DEBUG SRC:PRGSLH.COP
DBL /OBJ=OBJ:PRICES.TMP/R:DEBUG SRC:PRICES.COP
DBL /OBJ=OBJ:PRTD2.TMP/R:DEBUG SRC:PRTD2.COP
DBL /OBJ=OBJ:PRTLI.TMP/R:DEBUG SRC:PRTLI.COP
DBL /OBJ=OBJ:PRTDU.TMP/R:DEBUG SRC:PRTDU.COP
DBL /OBJ=OBJ:PSTINV.TMP/R:DEBUG SRC:PSTINV.COP
DBL /OBJ=OBJ:PSTSLH.TMP/R:DEBUG SRC:PSTSLH.COP
DBL /OBJ=OBJ:PURMSG.TMP/R:DEBUG SRC:PURMSG.COP
DBL /OBJ=OBJ:RBLISM.TMP/R:DEBUG SRC:RBLISM.COP
DBL /OBJ=OBJ:RSTCOM.TMP/R:DEBUG SRC:RSTCOM.COP
DBL /OBJ=OBJ:SAPCAT.TMP/R:DEBUG SRC:SAPCAT.COP
DBL /OBJ=OBJ:SCRN1.TMP/R:DEBUG SRC:SCRN1.COP
DBL /OBJ=OBJ:SCRN2.TMP/R:DEBUG SRC:SCRN2.COP
DBL /OBJ=OBJ:SCRN3.TMP/R:DEBUG SRC:SCRN3.COP
DBL /OBJ=OBJ:SCRN5.TMP/R:DEBUG SRC:SCRN5.COP
DBL /OBJ=OBJ:SHVCNT.TMP/R:DEBUG SRC:SHVCNT.COP
DBL /OBJ=OBJ:SHVMNT.TMP/R:DEBUG SRC:SHVMNT.COP
DBL /OBJ=OBJ:SHVPRT.TMP/R:DEBUG SRC:SHVPRT.COP
DBL /OBJ=OBJ:SHTCNT.TMP/R:DEBUG SRC:SHTCNT.COP
DBL /OBJ=OBJ:SHTMNT.TMP/R:DEBUG SRC:SHTMNT.COP
DBL /OBJ=OBJ:SHTPRT.TMP/R:DEBUG SRC:SHTPRT.COP
DBL /OBJ=OBJ:SLHCNT.TMP/R:DEBUG SRC:SLHCNT.COP
DBL /OBJ=OBJ:SLHENT.TMP/R:DEBUG SRC:SLHENT.COP
DBL /OBJ=OBJ:SLHPR1.TMP/R:DEBUG SRC:SLHPR1.COP
DBL /OBJ=OBJ:SLHPR2.TMP/R:DEBUG SRC:SLHPR2.COP
DBL /OBJ=OBJ:SLHPR3.TMP/R:DEBUG SRC:SLHPR3.COP
DBL /OBJ=OBJ:SSMCNT.TMP/R:DEBUG SRC:SSMCNT.COP
DBL /OBJ=OBJ:SLHEDT.TMP/R:DEBUG SRC:SLHEDT.COP
DBL /OBJ=OBJ:SLHINQ.TMP/R:DEBUG SRC:SLHINQ.COP
DBL /OBJ=OBJ:SLHJNL.TMP/R:DEBUG SRC:SLHJNL.COP
DBL /OBJ=OBJ:SLHYEN.TMP/R:DEBUG SRC:SLHYEN.COP
DBL /OBJ=OBJ:SLMORD.TMP/R:DEBUG SRC:SLMORD.COP
DBL /OBJ=OBJ:SPCFUN.TMP/R:DEBUG SRC:SPCFUN.COP
!
DBL /OBJ=OBJ:SRTBCU.TMP/R:DEBUG OBJ:SRTBCU.DBL
DBL /OBJ=OBJ:SRTBIT.TMP/R:DEBUG OBJ:SRTBIT.DBL
DBL /OBJ=OBJ:SRTBIX.TMP/R:DEBUG OBJ:SRTBIX.DBL
DBL /OBJ=OBJ:SRTBLD.TMP/R:DEBUG OBJ:SRTBLD.DBL
DBL /OBJ=OBJ:SRTLIX.TMP/R:DEBUG OBJ:SRTLIX.DBL
DBL /OBJ=OBJ:SRTPDA.TMP/R:DEBUG OBJ:SRTPDA.DBL
DBL /OBJ=OBJ:SRTPIX.TMP/R:DEBUG OBJ:SRTPIX.DBL
DBL /OBJ=OBJ:SRTPRC.TMP/R:DEBUG OBJ:SRTPRC.DBL
DBL /OBJ=OBJ:SRTSHT.TMP/R:DEBUG OBJ:SRTSHT.DBL
DBL /OBJ=OBJ:SRTSHV.TMP/R:DEBUG OBJ:SRTSHV.DBL
DBL /OBJ=OBJ:SRTSIX.TMP/R:DEBUG OBJ:SRTSIX.DBL
DBL /OBJ=OBJ:SRTSLH.TMP/R:DEBUG OBJ:SRTSLH.DBL
DBL /OBJ=OBJ:SRTSSM.TMP/R:DEBUG OBJ:SRTSSM.DBL
DBL /OBJ=OBJ:STSAPC.TMP/R:DEBUG OBJ:STSAPC.DBL
!
DBL /OBJ=OBJ:SSCNT.TMP/R:DEBUG SRC:SSCNT.COP
DBL /OBJ=OBJ:SSIUPD.TMP/R:DEBUG SRC:SSIUPD.COP
DBL /OBJ=OBJ:SSMENU.TMP/R:DEBUG SRC:SSMENU.COP
!DBL /OBJ=OBJ:SSSET.TMP/R:DEBUG SRC:SSSET.COP
DBL /OBJ=OBJ:SSSFMN.TMP/R:DEBUG SRC:SSSFMN.COP
!DBL /OBJ=OBJ:SSUPD.TMP/R:DEBUG SRC:SSUPD.COP
DBL /OBJ=OBJ:TERMSD.TMP/R:DEBUG SRC:TERMSD.COP
DBL /OBJ=OBJ:TPRICE.TMP/R:DEBUG SRC:TPRICE.COP
DBL /OBJ=OBJ:TRKMNT.TMP/R:DEBUG SRC:TRKMNT.COP
DBL /OBJ=OBJ:UNBILL.TMP/R:DEBUG SRC:UNBILL.COP
DBL /OBJ=OBJ:UNPRBL.TMP/R:DEBUG SRC:UNPRBL.COP
DBL /OBJ=OBJ:UNPRBO.TMP/R:DEBUG SRC:UNPRBO.COP
DBL /OBJ=OBJ:UNPRCM.TMP/R:DEBUG SRC:UNPRCM.COP
DBL /OBJ=OBJ:UNPRSA.TMP/R:DEBUG SRC:UNPRSA.COP
DBL /OBJ=OBJ:UNPSLH.TMP/R:DEBUG SRC:UNPSLH.COP
DBL /OBJ=OBJ:UPDMIS.TMP/R:DEBUG SRC:UPDMIS.COP
DBL /OBJ=OBJ:WRKORD.TMP/R:DEBUG SRC:WRKORD.COP
!
!
DBL /OBJ=SRC:ALNINV.BND/BIND/S:REFRESH/R:DEBUG SRC:ALNINV.COP
DBL /OBJ=SRC:ANALYS.BND/BIND/S:REFRESH/R:DEBUG SRC:ANALYS.COP
DBL /OBJ=SRC:BAKORD.BND/BIND/S:REFRESH/R:DEBUG SRC:BAKORD.COP
DBL /OBJ=SRC:BILEDT.BND/BIND/S:REFRESH/R:DEBUG SRC:BILEDT.COP
DBL /OBJ=SRC:BILIDX.BND/BIND/S:REFRESH/R:DEBUG SRC:BILIDX.COP
DBL /OBJ=SRC:BILLS.BND/BIND/S:REFRESH/R:DEBUG SRC:BILLS.COP
DBL /OBJ=SRC:BLADIN.BND/BIND/S:REFRESH/R:DEBUG SRC:BLADIN.COP
DBL /OBJ=SRC:BLDSLH.BND/BIND/S:REFRESH/R:DEBUG SRC:BLDSLH.COP
DBL /OBJ=SRC:BLMNU.BND/BIND/S:REFRESH/R:DEBUG SRC:BLMNU.COP
DBL /OBJ=SRC:BOCUST.BND/BIND/S:REFRESH/R:DEBUG SRC:BOCUST.COP
DBL /OBJ=SRC:BOITEM.BND/BIND/S:REFRESH/R:DEBUG SRC:BOITEM.COP
DBL /OBJ=SRC:CANCEL.BND/BIND/S:REFRESH/R:DEBUG SRC:CANCEL.COP
DBL /OBJ=SRC:CANEST.BND/BIND/S:REFRESH/R:DEBUG SRC:CANEST.COP
DBL /OBJ=SRC:CCTMNT.BND/BIND/S:REFRESH/R:DEBUG SRC:CCTMNT.COP
DBL /OBJ=SRC:CHANGE.BND/BIND/S:REFRESH/R:DEBUG SRC:CHANGE.COP
DBL /OBJ=SRC:CLRORD.BND/BIND/S:REFRESH/R:DEBUG SRC:CLRORD.COP
!DBL /OBJ=SRC:CLRMSS.BND/BIND/S:REFRESH/R:DEBUG SRC:CLRMSS.COP
!DBL /OBJ=SRC:CLRYSS.BND/BIND/S:REFRESH/R:DEBUG SRC:CLRYSS.COP
!DBL /OBJ=SRC:CMSC1.BND/S:REFRESH/R:DEBUG SRC:CMSC1.COP
!DBL /OBJ=SRC:CMSC2.BND/S:REFRESH/R:DEBUG SRC:CMSC2.COP
!DBL /OBJ=SRC:CMSC3.BND/S:REFRESH/R:DEBUG SRC:CMSC3.COP
DBL /OBJ=SRC:CPFILS.BND/BIND/S:REFRESH/R:DEBUG SRC:CPFILS.COP
DBL /OBJ=SRC:CPMENU.BND/PRIMARY/S:REFRESH/R:DEBUG SRC:CPMENU.COP
!DBL /OBJ=SRC:CPRSLS.BND/BIND/S:REFRESH/R:DEBUG SRC:CPRSLS.COP
DBL /OBJ=SRC:CPSPOL.BND/BIND/S:REFRESH/R:DEBUG SRC:CPSPOL.COP
!DBL /OBJ=SRC:CUSSLS.BND/BIND/S:REFRESH/R:DEBUG SRC:CUSSLS.COP
DBL /OBJ=SRC:DETHIS.BND/BIND/S:REFRESH/R:DEBUG SRC:DETHIS.COP
DBL /OBJ=SRC:DUCBL.BND/S:REFRESH/R:DEBUG SRC:DUCBL.COP
DBL /OBJ=SRC:DUCCN.BND/S:REFRESH/R:DEBUG SRC:DUCCN.COP
DBL /OBJ=SRC:DUCMNT.BND/S:REFRESH/R:DEBUG SRC:DUCMNT.COP
DBL /OBJ=SRC:DFITM.BND/S:REFRESH/R:DEBUG SRC:DFITM.COP
DBL /OBJ=SRC:DSPDU.BND/S:REFRESH/R:DEBUG SRC:DSPDU.COP
DBL /OBJ=SRC:GETIM.BND/S:REFRESH/R:DEBUG SRC:GETIM.COP
!DBL /OBJ=SRC:HSTSEL.BND/BIND/S:REFRESH/R:DEBUG SRC:HSTSEL.COP
DBL /OBJ=SRC:INITCP.BND/BIND/S:REFRESH/R:DEBUG SRC:INITCP.COP
DBL /OBJ=SRC:INQUIR.BND/BIND/S:REFRESH/R:DEBUG SRC:INQUIR.COP
DBL /OBJ=SRC:INVOIC.BND/BIND/S:REFRESH/R:DEBUG SRC:INVOIC.COP
DBL /OBJ=SRC:LINBL.BND/S:REFRESH/R:DEBUG SRC:LINBL.COP
DBL /OBJ=SRC:LINCN.BND/S:REFRESH/R:DEBUG SRC:LINCN.COP
DBL /OBJ=SRC:OE1.BND/S:REFRESH/R:DEBUG SRC:OE1.COP
DBL /OBJ=SRC:OE2.BND/S:REFRESH/R:DEBUG SRC:OE2.COP
DBL /OBJ=SRC:OE3B.BND/S:REFRESH/R:DEBUG SRC:OE3B.COP
DBL /OBJ=SRC:OE4.BND/S:REFRESH/R:DEBUG SRC:OE4.COP
DBL /OBJ=SRC:OE6.BND/S:REFRESH/R:DEBUG SRC:OE6.COP
DBL /OBJ=SRC:OE7.BND/S:REFRESH/R:DEBUG SRC:OE7.COP
DBL /OBJ=SRC:OE10.BND/S:REFRESH/R:DEBUG SRC:OE10.COP
DBL /OBJ=SRC:OEMNU.BND/BIND/S:REFRESH/R:DEBUG SRC:OEMNU.COP
DBL /OBJ=SRC:ORDADD.BND/BIND/S:REFRESH/R:DEBUG SRC:ORDADD.COP
DBL /OBJ=SRC:ORDBL.BND/S:REFRESH/R:DEBUG SRC:ORDBL.COP
DBL /OBJ=SRC:ORDCN.BND/S:REFRESH/R:DEBUG SRC:ORDCN.COP
DBL /OBJ=SRC:ORDEDT.BND/BIND/S:REFRESH/R:DEBUG SRC:ORDEDT.COP
DBL /OBJ=SRC:ORDINQ.BND/BIND/S:REFRESH/R:DEBUG SRC:ORDINQ.COP
DBL /OBJ=SRC:ORDNUM.BND/BIND/S:REFRESH/R:DEBUG SRC:ORDNUM.COP
DBL /OBJ=SRC:ORGPDA.BND/BIND/S:REFRESH/R:DEBUG SRC:ORGPDA.COP
!DBL /OBJ=SRC:ORGSLS.BND/BIND/S:REFRESH/R:DEBUG SRC:ORGSLS.COP
DBL /OBJ=SRC:ORGSHV.BND/BIND/S:REFRESH/R:DEBUG SRC:ORGSHV.COP
DBL /OBJ=SRC:ORGSHT.BND/BIND/S:REFRESH/R:DEBUG SRC:ORGSHT.COP
DBL /OBJ=SRC:PDACNT.BND/BIND/S:REFRESH/R:DEBUG SRC:PDACNT.COP
DBL /OBJ=SRC:PDALST.BND/BIND/S:REFRESH/R:DEBUG SRC:PDALST.COP
DBL /OBJ=SRC:PDAMNT.BND/BIND/S:REFRESH/R:DEBUG SRC:PDAMNT.COP
!DBL /OBJ=SRC:PIKTIK.BND/BIND/S:REFRESH/R:DEBUG SRC:PIKTIK.COP
DBL /OBJ=SRC:POSTAR.BND/BIND/S:REFRESH/R:DEBUG SRC:POSTAR.COP
DBL /OBJ=SRC:PRCCNG.BND/BIND/S:REFRESH/R:DEBUG SRC:PRCCNG.COP
DBL /OBJ=SRC:PRCSEL.BND/BIND/S:REFRESH/R:DEBUG SRC:PRCSEL.COP
!DBL /OBJ=SRC:PRCSLS.BND/BIND/S:REFRESH/R:DEBUG SRC:PRCSLS.COP
DBL /OBJ=SRC:PRDSEL.BND/BIND/S:REFRESH/R:DEBUG SRC:PRDSEL.COP
!DBL /OBJ=SRC:PRDSLS.BND/BIND/S:REFRESH/R:DEBUG SRC:PRDSLS.COP
DBL /OBJ=SRC:PRGSLH.BND/BIND/S:REFRESH/R:DEBUG SRC:PRGSLH.COP
DBL /OBJ=SRC:PRICES.BND/BIND/S:REFRESH/R:DEBUG SRC:PRICES.COP
DBL /OBJ=SRC:PRTD2.BND/S:REFRESH/R:DEBUG SRC:PRTD2.COP
DBL /OBJ=SRC:PRTLI.BND/S:REFRESH/R:DEBUG SRC:PRTLI.COP
DBL /OBJ=SRC:PRTDU.BND/S:REFRESH/R:DEBUG SRC:PRTDU.COP
DBL /OBJ=SRC:PSTINV.BND/BIND/S:REFRESH/R:DEBUG SRC:PSTINV.COP
DBL /OBJ=SRC:PSTSLH.BND/BIND/S:REFRESH/R:DEBUG SRC:PSTSLH.COP
DBL /OBJ=SRC:PURMSG.BND/BIND/S:REFRESH/R:DEBUG SRC:PURMSG.COP
DBL /OBJ=SRC:RSTCOM.BND/BIND/S:REFRESH/R:DEBUG SRC:RSTCOM.COP
DBL /OBJ=SRC:SAPCAT.BND/BIND/S:REFRESH/R:DEBUG SRC:SAPCAT.COP
DBL /OBJ=SRC:SCRN1.BND/S:REFRESH/R:DEBUG SRC:SCRN1.COP
DBL /OBJ=SRC:SCRN2.BND/S:REFRESH/R:DEBUG SRC:SCRN2.COP
DBL /OBJ=SRC:SCRN3.BND/S:REFRESH/R:DEBUG SRC:SCRN3.COP
DBL /OBJ=SRC:SCRN5.BND/S:REFRESH/R:DEBUG SRC:SCRN5.COP
DBL /OBJ=SRC:SHVCNT.BND/BIND/S:REFRESH/R:DEBUG SRC:SHVCNT.COP
DBL /OBJ=SRC:SHVMNT.BND/BIND/S:REFRESH/R:DEBUG SRC:SHVMNT.COP
DBL /OBJ=SRC:SHVPRT.BND/BIND/S:REFRESH/R:DEBUG SRC:SHVPRT.COP
DBL /OBJ=SRC:SHTCNT.BND/BIND/S:REFRESH/R:DEBUG SRC:SHTCNT.COP
DBL /OBJ=SRC:SHTMNT.BND/BIND/S:REFRESH/R:DEBUG SRC:SHTMNT.COP
DBL /OBJ=SRC:SHTPRT.BND/BIND/S:REFRESH/R:DEBUG SRC:SHTPRT.COP
DBL /OBJ=SRC:SLHCNT.BND/BIND/S:REFRESH/R:DEBUG SRC:SLHCNT.COP
DBL /OBJ=SRC:SLHENT.BND/BIND/S:REFRESH/R:DEBUG SRC:SLHENT.COP
DBL /OBJ=OBJ:SLHPR1.BND/BIND/S:REFRESH/R:DEBUG SRC:SLHPR1.COP
DBL /OBJ=OBJ:SLHPR2.BND/BIND/S:REFRESH/R:DEBUG SRC:SLHPR2.COP
DBL /OBJ=OBJ:SLHPR3.BND/BIND/S:REFRESH/R:DEBUG SRC:SLHPR3.COP
DBL /OBJ=SRC:SSMCNT.BND/BIND/S:REFRESH/R:DEBUG SRC:SSMCNT.COP
DBL /OBJ=SRC:SLHEDT.BND/BIND/S:REFRESH/R:DEBUG SRC:SLHEDT.COP
DBL /OBJ=SRC:SLHINQ.BND/BIND/S:REFRESH/R:DEBUG SRC:SLHINQ.COP
DBL /OBJ=SRC:SLHJNL.BND/BIND/S:REFRESH/R:DEBUG SRC:SLHJNL.COP
DBL /OBJ=SRC:SLHYEN.BND/BIND/S:REFRESH/R:DEBUG SRC:SLHYEN.COP
DBL /OBJ=SRC:SLMORD.BND/BIND/S:REFRESH/R:DEBUG SRC:SLMORD.COP
DBL /OBJ=SRC:SPCFUN.BND/BIND/S:REFRESH/R:DEBUG SRC:SPCFUN.COP
!
DBL /OBJ=SRC:SRTBCU.BND/BIND/S:REFRESH/R:DEBUG OBJ:SRTBCU.DBL
DBL /OBJ=SRC:SRTBIT.BND/BIND/S:REFRESH/R:DEBUG OBJ:SRTBIT.DBL
DBL /OBJ=SRC:SRTBIX.BND/BIND/S:REFRESH/R:DEBUG OBJ:SRTBIX.DBL
DBL /OBJ=SRC:SRTBLD.BND/BIND/S:REFRESH/R:DEBUG OBJ:SRTBLD.DBL
DBL /OBJ=SRC:SRTLIX.BND/BIND/S:REFRESH/R:DEBUG OBJ:SRTLIX.DBL
DBL /OBJ=SRC:SRTPDA.BND/BIND/S:REFRESH/R:DEBUG OBJ:SRTPDA.DBL
DBL /OBJ=SRC:SRTPIX.BND/BIND/S:REFRESH/R:DEBUG OBJ:SRTPIX.DBL
DBL /OBJ=SRC:SRTPRC.BND/BIND/S:REFRESH/R:DEBUG OBJ:SRTPRC.DBL
DBL /OBJ=SRC:SRTSHT.BND/BIND/S:REFRESH/R:DEBUG OBJ:SRTSHT.DBL
DBL /OBJ=SRC:SRTSHV.BND/BIND/S:REFRESH/R:DEBUG OBJ:SRTSHV.DBL
DBL /OBJ=SRC:SRTSIX.BND/BIND/S:REFRESH/R:DEBUG OBJ:SRTSIX.DBL
DBL /OBJ=SRC:SRTSLH.BND/BIND/S:REFRESH/R:DEBUG OBJ:SRTSLH.DBL
DBL /OBJ=SRC:SRTSSM.BND/BIND/S:REFRESH/R:DEBUG OBJ:SRTSSM.DBL
DBL /OBJ=SRC:STSAPC.BND/BIND/S:REFRESH/R:DEBUG OBJ:STSAPC.DBL
!
DBL /OBJ=SRC:SSCNT.BND/BIND/S:REFRESH/R:DEBUG SRC:SSCNT.COP
DBL /OBJ=SRC:SSIUPD.BND/BIND/S:REFRESH/R:DEBUG SRC:SSIUPD.COP
DBL /OBJ=SRC:SSMENU.BND/BIND/S:REFRESH/R:DEBUG SRC:SSMENU.COP
DBL /OBJ=SRC:SSSFMN.BND/BIND/S:REFRESH/R:DEBUG SRC:SSSFMN.COP
!DBL /OBJ=SRC:SSSET.BND/BIND/S:REFRESH/R:DEBUG SRC:SSSET.COP
!DBL /OBJ=SRC:SSUPD.BND/BIND/S:REFRESH/R:DEBUG SRC:SSUPD.COP
DBL /OBJ=SRC:TERMSD.BND/BIND/S:REFRESH/R:DEBUG SRC:TERMSD.COP
DBL /OBJ=SRC:TPRICE.BND/BIND/S:REFRESH/R:DEBUG SRC:TPRICE.COP
DBL /OBJ=SRC:TRKMNT.BND/BIND/S:REFRESH/R:DEBUG SRC:TRKMNT.COP
DBL /OBJ=SRC:UNBILL.BND/BIND/S:REFRESH/R:DEBUG SRC:UNBILL.COP
DBL /OBJ=SRC:UNPRBL.BND/BIND/S:REFRESH/R:DEBUG SRC:UNPRBL.COP
DBL /OBJ=SRC:UNPRBO.BND/BIND/S:REFRESH/R:DEBUG SRC:UNPRBO.COP
DBL /OBJ=SRC:UNPRCM.BND/BIND/S:REFRESH/R:DEBUG SRC:UNPRCM.COP
DBL /OBJ=SRC:UNPRSA.BND/BIND/S:REFRESH/R:DEBUG SRC:UNPRSA.COP
DBL /OBJ=SRC:UNPSLH.BND/BIND/S:REFRESH/R:DEBUG SRC:UNPSLH.COP
DBL /OBJ=SRC:UPDMIS.BND/BIND/S:REFRESH/R:DEBUG SRC:UPDMIS.COP
!
del obj:*.dbl/noq
!
!*****************************************************************************
!  T32CMP.IM
!
!         COMMAND FILE TO COMPILE IM RELEASE 7.0 ON TSX-32
!
!*****************************************************************************
!
! no assignments already set above
!
!ASSIGN C:\MCBA\SOURCE\IM\ SRC
!ASSIGN C:\MCBA\SOURCE\DEF\ DEF
!ASSIGN C:\MCBA\SOURCE\TEMP\ OBJ
!ASSIGN C:\MCBA\EXECUTE\UT\ UT

DBR UT:GSORT
SRC:SRTIID.IM
OBJ:SRTIID.DBL

DBL /OBJ=OBJ:ADVICE.TMP/R:DEBUG SRC:ADVICE.IM
DBL /OBJ=OBJ:CLRMO2.TMP/R:DEBUG SRC:CLRMO2.IM
DBL /OBJ=OBJ:CLRYOE.TMP/R:DEBUG SRC:CLRYOE.IM
DBL /OBJ=OBJ:IMFCNT.TMP/R:DEBUG SRC:IMFCNT.IM
DBL /OBJ=OBJ:IMFMNT.TMP/R:DEBUG SRC:IMFMNT.IM
DBL /OBJ=OBJ:IMFM1.TMP/R:DEBUG SRC:IMFM1.IM
DBL /OBJ=OBJ:IMFPRT.TMP/R:DEBUG SRC:IMFPRT.IM
DBL /OBJ=OBJ:INITIM.TMP/R:DEBUG SRC:INITIM.IM
DBL /OBJ=OBJ:ORGIMF.TMP/R:DEBUG SRC:ORGIMF.IM
!
DBL /OBJ=OBJ:SRTIID.TMP/R:DEBUG OBJ:SRTIID.DBL
!
!
!
DBL /OBJ=SRC:ADVICE.BND/BIND/S:REFRESH/R:DEBUG SRC:ADVICE.IM
DBL /OBJ=SRC:CLRMO2.BND/BIND/S:REFRESH/R:DEBUG SRC:CLRMO2.IM
DBL /OBJ=SRC:CLRYOE.BND/BIND/S:REFRESH/R:DEBUG SRC:CLRYOE.IM
DBL /OBJ=SRC:IMFCNT.BND/BIND/S:REFRESH/R:DEBUG SRC:IMFCNT.IM
DBL /OBJ=SRC:IMFMNT.BND/BIND/S:REFRESH/R:DEBUG SRC:IMFMNT.IM
DBL /OBJ=SRC:IMFM1.BND/S:REFRESH/R:DEBUG SRC:IMFM1.IM
DBL /OBJ=SRC:IMFPRT.BND/BIND/S:REFRESH/R:DEBUG SRC:IMFPRT.IM
DBL /OBJ=SRC:INITIM.BND/BIND/S:REFRESH/R:DEBUG SRC:INITIM.IM
DBL /OBJ=SRC:ORGIMF.BND/BIND/S:REFRESH/R:DEBUG SRC:ORGIMF.IM
!
DBL /OBJ=SRC:SRTIID.BND/BIND/S:REFRESH/R:DEBUG OBJ:SRTIID.DBL
!
del obj:*.dbl/noq
!

