/*
 * 1. Write a C program to implement Graph using Adjacency Matrix
 * along with the following functions:
 * a) To count number of vertices and edges present in a graph.
 * b) To find the adjacent vertices of a given vertex.
 * c) To search a node in a given graph.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

struct Graph {
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
};

// Function to initialize the graph
struct Graph* createGraph(int vertices) {
    if (vertices > MAX_VERTICES) {
        printf("Error: Number of vertices exceeds maximum limit of %d\n", MAX_VERTICES);
        return NULL;
    }
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    if (!graph) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    graph->numVertices = vertices;

    // Initialize adjacency matrix to 0 (no edges)
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
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
    graph->adjMatrix[src][dest] = 1;
    // Add edge from dest to src
    graph->adjMatrix[dest][src] = 1;
}

/*
 * a) To count number of vertices and edges present in a graph.
 */
void countVerticesAndEdges(struct Graph* graph) {
    int edgeCount = 0;
    
    // Vertices count is simply stored
    printf("Vertices: %d\n", graph->numVertices);
    
    // Count edges. Since it's an undirected graph,
    // we sum the upper triangle of the matrix.
    for (int i = 0; i < graph->numVertices; i++) {
        for (int j = i; j < graph->numVertices; j++) {
            if (graph->adjMatrix[i][j] == 1) {
                edgeCount++;
            }
        }
    }
    printf("Edges: %d\n", edgeCount);
}

/*
 * b) To find the adjacent vertices of a given vertex.
 */
void findAdjacentVertices(struct Graph* graph, int vertex) {
    if (vertex >= graph->numVertices || vertex < 0) {
        printf("Error: Vertex %d is not in the graph.\n", vertex);
        return;
    }
    
    printf("Adjacent vertices of vertex %d: ", vertex);
    int found = 0;
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->adjMatrix[vertex][i] == 1) {
            printf("%d ", i);
            found = 1;
        }
    }
    if (!found) {
        printf("None");
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

    printf("--- Graph (Adjacency Matrix) ---\n");

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

    free(graph);
    return 0;
}
