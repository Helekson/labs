#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *str_cat(const char *str1, const char *str2) {
    size_t ln1 = strlen(str1);
    size_t ln2 = strlen(str2);

    char *result = malloc(ln1 + ln2 + 1);
    if (result == NULL) {
        printf("Error: Memory allocation failed.\n");
        return NULL;
    }

    for (size_t i = 0; i < ln1; i++) {
        result[i] = str1[i];
    }

    for (size_t i = 0; i <= ln2; i++) {
        result[ln1 + i] = str2[i];
    }

    return result;
}

int main() {
    const char str1[] = "Hello, ";
    const char str2[] = "world!";

    char *result = str_cat(str1, str2);
    if (result != NULL) {
        printf("%s\n", result);

        free(result);
    }

    return 0;
}
