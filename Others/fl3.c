//read and write a file
#include <stdio.h>
#include <string.h>

int main() {
    FILE *p;
    p = fopen("Word.txt", "w+");
    char a[100];
    char c[100];
    if (p == NULL) {
        printf("Error opening file\n");
        return 0;
    } else {
        printf("Enter a string: ");
        fgets(a,100 , stdin);
        
        // Write the input string to the file
        fprintf(p, "%s", a);
        rewind(p);
        
        // Read the string back from the file
        fgets(c, sizeof(c), p);
        
        printf("Read from file: %s", c);
        
        fclose(p);
    }

    return 0;
}
