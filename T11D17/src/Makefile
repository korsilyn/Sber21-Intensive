C=gcc
CFLAGS=-Wall -Wextra -Werror
BUILD_DIR=../build

all: door_struct

door_struct: dmanager_module.c door_struct.h
	$(C) $(CFLAGS) dmanager_module.c -o $(BUILD_DIR)/Quest_1

rebuild: clean all

clean:
	rm -f *.o *.a *.gch *.so