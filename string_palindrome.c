/*C Program to check whether the given string is Palindrome or not, using Stack*/
#include <stdio.h>
#include <string.h>
#define MAX 20
char stack[MAX];
int top = -1;
void push(char item)
{
    stack[++top] = item;
}
char pop()
{
    return stack[top--];
}
int isPalindrome(char str[])
{
    int i,n;
    n = strlen(str);
    for (i = 0; i < n/2; i++)
    {
        push(str[i]);
    }
    if (n % 2 == 1)
        i= (n/2)+1;
    else
        i=n/2;
    while (str[i] != '\0')
    {
        char item = pop();
        if (item != str[i])
            return 0;
        i++;
    }
    return 1;
}
int main()
{
    char str[MAX];
    printf("Enter the input string:\n");
    scanf("%s", str);
    if (isPalindrome(str))
        printf("Given String is Palindrome");
    else
        printf("Given String is not Palindrome");
    return 0;
}