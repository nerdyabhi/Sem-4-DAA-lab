#include <stdio.h>

int max(int a, int b)
{
    a > b ? return a : return b;
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
    if (n <= 0)
        return 0;

    int include = 0;
    if (weight[n] <= capacity)
    {
        include = profit[n] + solve(profit, weight, capacity - weight[n], n - 1, ans);
    }

    int exclude = solve(profit, weight, capacity, n - 1, ans);

    if (include > exclude)
    {
        ans[n] = 1;
        return include;
    }
    else
    {
        ans[n] = 0; // Update ans array when excluding the item
        return exclude;
    }
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