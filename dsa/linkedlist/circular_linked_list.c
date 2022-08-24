#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * next;
} * head = NULL, *last=NULL;


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
    struct node * t;
    head=(struct node*)malloc(sizeof(struct node));
    head->data=a[0];
    head->next=head;
    last=head;

    for (int i = 1; i < n; i++)
    {
        struct node *t = (struct node *)malloc(sizeof(struct node));
        t->data = a[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
    if (head)
    {
        printf("\n--> LINKED LIST HAS BEEN CREATED\n");
    }
    else{
        printf("\n--> LINKED LIST HAS BEEN NOT BEEN CREATED\n");
    }
    
    
}

////////////////////////////////////////////////////////////////////////////////////////// DISPLAY

void display(struct node *p)
{

    printf("\nTHE LINKED LIST CONTAINS: ");
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p!=head);
}

////////////////////////////////////////////////////////////////////////////////////////////////// INSERT

void insert(struct node *p, int pos, int value)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data = value;
    if (pos == 0)
    {
        if (head == NULL)
        {
            head = t;
            t->next = head;
        }
        else
        {
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = t;
            t->next = head;
            head = t;
        }
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
    display(head);
}

////////////////////////////////////////////////////////////////////////////////////////// COUNT

int count(struct node *p){
    int l = 1;
    do
    {
        l++;
        p = p->next;
    } while (p->next != head);
    return l;
}

////////////////////////////////////////////////////////////////////////////////////////// DELETE

void delete(struct node *p,int pos){

    struct node *q;
    if (pos<1 || pos>count(head))
    {
        return; 
    }
    if (pos==1)
    {
        while (p->next!=head)
        {
            p = p->next;
        }
        if (head==p)
        {
            free(head);
            head = NULL;
        }
        
        p->next = head->next;
        free(head);
        head = p->next;
    }
    else{
        for (int i = 0; i < pos-2; i++)
        {
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        free(q);
    }

    display(head);
}

////////////////////////////////////////////////////////////////////////////////////////// DRIVER CODE

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
        printf("\nENTER YOUR CHOICE - ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create();
            break; 

        case 2:
            display(head);
            break;
        
        case 3:
            printf("\n-->THE LENGTH OF LINKED LIST IS %d ", count(head));
            break;

        case 4:
            printf("\n-->ENTER THE VALUE TO INSERT: ");
            int valuee = 0, poss = 0;
            scanf("%d", &valuee);
            printf("\n-->ENTER THE POSITION TO INSERT: ");
            scanf("%d", &poss);
            insert(head, poss, valuee);
            break; \
        case 5:
            printf("\n-->ENTER THE POSITION TO DELETE: ");
            int pos = 0;
            scanf("%d", &pos);
            delete(head, pos);
            break;

            default:
            break;
        }

    } while (choice != 0);

        return 0;
    }