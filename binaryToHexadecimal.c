#include <stdio.h>
#include <string.h>

void binaryToHex(char *binary) {
    int len = strlen(binary);
    int hexDigit = 0;
    char hex[100] = {0};  
    int hexIndex = 0;

    int extraBits = len % 4;
    if (extraBits != 0) {
        for (int i = 0; i < (4 - extraBits); i++) {
            binary--;
            *binary = '0';
        }
        len += (4 - extraBits);
    }

    for (int i = 0; i < len; i += 4) {
        hexDigit = 0;
        for (int j = 0; j < 4; j++) {
            hexDigit = hexDigit * 2 + (binary[i + j] - '0');
        }

        if (hexDigit < 10) {
            hex[hexIndex++] = hexDigit + '0';
        } else {
            hex[hexIndex++] = hexDigit - 10 + 'A';
        }
    }

    hex[hexIndex] = '\0';

    printf("Hexadecimal: %s\n", hex);
}

int main() {
    char binary[100];

    printf("Enter binary number: ");
    scanf("%s", binary);

    binaryToHex(binary);

    return 0;
}
