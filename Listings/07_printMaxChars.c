#include <stdio.h>
#include <string.h>

void printMaxChars(char *string) {
    size_t length = strlen(string);
    char maxChar = '\0';
    char currentChar;
    int maxOccurrence = 0;
    int currentOccurrence = 0;

    for (size_t i = 0; i < length; i++) {
        currentChar = string[i];
        currentOccurrence = 0;
        if (currentChar == maxChar)
            continue;
        for (size_t j = i; j < length; j++) {
            if (string[j] == currentChar)
                currentOccurrence++;
        }
        if (currentOccurrence > maxOccurrence) {
            maxOccurrence = currentOccurrence;
            maxChar = currentChar;
        }
    }

    printf("Zeichen %c kommt %d mal vor.\n", maxChar, maxOccurrence);
}

int main(void) {
    char string[] = "Fischers Fritze fischt frische Fische, frische Fische fischt Fischers Fritze";

    printMaxChars(string);
}
