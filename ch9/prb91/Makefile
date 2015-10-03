CC=g++
CC_Flags= -Wall -g

ifeq ($(shell uname -s), Darwin)
		CC_Flags += -stdlib=libstdc++
endif

_ALL=prog_student_info median.o student_info.o grade.o

all: prog_student_info

prog_student_info: prog_student_info.cc median.o student_info.o grade.o
	$(CC) -o $@ $^ $(CC_Flags)

%.o: %.cc
	$(CC) -o $@ -c $^ $(CC_Flags)

clean:
	rm -rf $(_ALL)
