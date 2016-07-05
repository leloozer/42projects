.name "zjmp"
.comment "oui"

	#### test carry à 0 ####
	live %0
	zjmp %400
	zjmp %400

	# test neg
	zjmp %-400

	# test high
	zjmp %436123

	#### test carry à 1 ####
	and	r1, r2, r3 # change le carry
	zjmp %400

	test neg
	zjmp %-400

	test high
	zjmp %7653273
