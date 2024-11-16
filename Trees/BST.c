/*C program to implement BST*/
#include<stdio.h>
#include<stdlib.h>
struct node {

    struct node* lchild;
    int data;
    struct node* rchild;
};
typedef struct node NODE;
NODE* root=NULL;

NODE* insert(NODE* root,int item) {
    if(root==NULL) {
        root=(NODE*)malloc(sizeof(NODE));
        root->data=item;
        root->lchild=NULL;
        root->rchild=NULL;
    }
    else if(item<root->data) {
        root->lchild=insert(root->lchild,item);
    }
    else {
        root->rchild=insert(root->rchild,item);
    }
    return root;
}

void inorder(NODE* root) {
    if(root!=NULL) {
        inorder(root->lchild);
        printf("%4d",root->data);
        inorder(root->rchild);
    }
}

void preorder(NODE* root) {
    if(root!=NULL) {
        printf("%4d",root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

void postorder(NODE* root) {
    if(root!=NULL) {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%4d",root->data);
    }
}

int count(NODE* root) {
    if(root==NULL) {
        return 0;
    }
    else {
        return (count(root->lchild)+count(root->rchild)+1);
    }
}
int main() {
    int item,ch;
    do {
        printf("Enter the Element: ");
        scanf("%d",&item);
        root=insert(root,item);
        printf("press 1 to continue: ");
        scanf("%d",&ch);
    } while(ch==1);
    printf("no. of Nodes: %d\n",count(root));
    printf("Inorder: ");
    inorder(root);
    printf("\n");
    printf("Preorder: ");
    preorder(root);
    printf("\n");
    printf("Postorder: ");
    postorder(root);
    printf("\n");
}