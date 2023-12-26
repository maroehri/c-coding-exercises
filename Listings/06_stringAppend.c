#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *stringAppend(char *firstString, char *secondString) {
    size_t length1 = strlen(firstString);
    size_t length2 = strlen(secondString);
    size_t lengthTotal = length1 + length2 + 1;

    char *concatenatedString = malloc(lengthTotal * sizeof(char));

    for (size_t i = 0; i < length1; i++)
        concatenatedString[i] = firstString[i];

    for (size_t i = 0; i < length2; i++)
        concatenatedString[length1 + i] = secondString[i];

    concatenatedString[lengthTotal - 1] = '\0';

    return concatenatedString;
}

int main(void) {
    char first[] = "Übungsaufgaben Programmieren ";
    char second[] = "in C";

    char *newString = stringAppend(first, second);
    printf("%s\n", newString);

    free(newString);
}
