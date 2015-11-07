CC = g++
CC_Flags = -Wall

ifeq ($(shell uname -s), Darwin)
		CC_Flags += -stdlib=libstdc++
endif

_ALL = basic_ptr

all: $(_ALL)

basic_ptr: basic_ptr.cc
	$(CC) -o $@ $^ $(CC_Flags)

clean:
	rm -rf $(_ALL)


