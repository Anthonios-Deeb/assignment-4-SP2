CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g
ITTRA = TreeIterator.hpp InOrderIterator.hpp DFSIterator.hpp
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
all: demo test

demo: Demo.o Tree.o Node.o 
	$(CXX) $(CXXFLAGS) -o $@ $^

test: test.o Tree.o Node.o
	$(CXX) $(CXXFLAGS) -o $@ $^

Demo.o: Demo.cpp Tree.hpp Node.hpp
	$(CXX) $(CXXFLAGS) -c Demo.cpp

Tree.o: Tree.cpp Tree.hpp Node.o $(ITTRA) $(LDFLAGS)
	$(CXX) $(CXXFLAGS) -c Tree.cpp

Node.o: Node.cpp Node.hpp
	$(CXX) $(CXXFLAGS) -c Node.cpp

test.o: test.cpp Tree.hpp Node.hpp
	$(CXX) $(CXXFLAGS) -c test.cpp

.PHONY: clean all

clean:
	rm -f demo *.o test