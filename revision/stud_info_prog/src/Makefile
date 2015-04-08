IDIR = ../include
CC = g++
CCFLAGS= -I $(IDIR)

ifeq ($(shell uname -s), Darwin)
    CCFLAGS += -stdlib=libstdc++
endif

_DEPS= median.h print_utils.h student_info.h
DEPS= $(patsubst %.h,$(IDIR)/%.h,$(_DEPS))

ODIR=obj

_OBJ = test_student_info.o print_utils.o median.o student_info.o
OBJ= $(patsubst %.o,$(ODIR)/%.o,$(_OBJ))

$(ODIR)/%.o: %.cc $(DEPS)
	$(CC) -c -o $@ $< $(CCFLAGS)

test_student_info: $(OBJ)
	$(CC) -o $@ $^ $(CCFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ) test_student_info

