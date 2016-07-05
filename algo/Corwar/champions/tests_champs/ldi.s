.name "ldi"
.comment "oui"

	#### test reg ####
	ld 	%3, r2
	ld 	%4, r3
	ldi	r2, r3, r4
	st	r4, 245

	# test neg
	ld 	%-6, r2
	ld 	%-1, r3
	ldi	r2, r3, r4
	st	r4, 250

	# test high
	ld 	%65530, r2
	ld 	%1, r3
	ldi	r2, r3, r4
	st	r4, 255

	#### test direct ####
	ldi %2, %15, r5
	st	r5, 345

	# test neg
	ldi %-6, %-14, r5
	st	r5, 350

	# test high
	ldi %65530, %1, r5
	st	r5, 355

	#### test indirect ####
	ldi 0, %1, r6
	st	r6, 445

	# test neg
	ldi -12, %1, r6
	st	r6, 450

	# test high
	ldi 2132134, %1, r6
	st	r6, 455
