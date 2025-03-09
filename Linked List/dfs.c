/*Enter the number of vertices: 5
Enter the number of edges: 4
Enter the edges (u v) for an undirected graph:
0 1
0 2
1 3
3 4
Enter the starting vertex: 0
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to perform DFS
void DFS(int vertex, int **graph, int *visited, int numVertices)
{
    printf("%d ", vertex);
    visited[vertex] = 1;

    for (int i = 0; i < numVertices; i++)
    {
        if (graph[vertex][i] == 1 && !visited[i]) // If edge exists and vertex not visited
        {
            DFS(i, graph, visited, numVertices);
        }
    }
}

int main()
{
    int numVertices, numEdges;
    int startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    // Dynamically allocate memory for the adjacency matrix
    int **graph = (int **)malloc(numVertices * sizeof(int *));
    if (!graph)
    {
        printf("Memory allocation failed for graph.\n");
        return 1;
    }
    for (int i = 0; i < numVertices; i++)
    {
        graph[i] = (int *)calloc(numVertices, sizeof(int));
        if (!graph[i])
        {
            printf("Memory allocation failed for graph row.\n");
            return 1;
        }
    }

    // Dynamically allocate memory for the visited array
    int *visited = (int *)calloc(numVertices, sizeof(int));
    if (!visited)
    {
        printf("Memory allocation failed for visited array.\n");
        return 1;
    }

    // Input the edges
    printf("Enter the edges (u v) for an undirected graph:\n");
    for (int i = 0; i < numEdges; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        if (u < 0 || u >= numVertices || v < 0 || v >= numVertices)
        {
            printf("Invalid edge: (%d, %d). Vertex index must be between 0 and %d.\n", u, v, numVertices - 1);
            return 1;
        }

        graph[u][v] = 1;
        graph[v][u] = 1; // For undirected graph
    }

    // Input starting vertex
    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    if (startVertex < 0 || startVertex >= numVertices)
    {
        printf("Invalid starting vertex: %d. It must be between 0 and %d.\n", startVertex, numVertices - 1);
        return 1;
    }

    // Perform DFS
    printf("DFS Traversal starting from vertex %d: ", startVertex);
    DFS(startVertex, graph, visited, numVertices);
    printf("\n");

    // Free the memory for graph
    for (int i = 0; i < numVertices; i++)
    {
        free(graph[i]);
    }
    free(graph);

    // Free the visited array
    free(visited);

    return 0;
}
