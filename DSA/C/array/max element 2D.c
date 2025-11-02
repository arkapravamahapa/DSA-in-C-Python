#include <stdio.h>
#include <stdlib.h> 
#include <limits.h> 

int main() {
    int **arr;
    int rows, cols, i, j, maxElement;

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    if (rows <= 0 || cols <= 0) {
        printf("Dimensions must be positive.\n");
        return 1;
    }

    arr = (int **)malloc(rows * sizeof(int *));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    for (i = 0; i < rows; i++) {
        arr[i] = (int *)malloc(cols * sizeof(int));
        if (arr[i] == NULL) {
            printf("Memory allocation failed for row %d!\n", i);
            exit(1); 
        }
    }

    printf("Enter %d elements (%d x %d matrix):\n", rows * cols, rows, cols);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    maxElement = arr[0][0];

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (arr[i][j] > maxElement) {
                maxElement = arr[i][j];
            }
        }
    }

    printf("The maximum element in the 2D array is: %d\n", maxElement);

    for (i = 0; i < rows; i++) {
        free(arr[i]); 
    }
    free(arr); 

    return 0;
}

