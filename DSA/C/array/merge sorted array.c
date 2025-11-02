#include <stdio.h>
#include <stdlib.h> 

int main() {
    int *arr1, *arr2, *mergedArr;
    int n1, n2, n_merged;
    int i, j, k;

    printf("Enter size of first sorted array: ");
    scanf("%d", &n1);
    arr1 = (int *)malloc(n1 * sizeof(int));
    if (arr1 == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    printf("Enter %d sorted elements for first array:\n", n1);
    for (i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter size of second sorted array: ");
    scanf("%d", &n2);
    arr2 = (int *)malloc(n2 * sizeof(int));
    if (arr2 == NULL) {
        printf("Memory allocation failed!\n");
        free(arr1); 
        exit(1);
    }
    printf("Enter %d sorted elements for second array:\n", n2);
    for (i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    n_merged = n1 + n2;
    mergedArr = (int *)malloc(n_merged * sizeof(int));
    if (mergedArr == NULL) {
        printf("Memory allocation failed!\n");
        free(arr1);
        free(arr2);
        exit(1);
    }

    i = 0; 
    j = 0; 
    k = 0; 

    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            mergedArr[k] = arr1[i];
            i++;
        } else {
            mergedArr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        mergedArr[k] = arr1[i];
        i++;
        k++;
    }

    while (j < n2) {
        mergedArr[k] = arr2[j];
        j++;
        k++;
    }

    printf("Merged sorted array:\n");
    for (i = 0; i < n_merged; i++) {
        printf("%d ", mergedArr[i]);
    }
    printf("\n");

    free(arr1);
    free(arr2);
    free(mergedArr);

    return 0;
}
