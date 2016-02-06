CXX = g++
CXXFLAGS = -Igtest_src -std=c++11 -lpthread

gtest-all.o:
	$(CXX) $(CXXFLAGS) -c gtest_src/gtest/gtest-all.cc

test: gtest-all.o
	$(CXX) $(CXXFLAGS) gtest_main.cc gtest-all.o -o run_tests

.PHONY: clean

clean:
	rm -f run_tests
