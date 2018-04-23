.PHONY: directories clean stat

all: directories bin/ut_all bin/dot_product

bin/dot_product: src/user_main.cpp src/vector_io.h src/dot.h
	g++ -std=c++11 -o bin/dot_product src/user_main.cpp

bin/ut_all: obj/ut_main.o
	g++ -std=c++11 -o bin/ut_all obj/ut_main.o -lgtest -lpthread

obj/ut_main.o: test/ut_main.cpp test/test_dot.h test/test_string.h src/dot.h \
	src/vector_io.h src/vector.h src/gcd.h src/fraction.h test/test_fraction.h \
	test/test_vector.h test/test_polygon.h src/polygon.h
	g++ -std=c++11 -c test/ut_main.cpp -o obj/ut_main.o

directories:
	mkdir -p bin obj

clean:
	rm -f bin/* obj/*.o

stat:
	wc src/*.h test/*.h test/*.cpp
