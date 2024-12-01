#include <stdio.h>
#include <stdlib.h> // strtol()
#include <string.h>

void findHighAndLow(const char *inputString, char *output) {
    // Create a copy of the input string for use with strtok
    size_t stringLength = strlen(inputString);
    char workingCopy[stringLength + 1];
    strncpy(workingCopy, inputString, stringLength);
    workingCopy[stringLength] = '\0'; // Ensure null termination

    char delimiter[] = " ";
    char *token = strtok(workingCopy, delimiter);

    if (token == NULL) {
        // Handle empty or invalid input
        strcpy(output, "No valid numbers");
        return;
    }

    long currentValue = strtol(token, NULL, 10);
    long max = currentValue;
    long min = currentValue;

    while (token != NULL) {
        currentValue = strtol(token, NULL, 10);
        if (currentValue > max) {
            max = currentValue;
        }
        if (currentValue < min) {
            min = currentValue;
        }
        token = strtok(NULL, delimiter);
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
