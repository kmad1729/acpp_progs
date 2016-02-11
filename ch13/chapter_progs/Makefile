CC=g++
CC_Flags = -Wall

_ALL = test_grad_student

ifeq ($(shell uname -s), Darwin)
		CC_Flags += -stdlib=libstdc++
endif

all: $(_ALL)

test_grad_student: test_grad_student.cc
	$(CC) $(CC_Flags) -o $@ $^

clean:
	rm -rf $(_ALL)
