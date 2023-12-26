#include <stdio.h>

int main(void) {
    int myArray[] = {4, 2, 9, 24, 4, 8};
    int arraySize = sizeof(myArray) / sizeof(int);
    int temp = 0;

    for (int i = 0; i < (arraySize / 2); i++) {
        temp = myArray[i];
        myArray[i] = myArray[arraySize - i - 1];
        myArray[arraySize - i - 1] = temp;
    }

    printf("Umgekehrte Reihenfolge:\n");
    for (int i = 0; i < arraySize; i++) {
        printf("myArray[%d] = %d\n", i, myArray[i]);
    }
}
