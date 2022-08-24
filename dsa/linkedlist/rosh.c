#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node
{
    int data;
    struct node *next;
} *first = NULL, *last, *second = NULL, *third = NULL;

/////////////////////////////////////////////////////////////// CREATE
;
void create1()
{
    int n, *a;
    printf("\nEnter the size of array - ");
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d : ", i + 1);
        scanf("%d", &a[i]);
    }

    struct node *t;                                     // temp pointer to traverse and last pointer
    first = (struct node *)malloc(sizeof(struct node)); // allocating memory for first node
    first->data = a[0];                                 // inserting data to first node
    first->next = NULL;                                 // next pointer of first node points to null as right now there are no other nodes after first node
    last = first;                                       // last points to first as there is only first node which is also the last

    for (int i = 1; i < n; i++) // creation of other nodes
    {
        t = (struct node *)malloc(sizeof(struct node)); // memory allocation
        t->data = a[i];                                 // data insertion
        t->next = NULL;                                 // next points to null indicating there are no nodes after this node
        last->next = t;                                 // last points to the node indicating this is the last node
        last = t;
    }
    printf("\n--> LINKED LIST HAS BEEN CREATED\n\n");
}


////////////////////////////////////////////////////////////////////// DISPLAY

void display(struct node *p)
{
    printf("\n--> THE LINKED LIST CONTAINS:- ");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}



//////////////////////////////////////////////////////////////////////// COUNT

int count(struct node *p)
{
    int l = 0;
    while (p)
    {
        l++;
        p = p->next;
    }
    return l;
}


//////////////////////////////////////////////////////////////////////// MAX

void max(struct node *p)
{
    int max = INT_MIN;
    while (p)
    {
        if (p->data > max)
        {
            max = p->data;
            p = p->next;
        }
    }
    printf("\n\n--> THE MAX ELEMENT IN LINKED LIST IS %d\n\n ", max);
}
//////////////////////////////////////////////////////////////////////// LINEAR SEARCH

int lsearch(struct node *p, int key)
{
    struct node *dummy = p;
    struct node *q = NULL;
    while (p)
    {
        if (p->data == key)
        {
            printf("\n--> THE ELEMENT IS FOUND \n");
            q->next = p->next;
            p->next = dummy;
            dummy = p;
            return 0;
        }
        q = p;
        p = p->next;
    }
    printf("\n--> ELEMENT IS NOT FOUND\n");
}

//////////////////////////////////////////////////////////////////////// INSERT

void insert(struct node *p, int index, int data)
{
    struct node *dummy = p;

    if (index < 0 || index > count(p))
    {
        return;
    }
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data = data;
    p = dummy;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
    }
    if (index == 0)
    {
        t->next = dummy->next;
        dummy = t;
    }
    else
    {
        t->next = p->next;
        p->next = t;
    }
    display(dummy);
}

//////////////////////////////////////////////////////////////////////// INSERT AT LAST

void insertlast(struct node *p, int data)
{
    struct node *dummy = p;
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data = data;
    t->next = NULL;
    if (dummy == NULL)
    {
        dummy = last = t;
    }
    else
    {
        last->next = t;
        last = t;
    }
    display(dummy);
}

//////////////////////////////////////////////////////////////////////// SORTED INSERT

void sortedinsert(struct node *p, int value)
{
    struct node *dummy = p;
    struct node *t = (struct node *)malloc(sizeof(struct node)), *q = NULL;
    t->data = value;
    t->next = NULL;
    if (first == NULL)
    {
        dummy = t;
    }
    else
    {
        while (p && p->data < value)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            dummy = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }

    display(dummy);
}

//////////////////////////////////////////////////////////////////////// DELETE NODE

void ndelete(struct node *p, int index)
{
    struct node *dummy = p;
    struct node *q;
    int nodedata = -1;

    if (index < 0 || index > count(dummy))
    {
        return;
    }

    if (index == 1)
    {
        nodedata = dummy->data;
        p = dummy;
        dummy = dummy->next;
        free(p);
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        nodedata = p->data;
        free(p);
    }

    printf("\n-->NODE CONTAINING %d HAS BEEN DELETED\n", nodedata);
    display(dummy);
}




//////////////////////////////////////////////////////////////////////// DRIVER CODE

int main(int argc, char const *argv[])
{
    int s;

    int choice;
    do
    {

        printf("\n*******-MENU-*******\n");
        printf("0.Exit\n");
        printf("1.Create Linked list\n");
        printf("2.Display Linked list\n");
        printf("7.Search an element in the linked list\n");
        printf("8.Insert an element into linked list\n");
        printf("9.Insert an element at last into linked list\n");
        printf("10.Insert an element into a sorted linked list\n");
        printf("11.Delete a node in linked list\n");
        
        printf("\nENTER YOUR CHOICE - ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (first == NULL)
            {
                create1();
                
            }
            break;

        case 2:
          
            
                display(first);
                
          
            break;


      
        case 7:

            
            printf("\nENTER THE ELEMENT YOU WANT TO SEARCH:");
            int key;
            scanf("%d", &key);
          
            
          
                lsearch(first, key);
                
           
                break;
    
        case 8:
          
            printf("\nENTER THE ELEMENT YOU WANT TO INSERT:");
            int data, pos;
            scanf("%d", &data);
            printf("\nENTER THE POSITION AT WHICH YOU WANT TO INSERT:");
            scanf("%d", &pos);
           
        
                insert(first, pos, data);
          
            break;
        case 9:
          
            printf("\nENTER THE ELEMENT YOU WANT TO INSERT:");
            int dataa;
            scanf("%d", &dataa);
          
          
                insertlast(first, dataa);
          
            break;

        case 10:
            
          
            printf("\nENTER THE ELEMENT YOU WANT TO INSERT:");
            int value;
            scanf("%d", &value);
           
                sortedinsert(first, value);
             
            
            break;
        case 11:
         
            printf("\nENTER THE NODE POSITION TO DELETE:");
            int poss;
            scanf("%d", &poss);
           
                ndelete(first, poss);
        
            break;
       

        default:
            printf("\n!!! invalid choice !!!\n");
            break;
        }

    } while (choice != 0);

    return 0;
}
