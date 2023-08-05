#include "s21_string.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

size_t s21_strlen(const char* str) {
    size_t count = 0;
    while (str[count] != '\0') count++;
    return count;
}

int s21_strcmp(const char* left_str, const char* right_str) {
    size_t left_l = s21_strlen(left_str);
    size_t right_l = s21_strlen(right_str);
    size_t len;
    if (left_l <= right_l)
        len = left_l;
    else
        len = right_l;
    for (size_t i = 0; i < len; i++) {
        if (left_str[i] > right_str[i])
            return 1;
        else if (left_str[i] < right_str[i])
            return -1;
    }
    if (left_l > right_l)
        return 1;
    else if (left_l < right_l)
        return -1;
    return 0;
}

char* s21_strcpy(char* restrict destination, const char* restrict source) {
    for (size_t i = 0; i < s21_strlen(source); i++) destination[i] = source[i];
    destination[s21_strlen(source)] = '\0';
    return destination;
}

char* s21_strcat(char* restrict to, const char* restrict from) {
    size_t index = s21_strlen(to);
    size_t count = 0;
    for (; index < s21_strlen(to) + s21_strlen(from); index++) {
        to[index] = from[count];
        count++;
    }
    to[index] = '\0';
    return to;
}

char* s21_strchr(const char* search, int ch) {
    int pos = -1;
    for (size_t i = 0; i < s21_strlen(search); i++) {
        if ((int)search[i] == ch) {
            pos = i;
            break;
        }
    }
    if (pos == -1)
        return NULL;
    else
        return (char*)(search + pos);
}

char* s21_strstr(const char* main_str, const char* sub_str) {
    int pos = -1;
    size_t sub_pos = 0;
    if (s21_strlen(sub_str) > s21_strlen(main_str)) return NULL;
    for (size_t i = 0; i < s21_strlen(main_str); i++) {
        if (main_str[i] == sub_str[sub_pos])
            sub_pos++;
        else if (sub_pos != 0 && sub_pos != s21_strlen(sub_str))
            sub_pos = 0;
        else if (sub_pos == s21_strlen(sub_str)) {
            pos = i - sub_pos;
            break;
        }
    }
    if (sub_pos == 0 || pos == -1)
        return NULL;
    else
        return (char*)(main_str + pos);
}