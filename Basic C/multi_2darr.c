#include<stdio.h>
int main()
{
    int r,c,rr,cc;
    printf("Enter size of 1st matrix");
    scanf("%d%d",&r,&c);
    int a[r][c],i,j,k;
    printf("Enter elements to the array");

    for (i = 0; i < r; i++)
    { 
        for ( j = 0; j < c; j++)
        {
           scanf("%d",&a[i][j]);
        }
    }
     printf("Enter size of 2nd matrix");
    scanf("%d%d",&rr,&cc);
    int b[rr][cc];
    printf("Enter elements to the array");

    for (i = 0; i < rr; i++)
    { 
        for ( j = 0; j < cc; j++)
        {
           scanf("%d",&b[i][j]);
        }
    }
    int ab[r][cc];
    if (c==rr)
    for (i = 0; i < r; i++)
    {  
        for ( j = 0; j < cc; j++)
        {
            ab[i][j]=0;
            for(k=0;k<rr;k++)
            {
                ab[i][j]=ab[i][j]+a[i][k]*b[k][j];
            }
        }
       
    }
     for (i = 0; i < r; i++)
    {  
        for ( j = 0; j < cc; j++)
        {
            printf("%d ",ab[i][j]);
        }
        printf("\n");
    }

}