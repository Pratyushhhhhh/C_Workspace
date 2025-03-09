//To Merge 2 sorted arrays into another sorted array
//incomplete
#include<stdio.h>
#define m 100
void sorted(int*,int);
int main()
{
    int r,rr;
    printf("Enter size of 1st matrix");
    scanf("%d",&r);
    int a[r],i;
    printf("Enter elements to the array");
    int *p=a;
    for (i = 0; i < r; i++)
    { 
        scanf("%d",(p+i));
    }
    sorted(p,r);
     printf("Enter size of 2nd matrix");
    scanf("%d",&rr);
    int b[rr];
    printf("Enter elements to the array");
    int *q=b;
    int *j=0,k=0;
    for (i = 0; i < rr; i++)
    { 
        scanf("%d",(q+i));   
    }
    sorted(q,rr);
    for(i=0;i<r+rr;i++)
    {
        if(i<r)
        *(j+i)=*(p+i);
        else
        {
            *(j+i)=*(q+k);
            k++;
        }
        printf("%d\n",*(j+i));

    }

}
void sorted(int *x, int rx) 
{
    int row, i, j, t;
    //for (row = 0; row < rx; row++) {
        for (i = 0; i < rx-1; i++) {
            for (j = i + 1; j < rx; j++) {
                if (*(x+i) > *(x+j))
                {
                    t = *(x+i);
                    *(x+i)=*(x+j);
                    *(x+j) = t;
                }
            }
        }
    
}
