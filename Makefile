CC=gcc
CFLAGS=-ansi -pedantic -Wall
LDFLAGS=-lncurses
OBJ=Main.o Liste.o Dico.o Graphisme.c Test.o Grille.o

Tp7: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

Main.o: Main.c Liste.h Dico.h Graphisme.h Test.h Grille.h

Liste.o: Liste.c Liste.h

Dico.o: Dico.c Dico.h

Graphisme.o: Graphisme.c Graphisme.h

Grille.o: Grille.c Grille.h Liste.h

Test.o: Test.c Test.h Liste.h Graphisme.h Dico.h Grille.h

%.o: %.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o

mrproper: clean
	rm -f Tp7
