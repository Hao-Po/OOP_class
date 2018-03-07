.PHONY: directories clean stat

all: directories bin/ut_all

bin/ut_all: obj/ut_main.o
	g++ -o bin/ut_all obj/ut_main.o -lgtest -lpthread

obj/ut_main.o: test/ut_main.cpp test/test_dot.h src/dot.h
	g++ -c test/ut_main.cpp -o obj/ut_main.o

directories:
	mkdir -p bin obj

clean:
	rm -f bin/* obj/*.o

stat:
	wc src/*.h test/*.h test/*.cpp
