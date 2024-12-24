#include <stdio.h>
#include <string.h>
#include <ctype.h>

void antisim(char *str1, char *str2) {


    int ln = strlen(str1);
    int j = 0;

    for(int i = 0; i < ln; i++) {

        if(isalnum(str1[i])) {

            str2[j++] = str1[i];
        }
    }
    str2[j] = '\0';
}

int main() {

    char str1[] = "Hello, world!";
    char str2[100] = "";

    printf("%s\n", str1);

    antisim(str1, str2);

    printf("%s\n", str2);

    return 0;
}
