CC=g++
CC_FLAGS = -Wall

ifeq ($(shell uname -s), Darwin)
		CC_FLAGS += -stdlib=libstdc++
endif

_ALL=permute_using_iterator
all: $(_ALL)

permute_using_iterator: permute_using_iterator.cc
	$(CC) -o $@ $< $(CC_FLAGS)


clean:
	rm -rf $(_ALL)
