#include <stdio.h>

int main(void) {
    int myArray[] = {4, 2, 9, 24, 4, 8, 5, 24};
    int to_find = 4;
    int arraySize = sizeof(myArray) / sizeof(int);

    // Test
    int count = 0;
    for (int i = 0; i < arraySize; i++) {
        if (myArray[i] == to_find)
            count++;
    }

    printf("Anzahl in Array: %d\n", count);
}
