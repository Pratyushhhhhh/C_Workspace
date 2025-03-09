#include<stdio.h>
int sum(int n)
{
    int d=n%10;
    if(n<10)
    return d;
    else 
    return d +sum(n/10);

}
int main()
{
    int num ,s;
    scanf("%d",&num);
    s=sum(num);
    printf("Sum of digit is %d ",s);
    return 0;
}