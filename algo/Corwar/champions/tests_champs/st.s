.name "st"
.comment "oui"

	# test reg->reg
	ld 	%625, r2
	st 	r2, r3
	st	r3, 145

	# test reg->reg neg
	ld 	%-625, r2
	st 	r2, r3
	st	r3, 150

	# test reg->reg high
	ld 	%625726, r2
	st 	r2, r3
	st	r3, 155

	# test reg->mem
	ld 	%625, r4
	st	r4, 750

	# test reg->mem neg
	ld 	%625, r4
	st	r4, -750

	# test reg->mem high
	ld 	%625, r4
	st	r4, 750819
