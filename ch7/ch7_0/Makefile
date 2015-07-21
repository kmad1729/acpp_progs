CC=g++
IDIR=../../include
ODIR=obj
SDIR=src
LIB=acpp_utils
LDIR=../../lib

CC_FLAGS= -Wall -I$(IDIR)


ifeq ($(shell uname -s), Darwin)
		CC_FLAGS += -stdlib=libstdc++
endif

all: word_freq xref_words_lines gen_sentences

$(ODIR)/%.o: $(SDIR)/%.cc
	mkdir -p $(ODIR)
	$(CC) -c -o $@ $< $(CC_FLAGS)

word_freq: $(ODIR)/word_freq.o
	$(CC) -o $@ $^ $(CC_FLAGS)

xref_words_lines: $(ODIR)/xref_words_lines.o
	$(CC) -o $@ $^ $(CC_FLAGS) -L$(LDIR) -l$(LIB)

gen_sentences: $(ODIR)/gen_sentences.o
	$(CC) -o $@ $^ $(CC_FLAGS) -L$(LDIR) -l$(LIB)

.PHONY: clean

clean:
	rm -rf $(ODIR) word_freq xref_words_lines gen_sentences
