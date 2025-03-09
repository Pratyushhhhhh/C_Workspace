//To find min value in a each row of 2D array
#include<stdio.h>
int main()
{
    int r,c;
    printf("Enter size of 2D array");
    scanf("%d%d",&r,&c);
    int a[r][c],i,j;
    printf("Enter elements to 2D array");
    for (i = 0; i < r; i++)
    { 
        for ( j = 0; j < c; j++)
        {
           scanf("%d",&a[i][j]);
        }
    }
    int min=a[0][0];
    for (i = 0; i < r; i++)
    {  
        min=a[i][0];
        for ( j = 0; j < c; j++)
        {
            if(min>a[i][j])
            min=a[i][j];
        }
        printf("Min element in the row %d is %d\n",i+1,min);
    }
}