"""
1. Write a program to implement the following functions for single linked list.
• createList
• insertAtFirst
• insertAtLast
• insertAtAny
• displayList
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

    def insertAtFirst(self, data):
        """Inserts a new node at the beginning of the list."""
        newNode = Node(data)
        newNode.next = self.head
        self.head = newNode
        print(f"Inserted {data} at the first.")

    def insertAtLast(self, data):
        """Inserts a new node at the end of the list."""
        newNode = Node(data)
        if self.head is None:
            self.head = newNode
            print(f"Inserted {data} at the last.")
            return

        temp = self.head
        while temp.next:
            temp = temp.next
        temp.next = newNode
        print(f"Inserted {data} at the last.")

    def insertAtAny(self, data, pos):
        """Inserts a new node at a specific position."""
        if pos < 1:
            print("Invalid position. Position must be 1 or greater.")
            return
        
        if pos == 1:
            self.insertAtFirst(data)
            return

        newNode = Node(data)
        temp = self.head
        
        # Traverse to the node *before* the target position
        try:
            for _ in range(pos - 2):
                if temp is None:
                    raise IndexError
                temp = temp.next
            
            if temp is None:
                 raise IndexError

            newNode.next = temp.next
            temp.next = newNode
            print(f"Inserted {data} at position {pos}.")
            
        except IndexError:
            print(f"Position {pos} is out of bounds.")


def main():
    """Main function with menu to create and modify the list."""
    ll = LinkedList()
    
    # createList: We build the list using this menu
    print("Creating list (initially empty)...")

    while True:
        print("\n--- SLL Insert Menu ---")
        print("1. Insert at First")
        print("2. Insert at Last")
        print("3. Insert at Any Position")
        print("4. Display List")
        print("5. Exit")
        
        try:
            choice = int(input("Enter your choice: "))
            
            if choice == 1:
                data = int(input("Enter data to insert at first: "))
                ll.insertAtFirst(data)
            elif choice == 2:
                data = int(input("Enter data to insert at last: "))
                ll.insertAtLast(data)
            elif choice == 3:
                data = int(input("Enter data: "))
                pos = int(input("Enter position: "))
                ll.insertAtAny(data, pos)
            elif choice == 4:
                ll.displayList()
            elif choice == 5:
                print("Exiting program.")
                break
            else:
                print("Invalid choice. Please try again.")
                
        except ValueError:
            print("Invalid input. Please enter a number.")

if __name__ == "__main__":
    main()




    """
2. Write a program to implement the following functions for single linked list.
• createList
• deleteFromFirst
• deleteFromLast
• deleteFromAny
• displayList
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

    def insertAtLast(self, data):
        """Helper function to populate the list."""
        newNode = Node(data)
        if self.head is None:
            self.head = newNode
            return
        temp = self.head
        while temp.next:
            temp = temp.next
        temp.next = newNode

    def deleteFromFirst(self):
        """Deletes the first node from the list."""
        if self.head is None:
            print("List is empty. Cannot delete.")
            return
        
        deletedData = self.head.data
        self.head = self.head.next
        print(f"Deleted {deletedData} from first.")

    def deleteFromLast(self):
        """Deletes the last node from the list."""
        if self.head is None:
            print("List is empty. Cannot delete.")
            return

        # If only one node
        if self.head.next is None:
            deletedData = self.head.data
            self.head = None
            print(f"Deleted {deletedData} from last.")
            return

        temp = self.head
        prev = None
        while temp.next:
            prev = temp
            temp = temp.next
        
        deletedData = temp.data
        prev.next = None
        print(f"Deleted {deletedData} from last.")

    def deleteFromAny(self, pos):
        """Deletes a node from a specific position."""
        if pos < 1:
            print("Invalid position. Position must be 1 or greater.")
            return
        
        if self.head is None:
            print("List is empty. Cannot delete.")
            return

        if pos == 1:
            self.deleteFromFirst()
            return

        temp = self.head
        prev = None
        
        try:
            for _ in range(pos - 1):
                if temp is None:
                    raise IndexError
                prev = temp
                temp = temp.next
            
            if temp is None:
                 raise IndexError

            deletedData = temp.data
            prev.next = temp.next
            print(f"Deleted {deletedData} from position {pos}.")
            
        except IndexError:
            print(f"Position {pos} is out of bounds.")

