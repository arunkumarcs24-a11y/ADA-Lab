#include <stdio.h>

int max(int a, int b) {
    if(a > b)
        return a;
    else
        return b;
}

int knapsack(int n, int weight[], int profit[], int capacity) {
    int i, j;
    int dp[n + 1][capacity + 1];

    for(i = 0; i <= n; i++) {
        for(j = 0; j <= capacity; j++) {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(weight[i] <= j)
                dp[i][j] = max(profit[i] + dp[i - 1][j - weight[i]],
                               dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][capacity];
}

int main() {
    int n, i, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int weight[n + 1], profit[n + 1];

    printf("Enter weights:\n");
    for(i = 1; i <= n; i++)
        scanf("%d", &weight[i]);

    printf("Enter profits:\n");
    for(i = 1; i <= n; i++)
        scanf("%d", &profit[i]);

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    int result = knapsack(n, weight, profit, capacity);

    printf("Maximum profit = %d\n", result);

    return 0;
}
