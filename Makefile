CXX=g++

CPPFLAGS=-std=c++11
LDFLAGS=-g

all: src/main.o src/tries.o
	$(CXX) -o main src/main.o src/tries.o

SRCS=src/main.cc src/trie.cc

OBJS=$(subst .cc,.o,$(SRCS))

main: $(OBJS)
	$(CXX) $(LDFLAGS) -o main $(OBJS)

clean:
	rm -f $(OBJS)
