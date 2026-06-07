#include <stdio.h>

#define MAX 50

int main()
{
    int i, j, n;

    float p[MAX], w[MAX], r[MAX], x[MAX];

    float capacity, temp, TotProfit = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter profits:\n");

    for (i = 0; i < n; i++)
        scanf("%f", &p[i]);

    printf("Enter weights:\n");

    for (i = 0; i < n; i++)
        scanf("%f", &w[i]);

    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);

    for (i = 0; i < n; i++)
        r[i] = p[i] / w[i];

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (r[i] < r[j])
            {
                temp = r[i];
                r[i] = r[j];
                r[j] = temp;

                temp = w[i];
                w[i] = w[j];
                w[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    for (i = 0; i < n; i++)
        x[i] = 0.0;

    for (i = 0; i < n; i++)
    {
        if (w[i] <= capacity)
        {
            x[i] = 1.0;

            TotProfit += p[i];

            capacity -= w[i];
        }
        else
        {
            x[i] = capacity / w[i];

            TotProfit += r[i] * capacity;

            break;
        }
    }

    printf("\nSelected items (fraction taken):\n");

    for (i = 0; i < n; i++)
    {
        if (x[i] > 0)
            printf("Item %d -> %.2f\n", i + 1, x[i]);
    }

    printf("\nMaximum Profit = %.2f\n", TotProfit);

    return 0;
}
