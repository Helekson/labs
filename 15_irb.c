#include <stdio.h>
#include <ctype.h>
#include <string.h>

void rearrange_string(char *str) {
    size_t len = strlen(str);
    char temp[len + 1];
    char *digits = temp;
    char *letters = temp;
    char *others = temp;

    letters += len;
    others += 2 * len;

    for (char *p = str; *p != '\0'; ++p) {
        if (isdigit(*p)) {
            *digits++ = *p;
        } else if (isalpha(*p)) {
            *letters++ = *p;
        } else {
            *others++ = *p;
        }
    }

    *digits = '\0';
    *letters = '\0';
    *others = '\0';

    strcpy(str, temp);
    strcat(str, temp + len);
    strcat(str, temp + 2 * len);
}

int main() {
    char str[] = "a1b2!c3@";

    printf("Original: %s\n", str);

    rearrange_string(str);

    printf("Rearranged: %s\n", str);

    return 0;
}
