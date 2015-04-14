CC=g++
CC_FLAGS= -Wall -g -I.

OBJS= bad_copy.o

%.o: %.cc
	$(CC) -c -o $@ $<

bad_copy: $(OBJS)
	$(CC) -o $@ $^ $(CC_FLAGS)

.PHONY: clean

clean:
	rm -rf $(OBJS)
