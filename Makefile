CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/matrix.o $(OBJ)/node.o $(OBJ)/heap.o
HDRS = $(INC)/matrix.hpp $(INC)/node.hpp $(INC)/heap.hpp
CFLAGS = -g -Wall -c -I $(INC)

EXE = $(BIN)/tp3.out

all: $(EXE)

$(BIN)/tp3.out: $(OBJS)
	$(CC) -g -o $(BIN)/tp3.out $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/matrix.o: $(HDRS) $(SRC)/matrix.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/matrix.o $(SRC)/matrix.cpp

$(OBJ)/node.o: $(HDRS) $(SRC)/node.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/node.o $(SRC)/node.cpp

$(OBJ)/heap.o: $(HDRS) $(SRC)/heap.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/heap.o $(SRC)/heap.cpp
clean:
	rm -f $(EXE) $(OBJS) gmon.out