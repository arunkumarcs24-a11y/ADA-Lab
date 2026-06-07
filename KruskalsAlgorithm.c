#include <stdio.h>

#define INF 999
#define MAX 20

int parent[MAX];

int find(int i)
{
    while (parent[i] != i)
    {
        i = parent[i];
    }

    return i;
}

void union_sets(int i, int j)
{
    int root_i = find(i);
    int root_j = find(j);

    if (root_i != root_j)
    {
        parent[root_i] = root_j;
    }
}

void kruskal(int n, int cost[MAX][MAX])
{
    int mincost = 0;

    int t[MAX][2];

    int i = 0;

    for (int v = 0; v < n; v++)
    {
        parent[v] = v;
    }

    while (i < n - 1)
    {
        int min = INF, u = -1, v = -1;

        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < n; c++)
            {
                if (cost[r][c] < min)
                {
                    min = cost[r][c];
                    u = r;
                    v = c;
                }
            }
        }

        if (u == -1 || v == -1)
            break;

        int root_u = find(u);
        int root_v = find(v);

        if (root_u != root_v)
        {
            mincost += cost[u][v];

            t[i][0] = u;
            t[i][1] = v;

            i++;

            union_sets(root_u, root_v);
        }

        cost[u][v] = cost[v][u] = INF;
    }

    if (i != (n - 1))
    {
        printf("MST cannot be constructed\n");
    }
    else
    {
        printf("\nMST edges:\n");

        for (int e = 0; e < n - 1; e++)
        {
            printf("Edge: (%d, %d)\n",
                   t[e][0], t[e][1]);
        }

        printf("\nTotal Minimum Cost: %d\n",
               mincost);
    }
}

void main()
{
    int n, cost[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix\n");
    printf("Enter %d for infinity (no edge)\n", INF);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    kruskal(n, cost);
}
