CC=gcc
CFLAGS=-c -Wall -O
LDFLAGS=
SOURCES=main.c hello_master.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=binary

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	-rm -f *.o core *.core
