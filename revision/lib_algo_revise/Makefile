CC=g++
CC_Flags= -Wall -g

ifeq ($(shell uname -s), Darwin)
	CC_Flags += -stdlib=libstdc++
endif

_ALL= my_reverse

all: $(_ALL)

my_reverse: my_reverse.cc
	$(CC) -o $@ $^ $(CC_Flags)


clean:
	rm -rf $(_ALL)


