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

// Function to perform BFS
void BFS(int start, int **graph, int numVertices)
{
    int *queue = (int *)malloc(numVertices * sizeof(int));
    if (!queue)
    {
        printf("Memory allocation failed for queue.\n");
        return;
    }
    int front = 0, rear = 0;
    bool *visited = (bool *)calloc(numVertices, sizeof(bool));
    if (!visited)
    {
        printf("Memory allocation failed for visited array.\n");
        free(queue);
        return;
    }

    queue[rear++] = start; // Enqueue the start vertex
    visited[start] = true;

    while (front < rear) // While the queue is not empty
    {
        int current = queue[front++]; // Dequeue the front vertex
        printf("%d ", current);

        for (int i = 0; i < numVertices; i++)
        {
            if (graph[current][i] == 1 && !visited[i]) // If edge exists and vertex not visited
            {
                queue[rear++] = i; // Enqueue the vertex
                visited[i] = true;
            }
        }
    }

    free(queue);
    free(visited);
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
        graph[u][v] = 1;
        graph[v][u] = 1; // For undirected graph
    }

    // Input starting vertex
    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    // Perform DFS
    printf("DFS Traversal:\n");
    DFS(startVertex, graph, visited, numVertices);
    printf("\n");

    // Reset visited array for BFS
    for (int i = 0; i < numVertices; i++)
        visited[i] = 0;

    // Perform BFS
    printf("BFS Traversal:\n");
    BFS(startVertex, graph, numVertices);
    printf("\n");

    // Free allocated memory
    for (int i = 0; i < numVertices; i++)
        free(graph[i]);
    free(graph);
    free(visited);

    return 0;
}
