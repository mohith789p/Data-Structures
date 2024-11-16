/*Program of Queue using Linked List*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node NODE;
void insert_last(int);
void delete_front();
void display();
NODE *head = NULL;
int main()
{
    int choice, item;
    while(1)
    {
        printf("\nMENU\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the element to be inserted");
            scanf("%d",&item);
            insert_last(item);
            break;
        case 2:
            delete_front();
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
void insert_last(int item)
{
    NODE *temp, *cur;
    temp = (NODE *)malloc(sizeof(NODE));
    temp->data = item;
    if(head==NULL)
        head=temp;
    else
    {
        cur=head;
        while(cur->next!=NULL)
        {
            cur = cur->next;
        }
        cur->next = temp;
    }
    temp->next = NULL;
}
void delete_front()
{
    NODE *temp;
    if(head==NULL)
        printf("Queue is empty\n");
    else
    {
        temp = head;
        head = head->next;
        printf("Element deleted: %d\n",temp->data);
        free(temp);
    }
}
void display()
{
    NODE *temp=head;
    if(head==NULL)
        printf("Queue is empty\n");
    else
    {
        printf("Queue content:\n");
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp = temp-> next;
        }
    }
}