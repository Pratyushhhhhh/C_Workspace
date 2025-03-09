#include<stdio.h>
int main()
{
    FILE *p;
    char a[100],b[100],c[200],ch;
    int i=0;
    p=fopen("Blank.txt","w+");
    if(p==NULL){
        printf("Error");
        return 0;
    }
    else{ 
    printf("Enter string");
    fgets(a,100,stdin);
    fprintf(p,"%s",a);
    //r=ftell(p);
   // printf("\n %d \n",r);
    rewind(p);
    while((ch=fgetc(p))!=EOF){
        
        if (ch !=' ')
        {
            b[i++]=ch;
        }
        
    }
    b[i]='\0';
    rewind(p);
    fprintf(p,"%s",b);
    rewind(p);
   // fscanf(p," %s ",c);
    //or we can use 
    fgets(c,200,p);
    printf("%s\n",c);
    fclose(p);
}
}