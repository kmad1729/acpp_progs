CC= g++
CC_Flags = -Wall -g

ifeq ($(shell uname -s), Darwin)
		CC_Flags += --stdlib=libstdc++
endif

_ALL= test_Str

all: $(_ALL)


test_Str: test_Str.cc
	$(CC) $(CC_Flags) -o $@ $^


clean:
	rm -rf $(_ALL)
