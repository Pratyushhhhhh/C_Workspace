#include<stdio.h>
int unq(int [],int);
int main()
{
    int n,i;
    printf("Enter the size of array");
    scanf("%d",&n);
    int a[n];
    printf("Enter elements to the array");
    for(i=0;i<n;i++)
    {
        scanf("%d ",&a[i]);
    }
    unq(a,n);
}
int unq (int x[],int n2)
{
    int i,j,count;
    printf("The unique elements found in the array are:");
    for(i=0;i<n2;i++)
    {
        count=0;
        for(j=0;j<n2;j++)
        {
            if (x[i]==x[j])
            count++;
        }
        if(count==1)
        printf("%d \t",x[i]);
    }
}
