#include <stdio.h>
#include <stdlib.h> 

int main() {
    int *arr, *temp;
    int n, i, start_index, end_index;
    int num_to_delete, new_size;

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

    printf("Enter start index of range to delete: ");
    scanf("%d", &start_index);
    printf("Enter end index of range to delete: ");
    scanf("%d", &end_index);

    if (start_index < 0 || end_index >= n || start_index > end_index) {
        printf("Invalid range!\n");
        printf("Start index must be 0 <= start <= end < %d\n", n);
        free(arr);
        return 1;
    }

    num_to_delete = (end_index - start_index) + 1;
    new_size = n - num_to_delete;

    for (i = end_index + 1; i < n; i++) {
        arr[i - num_to_delete] = arr[i];
    }

    if (new_size > 0) {
        temp = (int *)realloc(arr, new_size * sizeof(int));

        if (temp == NULL) {
            printf("Memory reallocation failed. Printing original array with shifted data.\n");
        } else {
            arr = temp;
        }
    } else {
        free(arr);
        arr = NULL;
    }


    printf("Array after deleting range [%d..%d]:\n", start_index, end_index);
    if (arr != NULL) {
        for (i = 0; i < new_size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        free(arr);
    } else {
        printf("[Array is now empty]\n");
    }

    return 0;
}

