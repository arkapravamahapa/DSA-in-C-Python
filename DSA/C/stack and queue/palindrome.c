/*
5. Write a C program to find the palindrome using appropriate ADT to implement
   a more powerful version of the is_palindrome() function.
   Your solution should ignore whitespace and punctuation, and all 
   comparisons should be case-insensitive.
   (ADT Used: Stack and Queue)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include <ctype.h>

// --- Stack Implementation ---
struct Stack {
    int top;
    unsigned capacity;
    char* array; // Use char for this problem
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

bool isFull_s(struct Stack* stack) { return stack->top == stack->capacity - 1; }
bool isEmpty_s(struct Stack* stack) { return stack->top == -1; }

void push(struct Stack* stack, char item) {
    if (isFull_s(stack)) return;
    stack->array[++stack->top] = item;
}

char pop(struct Stack* stack) {
    if (isEmpty_s(stack)) return '\0';
    return stack->array[stack->top--];
}

void freeStack(struct Stack* stack) {
    free(stack->array);
    free(stack);
}
// --- End Stack Implementation ---

// --- Queue Implementation ---
struct Queue {
    int front, rear, size;
    unsigned capacity;
    char* array; // Use char for this problem
};

struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1; 
    queue->array = (char*)malloc(queue->capacity * sizeof(char));
    return queue;
}

bool isFull_q(struct Queue* queue) { return (queue->size == queue->capacity); }
bool isEmpty_q(struct Queue* queue) { return (queue->size == 0); }

void enqueue(struct Queue* queue, char item) {
    if (isFull_q(queue)) return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

char dequeue(struct Queue* queue) {
    if (isEmpty_q(queue)) return '\0';
    char item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

void freeQueue(struct Queue* queue) {
    free(queue->array);
    free(queue);
}
// --- End Queue Implementation ---

/*
bool is_palindrome(char *text)
Return true if text is a palindrome, false otherwise.
Ignores case, whitespace, and punctuation.
*/
bool is_palindrome(char* text) {
    int len = strlen(text);
    if (len <= 1) return true;

    struct Stack* stack = createStack(len);
    struct Queue* queue = createQueue(len);

    // Add only alphabetic characters to the stack and queue
    for (int i = 0; i < len; i++) {
        if (isalpha((unsigned char)text[i])) {
            char c = tolower((unsigned char)text[i]);
            push(stack, c);
            enqueue(queue, c);
        }
    }

    bool palindrome = true;
    // Compare characters popped from stack and dequeued from queue
    while (!isEmpty_s(stack) && !isEmpty_q(queue)) {
        if (pop(stack) != dequeue(queue)) {
            palindrome = false;
            break;
        }
    }

    freeStack(stack);
    freeQueue(queue);
    return palindrome;
}

// Main function to test the is_palindrome function
int main() {
    printf("--- Q5: Palindrome Checker (Advanced) ---\n");

    char* test_cases[] = {
        "",
        "a",
        "aa",
        "aaa",
        "aba",
        "abba",
        "abc",
        "Taco cat",
        "Madam, I'm Adam",
        "A man, a plan, a canal: Panama",
        "Doc, note: I dissent. A fast never prevents a fatness. I diet on cod.",
        "Not a palindrome"
    };
    int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    printf("Running test cases:\n");
    for (int i = 0; i < num_cases; i++) {
        bool result = is_palindrome(test_cases[i]);
        printf("Result: %-5s | \"%s\"\n", result ? "true" : "false", test_cases[i]);
    }
    
    return 0;
}

