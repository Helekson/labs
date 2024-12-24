#include <stdio.h>
#include <string.h>
#include <ctype.h>

char aA(char *str) {

    size_t ln = strlen(str);

    for(int i = 0; i < ln; i += 2) {

        str[i] = toupper(str[i]);
    }

    return *str;
}

int main() {
    char str[] = "Hello world";

    printf("Before: %s\n", str);

    aA(&str);

    printf("After: %s\n", str);

    return 0;
}