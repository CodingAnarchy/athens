CXX = g++
CXXFLAGS = -Igtest_src -std=c++11

gtest-all.o:
	$(CXX) $(CXXFLAGS) -c gtest_src/gtest/gtest-all.cc

all: gtest-all.o
	$(CXX) $(CXXFLAGS) -lpthread gtest_main.cc gtest-all.o -o run_tests

test: all
	./run_tests

.PHONY: clean

clean:
	rm -f *.o run_tests
