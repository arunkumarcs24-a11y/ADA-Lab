#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX], indegree[MAX], queue[MAX];
int front = -1, rear = -1;

void enqueue(int x)
{
    if (rear == MAX - 1)
        return;

    if (front == -1)
        front = 0;

    queue[++rear] = x;
}

int dequeue()
{
    if (front == -1)
        return -1;

    int val = queue[front++];

    if (front > rear)
        front = rear = -1;

    return val;
}

int isEmpty()
{
    return front == -1;
}

int main()
{
    int n, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    for (i = 0; i < n; i++)
    {
        indegree[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (adj[i][j] == 1)
            {
                indegree[j]++;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            enqueue(i);
        }
    }

    printf("Topological Order: ");

    int count = 0;

    while (!isEmpty())
    {
        int u = dequeue();

        printf("%d ", u);

        count++;

        for (j = 0; j < n; j++)
        {
            if (adj[u][j] == 1)
            {
                indegree[j]--;

                if (indegree[j] == 0)
                {
                    enqueue(j);
                }
            }
        }
    }

    if (count != n)
    {
        printf("\nGraph has a cycle. Topological sort not possible.\n");
    }

    return 0;
}
