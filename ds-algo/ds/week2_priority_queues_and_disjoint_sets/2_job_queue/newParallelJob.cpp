/* TODO:
 * create a binary min heap with each nodes as pairs<int, long long> to store <proc. number and time taken for last execution.
 * 
 * make heap considering the completion times of the last job executed by the processor
 * if completion times are equal for 2 such nodes the node with the lower processor number gets higher priority
 * 
 * processes needed: 
 *
 *
 */
#include <iostream>
#include <bits/c++io.h>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

struct Heap     // stores processor completion times compared to their 
{
    vector<int> arr; // holds the elements of the array - change to int if required
    vector<long long> processor;
    bool heaptype;
    //  NOTE: true  = Min-Heap
    //        false = Max-Heap
    Heap(string s,int k)//  this one is preferrable
    {
        arr.resize(k);
        processor.resize(k);
        if(s == "min")
            heaptype = true;
        if(s == "max")
            heaptype = false;
        for(int i=0;i<k;i++)
        {
            arr[i] = 0;
            processor[i] = i;
        }
        //cerr << "completed executing: Heap(str,int)" << endl;
    }
    Heap(string s)
    {
        if(s == "min")
            heaptype = true;
        if(s == "max")
            heaptype = false;
        //cerr << "completed executing :Heap(str)" << endl;
    }
    bool compareNums(int a, int b)
    {
        bool decision=false;
        if(a <= b)
            decision = true;
        if(heaptype)
            decision = !decision;
        //cerr << "executed compareNums(" << a << ", " << b << ") = " << decision << endl;
        return decision;
    }
    int parent(int i)
    {
        //cerr << "parent(" << i << ") = " << floor((i-1)/2) << endl;
        return floor((i-1)/2);
    }
    int left(int i)
    {
        //cerr << "left(" << i << ") = " << floor((i-1)/2) << endl;
        return 2*i+1;
    }
    int right(int i)
    {
        //cerr << "right(" << i << ") = " << floor((i-1)/2) << endl;
        return 2*i+2;
    }
    /*void editValue(int i,int procNum, long long compT) // changes the value at index i with p
    {
        //cerr << "editValue(" << i << ", " << p << ")" << endl;
        int oldProc = processor[i];
        long long oldTime = arr[i];
        arr[i] = compT;
        processor[i] = procNum;
        if(compareNums(oldTime,compT))
            siftUp(i);
        else
            siftDown(i);
    }*/
    pair<int,long long> insert_to_heap(int p)
    {
        //cerr << "executing insert_to_heap(" << p << ")" << endl;
        pair<int,long long> k = make_pair(processor[0],arr[0]);
        arr[0] += p;
        siftDown(0);   // here too
        return k;
    }
    void siftDown(int i)
    {
        // TODO: Make changes to this procedure
        // 1: compare the completion times (arr) of the processors and swap with the child that has minimum completion time among 2 processors
        //          if both completion times of left and right children are equal, then select the one that has the minimum processor number
        //cerr << "executing siftDown(" << i << ")" << endl;
        int apt = i;
        int l = left(i);
        int r = right(i);
        /*
        if((l < arr.size() || r < arr.size()) && arr[apt] > arr[l] && arr[apt] > arr[r] && processor[l] != processor[r] && arr[l] == arr[r])
        {
            apt = compareNums(processor[r],processor[l])? l:r;
            if(apt >= arr.size() && l < arr.size())
                apt = l;
        }
        else
        {*/
        //cerr << " block, i = " << i << endl;
        if(l < arr.size() && compareNums(arr[apt],arr[l]))
            apt = l;
        if(r < arr.size() && compareNums(arr[apt],arr[r]))
        {
            apt = r;
            if(arr[l] == arr[r])
                apt = compareNums(processor[l],processor[r])? l:r;
            //cerr << "arr[l] == arr[r] apt = " << apt << endl;
        }
        
        //}
        if(apt != i)
        {
            swap(arr[i], arr[apt]);
            swap(processor[i],processor[apt]);
            //cerr << "calling siftDown(" << apt << ")" << endl;
            siftDown(apt);
        }
        else
        {
            // check is processor number is smaller than that of children
            if(arr[apt] > arr[l] || arr[apt] > arr[r])
            {
                l = left(apt);
                r = right(apt);
                if(l < processor.size() && processor[apt] > processor[l])
                    apt = l;
                if(r < processor.size() && processor[apt] > processor[r])
                    apt = r;
                if(apt != i)
                {
                    swap(processor[i],processor[apt]);
                    swap(arr[i],arr[apt]);
                }
                //swap processor number only since this block executes only if completion times are equal
                //no need to check parent since completion time of parent is lower
                
            }
        }
    }
    void buildHeap()
    {
        //cerr << "executing buildHeap()" << endl;
        int startIdx = arr.size()/2 - 1;
        for(int i = startIdx; i >= 0; i--)
            siftDown(i);
    }
    void printHeap()
    {
        cerr << "printing the heap:" << endl;
        for(int i=0;i<arr.size();i++)
            cout << processor[i] << " " << arr[i] << "\n";
        cout << "\n";
    }
};

int main()
{
    int n,x,m;
    cin >> n >> m;
    vector<pair<int,long long>> ans;
    Heap ob("min",n);
    for(int i=0;i<m;i++)
    {
        cin >> x;
        // cout << "before insertion of " << x << "\n";
        //ob.printHeap();
        //ob.printHeap();
        pair<int,long long> d = ob.insert_to_heap(x);
        //ob.printHeap();
        //cout << "after insertion of " << x << "\n";
        //ob.printHeap();
        ans.push_back(d);
    }
    //ob.printHeap();
    for(auto i = ans.begin();i != ans.end();i++)
        cout << i->first << " " << i->second << endl;
}
