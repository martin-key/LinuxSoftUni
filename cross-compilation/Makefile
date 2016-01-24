CC=avr-gcc
CFLAGS=-c
LDFLAGS=
SOURCES=main.c sum.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=binary.bin

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	-rm -f *.o core *.core
