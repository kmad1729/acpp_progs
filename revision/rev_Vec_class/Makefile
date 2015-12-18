CC=g++
CC_Flags = -Wall -g

ifeq ($(shell uname -s), Darwin)
	CC_Flags += --stdlib=libstdc++
endif

_ALL= Vec_test

all: $(_ALL)

Vec_test: Vec_test.cc
	$(CC) -o $@ $^ $(CC_Flags)

clean:
	rm -rf $(_ALL)
