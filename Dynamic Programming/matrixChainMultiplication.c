#include <stdio.h>
#include <limits.h>

int n;
void print(int arr[][n])
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%d  " , arr[i][j]);
        }
        printf("\n");
    }
}

void mcm(int arr[], int n)
{

    int dp[n][n];
    int bracket[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                dp[i][j] = 0;
            else
                dp[i][j] = -1;
            bracket[i][j] = -1;
        }
    }

    // Tabulation
    for(int len = 2; len<n+1; len++)
    {
        for(int i =1; i<n-len+1 ; i++)
        {
            int j = i + len -1;

             dp[i][j]  = INT_MAX;

            for(int k=i; k<j; k++)
            {
                int cost = dp[i][k] + dp[k+1][j] + arr[i-1] * arr[j] * arr[k];

                if(cost <dp[i][j])
                {
                    dp[i][j] = cost;
                    bracket[i][j] = i;
                }
            }
        }
    }
    

    print(dp);
    print(bracket);


    printf("Minimum Numbers of Operations Required are : %d\n", dp[1][n-1]);
}
int main()
{
    // int n;
    printf("Enter the number of matrices : ");
    scanf("%d", &n);

    int arr[n + 1];
    printf("Enter the dimensions  : (%d numbers ) : ", n + 1);

    for(int i=0; i<=n; i++)
    {
        scanf("%d", &arr[i]);
    }

    mcm(arr, n + 1);

    return 0;
}