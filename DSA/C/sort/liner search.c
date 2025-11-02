/*
 * 5. Write a C program to implement linear search.
 */

#include <stdio.h>

// Function to implement linear search
// Returns index of key if found, otherwise -1
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // Element found at index i
        }
    }
    return -1; // Element not found
}

// Main function to test the search
int main() {
    int arr[] = {10, 50, 30, 70, 80, 20, 90, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 20;

    printf("Array: ");
    for(int i=0; i<n; i++) printf("%d ", arr[i]);
    printf("\n");

    int result = linearSearch(arr, n, key);

    if (result == -1) {
        printf("Element %d not found in the array.\n", key);
    } else {
        printf("Element %d found at index %d.\n", key, result);
    }
    
    // Test with a key that doesn't exist
    key = 99;
    result = linearSearch(arr, n, key);
    if (result == -1) {
        printf("Element %d not found in the array.\n", key);
    } else {
        printf("Element %d found at index %d.\n", key, result);
    }
    
    return 0;
}
