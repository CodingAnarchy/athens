IDIR = ../lib
CXX = g++
CXXFLAGS = -std=c++14 -O3 -I$(IDIR) -I/usr/local/include
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
