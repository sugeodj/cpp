#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Allocate memory dynamically
    ptr = (int*) malloc(n * sizeof(int));

    // Check if memory allocation was successful
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // Input elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ptr[i]);
    }

    // Output elements
    printf("Elements entered are:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", ptr[i]);
    }

    // Free the dynamically allocated memory
    free(ptr);

    return 0;
}