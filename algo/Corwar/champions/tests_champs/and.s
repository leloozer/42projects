.name "and"
.comment "oui"

	#### test reg ####
	ld 	%23, r2
	ld 	%24, r3
	and	r2, r3, r4
	st	r4, 145

	# test neg
	ld 	%-437, r2
	ld 	%-612, r3
	and	r2, r3, r4
	st	r4, 150

	# test high
	ld 	%2332321, r2
	ld 	%24324442, r3
	and	r2, r3, r4
	st	r4, 155

	#### test direct ####
	and %300, %423, r5
	st	r5, 245

	# test neg
	and %-300, %-423, r5
	st	r5, 250

	# test high
	and %3031230, %423, r5
	st	r5, 255

	#### test indirect ####
	and 0, 10, r8
	st	r8, 345

	# test neg
	and -12, -8, r8
	st	r8, 350

	# test high
	and 421321312, 21331, r8
	st	r8, 355
