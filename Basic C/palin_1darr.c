#include <stdio.h>

int pal(int x[], int size) {
    for (int i = 0; i < size / 2; i++) 
    {
        if (x[i] != x[size - 1 - i]) 
            return 0;
    }
    return 1;
}

int main()
{
     int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int a[n], i;
    printf("Enter elements into the array: ");
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &a[i]);
    }

    if (pal(a,n)==1) 
        printf("The array is a palindrome.\n");
     else 
        printf("The array is not a palindrome.\n");

    return 0;
}
