.name "ld"
.comment "oui"

	# test direct
	ld 	%625, r2
	st	r2, 145

	# test neg direct
	ld 	%-457, r2
	st	r2, 150

	# test high direct
	ld 	%6657, r2
	st	r2, 155

	# test indirect
	ld 	0, r3
	st  r3, 225

	# test neg indirect
	ld 	-15, r3
	st  r3, 230

	# test high indirect
	ld 	65535, r3
	st  r3, 235
