/*
 * 2. Write a program to implement Binary Tree using linked list
 * along with all specified functions.
 */

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Helper function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Heap Overflow! Cannot allocate memory.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/*
 * a) To create a binary tree.
 * (This will be a manual, hard-coded creation in main for demo)
 */
struct Node* root = NULL; // Global root pointer

/*
 * b) To display tree using inorder (Left-Visit-Right)
 */
void displayInorder(struct Node* node) {
    if (node == NULL) {
        return;
    }
    displayInorder(node->left);   // 1. Visit left
    printf("%d ", node->data);    // 2. Visit root
    displayInorder(node->right);  // 3. Visit right
}

/*
 * c) To display tree using preorder (Visit-Left-Right)
 */
void displayPreorder(struct Node* node) {
    if (node == NULL) {
        return;
    }
    printf("%d ", node->data);    // 1. Visit root
    displayPreorder(node->left);  // 2. Visit left
    displayPreorder(node->right); // 3. Visit right
}

/*
 * d) To display tree using postorder (Left-Right-Visit)
 */
void displayPostorder(struct Node* node) {
    if (node == NULL) {
        return;
    }
    displayPostorder(node->left);  // 1. Visit left
    displayPostorder(node->right); // 2. Visit right
    printf("%d ", node->data);    // 3. Visit root
}

/*
 * e) To count number of node present in the tree.
 */
int countNodes(struct Node* node) {
    if (node == NULL) {
        return 0;
    }
    // 1 (for current node) + count(left) + count(right)
    return 1 + countNodes(node->left) + countNodes(node->right);
}

/*
 * f) To find the height of the tree.
 * (Height = number of edges in longest path from root to a leaf)
 */
int findHeight(struct Node* node) {
    if (node == NULL) {
        return -1; // Height of an empty tree is -1
    }
    int leftHeight = findHeight(node->left);
    int rightHeight = findHeight(node->right);
    
    // Return max of left/right height + 1 for the current node
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

/*
 * g) To find the number of leaf node.
 * (A leaf node has no children)
 */
int countLeafNodes(struct Node* node) {
    if (node == NULL) {
        return 0;
    }
    // If it has no children, it's a leaf
    if (node->left == NULL && node->right == NULL) {
        return 1;
    }
    // Otherwise, sum leaf nodes from left and right subtrees
    return countLeafNodes(node->left) + countLeafNodes(node->right);
}

/*
 * h) To find the number of internal node.
 * (An internal node has at least one child)
 */
int countInternalNodes(struct Node* node) {
    if (node == NULL) {
        return 0;
    }
    // If it has at least one child, it's an internal node
    if (node->left != NULL || node->right != NULL) {
        // 1 (for this node) + count from children
        return 1 + countInternalNodes(node->left) + countInternalNodes(node->right);
    }
    
    return 0; // It's a leaf node
}

/*
 * i) To search a data present in the tree.
 * (Returns 1 if found, 0 if not)
 */
int searchTree(struct Node* node, int key) {
    if (node == NULL) {
        return 0; // Key not found
    }
    if (node->data == key) {
        return 1; // Key found
    }
    
    // Search in left OR right subtree
    return searchTree(node->left, key) || searchTree(node->right, key);
}

// Helper function to free the tree
void freeTree(struct Node* node) {
    if (node == NULL) {
        return;
    }
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

// Main function to demonstrate
int main() {
    
    // a) Create tree (manual construction)
    root = createNode(10);
    root->left = createNode(20);
    root->right = createNode(30);
    root->left->left = createNode(40);
    root->left->right = createNode(50);
    root->right->left = createNode(60);

    /*
     * The tree looks like:
     * 10
     * /  \
     * 20    30
     * / \    /
     * 40  50  60
     */
     
    printf("\n--- Traversals ---\n");
    
    // b) Inorder
    printf("Inorder (LVR):   ");
    displayInorder(root); // 40 20 50 10 60 30
    printf("\n");
    
    // c) Preorder
    printf("Preorder (VLR):  ");
    displayPreorder(root); // 10 20 40 50 30 60
    printf("\n");
    
    // d) Postorder
    printf("Postorder (LRV): ");
    displayPostorder(root); // 40 50 20 60 30 10
    printf("\n");
    
    printf("\n--- Statistics ---\n");

    // e) Count Nodes
    printf("Total Nodes: %d\n", countNodes(root));
    
    // f) Find Height
    printf("Height of Tree: %d\n", findHeight(root));
    
    // g) Count Leaf Nodes
    printf("Leaf Nodes: %d\n", countLeafNodes(root));
    
    // h) Count Internal Nodes
    printf("Internal Nodes: %d\n", countInternalNodes(root));
    
    printf("\n--- Search ---\n");
    
    // i) Search
    int key = 50;
    if (searchTree(root, key)) {
        printf("Element %d found.\n", key);
    } else {
        printf("Element %d not found.\n", key);
    }
    
    key = 99;
    if (searchTree(root, key)) {
        printf("Element %d found.\n", key);
    } else {
        printf("Element %d not found.\n", key);
    }

    // Clean up memory
    freeTree(root);
    return 0;
}
