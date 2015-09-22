CC= g++
CC_Flags = -Wall


ifeq ($(shell uname -s), Darwin)
		CC_Flags += -stdlib=libstdc++
endif


all: my_accumulate

my_accumulate: my_accumulate.cc
	$(CC) -o $@ $^ $(CC_Flags)

