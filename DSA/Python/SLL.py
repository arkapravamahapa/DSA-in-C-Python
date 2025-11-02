"""
1. Write a program to reverse an already created single linked list.
"""

class Node:
    """A single node in a linked list."""
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    """A class representing the linked list."""
    def __init__(self):
        self.head = None

    def insertAtLast(self, data):
        """Inserts a new node at the end of the list."""
        newNode = Node(data)
        if self.head is None:
            self.head = newNode
            return
        temp = self.head
        while temp.next:
            temp = temp.next
        temp.next = newNode

    def displayList(self):
        """Prints the entire linked list."""
        if self.head is None:
            print("List is empty.")
            return
        temp = self.head
        print("List: ", end="")
        while temp:
            print(temp.data, end="")
            if temp.next:
                print(" -> ", end="")
            temp = temp.next
        print(" -> NULL")

    def reverse(self):
        """Reverses the linked list in-place."""
        prev_node = None
        current_node = self.head
        next_node = None
        
        while current_node:
            # Store the next node
            next_node = current_node.next
            # Reverse the current node's pointer
            current_node.next = prev_node
            # Move the pointers one step forward
            prev_node = current_node
            current_node = next_node
            
        # Update the head to the new front (which was the last node)
        self.head = prev_node

# --- Demonstration ---
if __name__ == "__main__":
    ll = LinkedList()
    
    print("Creating list...")
    ll.insertAtLast(10)
    ll.insertAtLast(20)
    ll.insertAtLast(30)
    ll.insertAtLast(40)
    
    print("Original list:")
    ll.displayList()
    
    print("\nReversing list...")
    ll.reverse()
    
    print("Reversed list:")
    ll.displayList()






"""
2. Write a program to merge two already sorted list.
"""

class Node:
    """A single node in a linked list."""
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    """A class representing the linked list."""
    def __init__(self):
        self.head = None

    def insertAtLast(self, data):
        """Inserts a new node at the end of the list."""
        newNode = Node(data)
        if self.head is None:
            self.head = newNode
            return
        temp = self.head
        while temp.next:
            temp = temp.next
        temp.next = newNode

    def displayList(self):
        """Prints the entire linked list."""
        if self.head is None:
            print("List is empty.")
            return
        temp = self.head
        print("List: ", end="")
        while temp:
            print(temp.data, end="")
            if temp.next:
                print(" -> ", end="")
            temp = temp.next
        print(" -> NULL")

def mergeSortedLists(list1_head, list2_head):
    """
    Merges two sorted linked lists and returns the head
    of the new merged list.
    """
    # Create a dummy node to act as a placeholder head
    dummy = Node(0)
    # tail will point to the last node in the merged list
    tail = dummy

    p1 = list1_head
    p2 = list2_head

    while p1 and p2:
        if p1.data <= p2.data:
            tail.next = p1
            p1 = p1.next
        else:
            tail.next = p2
            p2 = p2.next
        tail = tail.next

    # Attach the remaining nodes from whichever list is not empty
    if p1:
        tail.next = p1
    elif p2:
        tail.next = p2

    # The merged list starts after the dummy node
    return dummy.next

# --- Demonstration ---
if __name__ == "__main__":
    ll1 = LinkedList()
    ll2 = LinkedList()
    
    print("Creating sorted list 1...")
    ll1.insertAtLast(10)
    ll1.insertAtLast(30)
    ll1.insertAtLast(50)
    ll1.insertAtLast(70)
    ll1.displayList()

    print("\nCreating sorted list 2...")
    ll2.insertAtLast(20)
    ll2.insertAtLast(40)
    ll2.insertAtLast(60)
    ll2.displayList()

    print("\nMerging lists...")
    
    # Create a new list to hold the merged result
    merged_ll = LinkedList()
    merged_ll.head = mergeSortedLists(ll1.head, ll2.head)
    
    print("Merged list:")
    merged_ll.displayList()






"""
3. Write a program to perform addition of two polynomials using linked list.
   (Storing terms in descending order of exponent)
"""

class PolyNode:
    """A node to store a term in a polynomial (coefficient and exponent)."""
    def __init__(self, coeff, exp):
        self.coeff = coeff
        self.exp = exp
        self.next = None

