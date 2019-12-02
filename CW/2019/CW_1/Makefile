CC=gcc
CFLAGS=-c -Wall

all: main

main: main.o text.o text_func.o
	$(CC) main.o text.o text_func.o -o main.out

main.o: main.c text.o text_func.o
	$(CC) $(CFLAGS) main.c

text.o: text.c
	$(CC) $(CFLAGS) text.c

text_func.o: text_func.c text.o
	$(CC) $(CFLAGS) text_func.c

clean:
	rm -rf *.o

test:
	./main.out < inp > outp
