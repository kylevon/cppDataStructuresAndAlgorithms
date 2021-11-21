#
# example Makefile to build an executable named myprog from myprog.cpp
#
PROG=deque
COMPILER=g++

all: src/$(PROG)/*.cpp
	$(COMPILER) -std=c++11 -Wall src/$(PROG)/*.cpp -o $(PROG)

clean:
	$(RM) $(PROG)
