CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

all: demo

demo: Demo.o Tree.o Node.o
	$(CXX) $(CXXFLAGS) -o $@ $^

Demo.o: Demo.cpp Tree.hpp Node.hpp
	$(CXX) $(CXXFLAGS) -c Demo.cpp

Tree.o: Tree.cpp Tree.hpp PreOrderIterator.hpp InOrderIterator.hpp PostOrderIterator.hpp
	$(CXX) $(CXXFLAGS) -c Tree.cpp

Node.o: Node.cpp Node.hpp
	$(CXX) $(CXXFLAGS) -c Node.cpp

.PHONY: clean all

clean:
	rm -f demo *.o test