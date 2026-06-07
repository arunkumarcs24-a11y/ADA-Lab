#include <stdio.h>

void heapify(int a[], int p, int n)
{
    int c, item;

    c = 2 * p + 1;
    item = a[p];

    while (c <= n - 1)
    {
        if ((c + 1 <= n - 1) && (a[c] < a[c + 1]))
            c++;

        if (item < a[c])
        {
            a[p] = a[c];
        }
        else
            break;

        p = c;
        c = 2 * p + 1;
    }

    a[p] = item;
}

void buildHeap(int a[], int n)
{
    int i;

    for (i = (n - 1) / 2; i >= 0; i--)
        heapify(a, i, n);
}

void heap_sort(int a[], int n)
{
    int i, temp;

    buildHeap(a, n);

    for (i = n - 1; i >= 1; i--)
    {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        heapify(a, 0, i);
    }
}

int main()
{
    int n;

    printf("Enter the number of nodes:\n");
    scanf("%d", &n);

    int a[n];

    printf("Enter the weight of the nodes:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    heap_sort(a, n);

    printf("The sorted array is:\n");

    for (int i = 0; i < n; i++)
        printf("%d\t", a[i]);

    return 0;
}
