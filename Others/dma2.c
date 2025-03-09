#include<stdio.h>
#include<stdlib.h>

int main(){
	int i, n, *p, index;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	p=(int*)malloc(n*sizeof(int));
	if(p==NULL)
    {
		printf("Memory Allocation Failed");
		return 0;
	}
	printf("Enter the elements of the array:\n");
	for(i=0;i<n;i++)
    {
        printf("Element %d:",i+1);
		scanf("%d",p+i);
    }
	printf("Enter the index from where the array is to be reversed: ");
	scanf("%d",&index);
	for(i=0;i<(n-index)/2;i++)
    {
        int temp = *(p + i + index);
        *(p + i + index) = *(p + n - 1 - i);
        *(p + n - 1 - i) = temp;
    }
    printf("Reversed array:");
	for(i=0;i<n;i++)
		printf("%d ",*(p+i));
	free(p);	
	return 0;
}


