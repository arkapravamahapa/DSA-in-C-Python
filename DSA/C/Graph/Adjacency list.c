/*
 * 2. Write a C program to implement Graph using Adjacency List
 * along with the following functions:
 * a) To count number of vertices and edges present in a graph.
 * b) To find the adjacent vertices of a given vertex.
 * c) To search a node in a given graph.
 */

#include <stdio.h>
#include <stdlib.h>

// A node in the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// The graph structure
struct Graph {
    int numVertices;
    struct Node** adjLists; // Array of pointers to Node
};

// Function to create a new list node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with 'vertices'
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    
    // Create an array of adjacency lists
    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));
    if (!graph->adjLists) {
         printf("Memory allocation failed!\n");
         return NULL;
    }

    // Initialize each adjacency list as empty
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// Function to add an edge (for undirected graph)
void addEdge(struct Graph* graph, int src, int dest) {
    if (src >= graph->numVertices || dest >= graph->numVertices || src < 0 || dest < 0) {
        printf("Error: Invalid vertex index for edge %d-%d.\n", src, dest);
        return;
    }
    // Add edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

/*
 * a) To count number of vertices and edges present in a graph.
 */
void countVerticesAndEdges(struct Graph* graph) {
    int edgeCount = 0;
    
    // Vertices count is simply stored
    printf("Vertices: %d\n", graph->numVertices);

    // Count edges. Sum the length of all lists and divide by 2.
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* temp = graph->adjLists[i];
        while (temp) {
            edgeCount++;
            temp = temp->next;
        }
    }
    // Each edge is counted twice, so divide by 2
    printf("Edges: %d\n", edgeCount / 2);
}

/*
 * b) To find the adjacent vertices of a given vertex.
 */
void findAdjacentVertices(struct Graph* graph, int vertex) {
    if (vertex >= graph->numVertices || vertex < 0) {
        printf("Error: Vertex %d is not in the graph.\n", vertex);
        return;
    }
    
    struct Node* temp = graph->adjLists[vertex];
    
    printf("Adjacent vertices of vertex %d: ", vertex);
    if (temp == NULL) {
        printf("None");
    }
    while (temp) {
        printf("%d ", temp->vertex);
        temp = temp->next;
    }
    printf("\n");
}

/*
 * c) To search a node in a given graph.
 * (This checks if a vertex index is valid)
 */
void searchNode(struct Graph* graph, int vertex) {
    if (vertex >= 0 && vertex < graph->numVertices) {
        printf("Node %d exists in the graph.\n", vertex);
    } else {
        printf("Node %d does not exist in the graph.\n", vertex);
    }
}

// Helper function to free the graph
void freeGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* temp = graph->adjLists[i];
        while (temp) {
            struct Node* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
    }
    free(graph->adjLists);
    free(graph);
}

// Main function to demonstrate
int main() {
    int numV = 5;
    struct Graph* graph = createGraph(numV);
    
    if (graph == NULL) {
        return 1; // Exit if graph creation failed
    }

    /*
     * Create a graph like:
     * 0 --- 1
     * | \   |
     * |  \  |
     * 4---3---2
     */
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 3);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printf("--- Graph (Adjacency List) ---\n");

    // a) Count vertices and edges
    printf("\n--- Count ---\n");
    countVerticesAndEdges(graph);

    // b) Find adjacent vertices
    printf("\n--- Adjacency ---\n");
    findAdjacentVertices(graph, 0);
    findAdjacentVertices(graph, 2);
    findAdjacentVertices(graph, 6); // Test invalid vertex

    // c) Search for a node
    printf("\n--- Search ---\n");
    searchNode(graph, 3);
    searchNode(graph, 9);

    freeGraph(graph);
    return 0;
}
