//WAC to input n integers in the file, separate odd and even integers in separate file and display the content of even file
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    FILE *fp, *fpeven, *fpodd;
    int num,n,i,co=0,ce=0;
    printf("Enter the limit: ");
    scanf("%d",&n);
    
    fp=fopen("sample.txt","w");
    if(fp==NULL) 
    {
        printf("File Error.");
        exit(1);
    }
    
    printf("\nEnter content of the file:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        fputc(num,fp);
    }
    fclose(fp);
    
    fp=fopen("sample.txt","r");
    fpeven=fopen("even.txt","w");
    fpodd=fopen("odd.txt","w");
    if(fp==NULL||fpeven==NULL||fpodd==NULL) 
    {
        printf("File Error.");
        exit(1);
    }
    
    for(i=0;i<n;i++)
    {
        num=getc(fp);
        if(num%2==0)
        {
            putc(num,fpeven);
            ce++;
        }
        else
        {
            putc(num,fpodd);
            co++;
        }
    }
    fclose(fp);
    fclose(fpodd);
    fclose(fpeven);
    
    
    fpeven=fopen("even.txt","r");
    if(fpeven==NULL) 
    {
        printf("File Error.");
        exit(1);
    }
    for(i=0;i<ce;i++)
    {
       num=getc(fpeven);
       printf("%d ",num);
    }
    fclose(fpeven);
    
    return 0;
}