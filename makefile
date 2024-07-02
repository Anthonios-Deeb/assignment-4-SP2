# Email: anthoniosdb@gmail.com
# 3993

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Source and header files
SRCS = main.cpp Complex.cpp
HEADERS = Tree.hpp Node.hpp Complex.hpp
TEST_SRCS = test.cpp

# Executable names
RUN = tree
TEST = test

# Default target: build all executables
all: $(RUN) $(TEST) 

# Build and run the main tree executable
tree: main.o Complex.o
	$(CXX) $(CXXFLAGS) -o $(RUN) $^ $(LDFLAGS)
	./$(RUN)

# Build and run the test executable
test: test.o Complex.o
	$(CXX) $(CXXFLAGS) -o $(TEST) $^ $(LDFLAGS)
	./$(TEST)

# Compile object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $<

# Phony targets
.PHONY: clean all test tree

# Clean up build artifacts
clean:
	rm -f $(RUN) $(TEST) *.o
