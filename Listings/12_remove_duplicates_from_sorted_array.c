#include <stdio.h>
#include <stdlib.h>

void removeDuplicates(int **array, int *size) {
    if (*size < 2) {
        return;
    }

    int newSize = 1;
    for (int i = 1; i < *size; i++) {
        if ((*array)[i] != (*array)[newSize - 1]) {
            (*array)[newSize] = (*array)[i];
            newSize++;
        }
    }

    int *tempArray = realloc(*array, (size_t)newSize * sizeof(int));
    if (tempArray != NULL) {
        *array = tempArray; // Nur aktualisieren, wenn realloc erfolgreich war
        *size = newSize;
    }
}

int main(void) {
    int size = 10;
    int *myArray = malloc((size_t)size * sizeof(int));

    if (myArray == NULL) {
        printf("Speicher konnte nicht reserviert werden.\n");
        return 1;
    }

    // Hilfsarray, um myArray zu initialisieren
    int initArray[] = {1, 2, 3, 3, 4, 5, 5, 5, 6, 7};
    for (int i = 0; i < size; i++) {
        myArray[i] = initArray[i];
    }

    // Ausgabe der Array-Elemente vor der Bearbeitung
    printf("Array vor der Bearbeitung:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", myArray[i]);
    }
    printf("\n");

    removeDuplicates(&myArray, &size);

    // Ausgabe der Array-Elemente nach der Bearbeitung
    printf("Array nach der Bearbeitung:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", myArray[i]);
    }
    printf("\n");

    free(myArray);
    return 0;
}
