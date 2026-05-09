#include <stdio.h>

void compress(const char input[], char output[]) {
    int readPos = 0;
    int writePos = 0;

    while (input[readPos] != '\0') {
        char currentChar = input[readPos];
        int count = 1;

        readPos++;

        while (input[readPos] == currentChar) {
            count++;
            readPos++;
        }

        output[writePos] = currentChar;
        writePos++;

        output[writePos] = '0' + count;
        writePos++;
    }

    output[writePos] = '\0';
}

int main(void) {
    char input[] = "aaabbc";
    char output[100];

    compress(input, output);
    printf("Eingabe: \"%s\"\n", input);
    printf("Ausgabe: \"%s\"\n", output);
}
