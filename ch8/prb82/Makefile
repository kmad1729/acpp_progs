CC= g++
CC_Flags = -Wall

Inc_file=my_include.h

#CC_Flags += -I$(Inc_file)


ifeq ($(shell uname -s), Darwin)
		CC_Flags += -stdlib=libstdc++
endif


_ALL=a_my_equal b_my_find c_my_copy d_remove_copy_if e_my_transform f_my_accumulate g_my_search i_remove_copy j_my_remove k_partition


all: $(_ALL)


a_my_equal: a_my_equal.cc
	$(CC) -o $@ $^ $(CC_Flags)

b_my_find: b_my_find.cc
	$(CC) -o $@ $^ $(CC_Flags)

c_my_copy: c_my_copy.cc
	$(CC) -o $@ $^ $(CC_Flags) 

d_remove_copy_if: d_remove_copy_if.cc
	$(CC) -o $@ $^ $(CC_Flags) 

e_my_transform: e_my_transform.cc
	$(CC) -o $@ $^ $(CC_Flags)

f_my_accumulate: f_my_accumulate.cc
	$(CC) -o $@ $^ $(CC_Flags)

g_my_search: g_my_search.cc
	$(CC) -o $@ $^ $(CC_Flags)

i_remove_copy: i_remove_copy.cc
	$(CC) -o $@ $^ $(CC_Flags)

j_my_remove: j_my_remove.cc
	$(CC) -o $@ $^ $(CC_Flags) 

k_partition: k_partition.cc
	$(CC) -o $@ $^ $(CC_Flags) 




clean:
	rm -rf $(_ALL)




