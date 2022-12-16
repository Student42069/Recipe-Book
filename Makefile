CC = gcc
OPTIONS = -Wall -Wextra -std=c11
EXE = recherche
FILENAME = recherche

.PHONY: clean valgrind tests test

recherche: main.o linkedList.o stats.o central.o
	$(CC) main.o linkedList.o stats.o central.o -o $(EXE)

central.o: central.h central.c
	$(CC) $(OPTIONS) -c central.c
	
main.o: main.h main.c
	$(CC) $(OPTIONS) -c main.c

linkedList.o: linkedList.h linkedList.c
	$(CC) $(OPTIONS) -c linkedList.c

stats.o: stats.h stats.c
	$(CC) $(OPTIONS) -c stats.c

test: tests
	./tests

tests: tests.o main.o linkedList.o
	$(CC) tests.o main.o linkedList.o -lcunit -o tests

tests.o: tests.h tests.c
	$(CC) $(OPTIONS) -c tests.c

clean:
	rm -f *.o
	rm -f recherche
	rm -f *.txt
	rm -f tests

valgrind: recherche
	valgrind --leak-check=yes -s --track-origins=yes ./recherche test_files/banque2.txt < test_files/input.txt
