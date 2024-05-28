// Online C compiler to run C program online
#include <stdio.h>
void swap(int*a , int*b)
{
    int temp = *a ;
    *a = *b;
    *b = temp;
}

void merge(int arr[] , int s , int e)
{
    int mid = s + (e-s)/2;  
    int size1 = mid - s + 1;
    int size2 = e - mid;

    int left[size1] , right[size2];

    int i=0 , j=0 , k=s;

    for(int i=0; i<size1; i++)
    {
        left[i] = arr[k++];
    }
    for(int j=0; j<size2; j++) right[j] = arr[k++];


    i = 0 , j =0, k=s;

    while(i <size1 && j < size2)
    {
        if(left[i] < right[j])
        {
            arr[k++] = left[i++];
        }

        else arr[k++] = right[j++];
    }

    while(i<size1) arr[k++] = left[i++];
    while(j < size2) arr[k++] = right[j++];

}
void mergeSort(int arr[] , int s , int e)
{
    if(s<e)
    {
        int mid = s + (e-s)/2;
        mergeSort(arr , s , mid);
        mergeSort(arr , mid + 1 , e);
        merge(arr , s , e);
    }
}

int main() {
    // Write C code here
    int arr[] = {10 , 9 , 8 , 6, 5, 3, 2, 1, 0 , -2};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    mergeSort(arr , 0 ,n-1 );
    
    for(int i =0; i<n; i++) printf("%d\t" , arr[i]);
    printf("\n");

    return 0;
}
