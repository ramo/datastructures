CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=src/*
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=out/main

all: clean $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf out/*

run:
	./out/main