Data Structures and Algorithms in C and Python

About This Repository

This repository contains a comprehensive collection of fundamental data structures and algorithms (DSA) implemented in both C and Python. It serves as a practical guide and code reference for common computer science problems, from basic array manipulations to more complex graph and tree-based algorithms.

Each program is designed to be self-contained and demonstrates a specific concept.

Topics Covered

Arrays (Dynamic in C, Lists in Python)
Stacks & Queues
Singly Linked Lists
Doubly Linked Lists
Binary Trees
Graphs (Adjacency Matrix & List)
Searching & Sorting
Hashing

How to Use

C Programs

You will need a C compiler (like gcc) installed.

Compile a program:

gcc -o program_name file_name.c


Example: gcc -o stack 1_stack.c

Run the compiled program:

./program_name


Example: ./stack

Python Programs

You will need Python 3.x installed.

Run a program:

python3 file_name.py


Example: python3 1_stack.py

C Implementations

<details>
<summary><strong>Topic 1: Dynamic Array (10 Programs)</strong></summary>

1_search_1d_dynamic.c: Search an element in a 1D dynamic array.
2_kth_max_element.c: Find the Nth maximum element in a dynamic array.
3_min_element_1d.c: Find the minimum element in a 1D dynamic array.
4_search_2d_dynamic.c: Search an element in a 2D dynamic array.
5_max_element_2d.c: Find the maximum element in a 2D dynamic array.
6_min_element_2d.c: Find the minimum element in a 2D dynamic array.
7_merge_sorted_arrays.c: Merge two sorted dynamic arrays.
8_merge_unsorted_sorted.c: Merge two unsorted dynamic arrays into a sorted one.
9_delete_range.c: Delete a range of data from a dynamic array.
10_modify_array_size.c: Modify an array's size at runtime using realloc.

</details>

<details>
<summary><strong>Topic 2: Stack & Queue (7 Programs)</strong></summary>

1_stack.c: Implement Stack using a dynamic array (Push, Pop, Peek, Display).
2_queue.c: Implement Queue (linear) using a dynamic array.
3_reverse_string.c: Reverse a string using a Stack.
4_double_stack.c: Implement a Double-Ended Stack (two stacks in one array).
5_palindrome.c: Advanced palindrome checker (ignores case/punctuation) using Stack & Queue.
6_queue_from_stacks.c: Implement a Queue using two Stacks.
7_circular_queue.c: Implement a Circular Queue using a dynamic array.

</details>

<details>
<summary><strong>Topic 3: Singly Linked List (15 Programs)</strong></summary>

1_sll_insert.c: SLL Insert operations (AtFirst, AtLast, AtAny) with menu.
2_sll_delete.c: SLL Delete operations (FromFirst, FromLast, FromAny) with menu.
3_sll_menu.c: SLL full menu with all Insert, Delete, and Display functions.
4_sll_polynomial.c: Store a polynomial in ascending order.
5_sll_count.c: Count the number of nodes.
6_sll_odd_even.c: Print odd and even number nodes separately.

