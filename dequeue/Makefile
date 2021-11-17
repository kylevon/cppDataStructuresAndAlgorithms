#
# example Makefile to build an executable named myprog from myprog.cpp
#
PROG=deque
COMPILER=/usr/local/Cellar/gcc/11.2.0_1/bin/g++-11

all: src/$(PROG)/*.cpp
	$(COMPILER) -std=c++11 -Wall -fgnu-tm src/$(PROG)/*.cpp -o $(PROG)

clean:
	$(RM) $(PROG)
