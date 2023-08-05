#include <stdio.h>

struct record {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    int status;
    int code;
};

struct date {
    int day;
    int month;
    int year;
};

struct record read_record_from_file(FILE *pfile, int index);
int get_file_size_in_bytes(FILE *pfile);
int get_records_count_in_file(FILE *pfile);

int main(void) {
    struct record data;
    struct date dt;
    char file_path[200];
    int len_fp = 0;
    char input = '\0';
    FILE *fp;
    while (input != '\n') {
        scanf("%c", &input);
        if (input != '\n') file_path[len_fp++] = input;
    }
    if ((fp = fopen(file_path, "rb")) != NULL) {
        int len = get_records_count_in_file(fp);
        if (scanf("%d.%d.%d", &dt.day, &dt.month, &dt.year) == 3) {
            int check_flag = 0;
            for (int i = 0; i < len; i++) {
                data = read_record_from_file(fp, i);
                if (data.year == dt.year && data.month == dt.month && data.day == dt.day) {
                    printf("%d", data.code);
                    check_flag = 1;
                    break;
                }
            }
            if (!check_flag) printf("n/a");
        } else
            printf("n/a");
        fclose(fp);
    } else
        printf("n/a");
    return 0;
}

// Function of reading a record of a given type from a file by its serial number.
struct record read_record_from_file(FILE *pfile, int index) {
    // Calculation of the offset at which desired entry should be located from the beginning of the file.
    int offset = index * sizeof(struct record);
    // Move the position pointer to the calculated offset from the beginning of the file.
    fseek(pfile, offset, SEEK_SET);

    // Reading a record of the specified type from a file.
    struct record data;
    fread(&data, sizeof(struct record), 1, pfile);

    // For safety reasons, we return the file position pointer to the beginning of the file.
    rewind(pfile);

    // Return read record
    return data;
}

// Function to get file size in bytes.
int get_file_size_in_bytes(FILE *pfile) {
    int size = 0;
    fseek(pfile, 0, SEEK_END);  // Move the position pointer to the end of the file.
    size = ftell(
        pfile);  // Read the number of bytes from the beginning of the file to the current position pointer.
    rewind(pfile);  // For safety reasons, move the position pointer back to the beginning of the file.
    return size;
}

// Function to get count of records in file
int get_records_count_in_file(FILE *pfile) { return get_file_size_in_bytes(pfile) / sizeof(struct record); }
