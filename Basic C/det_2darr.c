//To find determinant of 2x2 2D array 
#include<stdio.h>
int main()
{
    int r,c;
    printf("Enter size of 2D array");
    scanf("%d%d",&r,&c);
    int a[r][c],i,j;
    int p1=1,p=1;
    printf("Enter elements to 2D array");

    for (i = 0; i < r; i++)
    { 
        for ( j = 0; j < c; j++)
        {
           scanf("%d",&a[i][j]);
        }
    }
    for (i = 0; i < r; i++)
    { 
        for ( j = 0; j < c; j++)
        {
            if(i==j)
                p=p*a[i][j];
            else
                p1=p*a[i][j];
        }
    }
    int det=p-p1;
    printf("Determenant is %d",det);
}