CC = gcc
OPTIONS = -Wall -Wextra -std=c11
EXE = recherche
FILENAME = recherche

recherche: $(FILENAME).c $(FILENAME).h
	$(CC) $(OPTIONS) $(FILENAME).c -o $(EXE)

test: recherche
	bats check.bats

compile: $(FILENAME).c $(FILENAME).h
	$(CC) $(OPTIONS) -c $(FILENAME).c

link: compile
	$(CC) $(FILENAME).o -o $(EXE)

clean:
	rm *.o -f
