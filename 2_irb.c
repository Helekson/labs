#include <stdio.h>
#include <string.h>

void revers(char str[]) {

    int start = 0;
    int end = strlen(str) - 1;
    int q;

    while (start < end) {

        q = str[start];
        str[start] = str[end];
        str[end] = q;

        start++;
        end--;
    }
}

int main() {

    char str[50];

    printf("Enter string: \n");
    scanf("%s", str);

    revers (str);

    printf("%s", str);

    return 0;
}