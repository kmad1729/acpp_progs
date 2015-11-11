CC = g++
CC_Flags = -Wall

ifeq ($(shell uname -s), Darwin)
		CC_Flags += -stdlib=libstdc++
endif

_ALL = basic_ptr string_methods array_initialization

all: $(_ALL)

basic_ptr: basic_ptr.cc
	$(CC) -o $@ $^ $(CC_Flags)

string_methods: string_methods.cc
	$(CC) -o $@ $^ $(CC_Flags)

array_initialization: array_initialization.cc
	$(CC) -o $@ $^ $(CC_Flags)

clean:
	rm -rf $(_ALL)


