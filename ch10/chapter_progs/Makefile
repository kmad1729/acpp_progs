CC = g++
CC_Flags = -Wall

ifeq ($(shell uname -s), Darwin)
		CC_Flags += -stdlib=libstdc++
endif

_ALL = basic_ptr string_methods array_initialization static_keyword_demo say \
	my_cp my_cat pointer_to_static pointer_to_dynamic duplicate_chars

all: $(_ALL)

basic_ptr: basic_ptr.cc
	$(CC) -o $@ $^ $(CC_Flags)

string_methods: string_methods.cc
	$(CC) -o $@ $^ $(CC_Flags)

array_initialization: array_initialization.cc
	$(CC) -o $@ $^ $(CC_Flags)

static_keyword_demo: static_keyword_demo.cc
	$(CC) -o $@ $^ $(CC_Flags)

say: say.cc
	$(CC) -o $@ $^ $(CC_Flags)

my_cp: my_cp.cc
	$(CC) -o $@ $^ $(CC_Flags)

my_cat: my_cat.cc
	$(CC) -o $@ $^ $(CC_Flags)

pointer_to_static: pointer_to_static.cc
	$(CC) -o $@ $^ $(CC_Flags)

pointer_to_dynamic: pointer_to_dynamic.cc
	$(CC) -o $@ $^ $(CC_Flags)

duplicate_chars: duplicate_chars.cc
	$(CC) -o $@ $^ $(CC_Flags)

clean:
	rm -rf $(_ALL)


