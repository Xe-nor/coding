#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int sumofdig(int num){
    int sum = 0;
    sum += num % 10;
    return sumofdig(num / 10);
}
 
int main()
{
    printf("%d",sumofdig(312));

    return 0;
}