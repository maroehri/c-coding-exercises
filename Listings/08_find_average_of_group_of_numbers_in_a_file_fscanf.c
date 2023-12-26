#include <stdio.h>
#include <stdlib.h> // für malloc und free

int main(void) {
    char *filename = "08_group_of_numbers.txt";
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Fehler beim Öffnen der Datei\n");
        return -1;
    }

    int groupLength;
    int number;
    int groupSum;
    double groupAverage;

    while (fscanf(fp, "%d", &groupLength) == 1) {
        groupSum = 0;
        groupAverage = 0.0;
        for (int i = 0; i < groupLength; i++) {
            if (fscanf(fp, "%d", &number) != 1) {
                printf("Fehler beim Lesen der Zahlen\n");
                fclose(fp);
                return -2;
            }
            groupSum += number;
        }
        groupAverage = (double)groupSum / groupLength;
        printf("Gruppe mit %d Elementen: %.2lf\n", groupLength, groupAverage);
    }

    fclose(fp);
    return 0;
}
