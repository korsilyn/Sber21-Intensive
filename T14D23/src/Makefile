C=gcc
CFLAGS=-Wall -Wextra -Werror
BUILD_DIR=../build

all: state_sort state_search

state_sort: state_sort.c
	$(C) $(CFLAGS) state_sort.c -o $(BUILD_DIR)/Quest_1

state_search: state_search.c
	$(C) $(CFLAGS) state_search.c -o $(BUILD_DIR)/Quest_2

rebuild: clean all

clean:
	rm -f *.o *.a *.gch *.so
