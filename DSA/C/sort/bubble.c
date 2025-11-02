/*
 * 1. Write a C program to implement Bubble Sort.
 */

#include <stdio.h>

// Helper function to swap two elements
void swap(int* xp, int* yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Function to implement bubble sort
void bubbleSort(int arr[], int n) {
    int i, j;
    // Outer loop for passes
    for (i = 0; i < n - 1; i++) {
        // Inner loop for comparisons in each pass
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function to test the sort
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Unsorted array: \n");
    printArray(arr, n);
    
    bubbleSort(arr, n);
    
    printf("Sorted array (Bubble Sort): \n");
    printArray(arr, n);
    return 0;
}
