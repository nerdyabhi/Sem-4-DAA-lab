#include <stdio.h>

int get_max(int arr[], int n)
{
    int i = 0, max = -1;
    for (i = 0; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    return max;
}
int main()
{
    printf("--------- Hello world this is : Greedy ALGORITHM -------------\n\n ");
    int i = 0, j = 0;  
    int profit[] = {35, 30, 25, 20, 15, 12, 5};
    int deadline[] = {3, 4, 4, 2, 3, 1, 2};
    int n = sizeof(profit) / sizeof(profit[0]);

    // printf("Enter the no. of jobs : ");
    // scanf("%d" , &n);
    // for(int i=0; i<n; i++)
    // {
    //     printf("Enter the profit for job %d: " , i);
    //     scanf("%d" , &profit[i]);

    //     printf("Enter the deadline for job %d: " , i+1);
    //     scanf("%d" , &deadline[i]);

    // }

    printf("\n\n----------------The Job DATA given is : ----------------------\n\n");
    printf("Jobs : ");
    for (i = 0; i < n; i++)
        printf("%d\t", profit[i]);
    printf("\nDead : ");

    for (i = 0; i < n; i++)
        printf("%d\t", deadline[i]);
    printf("\n");

    int max = get_max(deadline, n); // max jobs we can do :

    int ans[max]; // our answer array
    for (i = 0; i < max; i++)
        ans[i] = -1;
    int sum = 0; // to calculate total profit

    for (i = 0; i < n; i++)
    {
        for (j = deadline[i] - 1; j >= 0; j--)
        {
            if (ans[j] == -1) // mtlb khali time milgya
            {
                ans[j] = i + 1;
                sum += profit[i];
                break;
            }
        }
    }

    for (i = 0; i < max; i++)
    {
        printf("Job %d\t ", ans[i]);
    }

    printf("Max-Profit :  %d\t ", sum);
}
