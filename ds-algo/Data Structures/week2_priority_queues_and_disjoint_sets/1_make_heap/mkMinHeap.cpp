#include <iostream> 
#include <vector>
using namespace std; 
vector<int> arr;
int n;
bool heaptype = true;
//  NOTE: true  = Max-Heap
//        false = Min-Heap
vector<pair<int,int>> v;
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
        v.push_back(make_pair(i,largest));
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
    /*
    cout << "the heap is:" << endl;
    for(int i=0;i<n;i++)
        cout << arr[i] << " ";
    cout << "\n";
    */
    cout << v.size() << endl;
    for (auto i = v.begin();i!=v.end();i++) 
        cout << i->first  << " " << i->second << endl; 
} 
int main() 
{
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr[i];
    buildHeap();  
    printHeap(); 
    return 0; 
} 
