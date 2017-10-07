CC=gcc
CFLAGS=-I.
DEPS=parser.h
OBJ=parser.o shellbasico.o

%.o: %.c $(DEPS)
	$(CC) -Wall -c -o $@ $< $(CFLAGS)

# Makefile example
shellbasico: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

mypwd:
	$(CC) -Wall mypwd.c -o mypwd

mytime:
	$(CC) -Wall mytime.c -o mytime

clean:
	rm -f shellbasico $(OBJ) *~
	rm -f mytime
	rm -f mypwd
