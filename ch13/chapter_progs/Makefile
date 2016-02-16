CC=g++
CC_Flags = -Wall

_ALL = test_combo_student median.o grade.o

ifeq ($(shell uname -s), Darwin)
		CC_Flags += -stdlib=libstdc++
endif

all: test_combo_student

test_combo_student: test_combo_student.cc median.o grade.o
	$(CC) $(CC_Flags) -o $@ $^

%.o: %.cc
	$(CC) -c -o $@ $(CC_Flags) $^

clean:
	rm -rf $(_ALL)
