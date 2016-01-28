CC=gcc
CFLAGS=-c -Wall
LDFLAGS=-pthread
SOURCES=main.c
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=binary

all: $(SOURCES) $(EXECUTABLE)
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
