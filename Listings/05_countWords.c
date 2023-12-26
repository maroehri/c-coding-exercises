#include <stdio.h>
#include <string.h> // für strlen()
#include <ctype.h>  // für tolower() und isalpha()
#include <stdbool.h>

int countWords(char string[], char word[]) {
    int lenWord = (int)strlen(word);
    int count = 0;
    int i = 0;

    while (string[i + 1] != '\0') {
        bool validWord = true;

        // Stelle sicher, dass das aktuelle Zeichen im String
        // ein alphabetisches Zeichen ist
        // Gehe andernfalls zum nächsten Zeichen im String
        if (!isalpha(string[i])) {
            i++;
            continue;
        }

        // Für ein einzelnes Wort erwarten wir ein Leerzeichen vor dem Wort
        // Ausnahme ist nur das allererste Zeichen des Strings
        if (i != 0 && string[i - 1] != ' ') {
            i++;
            continue;
        }

        // Nun überprüfen wir Schritt für Schritt, ob das Zeichen am aktuellen
        // Index im String mit dem jeweiligen Zeichen im Wort übereinstimmt
        // Falls dies an einer Stelle nicht der Fall sein sollte, beenden wir
        // die (innere) Schleife
        for (int j = 0; j < lenWord; j++) {
            if (tolower(string[i]) != tolower(word[j])) {
                validWord = false;
                break;
            }
            // Die Zeichen waren identisch: gehe einen Schritt weiter
            i++;
        }

        // Nach einem Wort erwarten wir entweder ein Leerraumzeichen oder ein
        // Punktuationszeichen. Wir prüfen also, dass das nächste Zeichen
        // kein alphabetisches Zeichen ist
        if (isalpha(string[i])) {
            i++;
            continue;
        }

        if (validWord)
            count++;

        i++;
    }

    return count;
}

int main(void) {
    char string[] = "Fischers Fritze fischt frische Fische, frische Fische fischt Fischers Fritze";
    char word[] = "Fische";

    int count = countWords(string, word);

    printf("Das Wort \"%s\" kam %d-mal im String vor\n", word, count);
}
