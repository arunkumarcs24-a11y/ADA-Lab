#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;

    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void bestCase(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = i;
}

void worstCase(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = n - i;
}

int main()
{
    int n_values[] = {100, 200, 500, 1000, 2000, 5000};
    int size = 6;

    printf("\n\tBest Time\tWorst Time\n");

    for (int k = 0; k < size; k++)
    {
        int n = n_values[k];

        int *arr = (int *)malloc(n * sizeof(int));

        clock_t start, end;

        double best_time, worst_time;

        bestCase(arr, n);

        start = clock();

        mergeSort(arr, 0, n - 1);

        end = clock();

        best_time = ((double)(end - start)) / CLOCKS_PER_SEC;

        worstCase(arr, n);

        start = clock();

        mergeSort(arr, 0, n - 1);

        end = clock();

        worst_time = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("%d\t%f\t%f\n", n, best_time, worst_time);

        free(arr);
    }

    return 0;
}
