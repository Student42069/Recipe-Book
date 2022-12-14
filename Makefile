CC = gcc
OPTIONS = -Wall -Wextra -std=c11
EXE = recherche
FILENAME = recherche

.PHONY: clean valgrind tests

recherche: main.o linkedList.o stats.o
	$(CC) main.o linkedList.o stats.o -o $(EXE)

main.o: main.h main.c
	$(CC) $(OPTIONS) -c main.c

linkedList.o: linkedList.h linkedList.c
	$(CC) $(OPTIONS) -c linkedList.c

stats.o: stats.h stats.c
	$(CC) $(OPTIONS) -c stats.c

tests: tests.c main.c linkedList.c
	$(CC) main.c tests.c linkedList.c -lcunit -o tests

tests.o: tests.h tests.c
	$(CC) $(OPTIONS) -c tests.c

clean:
	rm -f *.o
	rm -f recherche
	rm -f *.txt

valgrind:
	valgrind --leak-check=yes -s --track-origins=yes ./recherche tests/banque1.txt
