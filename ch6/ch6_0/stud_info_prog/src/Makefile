CC=g++
I_DIR=../include
CC_Flags= -Wall -I$(I_DIR)

ifeq ($(shell uname -s),Darwin)
		$(CC_Flags) += -stdlib=libstdc++
endif



_DEPS= grades.h median.h student_info.h
DEPS=$(patsubst %.h,$(I_DIR)/%.h,$(_DEPS))

O_DIR=obj

_OBJS = grades.o median.o student_info.o student_grade_analysis.o
OBJS=$(patsubst %.o,$(O_DIR)/%.o,$(_OBJS))

$(O_DIR)/%.o: %.cc $(DEPS)
	@mkdir -p $(@D)
	$(CC) -c -o $@ $< $(CC_Flags)

student_grade_analysis: $(OBJS)
	$(CC) -o $@ $^ $(CC_Flags)


.PHONY: clean

clean:
	rm -rf $(OBJS) student_grade_analysis $(O_DIR)
