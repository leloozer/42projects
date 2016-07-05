.name "sti"
.comment "oui"

	#### test reg ####
	ld 	%57, r2
	ld 	%98, r3
	ld 	%53, r4
	sti	r4, r2, r3 

	# test neg
	ld 	%-257, r2
	ld 	%-43, r3
	ld 	%-487, r4
	sti	r4, r2, r3 

	# test high
	ld 	%78685, r2
	ld 	%887662, r3
	ld 	%9695553, r4
	sti	r4, r2, r3 

	#### test direct ####
	ld 	%123, r4
	sti r4, %123, %14

	# test neg
	ld 	%-233, r4
	sti r4, %-123, %-14

	# test high
	ld 	%969555, r4
	sti r4, %12332, %21314

	#### test indirect ####
	ld 	%96, r4
	sti	r4, 210, %13

	# test neg
	ld 	%-233, r4
	sti r4, -123, %-14

	# test high
	ld 	%964545, r4
	sti r4, 12332, %21314
