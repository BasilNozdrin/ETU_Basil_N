CC=gcc
CFLAGS=-c -Wall

all: main

main: main.o text.o textio.h
	$(CC) main.o text.o textio.o -o main

main.o: main.c text.o textio.o
	$(CC) $(CFLAGS) main.c

text.o: text.c
	$(CC) $(CFLAGS) text.c

textio.o: textio.c text.o
	$(CC) $(CFLAGS) textio.c

clean:
	rm -rf *.o

test:
	./main < inp > outp
