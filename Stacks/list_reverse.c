/*C program to reverse the elements in list using stack.*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int stack[MAX],top=-1;

void push(int item)
{
    if(top==MAX-1)
        printf("Stack Overflow\n");
    else
        stack[++top]= item;
}

int pop()
{
    if(top==-1)
    {
        printf("Stack Underflow\n");
        exit(0);
    }
    else
        return  stack[top--];
}


struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
void create();
void reverse();
void display();
NODE *head = NULL;

int main()
{
    int choice, item, pos;
    create();
    display();
    reverse();
    display();
}

void create()
{
    NODE *cur, *temp;
    int ch;
    int item;
    do
    {
        printf("Enter the element: ");
        scanf("%d",&item);
        temp = (NODE *)malloc(sizeof(NODE));
        temp->data = item;
        if(head==NULL)
        {
            head = cur = temp;
        }
        else
        {
            cur->next = temp;
            cur = temp;
        }
        printf("Press 1 to continue: ");
        scanf("%d",&ch);
    } while(ch==1);
    cur->next = NULL;
}

void reverse()
{
    NODE  *cur=head;
    while(cur!=NULL)
    {
        push(cur->data);
        cur=cur->next;
    }
    cur=head;
    while(cur!=NULL)
    {
        cur->data=pop();
        cur=cur->next;
    }
}
void display()
{
    NODE *temp=head;
    if(head==NULL)
        printf("List is empty\n");
    else
    {
        printf("List content:\n");
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp = temp-> next;
        }
    }
    printf("\n");
}