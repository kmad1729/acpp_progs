CC=g++
CC_FLAGS = -Wall -g -std=c++11

ifeq ($(shell uname -s), Darwin)
		CC_FLAGS += -stdlib=libstdc++
endif

_ALL=permute_using_iterator c_in_cpp c_rev_str c_int_char_cast \
		c_transform_space remove_ex gen_permute \
		merge_vec_of_vectors meeting_assign b_tree_reconstruction \
		atoi_impl rotated_arr_search

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

remove_ex: remove_ex.cc
	$(CC) -o $@ $< $(CC_FLAGS)

gen_permute: gen_permute.cc
	$(CC) -o $@ $< $(CC_FLAGS)

foo: foo.cc
	$(CC) -o $@ $< $(CC_FLAGS)

merge_vec_of_vectors: merge_vec_of_vectors.cc
	$(CC) -o $@ $< $(CC_FLAGS)

meeting_assign: meeting_assign.cc
	$(CC) -o $@ $< $(CC_FLAGS)

b_tree_reconstruction: b_tree_reconstruction.cc
	$(CC) -o $@ $< $(CC_FLAGS)

atoi_impl: atoi_impl.cc
	$(CC) -o $@ $< $(CC_FLAGS)

rotated_arr_search: rotated_arr_search.cc
	$(CC) -o $@ $< $(CC_FLAGS)

clean:
	rm -rf $(_ALL)
