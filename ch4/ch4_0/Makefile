CC=g++
IDIR=include
ODIR=obj
SDIR=src
CC_Flags = -Wall -I$(IDIR)

ifeq ($(shell uname -s), Darwin)
		CC_Flags += -stdlib=libstdc++
endif


student_info_prog: $(ODIR)/student_info.o $(ODIR)/grade.o $(ODIR)/median.o $(ODIR)/student_info_prog.o
	$(CC) -o $@ $^ $(CC_Flags)

$(ODIR)/%.o: $(SDIR)/%.cc
	mkdir -p $(ODIR)
	$(CC) -c -o $@ $< $(CC_Flags)

clean:
	rm -rf $(ODIR) student_info_prog

