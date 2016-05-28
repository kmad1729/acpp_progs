CC=g++
CC_Flags= -Wall -g

OBJ_FILES= student_info.o grade.o median.o
_ALL=test_student_info

all: $(_ALL)

%.o: %.cc
	$(CC) -o $@ -c $^ $(CC_Flags)

test_student_info: test_student_info.cc $(OBJ_FILES)
	$(CC) -o $@ $^ $(CC_Flags)

clean:
	rm -rf $(_ALL) $(OBJ_FILES)



