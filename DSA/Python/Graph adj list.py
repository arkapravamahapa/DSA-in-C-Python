"""
2. Write a Python program to implement Graph using Adjacency List
along with the following functions:
a) To count number of vertices and edges present in a graph.
b) To find the adjacent vertices of a given vertex.
c) To search a node in a given graph.

Note: In this Python version, we can represent the graph using a 
dictionary where keys are vertex IDs and values are lists of neighbors.
This allows for non-integer vertex names, but for this example,
we will stick to integer vertices (0 to numVertices-1) to match the C-style.
"""

class Graph:
    def __init__(self, vertices):
        """
        Initializes the graph.
        """
        self.numVertices = vertices
        # Use a dictionary to store adjacency lists
        # Keys are vertex numbers (0 to numVertices-1)
        self.adjList = {i: [] for i in range(vertices)}

    def addEdge(self, src, dest):
        """
        Function to add an edge (for an undirected graph)
        """
        if src not in self.adjList or dest not in self.adjList:
            print(f"Error: Invalid vertex index for edge {src}-{dest}.")
            return
        
        # Add edge from src to dest
        self.adjList[src].append(dest)
        # Add edge from dest to src
        self.adjList[dest].append(src)

    def countVerticesAndEdges(self):
        """
        a) To count number of vertices and edges present in a graph.
        """
        edgeCount = 0
        
        # Vertices count is the number of keys in our dict
        print(f"Vertices: {self.numVertices}")

        # Count edges. Sum the length of all lists and divide by 2.
        for vertex in self.adjList:
            edgeCount += len(self.adjList[vertex])
        
        # Each edge is counted twice, so divide by 2
        print(f"Edges: {edgeCount // 2}")

    def findAdjacentVertices(self, vertex):
        """
        b) To find the adjacent vertices of a given vertex.
        """
        if vertex not in self.adjList:
            print(f"Error: Vertex {vertex} is not in the graph.")
            return
        
        adjacent_nodes = self.adjList[vertex]
        
        print(f"Adjacent vertices of vertex {vertex}: ", end="")
        if not adjacent_nodes:
            print("None")
        else:
            # Convert list of ints to list of strings for joining
            print(" ".join(map(str, adjacent_nodes)))

    def searchNode(self, vertex):
        """
        c) To search a node in a given graph.
        (This checks if a vertex key exists)
        """
        if vertex in self.adjList:
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

    print("--- Graph (Adjacency List) ---")

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
