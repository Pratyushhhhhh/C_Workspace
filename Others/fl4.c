//count vowels consonants special charatcters
#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *p;
    p = fopen("Word.txt", "w+");
    int cc=0,cv=0,cs=0;
    char a[100],ch;
    char c[100];
    if (p == NULL) {
        printf("Error opening file\n");
        return 0;
    } else {
        printf("Enter a string: ");
        fgets(a,100 , stdin);
        fprintf(p, "%s", a);
        rewind(p);
        
        while ((ch=fgetc(p))!=EOF)
        { ch=tolower(ch);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
           cv++;
        } 
        // Check for consonants using ASCII values
        else if (ch >= 'a' && ch <= 'z') {
            cc++;
        } 
        // Check for special characters (excluding whitespace and digits)
        else if (!(ch >= '0' && ch <= '9') && !isspace(ch)) {
            cs++;
        }
        }
        printf("%d\n%d\n%d\n",cv,cc,cs);
               fclose(p);
    }

    return 0;
}

