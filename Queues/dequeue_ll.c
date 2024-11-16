/* Program on DEQueue using linked list */
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node NODE;
void insert_front(int);
void insert_last(int);
void delete_front();
void delete_last();
void display();
NODE *head = NULL;
int main()
{
    int choice, item;
    while(1)
    {
        printf("\nMENU\n");
        printf("1. Insert front\n");
        printf("2. Insert Last\n");
        printf("3. Delete front\n");
        printf("4. Delete Last\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d",&item);
            insert_front(item);
            break;
        case 2:
            printf("Enter the element to be inserted: ");
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

void insert_front(int item)
{
    NODE* temp;
    temp = (NODE *)malloc(sizeof(NODE));
    temp->data = item;
    temp->next = head;
    head = temp;
}
void insert_last(int item)
{
    NODE *temp, *cur;
    temp = (NODE *)malloc(sizeof(NODE));
    temp->data = item;
    if(head==NULL)
    {
        head=temp;
    }
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
    {
        printf("DEQueue is empty\n");
    }
    else
    {
        temp = head;
        head = head->next;
        printf("Element deleted: %d\n",temp->data);
        free(temp);
    }
}
void delete_last()
{
    NODE *temp, *cur;
    if(head==NULL) 
    printf("DEQueue is empty\n");
    else if(head->next==NULL) 
    {
        temp = head;
        head = NULL;
        printf("Deleted element: %d\n",temp->data);
        free(temp);
    }
    else 
    {
        cur = head;
        while(cur->next->next != NULL)
        {
            cur = cur->next;
        }
        temp = cur->next;
        cur->next = NULL;
        printf("Deleted element: %d\n",temp->data);
        free(temp);
    }
}

void display()
{
    NODE *temp=head;
    if(head==NULL)
        printf("DEQueue is empty\n");
    else
    {
        printf("DEQueue content:\n");
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp = temp-> next;
        }
    }
    printf("\n");
}