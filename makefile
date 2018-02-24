all: bin/hello bin/ut_all

bin/hello: src/hello.cpp
	g++ -std=c++11 src/hello.cpp -o bin/hello

bin/ut_all: obj/ut_main.o
	g++ -o bin/ut_all test/ut_main.cpp -lgtest -lpthread

obj/ut_main.o: test/ut_main.cpp test/ut_vector.h src/vector.h
	g++ -c test/ut_main.cpp -o obj/ut_main.o

clean:
	rm -f bin/* obj/*.o

stat:
	wc src/*.h src/*.cpp test/*.h test/*.cpp
