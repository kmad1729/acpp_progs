CC=g++
LIB_DIR=../../lib
LIB_NAME=acpp_utils
IDIR=../../include
SDIR=src

CCFLAGS= -Wall -I$(IDIR) 

ifeq ($(shell uname -s), Darwin)
		CCFLAGS += -stdlib=libstdc++
endif


all: word_freq xref_words_lines


ODIR=obj

_OBJ= word_freq.o xref_words_lines.o
OBJ = $(patsubst %.o,$(ODIR)/%.o,$(_OBJ))


$(ODIR)/%.o: $(SDIR)/%.cc 
	mkdir -p $(ODIR)
	$(CC) -c -o $@ $< $(CCFLAGS)

word_freq: $(ODIR)/word_freq.o
	$(CC) -o $@ $^ $(CCFLAGS)

xref_words_lines: $(ODIR)/xref_words_lines.o 
	$(CC) -o $@ $^ $(CCFLAGS)  -L$(LIB_DIR) -l$(LIB_NAME) 



.PHONY: clean

clean:
	rm -rf $(OBJ)
