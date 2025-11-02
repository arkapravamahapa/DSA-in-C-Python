import array
import sys

# 1. Write a Python program to create an array of 5 integers and display the array items.
#    Access individual elements through indexes.
print("--- 1. Create and Access Array ---")
my_array = [10, 20, 30, 40, 50]
print(f"Full array: {my_array}")
print(f"Element at index 0: {my_array[0]}")
print(f"Element at index 3: {my_array[3]}")
print("\n" + "="*30 + "\n")


# 2. Write a Python program to append a new item to the end of the array.
print("--- 2. Append to Array ---")
my_array = [10, 20, 30, 40, 50]
print(f"Original array: {my_array}")
my_array.append(60)
print(f"After appending 60: {my_array}")
print("\n" + "="*30 + "\n")


# 3. Write a Python program to reverse the order of the items in the array.
print("--- 3. Reverse Array ---")
my_array = [10, 20, 30, 40, 50]
print(f"Original array: {my_array}")
my_array.reverse()
print(f"Reversed array: {my_array}")
print("\n" + "="*30 + "\n")


# 4. Write a Python program to get the number of occurrences of a specified element in an array.
print("--- 4. Count Occurrences ---")
my_array = [10, 20, 30, 20, 40, 20, 50]
print(f"Array: {my_array}")
element = 20
count = my_array.count(element)
print(f"Occurrences of {element}: {count}")
print("\n" + "="*30 + "\n")


# 5. Write a Python program to create an array containing six integers.
#    Also, print all the members of the array.
print("--- 5. Create 6 Integers and Print ---")
my_array_6 = [5, 15, 25, 35, 45, 55]
print(f"Array of 6 integers: {my_array_6}")
print("Printing all members:")
for item in my_array_6:
    print(item)
print("\n" + "="*30 + "\n")


# 6. Write a Python program to insert a new item before the second element in an existing array.
print("--- 6. Insert Item ---")
my_array = [10, 20, 30, 40, 50]
print(f"Original array: {my_array}")
my_array.insert(1, 99)
print(f"After inserting 99 at index 1: {my_array}")
print("\n" + "="*30 + "\n")


# 7. Write a Python program to remove a specified item using the index from an array.
print("--- 7. Remove by Index ---")
my_array = [10, 20, 30, 40, 50]
print(f"Original array: {my_array}")
removed_item = my_array.pop(2)
print(f"Removed item: {removed_item}")
print(f"Array after removing item at index 2: {my_array}")
print("\n" + "="*30 + "\n")


# 8. Write a Python program to remove the first occurrence of a specified element from an array.
print("--- 8. Remove First Occurrence ---")
my_array = [10, 20, 30, 20, 40]
print(f"Original array: {my_array}")
element_to_remove = 20
try:
    my_array.remove(element_to_remove)
    print(f"Array after removing first {element_to_remove}: {my_array}")
except ValueError:
    print(f"Element {element_to_remove} not found in the array.")
print("\n" + "="*30 + "\n")


# 9. Write a Python program to convert an array to an ordinary list with the same items.
print("--- 9. Convert Array to Ordinary List ---")
typed_array = array.array('i', [100, 200, 300])
print(f"Original 'array' module object: {typed_array}")
ordinary_list = typed_array.tolist()
print(f"Converted to ordinary list: {ordinary_list}")
print(f"Type of original: {type(typed_array)}")
print(f"Type of converted: {type(ordinary_list)}")
print("\n" + "="*30 + "\n")


# 10. Write a Python program to find whether a given array of integers contains any duplicate element.
#     Return true if any value appears at least twice in the said array
#     and return false if every element is distinct.
print("--- 10. Check for Duplicates ---")
def contains_duplicates(arr):
    return len(set(arr)) != len(arr)

array1 = [1, 2, 3, 4, 5]
array2 = [1, 2, 3, 4, 2]
print(f"Array {array1} has duplicates: {contains_duplicates(array1)}")
print(f"Array {array2} has duplicates: {contains_duplicates(array2)}")
print("\n" + "="*30 + "\n")


# 11. Write a Python program to find a pair with the highest product
#     from a given array of integers.
print("--- 11. Pair with Highest Product ---")
def find_highest_product_pair(arr):
    if len(arr) < 2:
        return None
    
    arr_sorted = sorted(arr)
    
    product1 = arr_sorted[-1] * arr_sorted[-2]
    product2 = arr_sorted[0] * arr_sorted[1]
    
    return max(product1, product2)

array1 = [1, 2, 3, 4, 5, 6]
array2 = [-10, -3, 1, 2, 6]
array3 = [-10, -5, -1, -2, -6]
array4 = [1, -4, 3, -6, 7, 0]

print(f"Array: {array1}, Highest product: {find_highest_product_pair(array1)}")
print(f"Array: {array2}, Highest product: {find_highest_product_pair(array2)}")
print(f"Array: {array3}, Highest product: {find_highest_product_pair(array3)}")
print(f"Array: {array4}, Highest product: {find_highest_product_pair(array4)}")
print("\n" + "="*30 + "\n")


# 12. Write a Python program to get the length of an array.
print("--- 12. Get Array Length ---")
my_array = [1, 2, 3, 4, 5, 6, 7]
print(f"Array: {my_array}")
print(f"Length of the array: {len(my_array)}")
print("\n" + "="*30 + "\n")


# 13. Write a Python program to remove all duplicate elements
#     from a given array and returns a new array.
print("--- 13. Remove All Duplicates (New Array) ---")
def remove_duplicates_preserve_order(arr):
    seen = set()
    new_arr = []
    for item in arr:
        if item not in seen:
            seen.add(item)
            new_arr.append(item)
    return new_arr

my_array = [1S, 2, 3, 2, 4, 5, 4, 1, 6]
print(f"Original array: {my_array}")
unique_ordered_array = remove_duplicates_preserve_order(my_array)
print(f"New array (duplicates removed, order preserved): {unique_ordered_array}")
print("\n" + "="*30 + "\n")


# 14. Write a Python program to find the missing number
#     in a given array of numbers between 10 and 20.
print("--- 14. Find Missing Number (10-20) ---")
def find_missing_number(arr):
    full_range = set(range(10, 21))
    given_set = set(arr)
    missing = full_range - given_set
    return list(missing)

my_array = [10, 11, 13, 14, 15, 16, 18, 19, 20]
print(f"Array: {my_array}")
print(f"Missing numbers (10-20): {find_missing_number(my_array)}")
print("\n" + "="*30 + "\n")


# 15. Write a Python program to create a 2D array containing 12 integers.
#     Also print all the members of the array.
print("--- 15. Create 2D Array ---")
rows, cols = 3, 4
matrix = [
    [1, 2, 3, 4],
    [5, 6, 7, 8],
    [9, 10, 11, 12]
]
        
print(f"2D Array (Matrix):\n{matrix}")
        
print("\nPrinting all members:")
for row in matrix:
    for item in row:
        print(item, end="\t")
    print()
print("\n" + "="*30 + "\n")

