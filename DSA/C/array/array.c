#include <stdio.h>
#include <stdlib.h> 

int main() {
    int *arr;
    int n, i, elementToSearch, found = 0, index = -1;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int *)calloc(n, sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1); 
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &elementToSearch);

    for (i = 0; i < n; i++) {
        if (arr[i] == elementToSearch) {
            found = 1;
            index = i;
            break; 
        }
    }

    if (found == 1) {
        printf("Element %d found at index %d.\n", elementToSearch, index);
    } else {
        printf("Element %d not found in the array.\n", elementToSearch);
    }

    free(arr);

    return 0;
}

