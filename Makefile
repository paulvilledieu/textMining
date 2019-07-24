CXX=g++

CPPFLAGS=-std=c++11
LDFLAGS=-g

all: src/main.o src/tries.o src/damerau_levenshtein.o
	$(CXX) -o main src/main.o src/tries.o src/damerau_levenshtein.o

SRCS=src/main.cc src/trie.cc

OBJS=$(subst .cc,.o,$(SRCS))

main: $(OBJS)
	$(CXX) $(LDFLAGS) -o main $(OBJS)

clean:
	rm -f $(OBJS)
