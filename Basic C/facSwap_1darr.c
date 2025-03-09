#include<stdio.h>
int main()
{
     int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int a[n], i,j,p=1;
    printf("Enter elements into the array: ");
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++) 
    {   p=1;
        for(j=1;j<=a[i];j++)
        {
           p=p*j;
        }
        a[i]=p;
       
    }
    printf("New array is");
    for (i = 0; i < n; i++) 
    {
        printf("%d ", a[i]);
    }
}