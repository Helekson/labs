#include <stdio.h>

int str_len(char const str[], int *count)
{
    int i = 0;

    while(str[i])
    {
        (*count)++;
        ++i;
    }

    return *count;
}

int main() {
    char str[] = "abcdefg";
    int answer = 0;

    printf("%d", str_len(str, &answer));

    return 0;
}
