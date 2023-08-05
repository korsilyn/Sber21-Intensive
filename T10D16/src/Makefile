C=gcc
CFLAGS=-Wall -Wextra -Werror
BUILD_DIR=../build

all: strlen_tests strcmp_tests strcpy_tests strcat_tests strchr_tests strstr_tests

s21_string.o: s21_string.c s21_string.h
	$(C) $(CFLAGS) -c s21_string.c

strlen_tests: s21_string.o
	$(C) $(CFLAGS) s21_string_test.c s21_string.o -DSTRLEN -o $(BUILD_DIR)/Quest_1

strcmp_tests: s21_string.o
	$(C) $(CFLAGS) s21_string_test.c s21_string.o -DSTRCMP -o $(BUILD_DIR)/Quest_2

strcpy_tests: s21_string.o
	$(C) $(CFLAGS) s21_string_test.c s21_string.o -DSTRCPY -o $(BUILD_DIR)/Quest_3

strcat_tests: s21_string.o
	$(C) $(CFLAGS) s21_string_test.c s21_string.o -DSTRCAT -o $(BUILD_DIR)/Quest_4

strchr_tests: s21_string.o
	$(C) $(CFLAGS) s21_string_test.c s21_string.o -DSTRCHR -o $(BUILD_DIR)/Quest_5

strstr_tests: s21_string.o
	$(C) $(CFLAGS) s21_string_test.c s21_string.o -DSTRSTR -o $(BUILD_DIR)/Quest_6

rebuild: clean all

clean:
	rm -f *.o *.a *.gch *.so