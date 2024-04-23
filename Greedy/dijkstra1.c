#include <stdio.h>
#include <stdbool.h>

void print(int arr[], int n)
{
    printf("\nPrinting the array----->>>>>> \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n-------------------------------------------- \n");
}

int main()
{
    int cost[6][6] = // given cost adjancency matrix (can take input as well)
        {
            {0, 2, 4, 99, 99, 99},
            {99, 0, 1, 7, 99, 99},
            {99, 99, 0, 99, 3, 99},
            {99, 99, 99, 0, 99, 1},
            {99, 99, 99, 2, 0, 5},
            {99, 99, 99, 99, 99, 0}};
    int n=6;
    int dist[n]; // to store the ans
    bool selected[n]; // to check if the node is already relaxed
    int sv , mini , u;

    printf("Please Enter source vertex : ");
    scanf("%d" , &sv);

    for(int i=0; i<n; i++)
    {
        dist[i] = cost[sv][i];
        selected[i] = false;
    }
    dist[sv] =0;
    selected[sv] = true;

    for(int i=0; i<n; i++)
    {
        mini = 99;
        for(int j=0; j<n; j++)
        {
            if(mini > dist[j] && selected[j] == false)
            {
                mini = dist[j];
                u = j;
            }
        }
        selected[u] = true;

        for(int k=0; k<n; k++)
        {
            if(cost[u][k] !=99 && k!=u) // if there's a path from u to k && k isn't the min element
            {
                if(dist[k] > dist[u] + cost[u][k])
                {
                    dist[k] = dist[u] + cost[u][k];
                }
            }
        }
    }

    print(dist , n);
    return 0;
}