CC=g++
CC_Flags= -Wall -g

ifeq ($(shell uname -s), Darwin)
		CC_Flags += --stdlib=libstdc++
endif

_ALL=test_Vec

all: $(_ALL)

test_Vec: test_Vec.cc
	$(CC) -o $@ $^ $(CC_Flags)

clean:
	rm -rf $(_ALL)
