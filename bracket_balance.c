/*C Program to check whether the given expression is having balanced brackets*/
#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#define MAX 20
char stack[MAX];
int top = -1;
void push(char item) {
    stack[++top] = item;
}
int isMatch(char ch1, char ch2) {
    if(ch1=='(' && ch2==')') return 1;
    else if(ch1=='[' && ch2==']') return 1;
    else if(ch1=='{' && ch2=='}') return 1;
    else return 0;
}
char pop() {
    char ch;
    if(top==-1) {
        printf("Not balanced\n");
        exit(0);
    }
    ch = stack[top];
    top--;
    return ch;
}
int isEmpty() {
    return (top==-1);
}
int main() {
    char exp[MAX], ch, temp;
    int i;
    printf("Enter the expression:\n");
    scanf("%s", exp);
    for(i=0; exp[i]!='\0'; i++) {
        ch = exp[i];
        if(ch=='(' || ch=='[' || ch=='{')
            push(ch);
        else {
            temp = pop();
            if(!isMatch(temp, ch)) {
                printf("Not balanced\n");
                exit(0);
            }
        }
    }
    if(isEmpty())
        printf("Balanced\n");
    else
        printf("Not balanced\n");
    return 0;
}