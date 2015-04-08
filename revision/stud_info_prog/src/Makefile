IDIR = ../include
CC = g++
CFLAGS= -stdlib=libstdc++ -I $(IDIR)

_DEPS= median.h print_utils.h student_info.h
DEPS= $(patsubst %.h,$(IDIR)/%.h,$(_DEPS))

ODIR=obj

_OBJ = test_student_info.o print_utils.o median.o student_info.o
OBJ= $(patsubst %.o,$(ODIR)/%.o,$(_OBJ))

$(ODIR)/%.o: %.cc $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test_student_info: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ) test_student_info

