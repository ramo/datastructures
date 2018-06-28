# Makefile for "myds" C++ application
# Created by Ramo 06/28/18

PROG = myds
CC = g++
CPPFLAGS = -g -Wall -I../include
LDFLAGS =
SRC_DIR = ../src
OBJ_DIR = ./obj
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

# make targets

$(PROG): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CPPFLAGS) -c -o $@ $^

.PHONY: clean

clean:
	rm -f core $(PROG) $(OBJECTS)

run:
	./$(PROG)