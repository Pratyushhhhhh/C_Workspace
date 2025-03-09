//Sorting of 2D Array using function
#include <stdio.h>
#define m 100

void sorted(int[][m], int, int);

int main() {
    int r, c;
    printf("Enter number of rows and columns of the matrix: ");
    scanf("%d%d", &r, &c);
    int a[r][c], i, j;
    printf("Enter elements into the array: ");

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    sorted(a, r, c); 
    printf("Sorted matrix:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void sorted(int x[][m], int rr, int cc) 
{
    int row, i, j, t;
    for (row = 0; row < rr; row++)
     {
        for (i = 0; i < cc - 1; i++)
         {
            for (j = i + 1; j < cc; j++) 
            {
                if (x[row][i] > x[row][j]) 
                {
                    t = x[row][i];
                    x[row][i] = x[row][j];
                    x[row][j] = t;
                }
            }
        }
    }
}