class Polynomial:
    """A class to represent a polynomial using a linked list."""
    def __init__(self):
        self.head = None

    def insertTerm(self, coeff, exp):
        """
        Inserts a new term, maintaining descending order of exponents
        and combining like terms.
        """
        if coeff == 0:
            return  # No need to store zero-coefficient terms
            
        newNode = PolyNode(coeff, exp)

        if self.head is None or self.head.exp < exp:
            # Case 1: Insert at the beginning
            newNode.next = self.head
            self.head = newNode
            return
            
        temp = self.head
        prev = None
        while temp and temp.exp > exp:
            prev = temp
            temp = temp.next
            
        if temp and temp.exp == exp:
            # Case 2: Exponent already exists, combine terms
            temp.coeff += coeff
            if temp.coeff == 0:
                # If sum is zero, remove the node
                if prev:
                    prev.next = temp.next
                else:
                    self.head = temp.next
        else:
            # Case 3: Insert in the middle or at the end
            newNode.next = temp
            if prev:
                prev.next = newNode

    def displayPoly(self):
        """Displays the polynomial in a readable format."""
        if self.head is None:
            print("Polynomial: 0")
            return
            
        temp = self.head
        print("Polynomial: ", end="")
        isFirstTerm = True
        
        while temp:
            if temp.coeff == 0:  # Skip zero terms
                temp = temp.next
                continue

            # Handle sign
            if not isFirstTerm:
                print(" + " if temp.coeff > 0 else " - ", end="")
            elif temp.coeff < 0:
                print("-", end="")

            coeff_abs = abs(temp.coeff)

            # Print coefficient (only if not 1, or if exp is 0)
            if coeff_abs != 1 or temp.exp == 0:
                print(coeff_abs, end="")
            
            # Print exponent
            if temp.exp > 0:
                print("x", end="")
                if temp.exp > 1:
                    print(f"^{temp.exp}", end="")
            
            isFirstTerm = False
            temp = temp.next
        
        if isFirstTerm: # All terms were zero
            print("0", end="")
        
        print() # Newline at the end

def addPolynomials(poly1, poly2):
    """Adds two polynomials and returns a new Polynomial object."""
    p1 = poly1.head
    p2 = poly2.head
    resultPoly = Polynomial()

    while p1 or p2:
        if p1 and (not p2 or p1.exp > p2.exp):
            # Term from p1 is larger
            resultPoly.insertTerm(p1.coeff, p1.exp)
            p1 = p1.next
        elif p2 and (not p1 or p2.exp > p1.exp):
            # Term from p2 is larger
            resultPoly.insertTerm(p2.coeff, p2.exp)
            p2 = p2.next
        else:
            # Exponents are equal, combine them
            new_coeff = p1.coeff + p2.coeff
            if new_coeff != 0:
                resultPoly.insertTerm(new_coeff, p1.exp)
            p1 = p1.next
            p2 = p2.next
            
    return resultPoly

# --- Demonstration ---
if __name__ == "__main__":
    poly1 = Polynomial()
    poly2 = Polynomial()

    # Poly 1: 5x^2 + 4x^1 + 2x^0
    print("Creating Polynomial 1...")
    poly1.insertTerm(5, 2)
    poly1.insertTerm(4, 1)
    poly1.insertTerm(2, 0)
    poly1.displayPoly()

    # Poly 2: 3x^2 + 5x^0
    print("\nCreating Polynomial 2...")
    poly2.insertTerm(3, 2)
    poly2.insertTerm(5, 0)
    poly2.displayPoly()
    
    # Add them
    print("\nAdding polynomials...")
    result = addPolynomials(poly1, poly2)
    
    print("Result:")
    # Expected: 8x^2 + 4x^1 + 7x^0
    result.displayPoly()






"""
4. Given a singly linked list of size N. The task is to swap elements 
   in the linked list pairwise. 
   Example: 1->2->3->4 becomes 2->1->4->3
"""

