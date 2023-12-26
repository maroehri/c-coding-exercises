#include <stdio.h>
#include <stdbool.h>
#include <string.h> // für strlen()
#include <ctype.h>  // für tolower()

bool isPalindrome(char string[]) {
    int len = (int)strlen(string);
    int middle = len / 2;

    for (int i = 0; i < middle; i++) {
        if (tolower(string[i]) != tolower(string[len - i - 1]))
            return false;
    }
    return true;
}

int main(void) {
    char string1[] = "Kein Palindrom";
    char string2[] = "Reliefpfeiler";   // ist ein Palindrom
    char string3[] = "Rentner";         // ist ein Palindrom

    if (isPalindrome(string1))
        printf("\"%s\" ist ein Palindrom\n", string1);
    else
        printf("\"%s\" ist kein Palindrom\n", string1);

    if (isPalindrome(string2))
        printf("\"%s\" ist ein Palindrom\n", string2);
    else
        printf("\"%s\" ist kein Palindrom\n", string2);

    if (isPalindrome(string3))
        printf("\"%s\" ist ein Palindrom\n", string3);
    else
        printf("\"%s\" ist kein Palindrom\n", string3);
}
