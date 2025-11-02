"""
2. Write a Python program to implement Selection Sort.
"""

def selection_sort(arr):
    n = len(arr)
    
    # One by one move boundary of unsorted subarray
    for i in range(n - 1):
        # Find the minimum element in unsorted array
        min_idx = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j

        # Swap the found minimum element with the first element
        arr[i], arr[min_idx] = arr[min_idx], arr[i]

# Main function to test the sort
if __name__ == "__main__":
    arr = [64, 25, 12, 22, 11]
    
    print(f"Unsorted array: {arr}")
    
    selection_sort(arr)
    
    print(f"Sorted array (Selection Sort): {arr}")
