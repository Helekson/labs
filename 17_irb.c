#include <stdio.h>
#include <string.h>

char *str_cat(char * str1, char const * str2) {

    int ln1 = strlen(str1);
    int ln2 = strlen(str2);

    for(int i = 0; i <= ln2; i++) {

        str1[ln1 + i] = str2[i];
    }

    return str1;
}

int main() {

    char str1[100] = "Hello, ";
    char str2[] = "world!";

    str_cat(str1, str2);

    printf("%s", str1);

    return 0;
}