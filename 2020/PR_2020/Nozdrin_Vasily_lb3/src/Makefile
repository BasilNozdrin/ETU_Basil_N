CC=gcc

CFLAGS=-c -Wall


main: solution.o
	$(CC) solution.o -o run.out

solution.o: solution.c
	$(CC) $(CFLAGS) solution.c

clean:
	rm -rf *.o

run:
	./run.out "./tmp/"
