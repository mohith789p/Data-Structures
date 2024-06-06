/* Program of Circular Queue using Array */
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue[MAX];
int front=-1, rear=-1;
void insert(int);
void delete();
void display();
int main()
{
    int choice, item;
    while(1)
    {
        printf("\nMENU\n");
        printf("1.insert\n2.delete\n3.display\n4.exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter element:");
            scanf("%d",&item);
            insert(item);
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}
void insert(int item)
{
    if( (rear+1)%MAX == front)
        printf("Queue is full\n");
    else
    {
        rear = (rear+1)%MAX;
        queue[rear] = item;
        if(front==-1)
            front=0;
    }
}
void delete()
{
    if(front==-1)
        printf("Queue is empty\n");
    else
    {
        printf("Deleted element: %d\n", queue[front]);
        if(front==rear)
            front=rear=-1;
        else
            front=(front+1)%MAX;
    }
}
void display()
{
    int i;
    if(front==-1)
        printf("Queue is empty\n");
    else
    {
        printf("Queue content:\n");
        if(front<=rear)
        {
            for(i=front; i<=rear; i++)
                printf("%4d", queue[i]);
        }
        else
        {
            for(i=front; i<=MAX-1; i++)
                printf("%4d", queue[i]);
            for(i=0; i<=rear; i++)
                printf("%4d", queue[i]);
        }
    }
}