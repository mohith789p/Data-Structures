/*C Program to evaluate the given Postfix Expression*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 20
int stack[MAX];
int top=-1;
void push(int item)
{
    if(top==MAX-1)
    {
        printf("Stack Overflow\n");
        exit(0);
    }
    stack[++top]=item;
}
int pop()
{
    int item;
    if(top==-1)
    {
        printf("Stack Underflow\n");
        exit(0);
    }
    item = stack[top];
    top--;
    return item;
}
int isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
int main()
{
    char postfix[20], ch;
    int op1, op2, i, r;
    printf("Enter the postfix exp:\n");
    scanf("%s", postfix);
    for(i=0; postfix[i]; i++)
    {
        ch = postfix[i];
        if(isdigit(ch))
            push(ch-'0');
        else
        {
            op2 = pop();
            op1 = pop();
            switch(ch)
            {
            case '+':
                r=op1 + op2;
                break;
            case '-':
                r = op1 - op2;
                break;
            case '*':
                r = op1 * op2;
                break;
            case '/':
                r = op1 / op2;
                break;
            case '%':
                r = op1 % op2;
                break;
            }
            push(r);
        }
    }
    r = pop();
    if(!isEmpty())
        printf("Invalid Postfix Expression\n");
    else
        printf("Result = %d\n", r);
    return 0;
}