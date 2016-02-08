IDIR = ../lib
CXX = g++
CXXFLAGS = -std=c++14 -O3 -I$(IDIR) -I/usr/local/include -Igtest_src
ODIR = ../obj

STRUCTURE := $(shell find $(IDIR) -type d)
CODEFILES := $(addsuffix /*,$(STRUCTURE))
CODEFILES := $(wildcard $(CODEFILES))

SRCFILES := $(filter %.cpp,$(CODEFILES))
HDRFILES := $(filter %.hpp,$(CODEFILES))
OBJFILES := $(subst $(IDIR),$(ODIR),$(SRCFILES:%.cpp=%.o))

$(ODIR)/%.o: $(addprefix $(IDIR)/,%.cpp %.h)
	$(CXX) -c -o $@ $< $(CXXFLAGS)


all: gtest_main.cc gtest-all.o $(OBJFILES)
	$(CXX) $(CXXFLAGS) -lpthread $^ -o run_tests

$(ODIR)/%.o: $(IDIR)/%.cpp $(IDIR)/%.hpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

gtest-all.o:
	$(CXX) $(CXXFLAGS) -c gtest_src/gtest/gtest-all.cc

test: all
	./run_tests

.PHONY: clean

clean:
	rm -f *.o run_tests
