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
        scanf("%d", &a[i]);  }

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

////////////////////////////////////////////////////////////////////// CREATE2

void create2()
{
    
    int n, *b;
        printf("\nEnter the size of array - ");
        scanf("%d", &n);
        b = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++)
        {
            printf("Enter element %d : ", i + 1);
            scanf("%d", &b[i]);
        }

    struct node *t;                                      // temp pointer to traverse and last pointer
    second = (struct node *)malloc(sizeof(struct node)); // allocating memory for first node
    second->data = b[0];                                 // inserting data to first node
    second->next = NULL;                                 // next pointer of first node points to null as right now there are no other nodes after first node
    last = second;                                       // last points to first as there is only first node which is also the last

    for (int i = 1; i < n; i++) // creation of other nodes
    {
        t = (struct node *)malloc(sizeof(struct node)); // memory allocation
        t->data = b[i];                                 // data insertion
        t->next = NULL;                                 // next points to null indicating there are no nodes after this node
        last->next = t;                                 // last points to the node indicating this is the last node
        last = t;
    }
    printf("\n--> 2nd LINKED LIST HAS BEEN CREATED\n\n");
}

////////////////////////////////////////////////////////////////////// CREATE 3

void create3()
{
   
    int n, *c;

        printf("\nEnter the size of array - ");
        scanf("%d", &n);
        c = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++)
        {
            printf("Enter element %d : ", i + 1);
            scanf("%d", &c[i]);
        }

    struct node *t;                                     // temp pointer to traverse and last pointer
    third = (struct node *)malloc(sizeof(struct node)); // allocating memory for first node
    third->data = c[0];                                 // inserting data to first node
    third->next = NULL;                                 // next pointer of first node points to null as right now there are no other nodes after first node
    last = third;                                       // last points to first as there is only first node which is also the last

    for (int i = 1; i < n; i++) // creation of other nodes
    {
        t = (struct node *)malloc(sizeof(struct node)); // memory allocation
        t->data = c[i];                                 // data insertion
        t->next = NULL;                                 // next points to null indicating there are no nodes after this node
        last->next = t;                                 // last points to the node indicating this is the last node
        last = t;
    }
    printf("\n--> 3rd LINKED LIST HAS BEEN CREATED\n\n");
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

//////////////////////////////////////////////////////////////////////// RECURSIVE DISPLAY

