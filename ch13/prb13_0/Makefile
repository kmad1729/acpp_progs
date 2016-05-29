CC=g++
CC_Flags= -Wall -g

OBJS= median.o grade.o student_info.o

_ALL= test_student_info $(OBJS)

all: $(_ALL)

%.o: %.cc
	$(CC) -o $@ -c $^ $(CC_Flags)

test_student_info: test_student_info.cc $(OBJS)
	$(CC) -o $@ $^ $(CC_Flags)

clean:
	rm -rf $(_ALL)



