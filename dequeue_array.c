/* Program on DEQueue  using Arrays*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int dequeue[MAX];
int front=-1, rear=-1;

void insert_front(int item)
{
    if( (rear+1)%MAX == front)
        printf("DEQueue is full\n");
    else if(front==-1)
    {
        front=rear=0;
        dequeue[front]=item;
    }
    else if(front==0)
    {
        front=MAX-1;
        dequeue[front]=item;
    }
    else
    {
        front = front-1;
        dequeue[front] = item;
    }
}
void insert_last(int item)
{
    if( (rear+1)%MAX == front)
        printf("DEQueue is full\n");
    else if(front==-1)
    {
        front = rear = 0;
        dequeue[rear] = item;
    }
    else
    {
        rear = (rear+1)%MAX;
        dequeue[rear] = item;
    }
}
void delete_front()
{
    if(front==-1)
        printf("DEQueue is empty\n");
    else
    {
        printf("Deleted element: %d\n",dequeue[front]);
        if(front == rear)
            front = rear = -1;
        else
            front = (front+1)%MAX;
    }
}
void delete_last()
{
    if(front==-1)
        printf("DEQueue is empty\n");
    else
    {
        printf("Deleted element: %d\n",dequeue[rear]);
        if(front==rear)
            front = rear = -1;
        else if(rear==0)
            rear = MAX-1;
        else
            rear=rear-1;
    }
}

void display()
{
    int i;
    if(front==-1) printf("DEQueue is empty\n");
    else
    {
        printf("DEQueue content:\n");
        if(front<=rear)
        {
            for(i=front; i<=rear; i++)
                printf("%4d", dequeue[i]);
        }
        else
        {
            for(i=front; i<=MAX-1; i++)
                printf("%4d", dequeue[i]);
            for(i=0; i<=rear; i++)
                printf("%4d", dequeue[i]);
        }
    }
}

int main()
{
    int choice, item;
    while(1)
    {
        printf("\nMENU\n");
        printf("1.insert front\n2. insert last\n");
        printf("3.delete front\n4.delete last\n5.display\n6.exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter element:");
            scanf("%d",&item);
            insert_front(item);
            break;
        case 2:
            printf("Enter element:");
            scanf("%d",&item);
            insert_last(item);
            break;
        case 3:
            delete_front();
            break;
        case 4:
            delete_last();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}