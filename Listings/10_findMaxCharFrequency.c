#include <stdio.h>
#include <string.h>

char findMaxChar(const char *string, int *occurrence) {
    int frequency[256] = {0};
    size_t length = strlen(string);

    // Haeufigkeiten zaehlen
    for (size_t i = 0; i < length; i++) {
        int index = string[i];
        frequency[index]++;
    }

    // Index mit hoechster Haeufigkeit suchen
    int maxIndex = 0;
    for (int i = 1; i < 256; i++) {
        if (frequency[i] > frequency[maxIndex]) {
            maxIndex = i;
        }
    }

    *occurrence = frequency[maxIndex];
    return (char)maxIndex;
}

int main(void) {
    char string[] = "Fischers Fritze fischt frische Fische, "
                    "frische Fische fischt Fischers Fritze";

    int occurrence;
    char maxChar = findMaxChar(string, &occurrence);
    printf("Zeichen %c kommt %d mal vor.\n", maxChar, occurrence);
    return 0;
}
