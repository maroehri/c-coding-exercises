#include <stdio.h>
#include <string.h>

char findMaxChar(const char *string, int *occurrence) {
    size_t length = strlen(string);
    char maxChar = '\0';
    int maxOccurrence = 0;

    for (size_t i = 0; i < length; i++) {
        char currentChar = string[i];
        if (currentChar == maxChar) {
            continue;
        }

        int currentOccurrence = 0;
        for (size_t j = i; j < length; j++) {
            if (string[j] == currentChar) {
                currentOccurrence++;
            }
        }

        if (currentOccurrence > maxOccurrence) {
            maxOccurrence = currentOccurrence;
            maxChar = currentChar;
        }
    }

    *occurrence = maxOccurrence;
    return maxChar;
}

int main(void) {
    char string[] = "Fischers Fritze fischt frische Fische, "
                    "frische Fische fischt Fischers Fritze";

    int occurrence;
    char maxChar = findMaxChar(string, &occurrence);
    printf("Zeichen %c kommt %d mal vor.\n", maxChar, occurrence);
    return 0;
}
