CC = g++
CC_FLAGS=-Wall

ifeq ($(shell uname -s),Darwin)
	CC_FLAGS += -stdlib=libstdc++
endif

ALL = seq_write_only  template_max  template_median string_reverse seq_read_only seq_read_write reversible partial_reverse random_access inp_out_iterators split_output_iterator

all: $(ALL)



seq_write_only: seq_write_only.cc
	$(CC) -o $@ $< $(CC_FLAGS)

template_max: template_max.cc
	$(CC) -o $@ $< $(CC_FLAGS)

template_median: template_median.cc
	$(CC) -o $@ $< $(CC_FLAGS)

string_reverse: string_reverse.cc
	$(CC) -o $@ $< $(CC_FLAGS)

seq_read_only: seq_read_only.cc
	$(CC) -o $@ $< $(CC_FLAGS)

seq_read_write: seq_read_write.cc
	$(CC) -o $@ $< $(CC_FLAGS)

reversible: reversible.cc
	$(CC) -o $@ $< $(CC_FLAGS)

partial_reverse: partial_reverse.cc
	$(CC) -o $@ $< $(CC_FLAGS)

random_access: random_access.cc
	$(CC) -o $@ $< $(CC_FLAGS)

inp_out_iterators: inp_out_iterators.cc
	$(CC) -o $@ $< $(CC_FLAGS)

split_output_iterator: split_output_iterator.cc
	$(CC) -o $@ $< $(CC_FLAGS)

clean:
	rm -rf $(ALL)

