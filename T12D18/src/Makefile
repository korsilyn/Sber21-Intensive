C=gcc
CFLAGS=-Wall -Wextra -Werror
BUILD_DIR=../build

all: print_module documentation_module

print_module: main_module_entry_point.c print_module.o
	$(C) $(CFLAGS) main_module_entry_point.c print_module.o -DQ1 -o $(BUILD_DIR)/Quest_1

documentation_module: main_module_entry_point.c print_module.o documentation_module.o
	$(C) $(CFLAGS) main_module_entry_point.c print_module.o documentation_module.o -DQ2 -o $(BUILD_DIR)/Quest_2

print_module.o: print_module.c print_module.h
	$(C) $(CFLAGS) -c print_module.c

documentation_module.o: documentation_module.c documentation_module.h
	$(C) $(CFLAGS) -c documentation_module.c

rebuild: clean all

clean:
	rm -f *.o *.a *.gch *.so