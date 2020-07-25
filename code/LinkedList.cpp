#include <iostream>
#include <bits/c++io.h>
#include <new>
#include <cstdlib>
#include <map>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Node
{
    public:
    int data,count;
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
Node first=NULL;
void insert(int n)
{
    Node ob(n);
    ob.next = &first;
    first = ob;
}
void display()
{
    for(Node *k = &first;k->next != NULL;k = k->next)
    {
        cout << k->data << " ";
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
