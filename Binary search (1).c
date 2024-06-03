/* Program on Binary Search RECURSIVE*/

#include<stdio.h>
int a[30], n, key;
int binsearch(int low , int high) {
    if(low > high)
        return -1;
    else 
    {
        int mid = (low + high) / 2;
        if(key == a[mid])
            return mid;
        else if(key < a[mid])
            return binsearch(low, mid - 1);
        else
            return binsearch(mid + 1, high);
    }
}

int main() {
    int i, s;
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter the Key: ");
    scanf("%d", &key);
    s = binsearch(0, n - 1);
    if(s == -1)
        printf("Key is not Found.");
    else
        printf("Key is found at %d index.", s);
}


