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
        dist[i] = cost[sv][i]; // intialise dist[i] with cost from sv to ith vertex
        selected[i] = false; 
    }
    selected[sv] = true; // source vertex is selected already
    dist[sv] = 0; // distance from any vertex to itself is 0 , no self loops are there

    for(int i=0; i<n;i++) // we perform the following operations n times : 
    {
        // 1. Get the minimum element 'u' from dist[]
        // 2. Now for all vertices 'k' : check if distance of (k > dist[u] + cost[u][k] )                                            
       // if dist[k] (or direct path to k) is greater 


        // 1st step : Get minimum element 
        mini = 99; // OR INFINITY (can be reprogrammed)
        for(int j=0; j<n; j++)
        {
            if(mini > dist[j] && selected[j] == false) // select only if it's not selected previously
            {
                mini= dist[j];
                u = j; // u holds the index for minimum element
            }
        }

        // now we found minimum element : we have to mark it true in selected array
        selected[u] = true;

        // 2nd step : Relaxation process 
        for(int k=0; k<n; k++)
        {
            if(cost[u][k] !=99 && k!=u) // if(cost[u][k] == 99 means if there's no path from u ->  k , then ofc there cant be a path from sv-> u->k ) 
            {
                if(dist[k] > dist[u] + cost[u][k]) // if sv->k >  sv->u ->k  then take second path
                {
                   dist[k] =  dist[u] + cost[u][k];
                }
            }
        }
    }

    print(dist , n);





}