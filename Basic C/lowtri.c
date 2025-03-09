#include<stdio.h>
int main() 
{
    int r,c,i,j,s=0;
    printf("Enter the range of Matrics");
    scanf("%d %d",&r,&c);
    printf("Enter values to the array");
    int a[r][c];
    for(i=0; i<r; i++) 
    {
        for(j=0; j<c; j++) 
        {
            scanf("%d",&a[i][j]);
        }
    }

    printf("\nThe Given array is: \n");
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++) 
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

    printf("The elements being summed of the lower triangular matrix are: ");
    for(i=0; i<r-1; i++) {
        for(j=i+1;j<c; j++) 
        { 
            printf("%d ", a[j][i]);
            s=s+a[j][i];
        }
    }

    printf("\n The Sum of the lower triangular Matrix Elements are: %d",s);
    
    return 0;
}
