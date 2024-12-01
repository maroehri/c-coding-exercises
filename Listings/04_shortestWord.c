#include <stdio.h>
#include <string.h> // strlen()

int shortestWordLength(const char *s) {
    int length = (int)strlen(s);
    int minLength = length;
    int wordLength = 0;

    for (int i = 0; i < length; i++) {
        if (s[i] != ' ') {
            wordLength++;
        } else {
            if (wordLength < minLength) {
                minLength = wordLength;
            }
            wordLength = 0;
        }
    }

    if (wordLength < minLength) {
        minLength = wordLength;
    }

    return minLength;
}

int main(void) {
    char string1[] = "Ein Tag am Meer";
    printf("\"%s\"\n", string1);
    printf("Kürzestes Wort hat %d Zeichen\n", shortestWordLength(string1));

    char string2[] = "Fischers Fritze fischt frische Fische";
    printf("\"%s\"\n", string2);
    printf("Kürzestes Wort hat %d Zeichen\n\n", shortestWordLength(string2));
}
