CC=g++
CC_Flags= -Wall -g

ifeq ($(shell uname -s), Darwin)
		CC_Flags += -stdlib=libstdc++
endif

_ALL = test_Str rel_operator_Str_test concat_operator_Str_test \
	   getline_test_Str_cat insert_test

all: $(_ALL)

test_Str: test_Str.cc
	$(CC) -o $@ $(CC_Flags) $^

rel_operator_Str_test: rel_operator_Str_test.cc
	$(CC) -o $@ $(CC_Flags) $^

concat_operator_Str_test: concat_operator_Str_test.cc
	$(CC) -o $@ $(CC_Flags) $^

getline_test_Str_cat: getline_test_Str_cat.cc
	$(CC) -o $@ $(CC_Flags) $^

insert_test: insert_test.cc
	$(CC) -o $@ $(CC_Flags) $^

clean:
	rm -rf $(_ALL)
