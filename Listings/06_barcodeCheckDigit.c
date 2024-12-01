#include <stdio.h>
#include <string.h> // für strlen() und strcspn()
#include <ctype.h>  // für isdigit()

#define BARCODE_LENGTH 12

int convertStringToArray(const char *str, int barcode[]) {
    // Überprüfen, ob der String genau 12 Ziffern enthält
    if (strlen(str) != BARCODE_LENGTH) {
        printf("Fehler: String muss 12 Zeichen lang sein.\n");
        return 1;  // Fehlercode zurückgeben
    }

    // Überprüfen, ob der String nur Ziffern enthält
    for (int i = 0; i < 12; i++) {
        if (!isdigit(str[i])) {
            printf("Fehler: String darf nur Ziffern enthalten.\n");
            return 2;  // Fehlercode zurückgeben
        }
    }

    // Konvertieren der Zeichen in Integer
    for (int i = 0; i < 12; i++) {
        // ASCII-Wert von '0' subtrahieren,
        // um die Ziffer zu erhalten
        barcode[i] = str[i] - '0';
    }

    return 0;  // Erfolgscode zurückgeben
}

int barcodeCheckDigit(int barcode[], int barcodeLength) {
    int oddSum = 0, evenSum = 0, totalSum = 0;
    int checkDigit = 0;

    // Berechne die Summe der ungeraden und geraden Ziffern
    for (int i = 0; i < barcodeLength; i++) {
        if (i % 2 == 0) {
            // Ungerade Positionen (Index 0, 2, 4,...)
            oddSum += barcode[i];
        } else {
            // Gerade Positionen (Index 1, 3, 5,...)
            evenSum += barcode[i];
        }
    }

    // Multipliziere die Summe der geraden Positionen mit 3
    // und addiere diese Summe mit der Summe der ungeraden Zahlen
    totalSum = oddSum + (evenSum * 3);

    // Berechne die Prüfziffer
    checkDigit = 10 - (totalSum % 10);
    if (checkDigit == 10) {
        checkDigit = 0;
    }

    return checkDigit;
}

int main(void) {
    // Eingabe String: Platz für 12 Ziffern + Nullterminator
    char inputString[BARCODE_LENGTH + 1];
    int barcode[BARCODE_LENGTH];

    printf("Ersten 12 Ziffern des EAN-13 Barcodes eingeben:\n");
    fgets(inputString, sizeof(inputString), stdin);

    // Entfernt das Newline-Zeichen, falls vorhanden,
    // und ersetzt es durch das Nullterminierungszeichen
    inputString[strcspn(inputString, "\n")] = 0;


    // (a) String in Integer-Array umwandeln
    int convertResult = convertStringToArray(inputString, barcode);

    if (convertResult != 0)
        return 1; // String konnte nicht konvertiert werden

    // (b) Prüfziffer berechnen
    int checkDigit = barcodeCheckDigit(barcode, BARCODE_LENGTH);

    // Ausgabe der Prüfziffer
    printf("Die Prüfziffer lautet: %d\n", checkDigit);

    return 0;
}
