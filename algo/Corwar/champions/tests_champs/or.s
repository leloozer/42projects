.name "or"
.comment "oui"

	#### test reg ####
	ld 	%23, r2
	ld 	%24, r3
	or	r2, r3, r4
	st	r4, 145

	# test neg
	ld 	%-437, r2
	ld 	%-612, r3
	or	r2, r3, r4
	st	r4, 150

	# test high
	ld 	%2332321, r2
	ld 	%24324442, r3
	or	r2, r3, r4
	st	r4, 155

	#### test direct ####
	or %300, %423, r5
	st	r5, 245

	# test neg
	or %-300, %-423, r5
	st	r5, 250

	# test high
	or %3031230, %423, r5
	st	r5, 255

	#### test indirect ####
	or 0, 10, r8
	st	r8, 345

	# test neg
	or -12, -8, r8
	st	r8, 350

	# test high
	or 421321312, 21331, r8
	st	r8, 355
