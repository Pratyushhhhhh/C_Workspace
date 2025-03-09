#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 100 // Maximum number of edges

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a graph
struct Graph {
    int V, E; // Number of vertices and edges
    struct Edge edges[MAX_EDGES];
};

// Structure to represent a subset for Union-Find
struct Subset {
    int parent;
    int rank;
};

// Function to find the root of an element (with path compression)
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Function to perform Union of two subsets (by rank)
void unionSubsets(struct Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

// Comparison function to sort edges by weight
int compareEdges(const void *a, const void *b) {
    struct Edge *edgeA = (struct Edge *)a;
    struct Edge *edgeB = (struct Edge *)b;
    return edgeA->weight - edgeB->weight;
}

// Function to implement Kruskal's Algorithm
void kruskalMST(struct Graph *graph) {
    int V = graph->V;
    struct Edge result[V]; // Array to store the resulting MST
    int e = 0;             // Index for result[]
    int i = 0;             // Index for sorted edges

    // Sort all edges in non-decreasing order of weight
    qsort(graph->edges, graph->E, sizeof(graph->edges[0]), compareEdges);

    // Allocate memory for Union-Find subsets
    struct Subset *subsets = (struct Subset *)malloc(V * sizeof(struct Subset));

    // Initialize subsets
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Iterate through sorted edges and construct the MST
    while (e < V - 1 && i < graph->E) {
        struct Edge nextEdge = graph->edges[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        // If including this edge doesn't form a cycle, include it in the result
        if (x != y) {
            result[e++] = nextEdge;
            unionSubsets(subsets, x, y);
        }
    }

    // Print the resulting MST
    printf("Edges in the Minimum Spanning Tree:\n");
    int totalWeight = 0;
    for (int j = 0; j < e; j++) {
        printf("%d -- %d == %d\n", result[j].src, result[j].dest, result[j].weight);
        totalWeight += result[j].weight;
    }
    printf("Total weight of MST: %d\n", totalWeight);

    free(subsets);
}

int main() {
    int V, E;

    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    struct Graph graph;
    graph.V = V;
    graph.E = E;

    printf("Enter the edges in the format (src dest weight):\n");
    for (int i = 0; i < E; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &graph.edges[i].src, &graph.edges[i].dest, &graph.edges[i].weight);
    }

    kruskalMST(&graph);

    return 0;
}
