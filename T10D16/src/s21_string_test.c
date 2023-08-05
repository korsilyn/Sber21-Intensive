#include "s21_string.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void s21_strlen_test(void);
void s21_strcmp_test(void);
void s21_strcpy_test(void);
void s21_strcat_test(void);
void s21_strchr_test(void);
void s21_strstr_test(void);

int main(void) {
#ifdef STRLEN
    s21_strlen_test();
#endif

#ifdef STRCMP
    s21_strcmp_test();
#endif

#ifdef STRCPY
    s21_strcpy_test();
#endif

#ifdef STRCAT
    s21_strcat_test();
#endif

#ifdef STRCHR
    s21_strchr_test();
#endif

#ifdef STRSTR
    s21_strstr_test();
#endif
}

void s21_strlen_test(void) {
    char a[] = "abcd";
    size_t len = s21_strlen(a);
    printf("\"%s\"\n%d\n%s\n", a, (int)len, len == 4 ? "SUCCESS" : "FAIL");
    char b[] = "";
    len = s21_strlen(b);
    printf("\"%s\"\n%d\n%s\n", b, (int)len, len == 0 ? "SUCCESS" : "FAIL");
    char c[] = "Verter is bullying me...";
    len = s21_strlen(c);
    printf("\"%s\"\n%d\n%s\n", c, (int)len, len == 24 ? "SUCCESS" : "FAIL");
}

void s21_strcmp_test(void) {
    char a_l[] = "abcd";
    char a_r[] = "abcd";
    int result = s21_strcmp(a_l, a_r);
    printf("\"%s\" \"%s\"\n%d\n%s\n", a_l, a_r, result, result == 0 ? "SUCCESS" : "FAIL");
    char b_l[] = "abcd";
    char b_r[] = "abad";
    result = s21_strcmp(b_l, b_r);
    printf("\"%s\" \"%s\"\n%d\n%s\n", b_l, b_r, result, result == 1 ? "SUCCESS" : "FAIL");
    char c_l[] = "abad";
    char c_r[] = "abcd";
    result = s21_strcmp(c_l, c_r);
    printf("\"%s\" \"%s\"\n%d\n%s\n", c_l, c_r, result, result == -1 ? "SUCCESS" : "FAIL");
    char d_l[] = "abcd";
    char d_r[] = "ab";
    result = s21_strcmp(d_l, d_r);
    printf("\"%s\" \"%s\"\n%d\n%s\n", d_l, d_r, result, result == 1 ? "SUCCESS" : "FAIL");
    char e_l[] = "ab";
    char e_r[] = "abcd";
    result = s21_strcmp(e_l, e_r);
    printf("\"%s\" \"%s\"\n%d\n%s\n", e_l, e_r, result, result == -1 ? "SUCCESS" : "FAIL");
    char f_l[] = "";
    char f_r[] = "";
    result = s21_strcmp(f_l, f_r);
    printf("\"%s\" \"%s\"\n%d\n%s\n", f_l, f_r, result, result == 0 ? "SUCCESS" : "FAIL");
}

void s21_strcpy_test(void) {
    char to[100];
    s21_strcpy(to, "dog");
    printf("\"%s\" \"%s\"\n%s\n", "", "dog", s21_strcmp(to, "dog") ? "FAIL" : "SUCCESS");
    s21_strcpy(to, "cat");
    printf("\"%s\" \"%s\"\n%s\n", "", "cat", s21_strcmp(to, "cat") ? "FAIL" : "SUCCESS");
    s21_strcpy(to, "");
    printf("\"%s\" \"%s\"\n%s\n", "", "", s21_strcmp(to, "") ? "FAIL" : "SUCCESS");
}

void s21_strcat_test(void) {
    char to[100] = "cat";
    s21_strcat(to, "dog");
    printf("\"%s\" \"%s\"\n\"%s\"\n%s\n", "cat", "dog", to, s21_strcmp(to, "catdog") ? "FAIL" : "SUCCESS");
    s21_strcpy(to, "abcd");
    s21_strcat(to, "ef");
    printf("\"%s\" \"%s\"\n\"%s\"\n%s\n", "abcd", "ef", to, s21_strcmp(to, "abcdef") ? "FAIL" : "SUCCESS");
    s21_strcpy(to, "Verter ");
    s21_strcat(to, "is gay");
    printf("\"%s\" \"%s\"\n\"%s\"\n%s\n", "Verter ", "is gay", to,
           s21_strcmp(to, "Verter is gay") ? "FAIL" : "SUCCESS");
}

void s21_strchr_test(void) {
    char from[] = "There are a good weather today!";
    char* result;
    int ch = 'g';
    result = s21_strchr(from, ch);
    printf("\"%s\" \'%c\'\n\"%s\"\n%s\n", from, ch, result,
           s21_strcmp(result, "good weather today!") ? "FAIL" : "SUCCESS");
    ch = 'y';
    result = s21_strchr(from, ch);
    printf("\"%s\" \'%c\'\n\"%s\"\n%s\n", from, ch, result, s21_strcmp(result, "y!") ? "FAIL" : "SUCCESS");
    ch = 'w';
    result = s21_strchr(from, ch);
    printf("\"%s\" \'%c\'\n\"%s\"\n%s\n", from, ch, result,
           s21_strcmp(result, "weather today!") ? "FAIL" : "SUCCESS");
    ch = 'h';
    result = s21_strchr(from, ch);
    printf("\"%s\" \'%c\'\n\"%s\"\n%s\n", from, ch, result,
           s21_strcmp(result, "here are a good weather today!") ? "FAIL" : "SUCCESS");
    ch = 'x';
    result = s21_strchr(from, ch);
    printf("\"%s\" \'%c\'\n\"%s\"\n%s\n", from, ch, result, result != NULL ? "FAIL" : "SUCCESS");
}

void s21_strstr_test(void) {
    char from[] = "There are a good weather today!";
    char* result;
    char str[200] = "good";
    result = s21_strstr(from, str);
    printf("\"%s\" \"%s\"\n\"%s\"\n%s\n", from, str, result,
           s21_strcmp(result, "good weather today!") ? "FAIL" : "SUCCESS");
    s21_strcpy(str, "a ");
    result = s21_strstr(from, str);
    printf("\"%s\" \"%s\"\n\"%s\"\n%s\n", from, str, result,
           s21_strcmp(result, "a good weather today!") ? "FAIL" : "SUCCESS");
    s21_strcpy(str, "today");
    result = s21_strstr(from, str);
    printf("\"%s\" \"%s\"\n\"%s\"\n%s\n", from, str, result,
           s21_strcmp(result, "today!") ? "FAIL" : "SUCCESS");
    s21_strcpy(str, "extra");
    result = s21_strstr(from, str);
    printf("\"%s\" \"%s\"\n\"%s\"\n%s\n", from, str, result, result != NULL ? "FAIL" : "SUCCESS");
}