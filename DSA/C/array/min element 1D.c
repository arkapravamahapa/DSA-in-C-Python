#include <stdio.h>
#include <stdlib.h> 
#include <limits.h> 

int main() {
    int *arr;
    int n, i, minElement;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Array size must be positive.\n");
        return 1;
    }

    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1); 
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    minElement = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] < minElement) {
            minElement = arr[i];
        }
    }

    printf("The minimum element in the array is: %d\n", minElement);

    free(arr);

    return 0;
}
