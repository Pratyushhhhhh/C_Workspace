//Count No of characters
#include<stdio.h>
int main()
{
    FILE *p;
    p=fopen("data.txt","r+");
    char ch;
    int count=0;
    if(p==NULL){
        printf("error");
        return 0;
    }
    else{
   while((ch=fgetc(p))!=EOF)
    {
        if(ch==' '||ch=='\0')
            count++;
    }
    printf("No of words are %d",count);
    fclose(p);
    }
}