CC=gcc
CFLAGS=-c -Wall

all: main.o functions.o
	$(CC) main.o functions.o -o run.out

main.o: main.c
	$(CC) $(CFLAGS) main.c

functions.o: functions.c
	$(CC) $(CFLAGS) functions.c

clean:
	rm -rf *.o

run:
	./run.out "./workDir" 3
