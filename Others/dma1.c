#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i=0,j=0,k=0;
    
    int *a=malloc(5*sizeof(int));
    printf("Enter elements to the array");
    for(i=0;i<5;i++)
    {
        scanf("%d ",(a+1));
    }
    for(i=0;i<5;i++)
    {
        if(*(a+1)%2==0)
        {
            j++;
        }
        else
        {
            k++;
        }
    }
    printf("\nEven elements are: %d ",j);
    printf("\nOdd elements are: %d ",k);     
    return 0;
}