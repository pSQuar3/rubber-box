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
    Node *parent;
    vector<Node*>child;
    Node()
    {
        this->parent = NULL;
    }
    void parentSet(Node *theparent)
    {
        parent = theparent;
        parent->child.push_back(this);
    }
}

int main()
{
    
    return 0;
}
