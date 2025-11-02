/*
 * 6. Write a C program to implement binary search.
 * (Note: Binary search requires a SORTED array)
 */

#include <stdio.h>

// Function to implement binary search (iterative)
// Returns index of key if found, otherwise -1
int binarySearch(int arr[], int l, int r, int key) {
    while (l <= r) {
        int m = l + (r - l) / 2;

        // Check if key is present at mid
        if (arr[m] == key)
            return m;

        // If key greater, ignore left half
        if (arr[m] < key)
            l = m + 1;
        // If key smaller, ignore right half
        else
            r = m - 1;
    }

    // if we reach here, then element was not present
    return -1;
}

// Main function to test the search
int main() {
    // Array must be sorted for binary search
    int arr[] = {11, 22, 25, 34, 64, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 64;

    printf("Sorted Array: ");
    for(int i=0; i<n; i++) printf("%d ", arr[i]);
    printf("\n");

    int result = binarySearch(arr, 0, n - 1, key);

    if (result == -1) {
        printf("Element %d not found in the array.\n", key);
    } else {
        printf("Element %d found at index %d.\n", key, result);
    }

    // Test with a key that doesn't exist
    key = 23;
    result = binarySearch(arr, 0, n - 1, key);
    if (result == -1) {
        printf("Element %d not found in the array.\n", key);
    } else {
        printf("Element %d found at index %d.\n", key, result);
    }

    return 0;
}
