/*Program of queues using arrays*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue[MAX];
int front=-1,rear=-1;
void insert(int item){
        if(rear==MAX-1){
                printf("Queue is full\n");
        }
        else{
                if(front==-1)
                        front=0;
                queue[++rear]=item;
        }
}
void delete(){
        if(front==-1){
                printf("Queue is empty");
        }
        else{
                printf("Deleted element: %d",queue[front]);
                if(front==rear)
                        front=rear=-1;
                else 
                        front++;

        }
}
void display(){
        if(front==-1){
                printf("Queue is empty");
        }
        else{
                for(int i=front;i<=rear;i++)
                        printf("%4d",queue[i]);
        }
}
int main(){
        int ch,item;

        while(1){
                printf("\n***Menu***");
                printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
                printf("Enter your choice: ");
                scanf("%d",&ch);
                switch(ch){
                        case 1:
                                printf("Enter the element: ");
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
                        default: printf("Enter the valid choice.\n");
                }
        }
}