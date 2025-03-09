//to compare contents of 2 files
#include<stdio.h>
int main()
{
    FILE *p1,*p2;
    char a[100],ch1,b[100],ch2;
    int c=0,c1=0;
    p1=fopen("file1.txt","w+");
    p2=fopen("file2.txt","w+");
    if(p1==NULL || p2==NULL){
        printf("Error");
        return 0;
    }
    else{ 
    fgets(a,100,stdin);
    fgets(b,100,stdin);
    fprintf(p1,"%s",a);
    fprintf(p2,"%s",b);
    rewind(p1);
    rewind(p2);
    while((ch1=fgetc(p1))!=EOF && (ch2=fgetc(p2))!=EOF){
        if(ch1!=ch2)
        c++;
        else
        c1++;
    }  
    if(c==0)
        printf("Equal strings");
    else
        printf("No of differnt charcters are %d",c);
    fclose(p1);
    fclose(p2);

}

}