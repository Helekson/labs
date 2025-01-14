#include <stdio.h>
 int main(){

    int a;

    printf("Enter integer:");
    scanf("%d", &a);

    int lower_bit = a & 1;
     printf("Lowest bit of %d is equal to: %d\n", a, lower_bit);

     return 0;
}
