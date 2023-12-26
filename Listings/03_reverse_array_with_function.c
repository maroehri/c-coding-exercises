#include <stdio.h>

void reverse(int array[], int size) {
    int temp = 0;

    for (int i = 0; i < (size / 2); i++) {
        temp = array[i];
        array[i] = array[size - i - 1];
        array[size - i - 1] = temp;
    }
}

int main(void) {
    int myArray[] = {4, 2, 9, 24, 4, 8, 5, 24};
    int arraySize = sizeof(myArray) / sizeof(int);

    reverse(myArray, arraySize);

    printf("Umgekehrte Reihenfolge:\n");
    for (int i = 0; i < arraySize; i++) {
        printf("myArray[%d] = %d\n", i, myArray[i]);
    }
}
