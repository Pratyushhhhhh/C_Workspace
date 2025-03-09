//To check if the matrices are symmetric or not
#include<stdio.h>
int main()
{
    int r,c;
    printf("Enter size of matrix");
    scanf("%d%d",&r,&c);
    int a[r][c],i,j;
    printf("Enter elements to the array");

    for (i = 0; i < r; i++)
    { 
        for ( j = 0; j < c; j++)
        {
           scanf("%d",&a[i][j]);
        }
    }
    int t[c][r],count=0;
    for (i = 0; i < r; i++)
    {  
        for ( j = 0; j < c; j++)
        {
            t[j][i]=a[i][j];
        }
       
    }
     for (i = 0; i < r; i++)
    {  
        for ( j = 0; j < c; j++)
        {
            if(t[i][j]==a[i][j])
            count++;
        }
    }
    if (count==r*c)
    printf("Symmetric matrix");
    else
    printf("Not Symmetric matrix");

}