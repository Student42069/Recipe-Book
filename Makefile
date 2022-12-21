CC = gcc
OPTIONS = -Wall -Wextra -std=c11
EXE = recherche
FILENAME = recherche

.PHONY: clean valgrind tests test coverage

# Main usefull target to compile the software :
recherche: main.o linkedList.o stats.o central.o
	$(CC) main.o linkedList.o stats.o central.o -o $(EXE) -fprofile-arcs -ftest-coverage

# To compile (tests) AND execute CUnit tests :
test: tests
	./tests

# To check coverage of the CUnit tests :
coverage: test
	gcov main.c
	gcov linkedList.c
	gcov stats.c
	gcov tests.c

central.o: central.h central.c
	$(CC) $(OPTIONS) -c central.c
	
main.o: main.h main.c
	$(CC) $(OPTIONS) -c main.c -fprofile-arcs -ftest-coverage

linkedList.o: linkedList.h linkedList.c
	$(CC) $(OPTIONS) -c linkedList.c -fprofile-arcs -ftest-coverage

stats.o: stats.h stats.c
	$(CC) $(OPTIONS) -c stats.c -fprofile-arcs -ftest-coverage

# To compile only the ./tests executable :
tests: tests.o main.o linkedList.o stats.o
	$(CC) tests.o main.o linkedList.o stats.o -lcunit -o tests -fprofile-arcs -ftest-coverage

tests.o: tests.h tests.c
	$(CC) $(OPTIONS) -c tests.c -fprofile-arcs -ftest-coverage

clean:
	rm -f *.o
	rm -f recherche
	rm -f *.txt
	rm -f tests
	rm -f *.gcov
	rm -f *.gcda
	rm -f *.gcno

# To check for memory leaks :
valgrind: recherche
	valgrind --leak-check=yes --track-origins=yes ./recherche test_files/banque2.txt < test_files/input.txt
