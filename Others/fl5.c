//to append a file
#include<stdio.h>
int main()
{
    FILE *p;
    char ch[100];
    printf("enter a string");
    fgets(ch,100,stdin);
    p=fopen("word.txt","a+");
    if(p==NULL){
        printf("error");
        return 0;
    }
    else{
    fprintf(p,"   %s",ch);
    fclose(p);
    }
}