void quickSort(int arr[], int s, int e)
    {
        // code here
        
        if(s>=e) return;
        
        int p = partition(arr , s , e );
        
        quickSort(arr , s , p-1); // left
        
        quickSort(arr , p+1 , e); //right
    }
    
    public:
    int partition (int arr[], int s, int e)
    {
       int pivot = arr[e];

    int pivot_index = s;
    for (int j = s; j < e; j++)
    {
        if (arr[j] < pivot)
        {
            swap(arr[pivot_index], arr[j]);
            pivot_index++;
        } 
    }
    swap(arr[pivot_index], arr[e]);

    return pivot_index;
    
    }
};
