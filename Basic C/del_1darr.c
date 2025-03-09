#include <stdio.h>

void del(int a[], int *s, int index) {
    if (index < 0 || index >= *s) {
        printf("Invalid index\n");
        return;
    }
    for (int i = index; i < *s - 1; i++) {
        a[i] = a[i + 1];
    }
    (*s)--;
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int a[n], i;
    printf("Enter elements into the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int index;
    printf("Enter the index of the element to delete: ");
    scanf("%d", &index);

    del(a, &n, index);

    printf("Array after deletion: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
