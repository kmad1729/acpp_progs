IDIR=../include
CC=g++
CC_FLAGS= -I$(IDIR)

ifeq ($(shell uname -s),Darwin)
		CC_FLAGS += -stdlib=libstdc++
endif

_DEPS = median.h student_info.h
DEPS= $(patsubst %.h,$(IDIR)/%.h,$(_DEPS))

ODIR=obj

_OBJ = median.o student_info.o student_grade_analysis.o
OBJ=$(patsubst %.o,$(ODIR)/%.o,$(_OBJ))

$(ODIR)/%.o : %.cc $(DEPS)
	@mkdir -p $(@D)
	$(CC) -c -o $@ $< $(CC_FLAGS)

student_grade_analysis: $(OBJ)
	$(CC) -o $@ $^ $(CC_FLAGS)

.PHONY: clean
	
clean:
	rm -f $(OBJ) student_grade_analysis

