/* Program on Binary Search */

#include<stdio.h>

int binsearch(int a[ ], int n, int key) {
    int low, high, mid;
    low = 0;
    high = n-1;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(key == a[mid])
            return mid;
        else if(key < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main() {
    int i, a[30], n, s, key;
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter the Key: ");
    scanf("%d", &key);
    s = binsearch(a, n, key);
    if(s == -1)
        printf("Key is not Found.");
    else
        printf("Key is found at %d index.", s);
}


