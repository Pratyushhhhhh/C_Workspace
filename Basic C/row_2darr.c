
#include<stdio.h>
int main()
{
    int r,c;
    printf("Enter size of 2D array");
    scanf("%d%d",&r,&c);
    int a[r][c],i,j,p=1;
    printf("Enter elements to 2D array");

    for (i = 0; i < r; i++)
    { 
        for ( j = 0; j < c; j++)
        {
           scanf("%d",&a[i][j]);
        }
    }
    int row;
    printf("Enter row");
    scanf("%d",&row);
    for (i = 0; i < c; i++)
    { 
        p=p*a[row][i];
    }
    printf("product of row is %d",p);
}
      


