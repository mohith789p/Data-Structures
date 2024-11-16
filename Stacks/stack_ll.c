/*c-program of stacks using linked lists*/

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node NODE;

void insert_front(int);
void delete_front();
void display();
NODE *head = NULL;
int main()
{
    int choice, item, pos;
    while(1)
    {
        printf("\nMENU\n");
        printf("1. Insert \n");
        printf("2. Delete \n");
        printf("3. Display\n");
        printf("4. Exit\n");
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

void insert_front(int item)
{
    NODE* temp;
    temp = (NODE *)malloc(sizeof(NODE));
    temp->data = item;
    temp->next = head;
    head = temp;
}

void delete_front()
{
    NODE *temp;
    if(head==NULL)
    {
        printf("stack is empty\n");
    }
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
        printf("stack is empty\n");
    else
    {
        printf("stack content:\n");
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp = temp-> next;
        }
    }
    printf("\n");
}