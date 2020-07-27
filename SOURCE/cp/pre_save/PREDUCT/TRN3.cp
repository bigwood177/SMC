.function trn3
	in	,d.

record	vars
	dec	,d18

.proc
	dec=in/1000
	if(in.gt.dec*1000)dec=dec+1	
	freturn dec
.end
