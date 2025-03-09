//Count No of characters
#include<stdio.h>
int main()
{
    FILE *p;
    p=fopen("word.txt","r+");
    char ch;
    int count=0;
    if(p==NULL){
        printf("error");
        return 0;
    }
    else{
   while((ch=fgetc(p))!=EOF)
        count++;
    printf("No of characters are %d",count);
    fclose(p);
    }
}