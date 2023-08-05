#include <ctype.h>
#include <dirent.h>
#include <stdio.h>

void print_file(char* filename, int reuse);
void put_file(char* filename);
void encrypt();

int main(void) {
    char menu = '0';
    char helper;
    char filename[100];
    while (menu != '-') {
        menu = getchar();
        helper = getchar();
        if (menu == '1' && helper == '\n')
            print_file(filename, 0);
        else if (menu == '2' && helper == '\n')
            put_file(filename);
        else if (menu == '3' && helper == '\n')
            encrypt();
        else if (menu == '-' && helper == '1')
            continue;
        else
            printf("n/a\n");
    }
    return 0;
}

void print_file(char* filename, int reuse) {
    FILE* fp;
    char ch;
    int len = 0;
    if (!reuse) {
        while (ch != '\n') {
            scanf("%c", &ch);
            if (ch != '\n') filename[len++] = ch;
        }
    }
    fp = fopen(filename, "r");
    char str[10000];
    if (!fp)
        printf("n/a");
    else {
        while (fgets(str, 10000, fp)) printf("%s", str);
        fclose(fp);
    }
    printf("\n");
}

void put_file(char* filename) {
    FILE* fp;
    fp = fopen(filename, "r");
    if (fp == NULL)
        printf("n/a\n");
    else {
        fp = fopen(filename, "a");
        if (!fp)
            printf("n/a\n");
        else {
            char str;
            while (str != '\n') {
                scanf("%c", &str);
                fputc(str, fp);
            }
            fclose(fp);
            print_file(filename, 1);
        }
    }
}

void encrypt() {
    // char ch;
    // int len = 0;
    // char directory[100];
    // while (ch != '\n') {
    //     scanf("%c", &ch);
    //     if (ch != '\n') directory[len++] = ch;
    // }
    DIR* d;
    struct dirent* dir;
    d = opendir("ai_modules");
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (dir->d_type == DT_REG) {
                printf("%s\n", dir->d_name);
            }
        }
        closedir(d);
    } else
        printf("n/a\n");
}