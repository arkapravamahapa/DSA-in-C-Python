"""
4. Write a Python program to implement Merge Sort.
"""

def merge_sort(arr):
    # Base case: array of size 0 or 1 is already sorted
    if len(arr) > 1:
        # Finding the mid of the array
        mid = len(arr) // 2
        
        # Dividing the array elements into two halves
        L = arr[:mid]
        R = arr[mid:]
        
        # Recursively sort the two halves
        merge_sort(L)
        merge_sort(R)
        
        # Merge the sorted halves back into the original array
        i = j = k = 0
        
        # Copy data to temp arrays L[] and R[]
        while i < len(L) and j < len(R):
            if L[i] <= R[j]:
                arr[k] = L[i]
                i += 1
            else:
                arr[k] = R[j]
                j += 1
            k += 1
            
        # Checking if any element was left in L
        while i < len(L):
            arr[k] = L[i]
            i += 1
            k += 1
            
        # Checking if any element was left in R
        while j < len(R):
            arr[k] = R[j]
            j += 1
            k += 1

# Main function to test the sort
if __name__ == "__main__":
    arr = [12, 11, 13, 5, 6, 7]
    
    print(f"Unsorted array: {arr}")
    
    merge_sort(arr)
    
    print(f"Sorted array (Merge Sort): {arr}")
