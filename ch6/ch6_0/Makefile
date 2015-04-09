CC = g++
CC_FLAGS = -Wall
ODIR = obj

ifeq ($(shell uname -s),Darwin)
		CC_FLAGS += -stdlib=libstdc++
endif

all: url_helper vcat_prog

url_helper: url_helper.cc
	$(CC) -o $@ $^ $(CC_FLAGS)

_OBJ = vcat_prog.o string_utils.o
OBJ= $(patsubst %.o,$(ODIR)/%.o,$(_OBJ))

DEPS= string_utils.h

$(ODIR)/%.o: %.cc $(DEPS)
	@mkdir -p $(@D)
	$(CC) -c -o $@ $< $(CC_FLAGS)
vcat_prog: $(OBJ)
	$(CC) -o $@ $^ $(CC_FLAGS)

.PHONY: clean all

clean:
	rm -rf url_helper vcat_prog $(OBJ)
