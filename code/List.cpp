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
    int data;
    static int count;
    public:
    int getData();
    int getCount();
    void displayList();
    int pop();
    void push(int n);
    static Node next;
};

Node first;
void Node::push(int n)
{
    data = n;
    next = first;
    count++;
}
int pop()
{
    int num = first.getData();
    Node k = first.next;
    first.~Node();
    first = k;
    return num;
}
int Node::getData()
{
    return data;
}
int Node::getCount()
{
    return count;
}
void Node::displayList()
{
    Node k = first;
    int lim = first.count;
    cout << "Printing the elements of the linked list: " << endl;
    while(lim > 0)
    {
        cout << k.getData() << " ";
        k = k.next;
        lim--;
    }
}
int main()
{
    
    int n = 1;
    while(n > 0)
    {
        cout << "Enter 1 to insert, 2 to pop, 3 to display: ";
        cin >> n;
        switch(n)
        {
            case 1:
                Node newnode;
                cout << "Enter the data you want to insert: ";
                int num;
                cin >> num;
                newnode.push(num);
                first = newnode;
            break;
            case 2:
                // deletion of the last element
                if(first.getCount() == 0)
                    cout << "Vacant List: Nothing to pop";
                else
                {
                    cout << "Popped Element = " << first.pop() << endl;
                }
            break;
            case 3:
                if(first.getCount() == 0)
                    cout << "List is empty: Nothing to dislpay";
                else
                {
                    int ct = 0;
                    int max = first.getCount();
                    for(Node k = first;ct < max;k = k.next)
                    {
                        cout << k.getData() << " ";
                    }
                    cout << "Displayed\n";
                
                }
            break;
            default:
                cout << "Wrong choice: ";
                cout << "Please try again\n";
            break;
        }
    }
    return 0;
}
