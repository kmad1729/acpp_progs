CC=g++
CC_FLAGS = -Wall

ifeq ($(shell uname -s), Darwin)
		CC_FLAGS += -stdlib=libstdc++
endif

_ALL=permute_using_iterator c_in_cpp c_rev_str c_int_char_cast c_transform_space
all: $(_ALL)

permute_using_iterator: permute_using_iterator.cc
	$(CC) -o $@ $< $(CC_FLAGS)

c_in_cpp: c_in_cpp.cc
	$(CC) -o $@ $< $(CC_FLAGS)

c_rev_str: c_rev_str.cc
	$(CC) -o $@ $< $(CC_FLAGS)

c_int_char_cast: c_int_char_cast.cc
	$(CC) -o $@ $< $(CC_FLAGS)

c_transform_space: c_transform_space.cc
	$(CC) -o $@ $< $(CC_FLAGS)

clean:
	rm -rf $(_ALL)
