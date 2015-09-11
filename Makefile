CC=gcc
CFLAGS=-c -g -Wall

SOURCES=dh.c
OBJECTS=dh.o

EXECUTABLE=dh

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)  
	$(CC) $(OBJECTS) -o $(EXECUTABLE) 

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean

clean:
	rm $(OBJECTS) $(EXECUTABLE)
