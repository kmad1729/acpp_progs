CC = g++
CC_Flags = -Wall -g

ifeq ($(shell uname -s), Darwin)
		CC_Flags += -stdlib=libstdc++
endif

_ALL= test_btree new_btree

all: $(_ALL)

test_btree: test_btree.cc
	$(CC) $(CC_Flags) -o $@ $^

new_btree: new_btree.cc
	$(CC) $(CC_Flags) -o $@ $^

clean:
	rm -rf $(_ALL)
