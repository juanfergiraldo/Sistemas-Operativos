CC=gcc
CFLAGS=-I.
DEPS=parser.h
OBJ=parser.o shellbasico.o

%.o: %.c $(DEPS)
	$(CC) -Wall -c -o $@ $< $(CFLAGS)

# Makefile example
shellbasico: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f shellbasico $(OBJ) *~ 

