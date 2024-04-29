#include <stdio.h>

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int solve(int profit[], int weight[], int capacity, int n, int ans[])
{
    int dp[n + 1][capacity + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;

            else
            {
                int include = 0;
                if (weight[i] <= j)
                {
                    include = profit[i] + dp[i - 1][j - weight[i]];
                }

                int exclude = dp[i - 1][j];
                dp[i][j] = max(include, exclude);
            }
        }
    }

    int max_profit = dp[n][capacity]; // max profit
    int res = dp[n][capacity];

    for (int i = n; i > 0; i--)
    {
        if (res <= 0)
            break;
        else if (res == dp[i - 1][capacity])
            continue;
        else
        {
            ans[i] = 1;
            res = res - profit[i];
            capacity = capacity - weight[i];
        }
    }
    return max_profit;
}

int main()
{
    int profit[4] = {1, 2, 5, 6};
    int weight[4] = {2, 3, 4, 5};

    int n = sizeof(profit) / sizeof(profit[0]);
    int ans[4] = {0, 0, 0, 0};

    printf(" Max profit is : %d ", solve(profit, weight, 8, n - 1, ans));

    printf("\nAns is : \n");
    printArray(ans, 4);
    return 0;
}