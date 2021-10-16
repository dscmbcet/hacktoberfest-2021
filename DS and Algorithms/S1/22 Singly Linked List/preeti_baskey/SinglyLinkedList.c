#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};
struct node* root = NULL;
void append()
{
    int ele;
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter element :- ");
    scanf("%d",&ele);
    temp -> data = ele;
    temp ->link = NULL;
    if(root == NULL)
    {
        root = temp;
        printf("%d inserted successfully",ele);
    }
    else
    {
        struct node *p;
        p = root;
        while(p->link != NULL)
        {
            p = p -> link;
        }
        p -> link = temp;
       printf("%d inserted successfully",ele);
    }
}
void length()
{
    int count = 0;
    struct node *temp;
    temp = root;
    while(temp != NULL)
    {
        count = count + 1;
        temp = temp -> link;
    }
    printf("Length is :- %d",count);
}
void inFirst()
{
    int ele;
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter element :- ");
    scanf("%d",&ele);
    temp -> data = ele;
    temp -> link = root;
    root = temp;
    printf("%d inserted successfully",ele);
}
void display()
{
    struct node* p;
    p = root;
    if(root == NULL)
    {
        printf("No elements");
    }
    else
    {
        while(p != NULL)
        {
            printf("%d", p -> data);
            printf(" ");
            p = p -> link;
        }
    }
}
void atMiddle()
{
    int data, findEle;
    struct node *temp, *p, *q;;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter data :- ");
    scanf("%d",&data);
    temp -> data = data;
    p = root;
    printf("Enter element after which you want to insert :- ");
    scanf("%d",&findEle);
    while(p -> data != findEle)
    {
        p = p -> link;
    }
    q = p -> link;
    temp -> link = q;
    p -> link = temp;
    printf("%d inserted successfully",data);
}
int main()
{
        int choice;
        do
        {
            printf("\n");
            printf("\n1.Append\n2.Length\n3.In First\n4.Display\n5.At Middle\n6.Exit\n");
            printf("Enter your choice :- ");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1: append(); break;
                case 2: length(); break;
                case 3: inFirst(); break;
                case 4: display(); break;
                case 5: atMiddle(); break;
                case 6: exit(0);
                default: printf("Wrong input");
            }
        }while(choice != 6);
    getch();
}

