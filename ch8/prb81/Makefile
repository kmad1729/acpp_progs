CC=g++
CC_Flags = -Wall



ifeq ($(shell uname -s), Darwin)
		CC_Flags += -stdlib=libstdc++
endif



student_prog: student_prog.cc median.o grade.o student_info.o
	$(CC) -o $@ $^ $(CC_Flags)


median.o: median.cc
	$(CC) -c -o $@ $< $(CC_Flags)

grade.o: grade.cc
	$(CC) -c -o $@ $< $(CC_Flags)


student_info.o: student_info.cc
	$(CC) -c -o $@ $< $(CC_Flags)


clean:
	rm -rf *.o student_prog
