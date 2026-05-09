#include <stdio.h>
#include <stdlib.h> // strtol()
#include <string.h>

void findHighAndLow(const char *inputString, char *output) {
    long currentValue;
    char *parsePtr = (char *)inputString;

    // Parse the first number
    currentValue = strtol(parsePtr, &parsePtr, 10);
    long max = currentValue;
    long min = currentValue;

    // Parse the remaining numbers
    while (*parsePtr) {
        currentValue = strtol(parsePtr, &parsePtr, 10);
        if (currentValue > max) {
            max = currentValue;
        }
        if (currentValue < min) {
            min = currentValue;
        }
    }

    // Format the result
    sprintf(output, "%ld %ld", max, min);
}

int main(void) {
    char output[32];
    char testString[] = "15 -3 22 0 -45 67 89 -12 34 23 -56 78";
    printf("Eingabestring:  %s\n", testString);
    findHighAndLow(testString, output);
    printf("Ergebnisstring: %s\n", output);
}
