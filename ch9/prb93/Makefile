CC=g++
CC_Flags = -Wall -g

ifeq ($(shell uname -s), Darwin)
		CC_Flags += -stdlib=libstdc++
endif

ODIR=obj

_OBJS= grade.o median.o student_info.o
OBJ = $(patsubst %.o, $(ODIR)/%.o, $(_OBJS))

all: $(OBJ) prog_student_info_without_catching_exception 

$(ODIR)/%.o: %.cc
	@mkdir -p $(ODIR)
	$(CC) -o $@ $(CC_Flags) -c $^

prog_student_info_without_catching_exception: prog_student_info_without_catching_exception.cc
	$(CC) -o $@ $(CC_Flags) $^ $(OBJ)


clean:
	rm -rf  $(OBJ) prog_student_info_without_catching_exception $(ODIR)
