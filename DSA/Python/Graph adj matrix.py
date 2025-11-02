"""
1. Write a Python program to implement Graph using Adjacency Matrix
along with the following functions:
a) To count number of vertices and edges present in a graph.
b) To find the adjacent vertices of a given vertex.
c) To search a node in a given graph.
"""

class Graph:
    def __init__(self, vertices):
        """
        Initializes the graph with a given number of vertices.
        """
        self.numVertices = vertices
        # Initialize adjacency matrix with 0s
        self.adjMatrix = [[0] * vertices for _ in range(vertices)]

    def addEdge(self, src, dest):
        """
        Function to add an edge (for an undirected graph)
        """
        if src >= self.numVertices or dest >= self.numVertices or src < 0 or dest < 0:
            print(f"Error: Invalid vertex index for edge {src}-{dest}.")
            return
        
        # Add edge from src to dest
        self.adjMatrix[src][dest] = 1
        # Add edge from dest to src
        self.adjMatrix[dest][src] = 1

    def countVerticesAndEdges(self):
        """
        a) To count number of vertices and edges present in a graph.
        """
        edgeCount = 0
        
        # Vertices count is simply stored
        print(f"Vertices: {self.numVertices}")
        
        # Count edges. Since it's undirected,
        # we sum the upper triangle of the matrix.
        for i in range(self.numVertices):
            for j in range(i, self.numVertices):
                if self.adjMatrix[i][j] == 1:
                    edgeCount += 1
        print(f"Edges: {edgeCount}")

    def findAdjacentVertices(self, vertex):
        """
        b) To find the adjacent vertices of a given vertex.
        """
        if vertex >= self.numVertices or vertex < 0:
            print(f"Error: Vertex {vertex} is not in the graph.")
            return
        
        print(f"Adjacent vertices of vertex {vertex}: ", end="")
        found = False
        adjacent_nodes = []
        for i in range(self.numVertices):
            if self.adjMatrix[vertex][i] == 1:
                adjacent_nodes.append(str(i))
                found = True
        
        if not found:
            print("None")
        else:
            print(" ".join(adjacent_nodes))

    def searchNode(self, vertex):
        """
        c) To search a node in a given graph.
        (This checks if a vertex index is valid)
        """
        if 0 <= vertex < self.numVertices:
            print(f"Node {vertex} exists in the graph.")
        else:
            print(f"Node {vertex} does not exist in the graph.")

# Main function to demonstrate
if __name__ == "__main__":
    numV = 5
    graph = Graph(numV)

    """
    Create a graph like:
    0 --- 1
    | \   |
    |  \  |
    4---3---2
    """
    graph.addEdge(0, 1)
    graph.addEdge(0, 3)
    graph.addEdge(0, 4)
    graph.addEdge(1, 2)
    graph.addEdge(2, 3)
    graph.addEdge(3, 4)

    print("--- Graph (Adjacency Matrix) ---")

    # a) Count vertices and edges
    print("\n--- Count ---")
    graph.countVerticesAndEdges()

    # b) Find adjacent vertices
    print("\n--- Adjacency ---")
    graph.findAdjacentVertices(0)
    graph.findAdjacentVertices(2)
    graph.findAdjacentVertices(6)  # Test invalid vertex

    # c) Search for a node
    print("\n--- Search ---")
    graph.searchNode(3)
    graph.searchNode(9)
