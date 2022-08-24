#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct employee{
    char name[20];
    int age;
    float salary;
};

struct employee display(struct employee *one);

int main()
{
    struct employee emp1;
    strcpy(emp1.name, "rohan");
    emp1.age = 20;
    emp1.salary = 2;

    display(&emp1);

    return 0;
}

struct employee display(struct employee *one){
    printf("%s %d %.2f", one->name, one->age, one->salary);
}