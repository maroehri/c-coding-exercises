#include <stdio.h>
#include <string.h> // für strtok()
#include <stdlib.h> // für atoi()

int main(void) {
    char *filename = "08_group_of_numbers.txt";
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Fehler beim Öffnen der Datei\n");
        return -1;
    }

/*
    char buf[256];
    if (fgets(buf, 255, fp) == NULL) {
        printf("Fehler beim Einlesen der Zeile");
        return -2;
    }
*/

// Ermittle die Länge der Zeile
fseek(fp, 0, SEEK_END);
long length = ftell(fp);
fseek(fp, 0, SEEK_SET);

// Allokiere Speicher für die Zeile
char *buf = (char *)malloc((unsigned long)length + 1);
if (buf == NULL) {
    printf("Speicherzuweisungsfehler\n");
    fclose(fp);
    return -1;
}

if (fgets(buf, (int)length + 1, fp) == NULL) {
    printf("Fehler beim Einlesen der Zeile\n");
    free(buf);
    fclose(fp);
    return -2;
}

    int groupLength;
    int groupSum;
    double groupAverage;
    char *p;
    p = strtok(buf, " ");
    while (p != NULL) {
        groupLength = atoi(p);
        groupSum = 0;
        groupAverage = 0;
        for (int i = 0; i < groupLength; i++) {
            p = strtok(NULL, " ");
            if (p == NULL) {
                printf("Unerwartetes Ende der Zeile\n");
                return -3;
            }
            groupSum += atoi(p);
        }
        groupAverage = (double)groupSum / groupLength;
        printf("Gruppe mit %d Elementen: %.2lf\n", groupLength, groupAverage);

        // Bereite die nächste Gruppe vor
        p = strtok(NULL, " ");
    }

    free(buf);
    fclose(fp);
}
