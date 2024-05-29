#include <stdio.h>
#define n 7
#define INF 9999

int min(int a, int b) {
    if (a <= b)
        return a;
    return b;
}

void print(int arr[], int size) {
    int i = 0;
    for (i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main() {
    printf("\n------------------Bellman-Ford algorithm----------------------- \n");
    int i = 0, j = 0, k = 0;

    int cost[7][7] = {{0, 6, 5, 5, 99, 99, 99},
					  {99, 0, 99, 99, -1, 99, 99},
					  {99, -2, 0, 99, 1, 99, 99},
					  {99, 99, -2, 0, 99, -1, 99},
					  {99, 99, 99, 99, 0, 99, 3},
					  {99, 99, 99, 99, 99, 0, 3},
					  {99, 99, 99, 99, 99, 99, 0}};

    int source;
    int dist[n];
    printf("Enter the source Vertex : ");
    scanf("%d" , &source);

    for(int i=0; i<n; i++) dist[i] = cost[source][i];


    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n; j++)
        {
            for(int k=0; k<n; k++)
            {
                if(cost[j][k] !=0 && cost[j][k] !=99)
                dist[k] = min(dist[k]  ,dist[j] + cost[j][k]);
            }
        }
    }

    print(dist , n);
    return 0;
}