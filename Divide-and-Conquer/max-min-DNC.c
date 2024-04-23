/* max -min algorithm*/
#include <stdio.h>
#include <limits.h>

void solve(int *max, int *min, int s, int e, int arr[])
{
    if (s == e)
    { 
        if (arr[s] > *max)
            *max = arr[s];
        if (arr[s] < *min)
            *min = arr[s];
        return;
    }

    else if (e == s + 1)
    {
        int maxi = INT_MIN, mini = INT_MAX;
        if (arr[s] > arr[e])
        {
            maxi = arr[s];
            mini = arr[e];
        }
        else
        {
            maxi = arr[e];
            mini = arr[s];
        }

        if (*max < maxi)
            *max = maxi;
        if (*min > mini)
            *min = mini;
        return;
    }

    int mid = s + (e - s) / 2;
    solve(max, min, s, mid, arr);
    solve(max, min, mid, e, arr);
}

int main()
{
    int arr[] = {2, 4, 3, 2, 1, 10, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    // int n;
    // printf("Enter the size of array : ");
    // scanf("%d", &n);
    // int arr[n];
    // int i;
    // for (i = 0; i < n; i++)
    // {
    //     printf("Enter the value for %d  : ", i);
    //     scanf("%d", &arr[i]);
    // }

    int max = INT_MIN;
    int min = INT_MAX;

    solve(&max, &min, 0, n - 1, arr);

    printf("Max is : %d\nMin is : %d\n", max, min);
}