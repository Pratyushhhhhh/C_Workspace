#include<stdio.h>
#include<string.h>

int main() {
    int len, p = 0, i, j;
    char a[100];
    printf("Enter the string \n");
    fgets(a, 100, stdin);
    len= strlen(a); 
    printf("Strings after spliting by space are:  \n");
    for (i = 0; i < len; i++)
    {
        if (a[i] == ' ' || a[i] == '\n') 
        {
            for (j = p; j <=i; j++) 
            {
                printf("%c", a[j]); 
            }
            p = i + 1; 
            printf("\n");
        }
    }
    return 0;
}
