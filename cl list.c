/* C program on Circular Linked List*/
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* next;
};

struct node* last = NULL;
void insert_front(int item)
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp-> data = item;
    if (last == NULL) {
        temp->next = temp;
        last = temp;
    }
    else {
        temp->next = last->next;
        last->next = temp;
    }
}
void insert_last(int item)
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = item;

    if (last == NULL) {
        temp->next = temp;
        last = temp;
    }
    else {
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}
void delete_front()
{
    struct node* temp;
    if (last == NULL)
        printf("List is empty.\n");
    else if (last->next == last)
    {
        temp = last;
        last = NULL;
        printf("Deleted element: %d\n", temp->data);
        free(temp);
    }
    else {
        temp = last->next;
        printf("Deleted element: %d\n", temp->data);
        last->next = temp->next;
        free(temp);
    }
}
void delete_last()
{
    struct node* cur, *temp;
    if (last == NULL)
        printf("List is empty\n");
    else if (last->next == last)
    {
        temp = last;
        last = NULL;
        printf("Deleted element: %d\n", temp->data);
        free(temp);
    }
    else
    {
        cur = last->next;

        while (cur->next != last)
            cur = cur->next;
        temp = cur->next;
        cur->next = last->next;
        last = cur;
        printf("Deleted element: %d\n",temp->data);
        free(temp);
    }
}
void display()
{
    struct node *cur;
    if(last==NULL) 
        printf("List is empty\n");
    else
    {
        cur=last->next;
        printf("List content:\n");
        while(cur!=last)
        {
            printf("%d ",cur->data);
            cur=cur->next;
        }
        printf("%d",last->data);
    }
}

int main()
{
    int choice, item, pos;
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