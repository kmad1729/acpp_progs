CC = g++
CC_Flags = -Wall -g

ifeq ($(shell uname -s), Darwin)
		CC_Flags += -stdlib=libstdc++
endif



_ALL = general_median

all: $(_ALL)

general_median: general_median.cc
	$(CC) -o $@ $(CC_Flags) $^


clean:
	rm -rf $(_ALL)
