//To Merge 2 sorted arrays into another sorted array
//incomplete
#include<stdio.h>
#define m 100
void sorted(int[][m],int,int);
int main()
{
    int r,c,rr,cc;
    printf("Enter size of 1st matrix");
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
    sorted(a,r,c);
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
    sorted(b,rr,cc);

}
void sorted(int x[][m], int rr, int cc) {
    int row, i, j, t;
    for (row = 0; row < rr; row++) {
        for (i = 0; i < cc - 1; i++) {
            for (j = i + 1; j < cc; j++) {
                if (x[row][i] > x[row][j]) {
                    t = x[row][i];
                    x[row][i] = x[row][j];
                    x[row][j] = t;
                }
            }
        }
    }
}
