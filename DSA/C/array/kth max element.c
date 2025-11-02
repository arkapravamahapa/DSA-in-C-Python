#include <stdio.h>
#include <stdlib.h> 

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortDescending(int *arr, int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    int *arr;
    int n, i, k;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1); 
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value of k (e.g., 3 for 3rd maximum): ");
    scanf("%d", &k);

    if (k <= 0 || k > n) {
        printf("Invalid value of k. k must be between 1 and %d.\n", n);
        free(arr); 
        return 1;  
    }

    sortDescending(arr, n);

    printf("The %d-th maximum element is: %d\n", k, arr[k - 1]);

    free(arr);

    return 0;
}
