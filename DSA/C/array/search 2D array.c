#include <stdio.h>
#include <stdlib.h> 

int main() {
    int **arr; 
    int rows, cols, i, j, elementToSearch, found = 0;

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    arr = (int **)malloc(rows * sizeof(int *));
    if (arr == NULL) {
        printf("Memory allocation failed for rows!\n");
        exit(1);
    }

    for (i = 0; i < rows; i++) {
        arr[i] = (int *)malloc(cols * sizeof(int));
        if (arr[i] == NULL) {
            printf("Memory allocation failed for row %d!\n", i);
            for (j = 0; j < i; j++) {
                free(arr[j]);
            }
            free(arr);
            exit(1);
        }
    }

    printf("Enter %d elements (%d x %d matrix):\n", rows * cols, rows, cols);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Enter the element to search: ");
    scanf("%d", &elementToSearch);

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (arr[i][j] == elementToSearch) {
                printf("Element %d found at row %d, column %d (index [%d][%d]).\n",
                       elementToSearch, i, j, i, j);
                found = 1;
                break; 
            }
        }
        if (found == 1) {
            break; 
        }
    }

    if (found == 0) {
        printf("Element %d not found in the 2D array.\n", elementToSearch);
    }

    for (i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
