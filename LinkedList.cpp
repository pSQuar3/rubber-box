#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Link
{
    private:
        int data;
    public:
        
       
        Link(int num);
        //void insertNode(int n);
        
        Link next;
        void display();
        void NewNode(int num);
        int getValue()
        {
            return data;
        }
};
Link first;
Link::Link(int num)
{
    data = num;
}
/*void Link::insertNode(int n)
{
    data = n;
}*/
void Link::NewNode(int n)
{
    Link ob(n);
    ob.next = first;
    first = ob;
}
void Link::display()
{
    for(Link k = first;k != NULL;k = k.next)
        cout << k.next << " ";
    cout << endl;
}
int main()
{
    
    cout << "Enter the number of elements in the linked list: ";
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int inp;
        cin >> inp;
        NewNode(inp);
    }
    return 0;
}
