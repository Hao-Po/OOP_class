TEST = .
SRC = ./src

all: ut

ut: $(TEST)/unittest.cpp
ifeq ($(OS), Windows_NT)
	g++ $(TEST)/unittest.cpp -O3 -o $(TEST)/unittest.exe -lgtest -s
else
	g++ $(TEST)/unittest.cpp -O3 -o $(TEST)/unittest.exe -lgtest -lpthread -s
endif

clean:
ifeq ($(OS), Windows_NT)
	del $(TEST)/*.exe
else
	rm $(TEST)/*.exe
endif
