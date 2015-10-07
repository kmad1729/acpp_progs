CC=g++
CC_Flags= -Wall -g

ifeq ($(shell uname -s), Darwin)
		CC_Flags += -stdlib=libstdc++
endif

_ALL= my_swap incorrect_swap_function call_by_ref_example
all: $(_ALL)

my_swap: my_swap.cc
	$(CC) -o $@ $^ $(CC_Flags)

incorrect_swap_function: incorrect_swap_function.cc
	$(CC) -o $@ $^ $(CC_Flags)

call_by_ref_example: call_by_ref_example.cc
	$(CC) -o $@ $^ $(CC_Flags)

clean:
	rm -rf $(_ALL)

