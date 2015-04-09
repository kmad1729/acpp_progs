CC = g++
CC_FLAGS = -Wall

ifeq ($(shell uname -s),Darwin)
		CC_FLAGS += -stdlib=libstdc++
endif

url_helper: url_helper.cc
	$(CC) -o $@ $^ $(CC_FLAGS)

.PHONY: clean

clean:
	rm -rf url_helper
