CC = gcc
CFLAGS = -Wall -pedantic -ansi -std=c99 -O2 -g
OBJ = main.o matrix.o
EXECUTABLE = matrix
LIBS = -lm

.PHONY : all clean
all: $(OBJ) $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXECUTABLE) $(LIBS)

.c.o:
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf *~ 
	rm -f *.o matrix
