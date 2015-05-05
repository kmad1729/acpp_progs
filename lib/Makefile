CC=g++
CC_FLAGS=-Wall

ifeq ($(shell uname -s), Darwin)
		CC_FLAGS += -stdlib=libstdc++
endif

OUT=libacpp_utils.a
ODIR=obj
SDIR=src

_OBJS= string_utils.o
OBJS=$(patsubst %.o,$(ODIR)/%.o,$(_OBJS))

$(ODIR)/%.o: $(SDIR)/%.cc
	@mkdir -p $(ODIR)
	$(CC) -c -o $@ $^ $(CC_FLAGS)



$(OUT): $(OBJS)
	ar rvs $@ $^


.PHONY: clean
	
clean:
	rm -rf $(OBJS) $(OUT)
