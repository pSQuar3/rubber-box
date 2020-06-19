// Using a constructor and destructo
#include <iostream>
#include <map>
using namespace std;

#define SIZE 100
// This creates the class stack.
class stack
{
    int stck[SIZE];
    int tos;
    public:
        stack(); // constructor
        ~stack(); // destructor
        void push(int i);
        int pop();
};
// stack's constructor
stack::stack()
{
    tos = 0;
    cout << "Stack Initialized\n";
}
// stack's destructor
stack::~stack()
{
    cout << "Stack Destroyed\n";
}
void stack::push(int i)
{
    if(tos==SIZE)
    {
        cout << "Stack is full.\n";
    return;
    }
    stck[tos] = i;
    tos++;
}
int stack::pop()
{
    if(tos==0)
    {
        cout << "Stack underflow.\n";
        return 0;
    }
    tos--;
    return stck[tos];
}
int main()
{
    stack a, b;
    // create two stack objects
    //
    //
    a.push(1);
    b.push(2);
    a.push(3);
    b.push(4);
    cout << a.pop() << endl;
    cout << a.pop() << endl;
    cout << b.pop() << endl;
    cout << b.pop() << endl;
    cout << "Reached end of file";
    
    return 0;
};
