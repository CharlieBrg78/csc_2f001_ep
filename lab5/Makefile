

.SUFFIXES:         # remove all implicit rules (avoid conflicts with our own rules)
.SECONDARY:        # keep intermediates (object files)
.PHONY: all clean  # these targets are not real files

LDFLAGS  =
LIBS     =
CXX      = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Werror -g


BINS = lisp
SRC    = main.cpp node.cpp integer.cpp list.cpp keyword.cpp symbol.cpp
OBJ    = $(SRC:.cpp=.o)

all: $(BINS)

$(BINS): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $^ $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(BINS) *.o *~