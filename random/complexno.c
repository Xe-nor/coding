#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct complex{
    int real;
    int image;
};

struct complex add(struct complex *p, struct complex *q);//strcuture prototype

int main()
{
    struct complex num1, num2, addition,sub;
    printf("\nEnter the real and imaginary part of the first number: ");
    scanf("%d %d", &num1.real,&num1.image); 
    printf("\nEnter the real and imaginary part of the second number: ");
    scanf("%d %d", &num2.real, &num2.image);

    addition = add(&num1, &num2);

    printf("The final ans: % d + i% d", addition.real, addition.image);

    return 0;
}

struct complex add(struct complex *p, struct complex *q){//structure declaration
    struct complex temp;
    temp.real = p->real + q->real;
    temp.image = p->image + q->image;
    return temp;
}