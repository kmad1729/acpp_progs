CC=g++
CC_Flags= -Wall

ifeq ($(shell uname -s), Darwin)
		CC_Flags += -stdlib=libstdc++
endif

ODIR=obj
SDIR=.

all: sorted_word_counter

$(ODIR)/%.o: $(SDIR)/%.cc
	mkdir -p $(ODIR)
	$(CC) -c -o $@ $< $(CC_Flags)

sorted_word_counter: $(ODIR)/sorted_word_counter.o
	$(CC) -o $@ $^ $(CC_Flags)

clean:
	rm -rf sorted_word_counter $(ODIR)/*.o
