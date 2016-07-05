.name "lldi"
.comment "oui"

	#### test reg ####
	ld 	%3, r2
	ld 	%4, r3
	lldi	r2, r3, r4
	st	r4, 245

	# test neg
	ld 	%-5, r2
	ld 	%-3, r3
	lldi	r2, r3, r4
	st	r4, 250

	# test high
	ld 	%3096, r2
	ld 	%1001, r3
	lldi	r2, r3, r4
	st	r4, 255

	#### test direct ####
	lldi %4096, %4, r5
	st	r5, 345

	# test neg
	lldi %-4000, %-96, r5
	st	r5, 350

	# test high
	lldi %65530, %1, r5
	st	r5, 355

	#### test indirect ####
	lldi 0, %1, r6
	st	r6, 445

	# test neg
	lldi -12, %1, r6
	st	r6, 450

	# test high
	lldi 2132134, %1, r6
	st	r6, 455
