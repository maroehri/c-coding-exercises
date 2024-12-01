#include <stdio.h>

unsigned long long digitsToSquares(unsigned number) {
    unsigned long long transformedNumber = 0;
    unsigned int currentDigit = 0;
    unsigned long long digitSquare = 0;
    unsigned long long placeValue = 1;

    do {
        currentDigit = number % 10; // Get the last digit
        number /= 10;               // Remove the last digit

        digitSquare = currentDigit * currentDigit; // Calculate the square of the digit

        // Determine if the square requires one or two digits
        unsigned long long digitShiftMultiplier = 1;
        if (digitSquare > 9)
            digitShiftMultiplier = 10;

        transformedNumber += digitSquare * placeValue;
        // Adjust the place value for the next digit
        placeValue *= digitShiftMultiplier * 10;
    } while (number != 0);

    return transformedNumber;
}

int main(void) {
    unsigned int inputNumber1 = 123;   // Expected: 149
    unsigned long long outputNumber1 = digitsToSquares(inputNumber1);
    printf("%u --> %lld\n", inputNumber1, outputNumber1);

    unsigned int inputNumber2 = 9119;  // Expected: 811181
    unsigned long long outputNumber2 = digitsToSquares(inputNumber2);
    printf("%u --> %lld\n", inputNumber2, outputNumber2);

    unsigned int inputNumber3 = 3210987654;  // Expected: 9410816449362516
    unsigned long long outputNumber3 = digitsToSquares(inputNumber3);
    printf("%u --> %lld\n", inputNumber3, outputNumber3);

    unsigned int inputNumber4 = 0;  // Expected: 0
    unsigned long long outputNumber4 = digitsToSquares(inputNumber4);
    printf("%u --> %lld\n", inputNumber4, outputNumber4);
}
