.PHONY: directories clean

all: directories bin/eigen

bin/eigen: eigen.cpp function.h
	g++ -std=c++11 -o bin/eigen eigen.cpp

directories:
	mkdir -p bin obj

clean:
	rm -rf  obj/* bin/*
