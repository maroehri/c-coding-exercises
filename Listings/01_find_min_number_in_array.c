#include <stdio.h>

int findMin(int array[], int size) {
    int min = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

int main(void) {
    int myArray[] = {4, 2, 9, 24, 4, 8, 5, 24};
    int arraySize = (int)sizeof(myArray) / sizeof(int);

    int min = findMin(myArray, arraySize);

    printf("Kleinstes Element: %d\n", min);
}
