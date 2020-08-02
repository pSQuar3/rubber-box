struct Heap
{
    
    int arr[100000];//holds the elements of the array
    int n;          //the size of the array
    bool heaptype = true;
    //  NOTE: true  = Max-Heap
    //        false = Min-Heap
    bool compareNums(int a, int b)
    {
        bool decision=false;
        if(a < b)
            decision = true;
        if(heaptype)
            decision = !decision;
        return decision;
    }
    
    void heapify(int i)
    { 
        int largest = i;
        int l = 2 * i + 1; 
        int r = 2 * i + 2;  
        if (l < n && compareNums(arr[l],arr[largest]))
            largest = l; 
        if (r < n && compareNums(arr[r],arr[largest])) 
            largest = r; 
        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            heapify(largest);
        }
    } 
    void buildHeap() 
    { 
        int startIdx = (n / 2) - 1; 
        for (int i = startIdx; i >= 0; i--)
            heapify(i);
    } 
    void printHeap() 
    {
        for(int i=0;i<n;i++)
            cout << arr[i] << " ";
        cout << "\n";
    }
};
