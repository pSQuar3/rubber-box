#include <iostream>
#include <bits/c++io.h>
#include <new>
#include <cstdlib>
#include <map>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

static int count=0;
class Node
{
    public:
    int data;
    
    Node *next;
    Node()
    {
        data = 0;
    }
    Node(int n)
    {
        this->data = n;
        count++;
    }
};
Node first,last;
void insert(int n)
{
    Node ob(n);
    if(count == 1)
        first = ob;
    else
    {
        ob.next = &last;
        last = ob;
    }
    ob.next = &last;
    last = ob;
}
void display()
{

    for(Node *k = &first;count > 0;k = k->next)
    {
        cout << (long)(k->next) << " ";
        cout << k->data << "\n";
        count--;
    }
    /*if(k->next != NULL)
        display(k->next);*/
}
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int k;
        cin >> k;
        insert(k);
    }
    cout << "elements of the linked list:" << endl;
    display();
    return 0;
}
