#include <stdio.h>
#define MAX 100
int main()
{
    int n, e;
    int graph[MAX][MAX];
    int visited[MAX] = {0};
    int total_cost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);
  
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            graph[i][j] = 0;

    printf("Enter edges (u v weight):\n");

    for(int i = 0; i < e; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        graph[u][v] = w;
        graph[v][u] = w;
    }

    visited[0] = 1;

    printf("Edges in MST:\n");

    for(int count = 0; count < n - 1; count++)
    {
        int min = 9999;
        int u = -1, v = -1;

        for(int i = 0; i < n; i++)
        {
            if(visited[i])
            {
                for(int j = 0; j < n; j++)
                {
                    if(!visited[j] && graph[i][j] != 0 &&
                       graph[i][j] < min)
                    {
                        min = graph[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if(u == -1)
        {
            printf("Graph is disconnected\n");
            return 0;
        }

        printf("%d - %d : %d\n", u, v, min);

        visited[v] = 1;
        total_cost += min;
    }

    printf("Minimum Cost = %d\n", total_cost);

    return 0;
}

