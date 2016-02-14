IDIR = ../lib
CXX = g++-5  # Use GNU compiler installed directly instead of clang to allow OMP to be used
CXXFLAGS = -std=c++14 -msse4 -O3 -I$(IDIR) -I/usr/local/include
LDFLAGS = -fopenmp
ODIR = ../obj

STRUCTURE := $(shell find $(IDIR) -type d)
CODEFILES := $(addsuffix /*,$(STRUCTURE))
CODEFILES := $(wildcard $(CODEFILES))

SRCFILES := $(filter %.cpp,$(CODEFILES))
HDRFILES := $(filter %.hpp,$(CODEFILES))
OBJFILES := $(subst $(IDIR),$(ODIR),$(SRCFILES:%.cpp=%.o))

$(ODIR)/%.o: $(addprefix $(IDIR)/,%.cpp %.hpp)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

sim: main.cpp $(OBJFILES)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^

.PHONY: clean

clean:
	rm -f sim *~
	rm -r $(ODIR)/*
