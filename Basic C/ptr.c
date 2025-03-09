#include<stdio.h>
int prime_count(int *);
int main()
{   
    int a[10];
    printf("Enter 10 values");
    int *p=a,count=0,i;
    for(i=0;i<10;i++)
        scanf("%d",(p+i));
    count=prime_count(p);
    printf("No. of primr no are %d ",count);
}

int prime_count(int *q)
{
    int x=0,y=0,i,j;
    for(i=0;i<10;i++)
    {   if (*(q + i) < 2) {
            continue;  
        }
        x=0;
        for(j=2;j<*(q+i)-1;j++)
        {
            if(*(q+i)%j==0)
            {
                x=1;
                break;
            }
        }
        if(x==0)
        {
            y++;
        }
    }
    return y;
}