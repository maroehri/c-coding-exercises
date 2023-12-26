#include <stdio.h>

int occurrences(int array[], int size, int to_find)
{
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (array[i] == to_find)
            count++;
    }
    return count;
}

int main(void)
{
    int myArray[] = {4, 2, 9, 24, 4, 8, 5, 24};
    int to_find = 4;
    int arraySize = sizeof(myArray) / sizeof(int);

    int count = occurrences(myArray, arraySize, to_find);

    printf("Anzahl in Array: %d\n", count);
}
