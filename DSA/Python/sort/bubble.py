"""
1. Write a Python program to implement Bubble Sort.
"""

def bubble_sort(arr):
    n = len(arr)
    
    # Outer loop for passes
    for i in range(n - 1):
        # Inner loop for comparisons
        # Last i elements are already in place
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                # Pythonic swap
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

# Main function to test the sort
if __name__ == "__main__":
    arr = [64, 34, 25, 12, 22, 11, 90]
    
    print(f"Unsorted array: {arr}")
    
    bubble_sort(arr)
    
    print(f"Sorted array (Bubble Sort): {arr}")
