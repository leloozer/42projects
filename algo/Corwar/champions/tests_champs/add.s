.name "add"
.comment "oui"

	ld 	%12, r2
	ld 	%15, r3
	add r2, r3, r4
	st	r4, 145

	# test neg
	ld 	%12, r2
	ld 	%-155, r3
	add r2, r3, r4
	st	r4, 150

	# test high
	ld 	%12322, r2
	ld 	%1532321, r3
	add r2, r3, r4
	st	r4, 155
