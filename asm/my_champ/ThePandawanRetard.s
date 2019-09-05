.name "Letsgo"
.comment "Sans apostrophes ni espaces, GG l'auteur	TUEUR DE ZORK 1v1"

l2:	sti	r1, %:live,%1
#	ld	%1, r2

init:
	sti	r1, %:live4, %1
live4:	live	%18 #pas du tout générique :/
	lfork	%3043
	sti	r1, %:live3, %1
live3:	live	%18 #pas du tout générique :/

loop:
#	ld	%:l3, r4
#	sti	r4, %:jmp, %1
	zjmp	%:live
l3:	fork	%200
	sti	r1, %:live2, %1
live2:	live	%18 #pas du tout générique :/
	

live:	live	%18

jmp:
	add	r3, r2, r3
	and	r3, 100, r16 # censé etre un peu random
	zjmp	%:l3
	ld	%0, r16 # sert juste à remettre le carry à 1
	zjmp	%:loop
