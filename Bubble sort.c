/* Program on Bubble Sort */

#include<stdio.h>
void bubblesort(int a[], int n)
{
    int i, j, temp;
    for(i=0; i < n-1 ; i++)
    {
        for(j=0; j < n-1-i ; j++)
        {
            if(a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
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
    bubblesort(a, n);
    printf("Sorted list: \n");
    for(i=0; i < n; i++)
        printf("%4d", a[i]);
}
