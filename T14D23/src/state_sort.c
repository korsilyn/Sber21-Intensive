#include <ctype.h>
#include <stdio.h>
#include <time.h>

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

struct record read_record_from_file(FILE *pfile, int index);
int get_file_size_in_bytes(FILE *pfile);
int get_records_count_in_file(FILE *pfile);
void swap_records_in_file(FILE *pfile, int record_index1, int record_index2);
void write_record_in_file(FILE *pfile, const struct record *record_to_write, int index);
void quick_sort(FILE *fp, int low, int high);
int split(FILE *fp, int low, int high);

int main(void) {
    struct record data;
    char file_path[200];
    int len_fp = 0;
    char input_helper = '\0';
    char menu;
    while (input_helper != '\n') {
        scanf("%c", &input_helper);
        if (input_helper != '\n') file_path[len_fp++] = input_helper;
    }
    if (scanf("%c", &menu) && isdigit(menu)) {
        FILE *fp;
        if (menu == '0') {
            if ((fp = fopen(file_path, "rb")) != NULL) {
                int len = get_records_count_in_file(fp);
                for (int i = 0; i < len; i++) {
                    data = read_record_from_file(fp, i);
                    printf("%d %d %d %d %d %d %d %d\n", data.year, data.month, data.day, data.hour,
                           data.minute, data.second, data.status, data.code);
                }
                fclose(fp);
            } else
                printf("n/a");
        } else if (menu == '1') {
            if ((fp = fopen(file_path, "rb+")) != NULL) {
                int len = get_records_count_in_file(fp);
                // sort(fp, len);
                quick_sort(fp, 0, len - 1);
                for (int i = 0; i < len; i++) {
                    data = read_record_from_file(fp, i);
                    printf("%d %d %d %d %d %d %d %d\n", data.year, data.month, data.day, data.hour,
                           data.minute, data.second, data.status, data.code);
                }
                fclose(fp);
            } else
                printf("n/a");
        } else if (menu == '2') {
            if ((fp = fopen(file_path, "rb+")) != NULL) {
                int len = get_records_count_in_file(fp);
                struct record input;
                if (scanf("%d %d %d %d %d %d %d %d", &input.year, &input.month, &input.day, &input.hour,
                          &input.minute, &input.second, &input.status, &input.code) == 8) {
                    write_record_in_file(fp, &input, len);
                    quick_sort(fp, 0, len);
                    for (int i = 0; i < len + 1; i++) {
                        data = read_record_from_file(fp, i);
                        printf("%d %d %d %d %d %d %d %d\n", data.year, data.month, data.day, data.hour,
                               data.minute, data.second, data.status, data.code);
                    }
                } else
                    printf("n/a");
                fclose(fp);
            } else
                printf("n/a");
        } else
            printf("n/a");
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

int split(FILE *fp, int low, int high) {
    struct record data_high = read_record_from_file(fp, high);
    struct tm time;
    time.tm_year = data_high.year;
    time.tm_mon = data_high.month;
    time.tm_mday = data_high.day;
    time.tm_hour = data_high.hour;
    time.tm_min = data_high.minute;
    time.tm_sec = data_high.second;
    time_t pivot = mktime(&time);

    int i = (low - 1);

    for (int j = low; j < high; j++) {
        struct record data_low = read_record_from_file(fp, j);
        time.tm_year = data_low.year;
        time.tm_mon = data_low.month;
        time.tm_mday = data_low.day;
        time.tm_hour = data_low.hour;
        time.tm_min = data_low.minute;
        time.tm_sec = data_low.second;
        if (mktime(&time) <= pivot) {
            i++;
            swap_records_in_file(fp, i, j);
        }
    }

    swap_records_in_file(fp, i + 1, high);
    return (i + 1);
}

void quick_sort(FILE *fp, int low, int high) {
    if (low < high) {
        int pivot = split(fp, low, high);

        quick_sort(fp, low, pivot - 1);
        quick_sort(fp, pivot + 1, high);
    }
}

// Function of mutual transfer of two records in the file by their indexes.
void swap_records_in_file(FILE *pfile, int record_index1, int record_index2) {
    // Read both records from file to variables
    struct record record1 = read_record_from_file(pfile, record_index1);
    struct record record2 = read_record_from_file(pfile, record_index2);

    // Rewrite records in file
    write_record_in_file(pfile, &record1, record_index2);
    write_record_in_file(pfile, &record2, record_index1);
}

// Function of writing a record of the specified type to the file at the specified serial number.
void write_record_in_file(FILE *pfile, const struct record *record_to_write, int index) {
    // Calculation of the offset at which the required record should be located from the beginning of the
    // file.
    int offset = index * sizeof(struct record);
    // Move the position pointer to the calculated offset from the beginning of the file.
    fseek(pfile, offset, SEEK_SET);

    // Write a record of the specified type to a file.
    fwrite(record_to_write, sizeof(struct record), 1, pfile);

    // Just in case, force the I/O subsystem to write the contents of its buffer to a file right now.
    fflush(pfile);

    // For safety reasons, return the file position pointer to the beginning of the file.
    rewind(pfile);
}