.name "aff"
.comment "oui"

	# ld %625, r2
	# st r2, 750
	# aff r2

	# # test neg
	# ld %-42, r2
	# st r2, 750
	# aff r2

	# test high
	ld %625324, r2
	st r2, 750
	aff r2
	