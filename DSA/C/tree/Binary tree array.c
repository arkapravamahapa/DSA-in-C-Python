/*
 * 1. Write a program to implement Binary Tree using array along with
 * all specified functions.
 *
 * Note: This implementation uses a simple array representation where
 * left child of index i is at 2*i + 1
 * right child of index i is at 2*i + 2
 *
 * '-1' is used to represent an empty node.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Maximum number of nodes in the tree

int tree[MAX_SIZE];
int totalNodes = 0;

// Initialize the tree with -1 (empty)
void initTree() {
    for (int i = 0; i < MAX_SIZE; i++) {
        tree[i] = -1;
    }
}

/*
 * a) To create a binary tree.
 * (This function sets the root node)
 */
void createTree(int data) {
    if (tree[0] != -1) {
        printf("Tree already has a root.\n");
        return;
    }
    tree[0] = data;
    totalNodes = 1;
    printf("Root node with data %d created.\n", data);
}

// Helper function to set left/right child
void setLeft(int data, int parentIndex) {
    if (tree[parentIndex] == -1) {
        printf("Parent at index %d does not exist.\n", parentIndex);
        return;
    }
    int leftIndex = (2 * parentIndex) + 1;
    if (leftIndex >= MAX_SIZE) {
        printf("Array size limit reached. Cannot insert left child.\n");
        return;
    }
    if (tree[leftIndex] != -1) {
        printf("Left child at index %d already exists.\n", leftIndex);
    } else {
        tree[leftIndex] = data;
        totalNodes++;
        printf("Set %d as left child of %d (at index %d).\n", data, tree[parentIndex], parentIndex);
    }
}

void setRight(int data, int parentIndex) {
    if (tree[parentIndex] == -1) {
        printf("Parent at index %d does not exist.\n", parentIndex);
        return;
    }
    int rightIndex = (2 * parentIndex) + 2;
    if (rightIndex >= MAX_SIZE) {
        printf("Array size limit reached. Cannot insert right child.\n");
        return;
    }
    if (tree[rightIndex] != -1) {
        printf("Right child at index %d already exists.\n", rightIndex);
    } else {
        tree[rightIndex] = data;
        totalNodes++;
        printf("Set %d as right child of %d (at index %d).\n", data, tree[parentIndex], parentIndex);
    }
}

/*
 * b) To display tree using inorder.
 */
void displayInorder(int index) {
    if (index >= MAX_SIZE || tree[index] == -1) {
        return; // Node is empty or out of bounds
    }
    // 1. Visit left child
    displayInorder((2 * index) + 1);
    // 2. Visit root
    printf("%d ", tree[index]);
    // 3. Visit right child
    displayInorder((2 * index) + 2);
}

/*
 * c) To display tree using preorder.
 */
void displayPreorder(int index) {
    if (index >= MAX_SIZE || tree[index] == -1) {
        return;
    }
    // 1. Visit root
    printf("%d ", tree[index]);
    // 2. Visit left child
    displayPreorder((2 * index) + 1);
    // 3. Visit right child
    displayPreorder((2 * index) + 2);
}

/*
 * d) To display tree using postorder.
 */
void displayPostorder(int index) {
    if (index >= MAX_SIZE || tree[index] == -1) {
        return;
    }
    // 1. Visit left child
    displayPostorder((2 * index) + 1);
    // 2. Visit right child
    displayPostorder((2 * index) + 2);
    // 3. Visit root
    printf("%d ", tree[index]);
}

/*
 * e) To count number of node present in the tree.
 * (We use the globally tracked 'totalNodes' variable)
 */
int countNodes() {
    return totalNodes;
}

/*
 * f) To find the height of the tree.
 */
