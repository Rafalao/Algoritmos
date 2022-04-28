#include <stdio.h>
#include "utils.h"
int main(){
    int temp =0;
    printf("Enter the number\n");
    scanf("%d", &temp);
    int value = isGreaterThan10(temp);
    printf("Is %d greater than 10?:%d\n", temp, value);
    return 0;
}