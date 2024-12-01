#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isVowel(char c) {
    switch (c) {
    case 'a': case 'A':
    case 'e': case 'E':
    case 'i': case 'I':
    case 'o': case 'O':
    case 'u': case 'U':
        return true;
    default:
        return false;
    }
}

char *createVowelFreeString(const char *str) {
    size_t length = strlen(str);

    // Zählen der Vokale im Eingabestring
    size_t numberOfVowels = 0;
    for (size_t i = 0; i < length; i++) {
        if (isVowel(str[i])) {
            numberOfVowels++;
        }
    }

    // Berechnen der Länge des neuen Strings (ohne Vokale)
    size_t newStringLength = length - numberOfVowels;

    // Speicherplatz für den neuen String allokieren (inklusive Nullterminator)
    char *newString = malloc(newStringLength + 1);

    if (newString == NULL) {
        fprintf(stderr, "Speicher konnte nicht allokiert werden\n");
        exit(EXIT_FAILURE);
    }

    // Vokale aus dem Eingabestring herausfiltern und den neuen String füllen
    size_t index = 0;
    for (size_t i = 0; i < length; i++) {
        if (isVowel(str[i])) {
            continue; // Überspringe Vokale
        }
        newString[index++] = str[i];
    }

    // Nullterminator hinzufügen, um den neuen String korrekt abzuschließen
    newString[newStringLength] = '\0';

    return newString;
}

int main(void) {
    char string1[] = "Ein kluger Kopf durchdenkt jedes Problem";
    printf("Original:    \"%s\"\n", string1);

    char *vowelFreeString = createVowelFreeString(string1);
    printf("Ohne Vokale: \"%s\"\n", vowelFreeString);

    free(vowelFreeString);
}
