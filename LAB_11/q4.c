#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int n;

void dfs(int u)
{
    visited[u] = 1;

    for (int v = 0; v < n; v++)
    {
        if (graph[u][v] == 1 && visited[v] == 0)
            dfs(v);
    }
}

int isReachable(int source, int destination)
{
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    dfs(source);

    return visited[destination];
}

int main()
{
    int m;
    int u, v;
    int connected = 1;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter directed edges:\n");

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    for (int u = 0; u < n; u++)
    {
        for (int v = u + 1; v < n; v++)
        {
            if (!isReachable(u, v) && !isReachable(v, u))
            {
                connected = 0;
                break;
            }
        }

        if (connected == 0)
            break;
    }

    if (connected)
        printf("The given graph is one-way connected.\n");
    else
        printf("The given graph is NOT one-way connected.\n");

    return 0;
}