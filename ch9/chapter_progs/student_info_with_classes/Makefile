CC=g++
CC_FLAGS= -Wall

ifeq ($(shell uname -s), Darwin)
		CC_FLAGS += -stdlib=libstdc++
endif

all: prog_student_info

prog_student_info: prog_student_info.cc median.o student_info.o grade.o
	$(CC) -o $@ $^ $(CC_FLAGS)

%.o: %.cc
	$(CC) -o $@ -c $^ $(CC_FLAGS)
