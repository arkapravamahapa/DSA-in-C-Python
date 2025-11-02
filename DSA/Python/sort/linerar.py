"""
5. Write a Python program to implement linear search.
"""

def linear_search(arr, key):
    """
    Returns index of key if found, otherwise -1
    """
    for i in range(len(arr)):
        if arr[i] == key:
            return i # Element found at index i
    return -1 # Element not found

# Main function to test the search
if __name__ == "__main__":
    arr = [10, 50, 30, 70, 80, 20, 90, 40]
    key = 20
    
    print(f"Array: {arr}")
    
    result = linear_search(arr, key)
    
    if result == -1:
        print(f"Element {key} not found in the array.")
    else:
        print(f"Element {key} found at index {result}.")
        
    # Test with a key that doesn't exist
    key = 99
    result = linear_search(arr, key)
    
    if result == -1:
        print(f"Element {key} not found in the array.")
    else:
        print(f"Element {key} found at index {result}.")