void rdisplay(struct node *p)
{
    printf("\n\n--> THE LINKED LIST CONTAINS:-  ");
    while (p)
    {
        printf("%d, ", p->data);
        rdisplay(p->next);
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

//////////////////////////////////////////////////////////////////////// ADD

void add(struct node *p)
{
    int sum = 0;
    while (p)
    {
        sum = sum + p->data;
        p = p->next;
    }
    printf("\n--> THE SUM OF ELEMENTS ARE - %d", sum);
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

//////////////////////////////////////////////////////////////////////// CHECKSORT

void checksort(struct node *p)
{
    int x = INT_MIN;
    while (p)
    {
        if (p->data < x)
        {
            printf("\n-->THE LINKED LIST IS NOT SORTED\n");
            return;
        }

        else
        {
            x = p->data;
            p = p->next;
        }
    }
    printf("\n-->THE LINKED LIST IS SORTED\n");
}

//////////////////////////////////////////////////////////////////////// DELETE DUPLICATE

void deletedup(struct node *p)
{
    struct node *q = p->next, *t = p ,*start=p;
    while (q)
    {
        for (int i = 0; i < count(start); i++)
        {
            for (int j = 0; j < count(start); j++)
            {
                if (p->data == q->data)
                {
                    if (p->next = q)
                    {
                        p->next = q->next;
                        free(q);
                        q = p->next;
                    }
                    else
                    {
                        t->next = q->next;
                        free(q);
                        q = t->next;
                    }
                    printf("\n-->DUPLICATE FOUND AND DELETED\n");
                    display(start);
                    return;
                }
                else
                {
                    t = q;
                    q = q->next;
                }
            }
            p = p->next;
        }
        printf("\n-->NO DUPLICATES FOUND\n");
    }
}

//////////////////////////////////////////////////////////////////////// REVERSE USING ARRAY

void arrreverse(struct node *p)
{
    int *a = (int *)malloc(count(p) * sizeof(int)), i = 0;
    struct node *q = p;
    while (q)
    {
        a[i] = q->data;
        q = q->next;
        i++;
    }
    q = p;
    i--;
    while (q)
    {
        q->data = a[i];
        q = q->next;
        i--;
    }
    display(p);
}

//////////////////////////////////////////////////////////////////////// REVERSE USING SLIDING POINTERS

void slidereverse(struct node *p)
{
    struct node *dummy = p;
    struct node *q = NULL, *r = NULL;
    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    dummy = q;
    display(dummy);
}

//////////////////////////////////////////////////////////////////////// CONCAT

void concatt(struct node *p,struct node *q){
    third = p;
    while (p->next!=NULL)
    {
        p = p->next;
    }
    p->next = q;
    display(third);
}

//////////////////////////////////////////////////////////////////////// CHECK LOOP

void loopcheck(struct node *p){
    struct node *m=p, *n=p;
    do{
        m = m->next;
        n = n->next;
        if (n)
        {
            n = n->next;
        }
    } while (m && n && m != n);
    if (m==n)
    {
        printf("\n-->THERE EXISTS A LOOP\n");
    }
    else{
        printf("\n-->THERE IS NO LOOP\n");
    }
    

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
        printf("3.Display Linked list recursively\n");
        printf("4.Count the number of nodes\n");
        printf("5.ADD the linked list\n");
        printf("6.Find the MAX element in the linked list\n");
        printf("7.Search an element in the linked list\n");
        printf("8.Insert an element into linked list\n");
        printf("9.Insert an element at last into linked list\n");
        printf("10.Insert an element into a sorted linked list\n");
        printf("11.Delete a node in linked list\n");
        printf("12.Check if linked list is sorted\n");
        printf("13.Check for duplicates in linked list\n");
        printf("14.Reverse the linked list using array\n");
        printf("15.Reverse the linked list using sliding pointers\n");
        printf("16.Concat two linked lists\n");
        printf("17.Check for loop in linked lists\n");
        printf("\nENTER YOUR CHOICE - ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (first == NULL)
            {
                create1();
                break;
            }
            else if (second == NULL)
            {
                create2();
                break;
            }
            else
            {
                create3();
                break;
            }
            break;

        case 2:
            printf("\n-->ENTER LINKED LIST NUMBER- \n");
            scanf("%d", &s);
            switch (s)
            {
            case 1:
                display(first);
                break;
            case 2:
                display(second);
                break;
            case 3:
                display(third);
                break;

            default:
                break;
            }
            break;

        case 3:
            printf("\n-->ENTER LINKED LIST UMBERr- \n");
            scanf("%d", &s);
            switch (s)
            {
            case 1:
                rdisplay(first);
                break;
            case 2:
                rdisplay(second);
                break;
            case 3:
                rdisplay(third);
                break;

            default:
                break;
            }
            break;
        case 4:
            int c;
            printf("\n-->ENTER LINKED LIST NUMBER- \n");
            scanf("%d", &s);
            switch (s)
            {
            case 1:
                c = count(first);
                break;
            case 2:
                c = count(second);
                break;
            case 3:
                c = count(third);
                break;

            default:
                break;
            }
            printf("\n--> THE NUMBER OF NODES IN LINKED LIST IS %d", c);
            break;
        case 5:
            printf("\n-->ENTER LINKED LIST NUMBER- \n");
            scanf("%d", &s);
            switch (s)
            {
            case 1:
                add(first);
                break;
            case 2:
                add(second);
                break;
            case 3:
                add(third);
                break;

            default:
                break;
            }
            break;
        case 6:
            printf("\n-->ENTER LINKED LIST NUMBER- ");
            scanf("%d", &s);
            switch (s)
            {
            case 1:
                max(first);
                break;
            case 2:
                max(second);
                break;
            case 3:
                max(third);
                break;

            default:
                break;
            }
            break;
        case 7:
            int key;
            printf("\nENTER THE ELEMENT YOU WANT TO SEARCH:");
            scanf("%d", &key);
            printf("\n-->ENTER LINKED LIST NUMBER- ");
            scanf("%d", &s);
            switch (s)
            {
            case 1:
                lsearch(first, key);
                break;
            case 2:
                lsearch(second, key);
                break;
            case 3:
                lsearch(third, key);
                break;

            default:
                break;
            }
            break;
        case 8:
            int data, pos;
            printf("\nENTER THE ELEMENT YOU WANT TO INSERT:");
            scanf("%d", &data);
            printf("\nENTER THE POSITION AT WHICH YOU WANT TO INSERT:");
            scanf("%d", &pos);
            printf("\n-->ENTER LINKED LIST NUMBER- ");
            scanf("%d", &s);
            switch (s)
            {
            case 1:
                insert(first, pos, data);
                break;
            case 2:
                insert(second, pos, data);
                break;
            case 3:
                insert(third, pos, data);
                break;

            default:
                break;
            }
            break;
        case 9:
            int dataa;
            printf("\nENTER THE ELEMENT YOU WANT TO INSERT:");
            scanf("%d", &dataa);
            printf("\n-->ENTER LINKED LIST NUMBER- ");
            scanf("%d", &s);
            switch (s)
            {
            case 1:
                insertlast(first, dataa);
                break;
            case 2:
                insertlast(second, dataa);
                break;
            case 3:
                insertlast(third, dataa);
                break;

            default:
                break;
            }
            break;

        case 10:
            int value;
            printf("\nENTER THE ELEMENT YOU WANT TO INSERT:");
            scanf("%d", &value);
            printf("\n-->ENTER LINKED LIST NUMBER- ");
            scanf("%d", &s);
            switch (s)
            {
            case 1:
                sortedinsert(first, value);
                break;
            case 2:
                sortedinsert(second, value);
                break;
            case 3:
                sortedinsert(third, value);
                break;

            default:
                break;
            }
            break;
        case 11:
            int poss;
            printf("\nENTER THE NODE POSITION TO DELETE:");
            scanf("%d", &poss);
            printf("\n-->ENTER LINKED LIST NUMBER- ");
            scanf("%d", &s);
            switch (s)
            {
            case 1:
                ndelete(first, poss);
                break;
            case 2:
                ndelete(second, poss);
                break;
            case 3:
                ndelete(third, poss);
                break;

            default:
                break;
            }
            break;
        case 12:
            printf("\n-->ENTER LINKED LIST NUMBER- ");
            scanf("%d", &s);
            switch (s)
            {
            case 1:
                checksort(first);
                break;
            case 2:
                checksort(second);
                break;
            case 3:
                checksort(third);
                break;

            default:
                break;
            }
            break;

        case 13:
            printf("\n-->ENTER LINKED LIST NUMBER- ");
            scanf("%d", &s);
            switch (s)
            {
            case 1:
                deletedup(first);
                break;
            case 2:
                deletedup(second);
                break;
            case 3:
                deletedup(third);
                break;
            default:
                break;
            }
            break;
        case 14:
            printf("\n-->ENTER LINKED LIST NUMBER- ");
            scanf("%d", &s);
            switch (s)
            {
            case 1:
                arrreverse(first);
                break;
            case 2:
                arrreverse(second);
                break;
            case 3:
                arrreverse(third);
                break;

            default:
                break;
            }
            break;
        case 15:
            printf("\n-->ENTER LINKED LIST NUMBER- ");
            scanf("%d", &s);
            switch (s)
            {
            case 1:
                slidereverse(first);
                break;
            case 2:
                slidereverse(second);
                break;
            case 3:
                slidereverse(third);
                break;

            default:
                break;
            }

            break;
        case 16:
                concatt(first,second);
                break;  
        case 17:
            printf("\n-->ENTER LINKED LIST NUMBER- ");
            scanf("%d", &s);
            switch (s)
            {
            case 1:
                loopcheck(first);
                break;
            case 2:
                loopcheck(second);
                break;
            case 3:
                loopcheck(third);
                break;

            default:
                break;
            }

                break;

        default:
            printf("\n!!! invalid choice !!!\n");
            break;
        }

    } while (choice != 0);

    return 0;
}
