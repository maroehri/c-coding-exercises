#include <stdio.h>
#include <string.h> // für strlen()
#include <ctype.h>  // für tolower() und isalpha()
#include <stdbool.h>

int countWords(char string[], char word[]) {
    int lenWord = (int)strlen(word);
    int wordCount = 0;
    int stringPos = 0;

    while (string[stringPos + 1] != '\0') {
        bool wordFound = true;

        // Stelle sicher, dass das aktuelle Zeichen im String
        // ein alphabetisches Zeichen ist
        // Gehe andernfalls zum nächsten Zeichen im String
        if (!isalpha((unsigned char)string[stringPos])) {
            stringPos++;
            continue;
        }

        // Für ein einzelnes Wort erwarten wir ein Leerzeichen vor dem Wort
        // Ausnahme ist nur das allererste Zeichen des Strings
        if (stringPos != 0 && string[stringPos - 1] != ' ') {
            stringPos++;
            continue;
        }

        // Nun überprüfen wir Schritt für Schritt, ob das Zeichen am aktuellen
        // Index im String mit dem jeweiligen Zeichen im Wort übereinstimmt
        // Falls dies an einer Stelle nicht der Fall sein sollte, beenden wir
        // die (innere) Schleife
        for (int wordPos = 0; wordPos < lenWord; wordPos++) {
            if (tolower(string[stringPos]) != tolower(word[wordPos])) {
                wordFound = false;
                break;
            }
            // Die Zeichen waren identisch: gehe einen Schritt weiter
            stringPos++;
        }

        // Nach einem Wort erwarten wir entweder ein Leerraumzeichen oder ein
        // Punktuationszeichen. Wir prüfen also, dass das nächste Zeichen
        // kein alphabetisches Zeichen ist
        if (isalpha((unsigned char)string[stringPos])) {
            stringPos++;
            continue;
        }

        if (wordFound)
            wordCount++;

        stringPos++;
    }

    return wordCount;
}

int main(void) {
    char string[] = "Fischers Fritze fischt frische Fische, frische Fische fischt Fischers Fritze";
    char word[] = "Fische";

    int count = countWords(string, word);

    printf("Das Wort \"%s\" kam %d-mal im String vor\n", word, count);
}
