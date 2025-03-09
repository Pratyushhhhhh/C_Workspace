#include<stdio.h>
int main()
{
    int n,i,j=0,k=0;
    printf("Enter the size of array");
    scanf("%d",&n);
    int a[n],b[n],c[n];
    printf("Enter elements to the array");
    for(i=0;i<n;i++)
    {
        scanf("%d ",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        if(a[i]%2==0)
        {
            b[j]=a[i];
            j++;
        }
        else
        {
            c[k]=a[i];
            k++;
        }
    }
    printf("\nEven elements are: ");
    for(i=0;i<j;i++)    
    {        
        printf("%d ",b[i]);    
    }      
    printf("\nOdd elements are: ");     
    for(i=0;i<k;i++)
    {        
        printf("%d ",c[i]);    
    }     
    return 0;
}
