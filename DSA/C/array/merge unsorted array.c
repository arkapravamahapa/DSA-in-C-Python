#include <stdio.h>
#include <stdlib.h> 

int compareIntegers(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int *arr1, *arr2, *mergedArr;
    int n1, n2, n_merged;
    int i, k;

    printf("Enter size of first unsorted array: ");
    scanf("%d", &n1);
    arr1 = (int *)malloc(n1 * sizeof(int));
    if (arr1 == NULL) {
        exit(1);
    }
    printf("Enter %d elements for first array:\n", n1);
    for (i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter size of second unsorted array: ");
    scanf("%d", &n2);
    arr2 = (int *)malloc(n2 * sizeof(int));
    if (arr2 == NULL) {
        free(arr1);
        exit(1);
    }
    printf("Enter %d elements for second array:\n", n2);
    for (i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    n_merged = n1 + n2;
    mergedArr = (int *)malloc(n_merged * sizeof(int));
    if (mergedArr == NULL) {
        free(arr1);
        free(arr2);
        exit(1);
    }

    for (i = 0; i < n1; i++) {
        mergedArr[i] = arr1[i];
    }
    for (i = 0; i < n2; i++) {
        mergedArr[n1 + i] = arr2[i];
    }

    qsort(mergedArr, n_merged, sizeof(int), compareIntegers);

    printf("Merged and sorted array:\n");
    for (i = 0; i < n_merged; i++) {
        printf("%d ", mergedArr[i]);
    }
    printf("\n");

    free(arr1);
    free(arr2);
    free(mergedArr);

    return 0;
}
