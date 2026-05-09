#include <stdio.h>

void countNumbers(const int *data, int size, int *count) {
    // Effiziente Lösung
    for (int i = 0; i < 10; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        int value = data[i];
        if (value >= 0 && value <= 9) {
            count[value]++;
        }
    }

    // Ineffizientere Lösung
    // for (int i = 0; i < 10; i++) {
    //     int counter = 0;
    //     for (int j = 0; j < size; j++) {
    //         if (data[j] == i) {
    //             counter++;
    //         }
    //     }
    //     count[i] = counter;
    // }
}

void printHistogram(const int *count) {
    for (int i = 0; i < 10; i++) {
        printf("%d: ", i);
        for (int j = 0; j < count[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main(void) {
    int data[] = {10, 2, 2, 22, 3, 2, -3, 6, 3, 17};
    int size = sizeof(data) / sizeof(data[0]);
    int count[10];

    countNumbers(data, size, count);
    printHistogram(count);
}