class Node:
    """A single node in a linked list."""
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    """A class representing the linked list."""
    def __init__(self):
        self.head = None

    def insertAtLast(self, data):
        """Inserts a new node at the end of the list."""
        newNode = Node(data)
        if self.head is None:
            self.head = newNode
            return
        temp = self.head
        while temp.next:
            temp = temp.next
        temp.next = newNode

    def displayList(self):
        """Prints the entire linked list."""
        if self.head is None:
            print("List is empty.")
            return
        temp = self.head
        print("List: ", end="")
        while temp:
            print(temp.data, end="")
            if temp.next:
                print(" -> ", end="")
            temp = temp.next
        print(" -> NULL")

    def swapPairwise(self):
        """Swaps adjacent elements in the linked list."""
        
        # Use a dummy node to simplify head-swapping
        dummy = Node(0)
        dummy.next = self.head
        
        prev = dummy
        current = self.head
        
        while current and current.next:
            # Nodes to be swapped
            first = current
            second = current.next
            
            # Swapping
            prev.next = second
            first.next = second.next
            second.next = first
            
            # Move pointers for the next iteration
            prev = first
            current = first.next
            
        # Update the list head
        self.head = dummy.next

# --- Demonstration ---
if __name__ == "__main__":
    
    # Test 1: Even number of nodes
    print("--- Test 1: Even List ---")
    ll_even = LinkedList()
    ll_even.insertAtLast(1)
    ll_even.insertAtLast(2)
    ll_even.insertAtLast(3)
    ll_even.insertAtLast(4)
    
    print("Original list:")
    ll_even.displayList()
    
    print("\nSwapping pairwise...")
    ll_even.swapPairwise()
    
    print("Swapped list:")
    ll_even.displayList() # Expected: 2 -> 1 -> 4 -> 3

    # Test 2: Odd number of nodes
    print("\n--- Test 2: Odd List ---")
    ll_odd = LinkedList()
    ll_odd.insertAtLast(1)
    ll_odd.insertAtLast(2)
    ll_odd.insertAtLast(3)
    ll_odd.insertAtLast(4)
    ll_odd.insertAtLast(5)
    
    print("Original list:")
    ll_odd.displayList()
    
    print("\nSwapping pairwise...")
    ll_odd.swapPairwise()
    
    print("Swapped list:")
    ll_odd.displayList() # Expected: 2 -> 1 -> 4 -> 3 -> 5






"""
5. Write a program to detect a loop in a single linked list.
"""

class Node:
    """A single node in a linked list."""
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    """A class representing the linked list."""
    def __init__(self):
        self.head = None

    def insertAtLast(self, data):
        """Inserts a new node at the end of the list."""
        newNode = Node(data)
        if self.head is None:
            self.head = newNode
            return
        temp = self.head
        while temp.next:
            temp = temp.next
        temp.next = newNode

    def displayList(self):
        """
        Prints the entire linked list. 
        DO NOT call this if a loop exists!
        """
        if self.head is None:
            print("List is empty.")
            return
        temp = self.head
        print("List: ", end="")
        while temp:
            print(temp.data, end="")
            if temp.next:
                print(" -> ", end="")
            temp = temp.next
        print(" -> NULL")

    def detectLoop(self):
        """
        Detects a loop using Floyd's Cycle-Finding Algorithm
        (Tortoise and Hare).
        """
        slow = self.head
        fast = self.head
        
        while fast and fast.next:
            slow = slow.next      # Moves 1 step
            fast = fast.next.next # Moves 2 steps
            
            # If they meet, there is a loop
            if slow == fast:
                return True
                
        # If fast reaches the end, there is no loop
        return False

# --- Demonstration ---
if __name__ == "__main__":
    
    # Test 1: A normal list (no loop)
    print("--- Test 1: Normal List ---")
    ll_normal = LinkedList()
    ll_normal.insertAtLast(1)
    ll_normal.insertAtLast(2)
    ll_normal.insertAtLast(3)
    ll_normal.displayList()
    
    print(f"Loop detected: {ll_normal.detectLoop()}") # Expected: False

    # Test 2: A list with a loop
    print("\n--- Test 2: Looped List ---")
    ll_looped = LinkedList()
    ll_looped.insertAtLast(10)
    ll_looped.insertAtLast(20)
    ll_looped.insertAtLast(30)
    ll_looped.insertAtLast(40)
    ll_looped.insertAtLast(50)
    
    # Manually create the loop
    # 50 -> 30
    node30 = ll_looped.head.next.next  # Node with data 30
    node50 = ll_looped.head.next.next.next.next # Node with data 50
    node50.next = node30
    
    print("List created: 10 -> 20 -> 30 -> 40 -> 50 -> (points back to 30)")
    # We cannot call displayList() here as it would run forever
    
    print(f"Loop detected: {ll_looped.detectLoop()}") # Expected: True




