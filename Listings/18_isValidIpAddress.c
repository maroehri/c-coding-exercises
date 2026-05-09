#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h> // isdigit()

#define MAX_IP_LENGTH 15
#define MIN_IP_LENGTH 7

bool isValidIpv4(const char *ipAddress) {
    if (ipAddress == NULL)
        return false;

    size_t strLength = strlen(ipAddress);
    // Die minimale Länge besteht aus  4 Ziffern und 3 Punkten (= 7)
    // Die maximale Länge besteht aus 12 Ziffern und 3 Punkten (= 15)
    if (strLength > MAX_IP_LENGTH || strLength < MIN_IP_LENGTH)
        return false;

    char *copy = malloc(sizeof(char) * (strLength + 1));
    if (copy == NULL) {
        printf("Allokation fehlgeschlagen\n");
        return false;
    }

    strncpy(copy, ipAddress, strLength);
    copy[strLength] = '\0';

    int numOctets = 0;
    char *token = strtok(copy, ".");
    while (token != NULL) {
        // Ein Oktet mit mehr als einer Ziffer darf nicht mit einer '0' beginnen
        if (strlen(token) > 1 && token[0] == '0') {
            free(copy);
            return false;
        }

        // Ein Oktet darf nur aus Ziffern bestehen
        for (size_t i = 0; i < strlen(token); i++) {
            if (!isdigit(token[i])) {
                free(copy);
                return false;
            }
        }

        // Der Dezimalwert eines Oktets darf maximal 255 betragen
        long octetValue = strtol(token, NULL, 10);
        if (octetValue > 255) {
            free(copy);
            return false;
        }

        numOctets++;

        token = strtok(NULL, ".");
    }

    // Es müssen genau vier Oktette vorliegen
    if (numOctets != 4) {
        free(copy);
        return false;
    }

    free(copy);
    return true;
}

int main(void) {
    const char address1[] = "10.0.0.1";

    // These ones should not be valid:
    const char address2[] = "";
    const char address3[] = "abc.def.ghi.jkl";
    const char address4[] = "12.34.56 .1";      // Leerzeichen
    const char address5[] = "123.045.067.089";  // führende Nullen
    const char address6[] = "123.45.67";        // zu kurz
    const char address7[] = "123.45.67.8.9";    // zu lang
    const char address8[] = "300.0.0.1";        // Oktekt-Wert nur bis 255 erlaubt

    printf("%-15s: %s\n", address1, isValidIpv4(address1) ? "valid" : "invalid");
    printf("%-15s: %s\n", address2, isValidIpv4(address2) ? "valid" : "invalid");
    printf("%-15s: %s\n", address3, isValidIpv4(address3) ? "valid" : "invalid");
    printf("%-15s: %s\n", address4, isValidIpv4(address4) ? "valid" : "invalid");
    printf("%-15s: %s\n", address5, isValidIpv4(address5) ? "valid" : "invalid");
    printf("%-15s: %s\n", address6, isValidIpv4(address6) ? "valid" : "invalid");
    printf("%-15s: %s\n", address7, isValidIpv4(address7) ? "valid" : "invalid");
    printf("%-15s: %s\n", address8, isValidIpv4(address8) ? "valid" : "invalid");
}