1_reverse_sll.c: Reverse a Singly Linked List.
2_merge_sorted_sll.c: Merge two sorted Singly Linked Lists.
3_left_shift_sll.c: Left-shift a Singly Linked List by k nodes.
4_add_polynomials.c: Perform addition of two polynomials.
5_swap_pairwise_sll.c: Swap elements pairwise (1->2->3->4 becomes 2->1->4->3).
6_detect_loop_sll.c: Detect a loop (cycle) in a list (Floyd's Algorithm).
7_multiply_polynomials.c: Perform multiplication of two polynomials.
8_stack_sll.c: Implement a Stack using a Singly Linked List.
9_queue_sll.c: Implement a Queue using a Singly Linked List.

</details>

<details>
<summary><strong>Topic 4: Doubly Linked List (3 Programs)</strong></summary>

1_doubly_linked_list.c: Full menu for DLL (Create, Insert, Delete, Search, Count, Display).
2_merge_sorted_dll.c: Merge two sorted Doubly Linked Lists.
3_doubly_circular_list.c: Full menu for a Doubly Circular Linked List.

</details>

<details>
<summary><strong>Topic 5: Binary Tree (2 Programs)</strong></summary>

1_binary_tree_array.c: Implement Binary Tree using an array (static representation).
2_binary_tree_linkedlist.c: Implement Binary Tree using a linked list (dynamic).

Includes: Create, Inorder, Preorder, Postorder, Count Nodes, Height, Leaf Node Count, Internal Node Count, Search.

</details>

<details>
<summary><strong>Topic 6: Graph (2 Programs)</strong></summary>

1_graph_adjacency_matrix.c: Implement Graph using Adjacency Matrix (Count Vertices/Edges, Find Adjacent, Search).
2_graph_adjacency_list.c: Implement Graph using Adjacency List (Count Vertices/Edges, Find Adjacent, Search).

</details>

<details>
<summary><strong>Topic 7: Searching & Sorting (7 Programs)</strong></summary>

1_c_bubble_sort.c: Bubble Sort.
2_c_selection_sort.c: Selection Sort.
3_c_insertion_sort.c: Insertion Sort.
4_c_merge_sort.c: Merge Sort.
5_c_linear_search.c: Linear Search.
6_c_binary_search.c: Binary Search.
7_c_hashing.c: Hashing with Linear Probing.

</details>

Python Implementations

<details>
<summary><strong>Topic 1: Array / List (15 Programs)</strong></summary>

1_create_access_array.py: Create and access list elements.
2_append_array.py: Append a new item.
3_reverse_array.py: Reverse the order of items.
4_count_occurrences.py: Count occurrences of an element.
5_create_print_array.py: Create and print a list of 6 integers.
6_insert_item.py: Insert an item at a specific position.
7_remove_by_index.py: Remove an item by its index.
8_remove_first_occurrence.py: Remove the first occurrence of an element.
9_convert_array_to_list.py: Convert Python array.array to a list.
10_check_duplicates.py: Check if a list contains any duplicates.
11_highest_product_pair.py: Find the pair with the highest product.
12_get_array_length.py: Get the length of a list.
13_remove_duplicates.py: Remove all duplicates and return a new list.
14_find_missing_number.py: Find a missing number in a range.
15_create_2d_array.py: Create and print a 2D list (matrix).

</details>

<details>
<summary><strong>Topic 2: Stack & Queue (5 Programs)</strong></summary>

1_stack.py: Implement Stack (using a list).
2_queue.py: Implement Queue (using collections.deque).
3_reverse_string.py: Reverse a string using a Stack.
4_circular_queue.py: Implement a Circular Queue (using a fixed-size list).
5_filter_stack.py: Filter a stack of "boxes" based on color (Red, Green, Blue).

</details>

<details>
<summary><strong>Topic 3: Singly Linked List (11 Programs)</strong></summary>

1_sll_insert.py: SLL Insert operations (AtFirst, AtLast, AtAny) with demo.
2_sll_delete.py: SLL Delete operations (FromFirst, FromLast, FromAny) with demo.
3_sll_menu.py: SLL full menu with all Insert, Delete, and Display functions.
4_sll_polynomial.py: Store a polynomial in descending order.
5_sll_count.py: Count the number of nodes.
6_sll_odd_even.py: Print odd and even number nodes separately.

1_reverse_sll.py: Reverse a Singly Linked List.
2_merge_sorted_sll.py: Merge two sorted Singly Linked Lists.
3_add_polynomials.py: Perform addition of two polynomials.
4_swap_pairwise_sll.py: Swap elements pairwise (1->2->3->4 becomes 2->1->4->3).
5_detect_loop_sll.py: Detect a loop (cycle) in a list (Floyd's Algorithm).

</details>

<details>
<summary><strong>Topic 4: Doubly Linked List (2 Programs)</strong></summary>

1_doubly_linked_list.py: Full menu for DLL (Create, Insert, Delete, Search, Count, Display).
2_doubly_circular_list.py: Full menu for a Doubly Circular Linked List.

</details>

<details>
<summary><strong>Topic 5: Binary Tree (1 Program)</strong></summary>

2_binary_tree_linkedlist.py: Implement Binary Tree using classes (dynamic).

Includes: Create, Inorder, Preorder, Postorder, Count Nodes, Height, Leaf Node Count, Internal Node Count, Search.

</details>

<details>
<summary><strong>Topic 6: Graph (2 Programs)</strong></summary>

1_graph_adjacency_matrix.py: Implement Graph using Adjacency Matrix (list of lists).
2_graph_adjacency_list.py: Implement Graph using Adjacency List (dictionary of lists).

</details>

<details>
<summary><strong>Topic 7: Searching & Sorting (6 Programs)</strong></summary>

1_py_bubble_sort.py: Bubble Sort.
2_py_selection_sort.py: Selection Sort.
3_py_insertion_sort.py: Insertion Sort.
4_py_merge_sort.py: Merge Sort.
5_py_linear_search.py: Linear Search.
6_py_binary_search.py: Binary Search.

</details>

License
This project is licensed under the MIT License.
