CC=g++
IDIR=.
CC_Flags= -Wall -I$(IDIR)

DEPS=super_include.h

OBJ= cat_str_vec.o

%.o: %.cc $(DEPS)
	$(CC) -c -o $@ $< $(CC_Flags)

cat_str_vec: $(OBJ)
	$(CC) -o $@ $^ $(CC_Flags)

.PHONY: clean

clean:
	rm -rf $(OBJ) cat_str_vec
