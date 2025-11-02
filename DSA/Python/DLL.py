"""
1. Write a python program to create a Double linked list along with
   all specified insert, delete, search, count, and display
   functions, and a menu.
"""

class Node:
    """
    A node in a doubly linked list.
    """
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

class DoublyLinkedList:
    """
    A class representing the doubly linked list.
    """
    def __init__(self):
        self.head = None

    def displayList(self):
        """
        (a) Displays the elements of the Double Linked List.
        """
        if self.head is None:
            print("List is empty.")
            return
        
        temp = self.head
        print("List (Head to Tail): Head <-> ", end="")
        while temp:
            print(temp.data, end=" <-> ")
            temp = temp.next
        print("NULL")

    def insertAtFirst(self, data):
        """
        (b) Adds an element at the beginning of the list.
        """
        newNode = Node(data)
        if self.head is None:
            self.head = newNode
        else:
            newNode.next = self.head
            self.head.prev = newNode
            self.head = newNode
        print(f"Inserted {data} at the beginning.")

    def insertAtLast(self, data):
        """
        (c) Adds an element at the end of the list.
        """
        newNode = Node(data)
        if self.head is None:
            self.head = newNode
            return
        
        temp = self.head
        while temp.next:
            temp = temp.next
            
        temp.next = newNode
        newNode.prev = temp
        print(f"Inserted {data} at the end.")

    def countNodes(self):
        """
        (f) Counts the number of nodes in the list.
        Helper function for inserts/deletes.
        """
        count = 0
        temp = self.head
        while temp:
            count += 1
            temp = temp.next
        return count

    def insertAtAny(self, data, pos):
        """
        (d) Adds an element at any user-given position.
        """
        if pos < 1:
            print("Invalid position. Position must be 1 or greater.")
            return

        if pos == 1:
            self.insertAtFirst(data)
            return

        total_nodes = self.countNodes()
        if pos > total_nodes + 1:
            print(f"Invalid position. List has {total_nodes} nodes.")
            return
        
        if pos == total_nodes + 1:
            self.insertAtLast(data)
            return

        # Insert in the middle
        newNode = Node(data)
        temp = self.head
        for _ in range(1, pos - 1):
            temp = temp.next
            
        newNode.next = temp.next
        newNode.prev = temp
        temp.next.prev = newNode
        temp.next = newNode
        print(f"Inserted {data} at position {pos}.")

    def searchElement(self, key):
        """
        (e) Searches for a user-given element in the list.
        """
        if self.head is None:
            print("List is empty. Cannot search.")
            return

        temp = self.head
        pos = 1
        found = False
        while temp:
            if temp.data == key:
                print(f"Element {key} found at position {pos}.")
                found = True
            temp = temp.next
            pos += 1
            
        if not found:
            print(f"Element {key} not found in the list.")

    def deleteFromFirst(self):
        """
        (g) Deletes a node from the beginning of the list.
        """
        if self.head is None:
            print("List is empty. Cannot delete.")
            return
            
        data = self.head.data
        if self.head.next is None: # Only one node
            self.head = None
        else:
            self.head = self.head.next
            self.head.prev = None
            
        print(f"Deleted {data} from the beginning.")

    def deleteFromLast(self):
        """
        (h) Deletes a node from the end of the list.
        """
        if self.head is None:
            print("List is empty. Cannot delete.")
            return

        if self.head.next is None: # Only one node
            data = self.head.data
            self.head = None
            print(f"Deleted {data} from the end.")
            return

        temp = self.head
        while temp.next:
            temp = temp.next
            
        data = temp.data
        temp.prev.next = None
        print(f"Deleted {data} from the end.")

    def deleteFromAny(self, pos):
        """
        (i) Deletes a node from any position in the list.
        """
        if self.head is None:
            print("List is empty. Cannot delete.")
            return
            
        if pos < 1:
            print("Invalid position.")
            return

        if pos == 1:
            self.deleteFromFirst()
            return
            
        total_nodes = self.countNodes()
        if pos > total_nodes:
            print(f"Invalid position. List has {total_nodes} nodes.")
            return
            
        if pos == total_nodes:
            self.deleteFromLast()
            return

        # Delete from the middle
        temp = self.head
        for _ in range(1, pos):
            temp = temp.next
            
        data = temp.data
        temp.prev.next = temp.next
        temp.next.prev = temp.prev
        print(f"Deleted {data} from position {pos}.")

def main_dll():
    """Main function with menu for Doubly Linked List."""
    dll = DoublyLinkedList()
    
    while True:
        print("\n--- Doubly Linked List Menu ---")
        print(" 1. Display List (a)")
        print(" 2. Insert at First (b)")
        print(" 3. Insert at Last (c)")
        print(" 4. Insert at Any Position (d)")
        print(" 5. Search Element (e)")
        print(" 6. Count Nodes (f)")
        print(" 7. Delete from First (g)")
        print(" 8. Delete from Last (h)")
        print(" 9. Delete from Any Position (i)")
        print(" 0. Exit")
        print("---------------------------------")
        
        try:
            choice = int(input("Enter your choice: "))
        except ValueError:
            print("Invalid input. Please enter a number.")
            continue

        if choice == 1:
            dll.displayList()
        elif choice == 2:
            try:
                data = int(input("Enter data to insert at first: "))
                dll.insertAtFirst(data)
            except ValueError:
                print("Invalid data. Please enter an integer.")
        elif choice == 3:
            try:
                data = int(input("Enter data to insert at last: "))
                dll.insertAtLast(data)
            except ValueError:
                print("Invalid data. Please enter an integer.")
        elif choice == 4:
            try:
                data = int(input("Enter data: "))
                pos = int(input("Enter position: "))
                dll.insertAtAny(data, pos)
            except ValueError:
                print("Invalid data or position. Please enter integers.")
        elif choice == 5:
            try:
                key = int(input("Enter element to search: "))
                dll.searchElement(key)
            except ValueError:
                print("Invalid key. Please enter an integer.")
        elif choice == 6:
            count = dll.countNodes()
            print(f"Total number of nodes: {count}")
        elif choice == 7:
            dll.deleteFromFirst()
        elif choice == 8:
            dll.deleteFromLast()
        elif choice == 9:
            try:
                pos = int(input("Enter position to delete: "))
                dll.deleteFromAny(pos)
            except ValueError:
                print("Invalid position. Please enter an integer.")
        elif choice == 0:
            print("Exiting program.")
            break
        else:
            print("Invalid choice. Please enter a number between 0 and 9.")

if __name__ == "__main__":
    main_dll()
