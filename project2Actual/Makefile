CXXFLAGS=-I -std=c++11 -Wall -pedantic -ggdb

BIN=project2Actual

all: $(OBJ)

	$(CXX) -o $(BIN) $(wildcard *.cpp)

clean:
	rm -f $(wildcard *.o)
	rm $(BIN)