//To print upper and lower triangle
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
    printf("Upper Triangle:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (i <= j) {
                printf("%d ", a[i][j]);
            } else {
                printf("  "); 
            }
        }
        printf("\n");
    }

    printf("Lower Triangle:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (i >= j) {
                printf("%d ", a[i][j]);
            } else {
                printf("  "); 
            }
        }
        printf("\n");
    }

    return 0;
}