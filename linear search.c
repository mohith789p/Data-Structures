/* Program on Linear Search */
#include<stdio.h>

int linsearch(int a[ ], int n, int key) {
    int i;
    for(i = 0; i < n ; i++)
        if(key == a[i])
            return i;
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
    s = linsearch(a, n, key);
    if(s == -1)
        printf("Key is not Found.");
    else
        printf("Key is found at %d index.", s);
}

