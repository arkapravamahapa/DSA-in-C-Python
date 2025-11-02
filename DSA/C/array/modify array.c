#include <stdio.h>
#include <stdlib.h> 

int main() {
    int *arr, *temp;
    int n, i, new_size;

    printf("Enter the initial number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Initial memory allocation failed!\n");
        exit(1);
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Enter the new size for the array: ");
    scanf("%d", &new_size);

    temp = (int *)realloc(arr, new_size * sizeof(int));

    if (temp == NULL && new_size > 0) {
        printf("Memory reallocation failed!\n");
        free(arr); 
        exit(1);
    }

    arr = temp;
    temp = NULL; 

    if (new_size > n) {
        printf("Enter %d new elements:\n", new_size - n);
        for (i = n; i < new_size; i++) {
            scanf("%d", &arr[i]);
        }
    }

    printf("Modified array (size %d):\n", new_size);
    for (i = 0; i < new_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    if (arr != NULL) {
        free(arr);
    }

    return 0;
}

