//To find max value in a each row of 2D array
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
    int max=a[0][0];
    for (i = 0; i < r; i++)
    {  
        for ( j = 0; j < c; j++)
        {
            if(max<a[i][j])
            max=a[i][j];
        }
        printf("Max element in the row %d is %d\n",i,max);
        max=0;
    }
    

}