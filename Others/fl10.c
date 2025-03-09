#include<stdio.h>
#include<string.h>

int main() {
    FILE *p;
    char s[100], c[256];
    int n = 0, j = 0;
    char ch;

    p = fopen("Blank2.txt", "r");
    if (p == NULL) {
        printf("Error opening file\n");
        return 0;
    }

    printf("Input word to be searched: ");
    fgets(s, 100, stdin);
    s[strcspn(s, "\n")] = '\0'; // Remove newline from input

    // Search for the word in the file
    while ((ch = fgetc(p)) != EOF) {
        if (ch == '\n') {
            n++; // Increment line number
        }
        if (ch == s[0]) { // Check if first character matches
            fseek(p, -1, SEEK_CUR); // Move file pointer back by one character
            if (fgets(c, sizeof(c), p) != NULL) {
                if (strstr(c, s) != NULL) {
                    printf("Word found in line number %d: %s", n, c);
                    break;
                }
            }
        }
    }

    fclose(p);

    return 0;
}
