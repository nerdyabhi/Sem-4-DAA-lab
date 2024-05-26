// Online C compiler to run C program online
#include <stdio.h>
void swap(int*a , int*b)
{
    int temp = *a ;
    *a = *b;
    *b = temp;
}

int partition(int arr[] , int s , int e)
{
    int pivot = arr[e];
    int index = s;
    
    for(int i=s; i<e; i++)
    {
        if(arr[i] < pivot)
        {
            swap(&arr[i], &arr[index]);
            index++;
        }
    }
    
    swap(&arr[e] , &arr[index]);
   
    return index;
}
void quickSort(int arr[] , int s , int e)
{
    if(s<e)
    {
        int p = partition(arr , s , e);
        quickSort(arr , s , p-1);
        quickSort(arr , p+1 , e);
    }
}

int main() {
    // Write C code here
    int arr[] = {10 , 9 , 8 , 6, 5, 3, 2, 1, 0 , -2};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    quickSort(arr , 0 ,n-1 );
    
    for(int i =0; i<n; i++) printf("%d\t" , arr[i]);
    printf("\n");

    return 0;
}
