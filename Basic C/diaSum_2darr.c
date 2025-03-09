//To find sum of diagonal elements in a 2D array 
#include<stdio.h>
int main()
{
    int r,c;
    printf("Enter size of matrix");
    scanf("%d%d",&r,&c);
    int a[r][c],i,j,sum=0;
    printf("Enter elements to the array");

    for (i = 0; i < r; i++)
    { 
        for ( j = 0; j < c; j++)
        {
           scanf("%d",&a[i][j]);
        }
    }
   // int t[c][r],count=0;
     for (i = 0; i < r; i++)
    {  
        for ( j = 0; j < c; j++)
        {
            if(i==j||i+j==c-1)
            sum=sum+a[i][j];
        }
    }
    
    printf("Sum of diagonal elements is %d",sum);
    

}