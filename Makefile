CC=gcc
CFLAGS='-Wall' '-fdiagnostics-color=always'
DEPS='wrumple.h' 'ralts.h' 'kirlia.h 'gardevoir.h 'megaGardevoir.h'
OBJ=wrumple.o ralts.o kirlia.o gardevoir.o megaGardevoir.o pokemonShit.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $^ $(CFLAGS)

xPokemonShit: $(OBJ)
	$(CC) -o $@ $^ $(CTAGS)

wrumple.o: wrumple.c
	$(CC) -c wrumple.c

ralts.o: ralts.c
	$(CC) -c ralts.c

kirlia.o: kirlia.c
	$(CC) -c kirlia.c

gardevoir.o: gardevoir.c
	$(CC) -c gardevoir.c

megaGardevoir.o: megaGardevoir.c
	$(CC) -c megaGardevoir.c

pokemonShit.o: pokemonShit.c
	$(CC) -c pokemonShit.c

clean:
	rm *.o x*
