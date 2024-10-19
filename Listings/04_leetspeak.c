#include <stdio.h>

char getLeetChar(char c) {
    switch (c) {
    case 'A':
    case 'a':
        c = '4';
        break;
    case 'B':
    case 'b':
        c = '8';
        break;
    case 'E':
    case 'e':
        c = '3';
        break;
    case 'G':
    case 'g':
        c = '6';
        break;
    case 'H':
    case 'h':
        c = '#';
        break;
    case 'I':
    case 'i':
        c = '1';
        break;
    case 'O':
    case 'o':
        c = '0';
        break;
    case 'S':
    case 's':
        c = '$';
        break;
    case 'T':
    case 't':
        c = '7';
        break;
    case 'Z':
    case 'z':
        c = '2';
        break;
    default:
        break;
    }

    return c;
}

void leetspeak(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = getLeetChar(str[i]);
    }
}

int main(void) {
    char input[100];

    printf("Satz eingeben: ");
    fgets(input, sizeof(input), stdin);



    leetspeak(input);

    printf("Leetspeak: %s", input);

    return 0;
}
