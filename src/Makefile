IDIR = ../lib
CXX = g++
CXXFLAGS = -std=c++11 -I$(IDIR)
ODIR = ../obj
DEPS = rectangle.h

_OBJ = rectangle.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(IDIR)/%.cpp $(IDIR)/%.h
	$(CXX) -c -o $@ $< $(CXXFLAGS)

sim: main.cpp $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

.PHONY: clean

clean:
	rm -f sim *~
