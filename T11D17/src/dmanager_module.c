#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door* doors);
void sort_doors(struct door* doors);
void close_doors(struct door* doors);
void output_doors(struct door* doors);
void swap(int* a, int* b);

int main(void) {
    struct door doors[DOORS_COUNT];

    initialize_doors(doors);
    sort_doors(doors);
    close_doors(doors);
    output_doors(doors);

    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door* doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void close_doors(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT; i++) doors[i].status = 0;
}

void sort_doors(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT - 1; i++)
        for (int j = 0; j < DOORS_COUNT - i - 1; j++)
            if (doors[j].id > doors[j + 1].id) {
                swap(&doors[j].id, &doors[j + 1].id);
                swap(&doors[j].status, &doors[j + 1].status);
            }
}

void output_doors(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        printf("%d, %d", doors[i].id, doors[i].status);
        if (i + 1 != DOORS_COUNT) printf("\n");
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
