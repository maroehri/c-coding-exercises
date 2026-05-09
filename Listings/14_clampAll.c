#include <stdio.h>
#include <stdlib.h>

int clampAll(const int source[], const int n, const int max, int **target) {
    int *result = malloc(n * sizeof(int));
    if (result == NULL) {
        return -1;
    }

    for (int i = 0; i < n; i++) {
        if (source[i] > max) {
            result[i] = max;
        } else {
            result[i] = source[i];
        }
    }

    *target = result;
    return 0;
}

int main(void) {
    int source[] = {3, 12, 7, 20, 5};
    int n = sizeof(source) / sizeof(source[0]);
    int max = 10;
    int *result;

    if (clampAll(source, n, max, &result) != 0) {
        printf("Allokation fehlgeschlagen\n");
        return 1;
    }

    printf("Eingabe:   ");
    for (int i = 0; i < n; i++)
        printf("%d ", source[i]);
    printf("\nErgebnis:  ");
    for (int i = 0; i < n; i++)
        printf("%d ", result[i]);
    printf("\n");

    free(result);
}
