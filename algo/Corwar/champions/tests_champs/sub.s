.name "sub"
.comment "oui"

	ld 	%15, r2
	ld 	%12, r3
	sub r3, r2, r4
	st	r4, 750

	# test neg
	ld 	%-12, r2
	ld 	%-155, r3
	sub r2, r3, r4
	st	r4, 150

	# test high
	ld 	%22, r2
	ld 	%31532321, r3
	sub r2, r3, r4
	st	r4, 155
	