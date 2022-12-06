CC = gcc
OPTIONS = -Wall -Wextra -std=c11
EXE = recherche
FILENAME = recherche

.PHONY: clean valgrind

recherche: main.o linkedList.o stats.o tests.o
	$(CC) main.o linkedList.o stats.o tests.o -o $(EXE)

main.o: main.h main.c
	$(CC) $(OPTIONS) -c main.c

linkedList.o: linkedList.h linkedList.c
	$(CC) $(OPTIONS) -c linkedList.c

stats.o: stats.h stats.c
	$(CC) $(OPTIONS) -c stats.c

tests.o: tests.h tests.c
	$(CC) $(OPTIONS) -c tests.c

clean:
	rm -f *.o
	rm -f recherche
	rm -f *.txt

valgrind:
	valgrind --leak-check=yes -s --track-origins=yes ./recherche tests/banque1.txt
