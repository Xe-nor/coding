#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
  struct node *prev;
} *first = NULL, *last = NULL;

//////////////////////////////////////////////////////////////////////////////////////////////// CREATE
void create()
{
  int *a, n;
  printf("\n-->ENTER THE SIZE OF ARRAY: ");
  scanf("%d", &n);
  a = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
  {
    printf("\nENTER ELEMENT %d: ", i + 1);
    scanf("%d", &a[i]);
  }

  first = (struct node *)malloc(sizeof(struct node));
  first->data = a[0];
  first->next = first->prev = NULL;
  last = first;

  for (int i = 1; i < n; i++)
  {
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data = a[i];
    t->next = last->next;
    t->prev = last; // last is the previous node of t
    last->next = t;
    last = t;
  }
}

///////////////////////////////////////////////////////////////////////////// DISPLAY

void display(struct node *p)
{
  printf("\nTHE LINKED LIST CONTAINS: ");
  do
  {
    printf("%d ", p->data);
    p = p->next;
  } while (p);
}

///////////////////////////////////////////////////////////////////////////////// COUNT

int count(struct node *p)
{
  int count = 0;
  do
  {
    count++;
    p = p->next;
  } while (p);
  return count;
}

////////////////////////////////////////////////////////////////////////////////// INSERT

void insert(struct node *p, int pos, int value)
{
  if (pos < 0 || pos > count(first))
  {
    return;
  }
  if (pos == 0)
  {
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data = value;
    t->next = first;
    t->prev = NULL;
    first->prev = t;
    first = t;
  }
  else
  {
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data = value;
    for (int i = 0; i < pos - 1; i++)
    {
      p = p->next;
    }
    t->next = p->next;
    t->prev = p;
    if (p->next)
    {
      p->next->prev = t;
    }
    p->next = t;
  }
}

///////////////////////////////////////////////////////////////////////////////////// DELETE

void delete (struct node *p, int pos)
{
  struct node *t = first;
  if (pos < 0 || pos > count(first))
  {
    return;
  }
  if (pos == 0)
  {
    first = first->next;
    first->prev = NULL;
    free(t);
  }
  else
  {
    for (int i = 0; i < pos; i++)
    {
      t = p;
      p = p->next;
    }
    t->next = p->next;
    if (p->next)
    {
      p->next->prev = t;
    }
    free(p);
  }
}

////////////////////////////////////////////////////////////////////////////////// REVERSE

void reverse(struct node *p)
{
  struct node *temp = NULL;
  while (p)
  {
    temp = p->next;
    p->next = p->prev;
    p->prev = temp;
    p = p->prev;
    if (p && p->next == NULL)
    {
      first = p;
    } 
  }
}

int main()
{
  int choice;
  do
  {
    printf("\n\n*******-MENU-*******\n");
    printf("0.Exit\n");
    printf("1.Create Linked list\n");
    printf("2.Display Linked list\n");
    printf("3.Length of Linked list\n");
    printf("4.Insert in Linked list\n");
    printf("5.Delete in Linked list\n");
    printf("6.Reverse Linked list\n");
    printf("\nENTER YOUR CHOICE - ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      create();
      break;

    case 2:
      display(first);
      break;

    case 3:
      printf("\n-->THE LENGTH OF LINKED LIST IS %d ", count(first));
      break;

    case 4:
      printf("\n-->ENTER THE VALUE TO INSERT: ");
      int valuee = 0, poss = 0;
      scanf("%d", &valuee);
      printf("\n-->ENTER THE POSITION TO INSERT: ");
      scanf("%d", &poss);
      insert(first, poss, valuee);
      break;
    case 5:
      printf("\n-->ENTER THE POSITION TO DELETE: ");
      int pos = 0;
      scanf("%d", &pos);
      delete (first, pos);
      break;
    case 6:
      reverse(first);
      break;
    default:
      break;
    }

  } while (choice != 0);

  return 0;
}