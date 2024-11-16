/*C Program to convert infix exp to postfix exp*/

#include<stdio.h>
#include<ctype.h>
char stack[100];
int top = -1;
void push(char item)
{
    stack[++top] = item;
}
char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}
int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/' || x == '%')
        return 2;
    return 0;
}
int main()
{
    char infix[100];
    char ch, x;
    int i;
    printf("Enter the infix exp:\n");
    scanf("%s", infix);
    for(i=0; infix[i]; i++)
    {
        ch = infix[i];
        if(isalnum(ch))
            printf("%c ",ch);
        else if(ch == '(')
            push(ch);
        else if(ch == ')')
        {
            while((x = pop()) != '(')
                printf("%c ", x);
        }
        else
        {
            while(priority(stack[top]) >= priority(ch))
                printf("%c ",pop());
            push(ch);
        }
    }
    while(top != -1)
    {
        printf("%c ",pop());
    }
    return 0;
}