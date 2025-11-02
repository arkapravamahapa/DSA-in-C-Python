"""
6. Write a Python program to implement binary search.
(Note: Binary search requires a SORTED list)
"""

def binary_search(arr, key):
    """
    Returns index of key if found, otherwise -1
    """
    l, r = 0, len(arr) - 1
    
    while l <= r:
        mid = (l + r) // 2 # Integer division
        
        # Check if key is present at mid
        if arr[mid] == key:
            return mid
        # If key is greater, ignore left half
        elif arr[mid] < key:
            l = mid + 1
        # If key is smaller, ignore right half
        else:
            r = mid - 1
            
    # if we reach here, then element was not present
    return -1

# Main function to test the search
if __name__ == "__main__":
    # List must be sorted for binary search
    arr = [11, 22, 25, 34, 64, 90]
    key = 64
    
    print(f"Sorted Array: {arr}")
    
    result = binary_search(arr, key)
    
    if result == -1:
        print(f"Element {key} not found in the array.")
    else:
        print(f"Element {key} found at index {result}.")

    # Test with a key that doesn't exist
    key = 23
    result = binary_search(arr, key)
    
    if result == -1:
        print(f"Element {key} not found in the array.")
    else:
        print(f"Element {key} found at index {result}.")
