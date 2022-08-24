#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct stack
{
  int size;
  int top;
  int *s;
};

///////////////////////////////////////////////////////////////////////////////////////////////

void create(struct stack *st)
{
  printf("\n-->ENTER THE SIZE OF STACK: ");
  scanf("%d", &st->size);
  st->s = (int *)malloc(st->size * sizeof(int));
  for (int i = 0; i < st->size; i++)
  {
    scanf("%d", &st[i]);
  }
  
}

///////////////////////////////////////////////////////////////////////////////////////////////

void display(struct stack *st)
{
  printf("\n-->Stack contains : ");
  for (int i = st->top; i >= 0; i--)
  {
    printf("%d ", st->s[i]);
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////

void push(struct stack *st,int value){
  if (st->top==st->size-1)
  {
    printf("\n-->STACK OVERFLOW");
  }
  else{
    st->top++;
    st->s[st->top] = value;
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////

void pop(struct stack *st){
  if (st->top==-1)
  {
    printf("\n-->STACK UNDERFLOW"); 
  }
  else
  {
    st->s[st->top--];
    
  }
  
}

///////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
  struct stack st;

  int choice;
  do
  {
    printf("\n\n*******-MENU-*******\n");
    printf("0.Exit\n");
    printf("1.Create stack\n");
    printf("2.Display stack\n");
    printf("3.push stack\n");
    printf("4.pop stack\n");
    // printf("5.Delete in stack\n");
    printf("\nENTER YOUR CHOICE - ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      create(&st);
      break;

    case 2:
      display(&st);
      break;

    case 3:
      printf("\n-->ENTER THE VALUE TO INSERT: ");
      int valuee = 0;
      scanf("%d", &valuee);
      push(&st, valuee);
      break;

    case 4:
      pop(&st);
      break;
    // case 5:
    //   printf("\n-->ENTER THE POSITION TO DELETE: ");
    //   int pos = 0;
    //   scanf("%d", &pos);
    //   delete (head, pos);
    //   break;

    default:
      break;
    }

  } while (choice != 0);

  return 0;
}