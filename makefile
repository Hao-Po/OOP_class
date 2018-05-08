.PHONY: directories clean
CC=g++
CFLAGS=-std=c++11
LIBS=-lgtest -lpthread
OBJ=obj
BIN=bin
SRC=src
TEST=test

all: directories $(BIN)/ut_all

$(BIN)/ut_all: $(OBJ)/ut_main.o
	$(CC) $(CFLAGS) -o $@ $(OBJ)/ut_main.o $(LIBS)

bin/ut_all: obj/ut_main.o
	g++ -std=c++11 -o bin/ut_all obj/ut_main.o -lgtest -lpthread

obj/ut_main.o: test/ut_main.cpp test/test_dot.h test/test_string.h src/dot.h  src/term.h src/polynomial.h\
	src/vector_io.h src/vector.h src/gcd.h src/fraction.h test/test_fraction.h test/test_term.h test/test_polynomial.h \
	test/test_vector.h test/test_polygon.h src/polygon.h src/bubbleSort.h test/test_bubbleSort.h
	g++ -std=c++11 -c test/ut_main.cpp -o obj/ut_main.o

directories:
	mkdir -p bin obj

clean:
	rm -rf $(OBJ) $(BIN)

stat:
	wc $(SRC)/*.h $(SRC)/*.cpp $(TEST)/*.h $(TEST)/*.cpp
