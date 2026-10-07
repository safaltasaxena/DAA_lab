#include <stdio.h>

#define MAX 100

int main()
{
    int n, m;
    int graph[MAX][MAX] = {0};
    int queue[MAX];
    int visited[MAX] = {0};
    int distance[MAX];

    int front = 0, rear = 0;
    int u, v, s;

    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    printf("Enter the edges:\n");

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    printf("Enter starting node: ");
    scanf("%d", &s);

    for (int i = 1; i <= n; i++)
        distance[i] = -1;

    visited[s] = 1;
    distance[s] = 0;

    queue[rear++] = s;

    printf("\nBFS Traversal: ");

    while (front < rear)
    {
        u = queue[front++];

        printf("%d ", u);

        for (v = 1; v <= n; v++)
        {
            if (graph[u][v] == 1 && visited[v] == 0)
            {
                visited[v] = 1;

                distance[v] = distance[u] + 2;

                queue[rear++] = v;
            }
        }
    }

    printf("\n");

    printf("Distance [");

    for (int i = 1; i <= n; i++)
    {
        printf("%d", distance[i]);

        if (i != n)
            printf(" ");
    }

    printf("]\n");

    return 0;
}