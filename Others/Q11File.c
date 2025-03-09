#include<stdio.h>
#include<string.h>
int main()
{
    FILE *p,*q;
    p=fopen("Data.txt","r");
    q=fopen("Del.txt","w");
    char ch[100];
    while(fscanf(p,"%s",ch)!=EOF) {
        if(strcmp(ch,"a")==0||strcmp(ch,"an")==0||strcmp(ch,"the")==0) {
            fprintf(p," ");
        }
        else {
            fprintf(q,"%s",ch);
            fprintf(q,"%s"," ");
        }
    }
    fclose(p);
    fclose(q);
    printf("Words 'a', 'the', 'an' removed from Data.txt and written to Del.txt successfully.\n");
    return 0;



}



/*#include<stdio.h>
#include<string.h>
int main() {
    FILE *ptr1=fopen("Data.txt","r");
    FILE *ptr2=fopen("Del.txt","w");
    char word[100];
    printf("*****************************INPUT********************************\n"); 
    while(fscanf(ptr1,"%s",word)!=EOF) {
        if(strcmp(word,"a")==0||strcmp(word,"an")==0||strcmp(word,"the")==0) {
            fprintf(ptr2," ");
        }
        else {
            fprintf(ptr2,"%s",word);
            fprintf(ptr2,"%s"," ");
        }
    }
    printf("*****************************OUTPUT********************************\);
    fclose(ptr1);
    fclose(ptr2);
    printf("Words 'a', 'the', 'an' removed from Data.txt and written to Del.txt successfully.\n");
    return 0;
}


*/