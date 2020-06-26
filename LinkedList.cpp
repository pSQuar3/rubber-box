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
    int data,count;
    public:
    Node *next;
    void insert(int n)
    {
        data = n;
        count++;
    }
    void deleteVal();
    static void display();
}
void Node::display()
{
    
}
