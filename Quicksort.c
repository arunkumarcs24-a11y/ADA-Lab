#include <stdio.h>
#include <time.h>

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];

    int i = low + 1;
    int j = high;

    int temp;

    while (1)
    {
        while (i <= high && arr[i] <= pivot)
            i++;

        while (arr[j] > pivot)
            j--;

        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        else
        {
            temp = arr[low];
            arr[low] = arr[j];
            arr[j] = temp;

            return j;
        }
    }
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int j = partition(arr, low, high);

        quickSort(arr, low, j - 1);
        quickSort(arr, j + 1, high);
    }
}

int main()
{
    int n, i;

    int arr[10000];

    clock_t start, end;

    double time_taken;

    printf("Enter no of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    start = clock();

    quickSort(arr, 0, n - 1);

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sorted array:\n");

    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\nExecution time = %f seconds\n", time_taken);

    return 0;
}
