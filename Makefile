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

tests: tests.o main.o linkedList.o
	$(CC) main.o tests.o linkedList.o -lcunit -o tests

tests.o: tests.h tests.c
	$(CC) $(OPTIONS) -c tests.c

clean:
	rm -f *.o
	rm -f recherche
	rm -f *.txt
	rm -f tests

valgrind:
	valgrind --leak-check=yes -s --track-origins=yes ./recherche test/banque1.txt
