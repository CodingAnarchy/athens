IDIR = ../lib
CXX = g++
CXXFLAGS = -Igtest_src -I$(IDIR) -std=c++11

ODIR = ../obj
DEPS = rectangle.h

_OBJ = rectangle.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: gtest_main.cc gtest-all.o $(OBJ)
	$(CXX) $(CXXFLAGS) -lpthread $^ -o run_tests

$(ODIR)/%.o: $(IDIR)/%.cpp $(IDIR)/%.h
	$(CXX) -c -o $@ $< $(CXXFLAGS)


gtest-all.o:
	$(CXX) $(CXXFLAGS) -c gtest_src/gtest/gtest-all.cc

test: all
	./run_tests

.PHONY: clean

clean:
	rm -f *.o run_tests
