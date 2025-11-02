// Write a Python program to implement a stack.

class Stack:
    """A simple stack implementation using a Python list."""
    def __init__(self):
        """Initializes an empty stack."""
        self.items = []
        print("Stack created.")
    def is_empty(self):
        """Returns True if the stack is empty, False otherwise."""
        return len(self.items) == 0

    def push(self, item):
        """Adds an item to the top of the stack."""
        self.items.append(item)
        print(f"Pushed: {item}")

    def pop(self):
        """Removes and returns the item from the top of the stack."""
        if self.is_empty():
            print("Stack is empty. Cannot pop.")
            return None
        item = self.items.pop()
        print(f"Popped: {item}")
        return item

    def peek(self):
        """Returns the item at the top of the stack without removing it."""
        if self.is_empty():
            print("Stack is empty. Cannot peek.")
            return None
        item = self.items[-1]
        print(f"Peek: {item}")
        return item

    def size(self):
        """Returns the number of items in the stack."""
        return len(self.items)

    def display(self):
        """Displays the items in the stack from top to bottom."""
        if self.is_empty():
            print("Stack is empty.")
            return
        print("Stack (top to bottom):")
        for item in reversed(self.items):
            print(f"- {item}")

# --- Demonstration ---
if __name__ == "__main__":
    my_stack = Stack()
    
    my_stack.push("Apple")
    my_stack.push("Banana")
    my_stack.push("Cherry")
    
    my_stack.display()
    
    my_stack.peek()
    
    my_stack.pop()
    my_stack.display()
    
    my_stack.pop()
    my_stack.pop()
    
    my_stack.pop() # Try to pop from empty stack
    my_stack.display()




//Write a Python program to implement a queue.
//We will use collections.deque for an efficient O(1) implementation.

from collections import deque

class Queue:
    """A simple queue implementation using collections.deque."""
    
    def __init__(self):
        """Initializes an empty queue."""
        self.items = deque()
        print("Queue created.")

    def is_empty(self):
        """Returns True if the queue is empty, False otherwise."""
        return len(self.items) == 0

    def enqueue(self, item):
        """Adds an item to the end (rear) of the queue."""
        self.items.append(item)
        print(f"Enqueued: {item}")

    def dequeue(self):
        """Removes and returns the item from the beginning (front) of the queue."""
        if self.is_empty():
            print("Queue is empty. Cannot dequeue.")
            return None
        item = self.items.popleft()
        print(f"Dequeued: {item}")
        return item

    def front(self):
        """Returns the item at the front of the queue without removing it."""
        if self.is_empty():
            print("Queue is empty. Cannot get front.")
            return None
        item = self.items[0]
        print(f"Front: {item}")
        return item

    def size(self):
        """Returns the number of items in the queue."""
        return len(self.items)

    def display(self):
        """Displays the items in the queue from front to rear."""
        if self.is_empty():
            print("Queue is empty.")
            return
        print("Queue (front to rear):")
        print(" -> ".join(str(item) for item in self.items))

# --- Demonstration ---
if __name__ == "__main__":
    my_queue = Queue()  
    my_queue.enqueue("First")
    my_queue.enqueue("Second")
    my_queue.enqueue("Third")  
    my_queue.display()   
    my_queue.front()  
    my_queue.dequeue()
    my_queue.display()   
    my_queue.dequeue()
    my_queue.dequeue()
    my_queue.dequeue() # Try to dequeue from empty queue
    my_queue.display()




//Write a Python program to reverse a string using stack (using array).
//In Python, a list serves as a dynamic array and a stack.

def reverse_string_with_stack(text):
    """Reverses a string using a stack (implemented as a list)."""
    
    # 1. Create an empty stack (list)
    stack = []
    
    # 2. Push all characters of the string onto the stack
    for char in text:
        stack.append(char)
        
    print(f"Stack (top to bottom): {list(reversed(stack))}")
    
    # 3. Pop all characters from the stack and build the reversed string
    reversed_text = ""
    while len(stack) > 0:
        reversed_text += stack.pop()
        
    return reversed_text

# --- Demonstration ---
if __name__ == "__main__":
    original_string = "Hello, World!"
    
    print(f"Original string: {original_string}")
    
    reversed_string = reverse_string_with_stack(original_string)
    
    print(f"Reversed string: {reversed_string}")

    original_string_2 = "Python"
    print(f"\nOriginal string: {original_string_2}")
    reversed_string_2 = reverse_string_with_stack(original_string_2)
    print(f"Reversed string: {reversed_string_2}")







    ///////// Write a Python program to implement circular queue using array.////

