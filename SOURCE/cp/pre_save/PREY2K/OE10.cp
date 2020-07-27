SUBROUTINE OE10
;
;
;	OE10.COP - DISPLAYS DUCTWORK SCREEN
;
;			5/9/87 DS
;
PROC
	XCALL OUTPT (03,01,0,'   1. Type         ',1)
	XCALL OUTPT (04,01,0,'   2. Category     ',1)
	XCALL OUTPT (05,01,0,'   3. Style        ',1)
	XCALL OUTPT (06,01,0,'   4. Seam         ',1)
	XCALL OUTPT (07,01,0,'   5. Sealant      ',1)
	XCALL OUTPT (08,01,0,'   6. Qty/Joints  ______ ',1)
	XCALL OUTPT (09,01,0,'   7. Size        ___ X ___ X __ ',1)
	XCALL OUTPT (10,01,0,'   8. Gauge       __    ',1)
	XCALL OUTPT (11,01,0,'   9. Liner       _ ',1)
	XCALL OUTPT (12,01,0,'  10. Location    _______________',1)
	XCALL OUTPT (14,01,0,'  11. Access <2>  _   ',1)
	XCALL OUTPT (15,01,0,'  12. Slips       ',1)
	XCALL OUTPT (16,01,0,'  13. Drives      ',1)
	XCALL OUTPT (17,01,0,'  14. TDC Corners ',1)
	XCALL OUTPT (18,01,0,'  15. TDC N/B     ',1)
	XCALL OUTPT (19,01,0,'  16. TDC Gasket  ',1)
	XCALL OUTPT (20,01,0,'  17. TDC Cleats  ',1)
	XCALL OUTPT (21,01,0,'  18. TDC Bar     ',1)
	XCALL OUTPT (22,01,0,'  19. TDC Bar N/B ',1)
	RETURN
END
