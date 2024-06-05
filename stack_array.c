/*C Program to implement Stack using Arrays*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int stack[MAX], top=-1;
void push(int);
void pop();
void display();
int main()
{
    int choice, item;
    char ch;
    while(1)
    {
        printf("\nMENU\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the element: ");
            scanf("%d",&item);
            push(item);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid Choice\n");
        }
    }
}
void push(int item)
{
    if(top==MAX-1)
        printf("Stack Overflow\n");
    else
    {
        stack[++top]= item;
        printf("Element inserted\n");
    }
}
void pop()
{
    if(top==-1)
        printf("Stack Underflow\n");
    else
    {
        printf("Element deleted: %d\n", stack[top--]);
    }
}
void display()
{
    int i;
    if(top==-1)
        printf("Stack empty\n");
    else
    {
        printf("Stack Content:\n");
        for(i=top; i>=0; i--)
            printf("%d ",stack[i]);
    }
    printf("\n");
}