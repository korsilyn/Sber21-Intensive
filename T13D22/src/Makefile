C=gcc
CFLAGS=-Wall -Wextra -Werror
BUILD_DIR=../build

all: cipher

cipher: cipher.c
	$(C) $(CFLAGS) cipher.c -o $(BUILD_DIR)/cipher

rebuild: clean all

clean:
	rm -f *.o *.a *.gch *.so