def main():
    """Main function to create and test deletion."""
    ll = LinkedList()
    
    # createList: Pre-populate the list for demo
    print("Creating and populating list...")
    ll.insertAtLast(10)
    ll.insertAtLast(20)
    ll.insertAtLast(30)
    ll.insertAtLast(40)
    ll.insertAtLast(50)
    ll.displayList()

    while True:
        print("\n--- SLL Delete Menu ---")
        print("1. Delete from First")
        print("2. Delete from Last")
        print("3. Delete from Any Position")
        print("4. Display List")
        print("5. Exit")
        
        try:
            choice = int(input("Enter your choice: "))
            
            if choice == 1:
                ll.deleteFromFirst()
            elif choice == 2:
                ll.deleteFromLast()
            elif choice == 3:
                pos = int(input("Enter position to delete: "))
                ll.deleteFromAny(pos)
            elif choice == 4:
                ll.displayList()
            elif choice == 5:
                print("Exiting program.")
                break
            else:
                print("Invalid choice. Please try again.")
                
        except ValueError:
            print("Invalid input. Please enter a number.")

if __name__ == "__main__":
    main()




    """
3. Write a program to implement all the insert and delete functions 
and display function along with an appropriate menu for a single linked list.
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

    # --- Utility Functions ---
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

    def countNodes(self):
        """Counts the total number of nodes in the list."""
        count = 0
        temp = self.head
        while temp:
            count += 1
            temp = temp.next
        return count

    # --- Insert Functions ---
    def insertAtFirst(self, data):
        """Inserts a new node at the beginning of the list."""
        newNode = Node(data)
        newNode.next = self.head
        self.head = newNode
        print(f"Inserted {data} at the first.")

    def insertAtLast(self, data):
        """Inserts a new node at the end of the list."""
        newNode = Node(data)
        if self.head is None:
            self.head = newNode
            print(f"Inserted {data} at the last.")
            return
        temp = self.head
        while temp.next:
            temp = temp.next
        temp.next = newNode
        print(f"Inserted {data} at the last.")

    def insertAtAny(self, data, pos):
        """Inserts a new node at a specific position."""
        if pos < 1:
            print("Invalid position. Position must be 1 or greater.")
            return
        if pos == 1:
            self.insertAtFirst(data)
            return
        
        newNode = Node(data)
        temp = self.head
        try:
            # Go to pos-2 to find the node *before* the target
            for _ in range(pos - 2):
                if temp is None: raise IndexError
                temp = temp.next
            if temp is None: raise IndexError
            
            newNode.next = temp.next
            temp.next = newNode
            print(f"Inserted {data} at position {pos}.")
        except (IndexError, AttributeError):
            print(f"Position {pos} is out of bounds.")

    # --- Delete Functions ---
    def deleteFromFirst(self):
        """Deletes the first node from the list."""
        if self.head is None:
            print("List is empty. Cannot delete.")
            return
        deletedData = self.head.data
        self.head = self.head.next
        print(f"Deleted {deletedData} from first.")

    def deleteFromLast(self):
        """Deletes the last node from the list."""
        if self.head is None:
            print("List is empty. Cannot delete.")
            return
        if self.head.next is None: # Single node
            deletedData = self.head.data
            self.head = None
            print(f"Deleted {deletedData} from last.")
            return
        
        temp = self.head
        prev = None
        while temp.next:
            prev = temp
            temp = temp.next
        deletedData = temp.data
        prev.next = None
        print(f"Deleted {deletedData} from last.")

    def deleteFromAny(self, pos):
        """Deletes a node from a specific position."""
        if pos < 1:
            print("Invalid position. Position must be 1 or greater.")
            return
        if self.head is None:
            print("List is empty. Cannot delete.")
            return
        if pos == 1:
            self.deleteFromFirst()
            return

        temp = self.head
        prev = None
        try:
            for _ in range(pos - 1):
                if temp is None: raise IndexError
                prev = temp
                temp = temp.next
            if temp is None: raise IndexError
            
            deletedData = temp.data
            prev.next = temp.next
            print(f"Deleted {deletedData} from position {pos}.")
        except (IndexError, AttributeError):
            print(f"Position {pos} is out of bounds.")

def main():
    """Main function with a comprehensive menu."""
    ll = LinkedList()

    while True:
        print("\n--- Singly Linked List (SLL) Menu ---")
        print("--- Insert ---")
        print("1. Insert at First")
        print("2. Insert at Last")
        print("3. Insert at Any Position")
        print("--- Delete ---")
        print("4. Delete from First")
        print("5. Delete from Last")
        print("6. Delete from Any Position")
        print("--- Utility ---")
        print("7. Display List")
        print("8. Count Nodes")
        print("9. Exit")
        print("---------------------------------------")
        
        try:
            choice = int(input("Enter your choice: "))
            
            if choice == 1:
                data = int(input("Enter data: "))
                ll.insertAtFirst(data)
            elif choice == 2:
                data = int(input("Enter data: "))
                ll.insertAtLast(data)
            elif choice == 3:
                data = int(input("Enter data: "))
                pos = int(input("Enter position: "))
                ll.insertAtAny(data, pos)
            elif choice == 4:
                ll.deleteFromFirst()
            elif choice == 5:
                ll.deleteFromLast()
            elif choice == 6:
                pos = int(input("Enter position: "))
                ll.deleteFromAny(pos)
            elif choice == 7:
                ll.displayList()
            elif choice == 8:
                print(f"Total number of nodes: {ll.countNodes()}")
            elif choice == 9:
                print("Exiting program.")
                break
            else:
                print("Invalid choice. Please try again.")

        except ValueError:
            print("Invalid input. Please enter a number.")

if __name__ == "__main__":
    main()




"""
4. Write a program to store polynomial using linked list. 
Store the term in descending order (of exponent).
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
        Inserts a new term into the polynomial, maintaining
        descending order of exponents and combining like terms.
        """
        if coeff == 0:
            return # No need to store terms with zero coefficient
            
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
            # If coeff becomes 0, we could remove the node,
            # but we'll leave it for simplicity.
        else:
            # Case 3: Insert in the middle or at the end
            newNode.next = temp
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
            # Skip terms with zero coefficient
            if temp.coeff == 0:
                temp = temp.next
                continue

            # Handle signs
            if not isFirstTerm:
                if temp.coeff > 0:
                    print(" + ", end="")
                else:
                    print(" - ", end="")
            elif temp.coeff < 0:
                 print("-", end="")
            
            coeff_abs = abs(temp.coeff)

            # Print coefficient
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

def main():
    """Main function to create and test the polynomial."""
    poly = Polynomial()
    
    while True:
        print("\n--- Polynomial Menu ---")
        print("1. Add Term (in descending order)")
        print("2. Display Polynomial")
        print("3. Exit")
        
        try:
            choice = int(input("Enter your choice: "))
            
            if choice == 1:
                coeff = int(input("Enter coefficient: "))
                exp = int(input("Enter exponent: "))
                if exp < 0:
                    print("Exponent must be non-negative.")
                    continue
                poly.insertTerm(coeff, exp)
            elif choice == 2:
                poly.displayPoly()
            elif choice == 3:
                print("Exiting...")
                break
            else:
                print("Invalid choice.")
                
        except ValueError:
            print("Invalid input. Please enter a number.")

if __name__ == "__main__":
    main()






"""
5. Write a function to count the number of node present in a linked list.
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

    # --- Core Function ---
    def countNodes(self):
        """Counts the total number of nodes in the list."""
        count = 0
        temp = self.head
        while temp:
            count += 1
            temp = temp.next
        return count

    # --- Helper Functions ---
    def insertAtLast(self, data):
        """Helper function to populate the list."""
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
            print(temp.data, end=" -> ", sep="", end="")
            temp = temp.next
        print("NULL")

