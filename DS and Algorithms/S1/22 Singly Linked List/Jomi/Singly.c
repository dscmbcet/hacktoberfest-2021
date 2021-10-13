#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
} * head;

typedef struct node NODE;

void insert();
void delete ();
void insertfront(int);
void insertend(int);
void insertbetween(int);
NODE *Getnode();
void deletefront();
void deleteend();
void deletebetween();
void traversal();
void reverse();

void main()
{
    head = Getnode();
    int n;
    do
    {
        printf("\n\n1.Insertion");
        printf("\n2.Deletion");
        printf("\n3.Reversal");
        printf("\n4.Traversal");
        printf("\n5.Exit");
        printf("\nEnter your choice:");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            reverse(head);
            break;
        case 4:
            traversal();
            break;
        }
    } while (n != 5);
}

NODE *Getnode()
{
    NODE *new = (NODE *)malloc(sizeof(NODE));
    new->data = 0;
    new->link = NULL;
    return new;
}

void traversal()
{
    NODE *ptr = head->link;
    if (ptr == NULL)
        printf("\nThe linked list is empty");
    else
    {
        printf("\nHeader");
        while (ptr != NULL)
        {
            printf("-->%d", ptr->data);
            ptr = ptr->link;
        }
    }
}

void reverse()
{
    NODE *temp1, *temp2, *temp3;
    temp1 = NULL;
    temp2 = head->link;
    if (temp2 == NULL)
    {
        printf("\nThe linked list is empty");
    }
    else
    {
        while (temp2 != NULL)
        {
            temp3 = temp2->link;
            temp2->link = temp1;
            temp1 = temp2;
            temp2 = temp3;
        }
        head->link = temp1;
        printf("\nThe reversal is done");
    }
}

void insert()
{
    if (head == NULL)
        printf("\nNo memory available");
    else
    {
        int m, choice;
        do
        {
            printf("\n\n1.Insertion at front");
            printf("\n2.Insertion in between");
            printf("\n3.Insertion at end");
            printf("\n4.Exit");
            printf("\nEnter your choice:");
            scanf("%d", &choice);

            if (choice != 4)
            {
                printf("\nEnter the element to be inserted:");
                scanf("%d", &m);
            }

            switch (choice)
            {
            case 1:
                insertfront(m);
                break;
            case 2:
                insertbetween(m);
                break;
            case 3:
                insertend(m);
                break;
            }

        } while (choice != 4);
    }
}

void insertfront(int l)
{
    NODE *ptr = Getnode();
    ptr->data = l;
    ptr->link = head->link;
    head->link = ptr;
    printf("\nA new node is inserted at front\n");
}

void insertbetween(int l)
{
    NODE *ptr = Getnode();
    ptr->data = l;
    NODE *ptr2 = head;
    int pos;
    printf("\nEnter the key:");
    scanf("%d", &pos);
    while (ptr2->data != pos && ptr2->link != NULL)
    {
        ptr2 = ptr2->link;
    }
    if (ptr2->data != pos)
    {
        printf("\nThe key is not found.Inserted at the end");
        ptr2->link = ptr;
    }
    else
    {
        ptr->link = ptr2->link;
        ptr2->link = ptr;
        printf("\nA new node is inserted in between");
    }
}

void insertend(int l)
{
    NODE *ptr = Getnode();
    ptr->data = l;
    NODE *ptr2 = head;
    while (ptr2->link != NULL)
    {
        ptr2 = ptr2->link;
    }
    ptr2->link = ptr;
    printf("\nThe element is inserted at the end");
}

void delete ()
{
    int p;
    do
    {
        if (head->link == NULL)
        {
            printf("\nThe Linked List is empty");
            break;
        }

        printf("\n\n1.Delete at front");
        printf("\n2.Deletion in between");
        printf("\n3.Deletion at end");
        printf("\n4.Exit");
        printf("\nEnter your choice:");
        scanf("%d", &p);
        switch (p)
        {
        case 1:
            deletefront();
            break;
        case 2:
            deletebetween();
            break;
        case 3:
            deleteend();
            break;
        }
    } while (p != 4);
}

void deletefront()
{
    NODE *temp1;
    NODE *temp2;
    temp1 = head->link;
    head->link = temp1->link;
    int data = temp1->data;
    free(temp1);
    temp1 = NULL;
    printf("\nNode with data %d at the front is deleted", data);
}

void deletebetween()
{
    NODE *temp1;
    NODE *temp2;

    int key, f = 0;
    printf("\nEnter the key:");
    scanf("%d", &key);
    temp1 = head;
    while (temp1->link != NULL)
    {
        temp2 = temp1;
        temp1 = temp1->link;
        if (temp1->data == key)
        {
            temp2->link = temp1->link;
            int data = temp1->data;
            free(temp1);
            temp1 = NULL;
            f = 1;
            printf("\nNode with data %d is deleted", data);
            break;
        }
    }
    if (f == 0)
        printf("\nThe key not found");
}

void deleteend()
{
    NODE *temp1;
    NODE *temp2;

    temp1 = head;
    while (temp1->link != NULL)
    {
        temp2 = temp1;
        temp1 = temp1->link;
    }
    temp2->link = NULL;
    int data = temp1->data;
    free(temp1);
    temp1 = NULL;
    printf("\nNode with data %d at the end is deleted", data);
}
