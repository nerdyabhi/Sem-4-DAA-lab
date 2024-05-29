#include <stdio.h>

struct obj
{
    int profit;
    int weight;
    float ratio;
};

int main()
{
    int n = 7, capacity = 15;
    int profit[7] = {10, 5, 15, 7, 6, 18, 3};
    int weight[7] = {2, 3, 5, 7, 1, 4, 1};

    struct obj arr[7];

    for (int i = 0; i < n; i++)
    {
        arr[i].profit = profit[i];
        arr[i].weight = weight[i];
        float ratio = (float)profit[i] / (float)weight[i];
        arr[i].ratio = ratio;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].ratio <= arr[j + 1].ratio)
            {
                struct obj temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp; // sorted on the basis of bla bla
            }
        }
    }

    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (capacity == 0)
            break;
        if (capacity >= arr[i].weight)
        {
            sum += arr[i].profit;
            capacity -= arr[i].weight;
        }

        else if (capacity > 0)
        {
            float rem = (float)((float)capacity / (float)arr[i].weight * (float)arr[i].profit);
            sum += rem;
            capacity = 0;
        }
    }

    printf("Total profit is : %.2f", sum);
}