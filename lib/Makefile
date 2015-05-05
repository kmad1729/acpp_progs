CC=g++
CC_FLAGS=-Wall

ifeq ($(shell uname -s), Darwin)
		CC_FLAGS += -stdlib=libstdc++
endif

OUT=libacpp_utils.a
LIB_NAME=acpp_utils
ODIR=obj
SDIR=src
TDIR=utils_tests
IDIR=../include
LDIR=.

_OBJS= string_utils.o vector_utils.o
OBJS=$(patsubst %.o,$(ODIR)/%.o,$(_OBJS))

$(ODIR)/%.o: $(SDIR)/%.cc
	@mkdir -p $(ODIR)
	$(CC) -c -o $@ $^ $(CC_FLAGS)

TEST_FILES = $(TDIR)/test_vec_utils.cc

$(OUT): $(OBJS)
	ar rvs $@ $^

tests: $(OUT)
	$(CC) -o $@ $(TEST_FILES) $(CC_FLAGS) -I$(IDIR) -l$(LIB_NAME) -L$(LDIR)





.PHONY: clean
	
clean:
	rm -rf $(OBJS) $(OUT) tests
