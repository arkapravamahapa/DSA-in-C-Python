/*
 * 7. Write a C program to implement the concept of Hashing.
 * (This example uses a simple hash table with linear probing
 * to store integer keys in a hash set)
 */

#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10
#define EMPTY -1 // Sentinel value for an empty slot

int hashTable[TABLE_SIZE];

// Simple hash function
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Initialize hash table
void initHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = EMPTY;
    }
}

// Insert a key into the hash table
void insert(int key) {
    int index = hashFunction(key);
    int originalIndex = index;
    
    // Linear probing to find an empty slot
    while (hashTable[index] != EMPTY) {
        // Probe to the next slot
        index = (index + 1) % TABLE_SIZE;
        
        // Check if table is full or we've looped back
        if (index == originalIndex) {
            printf("Hash table is full! Cannot insert %d.\n", key);
            return;
        }
    }
    
    // Found an empty slot
    hashTable[index] = key;
    printf("Inserted %d at index %d\n", key, index);
}

// Search for a key in the hash table
// Returns 1 if found, 0 if not
int search(int key) {
    int index = hashFunction(key);
    int originalIndex = index;

    while (hashTable[index] != EMPTY) {
        if (hashTable[index] == key) {
            return 1; // Found
        }
        
        // Probe to the next slot
        index = (index + 1) % TABLE_SIZE;
        
        // If we loop back, the key is not present
        if (index == originalIndex) {
            return 0; // Not found
        }
    }
    
    return 0; // Not found (hit an empty slot)
}

// Function to display the hash table
void printHashTable() {
    printf("\nHash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("[%d] -> %d\n", i, hashTable[i]);
    }
}

// Main function to demonstrate hashing
int main() {
    initHashTable();
    
    insert(5);
    insert(25); // Collision with 5
    insert(15); // Collision with 5 and 25
    insert(8);
    insert(18); // Collision with 8
    
    printHashTable();
    
    printf("\nSearching for 15: %s\n", search(15) ? "Found" : "Not Found");
    printf("Searching for 8:  %s\n", search(8) ? "Found" : "Not Found");
    printf("Searching for 99: %s\n", search(99) ? "Found" : "Not Found");

    return 0;
}
