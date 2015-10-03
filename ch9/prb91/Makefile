CC=g++
CC_Flags= -Wall -g

ifeq ($(shell uname -s), Darwin)
		CC_Flags += -stdlib=libstdc++
endif

ODIR=obj
_OBJS=$(ODIR)/median.o $(ODIR)/student_info.o $(ODIR)/grade.o

_ALL=prog_student_info $(_OBJS)

all: prog_student_info

prog_student_info: prog_student_info.cc $(_OBJS)
	$(CC) -o $@ $^ $(CC_Flags)

$(ODIR)/%.o: %.cc
	@mkdir -p $(ODIR)
	$(CC) -o $@ -c $^ $(CC_Flags)

clean:
	rm -rf $(_ALL) $(ODIR)
