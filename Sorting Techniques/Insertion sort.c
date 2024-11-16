/* Program on Insertion Sort */

#include<stdio.h>

void insertionsort(int a[], int n)
{
    int i, j, item;
    for(i=1; i< n; i++)
    {
        item = a[i];
        for(j=i-1; j>=0 && a[j]>item; j--)
        {
            a[j+1] = a[j];
        }
        a[j+1] = item;
    }
}

int main()
{
    int a[50], i, n;
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for(i=0; i < n; i++)
        scanf("%d", &a[i]);
    insertionsort(a, n);
    printf("Sorted list: \n");
    for(i=0; i < n; i++)
        printf("%4d", a[i]);
}
