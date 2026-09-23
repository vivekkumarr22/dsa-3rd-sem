#include <stdio.h>

int main() {
    int a[100], b[100], c[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter first array:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter second array:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &b[i]);

    for(i = 0; i < n; i++)
        c[i] = a[i] * b[i];

    printf("Multiplication:\n");
    for(i = 0; i < n; i++)
        printf("%d ", c[i]);

    return 0;
}
