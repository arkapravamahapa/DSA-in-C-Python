"""
3. Write a Python program to implement Insertion Sort.
"""

def insertion_sort(arr):
    n = len(arr)
    
    # Start from the second element (index 1)
    for i in range(1, n):
        key = arr[i] # The element to be inserted
        j = i - 1
        
        # Move elements of arr[0..i-1], that are
        # greater than key, to one position ahead
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        
        arr[j + 1] = key # Place the key in its correct position

# Main function to test the sort
if __name__ == "__main__":
    arr = [12, 11, 13, 5, 6]
    
    print(f"Unsorted array: {arr}")
    
    insertion_sort(arr)
    
    print(f"Sorted array (Insertion Sort): {arr}")