def main():
    """Main function to demonstrate the node counting."""
    ll = LinkedList()

    print("--- Counting Nodes ---")
    ll.displayList()
    print(f"Total nodes: {ll.countNodes()}")
    
    print("\nPopulating list...")
    ll.insertAtLast(10)
    ll.insertAtLast(20)
    ll.insertAtLast(30)
    
    ll.displayList()
    print(f"Total nodes: {ll.countNodes()}")
    
    print("\nAdding another node...")
    ll.insertAtLast(40)
    
    ll.displayList()
    print(f"Total nodes: {ll.countNodes()}")

if __name__ == "__main__":
    main()





"""
6. Write a program to print the odd number and even number nodes 
separately from a single linked list.
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

    # --- Core Function ---
    def printOddEven(self):
        """
        Prints even and odd numbers from the list separately.
        This function traverses the list twice.
        """
        if self.head is None:
            print("List is empty.")
            return

        temp = self.head
        even_found = False
        print("Even numbers: ", end="")
        while temp:
            if temp.data % 2 == 0:
                print(temp.data, end=" ")
                even_found = True
            temp = temp.next
        if not even_found:
            print("None", end="")
        print() # Newline

        temp = self.head # Reset for second pass
        odd_found = False
        print("Odd numbers:  ", end="")
        while temp:
            if temp.data % 2 != 0:
                print(temp.data, end=" ")
                odd_found = True
            temp = temp.next
        if not odd_found:
            print("None", end="")
        print() # Newline

    # --- Helper Functions ---
    def insertAtLast(self, data):
        """Helper function to populate the list."""
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
        print("Full List: ", end="")
        while temp:
            print(temp.data, end=" -> ", sep="", end="")
            temp = temp.next
        print("NULL")

def main():
    """Main function to demonstrate odd/even printing."""
    ll = LinkedList()

    print("Enter numbers to add to the list (enter 'done' to stop):")
    while True:
        try:
            entry = input("Enter number: ")
            if entry.lower() == 'done':
                break
            data = int(entry)
            ll.insertAtLast(data)
        except ValueError:
            print("Invalid input. Please enter an integer or 'done'.")
    
    print()
    ll.displayList()
    print("\n--- Odd/Even Separation ---")
    ll.printOddEven()

if __name__ == "__main__":
    main()
