#ifndef S21_STRING_H
#define S21_STRING_H

#include <stddef.h>

size_t s21_strlen(const char* str);
int s21_strcmp(const char* left_str, const char* right_str);
char* s21_strcpy(char* restrict destination, const char* restrict source);
char* s21_strcat(char* restrict to, const char* restrict from);
char* s21_strchr(const char* search, int ch);
char* s21_strstr(const char* main_str, const char* sub_str);

#endif