.name "lld"
.comment "oui"

	# test direct
	lld	%625, r2
	st	r2, 145

	# test neg direct
	lld	%-457, r2
	st	r2, 150

	# test high direct
	lld	%6657, r2
	st	r2, 155

	# test indirect
	lld	0, r3
	st  r3, 225

	# test neg indirect
	lld	-15, r3
	st  r3, 230

	# test high indirect
	lld	4099, r3
	st  r3, 235