class CircularQueue:
    """An implementation of a circular queue using a fixed-size list."""
    
    def __init__(self, capacity):
        """
        Initializes the circular queue.
        :param capacity: The maximum number of items the queue can hold.
        """
        if capacity <= 0:
            raise ValueError("Capacity must be positive.")
            
        self.capacity = capacity
        self.queue = [None] * capacity
        self.front = -1  # Index of the front element
        self.rear = -1   # Index of the rear element
        self.size = 0    # Current number of elements
        print(f"Circular Queue created with capacity {self.capacity}")

    def is_empty(self):
        """Returns True if the queue is empty."""
        return self.size == 0

    def is_full(self):
        """Returns True if the queue is full."""
        return self.size == self.capacity

    def enqueue(self, item):
        """Adds an item to the rear of the queue."""
        if self.is_full():
            print("Queue is full. Cannot enqueue.")
            return

        if self.is_empty():
            self.front = 0
        
        # Move rear to the next position in a circular way
        self.rear = (self.rear + 1) % self.capacity
        
        self.queue[self.rear] = item
        self.size += 1
        print(f"Enqueued: {item}")

    def dequeue(self):
        """Removes and returns the item from the front of the queue."""
        if self.is_empty():
            print("Queue is empty. Cannot dequeue.")
            return None

        item = self.queue[self.front]
        self.queue[self.front] = None  # Optional: clear the space
        self.size -= 1

        if self.is_empty():
            # Reset pointers when queue becomes empty
            self.front = -1
            self.rear = -1
        else:
            # Move front to the next position in a circular way
            self.front = (self.front + 1) % self.capacity
            
        print(f"Dequeued: {item}")
        return item

    def front_item(self):
        """Returns the front item without removing it."""
        if self.is_empty():
            print("Queue is empty. Cannot get front.")
            return None
        return self.queue[self.front]

    def rear_item(self):
        """Returns the rear item without removing it."""
        if self.is_empty():
            print("Queue is empty. Cannot get rear.")
            return None
        return self.queue[self.rear]

    def display(self):
        """Displays the items in the queue from front to rear."""
        if self.is_empty():
            print("Queue is empty.")
            return

        print("Queue (front to rear):")
        
        # Iterate circularly from front to rear
        i = self.front
        for _ in range(self.size):
            print(f"- {self.queue[i]}")
            i = (i + 1) % self.capacity
            
        print(f"Internal Array: {self.queue}")
        print(f"(Front at index {self.front}, Rear at index {self.rear})")


# --- Demonstration ---
if __name__ == "__main__":
    cq = CircularQueue(5)   
    cq.enqueue(10)
    cq.enqueue(20)
    cq.enqueue(30)
    cq.display()  
    cq.dequeue()
    cq.display()    
    cq.enqueue(40)
    cq.enqueue(50)
    cq.enqueue(60) # This should be full
    cq.display()   
    cq.enqueue(70) # Should fail    
    cq.dequeue()
    cq.dequeue()
    cq.display()
    cq.enqueue(70)
    cq.display()
    cq.dequeue()
    cq.dequeue()
    cq.dequeue()
    cq.display() # Should be empty   
    cq.dequeue() # Should fail






/////////// Given a stack of boxes in different colors. Write a python function///////
# that accepts the stack of boxes and removes those boxes having color
# other than the primary colors (Red, Green and Blue) from the stack.
# The removed boxes should be en-queued into a new queue and returned.
# The original stack should have only the boxes having primary colors
# and the order must be maintained.

from collections import deque

def filter_primary_colors(box_stack: list) -> deque:
    """
    Filters a stack of colored boxes.
    
    Keeps only 'Red', 'Green', or 'Blue' boxes in the original stack,
    maintaining their order.
    
    Returns a queue containing all other removed boxes.
    
    :param box_stack: The original stack (list) of boxes (colors).
    :return: A deque (queue) with the removed boxes.
    """
    
    primary_colors = {"Red", "Green", "Blue"}
    
    # 1. Create a temporary stack to hold primary-colored boxes
    #    (This reverses the order temporarily)
    temp_primary_stack = []
    
    # 2. Create the queue for other-colored boxes
    other_colors_queue = deque()
    
    # 3. Process the original stack
    print(f"Processing stack...")
    while len(box_stack) > 0:
        box = box_stack.pop()
        
        if box in primary_colors:
            # Add to temp stack
            temp_primary_stack.append(box)
            print(f"  - '{box}' is primary. (Moved to temp stack)")
        else:
            # Add to the new queue
            other_colors_queue.appendleft(box) # appendleft to maintain pop order
            print(f"  - '{box}' is NOT primary. (Enqueued)")

    # 4. Restore the primary-colored boxes to the original stack
    #    This reverses them back to their original stacked order.
    print(f"\nRestoring primary boxes to original stack...")
    while len(temp_primary_stack) > 0:
        box_stack.append(temp_primary_stack.pop())
        
    # 5. Return the queue of other boxes
    return other_colors_queue

# --- Demonstration ---
if __name__ == "__main__":
    
    # Original stack (bottom-to-top)
    original_stack = [
        "Red",      # Bottom
        "Yellow",
        "Green",
        "Blue",
        "Magenta",
        "Red",
        "Cyan"      # Top
    ]
    
    print("--- Box Color Filter ---")
    print(f"Original stack (bottom to top): {original_stack}")
    
    # The function modifies the original_stack in-place
    removed_boxes_queue = filter_primary_colors(original_stack)
    
    print("\n--- Results ---")
    print(f"Original stack after filtering (bottom to top): {original_stack}")
    print(f"Queue of removed boxes (front to rear): {list(removed_boxes_queue)}")

    # Test 2: Stack with no primary colors
    print("\n--- Test 2 ---")
    stack_2 = ["Yellow", "Magenta", "Cyan"]
    print(f"Original stack: {stack_2}")
    queue_2 = filter_primary_colors(stack_2)
    print(f"Filtered stack: {stack_2}")
    print(f"Removed queue: {list(queue_2)}")

    # Test 3: Stack with only primary colors
    print("\n--- Test 3 ---")
    stack_3 = ["Red", "Green", "Blue"]
    print(f"Original stack: {stack_3}")
    queue_3 = filter_primary_colors(stack_3)
    print(f"Filtered stack: {stack_3}")
    print(f"Removed queue: {list(queue_3)}")