int findHeight(int index) {
    if (index >= MAX_SIZE || tree[index] == -1) {
        return -1; // Height of an empty node
    }
    int leftHeight = findHeight((2 * index) + 1);
    int rightHeight = findHeight((2 * index) + 2);
    
    // Return max of left/right height + 1 for the current node
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

/*
 * g) To find the number of leaf node.
 */
int countLeafNodes(int index) {
    if (index >= MAX_SIZE || tree[index] == -1) {
        return 0; // Empty node is not a leaf
    }
    
    int leftIndex = (2 * index) + 1;
    int rightIndex = (2 * index) + 2;

    // Check if left child is out of bounds or empty
    int isLeftEmpty = (leftIndex >= MAX_SIZE || tree[leftIndex] == -1);
    // Check if right child is out of bounds or empty
    int isRightEmpty = (rightIndex >= MAX_SIZE || tree[rightIndex] == -1);

    // If both children are empty, it's a leaf node
    if (isLeftEmpty && isRightEmpty) {
        return 1;
    }
    
    // Otherwise, sum leaf nodes from left and right subtrees
    return countLeafNodes(leftIndex) + countLeafNodes(rightIndex);
}

/*
 * h) To find the number of internal node.
 * (Internal node = Total nodes - Leaf nodes)
 */
int countInternalNodes(int index) {
    // An internal node is any node that is not a leaf.
    // We can get this by (Total Nodes - Leaf Nodes)
    // Or we can count recursively:
    
    if (index >= MAX_SIZE || tree[index] == -1) {
        return 0; // Empty node
    }

    int leftIndex = (2 * index) + 1;
    int rightIndex = (2 * index) + 2;
    int isLeftEmpty = (leftIndex >= MAX_SIZE || tree[leftIndex] == -1);
    int isRightEmpty = (rightIndex >= MAX_SIZE || tree[rightIndex] == -1);

    // If it has at least one child, it's an internal node
    if (!isLeftEmpty || !isRightEmpty) {
        // 1 (for this node) + count from children
        return 1 + countInternalNodes(leftIndex) + countInternalNodes(rightIndex);
    }
    
    return 0; // It's a leaf node
}

/*
 * i) To search a data present in the tree.
 */
int searchTree(int data) {
    for (int i = 0; i < MAX_SIZE; i++) {
        if (tree[i] == data) {
            return i; // Return index where data was found
        }
    }
    return -1; // Not found
}

// Main function to demonstrate
int main() {
    initTree();
    
    // a) Create tree
    // Root at index 0
    createTree(10); 
    
    // Children of root (index 0)
    setLeft(20, 0);  // at index 1
    setRight(30, 0); // at index 2
    
    // Children of node 20 (index 1)
    setLeft(40, 1);  // at index 3
    setRight(50, 1); // at index 4

    // Children of node 30 (index 2)
    setLeft(60, 2);  // at index 5

    /*
     * The tree looks like:
     * 10 (0)
     * /  \
     * 20(1)  30(2)
     * / \    /
     * 40(3) 50(4) 60(5)
     */
     
    printf("\n--- Traversals ---\n");
    
    // b) Inorder
    printf("Inorder (LVR):   ");
    displayInorder(0); // 0 is the root index
    printf("\n");
    
    // c) Preorder
    printf("Preorder (VLR):  ");
    displayPreorder(0);
    printf("\n");
    
    // d) Postorder
    printf("Postorder (LRV): ");
    displayPostorder(0);
    printf("\n");
    
    printf("\n--- Statistics ---\n");

    // e) Count Nodes
    printf("Total Nodes: %d\n", countNodes());
    
    // f) Find Height
    printf("Height of Tree: %d\n", findHeight(0));
    
    // g) Count Leaf Nodes
    printf("Leaf Nodes: %d\n", countLeafNodes(0));
    
    // h) Count Internal Nodes
    printf("Internal Nodes: %d\n", countInternalNodes(0));
    
    printf("\n--- Search ---\n");
    
    // i) Search
    int key = 50;
    int result = searchTree(key);
    if (result != -1) {
        printf("Element %d found at index %d.\n", key, result);
    } else {
        printf("Element %d not found.\n", key);
    }
    
    key = 99;
    result = searchTree(key);
    if (result != -1) {
        printf("Element %d found at index %d.\n", key, result);
    } else {
        printf("Element %d not found.\n", key);
    }

    return 0;
}
