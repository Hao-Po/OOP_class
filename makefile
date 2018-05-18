.PHONY: directories clean

all: directories bin/ut_all

bin/ut_all: obj/ut_main.o
	g++ -std=c++11 -o bin/ut_all obj/ut_main.o -lgtest -lpthread

obj/ut_main.o: \
	test/ut_main.cpp test/test_dot.h test/test_string.h test/test_vector.h \
	test/test_polygon.h test/test_fraction.h test/test_term.h test/test_polynomial.h \
	test/test_mainfunction.h test/test_template.h test/test_bubblesort.h \
	src/term.h src/polynomial.h src/vector_io.h src/vector.h src/gcd.h src/fraction.h \
	src/polygon.h src/template.h  src/bubblesort.h src/dot.h
	g++ -std=c++11 -c test/ut_main.cpp -o obj/ut_main.o

directories:
	mkdir -p bin obj

clean:
	rm -rf obj/*.o bin/*

stat:
	wc src/*.h src/*.cpp test/*.h test/*.cpp
