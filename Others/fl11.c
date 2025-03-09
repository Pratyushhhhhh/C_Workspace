
#include<stdio.h>
int main()
{
    FILE *p1,*p2;
    char a[100],ch[256],b[100],ch2,ch3;
    int c=0,c1=0;
    p1=fopen("file1.txt","w+");
    p2=fopen("file2.txt","w+");
    if(p1==NULL || p2==NULL){
        printf("Error");
        return 0;
    }
    else{ 
    fgets(a,100,stdin);
    fprintf(p1,"%s",a);
    rewind(p1);
    printf("Enter word to be searched")
    char sr[100];
    fgets(sr,100,stdin);

while ((ch = fgetc(p)) != EOF) {
        if (ch == '\n') {
            n++; // Increment line number
        }
        if (ch == sr[0]) { // Check if first character matches
            fseek(p, -1, SEEK_CUR); // Move file pointer back by one character
            if (fgets(c, sizeof(c), p1) != NULL) {
                if (strstr(c, sr) != NULL) {
                   ch3='h';
                   fprintf(p,"%s",ch3);
                    break;
                }
            }
        }
    }


       
    }  
    if(c==0)
        printf("Equal strings");
    else
        printf("No of differnt charcters are %d",c);
    fclose(p1);
    fclose(p2);

}

