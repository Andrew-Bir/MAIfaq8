CC = gcc
LDFLAGS =-std=c99
CFLAGS =-c -std=c99
SOURCES = main.o matrix.o
EXECUTABLE = start

all: $(EXECUTABLE)


$(EXECUTABLE): $(SOURCES)
	$(CC) $(LDLAGS) $(SOURCES) -o $@


.c.o:
	$(CC) $(CFLAGS) $< -o $@


clean:
	-rm -f *.o start
	
