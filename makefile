.PHONY: directories clean
CC=g++
CFLAGS=-std=c++11
LIBS=-lgtest -lpthread
OBJ=obj
BIN=bin
SRC=src
TEST=test

all: directories bin/ut_all

bin/ut_all: obj/ut_main.o
	g++ -std=c++11 -o bin/ut_all obj/ut_main.o -lgtest -lpthread 
obj/ut_main.o: test/ut_main.cpp \
		src/vector.h src/polygon.h src/circle.h src/shape.h src/dot.h src/bubblesort.h src/prism.h\
		test/test_vector.h test/test_polygon.h test/test_shape.h test/test_prism.h
	g++ -std=c++11 -c test/ut_main.cpp -o obj/ut_main.o

directories:
	mkdir -p bin obj

clean:
	rm -rf  obj/* bin/*

stat:
	wc $(SRC)/*.h $(SRC)/*.cpp $(TEST)/*.h $(TEST)/*.cpp
