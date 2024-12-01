#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h> // isdigit()

bool isValidIpv4(const char *ipAddress) {
    if (ipAddress == NULL || *ipAddress == '\0') {
        return false;
    }

    // Create a copy of the input string for use with strtok
    size_t stringLength = strlen(ipAddress);
    char *workingCopy = malloc(stringLength + 1);
    strncpy(workingCopy, ipAddress, stringLength);
    workingCopy[stringLength] = '\0'; // Ensure null termination

    int octetCount = 0;
    char *currentOctet = strtok(workingCopy, ".");

    while (currentOctet != NULL && octetCount < 4) {
        // Check if octet contains only digits
        for (char *digit = currentOctet; *digit != '\0'; digit++) {
            if (!isdigit(*digit)) {
                free(workingCopy);
                return false;
            }
        }

        // Check if octet with more than one digit
        // contains no leading zero
        if (strlen(currentOctet) > 1 && currentOctet[0] == '0') {
            free(workingCopy);
            return false;
        }

        // Convert octet into decimal number and check range
        long octetValue = strtol(currentOctet, NULL, 10);
        if (octetValue < 0 || octetValue > 255) {
            free(workingCopy);
            return false;
        }

        octetCount++;
        currentOctet = strtok(NULL, ".");
    }

    free(workingCopy);
    return octetCount == 4 && currentOctet == NULL;
}

int main(void) {
    const char address1[] = "10.0.0.1";

    // These ones should not be valid:
    const char address2[] = "";
    const char address3[] = "abc.def.ghi.jkl";
    const char address4[] = "12.34.56 .1";
    const char address5[] = "123.045.067.089";

    printf("%-15s: %s\n", address1, isValidIpv4(address1) ? "valid" : "invalid");
    printf("%-15s: %s\n", address2, isValidIpv4(address2) ? "valid" : "invalid");
    printf("%-15s: %s\n", address3, isValidIpv4(address3) ? "valid" : "invalid");
    printf("%-15s: %s\n", address4, isValidIpv4(address4) ? "valid" : "invalid");
    printf("%-15s: %s\n", address5, isValidIpv4(address5) ? "valid" : "invalid");
}
